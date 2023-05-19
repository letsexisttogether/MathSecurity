#pragma once

#include <bitset>

template <const std::size_t _SampleSize>
class FrequencyTest
{
public:
    FrequencyTest(const std::bitset<_SampleSize>& data)
        : m_Data{ data }
    {}

    float GetRelation()
    {
        float onesCount = 0;

        for (std::size_t i = 0; i < _SampleSize; ++i)
        {
            onesCount += m_Data[i];
        }

        return onesCount / _SampleSize;
    }

private:
    const std::bitset<_SampleSize>& m_Data;
};