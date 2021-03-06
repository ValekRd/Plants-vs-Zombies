﻿#include "Objects.h"
#include "Сonstants.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <functional>
#include <sstream>


template <typename T>
void SwapFrame(T i, std::vector <Frame>& frames, float time, float FrameRate);

void CreateNewZombie(std::vector <Zombie>& zombies, float time);

void Download(std::vector <Frame>& frames, int count, std::string nameOfFrameType);

void CreateNewFreeSun(std::vector <Sun>& suns, float time, Frame& sunFrame);


void CreateNewSunflower(std::vector <Sunflower>& sunflowers, sf::Vector2i mousePosition, float time, Frame& sunflowerFrame, sf::Text& score);

void CreateNewNut(std::vector <Nut>& nuts, sf::Vector2i mousePosition, float time, Frame& nutFrame, sf::Text& score);

void CreateNewPeas(std::vector <Peas>& peases, sf::Vector2i mousePosition, float time, Frame& peasFrame, sf::Text& score);

void PlantingSunflower(vector <Sunflower>& sunflowers, sf::Vector2i mousePosition, float time, sf::Sound& plant);

void PlantingPeas(std::vector <Peas>& peases, sf::Vector2i mousePosition, float time, sf::Sound& plant);

void PlantingNut(std::vector <Nut>& nuts, sf::Vector2i mousePosition, float time, sf::Sound& plant);

void ClickOnSun(std::vector <Sun>& suns, sf::Vector2i mousePosition, sf::Text& score, sf::Sound& getSun);

void FreeSunStopper(std::vector<Sun>::iterator i);

void CreateNewSun(std::vector <Sun>& suns, float time, Frame& sunFrame, std::vector <Sunflower>::iterator i);

void CallShoot(vector <Zombie>& zombies);

void CreateNewBullet(std::vector <Peas>::iterator i, vector <Bullet>& bullets, Frame& peaFrame, sf::Sound& shoot, float time);

void ZombieShooting(std::vector <Bullet>& bullets, sf::Sound& kernelpult);

void AccountUpdate(sf::Text& score);

bool CheckGameEnd (std::vector <Zombie>::iterator i, sf::RenderWindow& window, sf::Music& music, sf::Music& losemusic);

template <typename T>
void MoveWithMouse(T& vec, sf::Vector2i mousePosition);

template <typename T>
void Eat(std::vector <Zombie>::iterator i, T& peases, float time, sf::Sound& chomp);

template <typename T>
void CallEat(std::vector <Zombie>::iterator i, T& vec);

int Sun::score                  = 1000;
int gameStatus                  = 0;
float Sun::lastCreateTime       = 0;
float Nut::lastCreateTime       = 0;
float Zombie::lastCreateTime    = 0;
float Peas::lastCreateTime      = 0;
float Sunflower::lastCreateTime = 0;
static int callShoot[5];
static std::vector <Zombie>::iterator zombieForKilling[5];

