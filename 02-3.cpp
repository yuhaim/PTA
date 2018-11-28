#include <iostream>
#include <vector>

using namespace std;
struct Node{
    int data;
    int next;
};

struct Node mem_space[100001];
int link_list[100001];
int result_list[100001];

int main()
{
    int start_addr, N, K;
    cin >> start_addr >> N >> K;

    for(int i=0; i<N; i++){
        int addr, data, next;
        cin >> addr >> data >> next;
        struct Node node;
        node.data = data;
        node.next = next;
        mem_space[addr] = node;
    }

    int len = 0;
    int temp = start_addr;
    while(temp!=-1){
        link_list[len++] = temp;
        temp = mem_space[temp].next;
    }

    for(int i=0; i<len; i++){
        result_list[i] = link_list[i];
    }

    for(int i=0; i<len-len%K; i++){
        result_list[i] = link_list[i/K*K + K-1 - i%K];
    }

    for(int i=0; i<len-1; i++){
        printf("%05d %d %05d\n",
                result_list[i],
                mem_space[result_list[i]].data,
                result_list[i+1]);
    }

    printf("%05d %d -1\n",
            result_list[len-1],
            mem_space[result_list[len-1]].data);

    return 0;
}

