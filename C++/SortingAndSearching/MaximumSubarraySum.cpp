#include <iostream>

using namespace std;

int main()
{
    int array_size;
    cin >> array_size;
    long long best = -1e18;
    long long past = 0;

    for (int i = 0; i<array_size; i++)
    {
        int curr_num;
        cin >> curr_num;
        if (past >= 0) 
            past += curr_num;
        else 
            past = curr_num;
        best = max(best, past);
    } 
    cout << best << endl;
    }