#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void checkNewStepByColor(int chess[8][8], int next[8][8], int color);
void checkNewStep(int chess[8][8], int next[8][8], int x, int y, int color);
int newStep(int chess[8][8], int x, int y, int dx, int dy, int color);

int chess[8][8] = { {0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0},
                 {0,0,0,2,1,0,0,0},
                 {0,0,0,1,2,0,0,0},
                 {0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0}
};

int main() {
    int chess[8][8], next[8][8], color, x, y;


    printf("黑子可下位置:\n");
    checkNewStepByColor(chess, next, 1);

    scanf("%d %d", &x, &y);
    /*checkNewStep(chess, next, x, y);
    printf("白子可下位置:\n");
    checkNewStepByColor(chess, next, 2);
    printf("黑子可下位置:\n");
    checkNewStepByColor(chess, next, 1);*/

    return 0;
}

void checkNewStepByColor(int chess[8][8], int next[8][8], int color)
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            next[i][j] = 0;
        }
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (chess[i][j] == color) {
                checkNewStep(chess, next, i, j, color);
            }
        }
    }
}

void checkNewStep(int chess[8][8], int next[8][8], int x, int y, int color) {
    int directions[8][2] = { {-1, -1},{-1, 0},{-1, 1},{0, -1},{0, 1},{1, -1},{1, 0},{1, 1} };
    printf("test\n");
    for (int k = 0; k < 8; k++) {
        int dx = directions[k][0];
        int dy = directions[k][1];
        int step = newStep(chess, x, y, dx, dy, color);
        if (step > 0) {
            int i = x + step * dx;
            int j = y + step * dy;
            next[i][j] = step;
            printf("(%d,%d) ", i, j);
        }
    }
}

int newStep(int chess[8][8], int x, int y, int dx, int dy, int color)
{
    int X = x + dx;
    int Y = y + dy;
    int n = 1;
    return n;

    /*while (X >= 0 && X < 8 && Y >= 0 && Y < 8) {
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

    return 0;*/
}