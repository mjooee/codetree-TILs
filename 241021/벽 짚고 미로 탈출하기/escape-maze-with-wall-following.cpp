#include <iostream>
using namespace std;

#define MAX_N 100

int n, start_x, start_y;
int arr[MAX_N][MAX_N];

int dx[4] = {0, 1, 0, -1}; //우하좌상 
int dy[4] = {1, 0, -1, 0}; 

int pre_right_x = -1;
int pre_right_y = -1;

bool is_first = true;

// 탈출 확인
bool is_out(int x, int y)
{
    return x < 0 || x >= n || y < 0 || y >= n;
}

int move(int x, int y, int dir, int time)
{
    // 맴도는 지 확인
    if(start_x == x && start_y == y && dir == 0 && !is_first) 
        return -1;
    
    is_first = false;

    // 다음 위치 구하기
    int next_x = x + dx[dir];
    int next_y = y + dy[dir];

    // 탈출인지 확인
    if(is_out(next_x, next_y)) return time + 1;

    // 앞에 벽 있는 지 체크
    if(arr[next_x][next_y])
    {
        // 왼쪽으로 회전
        dir  = (dir + 3) % 4;
        return move(x, y, dir, time);
    }
    else
    {
        //오른쪽 벽 있는 지 확인
        int right_x = next_x + dx[(dir+1) % 4];
        int right_y = next_y + dy[(dir+1) % 4];
        if(!arr[right_x][right_y]) 
        {
            //오른쪽으로 회전
            dir = (dir+1) % 4;
        }
    }

    return move(next_x, next_y, dir, time+1);
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> start_x >> start_y;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            char input;
            cin >> input;
            if(input == '#')
                arr[i][j] = 1;
            else
                arr[i][j] = 0;
        }
    }

    start_x -= 1;
    start_y -= 1;

    cout << move(start_x, start_y, 0, 0);


    return 0;
}