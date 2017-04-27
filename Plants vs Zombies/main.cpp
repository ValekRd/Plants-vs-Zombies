//from src
#include "Objects.h"
#include "Сonstants.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;
/* ◊“Œ ›“Œ ¬ŒŒ¡Ÿ≈???
float Sunflower::last_create_time = 0;
int Sunflower::health = 100;
int Sunflower::count = 0;
int Sunflower::status = 2;

int Sun::score = 1000;
float Sun::last_create_time = 0;
int Sun::count = 0;
float Zombie::last_create_time = 0;
int Zombie::count = 0;

float Peas::last_create_time = 0;
int Peas::status = 2;
int Peas::count = 0;

*/



void Download(vector <Frame>* frames, int count, string nameOfFrameType)
{
	string path;
	for (int i = 0; i < count; i++)
	{
		path = nameOfFrameType + "/" + to_string(i) + ".png";
		//Frame frame = Frame(path);
		frames->push_back (*(new Frame(path)));
		//frames->push_back(frame);
	}
	//delete path;
}

void CreateNewFreeSun(vector <Sun>* suns, float time)
{
	suns->push_back (*(new Sun(rand() % (9 * GRID.x) + OFFSET.x, rand() % (2 * GRID.y) + OFFSET.y, "sun.png", SUN_SPEED, time, 0)));
	Sun::lastCreateTime = time;
	cout << "SUN!!!" << endl;
}
void FreeSunStopper(vector<Sun>::iterator i)
{
	i->speed.y = 0;
}
void CreateNewZombie(vector <Zombie>* zombies, float time)
{
	zombies->push_back(*(new Zombie(900, (rand() % 5 + 1)* GRID.y - 55, "zombie.png", ZOMBIE_SPEED, time)));
	Zombie::lastCreateTime = time;
}
void CreateNewSunflower(vector <Sunflower>* sunflowers, sf::Vector2i mousePosition, float time)
{
	if (Sun::score >= 50 && mousePosition.x > 305 && mousePosition.x < 346 && mousePosition.y > 9 && mousePosition.y < 69 && Sunflower::status == 2)
	{
		Sunflower::status = 1;
		//sunflower.sprite.setTexture(sunflower_frames[0].texture);
		//sunflower.sprite.setScale(0.75f, 0.75f);
		sunflowers->push_back(*(new Sunflower((float)mousePosition.x, (float)mousePosition.y, "sunflower.png", NULL_SPEED, time)));
		Sun::score -= 50;
		Sunflower::lastCreateTime = time;
	}
}
void CreateNewPeas(vector <Peas>* peases, sf::Vector2i mousePosition, float time)
{
	if (Sun::score >= 100 && mousePosition.x > 352 && mousePosition.x < 394 && mousePosition.y > 9 && mousePosition.y < 69 && Peas::status == 2)
	{
		Peas::status = 1;
		//peas.sprite.setTexture(peas_frames[0].texture);
		//peas.sprite.setScale(0.75f, 0.75f);
		peases->push_back(*(new Peas ((float)mousePosition.x, (float)mousePosition.y, "peas.png", NULL_SPEED, time)));
		Sun::score -= 100;
		Peas::lastCreateTime = time;
	}
}
void ClickOnSun(vector <Sun>* suns, sf::Vector2i mousePosition)
{
	for (vector<Sun>::iterator i = (*suns).begin(); i != (*suns).end(); i++)
	{
		sf::Vector2f center (i->sprite.getPosition().x + 40, i->sprite.getPosition().y + 40);
		sf::Vector2f d = sf::Vector2f(float(mousePosition.x), float(mousePosition.y)) - center;
		if (std::abs(d.x) < 30 && std::abs(d.y) < 30)
		{
			Sun::score += 50;
			(*suns).erase(i);
			if (i == (*suns).end())
				break;
		}
	}
}
void SwapZombieFrame(vector<Zombie>::iterator i, vector <Frame>* frames, float time, int count)
{
	if (time - i->lastUpdateTime > 0.2)
	{
		i->sprite.setTexture((*frames)[i->numberOfFrame].texture);
		//i->sprite.setScale(0.5, 0.5);
		if ((i->numberOfFrame) < (*frames).size())
			i->numberOfFrame++;
		else
			i->numberOfFrame -= count; //(*frames).size();
		i->lastUpdateTime = time;
		cout << "frame "<< i->numberOfFrame << endl;
	}
}


