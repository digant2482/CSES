#include<bits/stdc++.h> 
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main()
{
    int n,k;
    cin >> n >> k;
    ordered_set<int> children;
    for (int i=1; i<n+1; i++)
        children.insert(i);
    
    int startPosition = 0;
    while (children.size() > 0)
    {
        int positionToRemove = (startPosition+k) % children.size();
        startPosition = positionToRemove; 
        auto itr = children.find_by_order(positionToRemove);
        cout << *itr << " ";
        children.erase(itr);
    }
}