#include <iostream>
using namespace std;

#define MAX_N 200
int main() {
    // 여기에 코드를 작성해주세요.
    int arr[MAX_N * 2];
    int n, t;
    cin >> n >> t;

    for(int i = 0; i < 2* n; i++)
    {
        cin >> arr[i];
    }

    for(int i = 0; i < t; i++)
    {
        int temp = arr[2*n-1];
        for(int j = 2*n-2; j >= 0 ;j--)
        {
            arr[j+1] = arr[j];
        }
        arr[0] = temp;
    }

    for(int i = 0; i < 2*n; i++)
    {
        cout << arr[i] << " ";
        if(i == n-1) cout << endl;
    }
    return 0;
}