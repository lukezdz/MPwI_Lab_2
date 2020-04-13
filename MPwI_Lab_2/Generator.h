#pragma once
#include <vector>
#include "GenerationStrategy.h"

class Generator
{
public:
	Generator(GenerationStrategy& strategy);
	long long next();
	std::vector<long long> generate(int amount);
private:
	GenerationStrategy& strategy;
};