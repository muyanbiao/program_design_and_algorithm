#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class BigNumberString : public string
{
public:
	BigNumberString():string(){};
	
	BigNumberString&operator+(BigNumberString &s);
	BigNumberString&operator-(BigNumberString &s);
	BigNumberString&operator*(BigNumberString &s);
	BigNumberString&operator/(BigNumberString &s);
	
};

int main() {

	string s1, s2;
	char op;
	cin >> s1 >> op >> s2;

	cout << s1 << " " << op << " " << s2 << endl;

	return 0;
}