int Sun::score = 0;
float Sun::lastCreateTime = 0;
int Sunflower::status = 2;
int Peas::status = 2;
float Zombie::lastCreateTime = 0;
float Peas::lastCreateTime = 0;
float Sunflower::lastCreateTime = 0;
int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), "My Plants VS Zombies");
	Object background(0, 0, "fone.png", NULL_SPEED);
	Object topPanel (TOP_PANEL_POSITION_X, TOP_PANEL_POSITION_Y,"top_panel.png", NULL_SPEED);
	//vector <Frame> digitFrames(NUM_OF_DIGIT_FRAMES);
	//vector <Frame> sunflowerFrames(NUM_OF_SUNFLOWER_FRAMES);
	vector <Frame> zombieFrames(NUM_OF_ZOMBIE_FRAMES);
	//vector <Frame> peasFrames(NUM_OF_PEAS_FRAMES);
	//Download(&digitFrames, NUM_OF_DIGIT_FRAMES, "digit");
	//Download(&sunflowerFrames, NUM_OF_SUNFLOWER_FRAMES, "sunFlower");
	Download(&zombieFrames, NUM_OF_ZOMBIE_FRAMES, "zombie");
	//Download(&peasFrames, NUM_OF_PEAS_FRAMES, "peas");
	//create our objects
	/*vector <Bullet> bullets;*/
	
	sf::Clock clock;
	vector <Sun> suns;
	vector <Zombie> zombies;
	vector <Sunflower> sunflowers;
	vector <Peas> peases;
	int f = 0;
	while (window.isOpen())
	{
		sf::Time time = clock.getElapsedTime();
		window.draw(background.sprite);
		window.draw(topPanel.sprite);
		//digitFrames[0].sprite.setPosition(270, 61);
		//window.draw(digitFrames[0].sprite);
		if (time.asSeconds() - Sun::lastCreateTime > INTERVAL_BETWEEN_FREE_SUN_GENERATION)
		{
				CreateNewFreeSun(&suns, time.asSeconds());
		}
		for (vector<Sun>::iterator i = suns.begin(); i != suns.end(); i++)
		{
			window.draw(i->sprite);
			i->update(dt);
			if (time.asSeconds() - i->createTime > FREE_SUN_MOVE_TIME) FreeSunStopper(i);
		} // ÓÚËÒÓ‚Í‡ + ‡Ô‰˝ÈÚ + ÒÚÓÔ‡ÚÓ
		if ((time.asSeconds() > FREE_FROM_ZOMBIES_TIME) && (time.asSeconds() - Zombie::lastCreateTime > INTEERVAL_BETWEEN_ZOMBIE_GENERATION))
		{
			if (f == 0)
			{
				CreateNewZombie(&zombies, time.asSeconds());
				f = 1;
			}
		}
		for (vector<Zombie>::iterator i = zombies.begin(); i != zombies.end(); i++)
		{
			window.draw(i->sprite);
			SwapZombieFrame(i, &zombieFrames, time.asSeconds(), NUM_OF_ZOMBIE_FRAMES);
			i->update(dt);
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
			ClickOnSun(&suns, mousePosition);	
			CreateNewSunflower(&sunflowers, mousePosition, time.asSeconds());
			CreateNewPeas(&peases, mousePosition, time.asSeconds()); 
		}
		/*		
		if (Sunflower::status == 1)
		{
			sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
			sunflowers.back().sprite.setPosition(mousePosition.x - 30, mousePosition.y - 30);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (time.asSeconds() - Sunflower::last_create_time) > time_planting
				&& mousePosition.x > offset_x && mousePosition.x < 978 && mousePosition.y > offset_y && mousePosition.y < 569)
			{
				sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

				int x = int((mousePosition.x - offset_x) / grid_x);
				int y = int((mousePosition.y - offset_y) / grid_y);
				x = offset_x + x * grid_x + grid_x / 2 - 36;
				y = offset_y + y * grid_y + grid_y / 2 - 50;
				sunflowers.back().sprite.setPosition(x, y);
				sunflowers.back().last_create_sun_time = time.asSeconds();
				Sunflower::status = 2;
			}
		}


		if (Peas::status == 1)
		{
			sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
			peases.back().sprite.setPosition(mousePosition.x - 30, mousePosition.y - 30);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (time.asSeconds() - Peas::last_create_time) > time_planting
				&& mousePosition.x > offset_x && mousePosition.x < 978 && mousePosition.y > offset_y && mousePosition.y < 569)
			{
				sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

				int x = int((mousePosition.x - offset_x) / grid_x);
				int y = int((mousePosition.y - offset_y) / grid_y);
				x = offset_x + x * grid_x + grid_x / 2 - 36;
				y = offset_y + y * grid_y + grid_y / 2 - 50;
				peases.back().sprite.setPosition(x, y);
				Peas::status = 2;
			}
		}


		//create sunflower's stars
		if (Sunflower::status == 2)
		{
			for (auto i = sunflowers.begin(); i != sunflowers.end(); i++)
			{
				if (time.asSeconds() - i->last_create_sun_time > 10)
				{
					Sun sun;
					sun.sprite.setTexture(sun_texture);
					sun.sprite.setScale(0.5f, 0.5f);
					sun.create_time = time.asSeconds();
					sun.whose_sun = 1;
					sf::Vector2f center_cun = i->sprite.getPosition();
					sun.sprite.setPosition(center_cun.x + 30, center_cun.y - 30);
					stars.push_back(sun);
					i->last_create_sun_time = time.asSeconds();
					Sun::count++;

					if (Sunflower::status == 1 && i == (sunflowers.end() - 2))
						break;
				}
			}
		}
		*/
		//update frames of sunflowers
		/*if (Sunflower::status == 2)
		{
			for (auto i = sunflowers.begin(); i != sunflowers.end(); i++)
			{
				if (time.asSeconds() - i->last_update_time > 0.02)
				{
					i->sprite.setTexture(sunflower_frames[i->number_of_frame].texture);
					if (i->number_of_frame < 59)
					{
						i->number_of_frame++;
					}
					else
					{
						i->number_of_frame -= 59;
					}
					i->last_update_time = time.asSeconds();

					if (Sunflower::status == 1 && i == (sunflowers.end() - 2))
						break;
				}
			}
		}

		//update frames of peas and create bullets
		if (Peas::status == 2)
		{
			for (auto i = peases.begin(); i != peases.end(); i++)
			{
				if (time.asSeconds() - i->last_update_time > 0.02)
				{
					i->sprite.setTexture(peas_frames[i->number_of_frame].texture);
					if (i->number_of_frame < 59)
					{
						i->number_of_frame++;

						//create bullet
						if (i->number_of_frame == 33)
						{
							Bullet bul;
							bul.sprite.setTexture(bul_texture);
							bul.sprite.setScale(0.3f, 0.3f);
							sf::Vector2f center = i->sprite.getPosition();
							bul.sprite.setPosition(center.x + 55, center.y + 14);
							bul.create_time = time.asSeconds();
							bullets.push_back(bul);
						}

					}
					else
					{
						i->number_of_frame -= 59;
					}
					i->last_update_time = time.asSeconds();
				}

				if (Peas::status == 1 && i == (peases.end() - 2))
					break;
			}
		}


		//update bullets
		for (auto i = bullets.begin(); i != bullets.end(); i++)
		{
			sf::Vector2f current_point = i->sprite.getPosition();
			i->sprite.setPosition(current_point.x + 1, current_point.y);
		}


		//update frames of zombie
		for (auto i = zombies.begin(); i != zombies.end(); i++)
		{
			if (time.asSeconds() - i->last_update_time > 0.2)
			{
				i->sprite.setTexture(zombie_frames[i->number_of_frame].texture);
				if (i->number_of_frame < 92)
				{
					i->number_of_frame++;
				}
				else
				{
					i->number_of_frame -= 92;
				}
				i->last_update_time = time.asSeconds();
			}
		}


		//draw sunflowers
		for (auto i = sunflowers.begin(); i != sunflowers.end(); i++)
		{
			window.draw(i->sprite);
		}


		//draw zombies
		for (auto i = zombies.begin(); i != zombies.end(); i++)
		{
			window.draw(i->sprite);
		}


		//draw peas
		for (auto i = peases.begin(); i != peases.end(); i++)
		{
			window.draw(i->sprite);
		}


		//draw bullets
		for (auto i = bullets.begin(); i != bullets.end(); i++)
		{
			window.draw(i->sprite);
		}


		//draw stars
		for (std::vector<Sun>::iterator i = stars.begin(); i != stars.end(); i++)
		{
			window.draw(i->sprite);
		}


		//////////////////////////////////////////////////// score

		//check second number
		if (Sun::score % 100 / 10 == 5)
		{
			numbers[5].sprite.setPosition(259, 61);
			window.draw(numbers[5].sprite);
		}
		if (Sun::score % 100 / 10 == 0 && Sun::score > 50)
		{
			numbers[0].sprite.setPosition(259, 61);
			window.draw(numbers[0].sprite);
		}
		//check third number
		for (int i = 1; i < 10; i++)
		{
			if (Sun::score % 1000 / 100 == i)
			{
				numbers[i].sprite.setPosition(248, 61);
				window.draw(numbers[i].sprite);
			}
		} */

		window.display();

		//close the window
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}

	return 0;
}
