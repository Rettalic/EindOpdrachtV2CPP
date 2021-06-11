#include "DeltaTime.h"

DeltaTime::DeltaTime()  { }
DeltaTime::~DeltaTime() { }

void DeltaTime::UpdateDeTi() {
    dt = clock.restart().asSeconds();
}