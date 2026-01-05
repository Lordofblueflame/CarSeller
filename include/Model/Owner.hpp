#pragma once
#include <map>
#include <memory>
#include <string>

#include "Model/Car.hpp"

class Owner {
public:
    Owner(std::string name, double money);

    bool CanAfford(double price) const;
    void Spend(double price);
    void Earn(double price);

    int AddCar(std::shared_ptr<Car> car);
    std::shared_ptr<Car> RemoveCar(int id);

    const std::map<int, std::shared_ptr<Car>>& Cars() const;

private:
    std::string m_name;
    double m_money;
    int m_nextId{ 0 };
    std::map<int, std::shared_ptr<Car>> m_cars;
};
