#ifndef OWNER_H
#define OWNER_H

#include "pch.h"
#include "car.h"

class Owner
{
    std::string name;
    std::string surrname;
    double money;
    int amountOfCars = 0;
    std::map<int,Car> ownedCars;
    std::map<int,Car> carSummary;
public:
    Owner(std::string Name, std::string Surrname, double Money);

    int BuyCar(Car car);
    int AddCar(Car car);
    int SellCar(int choice, Owner *owner);
    void ShowCarsForSellers();
    void SummaryOfTheDay();
    void MyMoney();
};

#endif // OWNER_H