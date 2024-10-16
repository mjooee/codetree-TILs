#include <iostream>
using namespace std;

#define MAX_NUM 100

int arr[MAX_NUM][MAX_NUM];
int temp_arr[MAX_NUM][MAX_NUM];
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

//배열 내부인지 확인
bool is_safe(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

//직사각형 경계 위치바꾸기
void shift(int r1, int c1, int r2, int c2)
{
    //좌측 상단 값 빼두기
    int temp = arr[r1][c1];
    //좌측 상단 아래칸부터  남동북서순으로 가장자리 위치 바꾸기
    int x = r1+1, y = c1;
    int px = r1, py = c1;
    int time = (r2 - r1) * 2 + (c2 - c1) * 2;
    int dir = 0;

    while(time--)
    {
        if(x + dx[dir] > r2 || x + dx[dir] < r1 || y + dy[dir] > c2 || y + dy[dir] < c1)
        {
            dir += 1;
            time++;
            continue;
        }
        arr[px][py] = arr[x][y];
        px = x;
        py = y;
        x += dx[dir];
        y += dy[dir];
    }

    arr[r1][c1 + 1] = temp;
}

//배열 갱신
void update(int r1, int c1, int r2, int c2)
{
    for(int i = r1; i <= r2; i++)
    {
        for(int j = c1; j <= c2; j++)
        {
            arr[i][j] = temp_arr[i][j];
        }
    }
}

//평균으로 바꾸기
void make_avg(int r1, int c1, int r2, int c2)
{
    for(int i = r1; i <= r2; i++)
    {
        for(int j = c1; j <= c2; j++)
        {
            int sum = arr[i][j];
            int cnt = 1;
            for(int dir = 0; dir < 4; dir++)
            {
                if(is_safe(i+dx[dir], j+dy[dir]))
                {
                    sum += arr[i+dx[dir]][j+dy[dir]];
                    cnt++;
                }
            }
            temp_arr[i][j] = sum/cnt;
        }
    }
    update(r1, c1, r2, c2);
}

int main() {
    // 여기에 코드를 작성해주세요.
    int q;
    cin >> n >> m >> q;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }    

    while(q--)
    {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        shift(r1-1, c1-1, r2-1, c2-1);
        make_avg(r1-1, c1-1, r2-1, c2-1);
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";        
        }
        cout << endl;
    }

    return 0;
}