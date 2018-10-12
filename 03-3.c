#include <stdio.h>
#define MAX_SIZE 30

typedef int ElementType;
struct StStack {
    ElementType data[MAX_SIZE];
    int top;
} stack;

ElementType pop()
{
    return stack.data[stack.top--];
}

void push(ElementType data)
{
    stack.data[++stack.top] = data;
}

int main()
{
    int N, i;
    
    scanf("%d", &N);

    return 0;
}
