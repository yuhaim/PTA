#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct student{
    int id;
    int d;
    int c;
};

bool compare(student x, student y)
{
    if((x.d+x.c) == (y.d+y.c) && x.d != y.d)
        return x.d > y.d;
    else if((x.d+x.c) == (y.d+y.c) && x.d == y.d)
        return x.id < y.id;
    else
        return (x.d+x.c) > (y.d+y.c);
}

int main()
{
    int N, L, H;
    cin>>N>>L>>H;

    vector<student> d_and_c;
    vector<student> d_gr_c;
    vector<student> nd_gr_nc;
    vector<student> others;

    while(N--) {
        student x;
        //cin>>x.id>>x.d>>x.c;
        scanf("%d %d %d", &x.id, &x.d, &x.c);

        if(x.d>=L && x.c>=L) {
            if(x.d>=H && x.c>=H)
                d_and_c.push_back(x);
            else if(x.d>=H && x.c<H)
                d_gr_c.push_back(x);
            else if(x.d<H && x.c<H && x.d>=x.c)
                nd_gr_nc.push_back(x);
            else
                others.push_back(x);
        }
    }

    sort(d_and_c.begin(), d_and_c.end(), compare);
    sort(d_gr_c.begin(), d_gr_c.end(), compare);
    sort(nd_gr_nc.begin(), nd_gr_nc.end(), compare);
    sort(others.begin(), others.end(), compare);

    cout << d_and_c.size() + 
            d_gr_c.size() +
            nd_gr_nc.size() + 
            others.size()
         << endl;

    for(auto x : d_and_c) {
        //cout<<x.id<<' '<<x.d<<' '<<x.c<<endl;
        printf("%d %d %d\n", x.id, x.d, x.c);
    }

    for(auto x : d_gr_c) {
        //cout<<x.id<<' '<<x.d<<' '<<x.c<<endl;
        printf("%d %d %d\n", x.id, x.d, x.c);
    }

    for(auto x : nd_gr_nc) {
        //cout<<x.id<<' '<<x.d<<' '<<x.c<<endl;
        printf("%d %d %d\n", x.id, x.d, x.c);
    }

    for(auto x : others) {
        //cout<<x.id<<' '<<x.d<<' '<<x.c<<endl;
        printf("%d %d %d\n", x.id, x.d, x.c);
    }

    return 0;
}

