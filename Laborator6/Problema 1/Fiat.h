#pragma once
#include "Car.h"
class Fiat: public Car {
public:
	double fuelCapacity;
	double fuelConsumption;
	double speedSunny, speedRainy, speedSnowy;
	const char* brand;
	Fiat();
	virtual double getFuelCapacity();
	virtual double getFuelConsumption();
	virtual double getAverageSpeed(Weather weather);
	virtual double calculateTime(double lenght, Weather weather);
	virtual const char* getBrand();
};
