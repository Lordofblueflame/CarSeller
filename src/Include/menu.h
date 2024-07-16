#ifndef MENU_H
#define MENU_H

#include "pch.h"
#include "owner.h"
class Menu 
{
public:
    Menu();
    void MenuLoop();
    void InitializeValues();
    void PrintMenu();
    void PrintSummaryOfTransactions();
    void PrintSellCarMenu();
    void PrintBuyCarMenu();
private:
    
public:

private:
    Owner user;
    Owner npcSeller;
    int choice = 0;
};

#endif // MENU_H