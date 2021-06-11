#pragma once
#include <cmath>




class Vector2 {
public:
    Vector2(float Bx, float By);
    ~Vector2();
    Vector2& operator*(const int& i);
    Vector2& operator+(const Vector2& v2);
    Vector2& operator-(const Vector2& v2);

    float GetX();
    float GetY();

    float Magnitude();
    Vector2& Normalize();
    float Angle();
    float Distance(Vector2 other, float sizeSelf, float sizeOther);

private:
    float x;
    float y;
    float startX;
    float startY;
    float magnitude;
};



