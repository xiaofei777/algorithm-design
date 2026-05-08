#include <stdio.h>
#include <stdlib.h>

void combination(int arr[], int start, int n, int r, int temp[], int index) {
    if (index == r) {
        for (int i = 0; i < r; i++) {
            printf("%d ", temp[i]);
        }
        printf("\n");
        return;
    }
    
    for (int i = start; i <= n - (r - index); i++) {
        temp[index] = arr[i];
        combination(arr, i + 1, n, r, temp, index + 1);
    }
}

void printCombinations(int n, int r) {
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
    
    int *temp = (int *)malloc(r * sizeof(int));
    
    printf("Combinations of %d numbers taken %d at a time:\n", n, r);
    combination(arr, 0, n, r, temp, 0);
    
    free(arr);
    free(temp);
}

int main() {
    int n = 5, r = 3;
    printCombinations(n, r);
    return 0;
}
