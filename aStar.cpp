#include "./state.hpp"
#include "./stateGenerator.cpp"
#include <vector>
#include <algorithm> //std::find

stateNode* bestNodeOption(std::vector<stateNode*> options, state goal);

answer aStar(state initialState, state goalState) {
	int counter = 0;
	answer solution;
	stateNode* initialNode = new stateNode;
	initialNode->thisState = initialState;
	initialNode->prevNode = nullptr;
	initialNode->previousStateCount = 0;
	std::vector<stateNode*> allNodes = {initialNode};
	std::vector<stateNode*> frontier = {initialNode};

	stateNode* goalNode = nullptr;

	while(frontier.size() > 0 && goalNode == nullptr) {
		stateNode* nodeToExpand = bestNodeOption(frontier, goalState);
		frontier.erase(std::find(frontier.begin(), frontier.end(), nodeToExpand));

		if(nodeToExpand->thisState == goalState) {
			goalNode = nodeToExpand;
			solution.count = counter;
			break;
		}
		counter++;
		std::vector<state> nextStates = generateNextStates(nodeToExpand->thisState);
		for(state s : nextStates) {
			stateNode* nextNode = new stateNode;
			nextNode->previousStateCount = nodeToExpand->previousStateCount + 1;
			nextNode->prevNode = nodeToExpand;
			nextNode->thisState = s;
			allNodes.push_back(nextNode);
			frontier.push_back(nextNode);
		}
	}

	//We have path, build it back into vector
	std::vector<state> resultingPath;
	if(goalNode != nullptr) {
		//Add every state
		for(stateNode* currentState = goalNode; currentState->prevNode != nullptr; currentState = currentState->prevNode) {
			resultingPath.insert(resultingPath.begin(), currentState->thisState);
			//std::cout << currentState << std::endl;
		}
		//Don't forget the initialState
		resultingPath.insert(resultingPath.begin(), initialState);
	} else {
		//std::cout << "No solution from state:" << std::endl << initialState << std::endl;
	}

	//Now lets clean up memory we used
	for (stateNode* sn : allNodes) {
		delete sn;
	}

	//Finally, send back the path we found
	solution.path = resultingPath;
	return solution;
}

stateNode* bestNodeOption(std::vector<stateNode*> options, state goal) {
	stateNode* best = nullptr;
	int bestHeur = __INT_MAX__;
	for(stateNode* s : options) {
		int thisHeur = s->previousStateCount + s->thisState.getHeuristic(goal);
		if(thisHeur < bestHeur) {
			bestHeur = thisHeur;
			best = s;
		}
	}
	return best;
}