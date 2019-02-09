#include <iostream>
using namespace std;
class A {
public:
    int val;
    
};

int main()  {
    A a;
    cout << a.val << endl;
    a.GetObj() = 5;
    cout << a.val << endl;

    return 0;
}