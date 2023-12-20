#include <stdio.h>

#define MAX_N 10

int start_x = 1, start_y = 0;
int exit_x = 6, exit_y = 9;
int maze[MAX_N][MAX_N] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 1, 1, 0, 1, 1, 0, 1},
    {1, 0, 1, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 1, 0, 1, 0, 1},
    {1, 1, 1, 0, 1, 1, 0, 1, 1, 1},
    {1, 0, 1, 1, 1, 0, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 1, 1, 0, 0},
    {1, 0, 1, 1, 1, 1, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1, 1}, //if[8][4]=1, NO PATH !
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

typedef struct {
    int x, y;
} Point;

Point stack[MAX_N * MAX_N];
int top = -1;

int valid(int x, int y) {
    return x >= 0 && x < MAX_N&& y >= 0 && y < MAX_N&& maze[x][y] == 0;
}

void push(int x, int y) {
    top++;
    stack[top].x = x;
    stack[top].y = y;
}

void pop() {
    top--;
}

int findPath(int x, int y) {
    maze[x][y] = 2;
    push(x, y);
    if (x == exit_x && y == exit_y) {
        return 1;
    }
    int directions[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
    for (int i = 0; i < 4; i++) {
        int newX = x + directions[i][0];
        int newY = y + directions[i][1];

        if (valid(newX, newY) && findPath(newX, newY)) {
            return 1;
        }
    }
    pop();
    return 0;
}

void printPath() {
    for (int i = 0; i <= top; i++) {
        int x = stack[i].x;
        int y = stack[i].y;
        maze[x][y] = 'x';
    }
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++) {
            if (maze[i][j] == 1) {
                printf("1 ");
            }
            else if (maze[i][j] == 'x') {
                printf("x ");
            }
            else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main() {
    if (findPath(start_x, start_y)) {
        printPath();
    }
    else {
        printf("No Path\n");
    }
    return 0;
}
