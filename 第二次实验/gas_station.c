#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STATIONS 1000

int main(int argc, char *argv[]) {
    int n, k;
    int distances[MAX_STATIONS];
    int refuel_stations[MAX_STATIONS];
    int refuel_count = 0;
    int current_fuel;
    int i;
    char filename[100] = "input.txt";

    if (argc > 1) {
        strcpy(filename, argv[1]);
    }

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("无法打开 %s 文件！\n", filename);
        return 1;
    }

    fscanf(fp, "%d %d", &n, &k);
    for (i = 0; i <= k; i++) {
        fscanf(fp, "%d", &distances[i]);
    }
    fclose(fp);

    for (i = 0; i <= k; i++) {
        if (distances[i] > n) {
            printf("No Solution\n");
            return 0;
        }
    }

    current_fuel = n;
    for (i = 0; i < k; i++) {
        current_fuel -= distances[i];
        if (current_fuel < distances[i + 1]) {
            refuel_stations[refuel_count++] = i + 1;
            current_fuel = n;
        }
    }

    printf("petrol: %d", refuel_count);
    if (refuel_count > 0) {
        printf(" at ");
        for (i = 0; i < refuel_count; i++) {
            if (i > 0) {
                printf(", ");
            }
            printf("%d", refuel_stations[i]);
        }
        printf(" petrol station");
    }
    printf("\n");

    return 0;
}
