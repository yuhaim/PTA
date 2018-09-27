#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_N 100000
#define MAX_CMD 32

int compare(const void *x, const void *y)
{
    return *(int *)x - *(int *)y;
}

int main()
{
    int stack[MAX_N+1];
    int top = 0;
    char cmd[MAX_CMD];
    int stackCopy[MAX_N+1];
    int key;
        
    scanf("%s", cmd);

    while(scanf("%s", cmd)!=EOF) {
        if(!strcmp("Pop", cmd) && top) {
            printf("%d\n", stack[top--]);
        } else if(!strcmp(cmd, "PeekMedian") && top) {
            memcpy(stackCopy, stack, (top+1)*sizeof(int));
            qsort(stackCopy+1, top, sizeof(int), compare);
            printf("%d\n", stackCopy[top%2?(top+1)/2:top/2]);
        } else if(!strcmp(cmd, "Push") && 
                   scanf("%d", &key) == 1 &&
                   top<=MAX_N) {
            stack[++top] = key;
        } else {
            printf("Invalid\n");
        }       
    }
    
    return 0;
}
