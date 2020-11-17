#include "calc.h"
string create_ch(int ch)
{
    string tmp;
    while(ch)
    {
        tmp += (ch%10)+48;
        ch /= 10;
    }
    int lt = ft_len(tmp);
    string otv(lt, '\0');
    for(int i = 0; i < lt; i++)
    {
        otv[i] = tmp[lt-1 - i];
    }
    return otv;
}
string multia(string a, string b, int lena, int lenb)
{
    string sum = "0";
    int sdv = 1;
    for(int i = 0; i < lenb; i++)
    {
        int tb = b[lenb-1 - i] - 48;
        int mn = 1;
        for(int j = 0; j < lena; j++)
        {
            int ta = a[lena-1 - j] - 48;
            int t = ta * tb * mn * sdv;
            string tmp = create_ch(t);
            mn *= 10;
            sum = addition(sum, tmp);
        }
        sdv *= 10;
    }
    return sum;
}
string multib(string a, string b, int lena, int lenb)
{
    string sum = "0";
    int sdv = 1;
    for(int i = 0; i < lena; i++)
    {
        int ta = a[lena-1 - i] - 48;
        int mn = 1;
        for(int j = 0; j < lenb; j++)
        {
            int tb = b[lenb-1 - j] - 48;
            int t = tb * ta * mn * sdv;
            string tmp = create_ch(t);
            mn *= 10;
            sum = addition(sum, tmp);
        }
        sdv *= 10;
    }
    return sum;
}
string multiplication(string a, string b)
{
    int lena = ft_len(a);
    int lenb = ft_len(b);
    string otv;
    if(a[0] == '-' && b[0] != '-')
    {
        a[0] = ' ';
        otv = "-" + multiplication(a, b);
    }
    else if(a[0] != '-' && b[0] == '-')
    {
        b[0] = ' ';
        otv = "-" + multiplication(a, b);
    }
    else if(a[0] == '-' && b[0] == '-')
    {
        b[0] = ' ';
        a[0] = ' ';
        otv = multiplication(a, b);
    }
    else if(lena >= lenb)
        otv = multia(a, b, lena, lenb);
    else
        otv = multib(a, b, lena, lenb);
    return otv;
}
