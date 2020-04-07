#pragma once
#include "GenerationStrategy.h"

class Generator
{
public:
	Generator(GenerationStrategy strategy);
	void generate();

private:
	GenerationStrategy strategy;
};