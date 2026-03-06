#include <iostream>
#include <cstdlib>
#include <cmath> 

using namespace std;

int main() {
    
    cout << "Avvio del progetto polinomi" << endl;

    int p1[4], p2[4], somma[4], diff[4], prod[7];
    int g1, g2, scelta;

    
    system("cls");
    cout << " ................................................." << endl;
    cout << " :                                               :" << endl;
    cout << " :        IL NOSTRO PROGETTO POLINOMI !!!        :" << endl;
    cout << " :                                               :" << endl;
    cout << " :...............................................:" << endl;
    cout << "\n  [ SISTEMA IN FASE DI AVVIO... ]" << endl;
    cout << "\n  Premi un numero per ENTRARE: ";
    cin >> scelta;

    inserimento:
    for(int i=0; i<4; i++) { p1[i]=0; p2[i]=0; somma[i]=0; diff[i]=0; }
    for(int i=0; i<7; i++) { prod[i]=0; }

    
    system("cls");
    cout << "  _______________________________________________" << endl;
    cout << " |                                               |" << endl;
    cout << " |   ===> CONFIGURAZIONE PRIMO POLINOMIO <===    |" << endl;
    cout << " |_______________________________________________|" << endl;
    cout << "\n  Inserisci il grado del primo polinomio (massimo 3): ";
    cin >> g1;

    for (int i = g1; i >= 0; i--) {
        if (i == 0) cout << "  [?] Immetti il TERMINE NOTO: ";
        else cout << "  [?] Immetti il coefficiente di x^" << i << ": ";
        cin >> p1[i];
    }

    
    system("cls");
    cout << "  _______________________________________________" << endl;
    cout << " |                                               |" << endl;
    cout << " |   ===> CONFIGURAZIONE SECONDO POLINOMIO <===  |" << endl;
    cout << " |_______________________________________________|" << endl;
    cout << "\n  Inserisci il grado del secondo polinomio (massimo 3): ";
    cin >> g2;

    for (int i = g2; i >= 0; i--) {
        if (i == 0) cout << "  [?] Immetti il TERMINE NOTO: ";
        else cout << "  [?] Immetti il coefficiente di x^" << i << ": ";
        cin >> p2[i];
    }

   
    for (int i = 0; i < 4; i++) {
        somma[i] = p1[i] + p2[i];
        diff[i] = p1[i] - p2[i];
    }
    for (int i = 0; i <= g1; i++) {
        for (int j = 0; j <= g2; j++) {
            prod[i + j] = prod[i + j] + (p1[i] * p2[j]);
        }
    }

    system("cls");
    cout << "\n\n          /----------------------------\\" << endl;
    cout << "          |      A TE LA SCELTA...     |" << endl;
    cout << "          \\----------------------------/" << endl;
    cout << "\n          Analisi dei dati completata." << endl;
    cout << "          Premi un numero per il MENU: ";
    cin >> scelta;

    do {
        system("cls");
        cout << "  ===============================================" << endl;
        cout << "  ||            PANNELLO DI CONTROLLO          ||" << endl;
        cout << "  ===============================================" << endl;
        cout << "  || [1] Somma          (Pol1 + Pol2)          ||" << endl;
        cout << "  || [2] Sottrazione    (Pol1 - Pol2)          ||" << endl;
        cout << "  || [3] Moltiplicazione(Pol1 * Pol2)          ||" << endl;
        cout << "  || [4] RICERCA ZERI   (Analisi P(x)=0)       ||" << endl;
        cout << "  || [5] RESET DATI     (Torna Indietro)       ||" << endl;
        cout << "  || [0] ESCI DAL SISTEMA                      ||" << endl;
        cout << "  ===============================================" << endl;
        cout << "\n  Seleziona l'operazione: ";
        cin >> scelta;

        system("cls");
        if (scelta == 1) {
            cout << "  [!] RISULTATO: POLINOMIO 1 + POLINOMIO 2" << endl;
            cout << "  ----------------------------------------" << endl;
            cout << "  P(s) = ";
            for (int i = 3; i >= 0; i--) {
                if (somma[i] != 0) {
                    if (somma[i] > 0) cout << "+";
                    cout << somma[i];
                    if (i > 0) cout << "x^" << i << " ";
                }
            }
        } 
        else if (scelta == 2) {
            cout << "  [!] RISULTATO: POLINOMIO 1 - POLINOMIO 2" << endl;
            cout << "  ----------------------------------------" << endl;
            cout << "  P(d) = ";
            for (int i = 3; i >= 0; i--) {
                if (diff[i] != 0) {
                    if (diff[i] > 0) cout << "+";
                    cout << diff[i];
                    if (i > 0) cout << "x^" << i << " ";
                }
            }
        } 
        else if (scelta == 3) {
            cout << "  [!] RISULTATO: POLINOMIO 1 * POLINOMIO 2" << endl;
            cout << "  ----------------------------------------" << endl;
            cout << "  P(m) = ";
            for (int i = g1 + g2; i >= 0; i--) {
                if (prod[i] != 0) {
                    if (prod[i] > 0) cout << "+";
                    cout << prod[i];
                    if (i > 0) cout << "x^" << i << " ";
                }
            }
        }
        else if (scelta == 4) {
            cout << "  STUDIO DEL POLINOMIO: P(x) = 0" << endl;
            cout << "  ......................................." << endl;
            
            if (g1 == 1) {
                
                double a = p1[1];
                double b = p1[0];
                double x = -b / a;
                cout << "  > Grado rilevato: 1 (Equazione Lineare)" << endl;
                cout << "  > Formula applicata: x = -b / a" << endl;
                cout << "  > RISULTATO: x = " << x << endl;
            } 
            else if (g1 == 2) {
                
                double a = p1[2];
                double b = p1[1];
                double c = p1[0];
                double delta = (b * b) - (4 * a * c);
                
                cout << "  > Grado rilevato: 2 (Equazione Quadrata)" << endl;
                cout << "  > Calcolo del discriminante (Delta): " << delta << endl;
                
                if (delta > 0) {
                    double x1 = (-b + sqrt(delta)) / (2 * a);
                    double x2 = (-b - sqrt(delta)) / (2 * a);
                    cout << "  > Delta positivo: Due soluzioni reali e distinte" << endl;
                    cout << "  > x1 = " << x1 << endl;
                    cout << "  > x2 = " << x2 << endl;
                } else if (delta == 0) {
                    double x = -b / (2 * a);
                    cout << "  > Delta nullo: Due soluzioni reali e coincidenti" << endl;
                    cout << "  > x = " << x << endl;
                } else {
                    cout << "  > Delta negativo: Nessuna soluzione reale (Impossibile)" << endl;
                }
            } else {
                cout << "  [!] NOTA: Studio disponibile solo per gradi 1 e 2." << endl;
            }
            cout << "  ......................................." << endl;
        }
        else if (scelta == 5) {
            cout << "  |||||||||||||||||||||||||||||||||||||||||||||||" << endl;
            cout << "  |    RESET SISTEMA: TORNO ALL'INIZIO...       |" << endl;
            cout << "  |||||||||||||||||||||||||||||||||||||||||||||||" << endl;
            int pausa; cin >> pausa;
            goto inserimento;
        }

        if (scelta != 0) {
            cout << "\n\n  Premi un numero per tornare al menu... ";
            int pausa; cin >> pausa;
        }
    } while (scelta != 0);

    return 0;
}
