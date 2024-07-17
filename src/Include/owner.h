#ifndef OWNER_H
#define OWNER_H

#include "pch.h"
#include "car.h"

class Owner
{
public:
    Owner() = default;
    Owner(std::string Name, std::string Surname, double Money);
    
    void MyMoney() const;
    int AddCar(std::shared_ptr<Car> car);
    int BuyCar(Car car);
    int SellCar(int choice, Owner* owner);
    void ShowCarsForSellers() const;
    void SummaryOfTheDay() const;

private:
    std::string m_name;
    std::string m_surname;
    double m_money;
    int m_amountOfCars = 0;
    std::map<int, std::shared_ptr<Car>> m_ownedCars;
    std::map<int, std::shared_ptr<Car>> m_carSummary;
};

#endif // OWNER_H
