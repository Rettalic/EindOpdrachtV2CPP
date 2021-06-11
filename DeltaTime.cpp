#include "DeltaTime.h"

DeltaTime::DeltaTime()  { }
DeltaTime::~DeltaTime() { }

void DeltaTime::UpdateDeltaTime() {
    dt = clock.restart().asSeconds();
}