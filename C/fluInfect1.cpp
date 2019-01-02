#include <iostream>
using namespace std;
int main()
{
    //输入n和相应的房间状态
    int n=0;
    cin >> n;
    char a[50][50];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    //输入天数
    int day = 0;
    cin >> day;
    while (day)
    {
        //前四个for循环处理四周的边界的传染状态更新
        for (int i = 0; i < n; i++)
        {
            if (a[1][i]=='@')
            {
                if (a[0][i] != '#')
                {
                    a[0][i] = '@';
                }

            }
        }
        for (int i = 0; i < n; i++)
        {
            if (a[n][i] == '@')
            {
                if (a[n-1][i] != '#')
                {
                    a[n-1][i] = '@';
                }

            }
        }
        for (int i = 0; i < n; i++)
        {
            if (a[i][1] == '@')
            {
                if (a[i][0] != '#')
                {
                    a[i][0] = '@';
                }

            }
        }
        for (int i = 0; i < n; i++)
        {
            if (a[i][n] == '@')
            {
                if (a[i][n-1] != '#')
                {
                    a[i][n-1] = '@';
                }

            }
        }
        //摒弃四周边界的房间后，所有房间的传染更新状态
        for (int i = 1; i < n-1; i++)
        {
            for (int j = 1; j < n-1; j++)
            {
                if (a[i][j] == '@')
                {
                    if (a[i - 1][j]!='#')
                    {
                        a[i - 1][j] = '@';
                    }
                    if (a[i][j - 1] != '#')
                    {
                        a[i][j - 1] = '@';
                    }
                    if (a[i][j + 1] != '#')
                    {
                        a[i][j + 1] = '@';
                    }
                    if (a[i + 1][j] != '#')
                    {
                        a[i + 1][j] = '@';
                    }


                }
            }
        }
        day = day - 1;
    }
    //统计房间内被感染的数量。
    int num = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j]=='@')
            {
                num++;
            }

        }
    }
    cout << num << endl;
    return 0;
}