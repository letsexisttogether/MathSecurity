#pragma once

#include <bitset>
#include <unordered_map>
#include <cmath>

template <const std::size_t _SampleSize>
class RankTest
{
public:
    RankTest(const std::bitset<_SampleSize>& data)
        : m_Data{ data }
    {}

    bool CheckRankMatch(const std::size_t windowsSize, const std::size_t maxDifference)
    {
        std::unordered_map<std::uint32_t, std::size_t> frequency{};

        for (std::size_t i = 0; i < _SampleSize; ++i)
        {
            std::uint32_t value = 0;
            for (std::uint8_t j = 0; j < windowsSize; ++j)
            {
                value |= (m_Data[i + j] << j); 
            }

            ++frequency[value];
        } 

        const std::size_t firstFreq = frequency.begin()->second;
        for (const auto& iter : frequency)
        {
            // if (std::abs(iter.second - firstFreq) > maxDifference)
            // {
            //     std::cout << firstFreq << ' ' << iter.second;
            //     return false;
            // }
            std::cout << "Value: " << iter.first << " Freq: " << iter.second << '\n'; 
        }

        return true;
    }

private:
    const std::bitset<_SampleSize>& m_Data;
};