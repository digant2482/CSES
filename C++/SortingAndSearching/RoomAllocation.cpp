#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

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

using namespace std;

int main()
{
    int num_cust;
    cin >> num_cust;
    vector<Elements> customer_timing(num_cust);
    multiset<pair<int,int>> rooms_array;

    for (int i = 0; i<num_cust; i++)
    {
        cin >> customer_timing[i].l >> customer_timing[i].r;
        customer_timing[i].index = i;
    }

    sort(customer_timing.begin(), customer_timing.end());

    int num_rooms = 0;
    vector<int> answer_array(num_cust);
    for (int i = 0; i<num_cust; i++)
    {
        auto itr = rooms_array.lower_bound({customer_timing[i].l,0});
        if (itr != rooms_array.begin())
        {
            int available_room = (*--itr).second;
            rooms_array.erase(itr);
            rooms_array.insert({customer_timing[i].r, available_room});
            answer_array[customer_timing[i].index] = available_room;
        }
        else
        {
            num_rooms++; 
            rooms_array.insert({customer_timing[i].r, num_rooms});
            answer_array[customer_timing[i].index] = num_rooms;
        }
    }
    cout << num_rooms << '\n';
    for (int i = 0; i<num_cust; i++)
        cout << answer_array[i] << " ";
}