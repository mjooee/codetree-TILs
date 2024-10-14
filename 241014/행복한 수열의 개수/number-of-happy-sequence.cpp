#include <iostream>
using namespace std;

#define max_n 100

int arr[max_n][max_n];

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    int answer = 0;
    int little_m = 0;
    int num = 0;
    for(int i = 0; i < n; i++)
    {
        little_m = 0;
        for(int j = 0; j < n ;j++)
        {
            if(little_m >= m) break;
            if(arr[i][j] == num)
            {
                little_m++;
            }
            else
            {
                num = arr[i][j];
                little_m = 1;
            }
        }
        if(little_m >= m) answer++;
    }

    num = 0;
    for(int i = 0; i < n; i++)
    {
        little_m = 0;
        for(int j = 0; j < n ;j++)
        {
            if(little_m >= m) break;
            if(arr[j][i] == num)
            {
                little_m++;
            }
            else
            {
                num = arr[j][i];
                little_m = 1;
            }
        }
        if(little_m >= m) answer++;
    }
    cout << answer;

    return 0;
}