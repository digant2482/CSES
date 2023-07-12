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

    int j = array_size-1;
    for (int i = 0; i < j; i++)
    {
        while (array[i].first + array[j].first >= target_sum && j > i)
            j--;
        
        int new_j = j;
        while (new_j > i)
        {
            int l = new_j-1;
            ll new_target = target_sum - (array[i].first + array[new_j].first);
            for (int k = i+1; k < l; k++)
            {
                while (array[k].first + array[l].first > new_target && l > k)
                    l--;
                if ((k < l) && (array[i].first + array[new_j].first + array[k].first + array[l].first == target_sum))
                {
                    cout << array[i].second << " " <<  array[new_j].second << " " << array[k].second << " " << array[l].second << endl;
                    return 0;
                }
            }
            new_j--;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}