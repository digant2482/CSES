#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int size;
    std::cin >> size;
    std::vector<int> subsequence;
    for (int i = 0; i < size; i++)
    {
        int value;
        std::cin >> value;
        int idx = std::lower_bound(subsequence.begin(), subsequence.end(), value) - subsequence.begin();
        if (idx == subsequence.size())
            subsequence.push_back(value);    
        else
            subsequence[idx] = value;    
    }
    std::cout << subsequence.size() << std::endl;
}