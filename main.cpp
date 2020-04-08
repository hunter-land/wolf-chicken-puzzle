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

#include <iostream>
#include <fstream>
#include <string>

struct state{
	int wolvesOnLeft = 0;
	int wolvesOnRight = 0;
	int chickensOnLeft = 0;
	int chickensOnRight = 0;
	int boatsOnLeft = 0;
	int boatsOnRight = 0;

	// std::string toString() {
	// 	return	"" + wolvesOnLeft + "," + chickensOnLeft + "," << boatsOnLeft << std::endl 
	// 			<< wolvesOnRight << "," << chickensOnRight << "," << boatsOnRight << std::endl;
	// }
};

std::ostream& operator<<(std::ostream& outs, const state s) {
	outs << s.wolvesOnLeft << "," << s.chickensOnLeft << "," << s.boatsOnLeft << std::endl
		 << s.wolvesOnRight << "," << s.chickensOnRight << "," << s.boatsOnRight << std::endl;
}

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

	return 0;
}