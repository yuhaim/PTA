#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

struct Node {
    int left;
    int right;
} tree[MAX_SIZE];
int checked[MAX_SIZE];

typedef int ElementType;

struct StQueue {
    ElementType data[MAX_SIZE+1];
    int front;
    int rear;
};

typedef struct StQueue *Queue;

Queue createQueue()
{
    Queue queue;
    queue = (Queue)malloc(sizeof(struct StQueue));
    queue->front = 0;
    queue->rear = 0;
    return queue;
}

void enqueue(Queue queue, ElementType data)
{
    queue->data[(++(queue->rear))%MAX_SIZE] = data;
}

ElementType dequeue(Queue queue)
{
    return queue->data[(++(queue->front))%MAX_SIZE];
} 

int isEmpty(Queue queue)
{
    return queue->front == queue->rear;
}

int main()
{
    int N, i, root, node, flag = 0;
    char leftChar, rightChar;
    Queue queue;
    queue = createQueue();

    scanf("%d\n", &N);

    for(i=0; i<N; i++) {
        scanf("%c %c\n", &leftChar, &rightChar);
        tree[i].left = leftChar=='-' ? -1 : leftChar - '0';
        if(tree[i].left>=0) checked[tree[i].left] = 1;
        tree[i].right = rightChar=='-' ? -1 : rightChar - '0';
        if(tree[i].right>=0) checked[tree[i].right] = 1;
    }

    for(i=0; i<N; i++) {
        if(!checked[i]) break;
    }

    root = i;
    enqueue(queue, root);

    while(!isEmpty(queue)){
        node = dequeue(queue);
        if(tree[node].left<0 && tree[node].right<0) {
            if(!flag) {
                flag = 1;
            } else {
                printf(" ");
            }
            printf("%d", node);
        }
       
        if(tree[node].left>=0)
            enqueue(queue, tree[node].left);
        if(tree[node].right>=0)
            enqueue(queue, tree[node].right);
    }
    
    printf("\n");

    return 0;
}
