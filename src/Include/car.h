#ifndef CAR_H
#define CAR_H

#include "pch.h"
#include "eventEmitter.h"

class Car
{
public:
    Car(const std::string& model, const std::string& regDate, double price, double degradation, bool availability, std::shared_ptr<EventEmitter> emitter);
    ~Car();
    bool ShowAvailability() const;
    double CurrentPrice() const;
    double ShowDegradation() const;
    
    void ShowInfo() const;

    void ChangeAvailability(bool availability);
    void ChangePrice(double change);
    void PriceDegradation();


private:
    std::string m_model;
    std::string m_registrationDate;
    double m_firstPrice;
    double m_degradation;
    bool m_availability;
    std::shared_ptr<EventEmitter> m_emitter;
};

#endif // CAR_H
