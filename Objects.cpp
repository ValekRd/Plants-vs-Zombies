//from testSFML
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include "C:\Users\user\Desktop\Проект\TestSFML\vc2015project\testSFML\testSFML\Сonstants.h"
#include "C:\Users\user\Desktop\Проект\TestSFML\vc2015project\testSFML\testSFML\Objects.h"

using namespace std;

Object::Object(float x, float y, std::string filename, sf::Vector2f speed_)
{
	this->image.loadFromFile("images/" + filename);
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	this->pos.x = x;
	this->pos.y = y;
	this->speed = speed_;
	sprite.setPosition(pos.x, pos.y);
}
void Object::update(float dt)
{
	pos += speed * dt;
	sprite.setPosition(pos.x, pos.y);
}
Sun::Sun(float x, float y, std::string filename, sf::Vector2f speed, float CreateTime, int WhoseSun) : Object(x, y, filename, speed)
{
	this->createTime = CreateTime;
	this->whoseSun = WhoseSun;
}
Zombie::Zombie(float x, float y, std::string filename, sf::Vector2f speed, float createTime) : Object(x, y, filename, speed)
{
	this->createTime = createTime;
	this->health = MAX_ZOMBIE_HEALTH;
	this->numberOfFrame = 0;
	this->lastUpdateTime = 0;
};
Sunflower::Sunflower(float x, float y, std::string filename, sf::Vector2f speed, float plantTime) : Object(x, y, filename, speed)
{
	this->numberOfFrame = 0;
	this->lastCreateSunTime = 0;
	this->health = MAX_SUNFLOWER_HEALTH;
	this->plantTime = plantTime;
	this->lastUpdateTime = 0;
	this->status = 0;
}
Peas::Peas(float x, float y, std::string filename, sf::Vector2f speed, float plantTime) : Object(x, y, filename, speed)
{
	this->numberOfFrame = 0;
	this->health = MAX_PEAS_HEALTH;
	this->plantTime = plantTime;
	this->lastCreateTime = plantTime;
	this->lastUpdateTime = 0;
	this->status = 0;
}
Frame::Frame(string filename)
{
	this->texture.loadFromFile("images/" + filename);
	this->sprite.setTexture(texture);
	//this->sprite.setScale(0.3f, 0.3f);
	//cout << "here" << endl;
}
Frame::Frame()
{
}





