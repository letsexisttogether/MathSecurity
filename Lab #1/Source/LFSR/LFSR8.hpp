#pragma once

#include "LFSR.hpp"

// The polinom: x^8 + x^4 + x^3 + x^2 + 1

class LFSR8 : public LFSR
{
public:
    LFSR8() = delete;
    LFSR8(const LFSR8&) = default;
    LFSR8(LFSR8&&) = default;

    LFSR8(const std::bitset<8>& bits);
    LFSR8(std::bitset<8>&& bits);

    ~LFSR8() override = default;

    const bool GetNextValue() noexcept;

    LFSR8& operator = (const LFSR8&) = delete;
    LFSR8& operator = (LFSR8&&) = delete;

protected:
    void CalcualteNextSequence() noexcept override;

private:
    std::bitset<8> m_CurrentState;
};