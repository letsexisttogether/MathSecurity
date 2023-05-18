#pragma once

#include "LFSR.hpp"

class LFSR4 : public LFSR
{
public:
    LFSR4() = delete;
    LFSR4(const LFSR4&) = default;
    LFSR4(LFSR4&&) = default;

    LFSR4(const std::bitset<4>& bits);
    LFSR4(std::bitset<4>&& bits);

    ~LFSR4() override = default;

    const bool GetNextValue() noexcept;

    LFSR4& operator = (const LFSR4&) = delete;
    LFSR4& operator = (LFSR4&&) = delete;
    
protected:
    void CalcualteNextSequence() noexcept override;

private:
    std::bitset<4> m_CurrentState;
};