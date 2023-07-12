#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int,int>& a, pair<int,int>& b)
{    return a.second < b.second;
}

int main()
{
    int num_movies;
    cin >> num_movies;
    vector<pair<int,int>> movies(num_movies);
    for (int i = 0; i < num_movies; i++)
    {
        int start, end;
        cin >> start >> end;
        movies[i] = {start,end};
    }

    sort(movies.begin(), movies.end(), cmp);

    int counter = 1;
    int prev_movie_end = movies[0].second;
    for (int i = 1; i < num_movies; i++)
    {
        if (movies[i].first >= prev_movie_end)
        {
            counter++;
            prev_movie_end = movies[i].second;
        }
    } 
    cout << counter << endl;
}