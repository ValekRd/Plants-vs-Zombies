//from testSFML
#pragma once
#include <SFML/Graphics.hpp>
// sizes
const sf::Vector2i GRID(80, 96);   //размеры квадратика на поле 
const sf::Vector2i OFFSET(258, 89);			//координаты начала поля
const int WINDOW_SIZE_X = 1024;
const int WINDOW_SIZE_Y = 600;
const int TOP_PANEL_POSITION_X = 230;
const int TOP_PANEL_POSITION_Y = 0;
// number of frames
const int NUM_OF_DIGIT_FRAMES = 10;
const int NUM_OF_ZOMBIE_FRAMES = 93;
const int NUM_OF_SUNFLOWER_FRAMES = 60;
const int NUM_OF_PEAS_FRAMES = 60;
//times
const float TIME_PLANTING = 0.5;
const float FREE_FROM_ZOMBIES_TIME = 0;
const float INTEERVAL_BETWEEN_ZOMBIE_GENERATION = 4;
const float INTERVAL_BETWEEN_FREE_SUN_GENERATION = 5;
const float dt = 0.1;
const float FREE_SUN_MOVE_TIME = 3;
//speeds
const sf::Vector2f SUN_SPEED(0, 1);
const sf::Vector2f NULL_SPEED(0, 0);
const sf::Vector2f ZOMBIE_SPEED(-0.3, 0);
//distances

//healthes
const int MAX_ZOMBIE_HEALTH = 7;
const int MAX_SUNFLOWER_HEALTH = 10;
const int MAX_PEAS_HEALTH = 10;


//no constans
//float 
