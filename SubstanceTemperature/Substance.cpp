#include "pch.h"
#include "Substance.h"


Substance::Substance():
	m_nominalTempC(0), 
	m_measuredTempC(0)
{

}

Substance::Substance(const std::string& name, float nominalTemp, float measuredTemp) :
	m_name(name), 
	m_nominalTempC(nominalTemp), 
	m_measuredTempC(measuredTemp)
{

}

Substance::Substance(const Substance& substance)
{
    m_name = substance.m_name;
    m_nominalTempC = substance.m_nominalTempC;
    m_measuredTempC = substance.m_measuredTempC;
}

std::string Substance::getName() const
{
    return m_name;
}

float Substance::getMeasuredTemp() const
{
    return m_measuredTempC;
}

float Substance::getNominalTemp() const
{
    return m_nominalTempC;
}

void Substance::setMeasuredTemp(float newMeasuredTemp)
{
    m_measuredTempC = newMeasuredTemp;
}


void Substance::Serialize(CArchive& ar) 
{
    if (ar.IsStoring()) 
    {
        ar << CString(m_name.c_str()) << m_nominalTempC << m_measuredTempC;
    }
    else 
    {
        CString tempName;
        ar >> tempName >> m_nominalTempC >> m_measuredTempC;
        m_name = std::string(CT2CA(tempName));
    }
}