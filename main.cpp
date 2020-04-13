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

int main(int argc, char *argv[]) {
	
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
	state initState, goalState;
	std::ifstream initFileStream(initStateFile);

	std::vector<state> solution;
	std::ofstream outFileStream(outputFile);
	if(modeString == "BFS") {
		solution = BFS(initState, goalState);
	}
	for (state s : solution) {
		outFileStream << s << std::endl << std::endl;
	}

	return 0;
}