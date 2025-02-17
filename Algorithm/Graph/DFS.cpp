#include <iostream>

using namespace std;

/*

Depth-First Search

깊이 갈 수 있는데까지 간다.
1. 모든 경우를 다 둘러봐야할 때 사용함.
    - 해결을 위해 재귀 사용?(언제 끝날지 모르니까 사용)
    - 재귀는 조건 만족하면 끝내버림
2. 
*/

int nodeCnt;
int arr[1001][1001];
int st, en;
bool visited[1001];


int func(int now, int cnt)
{
    if(now == en)
    {
        return cnt;
    }
    int maxCnt = 0;
    for(auto i = 0; i < nodeCnt; i++)
    {
        if(visited[i] == true)
            continue;
        if(arr[now][i] == 0)
            continue;

        visited[i] = true;

        int result = func(i, cnt + 1);
        if(result > maxCnt)
        {
            maxCnt = result;
        }

        visited[i] = false;
    }

    return maxCnt;
}

auto main() -> int
{
    cin >> nodeCnt;

    for(auto i = 0; i < nodeCnt; i++)
    {
        for(auto j = 0; j < nodeCnt; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    cin >> st >> en;
    visited[st] = true;
    cout << func(st, 1);
    return 0;
}