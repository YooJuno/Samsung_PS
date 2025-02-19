#include <iostream>
#include <deque>
#include <cstring>

using namespace std;

bool isVisited[11];
int graph[11][11];
int N, M, K;


void BFS(int cur)
{
    deque<int> dq;
    int sum = 0;
    isVisited[cur] = true;
    dq.push_back(cur);
    while(!dq.empty())
    {
        int now = dq.front();
        dq.pop_front();
        
        for(auto i = 0; i < N; i++)
        {
            if(isVisited[i] == true) continue;
            if(K < sum + graph[now][i]) continue;
            
            sum += graph[now][i];
            isVisited[i] = true;
            cout << i << ' ';
            dq.push_back(i);
            sum -= graph[now][i];
        }
    }
    free(dq);
}

auto main() -> int
{
    memset(isVisited, 0, sizeof(isVisited));
    memset(graph, 0, sizeof(graph));
    cin >> N >> M >> K;

    for(auto i = 0; i < M; i++)
    {
        int a, b, c; cin >> a >> b >> c;
        graph[a][b] = c;
        graph[b][a] = c;
    }

    BFS(0);
    
    return 0;
}