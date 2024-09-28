#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    int arr[100001];
    cin >> n;
    for(int i = 1; i <= n * 2; i++)
    {
        cin >> arr[i];
    }

    sort(arr+1, arr + (n * 2)+1);
    int ans = 1000000000;

    for(int i = 1; i <= n; i++)
    {
        int gap = arr[i + n] - arr[i];
        if(gap < ans) ans = gap;
    }

    cout << ans;
    return 0;
}