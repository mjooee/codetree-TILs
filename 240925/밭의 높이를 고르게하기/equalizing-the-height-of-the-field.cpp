#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int arr[100];

int main() {
    // 여기에 코드를 작성해주세요.
    int n, h, t;
    int min = INT_MAX;
    cin >> n >> h >> t;

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for(int i=0; i < n-t+1; i++)
    {
        int sum = 0;
        for(int j=i; j < i+t; j++)
        {
            sum += abs(h-arr[j]);
        }
        if(min > sum) min = sum;
    }

    cout << min;
    return 0;
}