#include <stdio.h>
#include <limits.h>
#include <string.h>

#define INF INT_MAX
#define N 10

void forward(int cost[][N], int k, int segment[], int n) {
    int dist[N], path[N];
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        path[i] = -1;
    }
    dist[0] = 0;

    for (int i = 0; i < k - 1; i++) {
        int start = segment[i];
        int end = segment[i + 1];
        for (int u = start; u < end; u++) {
            if (dist[u] == INF) continue;
            for (int v = end; v < segment[i + 2]; v++) {
                if (cost[u][v] != INF && dist[v] > dist[u] + cost[u][v]) {
                    dist[v] = dist[u] + cost[u][v];
                    path[v] = u;
                }
            }
        }
    }

    int t = segment[k] - 1;
    printf("向前递推最短长度：%d\n", dist[t]);
    printf("向前递推路径：");
    int cur = t;
    int res[N], cnt = 0;
    while (cur != -1) {
        res[cnt++] = cur;
        cur = path[cur];
    }
    for (int i = cnt - 1; i >= 0; i--)
        printf("%d ", res[i] + 1);
    printf("\n");
}

void backward(int cost[][N], int k, int segment[], int n) {
    int dist[N], path[N];
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        path[i] = -1;
    }
    int t = segment[k] - 1;
    dist[t] = 0;

    for (int i = k - 2; i >= 0; i--) {
        int start = segment[i];
        int end = segment[i + 1];
        for (int u = start; u < end; u++) {
            for (int v = end; v < segment[i + 2]; v++) {
                if (cost[u][v] != INF && dist[v] != INF && dist[u] > dist[v] + cost[u][v]) {
                    dist[u] = dist[v] + cost[u][v];
                    path[u] = v;
                }
            }
        }
    }

    printf("向后递推最短长度：%d\n", dist[0]);
    printf("向后递推路径：");
    int cur = 0;
    while (cur != -1) {
        printf("%d ", cur + 1);
        cur = path[cur];
    }
    printf("\n");
}

int main() {
    int cost[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cost[i][j] = INF;

    cost[0][1] = 4; cost[0][2] = 7;
    cost[1][3] = 8; cost[1][4] = 6; cost[1][5] = 5;
    cost[2][3] = 4; cost[2][4] = 7; cost[2][5] = 6;
    cost[3][6] = 5; cost[3][7] = 4;
    cost[4][6] = 6; cost[4][7] = 7;
    cost[5][6] = 5; cost[5][7] = 4;
    cost[6][8] = 4;
    cost[7][8] = 3;

    int segment[] = {0, 1, 3, 6, 8, 9};
    int k = 5;
    int n = 9;

    printf("=== 多段图动态规划求解 ===\n");
    forward(cost, k, segment, n);
    backward(cost, k, segment, n);

    return 0;
}
