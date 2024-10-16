#include <iostream>
using namespace std;

#define MAX_N 200

int main() {
    // 여기에 코드를 작성해주세요.
    int n, t;
    cin >> n >> t;

    int num1[MAX_N], num2[MAX_N], num3[MAX_N];

    for(int i = 0; i < n; i++)
    {
        cin >> num1[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> num2[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> num3[i];
    }

    while(t--)
    {
        int temp = num3[n-1];

        for(int i = n-2; i >= 0; i--)
        {
            num3[i+1] = num3[i];
        }

        num3[0] = num2[n-1];

        for(int i = n-2; i >= 0; i--)
        {
            num2[i+1] = num2[i];
        }

        num2[0] = num1[n-1];

        for(int i = n-2; i >= 0; i--)
        {
            num1[i+1] = num1[i];
        }

        num1[0] = temp;

    }

    for(int i = 0; i < n; i++)
    {
        cout << num1[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < n; i++)
    {
        cout << num2[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < n; i++)
    {
        cout << num3[i] << " ";
    }
    cout << endl;

    return 0;
}