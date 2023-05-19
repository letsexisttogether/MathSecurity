#pragma once

#include <stdexcept>
#include <cmath>

#include "../LFSR/LFSRCalculator.hpp"

template <const std::size_t _TwoPowBitWidth, const std::size_t _SampleSize>
class TableGenerator
{
public:
    TableGenerator(std::vector<LFSR*>&& lsfrModules, std::bitset<_TwoPowBitWidth>&& bitTable)
        : m_LFSRModules{ std::move(lsfrModules) }, m_BitTable{ std::move(bitTable) }
    {
        if (pow(2, m_LFSRModules.size()) != _TwoPowBitWidth)
        {
            throw std::invalid_argument{ "Unable to calculate the required bit width with the given amount of LFSR modules" };
        }
    }

    ~TableGenerator() 
    {
        for (const auto& ptr : m_LFSRModules)
        {
            delete ptr;
        }    
    }

public:
    void Generate() noexcept
    {
        for (std::size_t i = 0; i < _SampleSize; ++i)
        {
            std::size_t address = 0;

            for (std::uint8_t j = 0; j < m_LFSRModules.size(); ++j)
            {
                address |= (m_LFSRModules[j]->GetNextValue() << j);
            }

            m_GeneratedSequence[i] = m_BitTable[address];
        }
    }

    inline const std::bitset<_SampleSize>& GetGeneratedSequence() const noexcept { return m_GeneratedSequence; }

private:
    std::vector<LFSR*> m_LFSRModules;
    const std::bitset<_TwoPowBitWidth> m_BitTable;

    std::bitset<_SampleSize> m_GeneratedSequence;
};