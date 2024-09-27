#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int x;
    cin >> x;

    int max_speed = 1;
    int total = 0;
    while(total < x)
    {
        total += max_speed;
        
        if(total + max_speed <= x)
        {
            max_speed++;
            total += max_speed;
        }
            
    }

    int time = 0;
    x -= total;
    time = max_speed * 2 -1;

    int speed = max_speed;

    while(x)
    {
        if(x - speed >= 0)
        {
            x -= speed;
            time += 1;
        }
        else speed -= 1;
    }

    cout << time;

    return 0;
}