#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int x;
    cin >> x;

    int max_speed = 0;
    int total = 0;

    while(total < x)
    {
        if(total + (max_speed * 2 + 1) <= x)
        {
            total += max_speed;
            max_speed++;
            total += max_speed;
        }
        else break;
    }

    int time = 0;
    x -= total;
    time = max_speed * 2 -1;

    int speed = max_speed;

    while(x && speed)
    {
        if(x - speed >= 0)
        {
            x -= speed;
            time++;
        }
        else speed -= 1;
    }

    cout << time;

    return 0;
}