#include "pch.h"
#pragma once
#include <iostream>
#include "motor_vehicle.h"

motor_vehicle::motor_vehicle(int platform , int chassis, int Engine_Volume, int Km, CString license_Type) {
	this->platform = platform;
	this->chassis = chassis;
	this->Engine_Volume = Engine_Volume;
	this->Km = Km;
	License_Type = license_Type;
}

void motor_vehicle::setChassis(int chassis) {
	this->chassis = chassis;
}

void motor_vehicle::setPlatform(int platform) {
	this->platform = platform;
}

void motor_vehicle::setEngine_Volume(int Engine_Volume) {
	this->Engine_Volume = Engine_Volume;
}

void motor_vehicle::setKm(int Km) {
	this->Km = Km;
}

void motor_vehicle::setLicense_Type(CString license_Type) {
	License_Type = license_Type;
}

int motor_vehicle::getPlatform() const {
	return platform;
}

int motor_vehicle::getChassis() const {
	return chassis;
}

int motor_vehicle::getEngine_Volume() const {
	return Engine_Volume;
}

int motor_vehicle::getKm() const {
	return Km;
}

CString motor_vehicle::getLicense_Type() const {
	return License_Type;
}