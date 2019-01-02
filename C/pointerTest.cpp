#include <iostream>
using namespace std;

int main( ){

    char a[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', 0}, *p;

    int i = 8;

    p = a + i;

    cout << p - 3 << endl;

    return 0;

}