#include <iostream>
#include <climits>
#
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int members[5] = {0};
    int all = 0;
    for(int i=0; i < 5; i++)
    {
        cin >> members[i];
        all += members[i];
    }

    int team1, team2, team3;
    int minVal = INT_MAX;
    int ans = -1;
    for(int i = 0; i < 5; i++)
    {
        team1 = members[i];
        //각 팀 능력 구하기
        for(int j = 0; j < 5; j++)
        {
            if(i == j) continue;
            for(int k = 0; k < 5; k++)
            {
                if(k == i || k == j) continue;
                team2 = members[j] + members[k];
                team3 = all - team1 - team2;
                if(team1 == team2 || team2 == team3 || team1 == team3) continue;
                int val = max(team1, max(team2, team3)) - min(team1, min(team2, team3));
                if(val < minVal) minVal = val;
            }
        }
    
    }

    if(minVal != INT_MAX) ans = minVal;
    cout << ans;
    
    return 0;
}