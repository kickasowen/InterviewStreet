/* Enter your code here. Read input from STDIN. Print output to STDOUT */
#include <iostream>
#include <vector>

using namespace std;

typedef vector<pair<int,int> > myvec;
typedef vector<pair<int,int> >::iterator myiter;

struct Query {
    char q;
    int a;
    int b;
};

inline void reflectX(const Query &q, myvec &p)
{
    myiter it = p.begin() + (q.a-1);
    myiter end = p.begin() + q.b;
    for (; it != end; ++it) {
        it->second = - it->second;
    }
}

inline void reflectY(const Query &q, myvec &p)
{
    myiter it = p.begin() + (q.a-1);
    myiter end = p.begin() + q.b;
    for (; it != end; ++it) {
        it->first = - it->first;
    }
}

inline void count(const Query &q, myvec &p)
{
    myiter it = p.begin() + (q.a-1);
    myiter end = p.begin() + q.b;
    int cnt[4] = {0,0,0,0};
    for (; it != end; ++it) {
        if (it->first > 0)
            if (it->second > 0)
                ++cnt[0];
            else
                ++cnt[3];
        else
            if (it->second > 0)
                ++cnt[1];
            else
                ++cnt[2];
    }
    cout << cnt[0] << " "
        << cnt[1] << " "
        << cnt[2] << " "
        << cnt[3] << endl;
}

int main()
{
    int N, Q;
    myvec p;
    
    cin >> N;
    p.resize(N);
    for (int i = 0; i < N; ++i)
        cin >> p[i].first >> p[i].second;
    
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        Query q;
        cin >> q.q >> q.a >> q.b;
        if (q.q == 'X')
            reflectX(q, p);
        else if (q.q == 'Y')
            reflectY(q, p);
        else
            count(q, p);
    }
       
    return 0;
}