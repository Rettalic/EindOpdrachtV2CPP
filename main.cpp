#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
//#include "Vector2.h"
#include "Enemy.h"
#include "TimeClass.h"
#include "Sound.h"
#include <vector>
#include "Score.h"
#include "Text.h"
#include "Border.h"

int main()
{
    //Window
    int windowX = 1280 ;
    int windowY = 940;
    sf::RenderWindow window(sf::VideoMode(windowX, windowY), "Cool Game");

    //Enemy
    int enemyAmount = 8;

    //Sound manager
    Sound* sound = new Sound;

    //Player
    Player* player = new Player(windowX, windowY);

    //Time
    TimeClass* deltaTime = new TimeClass();

    //Enemy
    std::vector<Enemy*> enimList;
    for (int i = 0; i < enemyAmount; ++i) {
        Enemy* enemy = new Enemy(windowX);
        enimList.push_back(enemy);
    }

    //Score
    Score* score = new Score;
    Vector2 scoreTextPos (100, 250);
    sf::Text scoreText;
    Text* changeText = new Text("", sf::Color::Yellow, 500, scoreTextPos);
    scoreText = changeText->returnText();

    //Game loop
    while (window.isOpen())
    {
        deltaTime->UpdateDT();
        sf::Event event;
        while (window.pollEvent(event))
        {
            //Close window
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
            }
        }

        //Player input
        float dest = sf::Mouse::getPosition(window).x;
        player->Move(deltaTime->dt, dest);
        //Enemy loop
        for (int i = 0; i < enimList.size(); ++i) {
            window.draw(enimList[i]->Draw(deltaTime->dt));
            //Delete enemy under screen
            if(enimList[i]->Draw(deltaTime->dt).getPosition().y > windowY + 5)
            {
                delete enimList[i];
                enimList.erase(enimList.begin() + i);
                score->RetractScore(1);
            }
            //Collision with player
            if (player->position->Distance(*enimList[i]->position, player->playerSize, enimList[i]->sizeEnemy) < 0){
                delete enimList[i];
                enimList.erase(enimList.begin() + i);
                score->AddScore(1);
                enemyAmount += 1;
            }
        }


        //Add new enemies
        while (enimList.size() < enemyAmount) {
            Enemy* enemy = new Enemy(windowX);
            enimList.push_back(enemy);
        }

        //Draw player
        window.draw(player->Draw());

        //Print score and add to difficulty
        window.draw(scoreText);

        //Display window and clear it
        window.display();
        window.clear();

    }

    return 0;
}