int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), "My Plants VS Zombies");
	Object background(0, 0, "fone.png", NULL_SPEED);
	Object topPanel(TOP_PANEL_POSITION_X, TOP_PANEL_POSITION_Y, "top_panel.png", NULL_SPEED);
    
	std::vector <Frame> sunflowerFrames(0);
	std::vector <Frame> zombieFrames(0);
    std::vector <Frame> zombieDieFrames(0);
	std::vector <Frame> zombieEatFrames(0);
	std::vector <Frame> peasFrames(0);
	std::vector <Frame> peasFramesIdle(0);
	std::vector <Frame> NutFrames(0);
	std::vector <Bullet> bullets;
    
	Frame sunFrame("sun.png");
	Frame peaFrame("pea.png");
    
	Download(sunflowerFrames,   NUM_OF_SUNFLOWER_FRAMES,    "sunFlower");
	Download(zombieFrames,      NUM_OF_ZOMBIE_FRAMES,       "zombie");
	Download(zombieEatFrames,   NUM_OF_ZOMBIE_EAT_FRAMES,   "zombieEat1");
	Download(zombieDieFrames,   NUM_OF_ZOMBIE_DIE_FRAMES,   "zombieDie");
	Download(peasFrames,        NUM_OF_PEAS_FRAMES,         "peas");
    Download(peasFramesIdle,    NUM_OF_PEAS_FRAMES,         "peasIdle");
    Download(NutFrames,         NUM_OF_NUT_FRAMES,          "nut");
    Download(zombieDieFrames,   NUM_OF_ZOMBIE_DIE_FRAMES,   "zombieDie");


	//SCORE:
	sf::Font font;
	font.loadFromFile("images/fonts/font.ttf");
	sf::Text score("", font, 22);
	score.setFillColor(sf::Color::Black);
	score.setFillColor(sf::Color::Black);
	score.setString("0");
	score.setStyle(sf::Text::Bold);
	score.setPosition(266, 59);
    
	//MUSIC:
	sf::Music music;
	sf::Music losemusic;
	music.openFromFile("music/gamemusic.ogg");
	losemusic.openFromFile("music/losemusic.ogg");
	music.setVolume(40);
	music.play();
	music.setLoop(true);
    
    //SOUND:
	sf::SoundBuffer plantBuffer;
	sf::SoundBuffer sunBuffer;
	sf::SoundBuffer shootBuffer;
    sf::SoundBuffer chompBuffer;
    sf::SoundBuffer kernelpultBuffer;
    
	plantBuffer.loadFromFile("music/plant.ogg");
	sunBuffer.loadFromFile("music/points.ogg");
	shootBuffer.loadFromFile("music/shoot.ogg");
    chompBuffer.loadFromFile("music/chomp.ogg");
    kernelpultBuffer.loadFromFile("music/kernelpult.ogg");
    
	sf::Sound plant(plantBuffer);
	sf::Sound getSun(sunBuffer);
	sf::Sound shoot(shootBuffer);
    sf::Sound chomp(chompBuffer);
    sf::Sound kernelpult(kernelpultBuffer);

    sf::Clock clock;
	std::vector <Sun> suns;
	std::vector <Zombie> zombies;
	std::vector <Sunflower> sunflowers;
	std::vector <Peas> peases;
    std::vector <Nut> nuts;
    
	while (window.isOpen())
	{
		
        sf::Time time = clock.getElapsedTime();
		sf::Event event;
		window.draw(background.sprite);
		window.draw(topPanel.sprite);

		CreateNewFreeSun(suns, time.asSeconds(), sunFrame);
		CreateNewZombie(zombies, time.asSeconds());
		CallShoot(zombies);
		
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
				ClickOnSun(suns, mousePosition, score, getSun);
				CreateNewSunflower(sunflowers, mousePosition, time.asSeconds(), sunflowerFrames[0], score);
				PlantingSunflower(sunflowers, mousePosition, time.asSeconds(), plant);
				CreateNewPeas(peases, mousePosition, time.asSeconds(), peasFrames[0], score);
				PlantingPeas(peases, mousePosition, time.asSeconds(), plant);
                CreateNewNut(nuts, mousePosition, time.asSeconds(), NutFrames[0], score);
                PlantingNut(nuts, mousePosition, time.asSeconds(), plant);
			}
		}

		MoveWithMouse(sunflowers, sf::Mouse::getPosition(window));
		MoveWithMouse(peases, sf::Mouse::getPosition(window));
        MoveWithMouse(nuts, sf::Mouse::getPosition(window));
    		
		for (auto i = zombies.begin(); i != zombies.end(); i++)
		{
			window.draw(i->sprite);
			CallEat(i, peases);
			CallEat(i, sunflowers);
			CallEat(i, nuts);
			if (i->status == 0)
			{
				SwapFrame(i, zombieFrames, time.asSeconds(), ZOMBIE_FRAME_RATE);
			}
	
			if (i->status == 1)
			{
				SwapFrame(i, zombieEatFrames, time.asSeconds(), ZOMBIE_FRAME_RATE);
				Eat(i, peases, time.asSeconds(), chomp);
				Eat(i, sunflowers, time.asSeconds(), chomp);
				Eat(i, nuts, time.asSeconds(), chomp);
			}
			i->update(dt);
			if (i->health == 0)
			{
				i = zombies.erase(i);
                
				if (i == zombies.end())
					break;
			}

            if (CheckGameEnd (i, window, music, losemusic) == true)
            {
                if (gameStatus == 0)
                {
                    gameStatus = 1;
                }
                else if (gameStatus == 1)
                    return 0;
                break;
            }
            
		}
        
		for (auto i = sunflowers.begin(); i != sunflowers.end(); i++)
		{
			window.draw(i->sprite);
			if (i->status == 1) SwapFrame(i, sunflowerFrames, time.asSeconds(), SUNFLOWER_FRAME_RATE);
			CreateNewSun(suns, time.asSeconds(), sunFrame, i);
			if (i->status == 1) SwapFrame(i, sunflowerFrames, time.asSeconds(), SUNFLOWER_FRAME_RATE);
		}
		for (auto i = peases.begin(); i != peases.end(); i++)
		{
			window.draw(i->sprite);
			if (i->status == 1 && callShoot[i->numberOfLine] == 1)
			{
				SwapFrame(i, peasFrames, time.asSeconds(), PEAS_FRAME_RATE);
				if (i->numberOfFrame == 33 && (time.asSeconds() - i->lastShootTime) > PEAS_FRAME_RATE)
				{
					CreateNewBullet(i, bullets, peaFrame, shoot, time.asSeconds());
				}

				ZombieShooting(bullets, kernelpult);

			}
            else if (i->status == 1)
            {
                SwapFrame(i, peasFramesIdle, time.asSeconds(), PEAS_FRAME_RATE);
            }
		}
        for (auto i = nuts.begin(); i != nuts.end(); i++)
        {
            window.draw(i->sprite);
        }
		for (auto i = bullets.begin(); i != bullets.end(); i++)
		{
			window.draw(i->sprite);
			i->update(dt);
		}
        
        window.draw(score);
		
		for (auto i = suns.begin(); i != suns.end(); i++)
		{
			window.draw(i->sprite);
			i->update(dt);
			if (time.asSeconds() - i->createTime > FREE_SUN_MOVE_TIME)
				FreeSunStopper(i);
		}
		window.display();		
	}

	return 0;
}


