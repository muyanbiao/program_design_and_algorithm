#include <iostream>
#include <cstring>
using namespace std;

class CArray {
    int size;
    int *ptr;

public:
    CArray(int s = 0);
    ~CArray();

    int &operator[](int i) {
        return ptr[i];
    }

    CArray &operator=(const CArray &a);
};

CArray::CArray(int s):size(s) {
    if (s == 0) {
        ptr = NULL;
    } else {
        ptr = new int[s];
    }
}

CArray::~CArray() {
    if (ptr) {
        delete[] ptr;
    }
}

CArray& CArray::operator=(const CArray &a) {
    if (ptr == a.ptr) { // 防止自己给自己赋值
        return *this;
    }

    if (a.ptr == NULL) { // 如果a为空，则把当前数组也置空
        if (ptr) {
            delete[] ptr;
        }
        ptr = NULL;
        size = 0;
        return *this;
    }

    if (size < a.size) { // 如果当前存储空间不够大，则删除当前存储空间，重新分配和a一样大的存储空间
        if (ptr) {
            delete[] ptr;
        }

        ptr = new int[a.size];
    }

    memcpy(ptr, a.ptr, sizeof(int) * a.size);
    size = a.size;
    return *this;
}

class Array2 {
    int row, column;
    CArray *ptr;
public:
    Array2(int i = 0, int j = 0);
    ~Array2();
    Array2 &operator=(Array2 &a);
    CArray &operator[](int i) {
        return ptr[i];
    }
    int &operator()(int i, int j);
};

Array2::Array2(int i, int j):row(i),column(j) {
    if (i == 0 || j == 0) {
        ptr = NULL;
    } else {
        ptr = new CArray[i];
        for (int k = 0; k < i; ++k) {
            ptr[k] = CArray(j);
        }
    }
}

Array2::~Array2() {
    if (ptr)
        delete[] ptr;
}

Array2& Array2::operator=(Array2 &a) {
    if (ptr == a.ptr) {
        return *this;
    }

    if (a.ptr == NULL) {
        if (ptr) delete[] ptr;

        ptr = NULL;
        row = 0;
        column = 0;
        return *this;
    }

    if (row < a.row || column < a.column) {
        if (ptr) delete[] ptr;

        ptr = new CArray[a.row];
        for (int i = 0; i < a.row; ++i) {
            ptr[i] = CArray(a.column);
        }
    }

    for (int j = 0; j < a.row; ++j) {
        ptr[j] = a[j];
    }
    row = a.row;
    column = a.column;
    return *this;
}

int& Array2::operator()(int i, int j) {
    CArray &array1 = ptr[i];
    return array1[j];
}

int main() {
    Array2 a(3,4); // 构造函数
    int i,j;
    for(  i = 0;i < 3; ++i )
        for(  j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j; // 重载下标运算符[][]
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ","; // 重载重载(,)运算符
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;     b = a; // 重载赋值运算符
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}