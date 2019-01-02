#include<iostream>
using namespace std;
int main()
{
    int n, k, a[1000];
    cin >> n >> k;
    for (int i = 0; i < n; i++)	//输入n个数
    {
        cin >> a[i];
    }
    int flag = 0;	//判断标志位
    for (int i = 0; i < n; i++)
    {
        if (n == 1)	//n=1时特殊情况
        {
            flag = 1;	//判断程序是否执行到该处,如果flag为1则必定输出yes 或者 no
            if (a[0] == k)
                cout << "yes";
            else
                cout << "no";
            break;	//跳出for循环
        }
        else //n大于2时
        {
            for (int j = 1; j < n; j++)
            {
                int num = 0;
                num = a[i] + a[j];
                if (num == k)
                {
                    cout << "yes";
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
            {
                break;
            }
        }
    }
    if (flag != 1)	//n不等于1，则表明没有进入n=1和输出yes，则直接输出no
        cout << "no";

    return 0;
}