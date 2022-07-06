#include <iostream>
#include <iomanip>
#include <math.h>
#include <thread>
#include <mutex>
#pragma warning(disable : 4996)

std::mutex mutex1;

class Car
{
	std::string model;
	std::string registrationDate;
	double firstPrice;
	double degradation;
	bool avilability;
public:

	Car(std::string Model, std::string RegDate, double Price, double Degradation, bool Avilability)
	{
		Car::model = Model;
		Car::registrationDate = RegDate;
		Car::firstPrice = Price;
		Car::degradation = Degradation;
		Car::avilability = Avilability;
	}
	void ShowInfo();

	void ChangeAvilability(bool Avilability);

	double CurrentPrice();

	double ShowDegradation();

	void PriceDegradation();

	bool ShowAvilability();

	void ChangePrice(double change);
};

inline bool Car::ShowAvilability()
{
	return Car::avilability;
}

inline void Car::ChangePrice(double change)
{
	Car::firstPrice = change;
}

inline void Car::ChangeAvilability(bool Avilability)
{
	Car::avilability = Avilability;
}

inline double Car::CurrentPrice()
{
	return Car::firstPrice - (Car::firstPrice *(Car::degradation/100));
}

inline void Car::ShowInfo()
{
	std::cout 
		<< "#Model : " << Car::model << "\n"
		<< "#Registration date : " << Car::registrationDate << "\n"
		<< "#Price : " << Car::CurrentPrice() << "\n";
		//<< " Degradation : " << Car::ShowDegradation() << "\n";
}

inline double Car::ShowDegradation()
{
	return Car::degradation;
}
inline void Car::PriceDegradation()
{
	std::this_thread::sleep_for(std::chrono::seconds(30));
	
	for (int i = 0; i < 20; i++) {

		std::unique_lock<std::mutex> lock(mutex1);
		if (Car::degradation < 20 && Car::avilability == true)
			Car::degradation++;
		else
			break;
		lock.unlock();

		std::this_thread::sleep_for(std::chrono::seconds(10));	
	}
}