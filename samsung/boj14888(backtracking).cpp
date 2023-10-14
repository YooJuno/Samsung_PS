// https://www.acmicpc.net/problem/14888
// 연산자 끼워넣기

// backtracking

// 예제 입력 3 
// 6
// 1 2 3 4 5 6
// 2 1 1 1

// 예제 출력 3 
// 54
// -24

// level은 총 N개가 있음
// 각 level의 노드에서 뻗어나가는 브랜치의 갯 수는 하나 씩 줄여나감


// 최댓값을 구하는 과정인데 남은 연산자가 - % 만 남았으면 백트래킹으로 돌아가도 될듯


#include <iostream>

using namespace std;

int N;
int Operands[11];
int Operators[4];

int Min = 1000000001;
int Max = -1000000001;

void backtracking(int result, int depth){

    if(N == depth){
        if(result > Max) Max = result;
        if(result < Min) Min = result;
        return;
    }

    for(int i=0 ; i<4 ; i++){
        if(Operators[i]>0){
            Operators[i]--; // 내려가
            if(i == 0) backtracking(result + Operands[depth], depth+1);
            else if(i == 1) backtracking(result - Operands[depth], depth+1);
            else if(i == 2) backtracking(result * Operands[depth], depth+1);
            else backtracking(result / Operands[depth], depth+1);
            Operators[i]++; // 올라가
        }
    }

}

int main(){

    cin >> N;

    for(int i=0 ; i<N ; i++) cin >> Operands[i];

    for(int i=0 ; i<4 ; i++) cin >> Operators[i];

    backtracking(Operands[0], 1);

    cout << Max << endl << Min << endl;

    return 0;
}