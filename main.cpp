#include "sortings.h"
#include "vectors_utilities.h"

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdint>
#include <ctime>

int main()
{
    // Initialize seed for randomness
    std::srand( static_cast<uint32_t>(std::time(nullptr)) );

    // Construct vector of random values
    std::vector<int> test(1000);
    for ( auto& it : test ) { it = std::rand(); }

    std::vector<int> cpy1(test), cpy2(test);
    std::sort(std::begin(cpy1), std::end(cpy1));
    SORTINGS::bubbleSort_m(cpy2);

    std::cout << ( ( cpy1 != cpy2 ) ? "FAIL" : "SUCCESS" ) << std::endl;
    std::cout << SORTINGS::toString(test.begin(), test.begin() + 10) << std::endl;
    SORTINGS::quickSort_m( test );
    std::cout << SORTINGS::toString(test.begin(), test.begin() + 10) << std::endl;

    return 0;
}
