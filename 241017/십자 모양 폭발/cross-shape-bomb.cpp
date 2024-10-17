#include <iostream>
using namespace std;

#define MAX_NUM 200

int n;
int arr[MAX_NUM+1][MAX_NUM+1];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool is_safe(int x, int y)
{
    return 0 < x && 0 < y && x <= n && y <= n;
}

void shift(int r, int c, int power)
{
    for(int y = 1; y < n+1; y++)
    {
        for(int x = n; x > 1; x--)
        {
            if(arr[x][y] == 0)
            {
                if(y == c) break;
                arr[x][y] = arr[x-1][y];
                arr[x-1][y] = 0;
            }
        }
    }

    int start0 = r + (power-1);
    start0 = start0 > n ? n : start0;
    int end0 = r - (power-1)-1;
    end0 = end0 < 1 ? 1 : end0; 

    for(int x = end0; x > 0; x--)
    {
        arr[start0][c] = arr[x][c];
        start0--;
    }
    for(int x = end0; x > 0; x--)
    {
        arr[x][c] = 0;
    }
    
}

void boom(int r, int c)
{
    int power = arr[r][c];
    arr[r][c] = 0;
    
    for(int i = 1; i < power; i++)
    {
        for(int dir = 0; dir < 4; dir++)
        {
            int x = r + dx[dir] * i;
            int y = c + dy[dir] * i;
            if(!is_safe(x, y)) continue;
            arr[x][y] = 0;
        }
    }

    shift(r, c, power);
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
        }
    }

    int r, c;
    cin >> r >> c;

    boom(r, c);

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}