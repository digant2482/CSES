#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main()
{
    int n,k;
    cin >> n >> k;
    vector<int> array(n);
    int max_array = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
        max_array = max(max_array, array[i]);
    }

    ll start = max_array;
    ll end = 1e18;
    ll minimum_sum = 1e18;
    while (start <= end)
    {
        int sub_array_counter = 1;
        ll local_sum = 0;
        ll mid = (start + end)/2;
        for (int i = 0; i < n; i++)
        {
            local_sum += array[i];
            if (local_sum > mid)
            {
                sub_array_counter++;
                local_sum = array[i];
            }
            if (sub_array_counter > k)
            {
                start = mid + 1;
                break;
            }
        }  
        if (sub_array_counter <= k)
        {
            end = mid - 1;
            minimum_sum = min(minimum_sum, mid);
        }
    }    
    cout << minimum_sum << endl;
}