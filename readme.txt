The program can be compiled with the command:
g++ ./main.cpp -o ./main

The program is then ran as:
./main <initState> <goalState> <mode> <outputFile>

where	<initState> is the path of the initial state file,
	<goalState> is the path of the goal state file,
	<mode> is the algorithm to use (Can be: "BFS", "DFS", "IDDFS", or "A*"),
	<outputFile> is the file to write the output to