#include <iostream>
using namespace std;

int arr[10][10] = {0};

int main() {
    // 여기에 코드를 작성해주세요.
    int r, c;
    cin >> r >> c;

    //W: 0, B: 1
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            char input;
            cin >> input;
            if(input == 'W') arr[i][j] = 0;
            else arr[i][j] = 1;
        }
    }

    int nowColor = arr[0][0];
    int cnt = 0;

    for(int i = 1; i < r-2; i++)
    {        
        for(int j = 1; j < c-2; j++)
        {
            if(arr[i][j] != nowColor && arr[i][j] == arr[r-1][c-1])
            {
                nowColor = arr[i][j];
                for(int k = i+1; k < r-1; k++)
                {
                    for(int l = j+1; l < c-1; l++)
                    {
                        if(arr[k][l] != nowColor && arr[k][l] != arr[r-1][c-1])
                        {
                            cnt++;
                        }
                    }
                }
            }
        }
    }

    cout << cnt;
    return 0;
}