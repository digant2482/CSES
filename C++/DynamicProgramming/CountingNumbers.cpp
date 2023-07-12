#include <iostream>
#include <string>
#include <cstring>

typedef long long ll; 
ll dp[20][10][2][2];
ll solve(std::string& number, int n, int x, bool leading_zeros, bool tight)
{
    if (n == 0)
        return 1;
    int lb = 0;
    int ub = tight ? (number[number.length() - n]) - '0' : 9;

    if (dp[n][x][leading_zeros][tight] != 0 && x != -1)
        return dp[n][x][leading_zeros][tight];

    ll answer = 0;
    for (int dig = lb; dig <= ub; dig++)
    {
        if (dig == x && leading_zeros == 0)
            continue;
        answer += solve(number, n-1, dig, (leading_zeros & dig == 0), (tight & (dig == ub)));
    }
    dp[n][x][leading_zeros][tight] = answer;
    return answer;
}

int main()  
{
    ll a, b;
    std::cin >> a >> b;
    std::string A = std::to_string(a-1);
    std::string B = std::to_string(b);

    memset(dp, 0, sizeof(dp));
    ll ans1 = solve(B, B.length(), -1, 1, 1);

    memset(dp, 0, sizeof(dp));
    ll ans2 = solve(A, A.length(), -1, 1, 1);
    std::cout << ans1 - ans2 << std::endl;
}