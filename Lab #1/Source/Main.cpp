#include <iostream>
#include <vector>
#include <bitset>


/*  Lab #1
    Variant: #20
    Table(p: 10)
    Regs: 8+
    Sample: 15000
    Comp: Linear
*/

template <std::uint8_t _BitWise>
class LFSR
{
public: 
    LFSR(const std::bitset<_BitWise>&& startValue, const std::vector<std::uint8_t>&& xorIndexes)
        : m_Data{ startValue }, m_XorIndexes{ xorIndexes };
    {}

public:
    

private:
    std::bitset<_BitWise> m_CurrentData;
    std::vector<std::uint8_t> m_XorIndexes{};
};

int32_t main()
{
    
    return EXIT_SUCCESS;
}