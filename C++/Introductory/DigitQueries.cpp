#include <iostream>
#include <string>
#define ll long long
using namespace std;

int main()
{
    int num_queries;
    cin >> num_queries;
    for (int i = 0; i < num_queries; i++)
    {
        ll k;
        cin >> k;
        if (k <= 9){
            cout << k << endl; 
            continue;
        }
        else
        {
            ll nines = 9;
            ll digits = 1;
            ll position = 9;
            while (position <= k)
            {
                nines *= 10;
                digits += 1;
                position += nines*digits;
            }
            position -= nines*digits;
            nines /= 10;
            digits -= 1;

            ll curr_num = 1;
            for(int i = 0; i<digits;i++)  curr_num *= 10;

            ll remaining_numbers =  (k - position)/(digits + 1);
            ll digit_occupies_by_remaninig_num = remaining_numbers * (digits + 1);

            if (position + digit_occupies_by_remaninig_num == k)
                cout << to_string(curr_num + remaining_numbers -1).back() << endl;
            else
            {
                ll desired_number = curr_num + remaining_numbers;
                ll desired_position = (k - (position + digit_occupies_by_remaninig_num)) - 1; //-1 because of index starts with 0
                cout << to_string(desired_number)[desired_position] << endl;
            }
        }       
    }
}