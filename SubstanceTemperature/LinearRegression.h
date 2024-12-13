#pragma once

#include <vector>

class LinearRegression
{
public:
    // Constructor
    LinearRegression();

    // Method to add data points
    void addDataPoint(int x, float y);

    // Method to calculate the regression
    bool calculate();

    // Getters for alpha and beta
    bool getBeta(float& beta) const;

    bool getAlpha(float& alpha) const;

    // Predict the value of y for a given x
    bool predict(int x, float& y_out) const;

private:

    std::vector<int> m_xData;
    std::vector<float> m_yData;
    float m_alpha;
    float m_beta;
    bool m_isCalculated;
};
