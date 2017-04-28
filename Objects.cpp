#include "Objects.h"
#include "Сonstants.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>




Object::Object(float x, float y, std::string filename, sf::Vector2f speed)
{
	texture.loadFromFile("images/" + filename);
	sprite.setTexture(texture);
	this->pos.x = x;
	this->pos.y = y;
	this->speed = speed;
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
	this->numberOfFrame = 93;
	this->lastUpdateTime = 0;
};


Sunflower::Sunflower(float x, float y, std::string filename, sf::Vector2f speed, float plantTime) : Object(x, y, filename, speed)
{
	this->numberOfFrame = 0;
	this->lastCreateSunTime = 0;
	this->health = MAX_SUNFLOWER_HEALTH;
	this->plantTime = plantTime;
	this->lastCreateSunTime = plantTime;
	this->lastUpdateTime = plantTime;
}


Peas::Peas(float x, float y, std::string filename, sf::Vector2f speed, float plantTime) : Object(x, y, filename, speed)
{
	this->numberOfFrame = 0;
	this->health = MAX_PEAS_HEALTH;
	this->plantingTime = plantTime;
	this->lastCreateTime = plantTime;
	this->lastUpdateTime = plantTime;
}


Frame::Frame(std::string filename)
{
	this->texture.loadFromFile("images/" + filename);
	this->sprite.setTexture(texture);
	//this->sprite.setScale(0.3f, 0.3f);
    
}


static int x = 0;


Frame::Frame()
{
	//cout << x << endl;
	x++;
}



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



