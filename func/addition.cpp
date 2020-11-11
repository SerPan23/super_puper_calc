#include "calc.h"
string addition(string a, string b)
{
    int lena = ft_len(a);
    int lenb = ft_len(b);
    int tmp = 0;
    if(lena >= lenb)
    {
        for(int i = 0; i < lenb; i++)
        {
            int ta = a[lena-1 - i] - 48;
            int tb = b[lenb-1 - i] - 48;
            int sum = ta + tb;
            a[lena-1 - i] = sum%10 + 48;
            tmp = sum/10;
        }
        if(tmp > 0)
        {
            int t = lena - lenb;
            if(t > 0)
            {
                a[t-1] += tmp;
            }
            else
            {
                string ts;
                ts[0] = tmp + 48;
                ts = ts[0] + a;
                //cout << ts;
                return ts;
            }
        }
    }
    else
    {
        for(int i = 0; i < lena; i++)
        {
            int ta = a[lena-1 - i] - 48;
            int tb = b[lenb-1 - i] - 48;
            int sum = tb + ta;
            b[lenb-1 - i] = sum%10 + 48;
            tmp = sum/10;
        }
        if(tmp > 0)
        {
            int t = lenb - lena;
            if(t > 0)
            {
                b[t-1] += tmp;
            }
            else
            {
                string ts;
                ts[0] = tmp + 48;
                ts = ts[0] + b;
                //cout << ts;
                return ts;
            }
        }
        return b;
    }
    return a;
}
