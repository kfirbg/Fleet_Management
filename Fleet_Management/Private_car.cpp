#include "pch.h"
#pragma once
#include <iostream>
#include"motor_vehicle.h"
#include"Private_car.h"
using namespace std;

Private_car::Private_car(int platform, int chassis, int Engine_Volume, int Km, CString License_Type, bool ownership) :motor_vehicle(platform, chassis, Engine_Volume, Km, License_Type) {
	this->ownership = ownership;
}

void Private_car::setownership(bool b){
	this->ownership = b;
}

bool Private_car::getownership() {
	return ownership;
}

Private_car::~Private_car(){}