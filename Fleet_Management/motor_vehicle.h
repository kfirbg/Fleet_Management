#include "pch.h"
#pragma once
#include <iostream>
using namespace std;

class motor_vehicle {
private:
	int platform;
	int chassis;
	int Engine_Volume;
	int Km;
	CString License_Type;
public:
	motor_vehicle(int platform = 0, int chassis = 0, int Engine_Volume = 0,int Km = 0, CString License_Type=_T(""));
	virtual ~motor_vehicle() {};
	
	void setPlatform(int);
	int getPlatform() const ;

	void setChassis(int);
	int getChassis() const;
	
	void setEngine_Volume(int);
	int getEngine_Volume() const;
	
	void setKm(int);
	int getKm() const;

	void setLicense_Type(CString);
	CString getLicense_Type() const;
};