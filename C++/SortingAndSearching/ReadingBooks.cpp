#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<int> timings(n);
    ll sum = 0;
    for (int i = 0; i<n; i++)
    {
        cin >> timings[i];
        sum += timings[i];
    }
    
    sort(timings.begin(), timings.end());
    cout << max((ll)2*timings.back(), sum) << endl;
    
}       