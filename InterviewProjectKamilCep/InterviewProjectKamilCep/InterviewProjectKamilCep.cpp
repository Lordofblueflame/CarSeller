#include "Car.h"
#include "Owner.h"
#include <cstdlib>


void Menu(int& choice, Owner owner)
{
	system("cls");
	std::cout << "##########################################\n";
	std::cout << "#		Menu\n";
	std::cout << "#1. Buy Car\n";
	std::cout << "#2. Sell Car\n";
	std::cout << "#3. Car Summary\n";
	std::cout << "#4. Exit\n";
	std::cout << "##########################################\n";
	owner.MyMoney();
	std::cout << "Navigation note, write number that represents your choice of action\n";
	std::cin >> choice;
	system("cls");
}

void BuyCarMenu(Owner& carOwner, Owner& carBuyier, int& choice)
{
	std::unique_lock<std::mutex> lock(mutex1);
	std::cout << "##########################################\n";
	std::cout << "#		Buying Cars\n";
	carOwner.ShowCarsForSellers();
	std::cout << "##########################################\n";
	std::cout << "TO EXIT WRITE 999\n";
	carBuyier.MyMoney();
	std::cout << "Pick yours: ";
	std::cin >> choice;
	if (choice != 999)
		carOwner.SellCar(choice, &carBuyier);
	lock.unlock();
}

void SellCarMenu(Owner& carOwner, Owner& carBuyier, int& choice)
{
	std::unique_lock<std::mutex> lock(mutex1);
	std::cout << "##########################################\n";
	std::cout << "#		Selling Cars\n";
	carOwner.ShowCarsForSellers();
	std::cout << "##########################################\n";
	std::cout << "TO EXIT WRITE 999\n";
	std::cout << "Pick to Sell: ";
	std::cin >> choice;
	if (choice != 999)
		carOwner.SellCar(choice, &carBuyier);
	lock.unlock();
}

void SummaryOfTransactionsMenu(Owner owner, Owner owner2)
{
	std::unique_lock<std::mutex> lock(mutex1);
	std::cout << "##########################################\n";
	std::cout << "#		Car Summary\n";
	owner.SummaryOfTheDay();
	std::cout << "##########################################\n";
	std::cout << "\n";
	std::cout << "##########################################\n";
	std::cout << "#		Car Summary\n";
	owner2.SummaryOfTheDay();
	std::cout << "##########################################\n";
	system("PAUSE");
	lock.unlock();
}

int main()
{
	int choice = 0;

	std::cout << "	Initialization of data\n";
	std::this_thread::sleep_for(std::chrono::seconds(2));

	system("cls");

	Car BMW = Car("E36", "2000/01/21", 5123, 0, 1);
	Car Opel("Astra", "2010/04/10", 8214, 0, 1);
	Car Volkswagen("Golf 4", "2000/05/20", 6123, 0, 1);
	Owner ShopOwner("Kamil", "Cep", 100000);
	Owner SomeCarSeller("John", "Montana", 10000);

	SomeCarSeller.AddCar(Opel);
	SomeCarSeller.AddCar(Volkswagen);
	ShopOwner.AddCar(BMW);

	std::cout << "	Data loaded thanks for waiting \n";
	std::this_thread::sleep_for(std::chrono::seconds(1));

	system("cls");
	while (choice != 4)
	{
		Menu(choice, ShopOwner);

		if (choice == 1)
			BuyCarMenu(SomeCarSeller, ShopOwner, choice);
		else if (choice == 2)
			SellCarMenu(ShopOwner, SomeCarSeller, choice);
		else if (choice == 3)
			SummaryOfTransactionsMenu(ShopOwner, SomeCarSeller);
		else
			break;
	}

	return 0;

}

