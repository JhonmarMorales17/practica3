#include <iostream>
#include <cmath> // Para abs

using namespace std;

string determinarCuadrante(int x, int y) {
    if (x > 0 && y > 0)
        return "Primer cuadrante";
    else if (x < 0 && y > 0)
        return "Segundo cuadrante";
    else if (x < 0 && y < 0)
        return "Tercer cuadrante";
    else if (x > 0 && y < 0)
        return "Cuarto cuadrante";
    else if (x == 0 && y != 0)
        return "Eje Y";
    else if (y == 0 && x != 0)
        return "Eje X";
    else
        return "Origen";
}

void calcularEcuacionRecta(int x1, int y1, int x2, int y2) {
    if (x1 == x2) {
        cout << "Los puntos están alineados en la recta vertical x = " << x1 << endl;
    } else {
        double pendiente = static_cast<double>(y2 - y1) / (x2 - x1);
        double intercepto = y1 - pendiente * x1;
        cout << "La ecuacion de la recta es: y = " << pendiente << "x + " << intercepto << endl;
    }
}

int main() {
    const int MAX_COORDENADAS = 10;
    int coordenadas[MAX_COORDENADAS][2];
    int n;

    // Solicitar número de coordenadas
    cout << "Ingrese el numero de coordenadas (maximo " << MAX_COORDENADAS << "): ";
    cin >> n;

    if (n < 2 || n > MAX_COORDENADAS) {
        cout << "Numero de coordenadas invalido. Debe estar entre 2 y " << MAX_COORDENADAS << "." << endl;
        return 1;
    }

    // Leer coordenadas
    for (int i = 0; i < n; i++) {
        cout << "Ingrese la coordenada " << i + 1 << " (x y): ";
        cin >> coordenadas[i][0] >> coordenadas[i][1];
    }

    // Determinar cuadrantes
    cout << "\nCuadrantes de las coordenadas:" << endl;
    for (int i = 0; i < n; i++) {
        int x = coordenadas[i][0];
        int y = coordenadas[i][1];
        cout << "Coordenada (" << x << ", " << y << "): " << determinarCuadrante(x, y) << endl;
    }

    // Verificar alineación de las coordenadas
    cout << "\nVerificando alineacion de las coordenadas:" << endl;
    bool alineados = true;
    for (int i = 2; i < n; i++) {
        int x1 = coordenadas[0][0], y1 = coordenadas[0][1];
        int x2 = coordenadas[1][0], y2 = coordenadas[1][1];
        int xi = coordenadas[i][0], yi = coordenadas[i][1];

        // Verificar si están en la misma recta (determinante == 0)
        if ((y2 - y1) * (xi - x1) != (yi - y1) * (x2 - x1)) {
            alineados = false;
            break;
        }
    }

    if (alineados) {
        cout << "Todas las coordenadas estan alineadas." << endl;
        calcularEcuacionRecta(coordenadas[0][0], coordenadas[0][1], coordenadas[1][0], coordenadas[1][1]);
    } else {
        cout << "Las coordenadas no estan alineadas en una misma linea." << endl;
    }

    return 0;
}
