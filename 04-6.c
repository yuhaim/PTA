#include <stdio.h>
#define MAX_SIZE 1000
#define MAX_VALUE 2000

int tree[MAX_SIZE+1];
int size;
int queue[MAX_SIZE+1];
int front, rear;

void insert(int x)
{
    
}

void enqueue(int x)
{
    queue[(++rear)%(MAX_SIZE+1)] = x;
}

int dequeue()
{
    return queue[(++front)%(MAX_SIZE+1)];
}

int main()
{
    int N, i;
    int x;
    scanf("%d", &N);

    while(N--) {
        scanf("%d", &x);
        insert(x);
    }

    i=1;
    printf("%d", tree[i++]);
    while(i<=N) {
        printf(" %d", tree[i++]);
    }

    printf("\n");
    return 0;
}

     6
   3   8
  1 5 7 9
0 2 4
