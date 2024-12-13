#pragma once

#include <afxstr.h>


class ValidationCheck
{
public:

	ValidationCheck(CString& inputString);

	bool isIdCorrect(int& id) const;

	bool isSubstanceNameCorrect() const;

	bool isTemperatureCorrect(float& temp) const;

private:

	bool isNumericWithSingleDot() const;

	CString m_inputString;
};