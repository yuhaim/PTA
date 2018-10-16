#include <stdio.h>
#include <stdlib.h>

int stack[100000];
int top = -1;

int compare(const void *a, const void *b)
{
    return *(int *)a - *(int*)b;
}

int main()
{
    int N, i, base;
    int x;
    scanf("%d", &N);

    for(i=0; i<N; i++) {
        scanf("%d", &x);
        if(x>0) {
            stack[++top] = x;
        }
    }

    qsort(stack, top, sizeof(int), compare);

    for(i=1; i<top; i++)
    {
        if(stack[i-1] == stack[i]) {
            stack[i-1] = 0;
        }
    }

    qsort(stack, top, sizeof(int), compare);

    base=0;
    while(!stack[base]) {
        base++;
    }

    for(i=base; i<=top; i++) {
        if(stack[i]>i+1-base) {
            printf("%d\n", i+1-base);
            return 0;
        }
    }

    printf("%d\n", i-base);
    return 0;
}

