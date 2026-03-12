#include <iostream>
#include <cstdlib>
#include <cmath> 
#include <iomanip>
#include<cctype>
#include "graphics2.h" 

/* =============================================================
   PROGETTO: SISTEMA AVANZATO ANALISI POLINOMI 
   
   
   =============================================================
*/

using namespace std;

int main() {
    // ---------------------------------------------------------
    // 1. MESSAGGIO DI  (INIZIALIZZAZIONE)
    // ---------------------------------------------------------
    cout << "Avvio del progetto polinomi..." << endl;
    cout << "Caricamento moduli matematici e grafici..." << endl;

    
    int p1[4], p2[4], somma[4], diff[4], prod[7];
    int g1, g2, scelta, sceltaDelta;
    int gd = 0, gm = 0; 

    // ---------------------------------------------------------
    // 2. INTERFACCIA GRAFICA  
    // ---------------------------------------------------------
    system("cls");
    system("color 0B"); 

    cout << "\n\n";
    cout << "          ._______________________________________________________." << endl;
    cout << "          |                                                       |" << endl;
    cout << "          |      ___________________________________________      |" << endl;
    cout << "          |     |                                           |     |" << endl;
    cout << "          |     |    >>> IL NOSTRO PROGETTO POLINOMI <<<    |     |" << endl;
    cout << "          |     |___________________________________________|     |" << endl;
    cout << "          |                                                       |" << endl;
    cout << "          |                                                       |" << endl;
    cout << "          |           [ Sistema in fase di avvio ]..              |" << endl;
    cout << "          |                                                       |" << endl;
    cout << "          |                                                       |" << endl;
    cout << "          |    _______________________________________________    |" << endl;
    cout << "          |   |                                               |   |" << endl;
    cout << "          |   |   Premi un tasto per avviare il programma...  |   |" << endl;
    cout << "          |   |_______________________________________________|   |" << endl;
    cout << "          |                                                       |" << endl;
    cout << "          |_______________________________________________________|" << endl;
    cout << "           Professional Edition - 2026" << endl;
    
    system("pause > nul"); 

    // ---------------------------------------------------------
    // 3. FASE DI INSERIMENTO DATI (INPUT STREAM)
    // ---------------------------------------------------------
    inserimento:
    
    for(int i=0; i<4; i++) { p1[i]=0; p2[i]=0; somma[i]=0; diff[i]=0; }
    for(int i=0; i<7; i++) { prod[i]=0; }

    system("cls");
    system("color 0B");
    cout << "  ___________________________________________________________" << endl;
    cout << " |                                                           |" << endl;
    cout << " |         ===> CONFIGURAZIONE PRIMO POLINOMIO <===          |" << endl;
    cout << " |___________________________________________________________|" << endl;
    cout << "\n  Inserisci il grado del primo polinomio (massimo 3): ";
    cin >> g1;
    
    while(g1 > 3 ) {
        cout << "  [!] Errore: il grado massimo supportato e' 3: ";
        cin >> g1;
    }
    while(isalpha(g1))
    {
    	cout << "  [!] Errore: il programma registra solo numeri: ";
        cin >> g1;	
	}

    for (int i = g1; i >= 0; i--) {
        if (i == 0) 
		{
			cout << "  [?] Immetti il TERMINE NOTO: ";
		}
        else 
		{
			cout << "  [?] Immetti il coefficiente di x^" << i << ": ";
		}
        cin >> p1[i];
    }

    system("cls");
    cout << "  ___________________________________________________________" << endl;
    cout << " |                                                           |" << endl;
    cout << " |         ===> CONFIGURAZIONE SECONDO POLINOMIO <===        |" << endl;
    cout << " |___________________________________________________________|" << endl;
    cout << "\n  Inserisci il grado del secondo polinomio (massimo 3): ";
    cin >> g2;

    while(g2 > 3) 
	{
        cout << "  [!] Errore: il grado massimo supportato e' 3: ";
        cin >> g2;
    }
    while(isalpha(g2))
    {
    	cout << "  [!] Errore: il programma registra solo numeri: ";
        cin >> g2;	
	}

    for (int i = g2; i >= 0; i--) {
        if (i == 0) cout << "  [?] Immetti il TERMINE NOTO: ";
        else cout << "  [?] Immetti il coefficiente di x^" << i << ": ";
        cin >> p2[i];
    }

    // ---------------------------------------------------------
    // 4. ELABORAZIONE MATEMATICA E NUOVO MESSAGGIO STATO
    // ---------------------------------------------------------
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
    system("color 0F"); 
    cout << "\n\n";
    cout << "          .--------------------------------------------." << endl;
    cout << "          |            SISTEMA DI CALCOLO              |" << endl;
    cout << "          |--------------------------------------------|" << endl;
    cout << "          |  Stato: Elaborazione completata            |" << endl;
    cout << "          |  Dati: Polinomi caricati correttamente     |" << endl;
    cout << "          '--------------------------------------------'" << endl;
    cout << "\n          Digita un numero per visualizzare il menu: ";
    cin >> scelta;

    // ---------------------------------------------------------
    // 5. PANNELLO DI CONTROLLO (USER INTERFACE) 
    // ---------------------------------------------------------
    do {
        system("cls");
        system("color 0B"); 
        cout << "  ===============================================" << endl;
        cout << "  ||            PANNELLO DI CONTROLLO          ||" << endl;
        cout << "  ===============================================" << endl;
        cout << "  ||                                           ||" << endl;
        cout << "  || [1] ADDIZIONE       (Pol 1 + Pol 2)       ||" << endl;
        cout << "  || [2] SOTTRAZIONE     (Pol 1 - Pol 2)       ||" << endl;
        cout << "  || [3] MOLTIPLICAZIONE (Pol 1 * Pol 2)       ||" << endl;
        cout << "  || [4] RICERCA ZERI    (Studio P(x)=0)       ||" << endl;
        cout << "  || [5] RICERCA E VISUALIZZAZIONE             ||" << endl;
        cout << "  ||     DEI PUNTI DI INTERSEZIONE             ||" << endl;
        cout << "  || [6] GRAFICO DEI POLINOMI                  ||" << endl;
        cout << "  || [7] RESET SISTEMA                         ||" << endl;
		cout << "  || [0] TERMINA PROGRAMMA                     ||" << endl;
		cout << "  ||                                           ||" << endl;
        cout << "  ===============================================" << endl;
        cout << "\n  Scelta operativa: ";
        cin >> scelta;

        system("cls");
        
        if (scelta == 1) {
            system("color 0F");
            cout << "  [!] RISULTATO: Polinomio 1 + Polinomio 2" << endl;
            cout << "  P(somma) = ";
            for (int i = 3; i >= 0; i--) {
                if (somma[i] != 0) {
                    if (somma[i] > 0 && i < 3) cout << "+";
                    cout << somma[i];
                    if (i > 0) cout << "x^" << i << " ";
                }
            }
        } 
        else if (scelta == 2) {
            system("color 0F");
            cout << "  [!] RISULTATO: Polinomio 1 - Polinomio 2" << endl;
            cout << "  P(diff) = ";
            for (int i = 3; i >= 0; i--) {
                if (diff[i] != 0) {
                    if (diff[i] > 0 && i < 3) cout << "+";
                    cout << diff[i];
                    if (i > 0) cout << "x^" << i << " ";
                }
            }
        } 
        else if (scelta == 3) {
            system("color 0F");
            cout << "  [!] RISULTATO: Polinomio 1 * Polinomio 2" << endl;
            cout << "  P(prod) = ";
            for (int i = g1 + g2; i >= 0; i--) {
                if (prod[i] != 0) {
                    if (prod[i] > 0 && i < (g1+g2)) cout << "+";
                    cout << prod[i];
                    if (i > 0) cout << "x^" << i << " ";
                }
            }
        }
        else if (scelta == 4) {
            system("color 0A");
            cout << "  ===============================================" << endl;
            cout << "  ||       QUALE POLINOMIO VUOI STUDIARE?      ||" << endl;
            cout << "  ===============================================" << endl;
            cout << "  || [1] STUDIO POLINOMIO 1                    ||" << endl;
            cout << "  || [2] STUDIO POLINOMIO 2                    ||" << endl;
            cout << "  || [3] STUDIO ENTRAMBI                       ||" << endl;
            cout << "  ===============================================" << endl;
            cout << "\n  Inserisci scelta: "; cin >> sceltaDelta;
            system("cls");

            for(int k=1; k<=2; k++) {
                if((sceltaDelta == 1 && k == 2) || (sceltaDelta == 2 && k == 1)) continue;
                int* p = (k == 1) ? p1 : p2;
                int g = (k == 1) ? g1 : g2;
                
                cout << "  [ ANALISI MATEMATICA POLINOMIO " << k << ": P(x)=0 ]" << endl;
                cout << "  -----------------------------------------------" << endl;
                if (g == 1) {
                    double a = p[1], b = p[0];
                    cout << "  > EQUAZIONE DI I GRADO (Lineare)" << endl;
                    cout << "  > Risultato: x = " << -b/a << endl;
                } else if (g == 2) {
                    double a = p[2], b = p[1], c = p[0];
                    double delta = (b * b) - (4 * a * c);
                    cout << "  > EQUAZIONE DI II GRADO (Quadratica)" << endl;
                    cout << "  > Calcolo: Delta = " << delta << endl;
                    if (delta > 0) {
                        cout << "  > DELTA POSITIVO: x1 = " << (-b+sqrt(delta))/(2*a) << " | x2 = " << (-b-sqrt(delta))/(2*a) << endl;
                    } else if (delta == 0) {
                        cout << "  > DELTA NULLO: x1 = x2 = " << -b/(2*a) << endl;
                    } else cout << "  > DELTA NEGATIVO: Nessuna soluzione reale (R)." << endl;
                } else cout << "  > Grado " << g << " non supportato per il Delta." << endl;
                cout << "  -----------------------------------------------\n" << endl;
            }
        }
        else if (scelta == 5) goto inserimento;

        if (scelta != 0) {
            cout << "\n  Premi un numero per tornare al pannello... ";
            int pausa; cin >> pausa;
        }
        
        else if (scelta == 6) goto inserimento;

        if (scelta != 0) {
            cout << "\n  Premi un numero per tornare al pannello... ";
            int pausa; cin >> pausa;
        }
        
        else if (scelta == 7) goto inserimento;

        if (scelta != 0) {
            cout << "\n  Premi un numero per tornare al pannello... ";
            int pausa; cin >> pausa;
        }
        
        else if (scelta == 7) goto inserimento;
        
    } while (scelta != 0);

    // ---------------------------------------------------------
    // 6. TERMINAZIONE
    // ---------------------------------------------------------
    system("cls");
    cout << "\n  Chiusura del sistema in corso..." << endl;
    cout << "  Sviluppato con successo. Arrivederci!" << endl;
    return 0;
}

