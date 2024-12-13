#include "pch.h"
#include "ValidationCheck.h"

#include <algorithm>
#include <cctype>



ValidationCheck::ValidationCheck(CString& inputString) :
	m_inputString(inputString)
{

}

bool ValidationCheck::isIdCorrect(int& id) const
{
    bool res = false;

    if (m_inputString.IsEmpty())
    {
        return res;
    }

    res = std::all_of(m_inputString.GetString(), m_inputString.GetString() + m_inputString.GetLength(), ::isdigit);
    if (res)
    {
        id = _ttoi(m_inputString);

        if (id <= 0)
        {
            res = false;
        }
    }

    return res;
}

bool ValidationCheck::isSubstanceNameCorrect() const
{
    bool res = false;

    if (!m_inputString.IsEmpty())
    {
        res = true;
    }

    return res;
}

bool ValidationCheck::isTemperatureCorrect(float& temp) const
{
    bool res = false;

    if (m_inputString.IsEmpty())
    {
        return res;
    }

    res = isNumericWithSingleDot();

    if (res)
    {
        temp = _ttof(m_inputString);
    }

    return res;
}

bool ValidationCheck::isNumericWithSingleDot() const
{
    bool hasDot = false;
    bool hasDigit = false;

    int start = (m_inputString[0] == '+' || m_inputString[0] == '-') ? 1 : 0;

    for (int i = start; i < m_inputString.GetLength(); i++)
    {
        if (std::isdigit(m_inputString[i]))
        {
            hasDigit = true;
        }
        else if (m_inputString[i] == '.')
        {
            if (hasDot) return false;
            hasDot = true;
        }
        else
        {
            return false;
        }
    }

    return hasDigit;
}