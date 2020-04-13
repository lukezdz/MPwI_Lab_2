#include "LinearStrategy.h"
#include <iostream>

LinearStrategy::LinearStrategy()
{
	previous = initialValue;
}

LinearStrategy::LinearStrategy(int seed)
{
	previous = seed;
}

long long LinearStrategy::next()
{
	long long generated = (a * previous + c) % m;
	previous = generated;
	return generated;
}
