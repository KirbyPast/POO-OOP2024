#pragma once
#include "Weather.h"
class Car {
public:
	double fuelCapacity;
	double fuelConsumption;
	double speedSunny, speedRainy, speedSnowy;
	const char* brand;
	virtual double getFuelCapacity() = 0;
	virtual double getFuelConsumption() = 0;
	virtual double getAverageSpeed(Weather weather) = 0;
	virtual double calculateTime(double lenght, Weather weather) = 0;
	virtual const char* getBrand() = 0;
};