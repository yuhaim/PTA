#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void PreorderTraversal( BinTree BT ); /* 先序遍历，由裁判实现，细节不表 */
void InorderTraversal( BinTree BT );  /* 中序遍历，由裁判实现，细节不表 */

BinTree Insert( BinTree BST, ElementType X );
BinTree Delete( BinTree BST, ElementType X );
Position Find( BinTree BST, ElementType X );
Position FindMin( BinTree BST );
Position FindMax( BinTree BST );

int main()
{
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;

    BST = NULL;
    scanf("%d", &N);
    for ( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
    printf("Preorder:"); PreorderTraversal(BST); printf("\n");
    MinP = FindMin(BST);
    MaxP = FindMax(BST);
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        Tmp = Find(BST, X);
        if (Tmp == NULL) printf("%d is not found\n", X);
        else {
            printf("%d is found\n", Tmp->Data);
            if (Tmp==MinP) printf("%d is the smallest key\n", Tmp->Data);
            if (Tmp==MaxP) printf("%d is the largest key\n", Tmp->Data);
        }
    }
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Delete(BST, X);
    }
    printf("Inorder:"); InorderTraversal(BST); printf("\n");

    return 0;
}
/* 你的代码将被嵌在这里 */
void PreorderTraversal( BinTree BT )
{
    if(BT) {
        printf("%d ", BT->Data);
        PreorderTraversal(BT->Left); 
        PreorderTraversal(BT->Right); 
    }
} 

void InorderTraversal( BinTree BT )
{
    if(BT) {
        InorderTraversal(BT->Left); 
        printf("%d ", BT->Data);
        InorderTraversal(BT->Right); 
    }
} 

BinTree Insert( BinTree BST, ElementType X )
{
    if(!BST) {
        BST = (Position)malloc(sizeof(struct TNode));
        BST->Data = X;
        BST->Left = NULL;
        BST->Right = NULL; 
    } else {
        if(X>BST->Data) {
            BST->Right = Insert(BST->Right, X);
        } else if (X<BST->Data) {
            BST->Left = Insert(BST->Left, X);
        }
    }

    return BST;
}

BinTree Delete( BinTree BST, ElementType X )
{
    Position temp;
    if(!BST) {
        printf("Not Found\n");
    } else {
        if(X>BST->Data) {
            BST->Right = Delete(BST->Right, X);
        } else if(X<BST->Data) {
            BST->Left = Delete(BST->Left, X);
        } else {
            if(!BST->Left || !BST->Right) {
                temp = BST->Left ? BST->Left : BST->Right;   
                free(BST);
                return temp; 
            } else {
                temp = FindMin(BST->Right);
                BST->Data = temp->Data;
                Delete(BST->Right, temp->Data);
            }
        }
    }
    return BST;
}

Position Find( BinTree BST, ElementType X )
{
    if(BST) {
        if(X>BST->Data) {
            BST = Find(BST->Right, X);
        } else if (X<BST->Data) {
            BST = Find(BST->Left, X);
        } else {
            return BST;
        }
    }
    return BST;
}

Position FindMin( BinTree BST )
{
    while(BST && BST->Left) {
        BST = BST->Left;
    }
    return BST;
}

Position FindMax( BinTree BST )
{
    while(BST && BST->Right) {
        BST = BST->Right;
    }
    return BST;
}

