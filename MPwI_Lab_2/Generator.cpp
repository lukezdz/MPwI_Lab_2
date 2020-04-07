#include "Generator.h"

Generator::Generator(Strategy strategy)
	:strategy(strategy)
{
}

void Generator::generate()
{
	strategy.generate();
}
