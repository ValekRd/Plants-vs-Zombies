#include "C:\Users\user\Desktop\Ïðîåêò\TestSFML\vc2015project\testSFML\testSFML\Objects.h"
#include "C:\Users\user\Desktop\Ïðîåêò\TestSFML\vc2015project\testSFML\testSFML\Ñonstants.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>

void Download(std::vector <Frame>* frames, int count, std::string nameOfFrameType);

void CreateNewFreeSun(std::vector <Sun>* suns, float time, Frame* sunFrame);

void CreateNewZombie(std::vector <Zombie>* zombies, float time);

void CreateNewSunflower(std::vector <Sunflower>* sunflowers, sf::Vector2i mousePosition, float time);

void CreateNewPeas(std::vector <Peas>* peases, sf::Vector2i mousePosition, float time);

void PlantingSunflower(vector <Sunflower>* sunflowers, sf::Vector2i mousePosition, float time);  //update

void PlantingPeas(vector <Peas>* peases, sf::Vector2i mousePosition, float time);

void SunflowerMoveWithMouse(vector <Sunflower>* sunflowers, sf::Vector2i mousePosition);	//update

void PeasMoveWithMouse(vector <Peas>* peases, sf::Vector2i mousePosition);

void SwapSunflowerFrame(std::vector <Sunflower>::iterator i, std::vector <Frame>* frames, float time);

void SwapPeasFrame(std::vector<Peas>::iterator i, std::vector <Frame>* frames, float time);

void SwapZombieFrame(std::vector<Zombie>::iterator i, std::vector <Frame>* frames, float time);

void ClickOnSun(std::vector <Sun>* suns, sf::Vector2i mousePosition);

void FreeSunStopper(std::vector<Sun>::iterator i);

int Sun::score = 10000;
float Sun::lastCreateTime = 0;
float Zombie::lastCreateTime = 0;
float Peas::lastCreateTime = 0;
float Sunflower::lastCreateTime = 0;
int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), "My Plants VS Zombies");
	Object background(0, 0, "fone.png", NULL_SPEED);
	Object topPanel(TOP_PANEL_POSITION_X, TOP_PANEL_POSITION_Y, "top_panel.png", NULL_SPEED);
	vector <Frame> digitFrames(0);
	std::vector <Frame> sunflowerFrames(0);
	std::vector <Frame> zombieFrames(0);
	std::vector <Frame> peasFrames(0);
	Frame sunFrame("sun.png");
	Download(&digitFrames, NUM_OF_DIGIT_FRAMES, "digit");
	Download(&sunflowerFrames, NUM_OF_SUNFLOWER_FRAMES, "sunFlower");
	Download(&zombieFrames, NUM_OF_ZOMBIE_FRAMES, "zombie");
	Download(&peasFrames, NUM_OF_PEAS_FRAMES, "peas");
	/*vector <Bullet> bullets;*/
	sf::Clock clock;
	std::vector <Sun> suns;
	std::vector <Zombie> zombies;
	std::vector <Sunflower> sunflowers;
	std::vector <Peas> peases;
	while (window.isOpen())
	{

		sf::Time time = clock.getElapsedTime();
		window.draw(background.sprite);
		window.draw(topPanel.sprite);
		digitFrames[0].sprite.setPosition(270, 61);
		window.draw(digitFrames[0].sprite);
		CreateNewFreeSun(&suns, time.asSeconds(), &sunFrame);
		CreateNewZombie(&zombies, time.asSeconds());

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
				ClickOnSun(&suns, mousePosition);
				CreateNewSunflower(&sunflowers, mousePosition, time.asSeconds());
				PlantingSunflower(&sunflowers, mousePosition, time.asSeconds());
				CreateNewPeas(&peases, mousePosition, time.asSeconds());
				PlantingPeas(&peases, mousePosition, time.asSeconds());
			}
		}
		SunflowerMoveWithMouse(&sunflowers, sf::Mouse::getPosition(window));
		PeasMoveWithMouse(&peases, sf::Mouse::getPosition(window));

		for (auto i = zombies.begin(); i != zombies.end(); i++)
		{
			window.draw(i->sprite);
			SwapZombieFrame(i, &zombieFrames, time.asSeconds());
			i->update(dt);
		}
		for (auto i = sunflowers.begin(); i != sunflowers.end(); i++)
		{
			window.draw(i->sprite);
			SwapSunflowerFrame(i, &sunflowerFrames, time.asSeconds());
		}
		for (auto i = peases.begin(); i != peases.end(); i++)
		{
			window.draw(i->sprite);
			SwapPeasFrame(i, &peasFrames, time.asSeconds());
		}

		//check second number
		if (Sun::score % 100 / 10 == 5)
		{
			digitFrames[5].sprite.setPosition(259, 61);
			window.draw(digitFrames[5].sprite);
		}
		if (Sun::score % 100 / 10 == 0 && Sun::score > 50)
		{
			digitFrames[0].sprite.setPosition(259, 61);
			window.draw(digitFrames[0].sprite);
		}
		//check third number
		for (int i = 1; i < 10; i++)
		{
			if (Sun::score % 1000 / 100 == i)
			{
				digitFrames[i].sprite.setPosition(248, 61);
				window.draw(digitFrames[i].sprite);
			}
		}
		for (auto i = suns.begin(); i != suns.end(); i++)
		{
			window.draw(i->sprite);
			i->update(dt);
			if (time.asSeconds() - i->createTime > FREE_SUN_MOVE_TIME)
				FreeSunStopper(i);
		}
		//create sunflower's stars
		/*
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
		//create bullet
		/*
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

		//draw bullets
		for (auto i = bullets.begin(); i != bullets.end(); i++)
		{
		window.draw(i->sprite);
		}
		//////////////////////////////////////////////////// score
		} */
		window.display();
	}

	return 0;
}

