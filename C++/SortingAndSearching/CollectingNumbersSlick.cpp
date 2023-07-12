#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int array_size;
    cin >> array_size;
    vector<int> pos_of_numbers(array_size);
    
    int num;
    for (int i = 0; i<array_size; i++)
    {
        cin >> num;
        num--;
        pos_of_numbers[num] = i;
    }

    int counter = 1;
    for (int i = 1; i<array_size; i++)
    {
        if(pos_of_numbers[i] < pos_of_numbers[i-1])
            counter++;
    }
    cout << counter << endl;
}