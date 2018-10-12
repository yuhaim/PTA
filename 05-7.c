#include <stdio.h>
#define MAX_SIZE 1000
#define MAX_VALUE 10000

int heap[MAX_SIZE+1] = {-MAX_VALUE,};
int size = 0;

void insert(int x)
{
    int i;
    i=++size;
    while(x<heap[i/2]) {
        heap[i] = heap[i/2];
        i=i/2;
    }

    heap[i] = x;
}

void printRoute(int index)
{
    int flag = 0;
    while(index){
        if(!flag) 
            flag = 1;
        else 
            printf(" ");
        printf("%d", heap[index]);
        index /= 2;
    }
    printf("\n");
}

int main()
{
    int M, N;
    int x;

    scanf("%d%d", &N, &M);

    while(N--) {
        scanf("%d", &x);
        insert(x);
    }

    while(M--) {
        scanf("%d", &x);
        printRoute(x);
    }
    return 0;
}
