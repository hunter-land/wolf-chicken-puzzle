#include "./state.hpp"
#include "./stateGenerator.cpp"
#include <vector>

std::vector<state> BFS(state initialState, state goalState) {
	std::vector<stateNode*> previousStates = {};
	std::vector<stateNode> allNodes = {{initialState, nullptr}};
	std::vector<stateNode*> fronteir = {&allNodes[0]};

	stateNode* goalNode = nullptr;

	while(fronteir.size() > 0 && goalNode == nullptr) {
		stateNode* thisNode = fronteir[0];
		fronteir.erase(fronteir.begin());

		if(thisNode->thisState == goalState) {
			goalNode = thisNode;
			break;
		}

		std::vector<state> possibleNextStates = generateNextStates(thisNode->thisState); //Get all states we may go to
		//Exclude already visited states
		for(int i = 0; i < possibleNextStates.size(); i++) {
			bool alreadyIncluded = false;
			for(int j = 0; j < allNodes.size(); j++) {
				if(allNodes[j].thisState == possibleNextStates[i]) {
					alreadyIncluded = true;
					break;
				}
			}
			if(!alreadyIncluded) {
				//std::cout << "Adding state" << std::endl << possibleNextStates[i] << std::endl;
				allNodes.push_back({possibleNextStates[i], thisNode});
				fronteir.push_back(&allNodes[allNodes.size()-1]);
			}
		}
	}
	
	//We have path, build it back into vector
	std::vector<state> resultingPath;
	if(goalNode != nullptr) {
		for(stateNode* currentState = goalNode; currentState->prevNode != nullptr; currentState = currentState->prevNode) {
			resultingPath.insert(resultingPath.begin(), currentState->thisState);
			//std::cout << currentState << std::endl;
		}
		resultingPath.insert(resultingPath.begin(), initialState);
	} else {
		std::cout << "No solution from state:" << std::endl << initialState << std::endl;
	}
	return resultingPath;
}