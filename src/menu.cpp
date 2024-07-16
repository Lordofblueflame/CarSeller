#include "pch.h"
#include "include\menu.h"

Menu::Menu() { 
    InitializeValues();
}

void Menu::MenuLoop()
{   
    
	system("cls");
	while (choice != 4)
	{
		PrintMenu();

		if (choice == 1)
			PrintBuyCarMenu();
		else if (choice == 2)
			PrintSellCarMenu();
		else if (choice == 3)
			PrintSummaryOfTransactions();
		else
			break;
	}

	return;
}

void Menu::InitializeValues()
{
    Car bmw = Car("E36", "2000/01/21", 5123, 0, 1);
	Car opel("Astra", "2010/04/10", 8214, 0, 1);
	Car volkswagen("Golf 4", "2000/05/20", 6123, 0, 1);
	Owner user("Kamil", "Cep", 100000);
	Owner npcSeller("John", "Montana", 10000);

	npcSeller.AddCar(opel);
	npcSeller.AddCar(volkswagen);
	user.AddCar(bmw);

    this->user = user;
    this->npcSeller = npcSeller;
}

void Menu::PrintMenu()
{
	system("cls");
	std::cout << "##########################################\n";
	std::cout << "#   Menu\n";
	std::cout << "#1. Buy Car\n";
	std::cout << "#2. Sell Car\n";
	std::cout << "#3. Car Summary\n";
	std::cout << "#4. Exit\n";
	std::cout << "##########################################\n";
	user.MyMoney();
	std::cout << "Navigation note, write number that represents your choice of action\n";
	std::cin >> choice;
	system("cls");
}

void Menu::PrintSummaryOfTransactions()
{
    std::cout << "##########################################\n";
	std::cout << "#		Car Summary\n";
	user.SummaryOfTheDay();
	std::cout << "##########################################\n";
	std::cout << "\n";
    std::cout << "\n";
	std::cout << "##########################################\n";
	std::cout << "#		Car Summary\n";
	npcSeller.SummaryOfTheDay();
	std::cout << "##########################################\n";
	system("PAUSE");
}

void Menu::PrintSellCarMenu()
{
    std::cout << "##########################################\n";
	std::cout << "#		Selling Cars\n";
	user.ShowCarsForSellers();
	std::cout << "##########################################\n";
	std::cout << "TO EXIT WRITE 999\n";
	std::cout << "Pick to Sell: ";
	std::cin >> choice;
	if (choice != 999)
		user.SellCar(choice, &npcSeller);
}

void Menu::PrintBuyCarMenu()
{
    std::cout << "##########################################\n";
	std::cout << "#		Buying Cars\n";
	npcSeller.ShowCarsForSellers();
	std::cout << "##########################################\n";
	std::cout << "TO EXIT WRITE 999\n";
	user.MyMoney();
	std::cout << "Pick yours: ";
	std::cin >> choice;
	if (choice != 999)
		npcSeller.SellCar(choice, &user);
}
