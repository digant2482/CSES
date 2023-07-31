#include <bits/stdc++.h>

int n;
int depth[200005];
int ans[200005];
std::vector<std::vector<int>> g;
void eval_depth(int node, int parent)
{
    for (int child : g[node])
    {
        if (child != parent)
        {
            eval_depth(child, node);
            depth[node] = std::max(depth[node], depth[child] + 1);  
        }
    }
}

void solve(int curr_node, int parent, int parent_par)
{
    std::vector<int> prefix_max, suffix_max;
    for (int child : g[curr_node])
    {
        if (child != parent)
        {
            prefix_max.push_back(depth[child]); 
            suffix_max.push_back(depth[child]);
        }
    }

    for (int i = 1; i < prefix_max.size(); i++)
        prefix_max[i] = std::max(prefix_max[i], prefix_max[i-1]);
    
    for (int i = suffix_max.size() - 2; i >= 0; i--)
        suffix_max[i] = std::max(suffix_max[i], suffix_max[i+1]);

    ans[curr_node] = 1 + std::max(parent_par, prefix_max.size() ? prefix_max.back() : -1);
    int c_idx = 0;
    for (int child : g[curr_node])
    {
        if(child != parent)
        {
            int prefix = (c_idx == 0) ? INT_MIN : prefix_max[c_idx-1];
            int suffix = (c_idx == suffix_max.size() - 1) ? INT_MIN : suffix_max[c_idx+1];
            int par_ans = 1 + std::max(parent_par, std::max(prefix, suffix));
            solve(child, curr_node, par_ans);
            c_idx++;
        }
    }
}

int main()
{
    std::cin >> n;
    if (n == 1)
    {
        std::cout << 0;
        return 0;
    }
    g.resize(n+1);
    int a, b;
    for (int i = 0; i < n-1; i++)
    {
        std::cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    eval_depth(1, 0);
    solve(1, 0, -1);
    for (int i = 1; i < n+1; i++)
        std::cout << ans[i] << " ";
}