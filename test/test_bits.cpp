#include <gtest/gtest.h>

#include "bits.hpp"


// TEST CLASS CREATION 

/**
 * @brief Create the setup for the test class to 
 *        share the bitManipulation test obejct 
 *        across the test fixtures 
 */
class bitManipulationTest : public testing::Test 
{
    protected:
        // Initialize bitTestObject directly in the 
        // constructor initializer list
        bitManipulationTest() : bitTestObject(400) {}

        // Helper function to verify if the bit is set 
        bool isBitSet(size_t index)
        {
            return bitTestObject.getBit(index);
        }

        // Helper function to verify if the bit is cleared 
        bool isBitCleared(size_t index)
        {
            // Using ! as if the bit is cleared will return 0
            // Which is what we want in this case to validate 
            // that the function is working and vice-versa 
            return !(bitTestObject.getBit(index));
        }

        // Share this test object 
        bitManipulation bitTestObject;
};

// TESTS

/**
 * @brief Unit test the setbit method
 * 
 */
TEST_F(bitManipulationTest, SetBit)
{
    bitTestObject.setBit(100);

    EXPECT_TRUE(isBitSet(100));
    // To ensure that the other bits are unaffected
    // by setting the bit at a paticular index 
    EXPECT_TRUE(isBitCleared(101));
}


/**
 * @brief Unit test the clearBit method
 * 
 */
TEST_F(bitManipulationTest, clearBit)
{
    bitTestObject.setBit(100);
    bitTestObject.clearBit(100);

    EXPECT_TRUE(isBitCleared(100));
}

/**
 * @brief Unit test the getBit method
 * 
 */
TEST_F(bitManipulationTest, getBit)
{
    bitTestObject.setBit(100);

    EXPECT_TRUE(isBitSet(100));
    EXPECT_TRUE(isBitCleared(101));
}

