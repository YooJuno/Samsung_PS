#include <iostream>

using namespace std;

/*
[ Union Find ]
- key, value 관점에서 value가 같은 key 끼리 하나의 집합으로 만드는 개념임
- 각 각의 key는 parent 정보를 함께 포함한다.
- value가 같은 key들은 작은 숫자의 key에 해당하는 parent에 묶이게 됨.
parent : 1 1 3 3 3 6 6 6 9 9
key    : 1 2 3 4 5 6 7 8 9 10
value  : 1 1 2 2 2 3 3 3 4 4
*/

int parent[10];
int birthdays[10] = { 8, 2, 2, 8, 3, 3, 12, 12, 6, 8 };

int find(int target)
{
    // 타겟이 자신의 집합에 속해 있다면(자신이 부모집합)
    if (target == parent[target])
        // 그냥 자기 번호 리턴
        return target;

    // 루트 노드를 찾아 여행을 떠남
    return find(parent[target]);
}

// a < b 
void setUnion(int a, int b)
{
    // a, b가 각 각 속한 집합을 리턴
    int t1 = find(a);
    int t2 = find(b);

    // 같은 집합에 속해 있다면 뭐 더 할 필요 없으니 리턴
    if (t1 == t2)
        return;

    // t2의 부모를 t1으로 만들어버림
    // 더 작은 번호의 부모로 부모 통일 
    parent[t2] = t1;
}

auto main() -> int
{
    // 10명 생성.
    // 이 때는 모두가 다른 그룹에 있다고 가정하는 것임
    for (int i = 0; i < 10; i++)
    {
        parent[i] = i;
    }
    
    for (int i = 0; i < 10 - 1; i++)
    {
        for (int j = i + 1; j < 10; j++)
        {
            // 모든 사람 끼리 1:1 비교하면서 생일이 같으면
            if (birthdays[i] == birthdays[j])
            {
                // 같은 집합으로 만들기
                // 기준은 부모 집합으로
                setUnion(i, j);
            }
        }
    }

    for (int i = 0; i < 10; i++)
    {
        // 각자의 번호마다 루트를 찾아서 재귀 여행을 떠남
        cout << i << "는" << find(i) << "그룹에 속해있습니다." << endl;
    }
    
    return 0;
}

