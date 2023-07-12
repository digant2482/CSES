#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long fives = 5;
    int zeros = 0;
    while (fives <= n)
    {
        zeros += n/fives;
        fives *= 5;
    }
    cout << zeros << endl;    
}