#include "../func/calc.h"

void SetColor(int text, int bg){
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}


int main()
{
    string a, b;
    char sign;
    cout << "write first number and press enter: ";
    SetColor(15, 0);
    cin >> a;
    SetColor(7, 0);
    cout << "write operation sign(+, - or *) and press enter: ";
    SetColor(15, 0);
    cin >> sign;
    SetColor(7, 0);
    cout << "write second number and press enter: ";
    SetColor(15, 0);
    cin >> b;
    SetColor(2, 0);
    cout << endl << "Otv: ";
    if(sign == '+')
        cout << addition(a, b);
    else if(sign == '-')
        cout << subtraction(a, b);
    else if(sign == '*')
        cout << multiplication(a, b);
    SetColor(7, 0);
    return 0;
}
