#include<bits/stdc++.h> 
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


int main()
{   
    int num_elements, window_size;
    cin >> num_elements >> window_size;
    vector<int> array(num_elements);
    for (int i = 0; i<num_elements; i++)
        cin >> array[i];   

    ordered_set<pair<int,int>> window_set; 
    int j = 0;    
    for(int i = 0; i < num_elements - window_size + 1; i++)
    {
        while((int)window_set.size() < window_size && j < num_elements)
        {
            window_set.insert({array[j], j});
            j++;
        }
        cout << window_set.find_by_order((window_size-1)/2) -> first << " ";
        window_set.erase({array[i], i});
    }
    cout << endl;  
}