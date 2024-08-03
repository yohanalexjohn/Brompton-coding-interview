/**
* @brief 
* @file
* 
* @author Yohan John 
*/

#ifndef BIT_MANIPULATION
#define BIT_MANIPULATION

#include <mutex>

/**
* @brief brief description
*
*/
class bitManipulation{
    private:

    public:

        /**
        * @brief Sets the bit at the specified index to 1
        * @param in  -name description
        *
        */
        void setBit(size_t index);

        /**
        * @brief clears the bit at the specified index
        * @param in  -name description
        *
        */
        void clearBit(size_t index);

        /**
        * @brief Returns the value of the bit at the specified index
        * @param in index -name description
        * @return -name description
        *
        */
        bool getBit(size_t index);

};

#endif // BIT_MANIPULATION
