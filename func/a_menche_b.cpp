#include "calc.h"
bool a_menche_b(string a, string b)
{
    int len = ft_len(a);
    int kolrav = 0;
    for(int i = 0; i < len; i++)
    {
        if(a[i]-48 > b[i]-48)
            return false;
        if(a[i]-48 == b[i]-48)
            kolrav++;
    }
    if(kolrav == len)
        return false;
    return true;
}
