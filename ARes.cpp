#include <cstdlib>
#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class A
{
public:
    A() {}
    A(int x, float y)
    {
        number = x;
        value = y;
    }
    int number;
    float value;
    bool operator > (const A &tmp) const
    {
        return value > tmp.value;
    }
    bool operator < (const A &tmp) const
    {
        return value < tmp.value;
    }
};

class mycompare
{
public:
    bool operator() (A a, A b)
    {
        return a.value > b.value;
    }
};

vector<int> ares( vector<A> vec, uint32_t n )
{
    vector<int> res;
    priority_queue < A, vector<A>, greater<A> > que;
    for (auto v : vec)
    {
        float ui = rand() * 1.f / RAND_MAX;
        float ki = pow(ui, 1 / v.value);
        if (que.size() < n)
        {
            que.emplace(A(v.number, ki));
        }
        else
        {
            auto tmp = que.top();
            if (ki > tmp.value)
            {
                que.emplace(A(v.number, ki));
                if (que.size() >= n)
                {
                    que.pop();
                }
            }
        }
    }
    while (que.empty() == false)
    {
        res.push_back(que.top().number);
        que.pop();
    }
    return res;
}

int main()
{
    int an[5] = {0};
    vector<A> vec;
    srand( (unsigned)time( NULL ) );
    int num[5] = {5, 10, 20, 10, 30};
    int total = 0;
    for (int i = 0; i < 5; ++i)
    {
        total += num[i];
    }
    for (int i = 0; i < 5; ++i)
    {
        vec.emplace_back(A(i, num[i] * 1.f / total));
    }
    for (int i = 0; i < 1000000; ++i)
    {
       vector<int> a = ares(vec, 3);
       for (auto k : a)
       {
           an[k]++;
       }
    }

    for (int i = 0; i < 5; ++i)
    {
        cout << i << ' ' << an[i] << endl;
    }
}
