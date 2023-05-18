#pragma once

#include "LFSR.hpp"

class LFSR8 : public LFSR
{
public:
    LFSR8() = delete;
    LFSR8(const LFSR8&) = default;
    LFSR8(LFSR8&&) = default;

    LFSR8(const std::bitset<8>& bits);
    LFSR8(std::bitset<8>&& bits);

    ~LFSR8() = default;

    const std::bitset<1> GetNextValue() noexcept;

    LFSR8& operator = (const LFSR8&) = delete;
    LFSR8& operator = (LFSR8&&) = delete;

private:
    

private:
    std::bitset<8> m_CurrentState;
};