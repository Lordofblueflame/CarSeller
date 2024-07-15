#include "car.h"

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
	std::this_thread::sleep_for(std::chrono::seconds(30));
	std::mutex mutex1;
	for (int i = 0; i < 200; i++) {

		std::unique_lock<std::mutex> lock(mutex1);
		if (Car::ShowDegradation() < 200 && Car::ShowAvailability() == true)
			Car::degradation++;
		else
			break;
		lock.unlock();

		std::this_thread::sleep_for(std::chrono::seconds(10));	
	}
}