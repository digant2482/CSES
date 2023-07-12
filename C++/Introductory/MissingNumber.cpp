#include <iostream>
#include <set>

int main()
{
    int n;
    std::cin >> n;
    std::set<int> arr;
    for (int i = 1; i<n+1; i++)
        arr.insert(i);
    
    for (int i = 1; i<n; i++)
    {
        int m;
        std::cin >> m;
        arr.erase(m);
    }

    std::cout << *(arr.begin()) << std::endl;   
}