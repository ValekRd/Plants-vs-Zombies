#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "C:\Users\user\Desktop\Ïðîåêò\TestSFML\vc2015project\testSFML\testSFML\Ñonstants.h"
#include "Objects.h"
 
using namespace std;

Object::Object(float x, float y, string filename, sf::Vector2f speed_)
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
Sun::Sun(float x, float y, string filename, sf::Vector2f speed, float CreateTime, int WhoseSun) : Object(x, y, filename, speed)
{
	this->createTime = CreateTime;
	this->whoseSun = WhoseSun;
}
Zombie:: Zombie (float x, float y, string filename, sf::Vector2f speed, float createTime) : Object (x,y, filename, speed)
{
	this->createTime = createTime;
};
/*
Frame::Frame(string filename)
{
	image.loadFromFile("images/" + filename);
	texture.loadFromImage(image);
	sprite.setTexture(texture);
}
*/


/*Sunflower::Sunflower(float x, float y, string filename, int NumberOfFrame, float LastUpdateTime, float LastCreateSunTime, float PlantTime, float Health, int Status): Object(x, y, filename)
{
	this->NumberOfFrame = NumberOfFrame;
	this->LastUpdateTime = LastUpdateTime;
	this->LastCreateSunTime = LastCreateSunTime;
	this->PlantTime = PlantTime;
	this->Health = Health;
	Sunflower::Status = Status;
};
*/

/*

class Peas : public Plans
{
public:
	static int health;
	static int count;
	static int status;
	static float last_create_time;
	int number_of_frame;
	float last_update_time;
	float planting_time;

	Peas()
	{

	}
}; */



