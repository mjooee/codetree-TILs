#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, k;
    cin >> n >> k;
    int arr[100];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr+n);

    int ans = INT_MAX;

    int gap = arr[n-1] - arr[0];
    if(gap > k) 
    {
        for(int i = 0; i < gap - k; i++)
        {
            int cnt = 0;
            int max = arr[n-1] - i;
            int min = arr[0] + gap - i - k;
            cnt += i;
            cnt += gap - i-k;
            for(int j = 1; j < n-1; j++)
            {
                if(arr[j] > max)
                {
                    cnt += arr[j] - max;
                }
                else if(arr[j] < min)
                {
                    cnt += min - arr[j];
                }
            }
            if(cnt < ans) ans = cnt;
        }
    }
    if(ans == INT_MAX) ans = 0;
    cout << ans;

    return 0;
}