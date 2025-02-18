#include "coding.h"
#include <iostream>
using std::cout;

unsigned char encode(unsigned char c)
{
    return c+1;
}
unsigned char decode(unsigned char c)
{
    return c-1;
}
