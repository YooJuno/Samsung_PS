#include <iostream>

using namespace std;

/*
-1 : 블랙홀
0 : 빈공간
1 ~ 5 : 블록
6 ~ 10 : 웜홀(동일 숫자로 감)

종료 조건)
1. 블랙홀
2. 시작지점으로 회귀

점수 획득)
벽이나 블록에 박으면 +1

경우의 수)
- 모든 빈 공간에 대해 상,하,좌,우 의 경우 계산
*/

enum Direction
{
    LEFT,
    RIGHT,
    UP,
    DOWN,
    CENTER
};

void changeDirection(int *offsetY, int *offsetX, Direction direction)
{
    if (direction == UP)
    {
        *offsetY = -1;
        *offsetX = 0;
    }
    else if (direction == DOWN)
    {
        *offsetY = 1;
        *offsetX = 0;
    }
    else if (direction == LEFT)
    {
        *offsetY = 0;
        *offsetX = -1;
    }
    else if (direction == RIGHT)
    {
        *offsetY = 0;
        *offsetX = 1;
    }
}

int playPinballGame(int **board, int N, int srcY, int srcX, Direction currentDirection)
{
    auto direction = currentDirection;
    auto point = 0;
    auto y = srcY;
    auto x = srcX;
    int offsetY;
    int offsetX;

    while (true)
    {
        changeDirection(&offsetY, &offsetX, direction);
        y += offsetY;
        x += offsetX;

        // 점수 획득 조건 (1) 벽 부딪히기.
        if (x < 0 || x > N - 1 || y < 0 || y > N - 1)
        {
            if (y < 0)
                direction = DOWN;
            else if (y > N - 1)
                direction = UP;
            else if (x < 0)
                direction = RIGHT;
            else if (x > N - 1)
                direction = LEFT;

            point += 1;
        }
        // 종료조건 (1) (블랙홀)
        else if (x == srcX && y == srcY)
        {
            return point;
        }
        else
        {
            // 종료조건 (2) 블랙홀
            if (board[y][x] == -1)
            {
                return point;
            }

            // 점수 획득 조건 (2) 블록
            else if (1 <= board[y][x] && board[y][x] <= 5)
            {
                if (board[y][x] == 1)
                {
                    if (direction == UP)
                        direction = DOWN;
                    else if (direction == DOWN)
                        direction = RIGHT;
                    else if (direction == LEFT)
                        direction = UP;
                    else if (direction == RIGHT)
                        direction = LEFT;
                }
                else if (board[y][x] == 2)
                {
                    if (direction == UP)
                        direction = RIGHT;
                    else if (direction == DOWN)
                        direction = UP;
                    else if (direction == LEFT)
                        direction = DOWN;
                    else if (direction == RIGHT)
                        direction = LEFT;
                }
                else if (board[y][x] == 3)
                {
                    if (direction == UP)
                        direction = LEFT;
                    else if (direction == DOWN)
                        direction = UP;
                    else if (direction == LEFT)
                        direction = RIGHT;
                    else if (direction == RIGHT)
                        direction = DOWN;
                }
                else if (board[y][x] == 4)
                {
                    if (direction == UP)
                        direction = DOWN;
                    else if (direction == DOWN)
                        direction = LEFT;
                    else if (direction == LEFT)
                        direction = RIGHT;
                    else if (direction == RIGHT)
                        direction = UP;
                }
                else
                {
                    if (direction == UP)
                        direction = DOWN;
                    else if (direction == DOWN)
                        direction = UP;
                    else if (direction == LEFT)
                        direction = RIGHT;
                    else if (direction == RIGHT)
                        direction = LEFT;
                }

                point += 1;
            }

            // 웜홀 - 숫자가 같은 다른 웜홀로 이동. 진행 방향 유지
            else if (6 <= board[y][x] && board[y][x] <= 10)
            {
                auto isFound = false;
                for (auto i = 0; i < N; i++)
                {
                    for (int j = 0; j < N; j++)
                    {
                        if ((i != y || j != x) && (board[y][x] == board[i][j]))
                        {
                            y = i;
                            x = j;
                            isFound = true;
                            break;
                        }
                    }

                    if (isFound) break;
                }
            }
        }
    }
}

int main()
{
    freopen("sample_input.txt", "r", stdin);

    int T;
    cin >> T;

    for (auto test_case = 1; test_case <= T; test_case++)
    {
        auto max_point = 0;

        int N;
        cin >> N;

        auto board = new int *[N];

        for (auto i = 0; i < N; i++)
        {
            board[i] = new int[N];
            for (auto j = 0; j < N; j++)
                cin >> board[i][j];
        }

        for (auto i = 0; i < N; i++)
        {
            for (auto j = 0; j < N; j++)
            {
                if (board[i][j] == 0)
                {
                    for(auto k=0; k<4; k++)
                    {
                        auto point = playPinballGame(board, N, i, j, (Direction)k);
                        if (point > max_point) 
                            max_point = point;
                    }
                }                
            }
        }

        cout << "#" << test_case << " " << max_point << endl;
    }

    return 0;
}