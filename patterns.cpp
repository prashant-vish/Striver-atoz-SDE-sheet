#include <bits/stdc++.h>
using namespace std;

void print1(int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "* ";
        }
        cout << "\n";
    }
}
void print2(int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "* ";
        }
        cout << "\n";
    }
}
void print3(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= i + 1; j++)
        {
            cout << j;
        }
        cout << "\n";
    }
}
void print4(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i;
        }
        cout << "\n";
    }
}
void print5(int n)
{

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n + 1 - i; j++)
        {
            cout << "*";
        }
        cout << "\n";
    }
}
void print6(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n + 1 - i; j++)
        {
            cout << j;
        }
        cout << "\n";
    }
}
void print7(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < n + 1 - i; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            cout << "*";
        }
        for (int j = 1; j < n + 1 - i; j++)
        {
            cout << " ";
        }
        cout << "\n";
    }
}
void print8(int n)
{

    for (int i = 0; i < n; i++)
    {

        // space
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        // star
        for (int j = 0; j < 2 * (n - i) - 1; j++)
        {
            cout << "*";
        }
        // space
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        cout << "\n";
    }
}
void print9(int n)
{
    print7(n);
    print8(n);
}
void print10(int n)
{
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        int stars = i;
        if (i > n)
        {
            stars = 2 * n - i;
        }

        for (int j = 1; j <= stars; j++)
        {
            cout << "*";
        }

        cout << "\n";
    }
}
void print11(int n)
{
    for (int i = 0; i < n; i++)
    {
        int flag = 1;
        if (i % 2 == 1)
        {
            flag = 0;
        }
        for (int j = 0; j <= i; j++)
        {
            cout << flag;
            flag = 1 - flag;
        }
        cout << "\n";
    }
}
void print12(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        for (int j = 1; j <= 2 * (n - i); j++)
        {
            cout << " ";
        }
        for (int j = i; j >= 1; j--)
        {
            cout << j;
        }
        cout << "\n";
    }
}
void print13(int n)
{
    int num = 1;
    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= i; j++)
        {
            cout << num;
            num++;
        }
        cout << "\n";
    }
}
void print14(int n)
{
    for (int i = 1; i <= n; i++)
    {
        char a = 'A';
        for (int j = 1; j <= i; j++)
        {
            cout << a;
            a++;
        }
        cout << " \n";
    }
}
void print15(int n)
{
    for (int i = 0; i < n; i++)
    {

        for (char j = 'A'; j < 'A' + n - i; j++)
        {
            cout << j;
        }
        cout << "\n";
    }
}
void print16(int n)
{
    for (char ch = 'A'; ch < 'A' + n; ch++)
    {
        for (char chr = 'A'; chr < ch + 1; chr++)
        {
            cout << ch;
        }
        cout << "\n";
    }
}
void print17(int n)
{

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        char ch = 'A';
        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << ch;
            if (j < i)
            {
                ch++;
            }
            else
            {
                ch--;
            }
        }
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        cout << "\n";
    }
}
void print18(int n)
{

    for (int i = 0; i < n; i++)
    {
        char ch = 'A' + n - i - 1;
        for (int j = 0; j <= i; j++)
        {
            cout << ch;
            ch++;
        }
        cout << "\n";
    }
}
void print19(int n)
{
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n - i; j++)
        {
            cout << "*";
        }
        for (int j = 0; j < 2 * i; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < n - i; j++)
        {
            cout << "*";
        }
        cout << "\n";
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        for (int j = 0; j < 2 * (n - 1 - i); j++)
        {
            cout << " ";
        }
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        cout << "\n";
    }
}
void print20(int n)
{
    int inS = 2 * n - 2;
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        int stars = i;
        if (i > n)
        {
            stars = 2 * n - i;
        }
        // stars
        for (int j = 1; j <= stars; j++)
        {
            cout << "*";
        }
        // spaces
        for (int j = 1; j <= inS; j++)
        {
            cout << " ";
        }

        // stars
        for (int j = 1; j <= stars; j++)
        {
            cout << "*";
        }

        if (i < n)
        {
            inS = inS - 2;
        }
        else
        {
            inS = inS + 2;
        }
        cout << "\n";
    }
}
void print21(int n)
{
    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= n; j++)
        {
            if (i == 1 || i == n || j == 1 || j == n)
                cout << "*";
            else
            {
                cout << " ";
            }
        }
        cout << "\n";
    }
}
void print22(int n)
{
    for (int i = 0; i < 2 * n - 1; i++)
    {
        for (int j = 0; j < 2 * n - 1; j++)
        {
            int top = i;
            int left = j;
            int right = 2 * n - 2 - j;
            int bottom = 2 * n - 2 - i;
            cout << n - min(min(top, bottom), min(left, right));
        }
        cout << "\n";
    }
}
void printx(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        for (int j = 0; j < 2 * (n - 1 - i); j++)
        {
            cout << " ";
        }
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        cout << "\n";
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        print22(n);
    }
}