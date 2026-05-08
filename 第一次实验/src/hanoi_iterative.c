#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int n;
    char from;
    char to;
    char aux;
    int step;
} StackFrame;

void iterativeHanoi(int n, char from, char to, char aux) {
    StackFrame *stack = (StackFrame *)malloc(n * 100 * sizeof(StackFrame));
    int top = -1;
    
    stack[++top] = (StackFrame){n, from, to, aux, 0};
    
    while (top >= 0) {
        StackFrame frame = stack[top--];
        
        if (frame.step == 0) {
            if (frame.n == 1) {
                printf("Move disk 1 from %c to %c\n", frame.from, frame.to);
            } else {
                stack[++top] = (StackFrame){frame.n, frame.from, frame.to, frame.aux, 1};
                stack[++top] = (StackFrame){frame.n - 1, frame.from, frame.aux, frame.to, 0};
            }
        } else if (frame.step == 1) {
            printf("Move disk %d from %c to %c\n", frame.n, frame.from, frame.to);
            stack[++top] = (StackFrame){frame.n, frame.from, frame.to, frame.aux, 2};
            stack[++top] = (StackFrame){frame.n - 1, frame.aux, frame.to, frame.from, 0};
        }
    }
    free(stack);
}

int main() {
    int n = 4;
    printf("Iterative Hanoi Tower with %d disks:\n", n);
    iterativeHanoi(n, 'A', 'C', 'B');
    return 0;
}
