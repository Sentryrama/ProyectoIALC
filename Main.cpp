#include <iostream>
#include <string>

using namespace std;

enum Step {
    One,
    Two,
    Three
};

bool isDigit(char key) {
    return key >= 48 && key <= 57;
}

bool limitador(char lowest, char highest, char key) {
    return key >= lowest && key <= highest;
}

string ultimosDigitos(int cantidad, string &direccionIP) {
    return cantidad == 1 ? direccionIP.substr(direccionIP.length() - 1, 1) : direccionIP.substr(
            direccionIP.length() - 2, 2);
}

int campoVacio(string &direccionIP) {
    char eleccion;
    cout << "Quieres que el campo sea unicamente 0? (S/N): ";
    cin >> eleccion;
    if (eleccion == 'S' || eleccion == 's') {
        direccionIP.append("0");
        return 3;
    } else if (eleccion == 'N' || eleccion == 'n') {
        return 1;
    } else {
        cout << "Solo puedes ingresar S o N" << endl;
        return 1;
    }
}

int automata(char key, string &direccionIP, int k) {

    static Step step = Step::One;
    if (key == 'b' || key == 'B') {
        if (direccionIP.back() == '.') {
            direccionIP.pop_back();
            direccionIP.pop_back();
            step = Step::Three;
            return 2;
        } else {
            direccionIP.pop_back();
            switch (step) {
                case Step::Three:
                    step = Step::Two;
                    break;
                case Step::Two:
                    step = Step::One;
                    break;
                case Step::One:
                    if (isDigit(direccionIP.length() - 4))
                        step = Step::Three;
                    else
                        step = Step::Two;
                    break;
            }
        }
    } else if (key == 't' || key == 'T') {
        if (direccionIP.back() == '.' || direccionIP.back() == '/')
            return campoVacio(direccionIP);
        else {
            step = Step::One;
            return 3;
        }
    } else if (isDigit(key)) {
        switch (step) {
            case Step::One:
                switch (key) {
                    case '0':
                        return campoVacio(direccionIP);
                    case '1':
                        direccionIP.append("1");
                        step = Step::Two;
                        return 1;
                    case '2':
                        direccionIP.append("2");
                        step = Step::Two;
                        return 1;
                    case '3':
                    case '4':
                    case '5':
                    case '6':
                    case '7':
                    case '8':
                    case '9':
                        step = Step::Two;
                        direccionIP.append(string(1, key));
                        return 1;
                }
                break;
            case Step::Two:
                switch (ultimosDigitos(1, direccionIP)[0]) {
                    case '1':
                        if (limitador('0', '9', key)) {
                            direccionIP.append(string(1, key));
                            step = Step::Three;
                            return 2;
                        }
                    case '2':
                        if (limitador('0', '4', key)) {
                            direccionIP.append(string(1, key));
                            step = Step::Three;
                            return 2;
                        } else if (limitador('5', '9', key)) {
                            direccionIP.append(string(1, key));
                            step = Step::Three;
                            return 2;
                        }
                    case '3':
                    case '4':
                    case '5':
                    case '6':
                    case '7':
                    case '8':
                    case '9':
                        direccionIP.append(string(1, key));
                        step = Step::One;
                        return 3;
                }
                break;
            case Step::Three:
                string ultimos = ultimosDigitos(2, direccionIP);
                string ultimo = ultimosDigitos(1, direccionIP);
                if (
                        ultimos == "10" ||
                        ultimos == "11" ||
                        ultimos == "12" ||
                        ultimos == "13" ||
                        ultimos == "14" ||
                        ultimos == "15" ||
                        ultimos == "16" ||
                        ultimos == "17" ||
                        ultimos == "18" ||
                        ultimos == "19"
                        ) {
                    direccionIP.append(string(1, key));
                    step = Step::One;
                    return 3;
                } else if (
                        ultimos == "20" ||
                        ultimos == "21" ||
                        ultimos == "22" ||
                        ultimos == "23" ||
                        ultimos == "24"
                        ) {
                    if (limitador('0', '9', key)) {
                        direccionIP.append(string(1, key));
                        step = Step::One;
                        return 3;
                    }
                } else if (ultimos == "25") {
                    if (limitador('0', '5' , key)) {
                        direccionIP.append(string(1, key));
                        step = Step::One;
                        return 3;
                    } else {
                        step = Step::One;
                        return 3;
                    }
                } else if (
                        ultimos == "25" ||
                        ultimos == "26" ||
                        ultimos == "27" ||
                        ultimos == "28" ||
                        ultimos == "29"
                        ) {
                    step = Step::One;
                    return 3;
                } else if (
                        ultimo == "1" ||
                        ultimo == "2" ||
                        ultimo == "3" ||
                        ultimo == "4" ||
                        ultimo == "5" ||
                        ultimo == "6" ||
                        ultimo == "7" ||
                        ultimo == "8" ||
                        ultimo == "9"
                        ) {
                    direccionIP.append(string(1, key));
                    step = Step::One;
                    return 3;
                }
                break;
        }
    } else
        cout << "No ingresaste un numero desde 0 hasta 9" << endl;
    return 0;
}

int main() {
    static string direccionIP = "/";
    char key;
    int k = 0;
    cout << &direccionIP << endl;
    for (int i = 0; i < 4; i++) {
        if (k == 3)
            direccionIP += ".";
        k = 0;
        while (k < 3) {
            cout << "\nDireccion compuesta: " << direccionIP << endl;

            cout << "Ingresa un digito numerico // 't' para TAB // 'b' para Backspace: ";
            cin >> key;
            if (direccionIP.back() == '.' && key == 'b' || key == 'B') {
                k = automata(key, direccionIP, k);
                i--;
            } else
                k = automata(key, direccionIP, k);
        }
    }
    cout << "Direccion IP final: " << direccionIP << endl;
}
