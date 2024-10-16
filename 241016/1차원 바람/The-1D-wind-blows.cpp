#include <iostream>
using namespace std;

#define MAX_NUM 100

int arr[MAX_NUM][MAX_NUM];

int n, m;

bool is_wind(int row, int next_row)
{
    for(int i = 0; i < m; i++)
    {
        if(arr[row][i] == arr[next_row][i])
        {
            return true;
        }
    }
    return false;
}

void left_wind(int row)
{
    int temp = arr[row][m-1];
    for(int i = m-2; i >= 0; i--)
    {
        arr[row][i+1] = arr[row][i];
    }
    arr[row][0] = temp;
}

void right_wind(int row)
{
    int temp = arr[row][0];
    for(int i = 1; i < m; i++)
    {
        arr[row][i-1] = arr[row][i];
    }
    arr[row][m-1] = temp;
}

void wind(int dir, int row)
{
    int next_dir = dir;

    for(int i = row; i < n; i++)
    {
        if(next_dir)
        {
            left_wind(i);
            next_dir = 0;
        }
        else
        {
            right_wind(i);
            next_dir = 1;
        }
        if(i != n-1 && !is_wind(i, i+1)) 
        {
            break;
        }
    }
    
    next_dir = dir;

    for(int i = row-1; i >= 0; i--)
    {
        if(!is_wind(i+1, i)) break;
        if(!next_dir)
        {
            left_wind(i);
            next_dir = 1;
        }
        else
        {
            right_wind(i);
            next_dir = 0;
        }
        
    }
}


int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    int q;
    cin >> q;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    while(q--)
    {
        int r;
        char d;
        cin >> r >> d;
        r--;

        if(d == 'L') wind(1, r);
        else wind(0, r);
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