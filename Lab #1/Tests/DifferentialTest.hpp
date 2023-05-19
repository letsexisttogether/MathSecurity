#pragma once

#include <bitset>

template <const std::size_t _SampleSize>
class DifferentialTest
{
public:
    DifferentialTest(const std::bitset<_SampleSize>& data)
        : m_Data{ data }
    {}

    float GetRelation()
    {
        float onesCount = 0;

        for (std::size_t i = 0; i < _SampleSize - 1; ++i)
        {
            onesCount += m_Data[i] ^ m_Data[i + 1];
        }

        return onesCount / (_SampleSize - 1);
    }

private:
    const std::bitset<_SampleSize>& m_Data;
};