void CreateNewZombie(std::vector <Zombie>& zombies, float time)
{
    if ((time > FREE_FROM_ZOMBIES_TIME) && (time - Zombie::lastCreateTime > INTEERVAL_BETWEEN_ZOMBIE_GENERATION))  
    {
        int numberOfLine = rand() % 5;
        zombies.push_back(Zombie (1024, (numberOfLine+1)*GRID.y - 55, "zombie/0.png", ZOMBIE_SPEED, time, numberOfLine));
        Zombie::lastCreateTime = time;
    }
}

template <typename T>
void MoveWithMouse(T& vec, sf::Vector2i mousePosition)
{
    mousePosition += sf::Vector2i(-30, -30);
    if ((vec.size() > 0) && vec.back().status == 0)
    {
        vec.back().sprite.setPosition(mousePosition.x, mousePosition.y);
    }
}

template <typename T>
void CallEat(std::vector <Zombie>::iterator i, T& vec)
{
	for (auto it = vec.begin(); it != vec.end(); it++)
	{
		if (i->pos.x - it->pos.x < 30 && i->pos.x > it->pos.x && i->numberOfLine == it->numberOfLine && i->status == 0 && it->status == 1)
		{
			i->speed.x = 0;
			i->status = 1;
			i->numberOfFrame = 0;
		}
	}
}

template <typename T>
void Eat(std::vector <Zombie>::iterator i, T& vec, float time, sf::Sound& chomp)
{
	for (auto it = vec.begin(); it != vec.end(); it++)
	{
        
		if (i->numberOfFrame == 12 && (time - i->lastEatingTime > ZOMBIE_FRAME_RATE) && (i->pos.x - it->pos.x) < 35 && abs(i->pos.y + 50 - it->pos.y) < 15)
		{
        
			it->health -= 1;
            
            chomp.play();
            
			i->lastEatingTime = time;
		}
		if (it->health <= 0)
		{
			i->status = 0;
			i->speed = ZOMBIE_SPEED;
			it = vec.erase(it);
			if (it == vec.end()) break;
		}
	}
}

