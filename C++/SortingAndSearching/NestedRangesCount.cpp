#include <iostream>
#include <vector>
#include <algorithm>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct Elements
{
    int l,r,index;
    bool operator<(const Elements& other) const
    {
        if (l == other.l)
            return r > other.r;
        return l < other.l;      
    }
};

int main()
{
    int num_ranges;
    cin >> num_ranges;
    vector<Elements> elements(num_ranges);

    for (int i = 0; i < num_ranges;i++)
    {
        cin >> elements[i].l >> elements[i].r;
        elements[i].index = i;        
    }

    sort(elements.begin(), elements.end());

    vector<int> contains(num_ranges,0);
    ordered_set<pair<int,int>> upper_limits;
    int lower_limit = 1e9 + 1;
    int l, r;
    for (int i = num_ranges-1; i >= 0; i--)
    {
        l = elements[i].l;
        r = elements[i].r;
        upper_limits.insert({r,-i});
        if (r >= lower_limit)
            contains[elements[i].index] = upper_limits.order_of_key({r, -i});
        else
            lower_limit = r;
    }
    for (int& elements:contains)
        cout << elements << " ";

    cout << endl;
    upper_limits.clear();

    vector<int> contained(num_ranges,0);
    int upper_limit = 0;
    for (int i = 0; i < num_ranges; i++)
    {
        l = elements[i].l;
        r = elements[i].r;
        upper_limits.insert({r, -i});
        if (r <= upper_limit)
            contained[elements[i].index] = (upper_limits.size() - upper_limits.order_of_key({r, -i})) - 1;
        else
            upper_limit = r;
    }
    for (int& elements:contained)
        cout << elements << " ";
}