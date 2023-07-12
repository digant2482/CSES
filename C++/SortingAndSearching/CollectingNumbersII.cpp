#include <iostream>
#include <vector>
#include <set>
#include <utility>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int array_size, num_operations;
    cin >> array_size >> num_operations;
    vector<int> pos_of_numbers(array_size+1);
    vector<int> values(array_size);
    
    for (int i = 1; i<=array_size; i++)
    {
        cin >> values[i];
        pos_of_numbers[values[i]] = i;
    }

    int counter = 1;
    for (int i = 1; i<array_size; i++)
        counter += pos_of_numbers[i] > pos_of_numbers[i+1];

    int pos1,pos2;
    while (num_operations--)
    {
        set<pair<int,int>> updated_pairs;
        cin >> pos1 >> pos2;
        if (values[pos2]+1 <= array_size)
            updated_pairs.insert({values[pos2],values[pos2]+1});
        if (values[pos2]-1 >= 1)
            updated_pairs.insert({values[pos2]-1,values[pos2]});
        if (values[pos1]+1 <= array_size)
            updated_pairs.insert({values[pos1],values[pos1]+1});
        if (values[pos1]-1 >= 1)
            updated_pairs.insert({values[pos1]-1,values[pos1]});

        for (pair <int,int> pair : updated_pairs)
            counter -= (pos_of_numbers[pair.first] > pos_of_numbers[pair.second]);

        swap(values[pos1], values[pos2]);
        pos_of_numbers[values[pos1]] = pos1;
        pos_of_numbers[values[pos2]] = pos2;
        
        for (pair <int,int> pair : updated_pairs)
            counter += (pos_of_numbers[pair.first] > pos_of_numbers[pair.second]);
        
        cout << counter << "\n";
    }
}