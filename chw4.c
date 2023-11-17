#include<stdio.h>

void checkNewStepByColor(int next[8][8], int color);
void checkNewStep(int next[8][8], int x, int y, int color);
int newStep(int x, int y, int dx, int dy, int color);

int chess[8][8] = {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 2, 0, 0, 0},
    {0, 0, 0, 2, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}
};

int main() {
    int chess[8][8],next[8][8],color,x,y;
  
    printf("白子可下位置:\n");
    checkNewStepByColor( next, 2);
    printf("黑子可下位置:\n");
    checkNewStepByColor( next, 1);

	return 0;
}

void checkNewStepByColor(int next[8][8], int color)
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            next[i][j] = 0;
        }
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
                checkNewStep(next, i, j, color);
        }
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (next[i][j] > 0) {
                printf("(%d,%d) ", i, j);
            }
        }
    }
    printf("\n");
}

void checkNewStep(int next[8][8], int x, int y, int color) {
    int directions[8][2] = { {-1, -1},{-1, 0},{-1, 1},{0, -1},{0, 1},{1, -1},{1, 0},{1, 1} };
    for (int k = 0; k < 8; k++) {
        int dx = directions[k][0];
        int dy = directions[k][1];
        int n = newStep( x, y, dx, dy,color);
        if (n > 0) {
            next[x][y] = 1;
        }
    }
}

int newStep(int x, int y, int dx, int dy, int color)
{
    int X = x + dx;
    int Y = y + dy;
    int n = 1;

    if (X >= 0 && X < 8 && Y >= 0 && Y < 8) {
        if (chess[X][Y] != color && chess[X][Y] != 0) {
            while (X >= 0 && X < 8 && Y >= 0 && Y < 8) {
                if (chess[X][Y] == 0) {
                    break;
                }
                else if (chess[X][Y] == color) {
                    return n;
                }
                X += dx;
                Y += dy;
                n++;
            }
        }
    }
    return 0;
}
