#include <Windows.h>
#include <Psapi.h>
#include "Debug.h"
#include "FPS.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "TCHAR.h"
#include "pdh.h"
#include "comutil.h"
#include "Wbemcli.h"
#include "Wbemidl.h"

CRUCIBLE::Debug::Debug()
{
	font.loadFromFile("resource/myriad-pro-bold.ttf");
	GetGPUInfo();
}

CRUCIBLE::Debug::~Debug()
{
}

long CRUCIBLE::Debug::GetMemory()
{
	PPROCESS_MEMORY_COUNTERS memCounter;
	memCounter = new PROCESS_MEMORY_COUNTERS();

	GetProcessMemoryInfo(GetCurrentProcess(), memCounter, sizeof(PROCESS_MEMORY_COUNTERS));
	return memCounter->WorkingSetSize >> 20;
}

void CRUCIBLE::Debug::GetGPUInfo()
{
	try
	{
		HRESULT hr;
		hr = CoInitializeEx(NULL, COINIT_MULTITHREADED);

		IWbemLocator *pIWbemLocator = NULL;
		hr = CoCreateInstance(__uuidof(WbemLocator), NULL,
			CLSCTX_INPROC_SERVER, __uuidof(IWbemLocator),
			(LPVOID *)&pIWbemLocator);

		BSTR bstrServer = SysAllocString(L"\\\\.\\root\\cimv2");
		IWbemServices *pIWbemServices;
		hr = pIWbemLocator->ConnectServer(bstrServer, NULL, NULL, 0L, 0L, NULL,
			NULL, &pIWbemServices);

		hr = CoSetProxyBlanket(pIWbemServices, RPC_C_AUTHN_WINNT,
			RPC_C_AUTHZ_NONE, NULL, RPC_C_AUTHN_LEVEL_CALL,
			RPC_C_IMP_LEVEL_IMPERSONATE, NULL,
			EOAC_DEFAULT);

		BSTR bstrWQL = SysAllocString(L"WQL");
		BSTR bstrPath = SysAllocString(L"select * from Win32_VideoController");
		IEnumWbemClassObject* pEnum;
		hr = pIWbemServices->ExecQuery(bstrWQL, bstrPath, WBEM_FLAG_FORWARD_ONLY, NULL, &pEnum);

		IWbemClassObject* pObj = NULL;
		ULONG uReturned;
		VARIANT var;
		hr = pEnum->Next(WBEM_INFINITE, 1, &pObj, &uReturned);

		if (uReturned)
		{
			hr = pObj->Get(L"Name", 0, &var, NULL, NULL);
			if (SUCCEEDED(hr))
			{
				char sString[256];
				WideCharToMultiByte(CP_ACP, 0, var.bstrVal, -1, sString,
					sizeof(sString), NULL, NULL);

				gpuName = sString;
			}

			hr = pObj->Get(L"AdapterRAM", 0, &var, NULL, NULL);
			if (SUCCEEDED(hr))
			{
				char str[MAX_PATH];
				sprintf_s(str, "%ld", std::abs((var.lVal / (1024 * 1024))));

				adapterRAM = str;
			}

			hr = pObj->Get(L"VideoModeDescription", 0, &var, NULL, NULL);
			if (SUCCEEDED(hr))
			{
				char sString[256];
				WideCharToMultiByte(CP_ACP, 0, var.bstrVal, -1, sString,

					sizeof(sString), NULL, NULL);
				videoModeDesc = sString;
			}

			hr = pObj->Get(L"DriverVersion", 0, &var, NULL, NULL);
			if (SUCCEEDED(hr))
			{
				char sString[256];
				WideCharToMultiByte(CP_ACP, 0, var.bstrVal, -1, sString,

					sizeof(sString), NULL, NULL);
				driverVer = sString;
			}
		}
	} catch(...)
	{
		
	}
}

sf::Text CRUCIBLE::Debug::DrawText(std::string string, sf::Vector2f position, uint32_t scale, sf::Color color)
{
	sf::Text text(string, font);
	text.setPosition(position);
	text.setColor(color);
	text.setCharacterSize(scale);
	return text;
}

void CRUCIBLE::Debug::Draw(sf::RenderWindow *window)
{
	float fps = GetFPS(fpsClock.restart());

	window->draw(DrawText("CRUCIBLE", sf::Vector2f(10, 5), 40, sf::Color::White));
	window->draw(DrawText("EXPERIMENTAL", sf::Vector2f(190, 5), 40, sf::Color(240, 126, 24)));
	window->draw(DrawText("FPS: " + std::to_string(fps), sf::Vector2f(15, 50), 20, sf::Color::White));
	window->draw(DrawText("PROCESS MEMORY: " + std::to_string(GetMemory()) + "MB", sf::Vector2f(15, 70), 20, sf::Color::White));
	window->draw(DrawText("GPU: " + gpuName, sf::Vector2f(15, 90), 20, sf::Color::White));
	window->draw(DrawText("GPU VRAM: " + adapterRAM + "MB", sf::Vector2f(15, 110), 20, sf::Color::White));
	window->draw(DrawText("GPU DRIVER VER: " + driverVer, sf::Vector2f(15, 130), 20, sf::Color::White));
	window->draw(DrawText("VIDEO MODE: " + videoModeDesc, sf::Vector2f(15, 150), 20, sf::Color::White));


}

int CRUCIBLE::Debug::GetFPS(const sf::Time& time)
{
	return std::floor((1000000.0f / time.asMicroseconds()));
}

