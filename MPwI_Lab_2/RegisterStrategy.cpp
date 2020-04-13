#include "RegisterStrategy.h"

using Utils::x_or;
using Utils::toLongLong;

RegisterStrategy::RegisterStrategy()
{
	clearBitTail();
	for (int i = 0; i < 7; i++)
	{
		bitRepresentation[i] = initialBitValues[i];
	}
}

RegisterStrategy::RegisterStrategy(int seed)
{
	clearBitTail();
	for (int i = 0; i < 7; i++)
	{
		bitRepresentation[i] = seed % 2;
		seed /= 2;
	}
}

long long RegisterStrategy::next()
{
	for (int i = 0; i < 999; i++)
	{
		performIteration();
	}
	
	return toLongLong(bitRepresentation);
}

void RegisterStrategy::performIteration()
{
	for (int i = 7; i < 31; i++)
	{
		bitRepresentation[i] = x_or(bitRepresentation[i - p], bitRepresentation[i - q]);
	}
	resetBitRepresentation();
}

void RegisterStrategy::moveBitHead()
{
	int offset = 24;
	for (int i = 0; i < 7; i++)
	{
		bitRepresentation[i] = bitRepresentation[i + offset];
	}
}

void RegisterStrategy::clearBitTail()
{
	for (int i = 8; i < 31; i++)
	{
		bitRepresentation[i] = false;
	}
}

void RegisterStrategy::resetBitRepresentation()
{
	moveBitHead();
	clearBitTail();
}
