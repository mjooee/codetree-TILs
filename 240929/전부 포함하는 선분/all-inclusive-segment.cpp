#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    int x1[100];
    int x2[100];

    for(int i = 0; i < n; i++)
    {
        cin >> x1[i] >> x2[i];
    }

    int ans = 1000;
    for(int i = 0; i < n; i++)
    {
        int min = 100;
        int max = 0;
        for(int j = 0; j < n ;j++)
        {
            if(i == j) continue;
            if(x1[j] < min) min = x1[j];
            if(x2[j] > max) max = x2[j];
        }
        if(max - min < ans) ans = max - min;
    }

    cout << ans;
    
    return 0;
}