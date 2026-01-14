#pragma once
#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <thread>
#include <atomic>
#include <mutex>
#include <chrono>

class View {
public:
    using Action = std::function<void()>;

    struct MenuItem {
        std::string text;
        Action action;
    };

    View() : running(true) {}

    ~View() {
        Stop();
    }

    void AddMenuItem(const std::string& text, Action action) {
        menu.push_back({ text, action });
    }

    // Starts the main loop (non-blocking updates)
    void Run() {
        // Start background display loop
        std::thread displayThread(&View::DisplayLoop, this);

        // Input menu loop
        while (running) {
            ShowMenu();
            int choice = GetChoice();
            if (choice <= 0 || choice > static_cast<int>(menu.size())) {
                std::cout << "Invalid option. Try again.\n";
                continue;
            }

            // Execute selected action
            menu[choice - 1].action();

            // Exit if menu item is "Exit"
            if (menu[choice - 1].text == "Exit") {
                running = false;
            }
        }

        // Join display thread before exit
        if (displayThread.joinable())
            displayThread.join();
    }

    void Stop() {
        running = false;
    }

private:
    std::vector<MenuItem> menu;
    std::atomic<bool> running;
    std::mutex printMutex;

    void ShowMenu() {
        std::lock_guard<std::mutex> lock(printMutex);
        std::cout << "\n==== Car Market Menu ====\n";
        for (size_t i = 0; i < menu.size(); ++i) {
            std::cout << i + 1 << ". " << menu[i].text << "\n";
        }
        std::cout << "========================\n";
        std::cout << "Select option: ";
    }

    int GetChoice() {
        int choice;
        while (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input. Enter a number: ";
        }
        std::cin.ignore(10000, '\n'); // discard remaining input
        return choice;
    }

    // Display loop that shows dynamic updates
    void DisplayLoop() {
        while (running) {
            std::this_thread::sleep_for(std::chrono::seconds(2));

            std::lock_guard<std::mutex> lock(printMutex);
            std::cout << "\n=== LIVE CAR UPDATE ===\n";
            for (const auto& f : liveDisplays)
                f();
            std::cout << "======================\n";
        }
    }

public:
    // Register a live display function to be called every update
    void AddLiveDisplay(Action displayFn) {
        liveDisplays.push_back(displayFn);
    }

private:
    std::vector<Action> liveDisplays;
};
