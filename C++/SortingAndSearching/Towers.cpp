#include <iostream>
#include <set>

using namespace std;

int main()
{
    int numCubes;
    cin >> numCubes;
    multiset<int> stacks;

    int num;
    for (int i =0; i<numCubes; i++)
    {
        cin >> num;
        auto itr = stacks.upper_bound(num);
        if (itr != stacks.end())
           stacks.erase(itr);
        stacks.insert(num);   
    }
    cout << stacks.size() << endl;
}