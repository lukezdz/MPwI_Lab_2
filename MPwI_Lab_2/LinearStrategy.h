#pragma once
#include "GenerationStrategy.h"

class LinearStrategy : public GenerationStrategy
{
public:
	LinearStrategy();
	LinearStrategy(int seed);
	long long next() override;
private:
	static constexpr int a = 69069;
	static constexpr long long m = 4294967295;
	static constexpr int c = 1;
	static constexpr int initialValue = 7;

	long long previous;
};