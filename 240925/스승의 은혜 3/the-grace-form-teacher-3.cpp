#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, b;
    int students[1000][2];
    int price[1000];
    cin >> n >> b;
    for(int i = 0; i < n; i++)
    {
        cin >> students[i][0] >> students[i][1];
        price[i] = students[i][0] + students[i][1];
    }

    sort(price, price + n);

    int max = 0;
    for(int i = 0 ; i < n; i++)
    {
        int sum = students[i][0] / 2 + students[i][1];
        int s = 0, people = 1;
        while(sum < b && s < n)
        {
            s+= 1;
            if (s == i) continue;
            sum += price[s];
            people += 1;
 
        }

        if(people > max) max = people;
    }

    cout << max;


    return 0;
}