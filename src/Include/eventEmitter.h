#ifndef EVENTEMITTER_H
#define EVENEMITTER_H

#include "pch.h"

class EventEmitter {
public:
    using Listener = std::function<void()>;

    EventEmitter();
    ~EventEmitter();

    void AddListener(const Listener& listener);
    void Emit();

private:
    void TimerLoop();

    std::vector<Listener> listeners;
    std::thread timerThread;
    std::mutex listenersMutex;
    std::mutex runningMutex;
    bool running = true;
};

#endif // EVENTEMITTER_H