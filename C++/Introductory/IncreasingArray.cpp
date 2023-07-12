#include <iostream>
using namespace std;

int main()
{
    int size;
    cin >> size;
    long long moves = 0;
    long long curr_num;
    long long prev_num;
    cin >> prev_num;

    for (int i = 1; i < size; i++)
    {
        cin >> curr_num;
        if (curr_num < prev_num)
            moves += prev_num - curr_num;
        prev_num = max(curr_num, prev_num);
    }

    cout << moves << endl;
}