#include <iostream>
#include <algorithm>
using namespace std;

#define max_m 200
#define max_n 200

int arr[max_n][max_m];
int n, m;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool is_safe(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

int curve_block(int x, int y) //ㄴ자 블럭
{
    int sum = arr[x][y];
    int updown;
    int leftright;

    if(is_safe(x+1, y) && is_safe(x-1, y))
        updown = max(arr[x+1][y], arr[x-1][y]);
    else if(is_safe(x+1, y))
        updown = arr[x+1][y];
    else
        updown = arr[x-1][y];
    
    if(is_safe(x, y+1) && is_safe(x, y-1))
        leftright = max(arr[x][y+1], arr[x][y-1]);
    else if(is_safe(x, y+1))
        leftright = arr[x][y+1];
    else
        leftright = arr[x][y-1];
    
    sum += updown + leftright;
    
    return sum;
}

int straight_block(int x, int y)
{
    int ver_sum, hor_sum;
    if(is_safe(x, y+1) && is_safe(x, y+2) && is_safe(x+1, y) && is_safe(x+2, y))
    {
        hor_sum = arr[x][y] + arr[x][y+1] + arr[x][y+2];
        ver_sum = arr[x][y] + arr[x+1][y] + arr[x+2][y];
    }
    else if(is_safe(x, y+1) && is_safe(x, y+2))
    {
        hor_sum = arr[x][y] + arr[x][y+1] + arr[x][y+2];
        ver_sum = 0;
    }
    else if(is_safe(x+1, y), is_safe(x+2, y))
    {
        hor_sum = 0;
        ver_sum = arr[x][y] + arr[x+1][y] + arr[x+2][y];
    }

    return max(ver_sum, hor_sum);
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    int cur_sum = 0, str_sum = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cur_sum = max(cur_sum, curve_block(i, j));
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            str_sum = max(str_sum, straight_block(i, j));
        }
    }

    cout << max(cur_sum, str_sum);

    return 0;
}