#include <iostream>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

int n, m;
bool visited[1001][1001];
pair<int,int> prev_node[1001][1001];

bool is_valid(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
        return false;
    if (visited[x][y])
        return false;
    return true;
}
pair<int,int> moves[4] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
deque<int> queue_x, queue_y;

void explore_neighbours(int parent_x, int parent_y)
{
    for (auto move : moves)
    {
        int child_x = parent_x + move.first;
        int child_y = parent_y + move.second;
        if (is_valid(child_x, child_y))
        {
            prev_node[child_x][child_y] = {parent_x,parent_y};
            queue_x.push_back(child_x);
            queue_y.push_back(child_y);
            visited[child_x][child_y] = true;
        }
    }
}

string construct_path(pair<int, int>& end_pos)
{
    string answer;
    int curr_x = end_pos.first;
    int curr_y = end_pos.second;
    
    while (prev_node[curr_x][curr_y].first != -1)
    {
        int prev_x = prev_node[curr_x][curr_y].first;
        int prev_y = prev_node[curr_x][curr_y].second;

        if (prev_x == curr_x)
        {
            if (prev_y > curr_y)
                answer += 'L';
            else    
                answer += 'R';
        }

        if (prev_y == curr_y)
        {
            if (prev_x > curr_x)
                answer += 'U';
            else    
                answer += 'D';
        }
        curr_x = prev_x;
        curr_y = prev_y;
    } 

    reverse(answer.begin(), answer.end());
    return answer;   
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> n >> m;
    pair<int,int> start_pos;
    pair<int,int> end_pos;
    //Read values
    char symbol;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> symbol;
            visited[i][j] = false;
            prev_node[i][j] = {-1,-1};

            if (symbol == '#')
                visited[i][j] = true;
            
            if (symbol == 'A')
            {
                start_pos.first = i;
                start_pos.second = j;
            }

            if (symbol == 'B')
            {
                end_pos.first = i;
                end_pos.second = j;
            }
        }
    
    queue_x.push_back(start_pos.first);
    queue_y.push_back(start_pos.second);
    visited[start_pos.first][start_pos.second] = true;

    while (!queue_x.empty())
    {
        int node_x_cordi = queue_x.front();
        queue_x.pop_front();
        int node_y_cordi = queue_y.front();
        queue_y.pop_front();

        if (node_x_cordi == end_pos.first && node_y_cordi == end_pos.second)
            break;
        
        explore_neighbours(node_x_cordi, node_y_cordi);
    }

    if (!visited[end_pos.first][end_pos.second])
    {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << '\n';
    string path = construct_path(end_pos);
    cout << path.size() << '\n';
    cout << path << endl;
}