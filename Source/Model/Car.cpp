#include "Model/Car.hpp"

Car::Car(std::string model, double basePrice, double degradation)
    : m_model(std::move(model)),
    m_basePrice(basePrice),
    m_degradation(degradation),
    m_available(true) {
}

double Car::CurrentPrice() const {
    return m_basePrice * (1.0 - m_degradation / 1000.0);
}

void Car::Degrade() {
    if (m_degradation < 200 && m_available)
        ++m_degradation;
}

bool Car::IsAvailable() const {
    return m_available;
}

void Car::SetAvailable(bool value) {
    m_available = value;
}

const std::string& Car::Model() const {
    return m_model;
}
