#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;

    int arr[101];

    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    int max = 0;

    for(int i = 1; i <= n; i++)
    {
        int now = i;
        int sum = 0; 
        for(int j = 0; j < m; j++)
        {
            sum += arr[now];
            now = arr[now];
        }

        if(sum > max) max = sum;
    }
    cout << max;
    return 0;
}