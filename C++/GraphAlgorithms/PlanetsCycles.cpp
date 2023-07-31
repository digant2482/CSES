#include <iostream>
#include <vector>

int len[200005] = {0};
int g[200005];
bool visited[200005] = {false};

void one_time_search(int node)
{
    //one time search until visited node is found
    std::vector<int> prev;
    visited[node] = true;
    prev.push_back(node);

    int child = g[node];
    while (!visited[child])
    {
        visited[child] = true;
        prev.push_back(child);
        child = g[child];
    }

    int score;
    if (len[child])
        score = len[child];
    else
    {
        score = 0;
        std::vector<int> prev2;

        while(true)
        {
            int a = prev.back(); 
            prev.pop_back();
            prev2.push_back(a);
            score++;
            if (a == child)
            {
                for (auto i: prev2) len[i] = score;
                len[child] = score;
                break;
            }
        } 
    }

    while (!prev.empty())
    {
        score++;
        int a = prev.back();
        prev.pop_back();
        len[a] = score;
    }   
}

int main()
{
    int n;
    std::cin >> n;
    for (int i = 1; i < n+1; i++)
        std::cin >> g[i];
    
    for (int i = 1; i < n+1; i++)
        if (!visited[i])
            one_time_search(i);

    for (int i = 1; i < n+1; i++)
        std::cout << len[i] << " ";
}