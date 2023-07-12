#include <iostream>

int main()
{
 long long size;
 std::cin >> size;
 while (size != 1)
    {
        std::cout << size << " ";   
        if (size % 2 == 1)
            size = size*3 + 1;
        else 
            size /= 2;
    }
    std::cout << 1;
 }