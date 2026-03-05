#include <iostream>

using namespace std;

int main() {
    cout << "Avvio del progetto polinomi" << endl;

    int p1[4] = {0, 0, 0, 0}; //primo polinomio
    int p2[4] = {0, 0, 0, 0}; //secondo polinomio
    
    int somma[4] = {0, 0, 0, 0}; //array per la somma
    int diff[4] = {0, 0, 0, 0}; //array per la differenza
    int prod[7] = {0, 0, 0, 0, 0, 0, 0}; //array per il prodotto

    int g1; //grado massimo del primo polinomio
    int g2; //grado massimo del secondo polinomio

    cout << "\nGrado del primo polinomio: ";
    cin >> g1;

    for (int i = g1; i >= 0; i--) {
        if (i == 0) {
            cout << "Immetti il termine noto: ";
        } else {
            cout << "Immetti il coefficiente di x^" << i << ": ";
        }
        cin >> p1[i];
    }

    cout << "\nGrado del secondo polinomio: ";
    cin >> g2;

    for (int i = g2; i >= 0; i--) {
        if (i == 0) {
            cout << "Immetti il termine noto: ";
        } else {
            cout << "Immetti il coefficiente di x^" << i << ": ";
        }
        cin >> p2[i];
    }

    for (int i = 0; i < 4; i++) {
        somma[i] = p1[i] + p2[i];
    }

    for (int i = 0; i < 4; i++) {
        diff[i] = p1[i] - p2[i];
    }

    for (int i = 0; i <= g1; i++) {
        for (int j = 0; j <= g2; j++) {
            int esp = i + j;
            prod[esp] = prod[esp] + (p1[i] * p2[j]);
        }
    }

    cout << "\nIl risultato della somma e' il seguente: " << endl;
    for (int i = 3; i >= 0; i--) {
        if (somma[i] != 0) {
            if (somma[i] > 0) cout << "+"; 
            cout << somma[i] << "x^" << i << " ";
        }
    }

    cout << "\n\nIl risultato della sottrazione e' il seguente: " << endl;
    for (int i = 3; i >= 0; i--) {
        if (diff[i] != 0) {
            if (diff[i] > 0) cout << "+";
            cout << diff[i] << "x^" << i << " ";
        }
    }

    cout << "\n\nIl risultato della moltiplicazione e' il seguente: " << endl;
    for (int i = g1 + g2; i >= 0; i--) {
        if (prod[i] != 0) {
            if (prod[i] > 0) cout << "+";
            cout << prod[i] << "x^" << i << " ";
        }
    }

    cout << endl;

    return 0;
}

