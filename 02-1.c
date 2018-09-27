#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    Print(L1);
    Print(L2);
    L = Merge(L1, L2);

    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

List Read()
{
    int size, data;
    List L, node, temp;
    L = (List)malloc(sizeof(struct Node));
    L->Data = 0;
    L->Next = NULL;
    temp = L;

    scanf("%d", &size);
    while(size) {
        scanf("%d", &data);
        node = (List)malloc(sizeof(struct Node));
        node->Data = data;
        temp->Next = node;
        temp = temp->Next;
        size--;
    }
    return L;
}

void Print(List L)
{
    if(!(L&&L->Next)) { 
        printf("NULL\n");
        return;
    }
    L = L->Next;

    while(L) { 
        printf("%d ", L->Data);
        L = L->Next;
    }    
    printf("\n");
}

/* 你的代码将被嵌在这里 */
List Merge(List L1, List L2)
{
    List L, current, preL1, preL2;
    preL1 = L1;
    preL2 = L2;

    L = (List)malloc(sizeof(struct Node));
    L->Next = NULL;
    if(L1 && L2 && L1->Next && L2->Next) {
    } else {
        return L;
    }

    current = L;
    L1 = L1->Next;
    L2 = L2->Next;

    while(L1 && L2) {
        if(L1->Data <= L2->Data) {
            current->Next = L1;
            L1 = L1->Next;
        } else {
            current->Next = L2;
            L2 = L2->Next;
        }

        current = current->Next;
    }

    current->Next = L1 ? L1 : L2;
    preL1->Next = NULL;
    preL2->Next = NULL;
    return L;
}
