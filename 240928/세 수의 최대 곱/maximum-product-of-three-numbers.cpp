#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    int arr[100000];
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int maxval = INT_MIN;

    sort(arr, arr+n);

    if(arr[1] >= 0)
    {
        maxval = arr[n-1] * arr[n-2] * arr[n-3];
    }
    else
    {
        if(arr[n-1] <= 0) maxval = arr[n-1] * arr[n-2] * arr[n-3];
        else
        {
            maxval = max(arr[n-1] * arr[0] * arr[1], arr[n-1] * arr[n-2] * arr[n-3]);
        }
    }

    cout << maxval;

    return 0;
}