#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int main()
{
    int num_elements, window_size;
    cin >> num_elements >> window_size;
    vector<int> values(num_elements);

    for (int i = 0; i<num_elements; i++)
        cin >> values[i];

    if (window_size == 1)
    {
        for (int i = 0; i < num_elements; i++)
            cout << 0 << " ";
        return 0;
    }
    if (window_size == 2)
    {
        for (int i = 0; i < num_elements-1; i++)
            cout << abs(values[i]-values[i+1]) << " ";
        return 0;
    }

    vector<pair<int,int>> window_set(window_size);
    for (int i = 0; i < window_size; i++)
        window_set[i] = {values[i],i};

    sort(window_set.begin(), window_set.end());

    set<pair<int,int>> left_set;
    set<pair<int,int>> right_set;
    ll left_set_sum = 0;
    ll right_set_sum = 0;

    for (int i = 0; i < window_size; i++)
    {
        if (i < window_size/2 + (window_size%2))
        {
            left_set.insert({window_set[i].first, window_set[i].second});
            left_set_sum += window_set[i].first;
        }
        else
        {
            right_set.insert({window_set[i].first, window_set[i].second});
            right_set_sum += window_set[i].first;
        }
    }

    ll median = left_set.rbegin()->first;
    cout << left_set.size()*median - left_set_sum + right_set_sum - right_set.size()*median << " ";

    for(int i = 0; i < num_elements - window_size; i++)
    {
        //Erasing
        if (left_set.count({values[i], i}))
        {
            left_set_sum -= values[i];
            left_set.erase({values[i], i});
        }
        else
        {
            right_set_sum -= values[i];
            right_set.erase({values[i], i});
        }
        
        //Insertion
        if (values[i+window_size] <= left_set.rbegin()->first)  
        {
            left_set.insert({values[i+window_size], i+window_size});
            left_set_sum += values[i+window_size];
        }
        else
        {
            right_set.insert({values[i+window_size], i+window_size});
            right_set_sum += values[i+window_size];
        }

        while (left_set.size() < (window_size/2 + (window_size % 2)))
        {
            auto itr = right_set.begin();
            left_set.insert(*itr);
            left_set_sum += itr->first;
            right_set_sum -= itr->first;
            right_set.erase(itr);

        }
        while (left_set.size() > (window_size/2 + (window_size % 2)))
        {
            auto itr = left_set.rbegin();
            right_set.insert(*itr);
            right_set_sum += itr->first;
            left_set_sum -= itr->first;
            left_set.erase(*itr);
        }

        median = left_set.rbegin()->first;
        cout << left_set.size()*median - left_set_sum 
                + right_set_sum - right_set.size()*median << " ";
    }
}