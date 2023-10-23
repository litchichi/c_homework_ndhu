#include<stdio.h>
#define SIZE 8

int chess[SIZE][SIZE] = {
	{0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 1, 2, 0, 0, 0},
	{0, 0, 0, 2, 1, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0}
};

int Move(x, y, color) {
    int direction[8][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };

    for (int a = 0; a < 8; a++) {
        int dx = direction[a][0];
        int dy = direction[a][1];
        int X = x + dx;
        int Y = y + dy;

		if (X > 0 && X <= SIZE && Y > 0 || Y <= SIZE) {
			if (chess[X][Y] != color && chess[X][Y] != 0) {
			   while (X >= 0 && X < SIZE && Y >= 0 && Y < SIZE) {
					if (chess[X][Y] == 0) {
						break;
					}
					if (chess[X][Y] == color) {
						return 1;
					}
					X += dx;
					Y += dy;
				}
			}			
		}
		return 0;
    }
}

int main() {
	int color=1, i,j;
	printf("先下黑棋，要下的位置: \n");
	scanf_s("%d%d", &i, &j);
	if (chess[i][j] == 0) {
		printf("(%d,%d)沒有棋子", i, j);
		if (Move(i, j, color)) {
			printf("且可以下\n");
		}
		else {
			printf("但不能下\n");
		}

	}
	else if(chess[i][j] == 1) {
		printf("(%d,%d)已有黑棋不能下棋\n", i, j);
	}
	else
		printf("(%d,%d)已有白棋不能下棋\n",i,j);

	return 0;
}