#pragma once

#include "Instrument.h"


class InstrumentsContainer
{
public:

	InstrumentsContainer();

	Instrument* getInstrumentByID(int id);

	void removeInstrument(int idToRemove);

	void removeInstrumentsWihoutSubstance();

	void addInstrument(Instrument& newInstrument);

	auto begin() { return m_instruments.begin(); }
	auto end() { return m_instruments.end(); }
	auto cbegin() const { return m_instruments.cbegin(); }
	auto cend() const { return m_instruments.cend(); }

private:

	std::vector<Instrument> m_instruments;
};