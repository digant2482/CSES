#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <unordered_map>

std::unordered_map<std::string, std::vector<std::string>> g;
void dfs(std::string node, std::string& answer)
{
    while (!g[node].empty())
    {
        std::string child = g[node].back();
        g[node].pop_back();
        dfs(child, answer);
    }
    answer += node[0];  
}

int main()
{
    int n;
    std::cin >> n;
    if (n == 1)
    {
        std::cout << "01";
        return 0;
    }
    std::deque<std::string> array;
    std::unordered_map<std::string, int> out_degree;
    std::unordered_map<std::string, int> in_degree;
    std::string first_num(n, '0');

    std::string second_num(n-1, '0');
    second_num += '1';
    array.push_back(second_num);
    int i = 1;
    while (i != (1 << n))
    {
        std::string element = array.back();
        array.pop_back();
        i++;
        array.push_front(element.substr(1,n) + '1');
        array.push_front(element.substr(1,n) + '0');

        std::string node_from = element.substr(0,n-1);
        std::string node_to = element.substr(1,n);
        g[node_from].push_back(node_to);
    }

    std::string answer = first_num.substr(0,n-1);
    dfs(second_num.substr(0,n-1), answer); 
    std::cout << answer << std::endl;
}