void NutMoveWithMouse(std::vector <Nut>& nuts, sf::Vector2i mousePosition)
{
    mousePosition += sf::Vector2i(-30, -30);
    if ((nuts.size() > 0) && nuts.back().status == 0)
    {
        nuts.back().sprite.setPosition(mousePosition.x, mousePosition.y);
    }
}

void CreateNewNut(std::vector <Nut>& nuts, sf::Vector2i mousePosition, float time, Frame& nutFrame, sf::Text& score)
{
    if (mousePosition.x > 418 && mousePosition.x < 463 && mousePosition.y > 14 && mousePosition.y < 79)
    {
        int f = 0;
        if (nuts.size() == 0)
        {
            nuts.push_back(Nut((float)mousePosition.x, (float)mousePosition.y, "nut/0.png", NULL_SPEED, time));
            nuts.front().status = 1;
            f = 1;
        }
        if (nuts.size() > 0 && nuts.back().status == 1 && Sun::score >= 50)
        {
            nuts.push_back(Nut ((float)mousePosition.x, (float)mousePosition.y, "nut/0.png", NULL_SPEED, time));
            nuts.back().sprite.setTexture(nutFrame.texture);
            Sun::score -= 50;
            AccountUpdate(score);
            Nut::lastCreateTime = time;
        }
        if (f == 1)
            nuts.erase(nuts.begin());
    }

}

bool CheckGameEnd(std::vector <Zombie>::iterator i, sf::RenderWindow& window, sf::Music& music, sf::Music& losemusic)
{
    if (i->pos.x < 100)
    {
        sf::Font FontZoombie;
        FontZoombie.loadFromFile("images/fonts/gameover.ttf");
        sf::Text gameover1("The Zombie", FontZoombie, 100);
        sf::Text gameover2("ATE YOUR BRAINS", FontZoombie, 100);
        gameover1.setFillColor(sf::Color::Black);
        gameover2.setFillColor(sf::Color::Black);
        gameover1.setPosition(250, 200);
        gameover2.setPosition(100, 300);
        
        window.draw(gameover1);
        window.draw(gameover2);
        
        music.stop();
        
        if (gameStatus == 1)
        {
            losemusic.play();
            while (losemusic.getStatus() == 2)
            {}
        }
        
        return true;
    }
    
    return false;
    
}

void AccountUpdate(sf::Text& score)
{
    std::ostringstream ScoreString;
    ScoreString << Sun::score;
    score.setString(ScoreString.str());
    
    if(Sun::score < 100)
        score.setPosition(262, 59);
    
    if(Sun::score < 1000 && Sun::score >= 100)
        score.setPosition(257, 59);
    
    if(Sun::score < 10000 && Sun::score >= 1000)
        score.setPosition(250, 59);
    
    if(Sun::score < 100000 && Sun::score >= 10000)
        score.setPosition(245, 59);

}

void ZombieShooting(std::vector <Bullet>& bullets, sf::Sound& kernelpult)
{
	for (std::vector <Bullet>::iterator it = bullets.begin(); it != bullets.end(); it++)
	{
		if (it->pos.x > zombieForKilling[it->numberOfLine]->pos.x)
		{
				zombieForKilling[it->numberOfLine]->health -= 1;
            
            kernelpult.play();
            
				it = bullets.erase(it);
				if (it == bullets.end())
					break;
			
		}
	}
}

void CreateNewBullet(std::vector <Peas>::iterator i, vector <Bullet>& bullets, Frame& peaFrame, sf::Sound& shoot, float time)
{
    Bullet bul(i->pos.x+55, i->pos.y+12, "pea.png", BULLET_SPEED, i->numberOfLine);
	bullets.push_back(bul);
	bullets.back().sprite.setTexture(peaFrame.texture);
	bullets.back().sprite.setScale(0.25, 0.25);
    i->lastShootTime = time;
    
    shoot.play();
}

