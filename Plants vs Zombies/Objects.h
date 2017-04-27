#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>



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
    
	Sun(float x, float y, std::string filename, sf::Vector2f spped, float createTime, int whoseSun);
};


class Zombie : public Object
{
public:
	int health;
	float createTime;
	static float lastCreateTime;
	float lastUpdateTime;
	int numberOfFrame;
    
	Zombie(float x, float y, std::string filename, sf::Vector2f speed, float createTime);
};


class Sunflower : public Object
{
public:
	static int status;
	static float lastCreateTime;
	int health;
	int numberOfFrame;
	float lastUpdateTime;
	float lastCreateSunTime;
	float plantTime;
    
	Sunflower(float x, float y, std::string filename, sf::Vector2f speed, float plantTime);
};


class Peas : public Object
{
public:
	static int status;
	static float lastCreateTime;
	int health;
	int numberOfFrame;
	float lastUpdateTime;
	float plantingTime;
    
	Peas(float x, float y, std::string filename, sf::Vector2f speed, float plantTime);
};


class Frame
{
public:
	sf::Texture texture;
	sf::Sprite sprite;
    
    Frame(std::string filename);
    
	Frame();
};
