#include "./state.hpp"
#include "./stateGenerator.cpp"
#include <vector>

using std::cout;
using std::endl;


answer DLS(state initialState, state goalState, int limit) {
	int counter = 0;
	answer solution;
	stateNode* initialNode = new stateNode; //Creating a stateNode element from initial state
	initialNode->thisState = initialState;
	initialNode->prevNode = nullptr;
	std::vector<stateNode*> allNodes = { initialNode }; //All nodes in our graph
	std::vector<stateNode*> fronteir = { initialNode }; //All frontier nodes in the graph
	
	stateNode* goalNode = nullptr;

	while (fronteir.size() > 0 && goalNode == nullptr && limit != -1) {
		//cout << "iterations left: " << limit << endl;
		limit--;
		stateNode* thisNode = fronteir[fronteir.size() - 1];
		fronteir.erase(fronteir.end() - 1);

		//Check if this is the state we are aiming for
		if (thisNode->thisState == goalState) {
			//This is the goal, set it and move on to the next step
			goalNode = thisNode;
			solution.count = counter;
			break;
		}

		counter++;

		std::vector<state> possibleNextStates = generateNextStates(thisNode->thisState); //Get all states we may go to
		//Exclude already visited states
		for (int i = 0; i < possibleNextStates.size(); i++) {
			bool alreadyIncluded = false;
			//Check for state in node list
			for (int j = 0; j < allNodes.size(); j++) {
				if (allNodes[j]->thisState == possibleNextStates[i]) {
					//State is in another node, adding it would be redundant/a step backwards
					alreadyIncluded = true;
					break;
				}
			}
			//Do not add redundant/backstepping states, but add all others
			if (!alreadyIncluded) {
				stateNode* newNode = new stateNode;
				newNode->thisState = possibleNextStates[i];
				newNode->prevNode = thisNode;
				allNodes.push_back(newNode);
				fronteir.push_back(newNode);
			}
		}
	}

	//We have path, build it back into vector
	std::vector<state> resultingPath;
	if (goalNode != nullptr) {
		//Add every state
		for (stateNode* currentState = goalNode; currentState->prevNode != nullptr; currentState = currentState->prevNode) {
			resultingPath.insert(resultingPath.begin(), currentState->thisState);
			//std::cout << currentState << std::endl;
		}
		//Don't forget the initialState
		resultingPath.insert(resultingPath.begin(), initialState);
	}
	else {
		//std::cout << "No solution from state:" << std::endl << initialState << std::endl;
	}

	//Now lets clean up memory we used
	for (stateNode* sn : allNodes) {
		delete sn;
	}

	//Finally, send back the path we found, and the number of nodes expanded
	solution.count = counter;
	solution.path = resultingPath;
	return solution;
}


answer IDDFS(state initialState, state goalState, int MAX)
{
	answer solution, subSolution;
	std::vector<state> foundPath;
	for (int i = 0; i <= MAX; i++)
	{
		//cout << "limit: " << i << endl;
		subSolution = DLS(initialState, goalState, i);
		solution.count += subSolution.count; //Nodes expanded over ALL iterations
		if (subSolution.path.size() > 0)
		{
			solution.path = subSolution.path;
			break;
		}
	}
	return solution;
}