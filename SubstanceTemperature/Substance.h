#pragma once

#include "afx.h"
#include <string>

class Substance
{
public:

    Substance();

    Substance(const std::string& name, float nominalTemp, float measuredTemp = 0.0);

    Substance(const Substance& substance);

    std::string getName() const;

    float getMeasuredTemp() const;

    float getNominalTemp() const;

    void setMeasuredTemp(float newMeasuredTemp);

    void Serialize(CArchive& ar);

private:

    std::string m_name;
    float m_nominalTempC;
    float m_measuredTempC;
};