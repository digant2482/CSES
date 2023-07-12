#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> curr_vector;
    for (int i = 1; i<n+1; i++)
        curr_vector.push_back(i);

    while (true)
    {
        vector<int> new_vector;
        if (n % 2 == 1) 
        {
            new_vector.push_back(curr_vector.back());
            for (int i = 1; i<n; i++)
            {
                if (i % 2 == 0) cout << curr_vector[i-1] << " ";
                else new_vector.push_back(curr_vector[i-1]);
            }
        }
        else
        {
            for (int i = 1; i<n+1; i++)
            {
                if (i % 2 == 0) cout << curr_vector[i-1] << " ";
                else new_vector.push_back(curr_vector[i-1]);
            }
        }
        curr_vector = new_vector;
        n = curr_vector.size();
        if (n == 1)
        {
            cout << new_vector.back() << endl;
            break;
        }
    }
}   