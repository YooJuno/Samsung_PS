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

void changeDirection(int *offset_x, int *offset_y, Direction direction)
{
    if (direction == UP)
    {
        *offset_y = -1;
        *offset_x = 0;
    }
    else if (direction == DOWN)
    {
        *offset_y = 1;
        *offset_x = 0;
    }
    else if (direction == LEFT)
    {
        *offset_y = 0;
        *offset_x = -1;
    }
    else if (direction == RIGHT)
    {
        *offset_y = 0;
        *offset_x = 1;
    }
}

int playPinballGame(int **board, int N, int src_x, int src_y, Direction currentDirection)
{
    Direction direction = currentDirection;

    int point = 0;

    int y = src_y;
    int x = src_x;
    int offset_y, offset_x;
    changeDirection(&offset_x, &offset_y, direction);
    y += offset_y;
    x += offset_x;
    while (true)
    {
        if (x < 0 || x > N - 1 || y < 0 || y > N - 1)
        {
            if (y < 0)
            {
                direction = DOWN;
                changeDirection(&offset_x, &offset_y, direction);
            }
            else if (y > N - 1)
            {
                direction = UP;
                changeDirection(&offset_x, &offset_y, direction);
            }
            else if (x < 0)
            {
                direction = RIGHT;
                changeDirection(&offset_x, &offset_y, direction);
            }
            else if (x > N - 1)
            {
                direction = LEFT;
                changeDirection(&offset_x, &offset_y, direction);
            }
            point += 1;
            x += offset_x;
            y += offset_y;
        }
        else if (x == src_x && y == src_y)
        {
            return point;
        }
        else{
            // 종료조건 (1) (블랙홀)
            if (board[y][x] == -1)
            {
                return point;
            }
            // 빈공간
            else if (board[y][x] == 0)
            {
                y += offset_y;
                x += offset_x;
            }

            // 점수 획득 조건 (1) 블록
            else if (1 <= board[y][x] && board[y][x] <= 5)
            {
                if (board[y][x] == 1)
                {
                    if (direction == UP)
                    {
                        direction = DOWN;
                        changeDirection(&offset_x, &offset_y, direction);
                    }
                    else if (direction == DOWN)
                    {
                        direction = RIGHT;
                        changeDirection(&offset_x, &offset_y, direction);
                    }
                    else if (direction == LEFT)
                    {
                        direction = UP;
                        changeDirection(&offset_x, &offset_y, direction);
                    }
                    else if (direction == RIGHT)
                    {
                        direction = LEFT;
                        changeDirection(&offset_x, &offset_y, direction);
                    }
                }
                else if (board[y][x] == 2)
                {
                    if (direction == UP)
                    {
                        direction = RIGHT;
                        changeDirection(&offset_x, &offset_y, direction);
                    }
                    else if (direction == DOWN)
                    {
                        direction = UP;
                        changeDirection(&offset_x, &offset_y, direction);
                    }
                    else if (direction == LEFT)
                    {
                        direction = DOWN;
                        changeDirection(&offset_x, &offset_y, direction);
                    }
                    else if (direction == RIGHT)
                    {
                        direction = LEFT;
                        changeDirection(&offset_x, &offset_y, direction);
                    }
                }
                else if (board[y][x] == 3)
                {
                    if (direction == UP)
                    {
                        direction = LEFT;
                        changeDirection(&offset_x, &offset_y, direction);
                    }
                    else if (direction == DOWN)
                    {
                        direction = UP;
                        changeDirection(&offset_x, &offset_y, direction);
                    }
                    else if (direction == LEFT)
                    {
                        direction = RIGHT;
                        changeDirection(&offset_x, &offset_y, direction);
                    }
                    else if (direction == RIGHT)
                    {
                        direction = DOWN;
                        changeDirection(&offset_x, &offset_y, direction);
                    }
                }
                else if (board[y][x] == 4)
                {
                    if (direction == UP)
                    {
                        direction = DOWN;
                        changeDirection(&offset_x, &offset_y, direction);
                    }
                    else if (direction == DOWN)
                    {
                        direction = LEFT;
                        changeDirection(&offset_x, &offset_y, direction);
                    }
                    else if (direction == LEFT)
                    {
                        direction = RIGHT;
                        changeDirection(&offset_x, &offset_y, direction);
                    }
                    else if (direction == RIGHT)
                    {
                        direction = UP;
                        changeDirection(&offset_x, &offset_y, direction);
                    }
                }
                else
                {
                    if (direction == UP)
                    {
                        direction = DOWN;
                        changeDirection(&offset_x, &offset_y, direction);
                    }
                    else if (direction == DOWN)
                    {
                        direction = UP;
                        changeDirection(&offset_x, &offset_y, direction);
                    }
                    else if (direction == LEFT)
                    {
                        direction = RIGHT;
                        changeDirection(&offset_x, &offset_y, direction);
                    }
                    else if (direction == RIGHT)
                    {
                        direction = LEFT;
                        changeDirection(&offset_x, &offset_y, direction);
                    }
                }
                y += offset_y;
                x += offset_x;
                ++point;
            }
            // 웜홀 - 숫자가 같은 다른 웜홀로 이동. 진행 방향 유지
            else if (6 <= board[y][x] && board[y][x] <= 10)
            {   
                int flag = false;
                for (int i = 0; i < N; i++)
                {
                    for (int j = 0; j < N; j++)
                    {
                        if ((i != y || j != x) && (board[y][x] == board[i][j]))
                        {
                            cout << "[" << i << ", " << j << "]\n";
                            y = i + offset_y;
                            x = j + offset_x;
                            flag=true;
                            break;
                        }
                    }
                    if(flag) break;
                }
            }
        }
    }
}

int main()
{
    int T;
    cin >> T;

    for (auto test_case = 1; test_case <= T; test_case++)
    {
        int max_point = -1;

        int N;
        cin >> N;

        int **board = new int *[N];
        ;
        for (auto i = 0; i < N; i++)
        {
            board[i] = new int[N];
            for (auto j = 0; j < N; j++)
            {
                cin >> board[i][j];
            }
        }

        for (auto i = 0; i < N; i++)
        {
            for (auto j = 0; j < N; j++)
            {
                if (board[i][j] == 0)
                {
                    int point = 0;
                    Direction currentDirection = LEFT;
                    while (currentDirection != CENTER)
                    {
                        switch (currentDirection)
                        {
                        case LEFT:
                            point = playPinballGame(board, N, j, i, currentDirection);
                            currentDirection = RIGHT;
                            break;

                        case RIGHT:
                            point = playPinballGame(board, N, j, i, currentDirection);
                            currentDirection = UP;
                            break;

                        case UP:
                            point = playPinballGame(board, N, j, i, currentDirection);
                            currentDirection = DOWN;
                            break;

                        case DOWN:
                            point = playPinballGame(board, N, j, i, currentDirection);
                            currentDirection = CENTER;
                            break;
                        }
                    }

                    if (point > max_point)
                    {
                        max_point = point;
                    }
                }
            }
        }

        cout << "#" << test_case << " " << max_point << endl;
    }

    return 0;
}