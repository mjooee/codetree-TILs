#include <iostream>
using namespace std;

int arr[20][20];
int check[20][20];
int n, m;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void init()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            check[i][j] = 0;
        }
    }
}

int get_cost(int k)
{
    return k * k + (k+1) * (k+1);
}

bool is_safe(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < n;
}

int get_gold(int x, int y, int k)
{
    if(k < 0) return 0;
    if(!is_safe(x, y)) return 0;

    int golds;
    if(check[x][y]) golds = 0;
    else
    {
        check[x][y] = 1;
        golds = arr[x][y];
    }

    for(int i = 0; i < 4; i++)
    {
        golds += get_gold(x+dx[i], y+dy[i], k-1);
    }
    return golds;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    int answer = 0;

    init();

    for(int k = 0; k < n*2; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int golds = get_gold(i, j, k);
                int income = m * golds - get_cost(k);
                if(income >= 0 && answer < golds) 
                {
                    answer = golds;

                }
                init();
            }
            
        }
    }

    cout << answer;

    return 0;
}