void CreateNewPeas(std::vector <Peas>* peases, sf::Vector2i mousePosition, float time)
{
	if (mousePosition.x > 349 && mousePosition.x < 393 && mousePosition.y > 10 && mousePosition.y < 70)
	{
		int f = 0;
		if ((*peases).size() == 0)
		{
			peases->push_back(Peas((float)mousePosition.x, (float)mousePosition.y, "peas/0.png", NULL_SPEED, time));
			(*peases).front().status = 1;
			f = 1;
		}
		if ((*peases).size() > 0 && (*peases).back().status == 1 && Sun::score >= 100)
		{
			Peas peas((float)mousePosition.x, (float)mousePosition.y, "peas/0.png", NULL_SPEED, time);
			peases->push_back(peas);
			Sun::score -= 100;
			Peas::lastCreateTime = time;
			cout << "create" << endl;
		}
		if (f == 1)
			(*peases).erase((*peases).begin());
	}
}

void PlantingPeas(vector <Peas>* peases, sf::Vector2i mousePosition, float time)
{
	if ((*peases).size() > 0 && (*peases).back().status == 0 && (time - Peas::lastCreateTime) > (*peases).back().plantTime
		&& mousePosition.x > OFFSET.x && mousePosition.x < 978 && mousePosition.y > OFFSET.y && mousePosition.y < 569)
	{
		int x = int((mousePosition.x - OFFSET.x) / GRID.x);
		int y = int((mousePosition.y - OFFSET.y) / GRID.y);
		x = OFFSET.x + x * GRID.x + GRID.x / 2 - 36;
		y = OFFSET.y + y * GRID.y + GRID.y / 2 - 50;
		(*peases).back().sprite.setPosition(x, y);
		(*peases).back().status = 1;
	}
}

void CreateNewSunflower(std::vector <Sunflower>* sunflowers, sf::Vector2i mousePosition, float time)
{
	if (mousePosition.x > 305 && mousePosition.x < 346 && mousePosition.y > 9 && mousePosition.y < 69)
	{
		int f = 0;
		if ((*sunflowers).size() == 0)
		{
			sunflowers->push_back(Sunflower((float)mousePosition.x, (float)mousePosition.y, "sunflower/0.png", NULL_SPEED, time));
			(*sunflowers).front().status = 1;
			f = 1;
		}
		if ((*sunflowers).size() > 0 && (*sunflowers).back().status == 1 && Sun::score >= 50)
		{
			Sunflower sunflower((float)mousePosition.x, (float)mousePosition.y, "sunflower/0.png", NULL_SPEED, time);
			sunflower.sprite.setScale(0.75f, 0.75f);
			sunflowers->push_back(sunflower);
			Sun::score -= 50;
			Sunflower::lastCreateTime = time;
		}
		if (f == 1)
			(*sunflowers).erase((*sunflowers).begin());
	}
}

void PeasMoveWithMouse(vector <Peas>* peases, sf::Vector2i mousePosition)
{
	if (((*peases).size() > 0) && (*peases).back().status == 0)
	{
		(*peases).back().sprite.setPosition(mousePosition.x, mousePosition.y);
	}
}

void SunflowerMoveWithMouse(vector <Sunflower>* sunflowers, sf::Vector2i mousePosition)
{
	if (((*sunflowers).size() > 0) && (*sunflowers).back().status == 0)
	{
		(*sunflowers).back().sprite.setPosition(mousePosition.x, mousePosition.y);
	}
}

