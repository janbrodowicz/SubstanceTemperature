#include "pch.h"
#include "SubstanceNamesContainer.h"

#include <algorithm>


SubstanceNamesContainer::SubstanceNamesContainer()
{

}

bool SubstanceNamesContainer::nameExists(CString& substanceName) const
{
    bool res = false;

    auto lambda = [substanceName](const std::string& name) {
        std::string lower_name = name;
        std::transform(lower_name.begin(), lower_name.end(), lower_name.begin(), ::tolower);

        CStringA substanceNameA(substanceName);
        std::string lower_substanceName = std::string(substanceNameA);
        std::transform(lower_substanceName.begin(), lower_substanceName.end(), lower_substanceName.begin(), ::tolower);

        return lower_name == lower_substanceName; };

    auto it = std::find_if(m_substancesNames.begin(), m_substancesNames.end(), lambda);

    if (it != m_substancesNames.end())
    {
        res = true;
    }

    return res;
}

void SubstanceNamesContainer::addSubstanceName(CString& newSubstanceName)
{
    std::string substanceNameStr = std::string(CStringA(newSubstanceName));

    m_substancesNames.push_back(substanceNameStr);

    std::sort(m_substancesNames.begin(), m_substancesNames.end());
}

void SubstanceNamesContainer::removeSubstanceName(CString& nameToRemove)
{
    std::string substanceNameStr = std::string(CStringA(nameToRemove));

    auto newEnd = std::remove_if(m_substancesNames.begin(), m_substancesNames.end(),
        [substanceNameStr](const std::string& element) {
            return element == substanceNameStr;
        });

    m_substancesNames.erase(newEnd, m_substancesNames.end());
}