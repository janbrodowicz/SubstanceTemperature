#pragma once

#include "Instrument.h"

/*
	Class used as a container for instruments
*/
class InstrumentsContainer
{
public:

	/*
		Default constructor
	*/
	InstrumentsContainer();

	/*
		Method to get instrument from container by provided instrument id

		@param id is the provided intrument id

		@return pointer to Instrument object
	*/
	Instrument* getInstrumentByID(int id);

	/*
		Method to remove an intrument from container by provided id

		@param idToRemove is the provided instrument id
	*/
	void removeInstrument(int idToRemove);

	/*
		Method to remove all intruments from the container that don't hold any substances
	*/
	void removeInstrumentsWihoutSubstance();

	/*
		Method to add new instrument to the container

		@param newInstrument is the Instrument object to be added
	*/
	void addInstrument(Instrument& newInstrument);

	/*
		Iterators to use in for loops
	*/
	auto begin() { return m_instruments.begin(); }
	auto end() { return m_instruments.end(); }
	auto cbegin() const { return m_instruments.cbegin(); }
	auto cend() const { return m_instruments.cend(); }

private:

	// Vector holding Instrument objects
	std::vector<Instrument> m_instruments;
};