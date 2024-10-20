#include <iostream>
using namespace std;

#define MAX_N 100

int arr[MAX_N][MAX_N];
int n;

//상하좌우
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int dice_arr[4] = {5, 2, 4, 3};

bool is_safe(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < n;
}

int init_dice(int dir, int dice)
{
    int new_dice = dice_arr[dir];

    if(dir == 0)
    {
        dice_arr[0] = 7 - dice;
        dice_arr[1] = dice;
    }
    else if(dir == 1)
    {
        dice_arr[0] = dice;
        dice_arr[1] = 7 - dice;
    }
    else if(dir == 2)
    {
        dice_arr[2] = 7 - dice;
        dice_arr[3] = dice;
    }
    else
    {
        dice_arr[2] = dice;
        dice_arr[3] = 7 - dice;
    }

    return new_dice;
}

int all_sum()
{
    int sum;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            sum += arr[i][j];
        }
    }
    return sum;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int m, r, c;
    cin >> n >> m >> r >> c;

    r -= 1;
    c -= 1;

    int dice = 6;
    int dir = 0;

    arr[r][c] = dice;

    while(m--)
    {
        //방향 입력
        char dir_char;
        cin >> dir_char;
        if(dir_char == 'U') dir = 0;
        else if(dir_char == 'D') dir = 1;
        else if(dir_char == 'L') dir = 2;
        else dir = 3;

        //이동
        r += dx[dir];
        c += dy[dir];

        if(!is_safe(r, c))
        {
            r -= dx[dir];
            c -= dy[dir];
            continue;
        }

        //주사위 숫자 계산
        dice = init_dice(dir, dice);

        //격자판 위에 주사위 숫자 새기기
        arr[r][c] = dice;
    }

    cout << all_sum();
    cout << endl;


    
    return 0;
}