void CallShoot(vector <Zombie>& zombies)
{
	if (zombies.size() > 0)
	{
		int i = 0;
		while (i < 5)
		{
			zombieForKilling[i] = find_if(zombies.begin(), zombies.end(), [&](const Zombie& zombie)
			{
				return (zombie.numberOfLine == i) ? true : false;
			});
			if (((zombieForKilling[i] >= zombies.begin() && zombieForKilling[i] < zombies.end()) ||
					(zombies.back().numberOfLine == i)))
			callShoot[i] = 1;
			else
			callShoot[i] = 0;
			i++;
		}
	}
}

void CreateNewPeas(std::vector <Peas>& peases, sf::Vector2i mousePosition, float time, Frame& peasFrame, sf::Text& score)
{
	if (mousePosition.x > 349 && mousePosition.x < 393 && mousePosition.y > 10 && mousePosition.y < 70)
	{
		int f = 0;
		if (peases.size() == 0)
		{
			peases.push_back(Peas((float)mousePosition.x, (float)mousePosition.y, "peas/0.png", NULL_SPEED, time));
			peases.front().status = 1;
			f = 1;
		}
		if (peases.size() > 0 && peases.back().status == 1 && Sun::score >= 100)
		{
			peases.push_back(Peas ((float)mousePosition.x, (float)mousePosition.y, "peas/0.png", NULL_SPEED, time));
			peases.back().sprite.setTexture(peasFrame.texture);
			Sun::score -= 100;
            AccountUpdate(score);
			Peas::lastCreateTime = time;
		}
		if (f == 1)
			peases.erase(peases.begin());
	}
}

void PlantingPeas(vector <Peas>& peases, sf::Vector2i mousePosition, float time, sf::Sound& plant)
{
	if (peases.size() > 0 && peases.back().status == 0 && (time - Peas::lastCreateTime) > peases.back().plantTime
		&& mousePosition.x > OFFSET.x && mousePosition.x < 978 && mousePosition.y > OFFSET.y && mousePosition.y < 569)
	{
		int x = int((mousePosition.x - OFFSET.x) / GRID.x);
		int y = int((mousePosition.y - OFFSET.y) / GRID.y);
		peases.back().numberOfLine = y;
		x = OFFSET.x + x * GRID.x + GRID.x / 2 - 32;
		y = OFFSET.y + y * GRID.y + GRID.y / 2 - 40;
		peases.back().sprite.setPosition(x, y);
		peases.back().status = 1;
		peases.back().pos = sf::Vector2f(x,y);
        plant.play();
	}
}

void CreateNewSunflower(std::vector <Sunflower>& sunflowers, sf::Vector2i mousePosition, float time, Frame& sunflowerFrame, sf::Text& score)
{
	if (mousePosition.x > 305 && mousePosition.x < 346 && mousePosition.y > 9 && mousePosition.y < 69)
	{
		int f = 0;
		if (sunflowers.size() == 0)
		{
			sunflowers.push_back(Sunflower((float)mousePosition.x, (float)mousePosition.y, "sunflower/0.png", NULL_SPEED, time));
			sunflowers.front().status = 1;
			f = 1;
		}
		if (sunflowers.size() > 0 && sunflowers.back().status == 1 && Sun::score >= 50)
		{
			sunflowers.push_back(Sunflower ((float)mousePosition.x, (float)mousePosition.y, "sunflower/0.png", NULL_SPEED, time));
			sunflowers.back().sprite.setTexture(sunflowerFrame.texture);
			sunflowers.back().sprite.setScale(0.75f, 0.75f);
			Sun::score -= 50;
            AccountUpdate(score);
            
			Sunflower::lastCreateTime = time;
		}
		if (f == 1)
			sunflowers.erase(sunflowers.begin());
	}
}

void PlantingNut(vector <Nut>& nuts, sf::Vector2i mousePosition, float time, sf::Sound& plant)
{
    if (nuts.size() > 0 && nuts.back().status == 0 && (time - Nut::lastCreateTime) > nuts.back().plantTime
        && mousePosition.x > OFFSET.x && mousePosition.x < 978 && mousePosition.y > OFFSET.y && mousePosition.y < 569)
    {
        int x = int((mousePosition.x - OFFSET.x) / GRID.x);
        int y = int((mousePosition.y - OFFSET.y) / GRID.y);
		nuts.back().numberOfLine = y;
        x = OFFSET.x + x * GRID.x + GRID.x / 2 - 30;
        y = OFFSET.y + y * GRID.y + GRID.y / 2 - 37;
        nuts.back().sprite.setPosition(x,y);
        nuts.back().status = 1;
		nuts.back().pos = sf::Vector2f(x, y);
        plant.play();
    }
}

