#include "swap.h"

void swap(Country& a, Country& b) {
    Country temp = a;
    a = b;
    b = temp;
}
