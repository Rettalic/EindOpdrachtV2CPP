#include "Vector2.h"

//begin
Vector2::Vector2(float Bx, float By) {
    x = Bx;
    y = By;

    startX = Bx;
    startY = By;
}

Vector2::~Vector2() {

}
//Square (kwadraat)
float Vector2::Magnitude() {
    float  Mx = startX - x;
    float  My = startY - y;
    float  magn = sqrt(std::pow(Mx, 2) + std::pow(My, 2));
    magnitude = magn;
    return magn;
}

//multiply (keer)
Vector2& Vector2::operator*(const int& i) {
    x = x * i;
    y = y * i;
    return *this;
}

//plus
Vector2& Vector2::operator+(const Vector2& v2) {
    x = x + v2.x;
    y = y + v2.y;
    return *this;
}

//minus
Vector2& Vector2::operator-(const Vector2& v2) {
    x = x - v2.x;
    y = y - v2.y;
    return *this;
}

//angle (hoek)
float Vector2::Angle() {
    float  Mx = startX - x;
    float  My = startY - y;
    float  angle = tan(My/Mx);
    return angle;
}

//afstand
float Vector2::Distance(Vector2 other, float sizeSelf, float sizeOther) {
    float  Mx = x - other.GetX();
    float  My = y - other.GetY();
    float  dir = sqrt(std::pow(Mx, 2) + std::pow(My, 2));
    float  dist = dir - sizeSelf - sizeOther;
    return dist;
}

//genormaliseerd
Vector2& Vector2::Normalize() {
    x = x / magnitude;
    y = y / magnitude;
    return *this;
}

//Getters
float Vector2::GetX() {
    return x;
}

float Vector2::GetY() {
    return y;
}

