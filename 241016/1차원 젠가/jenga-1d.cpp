#include <iostream>
using namespace std;

#define MAX_N 100

int n;
int arr[MAX_N];

int remove(int start, int end)
{
    int temp_arr[MAX_N];
    int temp_idx = 0;
    for(int i = 0; i < start; i++)
    {
        temp_arr[temp_idx] = arr[i];
        temp_idx++;
    }
    for(int i = end+1; i < n; i++)
    {
        temp_arr[temp_idx] = arr[i];
        temp_idx++;
    }

    for(int i = 0; i< temp_idx; i++)
    {
        arr[i] = temp_arr[i];
    }
    return temp_idx;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for(int i = 0; i < 2; i++)
    {
        int s, e;
        cin >> s >> e;
        n = remove(s-1, e-1);
    }

    cout << n << endl;
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}