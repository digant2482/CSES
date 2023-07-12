#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int num_coins;
    cin >> num_coins;
    vector<int> array(num_coins);

    for (int i = 0; i<num_coins; i++)
        cin >> array[i];
    
    sort(array.begin(), array.end());

    long long cum_sum = 0;
    bool found = false;
    for (int i = 0; i<num_coins; i++)
    {
        if (array[i] > cum_sum + 1)
        {    
            cout << cum_sum + 1 << endl;
            found = true;
            break;
        }
        else
            cum_sum += array[i];
    }
    if (!found) 
        cout << cum_sum + 1 << endl;
}