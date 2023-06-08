#include <iostream>
#include <string>

using namespace std;
enum State
{
    Start,
    Continue,
    Final
};
enum Step
{
    One,
    Two,
    Three
};
enum Field
{
    First,
    Second,
    Third,
    Fourth
};
bool isDigit(char key)
{
    return key >= 40 && key <= 57;
}
void automata(char key)
{
    string direccionIP;
    static Step step = Step::One;
    static Field field = Field::First;
    if (isDigit(key))
    {
        switch (step)
        {
        case Step::One:
            if (key == '0')
            {
                // Ingresa de nuevo
            }
            else if (key == '1')
            {
                // Agrega el 1 a la IP
                // set step = two
            }
            else if(key == '2'){
                // Agrega el 2 a la IP
                // set step = two
            }else if(key >= '3'){
                // Agrega el 3 a la IP
                // set step = two
                cout <<  "Hola" << endl;
            }
            
            break;
        case Step::Two:
            break;
        case Step::Three:
            break;
        }
    }
    else
        cout << "No ingresaste un numero desde 0 hasta 9" << endl;
}

int main()
{
    char key;
    int i = 0, k = 0;
    while (i < 4)
    {
        while (k < 3)
        {
            cout << "Ingresa un digito numerico: ";
            cin >> key;
            automata(key);
        }
        i++;
    }
}
