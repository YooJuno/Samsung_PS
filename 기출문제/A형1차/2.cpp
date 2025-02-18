#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

/*
일단 트리임
그래프 문제. DFS 같기도
Direction이 있음
*/

int N; // 2 <= N <= 500
int M; // 0 <= M <= N*(N-1)/2;
bool graph[501][501];
bool isVisited[501];
int cntVisited;

void DFS_Front(int idx)
{
	cntVisited++;
	for (int i = 0; i < N; i++)
	{
		if (isVisited[i] == true || idx == i) 
			continue;

		if (graph[idx][i] == true)
		{
			isVisited[i] = true;
			DFS_Front(i);
		}
	}
}

void DFS_Back(int idx)
{
	cntVisited++;
	for (int i = 0; i < N; i++)
	{
		if (isVisited[i] == true || idx == i) 
			continue;

		if (graph[i][idx] == true)
		{
			isVisited[i] = true;
			DFS_Back(i);
		}
	}
}

int main()
{
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; test_case++)
	{
		int result = 0;

		memset(graph, false, sizeof(graph));
		cin >> N;
		cin >> M;

		for (int i = 0; i < M; i++)
		{
			int a, b;
			cin >> a >> b;
			graph[a-1][b-1] = true;
		}

		for (int i = 0; i < N; i++)
		{
			memset(isVisited, false, sizeof(isVisited));
			cntVisited = 0;

			isVisited[i] == true;
			DFS_Front(i);
			DFS_Back(i);
			
			if (cntVisited == N + 1) result++;
		}

		cout << '#' << test_case << ' ' << result << endl;
	}

	return 0;
}
