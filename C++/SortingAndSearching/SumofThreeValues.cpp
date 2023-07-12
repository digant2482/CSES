#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main()
{
    ll array_size, target_sum;
    cin >> array_size >> target_sum;
    vector<pair<ll,int>> array(array_size);
    for (int i = 0; i < array_size; i++)
    {
        cin >> array[i].first;      
        array[i].second = i+1;
    }

    sort(array.begin(), array.end());

    for (int i = 0; i < array_size; i++)
    {
        ll x2 = target_sum - array[i].first;
        int k = array_size - 1;
        for (int j = i+1; j < k; j++)
        {
            while ((array[j].first + array[k].first) > x2)
                k--;
            
            if (((array[j].first + array[k].first) == x2) && (j < k))
            {
                cout << array[i].second  << " " << array[j].second << " " << array[k].second << endl;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}