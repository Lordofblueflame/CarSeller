#pragma once
#include <memory>
#include "Model/Owner.hpp"
#include "Model/Car.hpp"

class MarketController {
public:
    bool BuyCar(Owner& buyer, std::shared_ptr<Car> car);
    bool SellCar(Owner& seller, Owner& buyer, int carId);
};
