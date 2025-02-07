#include <iostream>
#include <algorithm>
 
using namespace std;
 
int Answer;
 
bool desc(int a, int b) {
    return a > b;
}
 
int main(int argc, char** argv){
    int T, test_case;
    int N, K;
    
    cin >> T;
    for (test_case = 0; test_case < T; test_case++){
 
        Answer = 0;
        cin >> N >> K;
        int* scores = new int[N];
 
        for (int i = 0; i < N; i++) {
            cin >> scores[i];
        }
 
        sort(scores, scores + N, desc);
 
        for (int i = 0; i < K; i++) {
            Answer += scores[i];
        }
 
        cout << "Case #" << test_case + 1 << endl;
        cout << Answer << endl;
        delete[] scores;
    }
 
    return 0;
    }
