#include <iostream>
#include <vector>

using namespace std;
struct Node{
    int data;
    int next;
};

struct Node mem_space[100001];

int reverse_list(int start_addr, int K)
{
    int curr_addr, prev_addr;
    prev_addr = -1;
    curr_addr = start_addr;

    int count = 0;
    while(count < K){
        int temp = mem_space[curr_addr].next;
        mem_space[curr_addr].next = prev_addr;
        prev_addr = curr_addr;
        curr_addr = temp;
        count++;
    }

    return prev_addr;
}

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
        len++;
        temp = mem_space[temp].next;
    }

    int prev_tail_addr;

    int curr_addr, prev_addr;
    prev_addr = -1;
    curr_addr = start_addr;
    for(int i=0; i<len; i+=K){
        if(i==K)
            start_addr = prev_addr;

        if(i>=K)
            mem_space[prev_tail_addr].next = curr_addr;

        if(i>len-K)
            break;

        prev_tail_addr = curr_addr;
        int count = 0;
        while(count < K){
            int temp = mem_space[curr_addr].next;
            mem_space[curr_addr].next = prev_addr;
            prev_addr = curr_addr;
            curr_addr = temp;
            count++;
        }
    }

    temp = start_addr;
    while(temp!=-1){
        if(mem_space[temp].next!=-1){
            printf("%05d %d %05d\n", 
                    temp, 
                    mem_space[temp].data, 
                    mem_space[temp].next);
        }else{
            printf("%05d %d %d\n", 
                    temp, 
                    mem_space[temp].data, 
                    mem_space[temp].next);
        }
        temp = mem_space[temp].next;
    }

    return 0;
}

