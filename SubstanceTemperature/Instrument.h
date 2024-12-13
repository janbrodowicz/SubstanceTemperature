#pragma once

#include <vector>
#include "Substance.h"

/*
    Class representing instrument
*/
class Instrument
{
public:
    
    /*
        Deafult constructor
    */
    Instrument();

    /*
        Custom constructor

        @param id is the id of the instrument
    */
    Instrument(int id);

    /*
        Method to get the Substance object

        @param substanceName is the name of the substance to get

        @return pointer to a Substance object
    */
    Substance* findSubstance(std::string& substanceName);

    /*
        Method to remove substance

        @param substanceName is the name of the substance to be removed
    */
    void removeSubstance(std::string& substanceName);

    /*
        Method to get the instrument id

        @return id of the instrument
    */
    int getId() const;

    /*
        Method to add substance

        @param newSubstance is a Substance object to be added
    */
    void addSubstance(Substance& newSubstance);

    /*
        Method to check whether Instrument constains any substances

        @return true if constains any substances, false otherwise
    */
    bool containsAnySubstance() const;

    void Serialize(CArchive& ar);

private:

    // Instrument id
    int m_id;

    // Vector holding Substances
    std::vector<Substance> m_substances;
};