#include "BMW.h"

BMW::BMW() : fuelCapacity(60.0),
fuelConsumption(3.5),
speedSunny(65.0),
speedRainy(40.0),
speedSnowy(35.0) ,
brand("BMW"){};

double BMW::getFuelCapacity() {
	return this->fuelCapacity;
}

double BMW::getFuelConsumption() {
	return this->fuelConsumption;
}

double BMW::getAverageSpeed(Weather weather) {
	switch (weather) {
	case Sunny: return this->speedSunny;
	case Rainy: return this->speedRainy;
	case Snowy: return this->speedSunny;
	}
}

double BMW::calculateTime(double distance, Weather weather) {
	return distance / this->getAverageSpeed(weather);
}

const char* BMW::getBrand() {
	return this->brand;
}