#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;

    for(auto test_case=0; test_case<T; test_case++)
    {
        int L, R;
        cin >> L >> R;
        auto is_found = false;

        for(auto X=1; X<=R*2; X++)
        {
            auto failed = false;
    
            for(auto N=L; N<=R; N++)
            {
                if(N%X < X/2.0)
                {
                    failed = true;
                    break;
                }
            }

            if(!failed) 
        }

        if(!is_found) cout << "no\n";
    }

    return 0;
}