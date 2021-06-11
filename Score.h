#pragma once





class Score {
public:
    Score();
    ~Score();
    void AddScore(int point);
    int GetScore();
    void RetractScore(int point);
private:
    int points = 0;
};
