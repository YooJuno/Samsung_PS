#include <iostream>

using namespace std;

int main()
{
    int T; cin >> T;
    for(int test_case=1; test_case<=T; test_case++)
    {
        int N; cin >> N;
        bool isCounted[10] = {0,};
        int8_t cntUnchecked = 10;
        int mul=0;

        while(cntUnchecked > 0)
        {
            int quotient = (++mul)*N;
            while(quotient >= 1)
            {
                int remainder = quotient%10;
                if(!isCounted[remainder]) 
                {   
                    isCounted[remainder] = true;
                    cntUnchecked--;
                }
                quotient /= 10;
            }
        }
        
        cout << '#' << test_case << ' ' << mul*N << endl;
    }

    return 0;
}