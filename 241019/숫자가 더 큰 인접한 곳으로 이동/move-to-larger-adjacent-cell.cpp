#include <iostream>
using namespace std;

#define MAX_N 100

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int arr[MAX_N][MAX_N];

int n;

bool is_safe(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < n;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int r, c;
    cin >> n >> r >> c;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    int x = r-1, y = c-1;
    bool is_move = true;

    while(is_move)
    {
        is_move = false;
        cout << arr[x][y] << " ";
        for(int dir = 0; dir < 4; dir++)
        {
            int new_x = x + dx[dir];
            int new_y = y + dy[dir];
            if(is_safe(new_x, new_y) && arr[x][y] < arr[new_x][new_y])
            {
                x = new_x;
                y = new_y;
                is_move = true;
                break;
            }
        }
    }
    
    return 0;
}