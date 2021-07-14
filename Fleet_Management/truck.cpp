#include "pch.h"
#pragma once
#include <iostream>
#include"truck.h"

truck::truck(int platform, int chassis, int Engine_Volume, int Km, CString License_Type, CString Engine_Type, int battery_power) :motor_vehicle(platform, chassis, Engine_Volume, Km, License_Type) {
	this->Engine_Type = Engine_Type;
	this->battery_power = battery_power;
}

void truck::setBattery_power(int battery_power) {
	if (battery_power == 0) {
		this->battery_power = 12;
	}
	else {
		this->battery_power = battery_power;
	}
}

int truck::getBattery_power() const {
	return battery_power;
}

void truck::setEngine_Type(CString Engine_Type) {
	this->Engine_Type = Engine_Type;
}

CString truck::getEngine_Type() const {
	return Engine_Type;
}

truck::~truck() {}