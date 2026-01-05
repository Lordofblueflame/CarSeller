#pragma once
#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <limits>

class View {
public:
    using Action = std::function<void()>;

    struct MenuItem {
        std::string text;
        Action action;
    };

    // Add a menu option
    void AddMenuItem(const std::string& text, Action action) {
        menu.push_back({ text, action });
    }

    // Start the menu loop
    void Run() {
        bool running = true;
        while (running) {
            ShowMenu();
            int choice = GetChoice();
            if (choice <= 0 || choice > static_cast<int>(menu.size())) {
                std::cout << "Invalid option. Try again.\n";
                continue;
            }

            // Execute selected action
            menu[choice - 1].action();

            std::cout << "\nPress Enter to continue...";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.get();

            // Example: exit on last item
            if (menu[choice - 1].text == "Exit")
                running = false;
        }
    }

private:
    std::vector<MenuItem> menu;

    void ShowMenu() const {
        std::cout << "\n==== Car Market Menu ====\n";
        for (size_t i = 0; i < menu.size(); ++i) {
            std::cout << i + 1 << ". " << menu[i].text << "\n";
        }
        std::cout << "========================\n";
        std::cout << "Select option: ";
    }

    int GetChoice() const {
        int choice;
        while (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Enter a number: ";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return choice;
    }
};
