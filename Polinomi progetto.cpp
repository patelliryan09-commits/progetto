#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int p1[4], p2[4], somma[4], diff[4], prod[7];
    int g1, g2, scelta;

    system("cls");
    cout << " ................................................." << endl;
    cout << " :                                               :" << endl;
    cout << " :        IL NOSTRO PROGETTO POLINOMI !!!        :" << endl;
    cout << " :                                               :" << endl;
    cout << " :...............................................:" << endl;
    cout << "\n  [>] Digita un numero per ACCEDERE al sistema: ";
    cin >> scelta;

    inserimento:
    
    for(int i=0; i<4; i++) { p1[i]=0; p2[i]=0; somma[i]=0; diff[i]=0; }
    for(int i=0; i<7; i++) { prod[i]=0; }

    system("cls");
    cout << "  _______________________________________________" << endl;
    cout << " |                                               |" << endl;
    cout << " |   ===> STEP 1: CONFIGURA POLINOMIO [A] <===   |" << endl;
    cout << " |_______________________________________________|" << endl;
    cout << "\n  Inserisci il grado (max 3): ";
    cin >> g1;

    for (int i = g1; i >= 0; i--) {
        if (i == 0) cout << "  [?] Immetti il TERMINE NOTO: ";
        else cout << "  [?] Immetti il coefficiente di x^" << i << ": ";
        cin >> p1[i];
    }

    system("cls");
    cout << "  _______________________________________________" << endl;
    cout << " |                                               |" << endl;
    cout << " |   ===> STEP 2: CONFIGURA POLINOMIO [B] <===   |" << endl;
    cout << " |_______________________________________________|" << endl;
    cout << "\n  Inserisci il grado (max 3): ";
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

    do {
        system("cls");
        cout << "  ===============================================" << endl;
        cout << "  ||            PANNELLO DI CONTROLLO          ||" << endl;
        cout << "  ===============================================" << endl;
        cout << "  || [1] Esegui ADDIZIONE       (Pol1 + Pol2)  ||" << endl;
        cout << "  || [2] Esegui SOTTRAZIONE     (Pol1 - Pol2)  ||" << endl;
        cout << "  || [3] Esegui MOLTIPLICAZIONE (Pol1 * Pol2)  ||" << endl;
        cout << "  || [4] RE-INSERISCI DATI (Torna Indietro)    ||" << endl;
        cout << "  || [0] TERMINA SESSIONE                      ||" << endl;
        cout << "  ===============================================" << endl;
        cout << "\n  Seleziona l'operazione: ";
        cin >> scelta;

        system("cls");
        if (scelta == 1) {
            cout << "  [!] RISULTATO ADDIZIONE: Polinomio 1 + Polinomio 2" << endl;
            cout << "  --------------------------------------------------" << endl;
            cout << "  P(s) = ";
            for (int i = 3; i >= 0; i--) {
                if (somma[i] != 0) {
                    if (somma[i] > 0) cout << "+";
                    cout << somma[i];
                    if (i > 0) cout << "x^" << i << " ";
                }
            }
            cout << "\n\n  Premi un numero per tornare al pannello... ";
            int pausa; cin >> pausa;
        } 
        else if (scelta == 2) {
            cout << "  [!] RISULTATO SOTTRAZIONE: Polinomio 1 - Polinomio 2" << endl;
            cout << "  ----------------------------------------------------" << endl;
            cout << "  P(d) = ";
            for (int i = 3; i >= 0; i--) {
                if (diff[i] != 0) {
                    if (diff[i] > 0) cout << "+";
                    cout << diff[i];
                    if (i > 0) cout << "x^" << i << " ";
                }
            }
            cout << "\n\n  Premi un numero per tornare al pannello... ";
            int pausa; cin >> pausa;
        } 
        else if (scelta == 3) {
            cout << "  [!] RISULTATO PRODOTTO: Polinomio 1 * Polinomio 2" << endl;
            cout << "  -------------------------------------------------" << endl;
            cout << "  P(m) = ";
            for (int i = g1 + g2; i >= 0; i--) {
                if (prod[i] != 0) {
                    if (prod[i] > 0) cout << "+";
                    cout << prod[i];
                    if (i > 0) cout << "x^" << i << " ";
                }
            }
            cout << "\n\n  Premi un numero per tornare al pannello... ";
            int pausa; cin >> pausa;
        }
        else if (scelta == 4) {
            cout << "  |||||||||||||||||||||||||||||||||||||||||||||||" << endl;
            cout << "  |                                             |" << endl;
            cout << "  |    RESET SISTEMA: TORNO ALL'INIZIO...       |" << endl;
            cout << "  |                                             |" << endl;
            cout << "  |||||||||||||||||||||||||||||||||||||||||||||||" << endl;
            cout << "\n  Attendere... Premi un numero per confermare: ";
            int pausa; cin >> pausa;
            goto inserimento;
        }
    } while (scelta != 0);

    return 0;
}






