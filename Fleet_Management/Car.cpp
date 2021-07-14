#include "pch.h"
#pragma once
#include <iostream>
#include"Private_car.h"
#include"Car.h"
using namespace std;

Car::Car(int platform, int chassis, int Engine_Volume, int Km, CString License_Type, bool ownership, bool Hybrid) :Private_car(platform, chassis, Engine_Volume, Km, License_Type, ownership) {
	this->Hybrid = Hybrid;
}

void Car::setHybrid(bool b) {
	this->Hybrid = b;
}
bool Car::getHybrid() {
	return Hybrid;
}