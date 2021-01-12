#include<bits/stdc++.h>
using namespace std;

bool ratInAMaze(char maze[4][4], int sr, int sc, int er, int ec) {
	if (sr == er and sc == ec) {
		return true;
	}

	if (sr > er or sc > ec or maze[sr][sc] == 'X') {
		return false;
	}

	bool right = ratInAMaze(maze, sr + 1, sc, er, ec);
	bool down = ratInAMaze(maze, sr, sc + 1, er, ec);

	return right or down;
}

bool printRatInaMaze(char maze[4][4], int sol[4][4], int sr, int sc, int er, int ec) {
	if (sr == er and sc == ec) {

		sol[sr][sc] = 1;

		for (int i = 0; i <= er; i++) {
			for (int j = 0; j <= ec; j++) {
				cout << sol[i][j] << " ";
			}
			cout << endl;
		}
		cout << "***************" << endl;

		return true;
	}

	if (sr > er or sc > ec or maze[sr][sc] == 'X' ) {
		return false;
	}


	sol[sr][sc] = 1;

	bool down = printRatInaMaze(maze, sol, sr + 1, sc, er, ec);
	if(down == true) return true;
	
	bool right = printRatInaMaze(maze, sol, sr, sc + 1, er, ec);
	if(right == true) return true;
	
	sol[sr][sc] = 0;
	return false;
}

int main()
{
    char maze[][4] = {
	 	{'0', '0', '0', '0'},
	 	{'0', 'X', 'X', 'X'},
	 	{'0', '0', '0', '0'},
	 	{'0', 'X', 'X', '0'},
	 };

	  cout << ratInAMaze(maze, 0, 0, 3, 3) << endl;
 
 
    int sol[4][4] = {0};
    printRatInaMaze(maze, sol, 0, 0, 3, 3);
 return 0;
}

