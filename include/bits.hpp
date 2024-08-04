/**
 * @brief Set up the header for the Manipulation of bits
 *        provided a value and an index
 *
 * @file bits.hpp
 * @author Yohan John
 */

#ifndef BIT_MANIPULATION
#define BIT_MANIPULATION

#include <iostream>
#include <vector>
#include <mutex>

/**
 * @brief brief description
 *
 */
class bitManipulation
{
private:
    /** Input Bitset */
    std::vector<uint8_t> bitset;
    /** Size of the bitset */
    size_t size_bitset;
    /** Mutex Lock to ensure thread safety */
    std::mutex mutex;

    /**
     * @brief Calculate the number of bytes required
     *         to store the input
     * @param input Bitset data
     * @return Size required to store the data
     */
    size_t input_size(size_t input) const
    {
        // +7 to help with the rounding for non multiples of 8
        return (input + 7) / 8;
    }

public:
    /**
     * @brief Construct a new bit Manipulation object
     *
     * @param numBits
     */
    bitManipulation(size_t numBits) : size_bitset(numBits)
    {
        size_t numBytes = input_size(numBits);

        // Now that we know the size initalise all bits to 0
        bitset.resize(numBytes, 0);
    }

    /**
     * @brief Sets the bit at the specified index to 1
     * @param index index position to set the bit at
     */
    void setBit(size_t index);

    /**
     * @brief clears the bit at the specified index
     * @param index index position to clear the bit at
     */
    void clearBit(size_t index);

    /**
     * @brief Returns the value of the bit at the specified index
     * @param index index position to check the bit value
     * @return the bit value at the index
     */
    bool getBit(size_t index);
};

#endif // BIT_MANIPULATION
