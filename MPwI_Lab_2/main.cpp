#include <vector>
#include <iostream>
#include "Generator.h"
#include "GenerationStrategy.h"
#include "LinearStrategy.h"
#include "RegisterStrategy.h"

void menu()
{
	std::cout << std::endl;
	std::cout << "What would you like to do?" << std::endl;
	std::cout << "1. Generate single value with linear generator" << std::endl;
	std::cout << "2. Generate multiple values with linear generator" << std::endl;
	std::cout << "3. Generate single value with register generator" << std::endl;
	std::cout << "4. Genrate multiple values with register generator" << std::endl;
	std::cout << "5. Reset generators with new seeds" << std::endl;
	std::cout << "6. Quit" << std::endl;
}

void prompt()
{
	std::cout << "> ";
}

void displayGeneratedVector(std::vector<long long> generated)
{
	for (long long value : generated)
	{
		std::cout << value << std::endl;
	}
}

int main()
{
	static constexpr int quitChoice = 6;

	Generator* linearGenerator = nullptr;
	Generator* registerGenerator = nullptr;

	LinearStrategy linearStrategy;
	RegisterStrategy registerStrategy;

	char ans;
	int seed;

	std::cout << "DISCLAIMER:" << std::endl;
	std::cout << "  You don't have to create generators with seed, but you can." << std::endl;
	std::cout << "  In case you choose not to give a seed, generators will be created with default seed." << std::endl;
	std::cout << std::endl;

	std::cout << "Would you like to create linear generator with seed? (y/n)" << std::endl;
	prompt();
	std::cin >> ans;
	if (ans == 'y')
	{
		std::cout << "Please enter seed" << std::endl;
		prompt();
		std::cin >> seed;
		linearStrategy = LinearStrategy(seed);
	}

	std::cout << "Would you like to create register generator with seed? (y/n)" << std::endl;
	prompt();
	std::cin >> ans;
	if (ans == 'y')
	{
		std::cout << "Please enter seed" << std::endl;
		prompt();
		std::cin >> seed;
		registerStrategy = RegisterStrategy(seed);
	}
	
	linearGenerator = new Generator(linearStrategy);
	registerGenerator = new Generator(registerStrategy);

	int userChoice = 0;
	while (userChoice != quitChoice)
	{
		menu();
		prompt();
		std::cin >> userChoice;

		switch (userChoice)
		{
		case 1:
		{
			std::cout << linearGenerator->next() << std::endl;
			break;
		}
		case 2:
		{
			int amount = 1;
			std::cout << "How many values would you like to generate?" << std::endl;
			prompt();
			std::cin >> amount;
			displayGeneratedVector(linearGenerator->generate(amount));
			break;
		}
		case 3:
		{
			std::cout << registerGenerator->next() << std::endl;
			break;
		}
		case 4:
		{
			int amount = 1;
			std::cout << "How many values would you like to generate?" << std::endl;
			prompt();
			std::cin >> amount;
			displayGeneratedVector(registerGenerator->generate(amount));
			break;
		}
		case 5:
		{
			int seed;
			std::cout << "Please enter new seed for linear generator" << std::endl;
			prompt();
			std::cin >> seed;

			linearStrategy = LinearStrategy(seed);
			linearGenerator = new Generator(linearStrategy);

			std::cout << "Please enter new seed for register generator" << std::endl;
			prompt();
			std::cin >> seed;

			registerStrategy = RegisterStrategy(seed);
			registerGenerator = new Generator(registerStrategy);
			break;
		}
		default:
		{
			break;
		}
		}
	}

	return 0;
}