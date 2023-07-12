#include <iostream>
using namespace std;

int main()
{
    long long k;
    cin >> k;
    for (long long i = 1; i < k+1; i++)
    {
        long long possible_positions = (i*i)*(i*i-1)/2;
        long long invalid_positions = (i-2)*(i-1)*4;
        cout << possible_positions - invalid_positions << endl;
    }
}