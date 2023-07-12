#include <iostream>
#include <vector>

typedef long long ll;

int main()
{
    int n;
    std::cin >> n;
    std::vector<ll> cache(n+1, 0);
    int mod = 1e9 + 7;
    cache[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        ll sum = 0;
        for (int j = 1; j < 7; j++)
        {
            if (i-j >= 0)
                sum += cache[i-j];
        }
        cache[i] = sum % mod;
    }
    std::cout << cache.back() << std::endl;
}