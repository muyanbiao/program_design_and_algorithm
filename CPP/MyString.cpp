#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

// FIXME: 这是正确的写法，只重载
class MyString : public string {
public:
    MyString():string(){};
    MyString(const char *cstr):string(cstr){};
    MyString(const string &str):string(str){};
    // 只需要在这里调用父类的substr方法就可以了
    MyString operator()(int m, int n) {
        return string::substr(m, n);
    }
};

// FIXME: 这是错误的版本，不需要重载那么多方法，只需要重载()就可以了，其他的交给父类来处理
//class MyString : public string {
//    string str;
//public:
//    MyString(string s = "");
//    MyString(MyString &mStr);
//    ~MyString();
//    MyString&operator=(MyString &mStr);
//    MyString&operator=(string s);
//    MyString&operator=(const char *s);
//    MyString&operator+(MyString &mStr);
//
//    string operator()(unsigned long i, unsigned long j);
//
//    friend ostream&operator<<(ostream &os, MyString &mStr);
//
//    char& operator[](int i);
//};
//
//char& MyString::operator[](int i) {
//    return str[i];
//}
//
//ostream &operator<<(ostream &os, MyString &mStr) {
//    os << mStr.str;
//    return os;
//}
//
//MyString::MyString(string s) {
//    str = s;
//}
//
//MyString::MyString(MyString &mStr) {
//    str = mStr.str;
//}
//
//MyString::~MyString() {
//    str = "";
//}
//
//MyString& MyString::operator=(MyString &mStr) {
//    str = mStr.str;
//    return *this;
//}
//
//MyString& MyString::operator=(string s) {
//    str = s;
//    return *this;
//}
//
//MyString& MyString::operator=(const char *s) {
//    str = s;
//    return *this;
//}
//
//MyString& MyString::operator+(MyString &mStr) {
//    str.append(mStr.str);
//    return *this;
//}
//
//string MyString::operator()(unsigned long i, unsigned long j) {
//    return str.substr(i, j);
//}

int CompareString( const void * e1, const void * e2) {
    MyString * s1 = (MyString * ) e1;
    MyString * s2 = (MyString * ) e2;
    if( *s1 < *s2 )     return -1;
    else if( *s1 == *s2 ) return 0;
    else if( *s1 > *s2 ) return 1;
    return 0;
}
int main() {
    MyString s1("abcd-"),s2,s3("efgh-"),s4(s1);
    MyString SArray[4] = {"big","me","about","take"};
    cout << "1. " << s1 << s2 << s3<< s4<< endl;
    s4 = s3;    s3 = s1 + s3;
    cout << "2. " << s1 << endl;
    cout << "3. " << s2 << endl;
    cout << "4. " << s3 << endl;
    cout << "5. " << s4 << endl;
    cout << "6. " << s1[2] << endl;
    s2 = s1;    s1 = "ijkl-";
    s1[2] = 'A' ;
    cout << "7. " << s2 << endl;
    cout << "8. " << s1 << endl;
    s1 += "mnop";
    cout << "9. " << s1 << endl;
    s4 = "qrst-" + s2;
    cout << "10. " << s4 << endl;
    s1 = s2 + s4 + " uvw " + "xyz";
    cout << "11. " << s1 << endl;
    qsort(SArray,4,sizeof(MyString), CompareString);
    for( int i = 0;i < 4;++i )
        cout << SArray[i] << endl;
    //输出s1从下标0开始长度为4的子串
    cout << s1(0,4) << endl;
    //输出s1从下标为5开始长度为10的子串
    cout << s1(5,10) << endl;
    return 0;
}