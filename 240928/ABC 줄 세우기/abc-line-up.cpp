#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    char arr[26];
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int cnt = 0;

    for(int j = 0; j < n -1; j++)
    {
        for(int i = 0; i < n - j - 1; i++)
        {
            if(arr[i] > arr[i+1])
            {
                char tmp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = tmp;
                cnt++;
            }
        }
    }

    cout << cnt;
    
    return 0;
}