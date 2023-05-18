#include "../LFSR4.hpp"

#include <iostream>
#include <utility>

LFSR4::LFSR4(const std::bitset<4>& bits)
    : m_CurrentState{ bits }
{}

LFSR4::LFSR4(std::bitset<4>&& bits)
    : m_CurrentState{ std::move(bits) }
{}
const bool LFSR4::GetNextValue() noexcept
{   
    const bool lastValue = m_CurrentState[3]; 

    CalcualteNextSequence();
  
    return lastValue;
}

void LFSR4::CalcualteNextSequence() noexcept
{
    const bool xorValue = m_CurrentState[3];

    m_CurrentState <<= 1;

    m_CurrentState[0] = xorValue; // 1 node 
    m_CurrentState[3] = m_CurrentState[3] ^ xorValue; // 4 node xor 
}
