#include "pch.h"
#include "LinearRegression.h"

#include <numeric>
#include <stdexcept>
#include <cmath>


LinearRegression::LinearRegression() : 
    m_alpha(0), 
    m_beta(0), 
    m_isCalculated(false) 
{

}

void LinearRegression::addDataPoint(int x, float y)
{
    m_xData.push_back(x);
    m_yData.push_back(y);
    m_isCalculated = false;
}

bool LinearRegression::calculate()
{
    if (m_xData.size() != m_yData.size() || m_xData.size() < 2)
    {
        return false;
    }

    size_t n = m_xData.size();

    float meanX = std::accumulate(m_xData.begin(), m_xData.end(), 0.0) / n;
    float meanY = std::accumulate(m_yData.begin(), m_yData.end(), 0.0) / n;

    float numerator = 0.0;
    float denominator = 0.0;

    for (size_t i = 0; i < n; ++i)
    {
        float xDiff = m_xData[i] - meanX;
        float yDiff = m_yData[i] - meanY;

        numerator += xDiff * yDiff;
        denominator += xDiff * xDiff;
    }

    if (std::abs(denominator) < 1e-10)
    {
        return false;
    }

    m_alpha = numerator / denominator;
    m_beta = meanY - m_alpha * meanX;
    m_isCalculated = true;

    return true;
}


bool LinearRegression::getBeta(float& beta) const
{
    if (!m_isCalculated)
    {
        return false;
    }

    beta = m_beta;

    return true;
}

bool LinearRegression::getAlpha(float& alpha) const
{
    if (!m_isCalculated)
    {
        return false;
    }

    alpha = m_alpha;

    return true;
}

bool LinearRegression::predict(int x, float& y_out) const
{
    if (!m_isCalculated)
    {
        return false;
    }

    y_out = m_alpha * x + m_beta;

    return true;
}