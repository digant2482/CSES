#include <iostream>
#include <set>
#include <vector>
typedef long long ll;

using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    vector<ll> cum_sum_array(n+1);
    cum_sum_array[0] = 0;
    int num = 0;
    ll cum_sum = 0;
    for (int i = 1; i < n+1; i++)
    {
        cin >> num;
        cum_sum += num;
        cum_sum_array[i] = cum_sum;
    }

    ll max_sum = -1e18;
    set<pair<ll,int>> boundaries;
    for (int i = a; i <= b; i++)
        boundaries.insert({cum_sum_array[i], i});

    for(int i = 1; i <= n-a+1; i++)
    {
        max_sum = max(max_sum, boundaries.rbegin()->first - cum_sum_array[i-1]);
        boundaries.erase({cum_sum_array[i-1+a],i-1+a});
        if (i + b <= n)
            boundaries.insert({cum_sum_array[i+b], i+b});
    }
    cout << max_sum << endl;
} 