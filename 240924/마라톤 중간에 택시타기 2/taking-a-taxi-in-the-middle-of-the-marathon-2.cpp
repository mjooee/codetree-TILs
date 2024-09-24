#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int check[100][2];

int mDis(int x1, int y1, int x2, int y2)
{
    return abs(x1-x2) + abs(y1-y2);
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> check[i][0] >> check[i][1];
    }

    int min = INT_MAX;

    for(int i = 1; i < n-1; i++)
    {
        //거리 구하기
        int sum = 0;
        for(int j = 1; j < n; j++)
        {
            int pre = j-1;
            if(i == j) continue;            
            else if(i == j-1)
            {
                pre -= 1;
            }
            sum += mDis(check[j][0], check[j][1], check[pre][0], check[pre][1]);
        }
        
        if(min > sum) min = sum;
    }

    cout << min;
    return 0;
}