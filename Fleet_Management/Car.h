#include "pch.h"
#pragma once
#include <iostream>
#include"Private_car.h"
using namespace std;

class Car :public Private_car {
private:
	bool Hybrid;
public:
	Car(int platform, int chassis, int Engine_Volume,int Km, CString License_Type, bool ownership,bool Hybrid=false) /*:Private_car(platform, chassis, Engine_Volume, Km,License_Type, ownership) {}*/;
	~Car() {};

	void setHybrid(bool);
	bool getHybrid();
};