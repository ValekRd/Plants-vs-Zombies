#include <SFML\Graphics.hpp>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>

class Object
{
public:
	sf::Vector2f position;
	sf::Texture texture;
	sf::Sprite sprite;

	Object(float _x, float _y, std::string filename)
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

	Sun(float _x, float _y, std::string filename) : Object(_x, _y, filename)
	{}
};

class Plans : public Object
{
public:
	int health;

	Plans(float _x, float _y, std::string filename, int _health) : Object(_x, _y, filename), health(_health)
	{}
};

class Zombie : public Object
{
public:
	sf::Vector2f velocity;
	int health;

	Zombie(float _x, float _y, std::string filename, int _health, float _Vx, float _Vy) : Object(_x, _y, filename), health(_health)
	{
		velocity.x = _Vx;
		velocity.y = _Vy;
	}
};

int Sun::score = 0;

int main()
{
  sf::RenderWindow window(sf::VideoMode(1024, 600), "My window");

  Object fon(0, 0, "fone.png");

  //create sun

  std::vector<Sun> stars;

  sf::Texture sun_texture;
  sun_texture.loadFromFile("sun.png");
  sf::Sprite sun_sprite;
  sun_sprite.setTexture(sun_texture);
  sun_sprite.setScale(0.5f, 0.5f);
  sun_sprite.setPosition(rand() % 600 + 200, rand() % 300 + 50);

  //create tabl_sun
  Object tabl_sun(230, 0, "tabl_sun.png");
  tabl_sun.sprite.setScale(0.9f, 0.9f);

  //download numbers for sun
  sf::Texture num_tex[10];
  num_tex[0].loadFromFile("0.png");
  num_tex[1].loadFromFile("1.png");
  num_tex[2].loadFromFile("2.png");
  num_tex[3].loadFromFile("3.png");
  num_tex[4].loadFromFile("4.png");
  num_tex[5].loadFromFile("5.png");
  num_tex[6].loadFromFile("6.png");
  num_tex[7].loadFromFile("7.png");
  num_tex[8].loadFromFile("8.png");
  num_tex[9].loadFromFile("9.png");

  //and create sprite for numbers
  sf::Sprite Num[10];
  for (int i = 0; i < 10; i++)
  {
	  Num[i].setTexture(num_tex[i]);
  }

  //use time
  sf::Clock clock;
  float last_create_sun_time = 0;

  while (window.isOpen())
  {
	  window.draw(fon.sprite);
	  window.draw(tabl_sun.sprite);
	  Num[0].setPosition(270, 61);
	  window.draw(Num[0]);
	
	  sf::Time time = clock.getElapsedTime();

	  ////////////////////////////////////////// sun 

	  if (time.asSeconds() - last_create_sun_time > 6)				
	  {
		  if (time.asSeconds() - last_create_sun_time < 16)
		  {
			  if (time.asSeconds() - last_create_sun_time < 8)
			  {
				  sf::Vector2f center = sun_sprite.getPosition();
				  sun_sprite.setPosition(center.x, center.y + 0.5 * (time.asSeconds() - last_create_sun_time));
			  }
			  window.draw(sun_sprite);

			  sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
			  sf::Vector2f center = sun_sprite.getPosition();
			  center.x += 40;				//this strings decide real poin center
			  center.y += 40;

			  sf::Vector2f d = sf::Vector2f(mousePosition.x, mousePosition.y) - center;

			  //if you can touch on sun
			  if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && abs(d.x) < 30 && abs(d.y) < 30)
			  {
				  Sun::score += 50;
				  last_create_sun_time = time.asSeconds();
				  sun_sprite.setPosition(rand() % 600 + 200, rand() % 300 + 50);
			  }

		  }
		  else
		  {
			  last_create_sun_time = time.asSeconds();
			  sun_sprite.setPosition(rand() % 600 + 200, rand() % 300 + 50);
		  }

	  }		 

	  //////////////////////////////////////////////////// score

	  //check second number
	  if (Sun::score % 100 / 10 == 5)
	  {
		  Num[5].setPosition(259, 61);
		  window.draw(Num[5]);
	  }
	  if (Sun::score % 100 / 10 == 0 && Sun::score > 50)
	  {
		  Num[0].setPosition(259, 61);
		  window.draw(Num[0]);
	  }
	  //check third number  
	  for (int i = 1; i < 10; i++)
	  {
		  if (Sun::score % 1000 / 100 == i)
		  {
			  Num[i].setPosition(248, 61);
			  window.draw(Num[i]);
		  }
	  }

      ////////////////////////////////////////////////////
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