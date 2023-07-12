#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // Invalid positions
    vector<pair<int,int>> invalid_pos;
    for (int i = 0; i<8; i++)
    {
        string line;
        cin >> line;
        for (int j = 0; j<8; j++)
        {
            if(line[j] == '*')
                invalid_pos.push_back({i,j});
        }
    }

    vector<int> y_cordi = {0,1,2,3,4,5,6,7};
    int counter = 0;
    do{
        //Check diagonals only conditions we need to take care of
        vector<int> right_diagonals(15,false);
        vector<int> left_diagonals(15,false);
        bool valid = true;
        for (int x = 0; x<8; x++)
        {
            // If queen's position is on invalid position
            if (!invalid_pos.empty())
            {
                auto curr_pos = find(invalid_pos.begin(), invalid_pos.end(), make_pair(x, y_cordi[x]));
                // If element not found than itr returns last value's itr, 
                // Also second condition is to check if value is not the last value of the vector
                if (curr_pos != invalid_pos.end() || (x == invalid_pos.back().first && y_cordi[x] == invalid_pos.back().second))
                {
                    valid = false;
                    break;
                }    
            }    
            
            int right_diagonal = y_cordi[x]-x+7;
            if (right_diagonals[right_diagonal])
            {
                valid = false;
                break;
            }
            else
                right_diagonals[right_diagonal] = true;

            int left_diagonal = x+y_cordi[x];
            if (left_diagonals[left_diagonal])
            {
                valid = false;
                break;
            }
            else
                left_diagonals[left_diagonal] = true;
        }
        if (valid) 
            counter += 1;
    } while(next_permutation(y_cordi.begin(), y_cordi.end()));
    cout << counter << endl;
}