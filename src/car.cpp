#include "include\car.h"

Car::Car(const std::string& model, const std::string& regDate, double price, double degradation, bool availability, std::shared_ptr<EventEmitter> emitter)
    : m_model(model), m_registrationDate(regDate), m_firstPrice(price), m_degradation(degradation), m_availability(availability), m_emitter(emitter)
{
    BOOST_LOG_TRIVIAL(info) << "Car constructor";
    m_emitter->AddListener([this]() { this->PriceDegradation(); });
}

Car::~Car() {
    BOOST_LOG_TRIVIAL(info) << "Car destructor";
}

void Car::ChangeAvailability(bool availability)
{
    m_availability = availability;
}

void Car::ShowInfo() const
{
    std::cout << "#Model : " << m_model << "\n"
              << "#Registration date : " << m_registrationDate << "\n"
              << "#Price : " << CurrentPrice() << "\n"
              << "#Degradation : " << ShowDegradation() << "\n";
}

double Car::CurrentPrice() const
{
    return m_firstPrice - (m_firstPrice * (m_degradation / 1000));
}

void Car::ChangePrice(double change)
{
	Car::m_firstPrice = change;
}

double Car::ShowDegradation() const
{
    return m_degradation;
}

void Car::PriceDegradation()
{
    if (ShowDegradation() < 200 && m_availability) {
        m_degradation++;
        BOOST_LOG_TRIVIAL(info) << " Degradation for model: " << this->m_model 
                                << "\n Degradation by: " << this->ShowDegradation() 
                                << "\n Current Price: " << this->CurrentPrice();
    }
}

bool Car::ShowAvailability() const
{
    return m_availability;
}
