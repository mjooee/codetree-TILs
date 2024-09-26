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
        int s = 1;
        int j = 0;
        while(sum < b && j < n)
        {
            if(j == i) 
            {
                j += 1;
                continue;
            }
            sum += students[j][0]; 
            if(sum < b) s++;
            j++;
        }

        if(s > maxval) maxval = s;
    }

    cout << maxval;

    return 0;
}