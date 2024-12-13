#include "pch.h"
#include "InstrumentsContainer.h"

#include <algorithm>


InstrumentsContainer::InstrumentsContainer()
{

}

Instrument* InstrumentsContainer::getInstrumentByID(int id)
{
    auto it = std::find_if(m_instruments.begin(), m_instruments.end(),
        [id](const Instrument& instrument) { return instrument.getId() == id; });

    if (it != m_instruments.end())
    {
        return &(*it);
    }
    return nullptr;
}

void InstrumentsContainer::addInstrument(Instrument& newInstrument)
{
    m_instruments.push_back(newInstrument);

    std::sort(m_instruments.begin(), m_instruments.end(), [](const Instrument& a, const Instrument& b) {
        return a.getId() < b.getId(); });
}

void InstrumentsContainer::removeInstrument(int idToRemove)
{
    auto newEnd = std::remove_if(m_instruments.begin(), m_instruments.end(),
        [idToRemove](const Instrument& instrument) {
            return instrument.getId() == idToRemove;
        });

    m_instruments.erase(newEnd, m_instruments.end());
}

void InstrumentsContainer::removeInstrumentsWihoutSubstance()
{
    auto newEnd = std::remove_if(m_instruments.begin(), m_instruments.end(),
        [](const Instrument& instrument) {
            return !instrument.containsAnySubstance();
        });

    m_instruments.erase(newEnd, m_instruments.end());
}