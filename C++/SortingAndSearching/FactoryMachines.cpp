#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;

using namespace std;

int main()
{
    int machines, products_needed;
    cin >> machines >> products_needed;
    vector<int> machine_timings(machines);
    for (int i = 0; i < machines; i++)
        cin >> machine_timings[i];

    //sort(machine_timings.begin(), machine_timings.end());

    ll start = 0;
    ll end = 1e18;
    ll curr_best = 1e18;
    ll time;
    ll products_created;

    while (start <= end)
    {
        time = (start + end)/2;
        products_created = 0;
        for(int i = 0; i < machines; i++)
        {
            products_created += time/machine_timings[i];
            if (products_created > products_needed)
                break;
        }

        if (products_created >= products_needed)
        {
            curr_best = min(curr_best, time);
            end = time - 1;
        }     
        else 
            start = time + 1;
    } 
    cout << curr_best << endl; 
}