#include "calc.h"
string adda(string a, string b, int lena, int lenb)
{
    int tmp = 0;
    for(int i = 0; i < lenb; i++)
    {
        int ta = a[lena-1 - i] - 48;
        int tb = b[lenb-1 - i] - 48;
        int sum = ta + tb;
        a[lena-1 - i] = sum%10 + 48;
        tmp = sum/10;
        if(lena-1 - i - 1 < 0 && tmp == 1)
        {
            a = "1" + a;
            tmp = 0;
        }
        else if(tmp == 1)
        {
            a[lena-1 - i - 1] += 1;
            tmp = 0;
        }
    }
    return a;
}
string addb(string a, string b, int lena, int lenb)
{
    int tmp = 0;
    for(int i = 0; i < lena; i++)
    {
        int ta = a[lena-1 - i] - 48;
        int tb = b[lenb-1 - i] - 48;
        int sum = tb + ta;
        b[lenb-1 - i] = sum%10 + 48;
        tmp = sum/10;
        if(lenb-1 - i - 1 < 0 && tmp == 1)
        {
            b = "1" + b;
            tmp = 0;
        }
        else if(tmp == 1)
        {
            b[lenb-1 - i - 1] += 1;
            tmp = 0;
        }
    }
    return b;
}

string addition(string a, string b)
{
    int lena = ft_len(a);
    int lenb = ft_len(b);
    string otv;
    if(a[0] == '-' && b[0] != '-')
    {
        a[0] = ' ';
        otv = subtraction(b, a);
    }
    else if(a[0] != '-' && b[0] == '-')
    {
        b[0] = ' ';
        otv = subtraction(a, b);
    }
    else if(a[0] == '-' && b[0] == '-')
    {
        b[0] = ' ';
        a[0] = ' ';
        otv = addition(a, b);
    }
    else if(lena >= lenb)
        otv = adda(a, b, lena, lenb);
    else
        otv = addb(a, b, lena, lenb);
    return otv;
}
