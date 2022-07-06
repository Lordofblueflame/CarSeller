#include "Car.h"
#include "Owner.h"
#include <thread>
#include <cstdlib>


int main()
{
	int Fchoice = 0;
	int Schoice = 0;
	
	std::cout << "	Initialization of data\n";
	std::this_thread::sleep_for(std::chrono::seconds(2));

	system("cls");

	Car BMW = Car("E36", "2000/01/21", 5123, 0, 1);
	Car Opel("Astra", "2010/04/10",8214,0,1);
	Car Volkswagen("Golf 4", "2000/05/20", 6123, 0, 1);
	Owner ShopOwner("Kamil","Cep",100000);
	Owner SomeCarSeller("John", "Montana",10000);

	SomeCarSeller.AddCar(Opel);
	SomeCarSeller.AddCar(Volkswagen);
	ShopOwner.AddCar(BMW);
	
	std::cout << "	Data loaded thanks for waiting \n";
	std::this_thread::sleep_for(std::chrono::seconds(1));

	system("cls");
	while (Fchoice != 4)
	{
		system("cls");
		std::cout << "##########################################\n";
		std::cout << "#		Menu\n";
		std::cout << "#1. Buy Car\n";
		std::cout << "#2. Sell Car\n";
		std::cout << "#3. Car Summary\n";
		std::cout << "#4. Exit\n";
		std::cout << "##########################################\n";
		ShopOwner.MyMoney();
		std::cout << "Navigation note, write number that represents your choice of action\n";
		std::cin >> Fchoice;
		system("cls");


		if (Fchoice == 1) {
			std::unique_lock<std::mutex> lock(mutex1);
			std::cout << "##########################################\n";
			std::cout << "#		Buying Cars\n";
			SomeCarSeller.ShowCarsForSellers();
			std::cout << "##########################################\n";
			std::cout << "TO EXIT WRITE 999\n";
			ShopOwner.MyMoney();
			std::cout << "Pick yours: ";
			std::cin >> Schoice;
			if (Schoice != 999)
				SomeCarSeller.SellCar(Schoice, &ShopOwner);
			lock.unlock();
		}
		else if (Fchoice == 2) {
			std::unique_lock<std::mutex> lock(mutex1);
			std::cout << "##########################################\n";
			std::cout << "#		Selling Cars\n";
			ShopOwner.ShowCarsForSellers();
			std::cout << "##########################################\n";
			std::cout << "TO EXIT WRITE 999\n";
			std::cout << "Pick to Sell: ";
			std::cin >> Schoice;
			if (Schoice != 999)
				ShopOwner.SellCar(Schoice, &SomeCarSeller);
			lock.unlock();
		}
		else if (Fchoice == 3) {
			std::unique_lock<std::mutex> lock(mutex1);
			std::cout << "##########################################\n";
			std::cout << "#		Car Summary\n";
			ShopOwner.SummaryOfTheDay();
			std::cout << "##########################################\n";
			std::cout << "\n";
			std::cout << "##########################################\n";
			std::cout << "#		Car Summary\n";
			SomeCarSeller.SummaryOfTheDay();
			std::cout << "##########################################\n";
			system("PAUSE");
			lock.unlock();
		}
		else
			break;
	}
	
	return 0;

}

