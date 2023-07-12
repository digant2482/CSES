#include <iostream>
#include <cmath>
using namespace std;

void tower(int stack_size, int from, int to, int through)
{
    if (stack_size == 1)
        cout << from << " " << to << endl;
    else
    {
        tower(stack_size-1, from, through, to);
        cout << from << " " << to << endl;
        tower(stack_size-1, through, to, from); 
    }

}

int main()
{
    int n;
    cin >> n;
    cout << pow(2,n)-1 << endl;
    tower(n,1,3,2);
}