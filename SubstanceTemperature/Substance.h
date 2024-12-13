#pragma once

#include "afx.h"
#include <string>

/*
    Class representing substance
*/
class Substance
{
public:

    /*
        Deafult constructor
    */
    Substance();

    /*
        Custom constructor 

        @param1 name is the name of substance
        @param2 nominalTemp is the nominal melting temperature of the substance
        @param3 measuredTemp is the measured melting temperature of the substance
    */
    Substance(const std::string& name, float nominalTemp, float measuredTemp = 0.0);

    /*
        Copying constructor

        @param substance is the substance to be copied
    */
    Substance(const Substance& substance);

    /*
        Method to get the name of the substance

        @return name of the substance
    */
    std::string getName() const;

    /*
        Method to get the measured melting temperature of the substance

        @return measured melting temperature of the substance
    */
    float getMeasuredTemp() const;

    /*
        Method to get the nominal melting temperature of the substance

        @return nominal melting temperature of the substance
    */
    float getNominalTemp() const;

    /*
        Method to set the measured melting temperature of the substance

        @param newMeasuredTemp is the new measured melting temperature
    */
    void setMeasuredTemp(float newMeasuredTemp);

    void Serialize(CArchive& ar);

private:

    // Name of the substance
    std::string m_name;

    // Nominal melting temperature
    float m_nominalTempC;

    // Measured melting temperature
    float m_measuredTempC;
};