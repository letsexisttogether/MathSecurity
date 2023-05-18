#include "../LFSR8.hpp"

#include <iostream>
#include <utility>

LFSR8::LFSR8(const std::bitset<8>& bits)
    : m_CurrentState{ bits }
{}

LFSR8::LFSR8(std::bitset<8>&& bits)
    : m_CurrentState{ std::move(bits) }
{}
const bool LFSR8::GetNextValue() noexcept
{   
    const bool lastValue = m_CurrentState[7]; 

    CalcualteNextSequence();
  
    return lastValue;
}

void LFSR8::CalcualteNextSequence() noexcept
{
    const bool xorValue = m_CurrentState[7];

    m_CurrentState <<= 1;

    m_CurrentState[0] = xorValue; // 1 node new value
    m_CurrentState[2] = m_CurrentState[2] ^ xorValue; // 3 node xor
    m_CurrentState[3] = m_CurrentState[3] ^ xorValue; // 4 node xor 
    m_CurrentState[4] = m_CurrentState[4] ^ xorValue; // 5 node xor 
}
