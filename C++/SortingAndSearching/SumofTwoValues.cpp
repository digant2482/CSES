#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int array_size, target_sum;
    cin >> array_size >> target_sum;
    vector<pair<int,int>> array(array_size);

    for (int i = 0; i<array_size; i++)
    {
        int num;
        cin >> num;
        array[i] = {num, i+1};
    }

    sort(array.begin(), array.end());

    int i = 0;
    int j = array_size - 1;
    while (array[j].first >= target_sum && j > 0) j--;
    bool found = false;

    while (i < j)
    {
        if (array[j].first + array[i].first > target_sum) j--;
        else if (array[j].first + array[i].first < target_sum) i++;
        else 
        {
            cout << array[i].second << " " << array[j].second << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "IMPOSSIBLE" << endl;
}