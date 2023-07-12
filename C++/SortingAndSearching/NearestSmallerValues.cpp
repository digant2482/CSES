#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int array_size;
    cin >> array_size;
    vector<pair<int,int>> stack;
    int num;
    cin >> num;
    stack.push_back({num,1});
    cout << 0 << " ";

    for (int i = 1; i < array_size; i++)
    { 
        cin >> num; 
        while (!stack.empty() && stack.back().first >= num)
            stack.pop_back();

        if (!stack.empty())
            cout << stack.back().second << " ";
        else    
            cout << 0 << " ";
        stack.push_back({num,i+1});
    }
}