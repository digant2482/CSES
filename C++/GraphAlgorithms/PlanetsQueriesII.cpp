#include <iostream>

int dp[200005][21];
int len[200005] = {0};
bool visited[200005] = {false};

void dfs(int node)
{
    if (visited[node])
        return;
    visited[node] = true;
    dfs(dp[node][0]);
    len[node] = len[dp[node][0]] + 1;
}

int move(int node, int dist)
{
    if (dist <= 0)
        return node;
    
    int p = 0;
    while (dist)
    {
        if (1 & dist)
            node = dp[node][p];
        dist = dist >> 1;
        p++;                
    }
    return node;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int n, q;
    std::cin >> n >> q;
    for (int i = 1; i < n+1; i++)
        std::cin >> dp[i][0];
    
    //Binary Lifting
    for (int j = 1; j < 21; j++)
        for (int i = 1; i < n+1; i++)
            dp[i][j] = dp[ dp[i][j-1] ][j-1];

    for (int i = 1; i < n+1; i++)
        if (!visited[i])
            dfs(i); 

    int a, b;
    while (q--)
    {
        std::cin >> a >> b;
        ////Due to problem's constrains position 0 will always be in cycle, hence moving any element by it's len will guarantee that the element will land in cycle
        //cases: 1) a and b inside the cycle, 2) a inside, b outside, 3) a outside, b inside
        //All the cases where a is after b, we move a to either bring a inside cycle or complete the cycle (else if block)
        int new_a = move(a, len[a]);
        if (move(a, len[a] - len[b]) == b)
            std::cout << len[a] - len[b] << '\n';
        else if (move(new_a, len[new_a] - len[b]) == b)
            std::cout << len[a] + len[new_a] - len[b] << '\n';
        else
            std::cout << -1 << '\n';
    } 
}