#include <iostream>

using namespace std;
/*
기존에 풀었던 문제였지만 그 당시 C언어로 풀었기에
지금은 C++로 풀어보았습니다. 그 때보다 푸는데 시간이
좀 더 걸린 것 같습니다.
*/

int main() {
    // 테스트 케이스 입력
    int test;  
    cin>>test;

    for(int i=0 ; i<test ; i++){
        int num; //학생 수
        int sum=0;// 학생들의 점수 총 합
        cin>>num;
        int point[num]; // 학생들의 점수를 받기 위한 배열
        for(int j=0 ; j<num ; j++){
            cin>>point[j];
            sum += point[j];
        }
        // 소수점형태로도 대,소가 바뀌기에 실수형태로 평균 값 저장
        double average = sum/(double)num;

        int higher=0;//점수가 평균보다 높으면 +1
        for(int j=0 ; j<num ; j++)
            if(point[j]>average) higher++;
        
        // C++에서 소수점 출력을 위한 함수
        cout.setf(ios::fixed);
        cout.precision(3);
        cout<<(higher/(double)num)*100<<'%'<<endl;;
    }
}