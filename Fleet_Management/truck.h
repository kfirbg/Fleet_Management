#include "pch.h"
#pragma once
#include <iostream>
#include"motor_vehicle.h"
using namespace std;

class truck :public motor_vehicle {
private:
	CString Engine_Type;
	int battery_power;
public:
	truck(int platform, int chassis, int Engine_Volume, int Km, CString License_Type, CString Engine_Type = _T("Diesel"), int battery_power = 0);
	~truck();
	void setBattery_power(int);
	int getBattery_power() const;
	void setEngine_Type(CString);
	CString getEngine_Type() const;
};