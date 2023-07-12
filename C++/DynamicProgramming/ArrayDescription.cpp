#include <iostream>
#include <vector>
typedef long long ll;

int main()
{
    int size, upperBound;
    std::cin >> size >> upperBound;
    int mod = 1e9 + 7;
    std::vector<int> array(size);
    for (int i = 0; i < size; i++)
        std::cin >> array[i];
    
    std::vector<std::vector<ll>> numArrays(size, std::vector<ll>(upperBound+1,0));
    if (array[0] != 0)
        numArrays[0][array[0]] = 1;
    else
    {
        for (int i = 1; i < upperBound+1; i++)
            numArrays[0][i] = 1;
    }
    for (int i = 1; i < size; i++)
    {
        if (array[i] == 0)
        {
            for (int j = 1; j <= upperBound; j++)
            {
                numArrays[i][j] = numArrays[i-1][j-1];
                numArrays[i][j] = (numArrays[i][j] + numArrays[i-1][j]) % mod; 
                if (j+1 <= upperBound)
                    numArrays[i][j] = (numArrays[i][j] + numArrays[i-1][j+1]) % mod;
            }
        }
        else
        {
            int num = array[i];
            numArrays[i][num] = numArrays[i-1][num-1];
            numArrays[i][num] += numArrays[i-1][num]; 
            if (num+1 <= upperBound)
                 numArrays[i][num] = (numArrays[i][num] + numArrays[i-1][num+1]) % mod;
        }
    }
 
    ll maxWays = 0;
    for (int i = 1; i < upperBound+1; i++)
        maxWays = (maxWays + numArrays[size-1][i]) % mod;
    std::cout << maxWays << std::endl;
}   