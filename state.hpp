#pragma once

//A struct to hold the values of a state
struct state{
	int wolvesOnLeft = 0;
	int wolvesOnRight = 0;
	int chickensOnLeft = 0;
	int chickensOnRight = 0;
	bool boatIsOnLeft = false;
	
	//Gets the closeness to goal state g
	//Smaller number means closer, with 0 being equal states
	int getHeuristic(const state &g) {
		return std::abs(wolvesOnLeft - g.wolvesOnLeft)
			 + std::abs(wolvesOnRight - g.wolvesOnRight)
			 + std::abs(chickensOnLeft - g.chickensOnLeft)
			 + std::abs(chickensOnRight - g.chickensOnRight)
			 + std::abs(boatIsOnLeft - g.boatIsOnLeft);
	}
};
//A struct to add a back pointer and a 'numberOfPreviousStates' value
//Used for state navigation
struct stateNode {
	state thisState;
	stateNode* prevNode = nullptr;
	int previousStateCount = 0;
};

//State comparitor
bool operator==(const state a, const state b) {
	return	a.wolvesOnLeft == b.wolvesOnLeft && a.wolvesOnRight == b.wolvesOnRight &&
			a.chickensOnLeft == b.chickensOnLeft && a.chickensOnRight == b.chickensOnRight &&
			a.boatIsOnLeft == b.boatIsOnLeft;
}

//For printing a state
std::ostream& operator<<(std::ostream& outs, const state s) {
	outs << s.wolvesOnLeft << "," << s.chickensOnLeft << "," << s.boatIsOnLeft << std::endl
		 << s.wolvesOnRight << "," << s.chickensOnRight << "," << !s.boatIsOnLeft;
}
//For reading a state
std::istream& operator>>(std::istream& ins, state& s) {
	std::string valStr;
	
	std::getline(ins, valStr, ',');
	s.wolvesOnLeft = std::stoi(valStr);
	std::getline(ins, valStr, ',');
	s.chickensOnLeft = std::stoi(valStr);
	std::getline(ins, valStr); //No ',' argument because the end here is noted by '\n' instead
	s.boatIsOnLeft = std::stoi(valStr);
	std::getline(ins, valStr, ',');
	s.wolvesOnRight = std::stoi(valStr);
	std::getline(ins, valStr, ',');
	s.chickensOnRight = std::stoi(valStr);
	std::getline(ins, valStr);
	//s.wolvesOnLeft = std::stoi(valStr); //This value is known from the boat value above

	// std::cout << "Created new state from istream:" << std::endl;
	// std::cout << s << std::endl;

	return ins;
}