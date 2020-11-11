#include "../func/calc.h"
int main()
{
    string a, b;
    char sign;
    cout << "write first number and press enter: ";
    cin >> a;
    cout << "write second number and press enter: ";
    cin >> b;
    cout << "write operation sign(+, - or *) and press enter: ";
    cin >> sign;
    cout << endl << "Otv: ";
    if(sign == '+')
        cout << addition(a, b);
    else if(sign == '-')
        cout << subtraction(a, b);
    else if(sign == '*')
        cout << multiplication(a, b);
    return 0;
}
