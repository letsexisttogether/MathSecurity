#include <iostream>

#include "Generator/TableGenerator.hpp"


/*  Lab #1
    Variant: #20
    Table(p: 10)
    Regs: 8+
    Sample: 15000
    Comp: Linear
*/



int32_t main()
{
    constexpr const std::size_t sampleSize = 15000;

    TableGenerator<10, sampleSize> generator
    {
        std::vector<LFSR*>
        {

        },
        std::bitset<sampleSize>
        {
            
        }
    };

    generator.Generate();

    const auto& generatedSequence = generator.GetGeneratedSequence();
    
    return EXIT_SUCCESS;
}