#include "calc.h"
string suba(string a, string b, int lena, int lenb)
{
    bool zaim = 0;
    for(int i = 0; i < lenb; i++)
    {
        int ta = a[lena-1 - i] - 48;
        int tb = b[lenb-1 - i] - 48;
        if(zaim)
        {
            ta -= 1;
            zaim = false;
        }
        if(ta < tb)
        {
            ta += 10;
            ta -= tb;
            zaim = true;
            a[lena-1 - i] = ta + 48;
        }
        else
        {
            ta -= tb;
            a[lena-1 - i] = ta + 48;
        }
    }
    if(zaim)
    {
        int ta = a[lena-1 - lenb] - 48;
        ta -= 1;
        a[lena-1 - lenb] = ta + 48;
        zaim = false;
    }
    return a;
}

string subb(string a, string b, int lena, int lenb)
{
    bool zaim = 0;
    for(int i = 0; i < lena; i++)
    {
        int ta = a[lena-1 - i] - 48;
        int tb = b[lenb-1 - i] - 48;
        if(zaim)
        {
            tb -= 1;
            zaim = false;
        }
        if(tb < ta)
        {
            tb += 10;
            tb -= ta;
            zaim = true;
            b[lenb-1 - i] = tb + 48;
        }
        else
        {
            tb -= ta;
            b[lenb-1 - i] = tb + 48;
        }
    }
    if(zaim)
    {
        int tb = a[lenb-1 - lena] - 48;
        tb -= 1;
        b[lenb-1 - lena] = tb + 48;
        zaim = false;
    }
    return "-" + b;
}


string subtraction(string a, string b)
{
    int lena = ft_len(a);
    int lenb = ft_len(b);
    string otv;
    if(lena >= lenb && a_menche_b(a, b) == 0)
        otv = suba(a, b, lena, lenb);
    else
        otv = subb(a, b, lena, lenb);
    return otv;
}
