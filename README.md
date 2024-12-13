# SubstanceTemperature

## Steps to run the app

1. Make sure you have Visual Studio and MFC installed
2. Clone the repository and open the project in Visual Studio (double click on the .sln file)
3. Build the project:
	* from the dropdown saying "Debug" choose "Release"
	* the next dropdown is to choose your machine architecture
	* after that click the green triangle, it should build and start the app

## App description

This apps allows the user to input:
	* measuring intrument id
	* measured substance name
	* nominal melting temperature for the substance 
	* measured melting temperaturę for the substance

The app also allows to choose from a list of predefined substances. Add button saves the input. Substance temperatures are possible to look up in the table below the inputs (just choose a substance from the dropdown above the table).
Update and Remove buttons work after choosing a position from the table.
The app also calculates linear regression for a substance.
Entered measured temperaturę values and the regression line are shown in a graph on the right.
Below the graph is the regression equation and its coefficients.