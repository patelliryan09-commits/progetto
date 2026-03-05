#include <iostream>

using namespace std;

int main() {
cout << "Avvio del progetto polinomi" << endl;

int p1[4] = {0, 0, 0, 0};
int p2[4] = {0, 0, 0, 0};

int somma[4] = {0, 0, 0, 0};
int diff[4] = {0, 0, 0, 0};
int prod[7] = {0, 0, 0, 0, 0, 0, 0};

int g1;
int g2;

  system("CLS");

cout << "\n--- INSERIMENTO PRIMO POLINOMIO ---" << endl;
cout << "Grado del primo polinomio: ";
cin >> g1;

for (int i = g1; i >= 0; i--) {
if (i == 0) {
cout << "Immetti il termine noto: ";
} else {
cout << "Immetti il coefficiente di x^" << i << ": ";
}
cin >> p1[i];
}

  system("CLS");
  
cout << "\n--- INSERIMENTO SECONDO POLINOMIO ---" << endl;
cout << "Grado del secondo polinomio: ";
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
int calcolo = p1[i] * p2[j];
prod[esp] = prod[esp] + calcolo;
}
}

cout << "\nIl risultato della somma e' il seguente: " << endl;
for (int i = 3; i >= 0; i--) {
if (somma[i] != 0) {
if (somma[i] > 0) {
cout << "+";
}
cout << somma[i];
if (i > 0) {
cout << "x^" << i << " ";
}
}
}

cout << "\n\nIl risultato della sottrazione e' il seguente: " << endl;
for (int i = 3; i >= 0; i--) {
if (diff[i] != 0) {
if (diff[i] > 0) {
cout << "+";
}
cout << diff[i];
if (i > 0) {
cout << "x^" << i << " ";
}
}
}

cout << "\n\nIl risultato della moltiplicazione e' il seguente: " << endl;
for (int i = g1 + g2; i >= 0; i--) {
if (prod[i] != 0) {
if (prod[i] > 0) {
cout << "+";
}
cout << prod[i];
if (i > 0) {
cout << "x^" << i << " ";
}
}
}

cout << endl;

return 0;
}




