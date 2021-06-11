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
    int windowWidth = 2048;
    int windowHeight = 1080;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Yeet");

    //Score
    Score* score = new Score;
    Vector2 scoreTextPos (windowWidth/25, windowHeight/30);
    TextInput* scoreText = new TextInput("Score: 0", sf::Color::Yellow, windowWidth/65, scoreTextPos);
    int winScore = 11; //minus one

    //End text
    Vector2 endTextPos (200, 300);
    TextInput* endText = new TextInput("You win!", sf::Color::Yellow, 50, endTextPos);


    Sound* soundMan = new Sound;
    bool isPlaying = false;

    //Create player
    Player* player = new Player(windowWidth, windowHeight);

    //Create enemy
    int enemiesNum = 5;
    std::vector<Enemy*> enimList;
    for (int i = 0; i < enemiesNum; ++i) {
        Enemy* enemy = new Enemy(windowWidth);
        enimList.push_back(enemy);
    }

    //set deltatime
    deltaTime->UpdateDeltaTime();

    soundMan->Play("BackgroundMusic.wav");
    //Game loop
    while (window.isOpen())
    {
        //Update deltatime
        deltaTime->UpdateDeltaTime();


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
            if(enimList[i]->Draw(deltaTime->dt).getPosition().y > windowHeight + 5)
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

        //Print score
        window.draw(scoreText->returnText("Score: " + std::to_string(score->GetScore())));

        //Player
        window.draw(player->Draw());

        //Add enemy
        while (enimList.size() < enemiesNum) {
            Enemy* enemy = new Enemy(windowWidth);
            enimList.push_back(enemy);
        }

        //Win
        if(score->GetScore() > winScore)
        {
            window.clear();
            window.draw(endText->returnText("You win!.. For now! :)"));
            window.display();
            _sleep(2000);
            window.close();
        }

        if(score->GetScore() <= loseScore)
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