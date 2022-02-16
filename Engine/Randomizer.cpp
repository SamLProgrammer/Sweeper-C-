#include "Randomizer.h"

int Randomizer::getRandomInt(int a, int b)
{
	std::random_device rd;
	std::mt19937 rng( rd() );
	std::uniform_int_distribution<int> dist(a, b);
	return dist(rng);
}
