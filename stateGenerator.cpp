#pragma once

#include "./state.hpp"
#include <vector>

//Generate and return all states which can be reach from given state
std::vector<state> generateNextStates(state from) {
	//Rules:
	//Boat can hold two animals
	//W > C is a failure
	state possibleState = from;
	std::vector<state> possible;
	if(from.boatIsOnLeft) {
		//std::cout << "Moving boat L->R" << std::endl;
		possibleState.boatIsOnLeft = false; //Boat will cross the river, what will it bring?
		//Possibile:
		for(unsigned int w = 0; w <= 2 && w <= from.wolvesOnLeft; w++) {
			for(unsigned int c = 0; c <= 2 && c <= from.chickensOnLeft; c++) {
				if(	w+c <= 2 && w+c > 0 //1-2 animals must cross
				 && (from.chickensOnLeft-c >= from.wolvesOnLeft-w || from.chickensOnLeft-c == 0) //Left wolves will not kill chickens
				 && (from.chickensOnRight+c >= from.wolvesOnRight+w || from.chickensOnRight+c == 0)) { //Right wolves will not kill chickens
					possibleState.chickensOnLeft = from.chickensOnLeft - c;
					possibleState.chickensOnRight = from.chickensOnRight + c;
					possibleState.wolvesOnLeft= from.wolvesOnLeft - w;
					possibleState.wolvesOnRight = from.wolvesOnRight + w;
					possible.push_back(possibleState);
					//std::cout << "Moving " << w << " wolves and " << c << " chicken" << std::endl;
				}
			}
		}
	} else {
		//std::cout << "Moving boat L<-R" << std::endl;
		possibleState.boatIsOnLeft = true; //Boat will cross the river, what will it bring?
		//Possibile:
		for(unsigned int w = 0; w <= 2 && w <= from.wolvesOnRight; w++) {
			for(unsigned int c = 0; c <= 2 && c <= from.chickensOnRight; c++) {
				if(	w+c <= 2 && w+c > 0 //1-2 animals must cross
				 && (from.chickensOnLeft+c >= from.wolvesOnLeft+w || from.chickensOnLeft+c == 0) //Left wolves will not kill chickens
				 && (from.chickensOnRight-c >= from.wolvesOnRight-w || from.chickensOnRight-c == 0)) { //Right wolves will not kill chickens
					possibleState.chickensOnLeft = from.chickensOnLeft + c;
					possibleState.chickensOnRight = from.chickensOnRight - c;
					possibleState.wolvesOnLeft= from.wolvesOnLeft + w;
					possibleState.wolvesOnRight = from.wolvesOnRight - w;
					possible.push_back(possibleState);
					//std::cout << "Moving " << w << " wolves and " << c << " chickens" << std::endl;
				}
			}
		}
	}
	return possible;
}