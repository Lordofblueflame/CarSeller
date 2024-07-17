#ifndef MENU_H
#define MENU_H

#pragma once

#include "pch.h"
#include "owner.h"

class Menu 
{
public:
    Menu();
    void MenuLoop();

private:
    void InitializeValues();
    void PrintMenu();
    void PrintSummaryOfTransactions();
    void PrintSellCarMenu();
    void PrintBuyCarMenu();

private:
    Owner m_user;
    Owner m_npcSeller;
    int m_choice = 0;
};

#endif // MENU_H