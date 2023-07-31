#include <bits/stdc++.h>
int n;
std::vector<int> tree[200005];
int sub_tree_size [200005];

void dfs(int node, int par)
{
    sub_tree_size[node] = 1;
    for (int child : tree[node])
    {
        if (child != par)
        {
            dfs(child, node);
            sub_tree_size[node] += sub_tree_size[child];
        }
    }
}

int find_centroid(int node, int par)
{
    for (int child : tree[node])
        if (child != par && sub_tree_size[child] > n/2)
            return find_centroid(child, node);

    return node;
}
int main()
{
    std::cin >> n;
    int a, b;
    for (int i = 0; i < n-1; i++)
    {
        std::cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(1, 0);
    std::cout << find_centroid(1,0) << std::endl;
}