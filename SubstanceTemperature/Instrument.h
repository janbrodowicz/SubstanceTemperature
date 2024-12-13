#pragma once

#include <vector>
#include "Substance.h"


class Instrument
{
public:
    
    Instrument();

    Instrument(int id);

    Substance* findSubstance(std::string& substanceName);

    void removeSubstance(std::string& substanceName);

    int getId() const;

    void addSubstance(Substance& newSubstance);

    bool containsAnySubstance() const;

    void Serialize(CArchive& ar);

private:

    int m_id;
    std::vector<Substance> m_substances;
};