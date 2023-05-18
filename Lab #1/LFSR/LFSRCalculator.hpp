#pragma once

#include <bitset>
#include <vector>

#include "LFSR.hpp"

template <const std::uint8_t _BitWidth>
class LFSRCalculator : public LFSR
{
public: 
    LFSRCalculator(const std::uint64_t startValue, const std::vector<std::uint8_t>&& xorIndexes)
        : m_CurrentState{ startValue }, m_XorIndexes{ xorIndexes }
    {}

    bool GetNextValue() noexcept override
    {   
        const bool lastValue = m_CurrentState[_BitWidth - 1]; 

        CalcualteNextSequence();
  
        return lastValue;
    }

private:
    void CalcualteNextSequence() noexcept
    {
        const bool xorValue = m_CurrentState[_BitWidth - 1];

        m_CurrentState <<= 1;

        m_CurrentState[0] = xorValue;

        for (const std::uint8_t index : m_XorIndexes)
        {
            m_CurrentState[index] = m_CurrentState[index] ^ xorValue;
        }
    }
    
private:
    std::bitset<_BitWidth> m_CurrentState;
    std::vector<std::uint8_t> m_XorIndexes{};
};