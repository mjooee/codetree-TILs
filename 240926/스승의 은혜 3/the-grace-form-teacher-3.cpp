#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, b;
    cin >> n >> b;
    vector<vector<int>> students;
    for(int i = 0; i < n; i++)
    {
        students.push_back(vector<int>(2));
        int p1, p2;
        cin >> p1 >> p2;
        students[i][0] = p1 + p2;
        students[i][1] = p1/2 + p2;
    }

    sort(students.begin(), students.end());

    int maxval = 0;

    for(int i=0; i < n; i++)
    {
        int sum = students[i][1];
        int s = 0;
        while(sum < b)
        {
            s += 1;
            if(s == i) continue;
            sum += students[s][0]; 
        }
        if(s > maxval) maxval = s;
    }

    cout << maxval;

    return 0;
}