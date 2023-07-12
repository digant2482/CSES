#include <iostream>
#include <vector>
typedef long long ll;

int main()
{
    int n;
    std::cin >> n;
    std::vector<ll> minPaths(n+1, 1e18);
    minPaths[0] = 0;

    for (int i = 1; i < n+1; i++)
    {
        int num = i;
        while (num != 0)
        {
            minPaths[i] = std::min(minPaths[i], minPaths[i - (num % 10)] + 1);
            num /= 10;
        }
    }
    std::cout << minPaths[n] << std:: endl;
}