#include <map>
#include <algorithm>


class Owner
{
    std::string name;
    std::string surrname;
    double money;
    int amountOfCars = 0;
    std::map<int,Car> ownedCars;
    std::map<int,Car> carSummary;
public:

    Owner(std::string Name, std::string Surrname, double Money)
    {
        name = Name;
        surrname = Surrname;
        money = Money;
    }
    int BuyCar(Car car);

    int AddCar(Car car);
 
    int SellCar(int choice, Owner *owner);

    void ShowCarsForSellers();

    void SummaryOfTheDay();

    void MyMoney();
};

inline void Owner::MyMoney()
{
    std::cout << "My money : " 
        << Owner::money 
        << " \n";
}

inline int Owner::AddCar(Car car)
{
    Owner::amountOfCars++;
    Owner::carSummary.insert({ Owner::amountOfCars, car });
    Owner::ownedCars.insert({ Owner::amountOfCars, car });

    return Owner::amountOfCars;
}

inline int Owner::BuyCar(Car car)
{
    if (Owner::money >= car.CurrentPrice()) {
        Owner::money = Owner::money - car.CurrentPrice();

        Owner::amountOfCars++;

        Owner::carSummary.insert({ Owner::amountOfCars, car });
        Owner::ownedCars.insert({ Owner::amountOfCars, car });

        auto it = ownedCars.find(amountOfCars);
        std::thread th1(&Car::PriceDegradation, &it->second);
        th1.detach();

        return Owner::amountOfCars;
    }
    std::cout << "You dont have enough money \n";
    return 0;
}

inline int Owner::SellCar(int choice, Owner *owner)
{
    if (!Owner::ownedCars.empty())
    {
        auto Own = Owner::ownedCars.find(choice);
        if (Own != Owner::ownedCars.end())
        {
            int j = owner->BuyCar(Own->second);
            if (j == 0)
               return 0;
            auto carSum = Owner::carSummary.find(choice);
            auto carSumClient = owner->carSummary.find(j);

            Owner::money += Own->second.CurrentPrice();

            carSum->second.ChangeAvailability(false);
            carSumClient->second.ChangeAvailability(true);
            carSum->second.ChangePrice(Own->second.CurrentPrice());

            Owner::ownedCars.erase(choice);
        }
        else
            std::cout << "Not Found";
    }
    else
        std::cout << "You've got no cars to sell\n";
    return 0;
}

inline void Owner::ShowCarsForSellers()
{
    if (!ownedCars.empty())
        for (auto n : ownedCars) {
            if (n.second.ShowAvailability() == true) {
                std::cout << n.first << ". ";
                n.second.ShowInfo();
            }
        }
    else
        std::cout << "You've got no cars\n";
}

inline void Owner::SummaryOfTheDay()
{

    std::cout << "#Owner Data : " << Owner::name << " " << Owner::surrname << " \n";
    if (!Owner::carSummary.empty())
        for (auto& n : Owner::carSummary) {
            if (n.second.ShowAvailability() == true) {
                std::cout 
                    << "#Type of transaction : "
                    << "Bought " << "\n"
                    << "#Record in Base: " << n.first << ". \n";
                    n.second.ShowInfo();
            }
            else {
                std::cout 
                    << "# Type of transaction : "
                    << "Sold " << "\n"
                    << "#Record in Base: " << n.first << ". \n";
                    n.second.ShowInfo();
            }
            std::cout << "\n";
        }
    else
        std::cout << "You've got no cars\n";
}
