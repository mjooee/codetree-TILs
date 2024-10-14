#include <iostream>
using namespace std;

int howmany(int arr[20][20], int starti, int startj)
{
    int sum = 0;
    for(int i = starti; i < starti + 3; i++)
    {
        for(int j = startj; j < startj + 3; j++)
        {
            sum += arr[i][j];
        }
    }
    return sum;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    int arr[20][20];
    cin >> n;

    for(int i = 0; i < n ;i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    int answer = 0;

    for(int i = 0; i < n-3+1; i++)
    {
        for(int j = 0; j < n-3+1; j++)
        {
            int newsum = howmany(arr, i, j);
            if(newsum > answer) answer = newsum;
        }
    }
    cout << answer;
    return 0;
}