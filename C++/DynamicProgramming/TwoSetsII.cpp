#include <iostream>
#include <vector>

typedef long long ll;
const int mod = 1e9 + 7;
ll modularBinaryExponentiation(int base, int exponent)
{
    if (exponent == 0)
        return 1;
    ll result = modularBinaryExponentiation(base, exponent/2);
    if (exponent % 2 == 1)
        return  (((result * result) % mod) * base) % mod;
    else
        return (result * result) % mod;
}

int main()
{
    int n;
    std::cin >> n;
    int totalSum = (n*(n+1))/2;
    if (totalSum % 2)
    {
        std::cout << 0;
        return 0;       
    }
    
    int setSum = totalSum/2;
    std::vector<ll> sumCount(setSum + 1);
    sumCount[0] = 1;
    for (int value = 1; value <= n; value++)
        for (int sum = setSum; sum >= value; sum--)
            sumCount[sum] = (sumCount[sum] + sumCount[sum-value]) % mod;
    std::cout << (sumCount[setSum] * modularBinaryExponentiation(2, mod-2)) % mod << std::endl;
}