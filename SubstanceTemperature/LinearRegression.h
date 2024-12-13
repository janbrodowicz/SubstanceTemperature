#pragma once

#include <vector>

/*
    Class used to calculate linear regression
*/
class LinearRegression
{
public:
    
    /*
        Default constructor
    */
    LinearRegression();

    /*
        Method to add data points

        @param1 x is the xAxis data point
        @param2 y is the yAxis data point
    */
    void addDataPoint(int x, float y);

    /*
        Method to calculate the regression

        @return true if the calculation was successfull, flase otherwise
    */
    bool calculate();

    /*
        Method to get beta coefficient

        @param beta is defined outside fo the method and overwritten by it

        @return true if beta was overwritten, false otherwise
    */
    bool getBeta(float& beta) const;

    /*
        Method to get alpha coefficient

        @param alpha is defined outside fo the method and overwritten by it

        @return true if alpha was overwritten, false otherwise
    */
    bool getAlpha(float& alpha) const;

    /*
        Method to predict the value of y for a given x

        @param1 x is the xAxis data point
        @param2 y_out is defined outside of the method and overwritten by it. It is the predicted value

        @return true if prediction was succsessfull, false otherwise
    */
    bool predict(int x, float& y_out) const;

private:

    // Vector holding x data
    std::vector<int> m_xData;

    // Vector holding y data
    std::vector<float> m_yData;

    // Alpha coefficient
    float m_alpha;

    // Beta coefficient
    float m_beta;

    // Additional field to hold information if regression was calculated
    bool m_isCalculated;
};
