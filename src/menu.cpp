#include "include\menu.h"

Menu::Menu() 
{ 
    InitializeValues();
}

void Menu::InitializeValues()
{
    BOOST_LOG_TRIVIAL(info) << "menu";
    std::shared_ptr<EventEmitter> emitter = std::make_shared<EventEmitter>();
    std::shared_ptr<Car> bmw = std::make_shared<Car>("E36", "2000/01/21", 5123, 0, true, emitter);
    std::shared_ptr<Car> opel = std::make_shared<Car>("Astra", "2010/04/10", 8214, 0, true, emitter);
    std::shared_ptr<Car> volkswagen = std::make_shared<Car>("Golf 4", "2000/05/20", 6123, 0, true, emitter);
    BOOST_LOG_TRIVIAL(info) << "After Adding cars";
    
    Owner user("Kamil", "Cep", 100000);
    Owner npcSeller("John", "Montana", 10000);

    npcSeller.AddCar(opel);
    npcSeller.AddCar(volkswagen);
    user.AddCar(bmw);

    m_user = user;
    m_npcSeller = npcSeller;
}

void Menu::PrintMenu()
{
    BOOST_LOG_TRIVIAL(info) << "Menu";
    std::cout << "##########################################\n";
    std::cout << "#   Menu\n";
    std::cout << "#1. Buy Car\n";
    std::cout << "#2. Sell Car\n";
    std::cout << "#3. Car Summary\n";
    std::cout << "#4. Exit\n";
    std::cout << "##########################################\n";
    m_user.MyMoney();
    std::cout << "Navigation note, write number that represents your choice of action\n";
    std::cin >> m_choice;
    
}

void Menu::PrintSummaryOfTransactions()
{
    BOOST_LOG_TRIVIAL(info) << "SummaryOfTransactions";
    std::cout << "##########################################\n";
    std::cout << "#       Car Summary\n";
    m_user.SummaryOfTheDay();
    std::cout << "##########################################\n";
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "##########################################\n";
    std::cout << "#       Car Summary\n";
    m_npcSeller.SummaryOfTheDay();
    std::cout << "##########################################\n";
    system("PAUSE");
}

void Menu::PrintSellCarMenu()
{
    BOOST_LOG_TRIVIAL(info) << "SellCarMenu";
    std::cout << "##########################################\n";
    std::cout << "#       Selling Cars\n";
    m_user.ShowCarsForSellers();
    std::cout << "##########################################\n";
    std::cout << "TO EXIT WRITE 999\n";
    std::cout << "Pick to Sell: ";
    std::cin >> m_choice;
    if (m_choice != 999)
        m_user.SellCar(m_choice, &m_npcSeller);
}

void Menu::PrintBuyCarMenu()
{
    BOOST_LOG_TRIVIAL(info) << "BuyCarMenu";
    std::cout << "##########################################\n";
    std::cout << "#       Buying Cars\n";
    m_npcSeller.ShowCarsForSellers();
    std::cout << "##########################################\n";
    std::cout << "TO EXIT WRITE 999\n";
    m_user.MyMoney();
    std::cout << "Pick yours: ";
    std::cin >> m_choice;
    if (m_choice != 999)
        m_npcSeller.SellCar(m_choice, &m_user);
}

void Menu::MenuLoop()
{
    while (m_choice != 4)
    {
        PrintMenu();

        if (m_choice == 1)
            PrintBuyCarMenu();
        else if (m_choice == 2)
            PrintSellCarMenu();
        else if (m_choice == 3)
            PrintSummaryOfTransactions();
        else
            break;
    }

    return;
}
