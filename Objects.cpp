#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include "Сonstants.h"
#include "Objects.h"

using namespace std;

Object::Object(float x, float y, std::string filename, sf::Vector2f speed_)
{
	this->texture.loadFromFile("images/" + filename);
	this->sprite.setTexture(texture);
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
Bullet::Bullet(float x, float y, std::string filename, sf::Vector2f speed, int numberOfLine) : Object(x, y, filename, speed)
{
	this->numberOfLine = numberOfLine;
}
Sun::Sun(float x, float y, std::string filename, sf::Vector2f speed, float CreateTime, int WhoseSun) : Object(x, y, filename, speed)
{
	this->createTime = CreateTime;
	this->whoseSun = WhoseSun;
}
Zombie::Zombie(float x, float y, std::string filename, sf::Vector2f speed, float createTime, int numberOfLine) : Object(x, y, filename, speed)
{
	this->createTime = createTime;
	this->health = MAX_ZOMBIE_HEALTH;
	this->numberOfFrame = 0;
	this->lastUpdateTime = 0;
	this->numberOfLine = numberOfLine;
	this->status = 0;
	this->lastEatingTime = 0;
};

void Zombie::stop()
{
    speed.x = 0;
    speed.y = 0;
}

Sunflower::Sunflower(float x, float y, std::string filename, sf::Vector2f speed, float plantTime) : Object(x, y, filename, speed)
{
	this->numberOfFrame = 0;
	this->lastCreateSunTime = 0;
	this->health = MAX_SUNFLOWER_HEALTH;
	this->plantTime = 0;
	this->lastUpdateTime = 0;
	this->status = 0;
	this->numberOfLine = 0;
}

Nut::Nut(float x, float y, std::string filename, sf::Vector2f speed, float plantTime) : Object(x, y, filename, speed)
{
    this->numberOfFrame = 0;
    this->health = MAX_NUT_HEALTH;
    this->plantTime = 0;
    this->status = 0;
	this->numberOfLine = 0;
}

Peas::Peas(float x, float y, std::string filename, sf::Vector2f speed, float plantTime) : Object(x, y, filename, speed)
{
	this->numberOfFrame = 0;
	this->health = MAX_PEAS_HEALTH;
	this->plantTime = 0;
	this->lastCreateTime = plantTime;
	this->lastUpdateTime = 0;
	this->numberOfLine = 0;
	this->lastShootTime = 0;
	this->status = 0;
}
Frame::Frame(string filename)
{
	this->texture.loadFromFile("images/" + filename);
	this->sprite.setTexture(texture);
}
Frame::Frame()
{}





