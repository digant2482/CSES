#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n == 3 || n==2)
        cout << "NO SOLUTION" << endl;
    else
    {
        for(int i = 2; i<n+1;i+=2)
            cout << i << " ";
        for(int i = 1; i<n+1;i+=2)
            cout << i << " ";
    }
}