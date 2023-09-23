#include "swap.h"

/**
 * Swap function that swaps two array values at certain indexes
 * Utilized by bubble and selection sort
 * @param a Country object a
 * @param b Country object b
**/
void swap(Country& a, Country& b) {
    Country temp = a;
    a = b;
    b = temp;
}
