#include <iostream>
using namespace std;

#define SIZE 4

int arr[4][4] = {0};

void left_shift()
{
    for(int i = 0; i < SIZE; i++)
    {
        int idx = 0;
        for(int j = 0; j < SIZE; j++)
        {
            if(arr[i][j] == 0) continue;
            arr[i][idx] = arr[i][j];
            idx++;
        }
        for(int j = idx; j < SIZE; j++)
        {
            arr[i][j] = 0;
        }
    }
}

void up_shift()
{
    for(int j = 0; j < SIZE; j++)
    {
        int idx = 0;
        for(int i = 0; i < SIZE; i++)
        {
            if(arr[i][j] == 0) continue;
            arr[idx][j] = arr[i][j];
            idx++;
        }
        for(int i = idx; i < SIZE; i++)
        {
            arr[i][j] = 0;
        }
    }
}

void move_to_right()
{
    left_shift();
    for(int i = 0; i < SIZE; i++)
    {
        int idx = SIZE-1;
        for(int j = SIZE-1; j >= 0; j--)
        {
            if(arr[i][j] == 0) continue;
            if(j != 0 && arr[i][j] == arr[i][j-1])
            {
                arr[i][idx] = arr[i][j] + arr[i][j-1];
                j--;
            }
            else
            {
                arr[i][idx] = arr[i][j];
            }
            idx--;
        }
        for(int j = idx; j >= 0; j--)
        {
            arr[i][j] = 0;
        }
    }
}

void move_to_left()
{
    left_shift();
    for(int i = 0; i < SIZE; i++)
    {
        int idx = 0;
        for(int j = 0; j < SIZE; j++)
        {
            if(arr[i][j] == 0) continue;
            if(j != SIZE-1 && arr[i][j] == arr[i][j+1])
            {
                arr[i][idx] = arr[i][j] + arr[i][j+1];
                j++;
            }
            else
            {
                arr[i][idx] = arr[i][j];
            }
            idx++;
        }
        for(int j = idx; j < SIZE; j++)
        {
            arr[i][j] = 0;
        }
    }
}

void move_to_up()
{
    up_shift();
    for(int j = 0; j < SIZE; j++)
    {
        int idx = 0;
        for(int i = 0; i < SIZE; i++)
        {
            if(arr[i][j] == 0) continue;
            if(i != SIZE-1 && arr[i][j] == arr[i+1][j])
            {
                arr[idx][j] = arr[i][j] + arr[i+1][j];
                i++;
            }
            else
            {
                arr[idx][j] = arr[i][j];
            }
            idx++;
        }
        for(int i = idx; i < SIZE; i++)
        {
            arr[i][j] = 0;
        }
    }
}

void move_to_down()
{
    up_shift();
    for(int j = 0; j < SIZE; j++)
    {
        int idx = SIZE-1;
        int pre = 0;
        for(int i = SIZE-1; i >= 0; i--)
        {
            if(arr[i][j] == 0) continue;
            if(i != 0 && arr[i][j] == arr[i-1][j])
            {
                arr[idx][j] = arr[i][j] + arr[i-1][j];
                i--;
            }
            else
            {
                arr[idx][j] = arr[i][j];
            }
            idx--;
        }
        for(int i = idx; i >= 0; i--)
        {
            arr[i][j] = 0;
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            cin >> arr[i][j];
        }
    }

    char dir;
    cin >> dir;

    if(dir == 'L') move_to_left();
    else if(dir == 'R') move_to_right();
    else if(dir == 'U') move_to_up();
    else move_to_down();

    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}