#include "pch.h"
#include "Instrument.h"


Instrument::Instrument() : 
    m_id(1)
{

}

Instrument::Instrument(int id) : 
    m_id(id)
{

}

Substance* Instrument::findSubstance(std::string& substanceName)
{
    auto it = std::find_if(m_substances.begin(), m_substances.end(),
        [substanceName](const Substance& substance) { return substance.getName() == substanceName; });

    if (it != m_substances.end())
    {
        return &(*it);
    }

    return nullptr;
}

void Instrument::removeSubstance(std::string& substanceName)
{
    auto newEnd = std::remove_if(m_substances.begin(), m_substances.end(),
        [substanceName](const Substance& substance) {
            return substance.getName() == substanceName;
        });

    m_substances.erase(newEnd, m_substances.end());
}

int Instrument::getId() const
{
    return m_id;
}

void Instrument::addSubstance(Substance& newSubstance)
{
    m_substances.push_back(newSubstance);
}

bool Instrument::containsAnySubstance() const
{
    bool res = true;

    if (m_substances.empty())
    {
        res = false;
    }

    return res;
}


void Instrument::Serialize(CArchive& ar) 
{
    if (ar.IsStoring()) 
    {
        ar << m_id;
        ar << (int)m_substances.size();

        for (auto& substance : m_substances)
        {
            substance.Serialize(ar);
        }
    }
    else 
    {
        ar >> m_id;

        int substanceCount;
        ar >> substanceCount;

        m_substances.clear();
        for (int i = 0; i < substanceCount; ++i) 
        {
            Substance substance;
            substance.Serialize(ar);
            m_substances.push_back(substance);
        }
    }
}