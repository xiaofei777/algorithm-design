#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20
#define INF 999999

int maze[MAX_SIZE][MAX_SIZE];
int bestPath[MAX_SIZE][MAX_SIZE];
int minLen = INF;
int rows, cols;
int startX, startY, endX, endY;

int directions[4][2] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};

void copyBestPath() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (maze[i][j] > 0) {
                bestPath[i][j] = maze[i][j];
            } else {
                bestPath[i][j] = 0;
            }
        }
    }
}

void printMaze(int path[MAX_SIZE][MAX_SIZE]) {
    printf("\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (path[i][j] == -1) {
                printf("  # ");
            } else if (path[i][j] == -2) {
                printf("  X ");
            } else if (path[i][j] == 0) {
                printf("  . ");
            } else {
                printf(" %2d ", path[i][j]);
            }
        }
        printf("\n");
    }
}

int backtrack(int x, int y, int dep) {
    if (x == endX && y == endY) {
        maze[x][y] = dep;
        if (dep < minLen) {
            minLen = dep;
            copyBestPath();
        }
        maze[x][y] = 0;
        return 1;
    }

    maze[x][y] = dep;

    int found = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + directions[i][0];
        int ny = y + directions[i][1];

        if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && maze[nx][ny] == 0) {
            if (backtrack(nx, ny, dep + 1)) {
                found = 1;
            }
        }
    }

    if (!found) {
        maze[x][y] = -2;
    } else {
        maze[x][y] = 0;
    }

    return found;
}

int main() {
    printf("请输入迷宫的行数和列数: ");
    scanf("%d %d", &rows, &cols);

    printf("请输入迷宫 (-1表示墙, 0表示通路):\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &maze[i][j]);
        }
    }

    printf("请输入起点坐标 (行 列): ");
    scanf("%d %d", &startX, &startY);
    printf("请输入终点坐标 (行 列): ");
    scanf("%d %d", &endX, &endY);

    printf("\n初始迷宫:");
    printMaze(maze);

    int tempMaze[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            tempMaze[i][j] = maze[i][j];
        }
    }

    backtrack(startX, startY, 1);

    if (minLen == INF) {
        printf("\n没有找到从起点到终点的路径!\n");
    } else {
        printf("\n最短路径长度为: %d\n", minLen);
        printf("\n最短路径标记 (数字表示步数):");
        printMaze(bestPath);

        printf("\n路径节点坐标 (按步数顺序):\n");
        for (int step = 1; step <= minLen; step++) {
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (bestPath[i][j] == step) {
                        printf("(%d, %d) ", i, j);
                    }
                }
            }
        }
        printf("\n");

        printf("\n搜索后的迷宫状态 (-2表示死胡同):");
        printMaze(maze);
    }

    return 0;
}
