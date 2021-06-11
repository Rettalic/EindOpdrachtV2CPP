#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <windows.h>
#include "Player.h"
#include "Enemy.h"
#include "DeltaTime.h"
#include "Sound.h"
#include "Score.h"
#include "Text.h"

int main()
{
    //"-----" is een titel

    //-----Time.deltaTime-----
    DeltaTime* deltaTime = new DeltaTime();
    bool firstLoop = false;

    //-----Create window size-----
    int windowWidth = 2048;
    int windowHeight = 1080;
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Cool game"); //SFML library

    //-----Score-----
    Score* score = new Score;
    Vector2 scoreTextPos (windowWidth/25, windowHeight/30); //pos die "scalable" is
    TextInput* scoreText = new TextInput("Score: 0", sf::Color::Yellow, windowWidth/65, scoreTextPos); //creër score
    int winScore = 10; //minus one
    int loseScore = -10;


    //-----Sound-----
    Sound* soundMan = new Sound;
    soundMan->Play("BackgroundMusic.wav");

    //-----Create player-----
    Player* player = new Player(windowWidth, windowHeight);

    //-----Create enemy-----
    int enemiesNum = 10;
    std::vector<Enemy*> enimList;
    for (int i = 0; i < enemiesNum; ++i) {
        Enemy* enemy = new Enemy(windowWidth);
        enimList.push_back(enemy);
    }

    //-----set deltatime-----
    deltaTime->UpdateDeltaTime();

    //-----End Game Text-----
    Vector2 endTextPos (windowWidth / 8 - 70, windowHeight /3); //
    TextInput* endText = new TextInput("", sf::Color::Yellow, 50, endTextPos);

    //-----Game loop-----
    while (window.isOpen())
    {
        if(firstLoop == false) {
            window.draw(endText->returnText("Catch the droids!"));
            firstLoop = true;
            _sleep(500);
        }
        window.clear();
        //Update deltatime
        deltaTime->UpdateDeltaTime();


        //-----Check event-----
        sf::Event event;
        while (window.pollEvent(event))
        {
            //Close window
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
            }
        }
        //-----Player input-----
        player->Move(deltaTime->dt);

        //-----Enemy loop-----
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

        //-----Print score-----
        window.draw(scoreText->returnText("Score: " + std::to_string(score->GetScore())));

        //-----Draw Player-----
        window.draw(player->Draw());

        //-----Add enemies-----
        while (enimList.size() < enemiesNum) {
            Enemy* enemy = new Enemy(windowWidth);
            enimList.push_back(enemy);
        }

        //-----Check Win-----
        if(score->GetScore() > winScore)
        {
            window.clear();
            window.draw(endText->returnText("You win!.. For now! ;>"));
            window.display();
            _sleep(2000);
            window.close();
        }

        //-----Check Lose-----
        if(score->GetScore() <= loseScore)
        {
            window.clear();
            window.draw(endText->returnText("You lost, better luck next time! :)"));
            soundMan->Play("lose.wav");
            _sleep(500);
            window.display();
            _sleep(6000);
            window.close();
        }

        //-----Display window and clear it-----
        window.display();
        window.clear();
    }

    //-----Garbage collection-----
    delete player;
    delete deltaTime;
    delete score;
    delete endText;
    delete soundMan;
    delete scoreText;
    return 0;
}