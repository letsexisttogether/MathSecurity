#pragma once

class LFSR
{
public:
    virtual ~LFSR() = 0;

    virtual bool GetNextValue() noexcept = 0;
};

LFSR::~LFSR() = default;