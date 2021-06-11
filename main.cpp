#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
#include "Enemy.h"
#include "DeltaTime.h"
#include "Sound.h"
#include <vector>
#include "Score.h"
#include "Text.h"
#include <windows.h>

int main()
{
    //Time.deltaTime
    DeltaTime* deltaTime = new DeltaTime();
    bool firstLoop = true;

    //Create window
    int windowW = 1280;
    int windowH = 920;

    sf::RenderWindow window(sf::VideoMode(windowW, windowH), "Yeet");



    //Score
    Score* score = new Score;
    Vector2 scoreTextPos (20, 10);
    TextInput* scoreText = new TextInput("Score: 0", sf::Color::Yellow, 25, scoreTextPos);
    int winScore = 14; //minus one

    //End text
    Vector2 endTextPos (200, 300);
    TextInput* endText = new TextInput("You win!", sf::Color::Yellow, 50, endTextPos);


    Sound* soundMan = new Sound;

    //Create player
    Player* player = new Player(windowW, windowH);

    //Create enemy
    int enemiesNum = 5;
    std::vector<Enemy*> enimList;
    for (int i = 0; i < enemiesNum; ++i) {
        Enemy* enemy = new Enemy(windowW);
        enimList.push_back(enemy);
    }

    //set deltatime
    deltaTime->UpdateDT();
    soundMan->Play("BackgroundMusic.wav");

    //Game loop
    while (window.isOpen())
    {
        //Update deltatime
        deltaTime->UpdateDT();

        //Check event
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
        player->Move(deltaTime->dt);
        //Enemy loop
        for (int i = 0; i < enimList.size(); ++i) {
            //Draw enemy
            window.draw(enimList[i]->Draw(deltaTime->dt));
            //Delete enemy under screen
            if(enimList[i]->Draw(deltaTime->dt).getPosition().y > windowH + 5)
            {
                delete enimList[i];
                enimList.erase(enimList.begin() + i);
                soundMan->Play("fail.wav");
                score->RetractScore(1);
            }
            //Collision with player
            if (player->position->Distance(*enimList[i]->position, player->playerSize, enimList[i]->enimSize) < 0){
                delete enimList[i];
                enimList.erase(enimList.begin() + i);
                soundMan->Play("score.wav");
                score->AddScore(1);
            }
        }

        //Player
        window.draw(player->Draw());

        //Add enemy
        while (enimList.size() < enemiesNum) {
            Enemy* enemy = new Enemy(windowW);
            enimList.push_back(enemy);
        }


        //Print score
        window.draw(scoreText->returnText("Score: " + std::to_string(score->GetScore())));

        //Win
        if(score->GetScore() > winScore)
        {
            window.clear();
            window.draw(endText->returnText("You win!.. For now! :)"));
            window.display();
            _sleep(2000);
            window.close();
        }
        //Display window and clear it
        window.display();
        window.clear();
    }

    //Delete everything
    delete player;
    delete deltaTime;
    delete score;
    delete endText;
    delete soundMan;
    delete scoreText;
    return 0;
}