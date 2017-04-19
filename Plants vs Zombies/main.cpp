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

int Sun::score = 0;
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
    
    
    //create zombie frames
    std::vector<Zombie_frames> zombie_frames(93);
    zombie_frames[0].texture.loadFromFile("zombie/0.png");
    zombie_frames[1].texture.loadFromFile("zombie/1.png");
    zombie_frames[2].texture.loadFromFile("zombie/2.png");
    zombie_frames[3].texture.loadFromFile("zombie/3.png");
    zombie_frames[4].texture.loadFromFile("zombie/4.png");
    zombie_frames[5].texture.loadFromFile("zombie/5.png");
    zombie_frames[6].texture.loadFromFile("zombie/6.png");
    zombie_frames[7].texture.loadFromFile("zombie/7.png");
    zombie_frames[8].texture.loadFromFile("zombie/8.png");
    zombie_frames[9].texture.loadFromFile("zombie/9.png");
    zombie_frames[10].texture.loadFromFile("zombie/10.png");
    zombie_frames[11].texture.loadFromFile("zombie/11.png");
    zombie_frames[12].texture.loadFromFile("zombie/12.png");
    zombie_frames[13].texture.loadFromFile("zombie/13.png");
    zombie_frames[14].texture.loadFromFile("zombie/14.png");
    zombie_frames[15].texture.loadFromFile("zombie/15.png");
    zombie_frames[16].texture.loadFromFile("zombie/16.png");
    zombie_frames[17].texture.loadFromFile("zombie/17.png");
    zombie_frames[18].texture.loadFromFile("zombie/18.png");
    zombie_frames[19].texture.loadFromFile("zombie/19.png");
    zombie_frames[20].texture.loadFromFile("zombie/20.png");
    zombie_frames[21].texture.loadFromFile("zombie/21.png");
    zombie_frames[22].texture.loadFromFile("zombie/22.png");
    zombie_frames[23].texture.loadFromFile("zombie/23.png");
    zombie_frames[24].texture.loadFromFile("zombie/24.png");
    zombie_frames[25].texture.loadFromFile("zombie/25.png");
    zombie_frames[26].texture.loadFromFile("zombie/26.png");
    zombie_frames[27].texture.loadFromFile("zombie/27.png");
    zombie_frames[28].texture.loadFromFile("zombie/28.png");
    zombie_frames[29].texture.loadFromFile("zombie/29.png");
    zombie_frames[30].texture.loadFromFile("zombie/30.png");
    zombie_frames[31].texture.loadFromFile("zombie/31.png");
    zombie_frames[32].texture.loadFromFile("zombie/32.png");
    zombie_frames[33].texture.loadFromFile("zombie/33.png");
    zombie_frames[34].texture.loadFromFile("zombie/34.png");
    zombie_frames[35].texture.loadFromFile("zombie/35.png");
    zombie_frames[36].texture.loadFromFile("zombie/36.png");
    zombie_frames[37].texture.loadFromFile("zombie/37.png");
    zombie_frames[38].texture.loadFromFile("zombie/38.png");
    zombie_frames[39].texture.loadFromFile("zombie/39.png");
    zombie_frames[40].texture.loadFromFile("zombie/40.png");
    zombie_frames[41].texture.loadFromFile("zombie/41.png");
    zombie_frames[42].texture.loadFromFile("zombie/42.png");
    zombie_frames[43].texture.loadFromFile("zombie/43.png");
    zombie_frames[44].texture.loadFromFile("zombie/44.png");
    zombie_frames[45].texture.loadFromFile("zombie/45.png");
    zombie_frames[46].texture.loadFromFile("zombie/46.png");
    zombie_frames[47].texture.loadFromFile("zombie/47.png");
    zombie_frames[48].texture.loadFromFile("zombie/48.png");
    zombie_frames[49].texture.loadFromFile("zombie/49.png");
    zombie_frames[50].texture.loadFromFile("zombie/50.png");
    zombie_frames[51].texture.loadFromFile("zombie/51.png");
    zombie_frames[52].texture.loadFromFile("zombie/52.png");
    zombie_frames[53].texture.loadFromFile("zombie/53.png");
    zombie_frames[54].texture.loadFromFile("zombie/54.png");
    zombie_frames[55].texture.loadFromFile("zombie/55.png");
    zombie_frames[56].texture.loadFromFile("zombie/56.png");
    zombie_frames[57].texture.loadFromFile("zombie/57.png");
    zombie_frames[58].texture.loadFromFile("zombie/58.png");
    zombie_frames[59].texture.loadFromFile("zombie/59.png");
    zombie_frames[60].texture.loadFromFile("zombie/60.png");
    zombie_frames[61].texture.loadFromFile("zombie/61.png");
    zombie_frames[62].texture.loadFromFile("zombie/62.png");
    zombie_frames[63].texture.loadFromFile("zombie/63.png");
    zombie_frames[64].texture.loadFromFile("zombie/64.png");
    zombie_frames[65].texture.loadFromFile("zombie/65.png");
    zombie_frames[66].texture.loadFromFile("zombie/66.png");
    zombie_frames[67].texture.loadFromFile("zombie/67.png");
    zombie_frames[68].texture.loadFromFile("zombie/68.png");
    zombie_frames[69].texture.loadFromFile("zombie/69.png");
    zombie_frames[70].texture.loadFromFile("zombie/70.png");
    zombie_frames[71].texture.loadFromFile("zombie/71.png");
    zombie_frames[72].texture.loadFromFile("zombie/72.png");
    zombie_frames[73].texture.loadFromFile("zombie/73.png");
    zombie_frames[74].texture.loadFromFile("zombie/74.png");
    zombie_frames[75].texture.loadFromFile("zombie/75.png");
    zombie_frames[76].texture.loadFromFile("zombie/76.png");
    zombie_frames[77].texture.loadFromFile("zombie/77.png");
    zombie_frames[78].texture.loadFromFile("zombie/78.png");
    zombie_frames[79].texture.loadFromFile("zombie/79.png");
    zombie_frames[80].texture.loadFromFile("zombie/80.png");
    zombie_frames[81].texture.loadFromFile("zombie/81.png");
    zombie_frames[82].texture.loadFromFile("zombie/82.png");
    zombie_frames[83].texture.loadFromFile("zombie/83.png");
    zombie_frames[84].texture.loadFromFile("zombie/84.png");
    zombie_frames[85].texture.loadFromFile("zombie/85.png");
    zombie_frames[86].texture.loadFromFile("zombie/86.png");
    zombie_frames[87].texture.loadFromFile("zombie/87.png");
    zombie_frames[88].texture.loadFromFile("zombie/88.png");
    zombie_frames[89].texture.loadFromFile("zombie/89.png");
    zombie_frames[90].texture.loadFromFile("zombie/90.png");
    zombie_frames[91].texture.loadFromFile("zombie/91.png");
    zombie_frames[92].texture.loadFromFile("zombie/92.png");
    
    for (int i = 0; i < 60; i++)
    {
        zombie_frames[i].sprite.setTexture(zombie_frames[i].texture);
    }
    
    
    //create peas
    std::vector<Peas_frames> peas_frames(60);
    peas_frames[0].texture.loadFromFile("peas/0.png");
    peas_frames[1].texture.loadFromFile("peas/1.png");
    peas_frames[2].texture.loadFromFile("peas/2.png");
    peas_frames[3].texture.loadFromFile("peas/3.png");
    peas_frames[4].texture.loadFromFile("peas/4.png");
    peas_frames[5].texture.loadFromFile("peas/5.png");
    peas_frames[6].texture.loadFromFile("peas/6.png");
    peas_frames[7].texture.loadFromFile("peas/7.png");
    peas_frames[8].texture.loadFromFile("peas/8.png");
    peas_frames[9].texture.loadFromFile("peas/9.png");
    peas_frames[10].texture.loadFromFile("peas/10.png");
    peas_frames[11].texture.loadFromFile("peas/11.png");
    peas_frames[12].texture.loadFromFile("peas/12.png");
    peas_frames[13].texture.loadFromFile("peas/13.png");
    peas_frames[14].texture.loadFromFile("peas/14.png");
    peas_frames[15].texture.loadFromFile("peas/15.png");
    peas_frames[16].texture.loadFromFile("peas/16.png");
    peas_frames[17].texture.loadFromFile("peas/17.png");
    peas_frames[18].texture.loadFromFile("peas/18.png");
    peas_frames[19].texture.loadFromFile("peas/19.png");
    peas_frames[20].texture.loadFromFile("peas/20.png");
    peas_frames[21].texture.loadFromFile("peas/21.png");
    peas_frames[22].texture.loadFromFile("peas/22.png");
    peas_frames[23].texture.loadFromFile("peas/23.png");
    peas_frames[24].texture.loadFromFile("peas/24.png");
    peas_frames[25].texture.loadFromFile("peas/25.png");
    peas_frames[26].texture.loadFromFile("peas/26.png");
    peas_frames[27].texture.loadFromFile("peas/27.png");
    peas_frames[28].texture.loadFromFile("peas/28.png");
    peas_frames[29].texture.loadFromFile("peas/29.png");
    peas_frames[30].texture.loadFromFile("peas/30.png");
    peas_frames[31].texture.loadFromFile("peas/31.png");
    peas_frames[32].texture.loadFromFile("peas/32.png");
    peas_frames[33].texture.loadFromFile("peas/33.png");
    peas_frames[34].texture.loadFromFile("peas/34.png");
    peas_frames[35].texture.loadFromFile("peas/35.png");
    peas_frames[36].texture.loadFromFile("peas/36.png");
    peas_frames[37].texture.loadFromFile("peas/37.png");
    peas_frames[38].texture.loadFromFile("peas/38.png");
    peas_frames[39].texture.loadFromFile("peas/39.png");
    peas_frames[40].texture.loadFromFile("peas/40.png");
    peas_frames[41].texture.loadFromFile("peas/41.png");
    peas_frames[42].texture.loadFromFile("peas/42.png");
    peas_frames[43].texture.loadFromFile("peas/43.png");
    peas_frames[44].texture.loadFromFile("peas/44.png");
    peas_frames[45].texture.loadFromFile("peas/45.png");
    peas_frames[46].texture.loadFromFile("peas/46.png");
    peas_frames[47].texture.loadFromFile("peas/47.png");
    peas_frames[48].texture.loadFromFile("peas/48.png");
    peas_frames[49].texture.loadFromFile("peas/49.png");
    peas_frames[50].texture.loadFromFile("peas/50.png");
    peas_frames[51].texture.loadFromFile("peas/51.png");
    peas_frames[52].texture.loadFromFile("peas/52.png");
    peas_frames[53].texture.loadFromFile("peas/53.png");
    peas_frames[54].texture.loadFromFile("peas/54.png");
    peas_frames[55].texture.loadFromFile("peas/55.png");
    peas_frames[56].texture.loadFromFile("peas/56.png");
    peas_frames[57].texture.loadFromFile("peas/57.png");
    peas_frames[58].texture.loadFromFile("peas/58.png");
    peas_frames[59].texture.loadFromFile("peas/59.png");
    
    for (int i = 0; i < 60; i++)
    {
        peas_frames[i].sprite.setTexture(peas_frames[i].texture);
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
            if(time.asSeconds() - Zombie::last_create_time > 5)
            {
                Zombie zomb;
                zomb.sprite.setTexture(zombie_frames[0].texture);
                zomb.sprite.setScale(0.3f, 0.3f);
                zomb.sprite.setPosition(900, (rand() % 5 +1) * grid_y + offset_y - grid_y / 2);
                zomb.number_of_frame = 0;
                zomb.last_update_time = 0;
                zomb.create_time = time.asSeconds();
                zombies.push_back(zomb);
                Zombie::count++;
                Zombie::last_create_time = time.asSeconds();
                std::cout << Zombie::count << std::endl;
            }
        }
        
        
        //move zombie
        for (auto i = zombies.begin(); i != zombies.end(); i++)
        {
            sf::Vector2f position = i->sprite.getPosition();
            i->sprite.setPosition(position.x - 0.001 * (time.asSeconds() - i->create_time), position.y);
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
                
            }
        }
        else
        {
            for (auto i = peases.begin(); i != peases.end() - 1; i++)
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
            }
        }
        
        
        //update bullets
        for(auto i = bullets.begin(); i != bullets.end(); i++)
        {
            sf::Vector2f starting_point = i->sprite.getPosition();
            i->sprite.setPosition(starting_point.x + 0.5 * (time.asSeconds() - i->create_time), starting_point.y);
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
