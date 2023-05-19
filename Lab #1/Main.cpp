#include <iostream>

#include "Generator/TableGenerator.hpp"
#include "Generator/TableMaker.hpp"
#include "Tests/FrequencyTest.hpp"
#include "Tests/DifferentialTest.hpp"
#include "Tests/RankTest.hpp"


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
    constexpr const std::size_t twoPowBitWidth = pow(2, 10);

    TableMaker<twoPowBitWidth> tableMaker{};    

    TableGenerator<twoPowBitWidth, sampleSize> generator
    {
        std::vector<LFSR*>
        {
            new LFSRCalculator<8>{ 0b10001110, std::vector<std::uint8_t>{ 2, 3, 4 } },              // x^8 + x^4 + x^3 + x^2 + 1
            new LFSRCalculator<9>{ 0b100001000, std::vector<std::uint8_t>{ 4 } },                   // x^9 + x^4 + 1
            new LFSRCalculator<10>{ 0b1000000100, std::vector<std::uint8_t>{ 3 } },                 // x^10 + x^3 + 1
            new LFSRCalculator<11>{ 0b10000000010, std::vector<std::uint8_t>{ 2 } },                // x^11 + x^2 + 1
            new LFSRCalculator<12>{ 0b100000101000, std::vector<std::uint8_t>{ 4, 6 } },            // x^12 + x^6 + x^4 + 1
            new LFSRCalculator<13>{ 0b1000000001101, std::vector<std::uint8_t>{ 1, 3, 4 } },        // x^13 + x^4 + x^3 + x + 1
            new LFSRCalculator<14>{ 0b1001000100001, std::vector<std::uint8_t>{ 1, 6, 10 } },       // x^14 + x^10 + x^6 + x + 1
            new LFSRCalculator<15>{ 0b10000000000001, std::vector<std::uint8_t>{ 1 } },             // x^15 + x + 1  
            new LFSRCalculator<16>{ 0b1001000000000101, std::vector<std::uint8_t>{ 1, 3, 13 } },    // x^16 + x^13 + x^3 + x + 1
            new LFSRCalculator<17>{ 0b10000000000000100, std::vector<std::uint8_t>{ 3 } },          // x^17 + x^3 + 1      
        },
        tableMaker.MakeTable()
    };

    generator.Generate();

    const auto& generatedSequence = generator.GetGeneratedSequence();

    FrequencyTest<sampleSize> frequencyTest{ generatedSequence };
    std::cout << "Frequency test value: " << frequencyTest.GetRelation() << '\n'; 

    DifferentialTest<sampleSize> differentialTest{ generatedSequence };
    std::cout << "Differential test value: " << frequencyTest.GetRelation() << '\n'; 

    RankTest<sampleSize> rankTest{ generatedSequence };
    std::cout << "The rank test value: " << std::boolalpha << rankTest.CheckRankMatch(5, 10);

    std::cout << std::endl;
    
    return EXIT_SUCCESS;
}