#include <SFML/Graphics.hpp>
#include "Objects.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <string>

class Object
{
public:
    sf::Texture texture;
    sf::Sprite sprite;
    
    Object()
    {}
    
    void set_for_static_object(float _x, float _y, std::string filename)
    {
        texture.loadFromFile(filename);
        sprite.setTexture(texture);
        sprite.setPosition(_x, _y);
    }
};

class Sun : public Object
{
public:
    static int score;
    static float last_create_time;
    float create_time;
    static int count;
    int whose_sun;
    
    Sun()
    {
        sprite.setPosition(float(rand() % 600 + 200), float(rand() % 300 + 50));
    }
};

class Number : public Object
{
public:
    
    Number()
    {}
};

class Plants : public Object
{
public:
    
    Plants()
    {}
};

class Sunflower : public Plants
{
public:
    static int health;
    static int count;
    static int status;
    static float last_create_time;
    int number_of_frame;
    float last_update_time;
    float last_create_sun_time;
    float planting_time;
    
    Sunflower()
    {
        
    }
};

class Sunflower_frames : public Object
{};

class Zombie_frames : public Object
{};

class Peas_frames : public Object
{};

class Peas : public Plants
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

class Zombie : public Object
{
public:
    sf::Vector2f velocity;
    int health;
    static int count;
    float create_time;
    static float last_create_time;
    int number_of_frame;
    float last_update_time;
    
    Zombie()
    {}
};

class Bullet : public Object
{
public:
    int create_time;
};
