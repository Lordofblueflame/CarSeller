#ifndef CAR_H
#define CAR_H
#include "pch.h"

class Car
{
public:

	Car(std::string Model, std::string RegDate, double Price, double Degradation, bool Availability)
	{
		Car::model = Model;
		Car::registrationDate = RegDate;
		Car::firstPrice = Price;
		Car::degradation = Degradation;
		Car::availability = Availability;
	}
	void ShowInfo();

	void ChangeAvailability(bool Availability);

	double CurrentPrice();

	double ShowDegradation();

	void PriceDegradation();

	bool ShowAvailability();

	void ChangePrice(double change);
	
private:
	std::string model;
	std::string registrationDate;
	double firstPrice;
	double degradation;
	bool availability;
};

#endif // CAR_H