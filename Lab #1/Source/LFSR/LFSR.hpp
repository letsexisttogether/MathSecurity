#pragma once

#include <bitset>

class LFSR
{
public:
    virtual ~LFSR() = 0;

    virtual const bool GetNextValue() noexcept = 0;

protected:
    virtual void CalcualteNextSequence() noexcept = 0;
};