#include <iostream>
#include <mutex>
#include <thread>


std::mutex mutex1;

class Car
{
	std::string model;
	std::string registrationDate;
	double firstPrice;
	double degradation;
	bool availability;
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
};

inline bool Car::ShowAvailability()
{
	return Car::availability;
}

inline void Car::ChangePrice(double change)
{
	Car::firstPrice = change;
}

inline void Car::ChangeAvailability(bool Availability)
{
	Car::availability = Availability;
}

inline double Car::CurrentPrice()
{
	return Car::firstPrice - (Car::firstPrice *(Car::degradation/1000));
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