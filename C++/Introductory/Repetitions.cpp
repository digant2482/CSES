#include <iostream>
#include <string>

int main()
{
    using namespace std;
    string sequence;
    cin >> sequence;

    int max_rep = 1;
    int counter = 1;

    for (int i = 1; i < sequence.size(); i++)
    {
        if (sequence[i] == sequence[i-1]) 
            counter ++;
        else
            counter = 1;
        max_rep = max(max_rep, counter);        
    }

    cout << max_rep << endl;
}