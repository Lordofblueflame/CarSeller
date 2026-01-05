#include "Model/Owner.hpp"

Owner::Owner(std::string name, double money)
    : m_name(std::move(name)), m_money(money) {
}

bool Owner::CanAfford(double price) const {
    return m_money >= price;
}

void Owner::Spend(double price) {
    m_money -= price;
}

void Owner::Earn(double price) {
    m_money += price;
}

int Owner::AddCar(std::shared_ptr<Car> car) {
    int id = ++m_nextId;
    m_cars[id] = car;
    return id;
}

std::shared_ptr<Car> Owner::RemoveCar(int id) {
    auto it = m_cars.find(id);
    if (it == m_cars.end())
        return nullptr;

    auto car = it->second;
    m_cars.erase(it);
    return car;
}

const std::map<int, std::shared_ptr<Car>>& Owner::Cars() const {
    return m_cars;
}
