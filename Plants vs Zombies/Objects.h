#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

class Object
{
public:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Image image;
	sf::Vector2f pos;
	sf::Vector2f speed;
	Object(float x, float y, std::string filename, sf::Vector2f speed);
	void update(float dt);
}; 
class Sun : public Object
{
public:
	static int score;
	static float lastCreateTime;
	float createTime;
	int whoseSun;
	Sun(float x, float y, string filename, sf::Vector2f spped, float createTime, int whoseSun);
};
class Zombie : public Object
{
public:
	int health;
	float createTime;
	static float lastCreateTime;
	float lastUpdateTime;
	Zombie(float x, float y, string filename, sf::Vector2f speed, float createTime);
};
/*class Sunflower : public Object
{
public:
	static int Health;
	static int Count;
	static int Status;
	static float LastCreateTime;
	int NumberOfFrame;
	float LastUpdateTime;
	float LastCreateSunTime;
	float PlantTime;
	Sunflower(float x, float y, string filename, int NumberOfFrame, float LastUpdateTime, float LastCreateSunTime, float PlantTime, float Health, int Status);
};*/
// not ready (constructor)
/*
class Frame
{
public:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Image image;
	Frame(string filename);
};
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
};



class Bullet : public Object
{
public:
	int create_time;
};
 */