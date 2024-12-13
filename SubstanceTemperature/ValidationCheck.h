#pragma once

#include <afxstr.h>

/*
	Class used to validate user input
*/
class ValidationCheck
{
public:

	/*
		Constructor

		@param inputString is the user input taken from CEdit
	*/
	ValidationCheck(CString& inputString);

	/*
		Method to check if the intrument id input is an integer and higher than 0

		@param id is an integer defined outside of the method and overwritten by this method

		@return true if id input is correct, false otherwise
	*/
	bool isIdCorrect(int& id) const;

	/*
		Method to check if the substance name input is not empty

		@return true if name is not empty, false otherwise
	*/
	bool isSubstanceNameCorrect() const;

	/*
		Method to check if the intrument id input is an integer and higher than 0

		@param temp is a float defined outside of the method and overwritten by this method

		@return true if temperature input is correct, false otherwise
	*/
	bool isTemperatureCorrect(float& temp) const;

private:

	/*
		Method to check if the temperature input is number with max one dot (.)

		@return true if is, false otherwise
	*/
	bool isNumericWithSingleDot() const;

	// Field holding user input
	CString m_inputString;
};