#include <chrono>
#include "Infrastructure/EventEmitter.hpp"


EventEmitter::EventEmitter() : running(true) {
    worker = std::thread(&EventEmitter::Loop, this);
}

EventEmitter::~EventEmitter() {
    running = false;
    if (worker.joinable())
        worker.join();
}

void EventEmitter::AddListener(Listener listener) {
    std::lock_guard<std::mutex> lock(mutex);
    listeners.push_back(std::move(listener));
}

void EventEmitter::Loop() {
    while (running) {
        std::this_thread::sleep_for(std::chrono::seconds(5));
        std::lock_guard<std::mutex> lock(mutex);
        for (auto& l : listeners)
            if (l) l();
    }
}
