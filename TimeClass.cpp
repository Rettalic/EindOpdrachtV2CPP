#include "TimeClass.h"

TimeClass::TimeClass() { }

TimeClass::~TimeClass() { }

void TimeClass::UpdateDeltaTime() {
    deltaTime = clock.restart().asSeconds();
}