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
enum Field
{
    First,
    Second,
    Third,
    Fourth
};
bool isDigit(char key)
{
    return key >= 48 && key <= 57;
}
void mostrar_direccionIP(string direccionIP)
{
    cout << direccionIP << endl;
}
void mostar_field(Field field){
    cout << "Estas en " << field << " y pasas a " << (field+1) << endl;
}
int automata(char key)
{
    static string direccionIP = "";
    static Step step = Step::One;
    static Field field = Field::First;
    char eleccion;

    if (isDigit(key))
    {
        switch (step)
        {
        case Step::One:
            if (key == '0')
            {
                cout << "Quieres que el campo sea unicamente 0? (S/N): ";
                cin >> eleccion;
                if (eleccion == 'S' || eleccion == 's' )
                {

                    if (field == Field::First)
                    {
                        direccionIP.append("0.");
                        field = Field::Second;
                        mostar_field(field);
                        return 1;
                    }
                    else if (field == Field::Second)
                    {
                        direccionIP.append("0.");
                        field = Field::Third;
                        mostar_field(field);
                        return 2;
                    }
                    else if (field == Field::Third)
                    {
                        direccionIP.append("0.");
                        field = Field::Fourth;
                        mostar_field(field);
                        return 3;
                    }
                    else if (field == Field::Fourth)
                    {
                        direccionIP.append("0");
                        mostar_field(field);
                        mostrar_direccionIP(direccionIP);
                        return 4;
                    }

                    break;
                }
                else if (key == '1')
                {
                    direccionIP.append("1");
                    // Agrega el 1 a la IP
                    // set step = two
                }
                else if (key == '2')
                {
                    // Agrega el 2 a la IP
                    // set step = two
                }
                else if (key >= '3')
                {
                    // Agrega el 3 a la IP
                    // set step = two
                    cout << "Hola" << endl;
                }
            }
            else
                cout << "Solo puedes ingresar S o N" << endl;
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
    char key;
    int i = 0, k = 0;
    while (i < 4)
    {
        cout << "Ingresa un digito numerico: ";
        cin >> key;
        i = automata(key);
        /*while (k < 3)
        {
        }*/
        // i++;
    }
}

