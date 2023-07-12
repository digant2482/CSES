#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

int n, m;
bool visited[1001][1001];
std::pair<int,int> player_prev[1001][1001];
std::queue<std::pair<int,int>> monster_queue;
std::queue<std::pair<int,int>> player_queue;
std::pair<int,int> exit_pos;
bool path_found = false;

bool is_valid_pos(int x, int y)
{
    if (x < 0 || y < 0 || x >=n || y >= m)
        return false;
    if (visited[x][y])
        return false;
    return true;
}

std::pair<int,int> moves[4] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
void explore_neighbours_monster(std::pair<int,int> monster_pos)
{
    int monster_x = monster_pos.first;
    int monster_y = monster_pos.second;
    for (auto move:moves)
    {
        int x = monster_x + move.first;
        int y = monster_y + move.second;
        if (is_valid_pos(x,y))
        {
            visited[x][y] = true;
            monster_queue.push({x,y});
        }
    } 
}

void explore_neighbours_player(std::pair<int,int> player_pos)
{
    int player_x = player_pos.first;
    int player_y = player_pos.second;
    for (auto move:moves)
    {
        int x = player_x + move.first;
        int y = player_y + move.second;
        if (is_valid_pos(x,y))
        {
            visited[x][y] = true;
            player_queue.push({x,y});
            player_prev[x][y] = {player_x, player_y};
            if (x == n-1 || y == m-1 || x == 0 || y == 0)
            {
                exit_pos.first = x;
                exit_pos.second = y;
                path_found = true;
                return;
            }
        }
    } 
}

std::string construct_path(std::pair<int, int>& end_pos)
{
    std::string answer;
    int curr_x = end_pos.first;
    int curr_y = end_pos.second;
    
    while (player_prev[curr_x][curr_y].first != -1)
    {
        int prev_x = player_prev[curr_x][curr_y].first;
        int prev_y = player_prev[curr_x][curr_y].second;

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
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    std::cin >> n >> m;
    std::pair<int,int> player_start;
    char symbol;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            std::cin >> symbol;
            visited[i][j] = false;
            player_prev[i][j] = {-1,-1}; 
            if (symbol == '#') //Boundaries and monsters' position are labeled visited
                visited[i][j] = true;

            if (symbol == 'M')
                monster_queue.push({i,j});
            
            if (symbol == 'A')
            {
                player_queue.push({i,j});
                player_start.first = i;
                player_start.second = j;
            }
        }
    
    //Edge case when player is already at boundary, 
    //No need for calculation since we have not considered 0 as output
    if (player_start.first == n-1 || player_start.first == 0 || 
            player_start.second == m-1 || player_start.first == 0)
    {
        std::cout << "YES" << '\n';
        std::cout << 0 << std::endl;
        return 0;
    }

    while (!player_queue.empty() && !path_found)
    {
        //Marks all existing/possible position of monsters as visited
        int monster_queue_size = monster_queue.size();
        for (int i = 0; i < monster_queue_size; i++)
        {
            std::pair<int,int> monster_pos = monster_queue.front();
            monster_queue.pop();
            visited[monster_pos.first][monster_pos.second] = true;
            explore_neighbours_monster(monster_pos);
        }

        int player_queue_size = player_queue.size();
        for (int i = 0; i < player_queue_size; i++)
        {
            std::pair<int,int> player_pos = player_queue.front();
            player_queue.pop();
            visited[player_pos.first][player_pos.second] = true;
            explore_neighbours_player(player_pos);
        }
    }

    if (!path_found)
    {
        std::cout << "NO" << std::endl;
        return 0;
    }

    std::cout << "YES" << '\n';
    std::string path = construct_path(exit_pos);
    std::cout << path.size() << '\n';
    std::cout << path << std::endl;
}