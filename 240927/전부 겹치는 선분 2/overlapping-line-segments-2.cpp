#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    string ans = "No";

    int arr[101] = {0};

    for(int i = 1; i <= n; i++)
    {
        int x1, x2;
        cin >> x1 >> x2;
        for(int j = x1; j <= x2; j++)
        {
            arr[j]++;
        }
    }

    for(int i = 1; i < 101; i++)
    {
        if(arr[i] >= n-1)
        {
            ans = "Yes";
            break;
        }
    }

    cout << ans;
    return 0;
}