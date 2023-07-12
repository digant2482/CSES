#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    int n, max_subarrays;
    cin >> n >> max_subarrays;
    vector<int> array(n);
    for (int i = 0; i < n; i++)
        cin >> array[i];

    map<int, int> distinct_elements_map;
    int j = 0;
    long long subarrays_counter = 0;

    for (int i = 0; i < n; i++)
    {
        while ((distinct_elements_map.size() < max_subarrays || distinct_elements_map.count(array[j]) > 0) && j < n)
        {
            distinct_elements_map[array[j]]++;
            j++;
        }
        subarrays_counter += j-i;
        distinct_elements_map[array[i]]--;
        
        if (!distinct_elements_map[array[i]])
            distinct_elements_map.erase(array[i]);
    }
    cout << subarrays_counter << endl;
}   