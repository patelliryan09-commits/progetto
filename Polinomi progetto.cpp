#include <iostream>  // Libreria standard per input (cin) e output (cout)
#include <cstdlib>   // Serve per i comandi di sistema come "cls" (pulisce lo schermo) e "color"
#include <cmath>     // Fondamentale per le funzioni matematiche come pow() (potenza) e sqrt() (radice)
#include <iomanip>   // Serve per gestire la formattazione dell'output (spazi, precisione decimali)
#include <cctype>    // Usata per la funzione toupper() che trasforma le lettere in maiuscolo
#include <conio.h>   // Fornisce getch(), usato per bloccare la schermata finché non premi un tasto
#include "graphics2.h" // La libreria esterna per disegnare il piano cartesiano e i polinomi

using namespace std;

int main() {
    
    // --- MESSAGGI DI AVVIO ---
    // Usiamo sequenze ANSI (\033[3m) per rendere il testo corsivo e dare un tocco in piu' al programma
    cout << "\033[3mAvvio del progetto polinomi...\033[0m" << endl;
    cout << "\033[3mCaricamento moduli matematici e grafici...\033[0m" << endl;

    // --- DICHIARAZIONE VARIABILI ---
    // p1 e p2 sono array di 4 elementi: p[0] è il termine noto, p[1] è x^1, p[2] è x^2, p[3] è x^3
    int p1[4], p2[4], somma[4], diff[4], prod[7];
    int g1, g2, scelta, sceltaDelta;
    double x1, x2, y1, y2, delta; 

    // --- 2. INTERFACCIA GRAFICA ---
    system("cls");      // Pulisce la console
    system("color 0B"); // Imposta lo sfondo nero (0) e il testo azzurro chiaro (B)

    // Cornice ASCII Art per il titolo iniziale
    cout << "\n\n";
    cout << "          ._______________________________________________________." << endl;
    cout << "          |                                                       |" << endl;
    cout << "          |      ___________________________________________      |" << endl;
    cout << "          |     |                                           |     |" << endl;
    cout << "          |     |    >>> IL NOSTRO PROGETTO POLINOMI <<<    |     |" << endl;
    cout << "          |     |___________________________________________|     |" << endl;
    cout << "          |                                                       |" << endl;
    cout << "          |                                                       |" << endl;
    cout << "          |                   [ Sistema in fase di avvio ]..      |" << endl;
    cout << "          |                                                       |" << endl;
    cout << "          |                                                       |" << endl;
    cout << "          |      _______________________________________________  | " << endl;
    cout << "          |     |                                               | |" << endl;
    cout << "          |     |    Premi un tasto per avviare il programma... | |" << endl;
    cout << "          |     |_______________________________________________| |" << endl;
    cout << "          |                                                       |" << endl;
    cout << "          |_______________________________________________________|" << endl;                        
    system("pause > nul"); // Blocca il programma finché non premi un tasto (nasconde il messaggio di default)
    

    // --- ETICHETTA DI RESET (GOTO) ---
    // Se l'utente sceglie "Reset", il programma torna qui e azzera tutti i coefficienti
    inserimento:
    for(int i=0; i<4; i++) { p1[i]=0; p2[i]=0; somma[i]=0; diff[i]=0; }
    for(int i=0; i<7; i++) { prod[i]=0; } // Il prodotto può arrivare fino al grado 6 (3+3)

    // --- CONFIGURAZIONE PRIMO POLINOMIO ---
    system("cls");
    system("color 0B");
    cout << "  ___________________________________________________________" << endl;
    cout << " |                                                           |" << endl;
    cout << " |            ===> CONFIGURAZIONE PRIMO POLINOMIO <===       |" << endl;
    cout << " |___________________________________________________________|" << endl;
    cout << "\n\033[3m  Inserisci il grado del primo polinomio (massimo 3): \033[0m";
    
    // Controllo  dell'input: se inserisco lettere o numeri > 3, il programma non crasha
    while(!(cin >> g1) || g1 > 3 || g1 < 0) {
        if(cin.fail()){
             cout << "  \033[1;31;3m[!] Inserisci un numero valido , non una lettera o caratteri speciali mi raccomando: \033[0m";
        } else {
             cout << "  \033[1;31;3m[!] Attenzione RIPROVA il grado massimo e' 3 : \033[0m";
        }
        cin.clear(); // Resetta lo stato di errore di cin
        cin.ignore(1000, '\n'); // Svuota il buffer per evitare loop infiniti
    }

    // Ciclo per inserire i coefficienti partendo dal grado più alto
    for (int i = g1; i >= 0; i--) {
        if (i == 0) cout << "\033[3m  [?] Immetti il TERMINE NOTO: \033[0m";
        else cout << "  \033[32;3m[?] Immetti il coefficiente di \033[33m" << "x^" << i << "\033[0m\033[3m: \033[0m";
        while(!(cin >> p1[i])) {
            cout << "  \033[1;31;3m[!] Inserisci un numero valido , non una lettera o caratteri speciali mi raccomando: \033[0m";
            cin.clear(); cin.ignore(1000, '\n');
        }
    }

    // --- CONFIGURAZIONE SECONDO POLINOMIO ---
    // (Stessa logica di controllo del primo polinomio)
    system("cls");
    system("color 0B");
    cout << "  ___________________________________________________________" << endl;
    cout << " |                                                           |" << endl;
    cout << " |            ===> CONFIGURAZIONE SECONDO POLINOMIO <===     |" << endl;
    cout << " |___________________________________________________________|" << endl;
    cout << "\n\033[3m  Inserisci il grado del secondo polinomio (massimo 3): \033[0m";
    
    while(!(cin >> g2) || g2 > 3 || g2 < 0) {
        if(cin.fail()){
             cout << "  \033[1;31;3m[!] Inserisci un numero valido , non una lettera o caratteri speciali mi raccomando: \033[0m";
        } else {
             cout << "  \033[1;31;3m[!] Attenzione RIPROVA il grado massimo e' 3 : \033[0m";
        }
        cin.clear();
        cin.ignore(1000, '\n');
    }

    for (int i = g2; i >= 0; i--) {
        if (i == 0) cout << "\033[3m  [?] Immetti il TERMINE NOTO: \033[0m";
        else cout << "  \033[32;3m[?] Immetti il coefficiente di \033[33m" << "x^" << i << "\033[0m\033[3m: \033[0m";
        while(!(cin >> p2[i])) {
            cout << "  \033[1;31;3m[!] Inserisci un numero valido , non una lettera o caratteri speciali mi raccomando: \033[0m";
            cin.clear(); cin.ignore(1000, '\n');
        }
    }

    // --- OPERAZIONI ALGEBRICHE ---
    // Calcolo immediato di Somma e Differenza (si sommano i coefficienti dello stesso grado)
    for (int i = 0; i < 4; i++) {
        somma[i] = p1[i] + p2[i];
        diff[i] = p1[i] - p2[i];
    }
    // Calcolo Moltiplicazione: ogni termine del primo moltiplica tutti quelli del secondo
    // Il grado del risultato i+j si accumula nell'array prod
    for (int i = 0; i <= g1; i++) {
        for (int j = 0; j <= g2; j++) {
            prod[i + j] = prod[i + j] + (p1[i] * p2[j]);
        }
    }

    system("cls");
    system("color 0F"); // Testo bianco su sfondo nero
    cout << "\n\n";
    cout << "                  .--------------------------------------------." << endl;
    cout << "                  |               SISTEMA DI CALCOLO            |" << endl;
    cout << "                  |--------------------------------------------|" << endl;
    cout << "                  |  Stato: Elaborazione completata             |" << endl;
    cout << "                  |  Dati: Polinomi caricati correttamente     |" << endl;
    cout << "                  '--------------------------------------------'" << endl;
    cout << "\n\033[3m                  Premi un qualsiasi tasto per visualizzare il menu: \033[0m";
    system("pause > nul");

    // --- LOOP MENU PRINCIPALE ---
    do {
        system("cls");
        system("color 0B"); 
        cout << "  ================================================" << endl;
        cout << "  ||                PANNELLO DI CONTROLLO         ||" << endl;
        cout << "  ================================================" << endl;
        cout << "  ||                                              ||" << endl;
        cout << "  || [1] ADDIZIONE       (Pol 1 + Pol 2)          ||" << endl;
        cout << "  || [2] SOTTRAZIONE     (Pol 1 - Pol 2)          ||" << endl;
        cout << "  || [3] MOLTIPLICAZIONE (Pol 1 * Pol 2)          ||" << endl;
        cout << "  || [4] RICERCA ZERI    (Studio P(x)=0)          ||" << endl;
        cout << "  || [5] INTERSEZIONI    (Punti comuni)           ||" << endl;
        cout << "  || [6] RAPPRESENTAZIONE GRAFICA                 ||" << endl;
        cout << "  || [7] RESET SISTEMA                            ||" << endl;
        cout << "  || [0] ESCI DAL PROGRAMMA                       ||" << endl;
        cout << "  ||                                              ||" << endl;
        cout << "  ================================================" << endl;
        cout << "\n\033[3m  Scelta operativa: \033[0m";
        
        while(!(cin >> scelta) || scelta < 0 || scelta > 7) {
            if(cin.fail()){
                cout << " \033[1;31;3m[!] ERRORE: Devi inserire un NUMERO, non una lettera ne un carattere speciale!\033[0m" << endl;
            } else {
                cout << " \033[1;31;3m[!] Attento il nostro pannello di controllo supporta solo i numeri che sono contenuti nel range (0 , 7) .\033[0m" << endl;
            }
            cout << " \033[3mScelta operativa: \033[0m";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        system("cls");
        
        // --- LOGICA DELLE OPERAZIONI ALGEBRICHE (SCELTE 1, 2, 3) ---
        if (scelta >= 1 && scelta <= 3) {
            system("color 0F"); 
            // Mostra il Polinomio 1 formattato bene (evita di mostrare i gradi con coeff 0)
            cout << "\033[3m  Polinomio 1: (\033[0m";
            bool primoTermine = true;
            for (int i = 3; i >= 0; i--) { 
                if(p1[i] != 0) { 
                    if(p1[i] > 0 && !primoTermine) cout << "+"; 
                    cout << p1[i] << (i > 0 ? "x^" : ""); 
                    if(i > 0) cout << i; 
                    primoTermine = false;
                } 
            }
            if(primoTermine) cout << "0"; 
            cout << "\033[3m) \033[0m";

            // Mostra il segno dell'operazione
            if (scelta == 1) cout << "\033[3m +\033[0m";
            else if (scelta == 2) cout << "\033[3m -\033[0m";
            else if (scelta == 3) cout << "\033[3m *\033[0m";
            cout << "\n";

            // Mostra il Polinomio 2
            cout << "\033[3m  Polinomio 2: (\033[0m";
            primoTermine = true;
            for (int i = 3; i >= 0; i--) { 
                if(p2[i] != 0) { 
                    if(p2[i] > 0 && !primoTermine) cout << "+"; 
                    cout << p2[i] << (i > 0 ? "x^" : ""); 
                    if(i > 0) cout << i; 
                    primoTermine = false;
                } 
            }
            if(primoTermine) cout << "0";
            cout << "\033[3m)\033[0m\n";

            cout << "  -----------------------------------------------\n";
            cout << "  \033[1;31;3m"; 
            if (scelta == 1) cout << "La somma tra i due polinomi e' la seguente p(somma)";
            else if (scelta == 2) cout << "La sottrazione tra i due polinomi e' la seguente p(diff)";
            else if (scelta == 3) cout << "La moltiplicazione tra i due polinomi e' la seguente p(prod)";
            cout << "\033[0m = ";
            
            // Stampa il risultato finale
            bool nullo = true;
            int fine = (scelta == 3) ? (g1+g2) : 3;
            for (int i = fine; i >= 0; i--) {
                int valoreAttuale = 0;
                if (scelta == 1) valoreAttuale = somma[i];
                else if (scelta == 2) valoreAttuale = diff[i];
                else if (scelta == 3) valoreAttuale = prod[i];
                
                if (valoreAttuale != 0) {
                    if (valoreAttuale > 0 && !nullo) cout << "+";
                    cout << valoreAttuale; 
                    if (i > 0) cout << "x^" << i;
                    nullo = false;
                }
            }
            if(nullo) cout << "0";
            cout << endl;
        }
        
        // --- RICERCA ZERI (SCELTA 4) ---
        else if (scelta == 4) {
            system("color 0A"); 
            cout << "  ._____________________________________________. " << endl;
            cout << "  |                                             |" << endl;
            cout << "  |        QUALE POLINOMIO VUOI STUDIARE?       |" << endl;
            cout << "  |_____________________________________________|" << endl;
            cout << "  |                                             |" << endl;
            cout << "  |  [1] STUDIO POLINOMIO 1                     |" << endl;
            cout << "  |  [2] STUDIO POLINOMIO 2                     |" << endl;
            cout << "  |  [3] STUDIO ENTRAMBI                        |" << endl;
            cout << "  |_____________________________________________|" << endl;
            cout << "\n\033[3m  Inserisci scelta: \033[0m"; cin >> sceltaDelta;
            system("cls");
            
            // Ciclo per studiare il polinomio scelto o entrambi
            for(int k=1; k<=2; k++) {
                if((sceltaDelta == 1 && k == 2) || (sceltaDelta == 2 && k == 1)) continue;
                double ta, tb, tc;
                int tg;
                // Assegniamo temporaneamente i coefficienti per il calcolo
                if(k==1) { ta=p1[2]; tb=p1[1]; tc=p1[0]; tg=g1; }
                else { ta=p2[2]; tb=p2[1]; tc=p2[0]; tg=g2; }
                
                cout << "  .-----------------------------------------------." << endl;
                cout << "  |  [ ANALISI MATEMATICA POLINOMIO " << k << ": P(x)=0 ]   |" << endl;
                cout << "  '-----------------------------------------------'" << endl;
                
                // Studio delle soluzioni in base al grado
                if (tg == 0) {
                    if(tc == 0) cout << "\033[32;3m  > EQUAZIONE INDETERMINATA (0=0)\033[0m" << endl;
                    else cout << "\033[32;3m  > EQUAZIONE IMPOSSIBILE (" << tc << "=0)\033[0m" << endl;
                }
                else if (tg == 1) {
                    // Equazione bx + c = 0  -> x = -c/b
                    if(tb == 0) {
                        if(tc == 0) cout << "\033[32;3m  > EQUAZIONE INDETERMINATA\033[0m" << endl;
                        else cout << "\033[32;3m  > EQUAZIONE IMPOSSIBILE\033[0m" << endl;
                    } else {
                        cout << "\033[3m  > EQUAZIONE DI I GRADO (Lineare)\033[0m" << endl;
                        cout << "\033[32;3m  > Risultato: x = " << (double)-tc/tb << "\033[0m" << endl;
                    }
                } else if (tg == 2) {
                    // Formula risolutiva equazioni II grado: Delta = b^2 - 4ac
                    double deltaEq = (tb * tb) - (4 * ta * tc);
                    cout << "\033[3m  > EQUAZIONE DI II GRADO (Quadratica)\033[0m" << endl;
                    cout << "\033[32;3m  > Calcolo: Delta = " << deltaEq << "\033[0m" << endl;
                    if (deltaEq > 0) {
                        cout << "\033[32;3m  > DELTA POSITIVO: x1 = " << (-tb+sqrt(deltaEq))/(2*ta) << " | x2 = " << (-tb-sqrt(deltaEq))/(2*ta) << "\033[0m" << endl;
                    } else if (deltaEq == 0) {
                        cout << "\033[32;3m  > DELTA NULLO: x1 = x2 = " << -tb/(2*ta) << "\033[0m" << endl;
                    } else cout << "\033[32;3m  > DELTA NEGATIVO: Nessuna soluzione reale (R).\033[0m" << endl;
                } else {
                    cout << "\033[32;3m  > Grado " << tg << " non supportato per lo studio degli zeri.\033[0m" << endl;
                }
                cout << "  -----------------------------------------------\n" << endl;
            }
        }
        
        // --- RICERCA INTERSEZIONI (SCELTA 5) ---
        else if (scelta == 5) { 
            system("color 0E"); 
            cout << "\033[3m  [ RICERCA PUNTI DI INTERSEZIONE ]\033[0m" << endl;
            cout << "  -----------------------------------------------" << endl;
            
            // Analisi per gradi fino al secondo
            if(g1 <= 2 && g2 <= 2) {
                // Sottraiamo i due polinomi per trovare dove P1 - P2 = 0
                double a = (double)p1[2] - p2[2];
                double b = (double)p1[1] - p2[1];
                double c = (double)p1[0] - p2[0];

                if(a == 0) { // Caso lineare
                    if(b == 0) {
                        if(c == 0) cout << "\033[3m  [!] COINCIDENTI: Infiniti punti.\033[0m";
                        else cout << "\033[3m  [!] PARALLELE: Nessun punto.\033[0m";
                    } else {
                        x1 = -c / b;
                        y1 = p1[1] * x1 + p1[0];
                        cout << "\033[3m  Intersezione retta-retta: (\033[1;31m" << x1 << "\033[0m\033[3m ; \033[1;31m" << y1 << "\033[0m\033[3m)\033[0m";
                    }
                } else { // Caso parabolico/secondo grado
                    delta = b*b - 4*a*c;
                    if(delta < 0) cout << "\033[3m  [!] Nessun punto di intersezione reale.\033[0m";
                    else if(delta == 0) {
                        x1 = -b / (2*a);
                        y1 = p1[2]*x1*x1 + p1[1]*x1 + p1[0];
                        cout << "\033[3m  Unico punto (Tangenza): (\033[1;31m" << x1 << "\033[0m\033[3m ; \033[1;31m" << y1 << "\033[0m\033[3m)\033[0m";
                    } else {
                        x1 = (-b + sqrt(delta)) / (2*a);
                        x2 = (-b - sqrt(delta)) / (2*a);
                        y1 = p1[2]*x1*x1 + p1[1]*x1 + p1[0];
                        y2 = p1[2]*x2*x2 + p1[1]*x2 + p1[0];
                        cout << "\033[3m  Due punti di intersezione:\033[0m" << endl;
                        cout << "\033[3m  \033[1;31mA(\033[0m\033[1;31m" << x1 << "\033[0m\033[3m ; \033[1;31m" << y1 << "\033[0m\033[3m) e \033[1;31mB(\033[0m\033[1;31m" << x2 << "\033[0m\033[3m ; \033[1;31m" << y2 << "\033[0m\033[3m)\033[0m";
                    }
                }
            } else {
                cout << "\033[3m  [!] Grado 3 rilevato: Intersezione non supportata.\033[0m";
            }
            cout << "\n  -----------------------------------------------" << endl;
        }
        
        // --- RAPPRESENTAZIONE GRAFICA (SCELTA 6) ---
        else if (scelta == 6) { 
            char conf;
            do {
                cout << "\033[0;3m" << "  SEI SICURO DI VOLER VEDERE LA GRAFICA DEI POLINOMI?" << endl << endl;
                cout << "  [\033[1;31mS\033[0m\033[3m] -> Preparati a visualizzare la nostra grafica!" << endl;
                cout << "  [\033[1;31mN\033[0m\033[3m] -> Forse e' meglio ritornare al menu ..." << endl << endl;
                cout << "  Inserisci la tua scelta (S/N): \033[0m";
                cin >> conf;
                conf = toupper(conf);
                if(conf != 'S' && conf != 'N') {
                    cout << "\033[1;31m  [!] ERRORE: Devi inserire 'S' per SI o 'N' per NO!\033[0m" << endl << endl;
                }
            } while(conf != 'S' && conf != 'N');

            if (conf == 'N') {
                int sceltaNo;
                system("cls");
                cout << "\n\033[1;31m  [\033[0m\033[3m實NO\033[1;31m]\033[0m \033[3mse desideri ritornare al menu, o desideri uscire dal nostro progetto polinomi\033[0m" << endl << endl;
                cout << "  \033[1;31mPremi 1\033[0m \033[3mper ritornare al pannello di controllo\033[0m" << endl;
                cout << "  \033[1;31mPremi 0\033[0m \033[3mse vuoi uscire dal programma\033[0m" << endl;
                cout << "\n  Scelta: "; cin >> sceltaNo;
                
                if (sceltaNo == 0) {
                    system("cls");
                    cout << "\n\033[3m  Chiusura del sistema in corso...\033[0m" << endl;
                    cout << "\033[3m  Sviluppato con successo. Arrivederci!\033[0m" << endl;
                    cout << "\033[1;31m";
                    cout << "  ____  ____   _     _____  ___   _____" <<endl;
                    cout << " / ___| |  _ \\    / \\    |__  / |_ _| |  ___|" <<endl;
                    cout << "| |  _  | |_) |  / _ \\    / /    | |  |  _|  " <<endl;
                    cout << "| |_| | |  _ <  / ___ \\  / /_    | |  | |___ " <<endl;
                    cout << " \\____| |_| \\_\\/_/   \\_\\/____| |___| |_____|" <<endl;
                    cout << "\033[0m";
                    return 0;
                }
                continue; 
            } else {
                system("cls");
                cout << "\n  \033[1;31m[\033[0m\033[3mSI\033[1;31m]\033[0m \033[3mper visualizzare la nostra grafica!\033[0m" << endl << endl;
                cout << "  \033[3mUna volta all'interno potrai osservare il nostro grafico con i rispettivi polinomi\033[0m" << endl;
                cout << "  \033[3me le intersezioni se presenti.\033[0m" << endl << endl;
                cout << "  \033[3mSe si vuole ritornare al menu premere un qualsiasi tasto all'interno della grafica.\033[0m" << endl;
                cout << "\n  \033[1;31mAvvio grafica in corso... (premi un tasto)\033[0m";
                system("pause > nul");

                // Inizializzazione driver grafico
                int gd = DETECT, gm;
                initgraph(&gd, &gm, (char*)"", 0, 0); 
                
                delay(100); 
                
                int mx = getmaxx()/2; // Centro X dello schermo
                int my = getmaxy()/2; // Centro Y dello schermo
                int scalaX = 30; // Pixel per ogni unità matematica
                int scalaY = (int)(scalaX * (double)getmaxx() / getmaxy() * 0.6);        

                // Disegno assi Cartesiani
                line(0, my, getmaxx(), my); // Asse X
                line(mx, 0, mx, getmaxy()); // Asse Y
                outtextxy(getmaxx()-20, my+10, (char*)"X");
                outtextxy(mx+10, 10, (char*)"Y");
                
                // Disegno della griglia (puntini e tacche sugli assi)
                for(int i=-15; i<=15; i++) {
                    setcolor(DARKGRAY);
                    for(int j=-15; j<=15; j++) putpixel(mx + i*scalaX, my + j*scalaY, WHITE); 
                    setcolor(WHITE);
                    line(mx + i*scalaX, my-3, mx + i*scalaX, my+3); 
                    line(mx-3, my + i*scalaY, mx+3, my + i*scalaY); 
                }

                // Legenda a schermo
                char leg1[100], leg2[100]; 
                sprintf(leg1, "P1 (Giallo): %dx^3 + %dx^2 + %dx^1 + %d", p1[3], p1[2], p1[1], p1[0]); 
                sprintf(leg2, "P2 (Verde) : %dx^3 + %dx^2 + %dx^1 + %d", p2[3], p2[2], p2[1], p2[0]); 
                
                setcolor(YELLOW);
                outtextxy(20, getmaxy()-80, leg1);
                setcolor(GREEN);
                outtextxy(20, getmaxy()-60, leg2);
                setcolor(CYAN);
                outtextxy(20, getmaxy()-40, (char*)"Sovrapposizione (Ciano)");
                setcolor(RED);
                outtextxy(20, getmaxy()-20, (char*)"Intersezioni (Rosso)");

                // Disegno effettivo delle curve polinomiali
                // Ciclo su un range di X da -10 a 10 con piccoli passi (0.1)
                for (double i = -10; i <= 10; i += 0.1) 
                {
                    double v1 = p1[3]*pow(i,3) + p1[2]*pow(i,2) + p1[1]*i + p1[0]; 
                    double v2 = p2[3]*pow(i,3) + p2[2]*pow(i,2) + p2[1]*i + p2[0];

                    // Disegno Polinomio 1 (Cerchietti gialli)
                    if (v1 >= -10 && v1 <= 10) {
                        setcolor(YELLOW);
                        circle(mx + i*scalaX, my - v1*scalaY, 4);
                    }
                    // Disegno Polinomio 2 (Cerchietti verdi)
                    if (v2 >= -10 && v2 <= 10) {
                        setcolor(GREEN);
                        circle(mx + i*scalaX, my - v2*scalaY, 4);
                    }

                    // Se i valori sono molto vicini, segna il punto come sovrapposizione
                    if (abs(v1 - v2) < 0.05) { 
                        setcolor(CYAN);
                        circle(mx + i*scalaX, my - v1*scalaY, 5); 
                        circle(mx + i*scalaX, my - v1*scalaY, 6); 
                    }
                }

                // Disegno intersezioni precise (solo per gradi <= 2) con cerchi rossi
                if(g1 <= 2 && g2 <= 2) {
                    double a = (double)p1[2] - p2[2];
                    double b = (double)p1[1] - p2[1];
                    double c = (double)p1[0] - p2[0];

                    if(a == 0 && b != 0) {
                        double ix = -c / b;
                        double iy = p1[1] * ix + p1[0];
                        if(ix >= -10 && ix <= 10 && iy >= -10 && iy <= 10) {
                            setcolor(RED);
                            circle(mx + ix*scalaX, my - iy*scalaY, 10);
                            circle(mx + ix*scalaX, my - iy*scalaY, 11); 
                        }
                    } else if(a != 0) {
                        double idelta = b*b - 4*a*c;
                        if(idelta >= 0) {
                            double ix1 = (-b + sqrt(idelta)) / (2*a);
                            double iy1 = p1[2]*ix1*ix1 + p1[1]*ix1 + p1[0];
                            if(ix1 >= -10 && ix1 <= 10 && iy1 >= -10 && iy1 <= 10) {
                                setcolor(RED);
                                circle(mx + ix1*scalaX, my - iy1*scalaY, 10);
                                circle(mx + ix1*scalaX, my - iy1*scalaY, 11);
                            }
                            if(idelta > 0) {
                                double ix2 = (-b - sqrt(idelta)) / (2*a);
                                double iy2 = p1[2]*ix2*ix2 + p1[1]*ix2 + p1[0];
                                if(ix2 >= -10 && ix2 <= 10 && iy2 >= -10 && iy2 <= 10) {
                                    setcolor(RED);
                                    circle(mx + ix2*scalaX, my - iy2*scalaY, 10);
                                    circle(mx + ix2*scalaX, my - iy2*scalaY, 11);
                                }
                            }
                        }
                    }
                }

                getch(); // Aspetta pressione tasto per uscire dalla grafica
                closegraph(); // Chiude la finestra grafica
                continue; 
            }
        }
        
        // --- RESET SISTEMA (SCELTA 7) ---
        else if (scelta == 7) goto inserimento; 

        if (scelta != 0) {
            cout << "\n\033[3m  Premi un qualsiasi tasto per tornare al pannello... \033[0m";
            system("pause > nul");
        }
    } while (scelta != 0); // Il ciclo continua finché l'utente non digita 0

    // --- MESSAGGI DI CHIUSURA ---
    system("cls");
    cout << "\n\033[3m  Chiusura del sistema in corso...\033[0m" << endl;
    cout << "\033[3m  Sviluppato con successo. Arrivederci!\033[0m" << endl;
    cout << "\033[1;31m";
    cout << "  ____  ____   _     _____  ___   _____" <<endl;
    cout << " / ___| |  _ \\    / \\    |__  / |_ _| |  ___|" <<endl;
    cout << "| |  _  | |_) |  / _ \\    / /    | |  |  _|  " <<endl;
    cout << "| |_| | |  _ <  / ___ \\  / /_    | |  | |___ " <<endl;
    cout << " \\____| |_| \\_\\/_/   \\_\\/____| |___| |_____|" <<endl;
    cout << "\033[0m";
    return 0;
}
