#include "include/eventEmitter.h"

EventEmitter::EventEmitter() {
    BOOST_LOG_TRIVIAL(info) << "EventEmitter constructor";
    running = true; 
    timerThread = std::thread([this]() { this->TimerLoop(); });
    timerThread.detach();
}

EventEmitter::~EventEmitter() {
    running = false; 
    if (timerThread.joinable()) {
        timerThread.join(); 
    }
    BOOST_LOG_TRIVIAL(info) << "EventEmitter destructor";
}

void EventEmitter::AddListener(const Listener& listener) {
    std::lock_guard<std::mutex> lock(listenersMutex);
    listeners.push_back(listener);
    BOOST_LOG_TRIVIAL(info) << "Added listener";
}

void EventEmitter::Emit() {
    std::lock_guard<std::mutex> lock(listenersMutex);
    BOOST_LOG_TRIVIAL(info) << "Event Emit";
    for (auto it = listeners.begin(); it != listeners.end();) {
        if (*it) {
            (*it)();
            ++it;
        } else {
            it = listeners.erase(it);
        }
    }
}

void EventEmitter::TimerLoop() {
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(5));
        {
            std::lock_guard<std::mutex> lock(runningMutex);
            if (!running) {
                break;
            }
        }
        Emit();
    }
    BOOST_LOG_TRIVIAL(info) << "TimerLoop exited";
}
