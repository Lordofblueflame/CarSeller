#pragma once
#include <atomic>
#include <functional>
#include <mutex>
#include <thread>
#include <vector>

class EventEmitter {
public:
    using Listener = std::function<void()>;

    EventEmitter();
    ~EventEmitter();

    void AddListener(Listener listener);

private:
    void Loop();

    std::atomic<bool> running;
    std::vector<Listener> listeners;
    std::mutex mutex;
    std::thread worker;
};
