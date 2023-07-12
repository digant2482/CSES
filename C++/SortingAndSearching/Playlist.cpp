#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
    int num_songs;
    cin >> num_songs;
    vector<int> playlist(num_songs);

    for (int i = 0; i<num_songs; i++)
        cin >> playlist[i];

    set<int> heard;
    int i = 0;
    int j = 0;
    int max_streak = 0;

    while (j < num_songs)
    {
        while (j < num_songs && !heard.count(playlist[j]))
        {
            heard.insert(playlist[j]);
            max_streak = max(max_streak, j-i+1);
            j++;
        }

        while (heard.count(playlist[j]))
        {
            heard.erase(playlist[i]);
            i++;
        }
    }
    cout << max_streak << endl;
}