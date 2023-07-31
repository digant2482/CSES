#include <bits/stdc++.h>
typedef long long ll;

int n, q;
int array[200005];
int start[200005];
int sub_tree_size[200005];
ll s_tree[400005];
std::vector<int> tree[200005];

void update(int pos, int node)
{
    pos += n;
    s_tree[pos] = node;
    pos >>= 1;
    while (pos >= 1)
    {
        s_tree[pos] = s_tree[2*pos] + s_tree[2*pos + 1];
        pos >>= 1;
    }
}

int timer = 0;
void dfs(int node, int par)
{
    start[node] = timer++;
    update(start[node], array[node]);
    for (int child : tree[node])
    {
        if (child != par)
        {
            dfs(child, node);
            sub_tree_size[node] += sub_tree_size[child] + 1;
        }
    }
}

ll query(int a, int b)
{ 
    a += n, b+= n;
    ll ans = 0;
    while (a <= b)
    {
        if (a & 1)
            ans += s_tree[a++];
        if (~b & 1)
            ans += s_tree[b--];
        a >>= 1, b >>= 1;  
    }  
    return ans;  
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> q;
    for (int i = 1; i < n+1; i++)
        std::cin >> array[i];

    int n1, n2;
    for (int i = 0; i < n-1; i++)
    {
        std::cin >> n1 >> n2;
        tree[n1].push_back(n2);
        tree[n2].push_back(n1);        
    }
    dfs(1, 0);
    int x, a, b;
    while (q--)
    {
        std::cin >> x >> a;
        if (x == 1)
        {
            std::cin >> b;
            update(start[a], b);
        }
        else
        {
            int idx_a = start[a];
            std::cout << query(idx_a, idx_a + sub_tree_size[a]) << '\n';
        }
    }
}