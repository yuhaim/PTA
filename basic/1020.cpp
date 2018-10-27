#include <iostream>
#include <set>
#include <vector>
#include <cstdio>

using namespace std;

struct Pie{
    int weight;
    int total;
};

struct Rule {
    bool operator()(const Pie &pie_x, const Pie &pie_y)
    {
        return (double)pie_x.total/pie_x.weight > (double)pie_y.total/pie_y.weight;
    }
};

int main()
{
    int N, D;
    cin>>N>>D;

    vector<int> weight, total;
    multiset<Pie, Rule> storage;
    
    for(int i=0; i<N; i++) {
        int x;
        cin>>x;
        weight.push_back(x);
    }

    for(int i=0; i<N; i++) {
        int x;
        cin>>x;
        total.push_back(x);
    }

    for(int i=0; i<N; i++) {
        Pie x;
        x.weight = weight[i];
        x.total = total[i];
        storage.insert(x);
    }

    double profit = 0.0;
    for(auto x : storage) {
        if(x.weight <= D) {
            D -= x.weight;
            profit += x.total;
        } else {
            profit += (double)D*x.total/x.weight;
            break;
        }
    }

    printf("%.2f\n", profit);
    return 0;
}
