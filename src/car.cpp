#include "include\car.h"

bool Car::ShowAvailability()
{
	return Car::availability;
}

void Car::ChangePrice(double change)
{
	Car::firstPrice = change;
}

void Car::ChangeAvailability(bool Availability)
{
	Car::availability = Availability;
}

double Car::CurrentPrice()
{
	return Car::firstPrice - (Car::firstPrice *(Car::degradation/1000));
}

void Car::ShowInfo()
{
	std::cout 
		<< "#Model : " << Car::model << "\n"
		<< "#Registration date : " << Car::registrationDate << "\n"
		<< "#Price : " << Car::CurrentPrice() << "\n";
		//<< " Degradation : " << Car::ShowDegradation() << "\n";
}

double Car::ShowDegradation()
{
	return Car::degradation;
}
void Car::PriceDegradation()
{
	for (int i = 0; i < 200; i++) {

		if (Car::ShowDegradation() < 200 && Car::ShowAvailability() == true)
			Car::degradation++;
		else
			break;
	}
}