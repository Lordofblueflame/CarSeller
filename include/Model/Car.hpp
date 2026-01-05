#pragma once
#include <string>

class Car {
public:
    Car(std::string model, double basePrice, double degradation = 0.0);

    double CurrentPrice() const;
    void Degrade();

    bool IsAvailable() const;
    void SetAvailable(bool value);

    const std::string& Model() const;

private:
    std::string m_model;
    double m_basePrice;
    double m_degradation;
    bool m_available;
};
