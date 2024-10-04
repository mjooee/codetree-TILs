#include <iostream>
#include <stack>
using namespace std;

stack<int> s;

int pops()
{
    int last = s.top();
    s.pop();
    return last;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        string input;
        cin >> input;

        if(input == "push")
        {
            int num;
            cin >> num;
            s.push(num);
        }
        else if(input == "size")
        {
            cout << s.size() << endl;
        }
        else if(input == "empty")
        {
            if(s.empty()) cout << 1 << endl;
            else cout << 0 << endl;
        }
        else if(input == "top")
        {
            cout << s.top();
        }
        else{
            int last = pops();
            cout << last << endl;;
        }
    }
    return 0;
}