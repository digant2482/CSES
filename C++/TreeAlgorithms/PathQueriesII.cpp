#include <bits/stdc++.h>

int n, q, ceil_n;
int values[200005];
int s_tree[800005];
std::vector<int> tree[200005];

void update(int pos, int node)
{
    pos += ceil_n;
    s_tree[pos] = node;
    pos >>= 1;
    while (pos >= 1)
    {
        s_tree[pos] = std::max(s_tree[2*pos], s_tree[2*pos + 1]);
        pos >>= 1;
    }
}

int query(int a, int b)
{ 
    a += ceil_n, b+= ceil_n;
    int ans = 0;
    while (a <= b)
    {
        if (a & 1)
            ans = std::max(ans, s_tree[a++]);
        if (~b & 1)
            ans = std::max(ans, s_tree[b--]);
        a >>= 1, b >>= 1;  
    }  
    return ans;  
}

int parent[200005]; //parent of the node
int sub_tree_size[200005]; 
int heavy[200005]; //Child node with max sub_tree_size
int depth[200005];
void dfs(int node, int par)
{
    int max_subtree_size_child = 0;
    sub_tree_size[node] = 1;
    for (int child : tree[node])
    {
        if (child != par)
        {
            depth[child] = depth[node] + 1;
            parent[child] = node;
            dfs(child, node);
            sub_tree_size[node] += sub_tree_size[child];
            if (max_subtree_size_child < sub_tree_size[child])
            {
                max_subtree_size_child = sub_tree_size[child];
                heavy[node] = child;
            }
        }
    }
}

int count = 0;
int head[200005]; //head of the chain
int id[200005]; //position in s_tree
void hld(int node, int h)
{
    head[node] = h;
    id[node] = count++;
    update(id[node], values[node]);
    if (heavy[node]) //child node with max_subtree_size are priortized
        hld(heavy[node], h);
    for (auto child : tree[node])
        if (child != parent[node] && child != heavy[node])
            hld(child, child);
}

int path(int x, int y)
{
    int ans = 0;
    while (head[x] != head[y])
    {
        if (depth[head[x]] > depth[head[y]])
            std::swap(x,y);
        ans = std::max(ans, query(id[head[y]], id[y]));
        y = parent[head[y]];  
    }
    if (depth[x] > depth[y])
        std::swap(x,y);
    ans = std::max(ans, query(id[x], id[y]));
    return ans;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> q;
    ceil_n = 1 << (int)ceil(log2(n));
    for (int i = 1; i < n+1; i++)
        std::cin >> values[i];

    int n1, n2;
    for (int i = 0; i < n-1; i++)
    {
        std::cin >> n1 >> n2;
        tree[n1].push_back(n2);
        tree[n2].push_back(n1);        
    }
    dfs(1, 0);
    hld(1, 1);
    int x, a, b;
    while (q--)
    {
        std::cin >> x >> a >> b;
        if (x == 1)
            update(id[a], b);
        else
            std::cout << path(a,b) << " ";
    }
}