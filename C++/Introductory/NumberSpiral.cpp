#include <iostream>

using namespace std;

void solve(const long long& row, const long long& col) 
{
    if(row >= col)
        {
            if(row % 2 ==0)
                cout << row*row - col + 1 << endl;   
            else
                cout << (row-1)*(row-1) + col << endl;
        }
        else
        {
            if(col % 2 ==1)
                cout << col*col - row + 1 << endl;
            else
                cout << (col-1)*(col-1) + row << endl;
        }
}

int main()
{
    int t;
    cin >> t;
    long long row;
    long long col;
    for (int i = 0; i < t; i++)
    {
        cin >> row;
        cin >> col;
        solve(row, col);
    }
}