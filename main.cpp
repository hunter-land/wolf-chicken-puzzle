/**
 * Solves the problem of getting a number of chickens and wolves across a river with a boat.
 * The boat can only hold two animals and must hold at least one animal to move.
 * If any side has more wolves than chickens, the chickens are eaten by the wolves and the problem is failed.
 * 
 * 
 * 
 * Aaron Koffel
 * Hunter Land
 */

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

#include "./state.hpp"
#include "./stateGenerator.cpp"
#include "./BFS.cpp"
#include "./aStar.cpp"
#include "./DFS.cpp"
#include "./IDDFS.cpp"

#define MAX 25

int main(int argc, char *argv[]) {
	
	answer solution;

	if(argc != 5) {
		std::cerr << "This program requires 4 arguments:" << std::endl;
		std::cerr << "\t<Initial State File>" << std::endl;
		std::cerr << "\t<Goal State File>" << std::endl;
		std::cerr << "\t<Mode>" << std::endl;
		std::cerr << "\t<Output File>" << std::endl;
		return 1;
	}

	std::string initStateFile(argv[1]);
	std::string goalStateFile(argv[2]);
	std::string modeString(argv[3]);
	std::string outputFile(argv[4]);


	//Do code
	//Setup initState and goalState from given file arguments
	state initState, goalState;
	std::ifstream initFileStream(initStateFile);
	initFileStream >> initState;
	std::ifstream goalFileStream(goalStateFile);
	goalFileStream >> goalState;

	//Setup to solve the problem
	//std::vector<state> solution;

	
	if(modeString == "BFS") {
		solution = BFS(initState, goalState);
	} else if (modeString == "DFS") {
		solution = DFS(initState, goalState);
	} else if (modeString == "IDDFS") {
		solution = IDDFS(initState, goalState, MAX);
	} else if (modeString == "A*" || modeString == "ASTAR") {
		solution = aStar(initState, goalState);
	} else {
		std::cerr << "Invalid mode argument: \"" << modeString << "\", exiting..." << std::endl;
	}

	//Write solution to file and console
	std::ofstream outFileStream(outputFile);
	for (state s : solution.path) {
		std::cout << s << std::endl << std::endl;
		outFileStream << s << std::endl << std::endl;
	}
	std::cout << "Number of nodes expanded: " << solution.count << std::endl;

	return 0;
}