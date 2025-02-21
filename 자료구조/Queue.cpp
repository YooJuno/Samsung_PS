#include <iostream>
#include <deque>

using namespace std;


auto main() -> int
{
    // [Initialization]
    std::deque<int> dq;

    // [push_back()]
    for(auto i = 0; i < 10; i++)
    {
        dq.push_back(i);
    }

    // [Iterator]
    cout << "Initialization : ";
    std::deque<int>::iterator iter;
    for(auto iter = dq.begin(); iter != dq.end(); iter++)
        cout << *iter << ' ';
    cout << endl;

    // [Push, Pop]
    dq.push_front(-1);
    dq.push_back(-2);
    dq.push_back(-3);
    dq.pop_front();
    dq.pop_back();
    
    cout << "Push, Pop : ";
    for(auto iter = dq.begin(); iter != dq.end(); iter++)
        cout << *iter << ' ';
    cout << endl;
    
    // [Reverse Iterator]
    std::deque<int>::reverse_iterator rIter;
    cout << "Reversed : ";
    for (rIter = dq.rbegin(); rIter != dq.rend(); rIter++)
		cout << *rIter << " ";
    cout << endl;

    // [Insert, Const Iterator]
    cout << "Insert : ";
    std::deque<int>::const_iterator conIter = dq.begin();
    conIter += 2; // 두 번 자리에 삽입(원래꺼는 뒤로 밀려남)
    dq.insert(conIter, 100);
    for (conIter = dq.begin(); conIter != dq.end(); conIter++)
		std::cout << *conIter << " ";
    cout << endl;

    return 0;
}