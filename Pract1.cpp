#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {

    int n;

    do {
        string tk;

        cout << "\nTeclea un token: ";
        cin >> tk;

        // Banderas
        bool tieneLetra = false;
        bool tieneNumero = false;
        bool tieneSimbolo = false;

        bool iniciaConLetra = false;
        bool iniciaConNumero = false;
        bool iniciaConGuion = false;

        // Recorrido del token
        for (int x = 0; x < tk.size(); x++) {
            char c = tk[x];

            if (isalpha(c)) {
                tieneLetra = true;
            }
            else if (isdigit(c)) {
                tieneNumero = true;
            }
            else if (c == '_') {
                // permitido para identificadores
            }
            else {
                tieneSimbolo = true;
            }

            // Analizar solo el primer carácter
            if (x == 0) {
                if (isalpha(c)) iniciaConLetra = true;
                else if (isdigit(c)) iniciaConNumero = true;
                else if (c == '_') iniciaConGuion = true;
            }
        }
////////////////////////////////////////////////////////////////////////////////////////////////
        cout << "\nClasificacion del token:\n";

        // 1. Número válido
        if (tieneNumero && !tieneLetra && !tieneSimbolo) {
            cout << "Es un NUMERO valido\n";
        }
        // 2. Número mal declarado
        else if (iniciaConNumero && (tieneLetra || tieneSimbolo)) {
            cout << "Es un NUMERO mal declarado\n";
        }
        // 3. Palabra (solo letras)
        else if (tieneLetra && !tieneNumero && !tieneSimbolo) {
            cout << "Es una PALABRA\n";
        }
        // 4. Identificador
        else if (!tieneSimbolo &&
                (iniciaConLetra || iniciaConGuion) &&
                (tieneLetra || tieneNumero)) {
            cout << "Es un IDENTIFICADOR\n";
        }
        // 5. Error
        else {
            cout << "ERROR: token no valido\n";
        }

        cout << "\nDesea reintentar? S=1 N=0: ";
        cin >> n;

    } while (n == 1);

    return 0;
}

