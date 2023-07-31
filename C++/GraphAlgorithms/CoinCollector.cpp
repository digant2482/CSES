#include <iostream>
#include <vector>
#include <stack>

typedef long long ll;

int ids[100005];
int low_link[100005];
bool on_stack[100005];
int UNVISITED = -1;
std::vector<std::vector<int>> g1;
std::vector<int> coins;
std::stack<int> stk;
std::vector<int> scc_array;

int id = 1;
int scc = 0;
void tarjan_dfs(int node)
{
    ids[node] = low_link[node] = id++;
    stk.push(node);
    on_stack[node] = true;
    for (int child : g1[node])
    {
        if (ids[child] == UNVISITED)
            tarjan_dfs(child);
        if (on_stack[child])
            low_link[node] = std::min(low_link[node], low_link[child]);
    }

    if (ids[node] == low_link[node])
    {
        scc++;
        int s_node = -1;
        while (s_node != node)
        {         
            s_node = stk.top();
            stk.pop();
            scc_array[s_node] = scc;
            on_stack[s_node] = false;  
        }
    }
}

std::vector<std::vector<ll>> meta_graph;
ll coins2[100005];
bool visited[100005];

void dfs2(int node)
{
    visited[node] = true;
    ll node_coins = coins2[node];
    for (int child : meta_graph[node])
    {
        if (!visited[child])
            dfs2(child);
        coins2[node] = std::max(coins2[node], coins2[child] + node_coins);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;
    coins.resize(n+1);
    scc_array.resize(n+1);
    g1.resize(n+1);
    for (int i = 1; i < n+1; i++)
        std::cin >> coins[i];
    
    int a, b;
    for (int i = 0; i < m; i++)
    {
        std::cin >> a >> b;
        g1[a].push_back(b);
    }

    for (int i = 1; i < n+1; i++)
        ids[i] = UNVISITED;

    for (int i = 1; i < n+1; i++)
        if (ids[i] == UNVISITED)
            tarjan_dfs(i);

    meta_graph.resize(scc+1);
    for (int i = 1; i < n+1; i++)
    {
        coins2[scc_array[i]] += coins[i];
        for (int child : g1[i])
            if (scc_array[i] != scc_array[child]) //Edges which are not a part of SCC
                meta_graph[scc_array[i]].push_back(scc_array[child]); 
    }

    for (int i = 1; i < scc+1; i++)
        if (!visited[i])
            dfs2(i);

    ll answer = 0;
    for (int i = 1; i < scc+1; i++)
        answer = std::max(answer, coins2[i]);

    std::cout << answer << std::endl;
}