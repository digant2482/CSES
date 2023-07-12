#include <iostream>
#include <cmath>
#define ll long long

using namespace std;

int main()
{
    int n;
    cin >> n;
    int ans = 1;
    int mod = (pow(10,9) + 7);
    for (ll i = 0; i<n;i++)
    {
        ans *= 2;
        ans %= mod;
    }
    cout << ans % mod << endl;
}