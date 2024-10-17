#include <iostream>
using namespace std;

#define MAX_NUM 100

int n, m;
int arr[MAX_NUM];

void print_bomb()
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}

bool is_boom()
{
    //연속해서 폭탄 있는 지 검사
    int pre_bomb = 0;
    int cnt = 1;
    for(int i = 0; i < n; i++)
    {
        if(cnt >= m) return true;
        int now_bomb = arr[i];
        if(pre_bomb != now_bomb)
        {
            pre_bomb = now_bomb;
            cnt = 1;
        }
        else
        {
            cnt++;
            if(cnt >= m) return true;
        }
    }
    return false;
}

void boom()
{
    //연속한 폭탄 0으로 대체
    int cnt = 1;
    int pre_bomb = 0;

    for(int i = 1; i <= n; i++)
    {
        if(arr[pre_bomb] != arr[i] || i == n)
        {
            if(cnt >= m)
            {
                for(int idx = pre_bomb; idx < i; idx++)
                {
                    arr[idx] = 0;
                }
            }
            cnt = 1;
            pre_bomb = i;
        }
        else cnt++;
    }

    //새 배열에 옮겨서 중력적용
    int new_arr[MAX_NUM];
    int new_n = 0;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] != 0)
        {
            new_arr[new_n] = arr[i];
            new_n++;
        }
    }
    n = new_n;

    for(int i = 0; i < n; i++)
    {
        arr[i] = new_arr[i];
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    while(is_boom())
    {
        boom();
    }

    cout << n << endl;

    print_bomb();

    return 0;
}