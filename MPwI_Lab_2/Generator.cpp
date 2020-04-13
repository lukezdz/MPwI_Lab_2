#include "Generator.h"

Generator::Generator(GenerationStrategy& strategy)
	:strategy(strategy)
{
}

long long Generator::next()
{
	return strategy.next();
}

std::vector<long long> Generator::generate(int amount)
{
	std::vector<long long> generated;
	for (int i = 0; i < amount; i++)
	{
		generated.push_back(strategy.next());
	}

	return generated;
}
