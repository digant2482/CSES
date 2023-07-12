#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int num_cust;
    cin >> num_cust;
    vector<pair<int, int>> array;
    for (int i = 0; i < num_cust; i++)
    {
        int arrival_time, departure_time;
        cin >> arrival_time >> departure_time;
        array.push_back({arrival_time, 1});
        array.push_back({departure_time, -1});
    }
    sort(array.begin(), array.end());

    int max_customers = 0;
    int curr_total = 0;
    int array_size = array.size();

    for (int i = 0; i<array_size; i++)
    {
        curr_total += array[i].second;
        max_customers = max(max_customers, curr_total);
    }
    cout << max_customers << endl;
}