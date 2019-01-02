#include<stdio.h>
int f()
{
    int i, j, n, k;
    int a[1001];
    scanf("%d%d", &n, &k);
    for (i = 0; i<n; i++)
    {
        scanf("%d",&a[i]);
        for (j = i - 1; j >= 0; j--)
        if (a[i] + a[j] == k)
            return 1;
    }
    return 0;
}
int main()
{
    if (f())
        printf("yes\n");
    else
        printf("no\n");
}