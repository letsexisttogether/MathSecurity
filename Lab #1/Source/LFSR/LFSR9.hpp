#pragma once

#include "LFSR.hpp"

// The polinom: x^9 + x^4 + 1

class LFSR9 : public LFSR
{
public:
    LFSR9() = delete;
    LFSR9(const LFSR9&) = default;
    LFSR9(LFSR9&&) = default;

    LFSR9(const std::bitset<9>& bits);
    LFSR9(std::bitset<9>&& bits);

    ~LFSR9() override = default;

    const bool GetNextValue() noexcept;

    LFSR9& operator = (const LFSR9&) = delete;
    LFSR9& operator = (LFSR9&&) = delete;

protected:
    void CalcualteNextSequence() noexcept override;

private:
    std::bitset<9> m_CurrentState;
};