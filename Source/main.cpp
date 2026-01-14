#include "model/Car.hpp"
#include "model/Owner.hpp"
#include "controller/MarketController.hpp"
#include "infrastructure/EventEmitter.hpp"
#include "view/View.hpp"

#include <memory>

int main() {
    EventEmitter emitter;

    // Create cars
    auto car1 = std::make_shared<Car>("BMW", 100000);
    auto car2 = std::make_shared<Car>("Audi", 80000);

    // Degrade cars automatically
    emitter.AddListener([car1]() { car1->Degrade(); });
    emitter.AddListener([car2]() { car2->Degrade(); });

    Owner alice("Alice", 150000);
    Owner bob("Bob", 50000);

    MarketController controller;

    View view;

    // Live display
    view.AddLiveDisplay([&]() {
        std::cout << "Alice's Cars:\n";
        for (auto& [id, car] : alice.Cars())
            std::cout << id << ". " << car->Model()
            << " Price: " << car->CurrentPrice()
            << " Available: " << car->IsAvailable() << "\n";
        });

    view.AddLiveDisplay([&]() {
        std::cout << "Bob's Cars:\n";
        for (auto& [id, car] : bob.Cars())
            std::cout << id << ". " << car->Model()
            << " Price: " << car->CurrentPrice()
            << " Available: " << car->IsAvailable() << "\n";
        });

    // Menu actions
    view.AddMenuItem("Alice buys BMW", [&]() {
        controller.BuyCar(alice, car1);
        std::cout << "Alice bought BMW.\n";
        });

    view.AddMenuItem("Alice sells BMW to Bob", [&]() {
        controller.SellCar(alice, bob, 1);
        std::cout << "Transaction done.\n";
        });

    view.AddMenuItem("Exit", [&]() { view.Stop(); });

    // Run app loop
    view.Run();

    return 0;
}
