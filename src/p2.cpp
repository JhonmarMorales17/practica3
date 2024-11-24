#include <iostream>
#include <cmath> // Para sqrt y pow
#include <limits> // Para numeric_limits

using namespace std;

struct Punto {
    int x, y;
};

double calcularDistancia(const Punto& p1, const Punto& p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

bool estaEnCuadrante(const Punto& p, int xmin, int xmax, int ymin, int ymax) {
    return (p.x >= xmin && p.x <= xmax && p.y >= ymin && p.y <= ymax);
}

int main() {
    const int MAX_PUNTOS = 10; 
    Punto puntos[MAX_PUNTOS]; 
    int n;

    cout << "Ingrese el numero de puntos (maximo " << MAX_PUNTOS << "): ";
    cin >> n;

    if (n < 2 || n > MAX_PUNTOS) {
        cout << "Número de puntos invalido. Debe estar entre 2 y " << MAX_PUNTOS << "." << endl;
        return 1;
    }

    for (int i = 0; i < n; i++) {
        cout << "Ingrese el punto " << i + 1 << " (x y): ";
        cin >> puntos[i].x >> puntos[i].y;
    }

    int xmin, xmax, ymin, ymax;
    cout << "\nIngrese los lImites del cuadrante:" << endl;
    cout << "xmin: ";
    cin >> xmin;
    cout << "xmax: ";
    cin >> xmax;
    cout << "ymin: ";
    cin >> ymin;
    cout << "ymax: ";
    cin >> ymax;

    double distanciaMaxima = -1.0;
    Punto puntoA, puntoB;

    for (int i = 0; i < n; i++) {
        if (!estaEnCuadrante(puntos[i], xmin, xmax, ymin, ymax)) continue;
        for (int j = i + 1; j < n; j++) {
            if (!estaEnCuadrante(puntos[j], xmin, xmax, ymin, ymax)) continue;
            double distancia = calcularDistancia(puntos[i], puntos[j]);
            if (distancia > distanciaMaxima) {
                distanciaMaxima = distancia;
                puntoA = puntos[i];
                puntoB = puntos[j];
            }
        }
    }

    if (distanciaMaxima < 0) {
        cout << "\nNo hay suficientes puntos dentro del cuadrante para calcular distancias." << endl;
    } else {
        cout << "\nLa distancia maxima es " << distanciaMaxima << " entre los puntos ("
             << puntoA.x << ", " << puntoA.y << ") y (" << puntoB.x << ", " << puntoB.y << ")." << endl;
    }

    int indice;
    cout << "\nSeleccione un punto del arreglo (1 a " << n << "): ";
    cin >> indice;

    if (indice < 1 || indice > n) {
        cout << "Índice fuera de rango." << endl;
        return 1;
    }

    Punto puntoSeleccionado = puntos[indice - 1];
    cout << "\nDistancias desde el punto (" << puntoSeleccionado.x << ", " << puntoSeleccionado.y << "):" << endl;

    for (int i = 0; i < n; i++) {
        if (i == indice - 1) continue;
        if (estaEnCuadrante(puntos[i], xmin, xmax, ymin, ymax)) {
            double distancia = calcularDistancia(puntoSeleccionado, puntos[i]);
            cout << "  -> Hasta el punto (" << puntos[i].x << ", " << puntos[i].y << "): " << distancia << endl;
        }
    }

    return 0;
}
