#include "../LFSR8.hpp"

#include <utility>

LFSR8::LFSR8(const std::bitset<8>& bits)
    : m_CurrentState{ bits }
{}

LFSR8::LFSR8(std::bitset<8>&& bits)
    : m_CurrentState{ std::move(bits) }
{}
const std::bitset<1> LFSR8::GetNextValue() noexcept
{
    return std::bitset<1>();
}
