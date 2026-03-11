#include <iostream>
#include <cstdlib>
#include <cmath> 

using namespace std;

int main() {
    // Frase obbligatoria per il display
    cout << "Avvio del progetto polinomi" << endl;

    int p1[4], p2[4], somma[4], diff[4], prod[7];
    int g1, g2, scelta, subScelta;

    // --- TITOLO INIZIALE ---
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

    // --- INPUT POLINOMIO 1 ---
    system("cls");
    cout << "  _______________________________________________" << endl;
    cout << " |                                               |" << endl;
    cout << " |   ===> CONFIGURAZIONE PRIMO POLINOMIO <===    |" << endl;
    cout << " |_______________________________________________|" << endl;
    cout << "\n  Inserisci il grado del primo polinomio (massimo 3): ";
    cin >> g1;
    
    while(g1 > 3) {
        cout << "  [!] Attenzione: inserisci un grado massimo di 3: ";
        cin >> g1;
    }

    for (int i = g1; i >= 0; i--) {
        if (i == 0) cout << "  [?] Immetti il TERMINE NOTO: ";
        else cout << "  [?] Immetti il coefficiente di x^" << i << ": ";
        cin >> p1[i];
    }

    // --- INPUT POLINOMIO 2 ---
    system("cls");
    cout << "  _______________________________________________" << endl;
    cout << " |                                               |" << endl;
    cout << " |   ===> CONFIGURAZIONE SECONDO POLINOMIO <===  |" << endl;
    cout << " |_______________________________________________|" << endl;
    cout << "\n  Inserisci il grado del secondo polinomio (massimo 3): ";
    cin >> g2;

    while(g2 > 3) {
        cout << "  [!] Attenzione: inserisci un grado massimo di 3: ";
        cin >> g2;
    }

    for (int i = g2; i >= 0; i--) {
        if (i == 0) cout << "  [?] Immetti il TERMINE NOTO: ";
        else cout << "  [?] Immetti il coefficiente di x^" << i << ": ";
        cin >> p2[i];
    }

    // --- CALCOLI GENERALI ---
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
    cout << "          Premi un numero per il menu: ";
    cin >> scelta;

    do {
        system("cls");
        cout << "  ===============================================" << endl;
        cout << "  ||            PANNELLO DI CONTROLLO          ||" << endl;
        cout << "  ===============================================" << endl;
        cout << "  || [1] Esegui ADDIZIONE       (Pol1 + Pol2)  ||" << endl;
        cout << "  || [2] Esegui SOTTRAZIONE     (Pol1 - Pol2)  ||" << endl;
        cout << "  || [3] Esegui MOLTIPLICAZIONE (Pol1 * Pol2)  ||" << endl;
        cout << "  || [4] RICERCA ZERI           (Analisi P=0)  ||" << endl;
        cout << "  || [5] RESET SISTEMA          (Reset)        ||" << endl;
        cout << "  || [0] ESCI DAL PROGRAMMA                    ||" << endl;
        cout << "  ===============================================" << endl;
        cout << "\n  Seleziona l'operazione: ";
        cin >> scelta;

        system("cls");
        if (scelta == 1) {
            cout << "  [!] RISULTATO SOMMA: " << endl;
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
            cout << "  [!] RISULTATO SOTTRAZIONE: " << endl;
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
            cout << "  [!] RISULTATO MOLTIPLICAZIONE: " << endl;
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
            cout << "  QUALE POLINOMIO VUOI ANALIZZARE?" << endl;
            cout << "  [1] Polinomio 1" << endl;
            cout << "  [2] Polinomio 2" << endl;
            cout << "  Scelta: ";
            cin >> subScelta;

            int* pTemp;
            int gTemp;
            if(subScelta == 2) { pTemp = p2; gTemp = g2; }
            else { pTemp = p1; gTemp = g1; }

            system("cls");
            cout << "  STUDIO DEL POLINOMIO: P(x) = 0" << endl;
            cout << "  ......................................." << endl;
            
            if (gTemp == 0) {
                cout << "  > Grado 0: Equazione costante." << endl;
                if (pTemp[0] == 0) cout << "  > Indeterminata (0=0)." << endl;
                else cout << "  > Impossibile (" << pTemp[0] << "=0)." << endl;
            }
            else if (gTemp == 1) {
                double a = pTemp[1], b = pTemp[0];
                cout << "  > Grado 1 (Lineare)" << endl;
                cout << "  > RISULTATO: x = " << -b / a << endl;
            } 
            else if (gTemp == 2) {
                double a = pTemp[2], b = pTemp[1], c = pTemp[0];
                double delta = (b * b) - (4 * a * c);
                cout << "  > Grado 2 (Quadrata)" << endl;
                cout << "  > Delta: " << delta << endl;
                
                if (delta > 0) {
                    cout << "  > Due soluzioni reali:" << endl;
                    cout << "    x1 = " << (-b + sqrt(delta)) / (2 * a) << endl;
                    cout << "    x2 = " << (-b - sqrt(delta)) / (2 * a) << endl;
                } else if (delta == 0) {
                    cout << "  > Soluzione reale coincidente:" << endl;
                    cout << "    x = " << -b / (2 * a) << endl;
                } else {
                    cout << "  > Delta Negativo (" << delta << ")" << endl;
                    cout << "  > RISULTATO: IMPOSSIBILE in R." << endl;
                }
            } else {
                cout << "  [!] Studio disponibile solo per gradi 1 e 2." << endl;
            }
            cout << "  ......................................." << endl;
        }
        else if (scelta == 5) {
            cout << "  //===========================================\\\\" << endl;
            cout << "  ||                                           ||" << endl;
            cout << "  ||    RESET SISTEMA... TORNO ALL'INIZIO      ||" << endl;
            cout << "  ||    RIPRISTINO CONFIGURAZIONE IN CORSO     ||" << endl;
            cout << "  ||                                           ||" << endl;
            cout << "  \\\\===========================================//" << endl;
            cout << "\n  Premi un numero per confermare... ";
            int pausa; cin >> pausa;
            goto inserimento;
        }

        if (scelta != 0) {
            cout << "\n\n  Premi un numero per tornare al pannello... ";
            int pausa; cin >> pausa;
        }
    } while (scelta != 0);

    return 0;
}

