#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main()
{
    int num_tasks;
    cin >> num_tasks;
    vector<pair<ll,ll>> array(num_tasks);

    for(int i = 0; i < num_tasks; i++)
        cin >> array[i].first >> array[i].second;
    
    sort(array.begin(), array.end());

    ll cum_time = 0;
    ll reward = 0;
    for(int i = 0; i < num_tasks; i++)
    {
        cum_time += array[i].first;
        reward += array[i].second - cum_time;
    }
    cout << reward << endl;
}