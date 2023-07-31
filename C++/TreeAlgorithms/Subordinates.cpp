#include <bits/stdc++.h>

int n;
std::vector<std::vector<int>> g;
int sub[200005];

void dfs(int node)
{
    for (int child : g[node])
    {
        dfs(child);
        sub[node] += (sub[child] + 1); //Subirdinate of child + the employee itself
    }
}
int main()
{
    std::cin >> n;
    g.resize(n+1);
    int boss;
    for (int i = 2; i < n+1; i++)
    {
        std::cin >> boss;
        g[boss].push_back(i);        
    }

    dfs(1);

    for (int i = 1; i < n+1; i++)
        std::cout << sub[i] << " ";    
}