#include "pch.h"
#include <iostream>
#include"Private_car.h"
#include"Jeep.h"
using namespace std;

Jeep::Jeep(int platform, int chassis, int Engine_Volume, int Km, CString License_Type, bool ownership, bool suv ) :Private_car(platform, chassis, Engine_Volume, Km, License_Type, ownership) {
	this->suv = suv;
}

void Jeep::setFoF(bool b) {
	this->suv = b;
}

bool Jeep::getFoF(){
	return suv;
}