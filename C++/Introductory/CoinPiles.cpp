#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        int a, b;
        cin >> a >> b;
        //We are taking 3 coins at a time, hence condition 1 
        //Condition 2 is to make sure we don't run out of coins in one of the piles, also when equal stacks means 
        if (((a+b)%3 == 0) && (max(a,b)/2 - min(a,b) <= 0))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}