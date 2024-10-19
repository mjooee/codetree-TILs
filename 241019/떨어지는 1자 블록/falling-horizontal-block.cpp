#include <iostream>
using namespace std;

#define MAX_N 100

int arr[MAX_N][MAX_N] = {0};
int n, m, k;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m >> k;
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n ;j++)
        {
            cin >> arr[i][j];
        }
    }

    bool is_block = false;
    int floor = 0;

    for(int i = 1; i < n; i++)
    {
        for(int j = k-1; j < k + m -1; j++)
        {
            if(arr[i][j])
            {
                is_block = true;
                break;
            }
        }
        if(is_block) break;
        floor++;
    }

    for(int j = k-1; j < k + m - 1; j++)
    {
        arr[floor][j] = 1;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n ;j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}