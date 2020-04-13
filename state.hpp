#pragma once

struct state{
	int wolvesOnLeft = 0;
	int wolvesOnRight = 0;
	int chickensOnLeft = 0;
	int chickensOnRight = 0;
	bool boatIsOnLeft = false;
	//int boatsOnLeft = 0;
	//int boatsOnRight = 0;

	// std::string toString() {
	// 	return	"" + wolvesOnLeft + "," + chickensOnLeft + "," << boatsOnLeft << std::endl 
	// 			<< wolvesOnRight << "," << chickensOnRight << "," << boatsOnRight << std::endl;
	// }
};
struct stateNode {
	state thisState;
	stateNode* prevNode;
};

bool operator==(const state a, const state b) {
	return	a.wolvesOnLeft == b.wolvesOnLeft && a.wolvesOnRight == b.wolvesOnRight &&
			a.chickensOnLeft == b.chickensOnLeft && a.chickensOnRight == b.chickensOnRight &&
			a.boatIsOnLeft == b.boatIsOnLeft;
}

std::ostream& operator<<(std::ostream& outs, const state s) {
	outs << s.wolvesOnLeft << "," << s.chickensOnLeft << "," << s.boatIsOnLeft << std::endl
		 << s.wolvesOnRight << "," << s.chickensOnRight << "," << !s.boatIsOnLeft;
}