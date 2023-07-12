#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int array_size;
    cin >> array_size;
    vector<pair<int,int>> array;

    for (int i = 0; i<array_size; i++)
    {
        int num;
        cin >> num;
        array.push_back({num,i});
    }

    sort(array.begin(), array.end());

    int counter = 1;
    for (int i = 1; i<array_size; i++)
    {
        if(array[i].second < array[i-1].second)
            counter++;
    }
    cout << counter << endl;
}