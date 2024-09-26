#include <iostream>
#include <string>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int x, y;
    cin >> x >> y;

    int ans = 0;
    for(int i = x; i <= y; i++)
    {
        string number = to_string(i);
        int n = number.size() / 2;
        bool is = true;
        for(int j = 0; j < n; j++)
        {
            if(number[j] != number[number.size()-j-1])
            {
                is = false;
                break;
            }
        }
        if(is)
        {
            ans++;
        }
    }

    cout << ans;

    return 0;
}