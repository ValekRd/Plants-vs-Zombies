#include "Objects.cpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>


float Sunflower::last_create_time = 0;
int Sunflower::health = 100;
int Sunflower::count = 0;
int Sunflower::status = 2;

int Sun::score = 1000;
float Sun::last_create_time = 0;
int Sun::count = 0;

int grid_x = 80;
int grid_y = 96;
int offset_x = 258;
int offset_y = 89;
float time_planting = 0.5;
float free_from_zombies_time = 0;

float Zombie::last_create_time = 0;
int Zombie::count = 0;

float Peas::last_create_time = 0;
int Peas::status = 2;
int Peas::count = 0;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1024, 600), "My window");
    
    
    //create fon
    Object fon;
    fon.set_for_static_object(0, 0, "fone.png");
    
    
    //create stars
    std::vector<Sun> stars;
    
    
    //create top panel
    Object top_panel;
    top_panel.set_for_static_object(230, 0, "top_panel.png");
    top_panel.sprite.setScale(0.9f, 0.9f);
    
    
    //create numbers
    std::vector<Number> numbers(10);
    for(int i = 0; i < 10; i++)
    {
        std::string string = std::to_string(i);
        string = "numbers/" + string + ".png";
        numbers[i].texture.loadFromFile(string);
    }
    for (int i = 0; i < 10; i++)
    {
        numbers[i].sprite.setTexture(numbers[i].texture);
    }
    
    
    //create sunflower frames
    std::vector<Sunflower_frames> sunflower_frames(60);
    for(int i = 0; i < 60; i++)
    {
        std::string string = std::to_string(i);
        string = "sun/" + string + ".png";
        sunflower_frames[i].texture.loadFromFile(string);
    }
    
    
    //create zombie frames
    std::vector<Zombie_frames> zombie_frames(93);
    for(int i = 0; i < 93; i++)
    {
        std::string string = std::to_string(i);
        string = "zombie/" + string + ".png";
        zombie_frames[i].texture.loadFromFile(string);
    }
    
    
    //create peas
    std::vector<Peas_frames> peas_frames(60);
    for(int i = 0; i < 60; i++)
    {
        std::string string = std::to_string(i);
        string = "peas/" + string + ".png";
        peas_frames[i].texture.loadFromFile(string);
    }
    
    
    //create sunlower
    std::vector<Sunflower> sunflowers;
    
    
    //create peas
    std::vector<Peas> peases;
    
    
    //create bullets
    std::vector<Bullet> bullets;
    
    
    //create zombies
    std::vector<Zombie> zombies;
    
    
    //create sun
    sf::Texture sun_texture;
    sun_texture.loadFromFile("sun.png");
    
    
    //create bul
    sf::Texture bul_texture;
    bul_texture.loadFromFile("pea.png");
    
    
    //use time
    sf::Clock clock;
    
    
    while (window.isOpen())
    {
        sf::Time time = clock.getElapsedTime();
        
        window.draw(fon.sprite);
        window.draw(top_panel.sprite);
        numbers[0].sprite.setPosition(270, 61);
        window.draw(numbers[0].sprite);
        
        
        //create new sun
        if (time.asSeconds() - Sun::last_create_time > 10)
        {
            Sun sun;
            sun.sprite.setTexture(sun_texture);
            sun.sprite.setScale(0.5f, 0.5f);
            sun.whose_sun = 0;
            stars.push_back(sun);
            Sun::last_create_time = time.asSeconds();
            sun.create_time = time.asSeconds();
            Sun::count++;
        }
        
        
        //create new Zombie
        if (time.asSeconds() > free_from_zombies_time)
        {
            if(time.asSeconds() - Zombie::last_create_time > 0.5)
            {
                Zombie zomb;
                zomb.sprite.setTexture(zombie_frames[0].texture);
                zomb.sprite.setScale(0.3f, 0.3f);
                zomb.sprite.setPosition(900, (rand() % 5 +1) * grid_y - 55);
                zomb.number_of_frame = 0;
                zomb.last_update_time = 0;
                zomb.create_time = time.asSeconds();
                zombies.push_back(zomb);
                Zombie::count++;
                Zombie::last_create_time = time.asSeconds();
            }
        }
        
        
        //move zombie
        for (auto i = zombies.begin(); i != zombies.end(); i++)
        {
            sf::Vector2f position = i->sprite.getPosition();
            i->sprite.setPosition(position.x - 0.05, position.y);
        }
        
        
        //move for all stars...
        for(auto i = stars.begin(); i != stars.end(); i++)
        {
            if (time.asSeconds() - i->create_time < 50)
            {
                if (time.asSeconds() - i->create_time < 12 && i->whose_sun == 0)
                {
                    sf::Vector2f center = i->sprite.getPosition();
                    i->sprite.setPosition(float(center.x), float(center.y + 0.005 * (time.asSeconds() - i->create_time)));
                }
            }
            else
            {
                stars.erase(i);
                Sun::count--;
                
                if (i == stars.end())
                    break;
            }
        }
        
        
        //if you can touch...
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            
            //...on sun
            for(auto i = stars.begin(); i != stars.end(); i++)
            {
                sf::Vector2f center = i->sprite.getPosition();
                center.x += 40;
                center.y += 40;
                
                sf::Vector2f d = sf::Vector2f(float(mousePosition.x), float(mousePosition.y)) - center;
                
                if (std::abs(d.x) < 30 && std::abs(d.y) < 30)
                {
                    Sun::score += 50;
                    stars.erase(i);
                    Sun::count--;
                    
                    if (i == stars.end())
                        break;
                }
            }
            
            //...create sunflower
            if (Sun::score >= 50 && mousePosition.x > 305 && mousePosition.x < 346 && mousePosition.y > 9 && mousePosition.y < 69 && Sunflower::status == 2)
            {
                Sunflower sunflower;
                Sunflower::status = 1;
                sunflower.sprite.setTexture(sunflower_frames[0].texture);
                sunflower.number_of_frame = 0;
                sunflower.last_update_time = 0;
                sunflower.sprite.setScale(0.75f, 0.75f);
                sunflowers.push_back(sunflower);
                Sunflower::count++;
                Sun::score -= 50;
                Sunflower::last_create_time = time.asSeconds();
            }
            
            //create peas
            if (Sun::score >= 100 && mousePosition.x > 352 && mousePosition.x < 394 && mousePosition.y > 9 && mousePosition.y < 69 && Peas::status == 2)
            {
                Peas peas;
                Peas::status = 1;
                peas.sprite.setTexture(peas_frames[0].texture);
                peas.number_of_frame = 0;
                peas.last_update_time = 0;
                peas.sprite.setScale(0.75f, 0.75f);
                peases.push_back(peas);
                Peas::count++;
                Sun::score -= 100;
                Peas::last_create_time = time.asSeconds();
            }
            
        }
        
        
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
                    
                    if(Sunflower::status ==  1 && i == (sunflowers.end() - 2))
                        break;
                }
            }
        }
        
        //update frames of sunflowers
        if (Sunflower::status == 2)
        {
            for (auto i = sunflowers.begin(); i != sunflowers.end(); i++)
            {
                if(time.asSeconds() - i->last_update_time > 0.02)
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
                    
                    if(Sunflower::status ==  1 && i == (sunflowers.end() - 2))
                        break;
                }
            }
        }
        
        //update frames of peas and create bullets
        if (Peas::status == 2)
        {
            for (auto i = peases.begin(); i != peases.end(); i++)
            {
                if(time.asSeconds() - i->last_update_time > 0.02)
                {
                    i->sprite.setTexture(peas_frames[i->number_of_frame].texture);
                    if (i->number_of_frame < 59)
                    {
                        i->number_of_frame++;
                        
                        //create bullet
                        if(i->number_of_frame == 33)
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
                
                if(Peas::status ==  1 && i == (peases.end() - 2))
                    break;
            }
        }
        
        
        //update bullets
        for(auto i = bullets.begin(); i != bullets.end(); i++)
        {
                sf::Vector2f current_point = i->sprite.getPosition();
                i->sprite.setPosition(current_point.x + 1, current_point.y);
        }
        
        
        //update frames of zombie
        for (auto i = zombies.begin(); i != zombies.end(); i++)
        {
            if(time.asSeconds() - i->last_update_time > 0.2)
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
        }
        
        
        //sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        //std::cout << mousePosition.x << "  " << mousePosition.y << std::endl;
        //std::cout << time.asSeconds() << std::endl;
        
        
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
