/**
 * @brief Defintions and logical setup for the mainpulation
 *        of bits at the provided location for the given value
 *
 * @file bits.cpp
 * @author Yohan John
 */

#include "bits.hpp"

void bitManipulation::setBit(size_t index)
{
    std::lock_guard<std::mutex> lock(mutex);
    if (index >= size_bitset)
    {
        throw std::out_of_range("Index is out of range for the given bitset input");
    }

    // Vector is stored as 8 bytes
    size_t byteIndex = index / 8;

    // Find the bit index to jump
    size_t bitIndex = index % 8;

    // Set the bit at the index for the given value
    bitset[byteIndex] |= (0x01 << bitIndex);
}

void bitManipulation::clearBit(size_t index)
{
    std::lock_guard<std::mutex> lock(mutex);
    if (index >= size_bitset)
    {
        throw std::out_of_range("Index is out of range for the given bitset input");
    }

    // Vector is stored as 8 bytes
    size_t byteIndex = index / 8;

    // Find the bit index to jump
    size_t bitIndex = index % 8;

    // Clear the bit at the index for the given value
    bitset[byteIndex] &= ~(0x01 << bitIndex);
}

bool bitManipulation::getBit(size_t index)
{
    std::lock_guard<std::mutex> lock(mutex);
    if (index >= size_bitset)
    {
        throw std::out_of_range("Index is out of range for the given bitset input");
    }

    // Vector is stored as 8 bytes
    size_t byteIndex = index / 8;

    // Find the bit index to jump
    size_t bitIndex = index % 8;

    // Return the value of the bit at the given index
    return bitset[byteIndex] & (0x01 << bitIndex);
}
