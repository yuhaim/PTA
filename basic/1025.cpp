#include <iostream>
#include <map>
#include <stack>
#include <cstdio>

using namespace std;

struct Node {
    int Data;
    int Next;
};

int main()
{
    int start, N, K;
    cin>>start>>N>>K;

    map<int, Node> storage;
    for(int i=0; i<N; i++) {
        int Address;
        Node node;
        cin>>Address;
        cin>>node.Data>>node.Next;
        storage[Address] = node;
    }

    int addr = start;
    int count = 0;
    stack<pair<int, int> > s;

    while(true) {
        count++;
        if(addr!=-1){
            s.push(make_pair(addr, storage[addr].Data));
            addr = storage[addr].Next;
        }
        if(count%K==0) {
            if(count>K) printf(" %05d\n", s.top().first);
            printf("%05d %d", s.top().first, s.top().second);
            s.pop();
            while(!s.empty()) {
                auto x = s.top();
                printf(" %05d\n%05d %d", x.first, x.first, x.second);
                s.pop();
            }
        }
        if(addr==-1) break;
    }

    if(!s.empty()) {
        stack<pair<int, int> > r;
        while(!s.empty()) {
            r.push(s.top());
            s.pop();
        }

        while(!r.empty()) {
            auto x = r.top();
            printf(" %05d\n%05d %d", x.first, x.first, x.second);
            r.pop();
        }
    }

    cout<<' '<<-1<<endl;
    return 0;
}
