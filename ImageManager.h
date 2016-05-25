#pragma once
#ifndef IMAGE_MANAGER_H_
#define IMAGE_MANAGER_H_
#include <string>
#include <vector>
#include <SFML/Graphics/Image.hpp>
#include <map>

class ImageManager
{
public:
	ImageManager();
	~ImageManager();

private:
	ImageManager(const ImageManager&);
	ImageManager& operator =(const ImageManager&);

public:
	const sf::Image&    get_image(const std::string& filename);
	void                delete_image(const sf::Image& image);
	void                delete_image(const std::string& filename);
	void                add_resource_directory(const std::string& directory);
	void                remove_resource_directory(const std::string& directory);

private:
	std::map< std::string, sf::Image > images_;
	std::vector< std::string > resource_directories_;
};
#endif