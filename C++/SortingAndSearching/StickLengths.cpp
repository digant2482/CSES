#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int num_sticks;
    cin >> num_sticks;
    vector<int> array(num_sticks);

    for (int i = 0; i<num_sticks; i++)
        cin >> array[i];

    sort(array.begin(), array.end());
    int median = array[num_sticks/2];

    long long cost = 0;
    for (int i = 0; i<num_sticks; i++)
    {
        cost += llabs(median-array[i]);
    }
    cout << cost << endl;
}