#pragma once

#include <afxstr.h>
#include <vector>
#include <string>


class SubstanceNamesContainer
{
public:

	SubstanceNamesContainer();

	bool nameExists(CString& substanceName) const;

	void addSubstanceName(CString& newSubstanceName);

	void removeSubstanceName(CString& nameToRemove);

	auto begin() { return m_substancesNames.begin(); }
	auto end() { return m_substancesNames.end(); }
	auto cbegin() const { return m_substancesNames.cbegin(); }
	auto cend() const { return m_substancesNames.cend(); }

private:

	std::vector<std::string> m_substancesNames;
};