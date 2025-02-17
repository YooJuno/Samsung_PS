// https://www.acmicpc.net/problem/11726

// 문제
// 2×n 크기의 직사각형을 1×2, 2×1 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.

// 아래 그림은 2×5 크기의 직사각형을 채운 한 가지 방법의 예이다.



// 입력
// 첫째 줄에 n이 주어진다. (1 ≤ n ≤ 1,000)

// 출력
// 첫째 줄에 2×n 크기의 직사각형을 채우는 방법의 수를 10,007로 나눈 나머지를 출력한다.

// 예제 입력 1 
// 2
// 예제 출력 1 
// 2
// 예제 입력 2 
// 9
// 예제 출력 2 
// 55

#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;

    // n==1 -> return 1
    // n==2 -> return 2
    // n==3 -> return 3
    // n==4 -> return 5
    // n==5 -> return 8

    int num[1001];
    num[1] = 1;
    num[2] = 2;

    for(int i=3 ; i<=n ; i++){
        num[i] = (num[i-1] + num[i-2])%10007;
    }

    cout<<num[n]<<endl;

    return 0;
}
