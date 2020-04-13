#pragma once
#include "GenerationStrategy.h"
#include "Utils.h"

class RegisterStrategy : public GenerationStrategy
{
public:
	RegisterStrategy();
	RegisterStrategy(int seed);
	long long next() override;
private:
	void performIteration();
	void moveBitHead();
	void clearBitTail();
	void resetBitRepresentation();

	static constexpr int p = 7;
	static constexpr int q = 3;
	static constexpr bool initialBitValues[7] = { true, false, true, true, true, false, true };

	bool bitRepresentation[32];
};