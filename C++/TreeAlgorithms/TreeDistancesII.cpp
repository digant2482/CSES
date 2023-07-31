#include <bits/stdc++.h>

typedef long long ll;
int n;
int sub_tree_nodes[200005];
ll sub_tree_ans[200005];
std::vector<std::vector<int>> tree;
ll ans[200005];
void create_subtree(int node, int par)
{
    int num_nodes = 1;
    ll ans_sub_tree = 0;
    for (int child : tree[node])
    {
        if (child != par)
        {
            create_subtree(child, node);
            num_nodes += sub_tree_nodes[child];
            ans_sub_tree += sub_tree_ans[child] + sub_tree_nodes[child];
        }
    }  
    sub_tree_nodes[node] = num_nodes;
    sub_tree_ans[node]  = ans_sub_tree; 
}

void solve(int curr_node, int par, ll par_partial, int& total_nodes)
{
    ans[curr_node] = sub_tree_ans[curr_node] + (par_partial + (total_nodes - sub_tree_nodes[curr_node]));
    for (int child : tree[curr_node])
    {
        if (child != par)
            solve(child, curr_node, ans[curr_node] - (sub_tree_ans[child]+sub_tree_nodes[child]), total_nodes);
    }
}

int main()
{
    std::cin >> n;
    tree.resize(n+1);
    int a, b;
    for (int i = 0; i < n-1; i++)
    {
        std::cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    create_subtree(1, 0); //1 as our root node
    solve(1, 0, 0, n);
    for (int i = 1; i < n+1; i++)
        std::cout << ans[i] << " ";
}