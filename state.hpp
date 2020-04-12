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