void PlantingSunflower(vector <Sunflower>* sunflowers, sf::Vector2i mousePosition, float time)
{
	if ((*sunflowers).size() > 0 && (*sunflowers).back().status == 0 && (time - Sunflower::lastCreateTime) > (*sunflowers).back().plantTime
		&& mousePosition.x > OFFSET.x && mousePosition.x < 978 && mousePosition.y > OFFSET.y && mousePosition.y < 569)
	{
		int x = int((mousePosition.x - OFFSET.x) / GRID.x);
		int y = int((mousePosition.y - OFFSET.y) / GRID.y);
		x = OFFSET.x + x * GRID.x + GRID.x / 2 - 36;
		y = OFFSET.y + y * GRID.y + GRID.y / 2 - 50;
		(*sunflowers).back().sprite.setPosition(x, y);
		(*sunflowers).back().lastCreateSunTime = time;
		(*sunflowers).back().status = 1;
	}
}

void CreateNewFreeSun(std::vector <Sun>* suns, float time, Frame *sunFrame)
{
	if (time - Sun::lastCreateTime > INTERVAL_BETWEEN_FREE_SUN_GENERATION)
	{
		suns->push_back(Sun(rand() % (9 * GRID.x) + OFFSET.x, rand() % (2 * GRID.y) + OFFSET.y, "sun.png", SUN_SPEED, time, 0));
		(*suns).back().sprite.setTexture((*sunFrame).texture);
		Sun::lastCreateTime = time;
	}
}

void Download(std::vector <Frame>* frames, int count, std::string nameOfFrameType)
{
	std::string path;

	for (int i = 0; i < count; i++)
	{
		path = nameOfFrameType + "/" + std::to_string(i) + ".png";
		frames->push_back(Frame(path));
	}

}

void FreeSunStopper(std::vector<Sun>::iterator i)
{
	i->speed.y = 0;
}

void CreateNewZombie(std::vector <Zombie>* zombies, float time)
{
	if ((time > FREE_FROM_ZOMBIES_TIME) && (time - Zombie::lastCreateTime > INTEERVAL_BETWEEN_ZOMBIE_GENERATION))
	{
		zombies->push_back(Zombie(1000, (rand() % 5 + 1)* GRID.y - 55, "zombie/0.png", ZOMBIE_SPEED, time));
		Zombie::lastCreateTime = time;
	}
}

void ClickOnSun(std::vector <Sun>* suns, sf::Vector2i mousePosition)
{
	for (std::vector<Sun>::iterator i = (*suns).begin(); i != (*suns).end(); i++)
	{
		sf::Vector2f center(i->sprite.getPosition().x + 40, i->sprite.getPosition().y + 40);
		sf::Vector2f d = sf::Vector2f(float(mousePosition.x), float(mousePosition.y)) - center;
		if (std::abs(d.x) < 30 && std::abs(d.y) < 30)
		{
			Sun::score += 50;
			i = (*suns).erase(i);
			if (i == (*suns).end())
				break;
		}
	}
}

void SwapZombieFrame(std::vector<Zombie>::iterator i, std::vector <Frame>* frames, float time)
{
	if (time - i->lastUpdateTime > ZOMBIE_FRAME_RATE)
	{
		i->sprite.setTexture((*frames)[i->numberOfFrame].texture);
		if ((i->numberOfFrame) < (*frames).size() - 1)
			i->numberOfFrame++;
		else
			i->numberOfFrame -= ((*frames).size() - 1);
		i->lastUpdateTime = time;
	}
}

void SwapSunflowerFrame(std::vector<Sunflower>::iterator i, std::vector <Frame>* frames, float time)
{
	if (time - i->lastUpdateTime > SUNFLOWER_FRAME_RATE)
	{
		i->sprite.setTexture((*frames)[i->numberOfFrame].texture);
		if ((i->numberOfFrame) < (*frames).size() - 1)
			i->numberOfFrame++;
		else
			i->numberOfFrame -= ((*frames).size() - 1);
		i->lastUpdateTime = time;
	}
}

void SwapPeasFrame(std::vector<Peas>::iterator i, std::vector <Frame>* frames, float time)
{
	if (time - i->lastUpdateTime > PEAS_FRAME_RATE)
	{
		i->sprite.setTexture((*frames)[i->numberOfFrame].texture);
		if ((i->numberOfFrame) < (*frames).size() - 1)
			i->numberOfFrame++;
		else
			i->numberOfFrame -= ((*frames).size() - 1);
		i->lastUpdateTime = time;
	}
}

