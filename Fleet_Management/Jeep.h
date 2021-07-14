#include "pch.h"
#pragma once
#include <iostream>
#include"Private_car.h"
using namespace std;

class Jeep :public Private_car {
private:
	bool suv;
public:
	Jeep(int platform, int chassis, int Engine_Volume, int Km, CString License_Type,bool ownership,bool suv = 0) ;
	~Jeep() {};
	void setFoF(bool);
	bool getFoF();
};