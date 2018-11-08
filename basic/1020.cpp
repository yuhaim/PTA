#include <iostream>
#include <set>
#include <vector>
#include <cstdio>

using namespace std;

struct Pie{
    double weight;
    double total;
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

    vector<double> weight(N), total(N);
    multiset<Pie, Rule> storage;
    
    for(int i=0; i<N; i++) {
        double x;
        cin>>x;
        weight[i] = x;
    }

    for(int i=0; i<N; i++) {
        double x;
        cin>>x;
        total[i] = x;
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
