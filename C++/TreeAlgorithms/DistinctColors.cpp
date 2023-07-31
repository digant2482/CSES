#include <bits/stdc++.h>

std::set<int> *st[200005];
int values[200005];
int ans[200005];
std::vector<int> tree[200005];
void dfs(int node, int par)
{
    int mx = 0;
    int mx_node = -1;
    for (int child : tree[node])
    {
        if (child != par)
        {
            dfs(child, node);
            if (st[child]->size() > mx)
            {
                mx = st[child]->size();
                mx_node = child;
            }
        }
    }
    
    if (mx_node == -1)
        st[node] = new std::set<int> ();
    else
        st[node] = st[mx_node];

    st[node] -> insert(values[node]);

    for (int child : tree[node])
        if (child != par && child != mx_node)
            for (int color : *st[child])
                st[node] -> insert(color);
    ans[node] = st[node] -> size(); 
}

int main()
{
    int n;
    std::cin >> n;
    for (int i = 1; i < n+1; i++)
        std::cin >> values[i];
    
    int a, b;
    for (int i = 0; i < n-1; i++)
    {
        std::cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1,0);
    for (int i = 1; i < n+1; i++)
        std::cout << ans[i] << " ";
}