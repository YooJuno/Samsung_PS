#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    
    int N;
    cin>>N;
    queue <int> q;
    
    for(int i=1 ; i<=N ; i++) q.push(i);

    for(int i=0 ; i<N ; i++){
        if(q.size()==1) break;
        q.pop();
        q.push(q.front());
        q.pop();
    }
    cout<<q.front()<<endl<<endl;
    
}
// 힌트 1 : 2의 제곱수는 그 수가 그대로 나온다
// 힌트 2 : 모르겠다.
