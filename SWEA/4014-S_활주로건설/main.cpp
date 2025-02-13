#include <iostream>
#include <cstring>
using namespace std;

auto main() -> int
{
    // freopen("sample_input.txt", "r", stdin);

    int T; cin >> T;
    for(auto test_case=1; test_case<=T; test_case++)
    {
        int result = 0;
        int N; cin >> N; // 가로, 세로 길이 6 ~ 20
        int X; cin >> X; // 경사로 길이 2 ~ 4
        int map[N][N];
        for(auto i = 0; i < N; i++)
        {
            for(auto j = 0; j < N; j++)
            {
                cin >> map[i][j];
            }
        }

        // 한 줄 씩 넣으면 될 듯.
        // 2 이상 차이 나면 바로 짤
            // 계속 비교하면서 가야함.
        // 진행 방향에서 1차이나는 높은 땅을 만나면
            // 현재 인덱스-X부터 현재까지 높이가 같은지 확인해야함.
            // 처음 값이랑 그 이후의 값을 계속 비교해가면서 해야함.
            // flag도 하나 두고
        // 진행 방향에서 1차이나는 낮은 땅을 만나면
            // 낮은 땅부터 X만큼 루프 돌림
        // 루프 돌릴 때는 가로 세로 길이 고려해서 가지 칠건 쳐야함

        for(auto i = 0; i < N; i++)
        {
            int j;
            bool visited[N];
            memset(visited, 0, sizeof(visited));
            bool isPossible = true;
            for(j = 0; j < N-1; j++)
            {
                // 너무 차이가 커서 탈락
                if(abs(map[i][j]-map[i][j+1]) > 1)
                {
                    break;
                }
                // 오르막길
                else if(map[i][j]-map[i][j+1] == -1)
                {
                    if(j+1 < X) break;
                    
                    for(auto k = j; k > j-X+1; k--)
                    {

                        if(map[i][k] != map[i][k-1] || visited[k]) 
                        {
                            isPossible = false;
                            break;
                        }
                        else
                        {
                            visited[k] = true;
                        }
                    }
                    if(!isPossible || visited[j-X+1]) break;
                    
                }
                // 내리막길
                else if(map[i][j]-map[i][j+1] == 1)
                {
                    if(N-1 < X+j) break;
                    for(auto k = j+1; k < j+X; k++)
                    {
                        if(map[i][k] != map[i][k+1]) 
                        {
                            isPossible = false;
                            break;
                        }
                        else
                        {
                            visited[k] = true;
                            visited[k+1] = true;
                        }
                    }
                    if(!isPossible) break;
                }
            }
            if(j == N-1) 
            {
                result++;
            }

            memset(visited, 0, sizeof(visited));
            isPossible = true;
            for(j = 0; j < N-1; j++)
            {
                if(abs(map[j][i]-map[j+1][i]) > 1)
                {
                    break;
                }
                // 오르막길
                else if(map[j][i]-map[j+1][i] == -1)
                {
                    if(j+1 < X) break;

                    for(auto k = j; k > j-X+1; k--)
                    {
                        if(map[k][i] != map[k-1][i] || visited[k]) 
                        {
                            isPossible = false;
                            break;
                        }
                        else
                        {
                            visited[k] = true;
                        }
                    }
                    if(!isPossible || visited[j-X+1]) break;
                }
                // 내리막길
                else if(map[j][i]-map[j+1][i] == 1)
                {
                    if(N-1 < X+j) break;
                    for(auto k = j+1; k < j+X; k++)
                    {
                        if(map[k][i] != map[k+1][i]) 
                        {
                            isPossible = false;
                            break;
                        }
                        else
                        {
                            visited[k] = true;
                            visited[k+1] = true;
                        }
                    }
                    if(!isPossible) break;
                }
            }
            if(j == N-1) 
            {
                result++;
            }
        }

        
        cout << '#' << test_case << ' ' << result << endl;
    }
    return 0;
}