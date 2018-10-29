#include "startup.h"
#include <iostream>
#include <string>
#include <vector>

string startup::order_play(string a, string b) {
	
	std::random_device rd;     // only used once to initialise (seed) engine
	std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
	std::uniform_int_distribution<int> uni(1, 2); // guaranteed unbiased

	auto random_integer = uni(rng);

	if (random_integer == 1) {
		return a + " is first, " + b" is second";
	}

	else
		return b + " is first, " + a" is second";

}

string startup::order_play(string A, string B, string C) {
	
	string[3] array;

	array[0] = A;
	array[1] = B;
	array[2] = C;

	std::random_device rd;     // only used once to initialise (seed) engine
	std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
	std::uniform_int_distribution<int> uni(1, 3); // guaranteed unbiased

	
	auto random_integer = uni(rng);

	string[3] newArray;

	newArray[0] = array[random_integer];

	auto random2 = uni(rng);
	while (random2 == random_integer) {
		random2 = uni(rng);
	}

	newArray[1] = array[random2];

	auto random3 = uni(rng);
	while (random3 == random2 || random3 == random_integer) {
		random3 = uni(rng);
	}

	newArray[2] = array[random3];

	return newArray[0]+" is first, "+ newArray[1]+" is second, "+ newArray[2]+" is third."


	
	

	
	


}
