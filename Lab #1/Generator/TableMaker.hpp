#pragma once

#include <bitset>
#include <random>
#include <algorithm>
#include <stdexcept>

template<const std::size_t _SampleSize>
class TableMaker
{
public:
    std::bitset<_SampleSize> MakeTable() const noexcept(false)
    {
        if (_SampleSize % 2)
        {
            throw std::length_error{ "Unable to make equal amout of 0 and 1" };
        }

        std::vector<bool> temp{};        
        for (std::size_t i = 0; i < _SampleSize / 2; i += 2)
        {
            temp.push_back(0);
            temp.push_back(1);
        }

        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(temp.begin(), temp.end(), g);

        std::bitset<_SampleSize> set{};

        for (std::size_t i = 0; i < _SampleSize; ++i)
        {
            set[i] = temp[i];
        }

        return set;
    }
};