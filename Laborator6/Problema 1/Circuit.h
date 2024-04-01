#pragma once
#include "Car.h"
#include "Weather.h"
class Circuit
{
	Car** cars;
	double length;
	Weather weather;
	int numberOfCars, capacity;
public:
	Circuit();
	~Circuit();
	void SetLength(double length);
	void SetWeather(Weather weather);
	void AddCar(Car* car);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};

