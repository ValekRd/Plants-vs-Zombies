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
	Sun(float x, float y, std::string filename, sf::Vector2f speed, float createTime, int whoseSun);
};
class Zombie : public Object
{
public:
	int health;
	float createTime;
	static float lastCreateTime;
	float lastUpdateTime;
	int numberOfFrame;
	int numberOfLine;
	int status;
	float lastEatingTime;
	Zombie(float x, float y, std::string filename, sf::Vector2f speed, float createTime, int numberOfLine);
    void stop();
};
class Sunflower : public Object
{
public:
	int status;
	static float lastCreateTime;
	int health;
	int numberOfFrame;
	int numberOfLine;
	float lastUpdateTime;
	float lastCreateSunTime;
	float plantTime;
	Sunflower(float x, float y, std::string filename, sf::Vector2f speed, float plantTime);
};
class Peas : public Object
{
public:
	int status;
	static float lastCreateTime;
	int health;
	int numberOfFrame;
	float lastUpdateTime;
	float plantTime;
	int numberOfLine;
	float lastShootTime;
	Peas(float x, float y, std::string filename, sf::Vector2f speed, float plantTime);
};

class Nut : public Object
{
public:
    int status;
    static float lastCreateTime;
    int health;
    int numberOfFrame;
	int numberOfLine;
    float plantTime;
    Nut(float x, float y, std::string filename, sf::Vector2f speed, float plantTime);
};


class Frame
{
public:
	sf::Texture texture;
	sf::Sprite sprite;
	Frame(string filename);
	Frame();
};

class Bullet : public Object
{
public:
	int numberOfLine;
	Bullet(float x, float y, std::string filename, sf::Vector2f speed, int numberOfLine);
};
