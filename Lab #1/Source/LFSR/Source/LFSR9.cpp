#include "../LFSR9.hpp"

#include <utility>

LFSR9::LFSR9(const std::bitset<9>& bits)
    : m_CurrentState{ bits }
{}

LFSR9::LFSR9(std::bitset<9>&& bits)
    : m_CurrentState{ std::move(bits) }
{}
const bool LFSR9::GetNextValue() noexcept
{   
    const bool lastValue = m_CurrentState[8]; 

    CalcualteNextSequence();
  
    return lastValue;
}

void LFSR9::CalcualteNextSequence() noexcept
{
    const bool xorValue = m_CurrentState[8];

    m_CurrentState <<= 1;

    m_CurrentState[0] = xorValue; // 1 node new value
    m_CurrentState[3] = m_CurrentState[3] ^ xorValue; // 2 node xor

}
