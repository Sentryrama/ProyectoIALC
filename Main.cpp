#include <iostream>
#include <stdio.h>
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

bool isDigit(char key)
{
    return key >= 48 && key <= 57;
}
void mostrar_direccionIP(string direccionIP)
{
    cout << direccionIP << endl;
}

int automata(char key, string &direccionIP)
{

    static Step step = Step::One;
    char eleccion;
    if (key == 'b' || key == 'B')
    {
        if (direccionIP.length() - 1 == '.')
            direccionIP.erase(direccionIP.length() - 1);
        else
            direccionIP.erase(direccionIP.length() - 2, 2);
    }
    else if (isDigit(key))
    {
        switch (step)
        {
        case Step::One:
            if (key == '0')
            {
                cout << "Quieres que el campo sea unicamente 0? (S/N): ";
                cin >> eleccion;
                if (eleccion == 'S' || eleccion == 's')
                {
                    direccionIP.append("0");
                    return 3;
                }
                else if (eleccion == 'N' || eleccion == 'n')
                {
                    return 0;
                }
                else
                    cout << "Solo puedes ingresar S o N" << endl;
            }
            else if (key == '1')
            {
                direccionIP.append("1");
                step = Step::Two;
                return 1;
            }
            else if (key == '2')
            {
                direccionIP.append("2");
                step = Step::Two;
                return 1;
            }
            else if (key >= '3')
            {
                string caracter = string(1, key);
                step = Step::Two;
                direccionIP.append(caracter);
                return 1;
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
    return 0;
}

int main()
{
    static string direccionIP = "/";
    char key;
    int k = 0;
    cout << &direccionIP << endl;
    for (int i = 0; i < 4; i++)
    {
        if (i != 4 && k == 3)
        {
            direccionIP += ".";
        }
        k = 0;
        while (k < 3)
        {
            cout << "Ingresa un digito numerico: ";
            cin >> key;
            if (key == 'b')
                i--;
            k = automata(key, direccionIP);
            cout << "El valor de k: " << k << " El valor de i: " << i << endl;
            cout << "Direccion compuesta: " << direccionIP << endl;
        }
    }
}
