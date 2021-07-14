#include "pch.h"
#pragma once
#include <iostream>
#include"motor_vehicle.h"
using namespace std;

class Private_car :public motor_vehicle {
private:
	bool ownership;
public:
	Private_car(int platform, int chassis, int Engine_Volume, int Km, CString License_Type,bool ownership = false);
	~Private_car();

	void setownership(bool);
	bool getownership();
};