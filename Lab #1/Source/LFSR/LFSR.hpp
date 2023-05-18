#pragma once

#include <bitset>

class LFSR
{
public:
    virtual ~LFSR() = 0 {}

    virtual const std::bitset<1> GetNextValue() noexcept = 0;
};