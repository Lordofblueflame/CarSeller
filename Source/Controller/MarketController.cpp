#include "Controller/MarketController.hpp"

bool MarketController::BuyCar(Owner& buyer, std::shared_ptr<Car> car) {
    double price = car->CurrentPrice();
    if (!buyer.CanAfford(price))
        return false;

    buyer.Spend(price);
    buyer.AddCar(car);
    car->SetAvailable(true);

    return true;
}

bool MarketController::SellCar(Owner& seller, Owner& buyer, int carId) {
    auto car = seller.RemoveCar(carId);
    if (!car)
        return false;

    double price = car->CurrentPrice();
    if (!buyer.CanAfford(price)) {
        seller.AddCar(car);
        return false;
    }

    buyer.Spend(price);
    buyer.AddCar(car);

    seller.Earn(price);
    car->SetAvailable(false);

    return true;
}
