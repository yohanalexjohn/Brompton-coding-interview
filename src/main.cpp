/*!
 * @brief Main application and call setup
 *
 * @file main.cpp
 * @author Yohan John
 */

#include "bits.hpp"

int main()
{
    bitManipulation bitset(69763453453);

    bitset.setBit(350);

    std::cout << "the bit at index position is " << bitset.getBit(350) << std::endl;
    bitset.clearBit(350);
    std::cout << "the bit at index position is " << bitset.getBit(350) << std::endl;

    return 0;
}
