#include <iostream>
#include <set>
#include <vector>

typedef long long ll;

struct Edge
{
    int from, to, cost;
    Edge(int from, int to, int cost) : from(from), to(to), cost(cost) {}
};

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<Edge>> g(n+1);
    std::vector<ll> cost_without_discount(n+1, 1e18);
    std::vector<ll> cost_with_discount(n+1, 1e18);
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    cost_without_discount[1] = 0;
    cost_with_discount[1] = 0;

    Edge edge(0,0,0);
    for (int i = 0; i < m; i++)
    {
        std::cin >> edge.from >> edge.to >> edge.cost;
        g[edge.from].push_back(edge);
    }

    std::set<std::pair<ll,std::pair<int,bool>>> pq;
    pq.insert({0,{1,false}});

    while(!pq.empty())
    {
        auto itr = pq.begin();
        int curr_city = (itr ->second).first;
        bool coupon_used = (itr ->second).second;
        pq.erase(itr);

        if (coupon_used && cost_with_discount[curr_city] < itr->first)
            continue;
        
        if (!coupon_used && cost_without_discount[curr_city] < itr->first)
            continue;

        for (Edge edge : g[curr_city])
        {
            if (coupon_used)
            {
                ll new_cost = cost_with_discount[curr_city] + edge.cost;
                if (cost_with_discount[edge.to] > new_cost)
                {
                    cost_with_discount[edge.to] = new_cost;
                    pq.insert({cost_with_discount[edge.to], {edge.to, true}});
                } 
            }
            else
            {
                //Coupon Used
                ll new_cost = cost_without_discount[curr_city] + edge.cost/2;
                if (cost_with_discount[edge.to] > new_cost)
                {
                    cost_with_discount[edge.to] = new_cost;
                    pq.insert({cost_with_discount[edge.to], {edge.to, true}});
                } 
                //Coupon Unused
                new_cost = cost_without_discount[curr_city] + edge.cost;
                if (cost_without_discount[edge.to] > new_cost)
                {
                    cost_without_discount[edge.to] = new_cost;
                    pq.insert({cost_without_discount[edge.to], {edge.to, false}});
                } 
            }
        }
    }
    std::cout << cost_with_discount[n]  << std::endl;
}