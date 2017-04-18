#include "Objects.cpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>


float Sunflower::last_create_time = 0;
int Sun::score = 0;
float Sun::last_create_time = 0;
int Sun::count = 0;
int Sunflower::health = 100;
int Sunflower::count = 0;
int Sunflower::status = 2;

int grid_x = 80;
int grid_y = 96;
int offset_x = 258;
int offset_y = 89;
float time_planting = 0.5;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1024, 600), "My window");
    
    //create fon
    Object fon;
    fon.set_for_static_object(0, 0, "fone.png");
    
    std::vector<Sun> stars;
    
    //create top panel
    Object top_panel;
    top_panel.set_for_static_object(230, 0, "top_panel.png");
    top_panel.sprite.setScale(0.9f, 0.9f);
    
    //create numbers
    std::vector<Number> numbers(10);
    numbers[0].texture.loadFromFile("numbers/0.png");
    numbers[1].texture.loadFromFile("numbers/1.png");
    numbers[2].texture.loadFromFile("numbers/2.png");
    numbers[3].texture.loadFromFile("numbers/3.png");
    numbers[4].texture.loadFromFile("numbers/4.png");
    numbers[5].texture.loadFromFile("numbers/5.png");
    numbers[6].texture.loadFromFile("numbers/6.png");
    numbers[7].texture.loadFromFile("numbers/7.png");
    numbers[8].texture.loadFromFile("numbers/8.png");
    numbers[9].texture.loadFromFile("numbers/9.png");
    
    for (int i = 0; i < 10; i++)
    {
        numbers[i].sprite.setTexture(numbers[i].texture);
    }
    
    //create sunflower frames
    std::vector<Sunflower_frames> sunflower_frames(60);
    sunflower_frames[0].texture.loadFromFile("sun/0.png");
    sunflower_frames[1].texture.loadFromFile("sun/1.png");
    sunflower_frames[2].texture.loadFromFile("sun/2.png");
    sunflower_frames[3].texture.loadFromFile("sun/3.png");
    sunflower_frames[4].texture.loadFromFile("sun/4.png");
    sunflower_frames[5].texture.loadFromFile("sun/5.png");
    sunflower_frames[6].texture.loadFromFile("sun/6.png");
    sunflower_frames[7].texture.loadFromFile("sun/7.png");
    sunflower_frames[8].texture.loadFromFile("sun/8.png");
    sunflower_frames[9].texture.loadFromFile("sun/9.png");
    sunflower_frames[10].texture.loadFromFile("sun/10.png");
    sunflower_frames[11].texture.loadFromFile("sun/11.png");
    sunflower_frames[12].texture.loadFromFile("sun/12.png");
    sunflower_frames[13].texture.loadFromFile("sun/13.png");
    sunflower_frames[14].texture.loadFromFile("sun/14.png");
    sunflower_frames[15].texture.loadFromFile("sun/15.png");
    sunflower_frames[16].texture.loadFromFile("sun/16.png");
    sunflower_frames[17].texture.loadFromFile("sun/17.png");
    sunflower_frames[18].texture.loadFromFile("sun/18.png");
    sunflower_frames[19].texture.loadFromFile("sun/19.png");
    sunflower_frames[20].texture.loadFromFile("sun/20.png");
    sunflower_frames[21].texture.loadFromFile("sun/21.png");
    sunflower_frames[22].texture.loadFromFile("sun/22.png");
    sunflower_frames[23].texture.loadFromFile("sun/23.png");
    sunflower_frames[24].texture.loadFromFile("sun/24.png");
    sunflower_frames[25].texture.loadFromFile("sun/25.png");
    sunflower_frames[26].texture.loadFromFile("sun/26.png");
    sunflower_frames[27].texture.loadFromFile("sun/27.png");
    sunflower_frames[28].texture.loadFromFile("sun/28.png");
    sunflower_frames[29].texture.loadFromFile("sun/29.png");
    sunflower_frames[30].texture.loadFromFile("sun/30.png");
    sunflower_frames[31].texture.loadFromFile("sun/31.png");
    sunflower_frames[32].texture.loadFromFile("sun/32.png");
    sunflower_frames[33].texture.loadFromFile("sun/33.png");
    sunflower_frames[34].texture.loadFromFile("sun/34.png");
    sunflower_frames[35].texture.loadFromFile("sun/35.png");
    sunflower_frames[36].texture.loadFromFile("sun/36.png");
    sunflower_frames[37].texture.loadFromFile("sun/37.png");
    sunflower_frames[38].texture.loadFromFile("sun/38.png");
    sunflower_frames[39].texture.loadFromFile("sun/39.png");
    sunflower_frames[40].texture.loadFromFile("sun/40.png");
    sunflower_frames[41].texture.loadFromFile("sun/41.png");
    sunflower_frames[42].texture.loadFromFile("sun/42.png");
    sunflower_frames[43].texture.loadFromFile("sun/43.png");
    sunflower_frames[44].texture.loadFromFile("sun/44.png");
    sunflower_frames[45].texture.loadFromFile("sun/45.png");
    sunflower_frames[46].texture.loadFromFile("sun/46.png");
    sunflower_frames[47].texture.loadFromFile("sun/47.png");
    sunflower_frames[48].texture.loadFromFile("sun/48.png");
    sunflower_frames[49].texture.loadFromFile("sun/49.png");
    sunflower_frames[50].texture.loadFromFile("sun/50.png");
    sunflower_frames[51].texture.loadFromFile("sun/51.png");
    sunflower_frames[52].texture.loadFromFile("sun/52.png");
    sunflower_frames[53].texture.loadFromFile("sun/53.png");
    sunflower_frames[54].texture.loadFromFile("sun/54.png");
    sunflower_frames[55].texture.loadFromFile("sun/55.png");
    sunflower_frames[56].texture.loadFromFile("sun/56.png");
    sunflower_frames[57].texture.loadFromFile("sun/57.png");
    sunflower_frames[58].texture.loadFromFile("sun/58.png");
    sunflower_frames[59].texture.loadFromFile("sun/59.png");
    
    for (int i = 0; i < 60; i++)
    {
        sunflower_frames[i].sprite.setTexture(sunflower_frames[i].texture);
    }
    
    //create sublower
    std::vector<Sunflower> sunflowers;
    
    //create sun
    sf::Texture sun_texture;
    sun_texture.loadFromFile("sun.png");
    
    //use time
    sf::Clock clock;
    
    
    while (window.isOpen())
    {
        sf::Time time = clock.getElapsedTime();
        
        window.draw(fon.sprite);
        window.draw(top_panel.sprite);
        numbers[0].sprite.setPosition(270, 61);
        window.draw(numbers[0].sprite);
        
        ////////////////////////////////////////// Sun
        
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
            if (Sun::score >= 50 && mousePosition.x > 305 && mousePosition.x < 346 && mousePosition.y > 9 && mousePosition.y < 69 && Sunflower::status == 2)   // fixed 18.04.17
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
                }
            }
        }
        else
        {
            for (auto i = sunflowers.begin(); i != (sunflowers.end() - 1); i++)
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
                }
            }
        }
        
        
        
        //update frames of sunflowers
        
        if (Sunflower::status == 2)
        {
            for (auto i = sunflowers.begin(); i != sunflowers.end(); i++)
            {
                if(time.asSeconds() - i->last_update_time > 0.02)                               //fixed it 18.04.17
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
                }
                
            }
        }
        else
        {
            for (auto i = sunflowers.begin(); i != sunflowers.end() - 1; i++)
            {
                if(time.asSeconds() - i->last_update_time > 0.02)                               //fixed it 18.04.17
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
                }
            }
        }
        
        //draw sunflowers
        for (auto i = sunflowers.begin(); i != sunflowers.end(); i++)
        {
            window.draw(i->sprite);
        }		  
        
        //sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        //std::cout << mousePosition.x << "  " << mousePosition.y << std::endl;
        //std::cout << time.asSeconds() << std::endl;
        //std::cout << Sunflower::count << std::endl;
        
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
