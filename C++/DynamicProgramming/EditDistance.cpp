#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

int main()
{
    std::string word1, word2;
    std::cin >> word1 >> word2;
    std::vector<std::vector<int>> minOperations(word1.length(), std::vector<int>(word2.length(), 1e9)); 

    for (int i = 0; i < word2.length()+1; i++)
        minOperations[0][i] = i;
    for (int i = 0; i < word2.length()+1; i++)
        minOperations[i][0] = i;

    for (int row = 1; row < word1.length()+1; row++)
    {
        for (int col = 1; col < word2.length()+1; col++)
        {
            minOperations[row][col] = std::min({minOperations[row-1][col-1] + (word1[row-1] != word2[col-1]),
                                                minOperations[row-1][col] + 1, 
                                                minOperations[row][col-1] + 1});
        }
    }
    std::cout << minOperations[word1.length()][word2.length()] << std::endl;
}