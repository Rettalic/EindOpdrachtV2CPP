#include "TimeClass.h"

TimeClass::TimeClass() {

}

TimeClass::~TimeClass() {

}

void TimeClass::UpdateDT() {
    dt = clock.restart().asSeconds();
}