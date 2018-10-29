#include "startup.h"
#include <iostream>
#include <string>
#include <vector>
#include "Player.h"

using namespace std;
//------------------------------------------------------------------------------------------------------
string startup::order_play(string a, string b) {
	
	std::random_device rd;     // only used once to initialise (seed) engine
	std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
	std::uniform_int_distribution<int> uni(1, 2); // guaranteed unbiased

	auto random_integer = uni(rng);

	if (random_integer == 1) {
		return a + " is first, " + b + " is second";
	}

	else
		return b + " is first, " + a +" is second";

}
//------------------------------------------------------------------------------------------------------
string startup::order_play(string A, string B, string C) {
	
	string array [3];
	string newArray[3];

	array[0] = A;
	array[1] = B;
	array[2] = C;

	std::random_device rd;     // only used once to initialise (seed) engine
	std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
	std::uniform_int_distribution<int> uni(0, 2); // guaranteed unbiased

	
	auto random_integer = uni(rng);

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

	return newArray[0] + " is first, " + newArray[1] + " is second, " + newArray[2] + " is third.";
}
//-----------------------------------------------------------------------------------------------------------
string startup::order_play(string a, string b, string c, string d) {
	string array[4] = { a,b,c,d };
	string newArray[4];

	std::random_device rd;     // only used once to initialise (seed) engine
	std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
	std::uniform_int_distribution<int> uni(0, 3); // guaranteed unbiased

	auto random_integer = uni(rng);

    newArray[0] = array[random_integer];

	auto random2 = uni(rng);
	while (random2 == random_integer) {
		random2 = uni(rng);
	}

	newArray[1] = array[random2];

	auto random3 = uni(rng);
	while (random3 == random_integer || random3 == random2) {
		random3 = uni(rng);
	}

	newArray[2] = array[random3];

	auto random4 = uni(rng);
	while (random4 == random_integer || random4 == random2 || random4 == random3) {
		random4 = uni(rng);
	}

	newArray[3] = array[random4];

	return newArray[0] + " is first, " + newArray[1] + " is second, " + newArray[2] + " is third and " + newArray[3] + " is fourth";

	
}
//---------------------------------------------------------------------------------------------------------------------------------
string startup::order_play(string a, string b, string c, string d, string e) {
	string array[5] = { a,b,c,d,e };
	string newArray[5];

	std::random_device rd;     // only used once to initialise (seed) engine
	std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
	std::uniform_int_distribution<int> uni(0, 4); // guaranteed unbiased

	auto random_integer = uni(rng);

    newArray[0] = array[random_integer];

	auto random2 = uni(rng);
	while (random2 == random_integer) {
		random2 = uni(rng);
	}

	newArray[1] = array[random2];

	auto random3 = uni(rng);
	while (random3 == random_integer || random3 == random2) {
		random3 = uni(rng);
	}

	newArray[2] = array[random3];

	auto random4 = uni(rng);
	while (random4 == random_integer || random4 == random2 || random4 == random3) {
		random4 = uni(rng);
	}

	newArray[3] = array[random4];

	auto random5 = uni(rng);
	while (random5 == random_integer || random5 == random2 || random5 == random3 || random5 == random4) {
		random5 = uni(rng);
	}

	newArray[4] = array[random5];

	return newArray[0] + " is first, " + newArray[1] + " is second, " + newArray[2] + " is third " + newArray[3] +
		" is fourth and " + newArray[4] + " is fifth";


}
//--------------------------------------------------------------------------------------------------------------------
string startup::order_play(string a, string b, string c, string d, string e, string f) {
	string array[6] = { a,b,c,d,e,f };
	string newArray[6];

	std::random_device rd;     // only used once to initialise (seed) engine
	std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
	std::uniform_int_distribution<int> uni(0, 5); // guaranteed unbiased

	auto random_integer = uni(rng);

    newArray[0] = array[random_integer];

	auto random2 = uni(rng);
	while (random2 == random_integer) {
		random2 = uni(rng);
	}

	newArray[1] = array[random2];

	auto random3 = uni(rng);
	while (random3 == random_integer || random3 == random2) {
		random3 = uni(rng);
	}

	newArray[2] = array[random3];

	auto random4 = uni(rng);
	while (random4 == random_integer || random4 == random2 || random4 == random3) {
		random4 = uni(rng);
	}

	newArray[3] = array[random4];

	auto random5 = uni(rng);
	while (random5 == random_integer || random5 == random2 || random5 == random3 || random5 == random4) {
		random5 = uni(rng);
	}

	newArray[4] = array[random5];

	auto random6 = uni(rng);
	while (random6 == random_integer || random6 == random2 || random6 == random3 || random6 == random4 || random6 == random5) {
		random6 = uni(rng);
	}

	newArray[5] = array[random6];

	return newArray[0] + " is first, " + newArray[1] + " is second, " + newArray[2] + " is third " + newArray[3] +
		" is fourth " + newArray[4] + " is fifth and "+ newArray[5]+" is sixth";
}


