#pragma once
#include <cmath>

namespace Utils
{
	static bool x_or(bool a, bool b)
	{
		return a != b;
	}

	static long long toLongLong(bool values[32])
	{
		long long calculated = 0;
		for (int i = 31; i > 0; i--)
		{
			if (values[i])
			{
				calculated += pow(2, 31 - i);
			}
		}
		return calculated;
	}
};