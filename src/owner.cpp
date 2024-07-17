#include "include\owner.h"
#include "include\car.h"

Owner::Owner(std::string Name, std::string Surname, double Money)
    : m_name(Name), m_surname(Surname), m_money(Money) {
}

void Owner::MyMoney() const
{
    std::cout << "My money: " << m_money << "\n";
}

int Owner::AddCar(std::shared_ptr<Car> car)
{
    m_amountOfCars++;
    m_ownedCars.insert({ m_amountOfCars, car });
    m_carSummary.insert({ m_amountOfCars, car });

    return m_amountOfCars;
}

int Owner::BuyCar(Car car)
{
    if (m_money >= car.CurrentPrice()) {
        m_money -= car.CurrentPrice();
        m_amountOfCars++;

        auto carPtr = std::make_shared<Car>(car);
        m_ownedCars.insert({ m_amountOfCars, carPtr });
        m_carSummary.insert({ m_amountOfCars, carPtr });

        return m_amountOfCars;
    }

    std::cout << "You don't have enough money\n";
    return 0;
}

int Owner::SellCar(int choice, Owner* owner)
{
    if (!m_ownedCars.empty()) {
        auto it = m_ownedCars.find(choice);
        if (it != m_ownedCars.end()) {
            int newRecord = owner->BuyCar(*(it->second));
            if (newRecord == 0)
                return 0;

            auto carSum = m_carSummary.find(choice);
            auto carSumClient = owner->m_carSummary.find(newRecord);

            m_money += it->second->CurrentPrice();

            carSum->second->ChangeAvailability(false);
            carSumClient->second->ChangeAvailability(true); 
            carSum->second->ChangePrice(it->second->CurrentPrice()); 

            m_ownedCars.erase(it);
        } else {
            std::cout << "Car not found\n";
        }
    } else {
        std::cout << "You don't have any cars to sell\n";
    }
    return 0;
}

void Owner::ShowCarsForSellers() const
{
    if (!m_ownedCars.empty()) {
        for (const auto& pair : m_ownedCars) {
            if (pair.second->ShowAvailability()) {
                std::cout << pair.first << ". ";
                pair.second->ShowInfo();
            }
        }
    } else {
        std::cout << "You don't have any cars\n";
    }
}

void Owner::SummaryOfTheDay() const
{
    std::cout << "#Owner Data: " << m_name << " " << m_surname << "\n";
    if (!m_carSummary.empty()) {
        for (const auto& pair : m_carSummary) {
            if (pair.second->ShowAvailability()) { 
                std::cout << "#Type of transaction: Bought\n";
            } else {
                std::cout << "#Type of transaction: Sold\n";
            }
            std::cout << "#Record in Base: " << pair.first << ".\n";
            pair.second->ShowInfo();
            std::cout << "\n";
        }
    } else {
        std::cout << "You don't have any cars\n";
    }
}

