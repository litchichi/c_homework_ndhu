#include<stdio.h>

void checkNewStep(int chess[8][8], int next[8][8], int x, int y);

int chess[8][8] = { {0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0},
                 {0,0,0,1,2,0,0,0},
                 {0,0,0,2,1,0,0,0},
                 {0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0}
};

void checkNewStepByColor(int chess[8][8], int next[8][8], int color)
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (chess[i][j] == color) {
                checkNewStep(chess, next, i, j);
            }
        }
    }
}

void checkNewStep(int chess[8][8], int next[8][8], int x, int y) {
    int directions[8][2] = {{-1, -1},{-1, 0},{-1, 1},{0, -1},{0, 1},{1, -1},{1, 0},{1, 1}};

    for (int k = 0; k < 8; k++) {
        int dx = directions[k][0];
        int dy = directions[k][1];
        int step = newStep(chess, x, y, dx, dy);
        if (step > 0) {
            int i = x + step * dx;
            int j = y + step * dy;
            next[i][j] = step;
        }
    }
}

int newStep(int chess[8][8], int x, int y, int dx, int dy)
{
    int i = x + dx;
    int j = y + dy;
    int step = 1;

    while (i >= 0 && i < 8 && j >= 0 && j < 8) {
        if (chess[i][j] == 0) {
            return step;
        }
        i += dx;
        j += dy;
        step++;
    }

    return 0;
}

int main() {
    int chess[8][8],color=1,next[8][8]={0},x,y;

    while (1) {
        printf("黑子可下位置:\n");
        checkNewStepByColor(chess, next, 2);
        scanf("%d %d", &x, &y);
        checkNewStep(chess, next, x, y);
        printf("白子可下位置:\n");
        checkNewStepByColor(chess, next, 1);
        printf("黑子可下位置:\n");
        checkNewStepByColor(chess, next, 2);

        int count = 0, blackCount = 0,whiteCount = 0;
        for (int x = 0; x < 9; x++) {
            for (int y = 0; y < 9; y++) {
                if (chess[x][y] == 1) {
                    whiteCount++;
                    count++;
                }
                else if (chess[x][y] == 1) {
                    blackCount++;
                    count++;
                }
                else;
            }
        }
        if (count == 64) {
            if (whiteCount > blackCount)
                printf("白棋獲勝!\n");
            else if (whiteCount < blackCount)
                printf("黑棋獲勝!\n");
            else
                printf("平手!\n");
            break;
        }
            
    }
	return 0;
}
