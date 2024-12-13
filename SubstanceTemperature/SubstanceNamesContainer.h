#pragma once

#include <afxstr.h>
#include <vector>
#include <string>

/*
	Class used as a container for substances names
*/
class SubstanceNamesContainer
{
public:

	/* 
		Default constructor
	*/
	SubstanceNamesContainer();

	/*
		Method for checking if a name exist in the container

		@param substanceName is the name to be found

		@return true if the name exists in the ocntainer, false otherwise
	*/
	bool nameExists(CString& substanceName) const;

	/*
		Method for adding new substance name to the constainer

		@param newSubstanceName is the name to be added
	*/
	void addSubstanceName(CString& newSubstanceName);

	/*
		Method for removing substance name from the constainer

		@param nameToRemove is the name to be removed
	*/
	void removeSubstanceName(CString& nameToRemove);

	/*
		Iterators to use in for loops
	*/
	auto begin() { return m_substancesNames.begin(); }
	auto end() { return m_substancesNames.end(); }
	auto cbegin() const { return m_substancesNames.cbegin(); }
	auto cend() const { return m_substancesNames.cend(); }

private:

	// Vector holding substances names
	std::vector<std::string> m_substancesNames;
};