void PlantingSunflower(vector <Sunflower>& sunflowers, sf::Vector2i mousePosition, float time, sf::Sound& plant)
{
	if (sunflowers.size() > 0 && sunflowers.back().status == 0 && (time - Sunflower::lastCreateTime) > sunflowers.back().plantTime
		&& mousePosition.x > OFFSET.x && mousePosition.x < 978 && mousePosition.y > OFFSET.y && mousePosition.y < 569)
	{
		int x = int((mousePosition.x - OFFSET.x) / GRID.x);
		int y = int((mousePosition.y - OFFSET.y) / GRID.y);
		sunflowers.back().numberOfLine = y;
		x = OFFSET.x + x * GRID.x + GRID.x / 2 - 36;
		y = OFFSET.y + y * GRID.y + GRID.y / 2 - 50;
		sunflowers.back().sprite.setPosition(x,y);
		sunflowers.back().lastCreateSunTime = time;
		sunflowers.back().status = 1;
		sunflowers.back().pos = sf::Vector2f(x, y);
        plant.play();
	}
}

void CreateNewSun(std::vector <Sun>& suns, float time, Frame& sunFrame, std::vector <Sunflower>::iterator i)
{
	if ((i->status == 1) && (time - i->lastCreateSunTime > INTERVAL_BETWEEN_SUN_GENERATION))
	{
		suns.push_back(Sun(i->pos.x - 10, i->pos.y - 45, "sun.png", NULL_SPEED, time, 0));
		suns.back().sprite.setTexture(sunFrame.texture);
		i->lastCreateSunTime = time;
	}
}

void CreateNewFreeSun(std::vector <Sun>& suns, float time, Frame& sunFrame)
{
	if (time - Sun::lastCreateTime > INTERVAL_BETWEEN_FREE_SUN_GENERATION)
	{
		suns.push_back(Sun(rand() % (9 * GRID.x) + OFFSET.x, rand() % (2 * GRID.y) + OFFSET.y, "sun.png", SUN_SPEED, time, 0));
		suns.back().sprite.setTexture(sunFrame.texture);
		Sun::lastCreateTime = time;
	}
}

void Download(std::vector <Frame>& frames, int count, std::string nameOfFrameType)
{
	std::string path;

	for (int i = 0; i < count; i++)
	{
		path = nameOfFrameType + "/" + std::to_string(i) + ".png";
		frames.push_back(Frame(path));
	}

}

void FreeSunStopper(std::vector<Sun>::iterator i)
{
	i->speed.y = 0;
}

void ClickOnSun(std::vector <Sun>& suns, sf::Vector2i mousePosition, sf::Text& score, sf::Sound& getSun)
{
	for (std::vector<Sun>::iterator i = suns.begin(); i != suns.end(); i++)
	{
		sf::Vector2f center(i->sprite.getPosition().x + 40, i->sprite.getPosition().y + 40);
		sf::Vector2f d = sf::Vector2f(float(mousePosition.x), float(mousePosition.y)) - center;
		if (std::abs(d.x) < 30 && std::abs(d.y) < 30)
		{
			Sun::score += 50;
            getSun.play();
            AccountUpdate(score);
			i = suns.erase(i);
			if (i == suns.end())
				break;
		}
	}
}

template <typename T>
void SwapFrame(T i, std::vector <Frame>& frames, float time, float FrameRate)
{
    if (time - i->lastUpdateTime > FrameRate)
    {
        i->sprite.setTexture(frames[i->numberOfFrame].texture);
        if ((i->numberOfFrame) < frames.size() - 1)
            i->numberOfFrame++;
        else
            i->numberOfFrame -= (frames.size() - 1);
        i->lastUpdateTime = time;
    }
}



