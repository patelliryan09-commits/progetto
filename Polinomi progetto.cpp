#include <iostream>
#include <cstdlib>
#include <cmath> 
#include <iomanip>
#include <cctype>
#include "graphics2.h" 

using namespace std;

int main() {
    
    // --- MESSAGGI DI AVVIO ---
    // Stampiamo a video l'inizio del caricamento usando i codici ANSI per il corsivo (\033[3m)
    cout << "\033[3mAvvio del progetto polinomi...\033[0m" << endl;
    cout << "\033[3mCaricamento moduli matematici e grafici...\033[0m" << endl;

    // --- DICHIARAZIONE VARIABILI ---
    // p1 e p2 sono array che contengono i coefficienti dei polinomi (indice = grado)
    // somma, diff e prod servono per salvare i risultati delle operazioni
    int p1[4], p2[4], somma[4], diff[4], prod[7];
    
    // g1 e g2 indicano il grado scelto dall'utente; scelta e sceltaDelta gestiscono i menu
    int g1, g2, scelta, sceltaDelta;
    
    // Variabili per i calcoli matematici: coordinate (x,y) e il discriminante (delta)
    double x1, x2, y1, y2, delta; 

    // --- 2. INTERFACCIA GRAFICA ---
    system("cls");      // Pulisce lo schermo del terminale
    system("color 0B"); // Cambia il colore del testo (Sfondo nero, Testo azzurro)

    // Disegno del box di benvenuto con caratteri ASCII
    cout << "\n\n";
    cout << "          ._______________________________________________________." << endl;
    cout << "          |                                                       |" << endl;
    cout << "          |      ___________________________________________      |" << endl;
    cout << "          |     |                                           |     |" << endl;
    cout << "          |     |    >>> IL NOSTRO PROGETTO POLINOMI <<<    |     |" << endl;
    cout << "          |     |___________________________________________|     |" << endl;
    cout << "          |                                                       |" << endl;
    cout << "          |                                                       |" << endl;
    cout << "          |            [ Sistema in fase di avvio ]..             |" << endl;
    cout << "          |                                                       |" << endl;
    cout << "          |                                                       |" << endl;
    cout << "          |     _______________________________________________   |" << endl;
    cout << "          |    |                                               |  |" << endl;
    cout << "          |    |   Premi un tasto per avviare il programma...  |  |" << endl;
    cout << "          |    |_______________________________________________|  |" << endl;
    cout << "          |                                                       |" << endl;
    cout << "          |_______________________________________________________|" << endl;
    
    system("pause > nul"); // Blocca il programma finchÃ© non premi un tasto (senza mostrare scritte)

    // --- ETICHETTA DI RESET (GOTO) ---
    inserimento:
    // Reset di tutti gli array a zero per evitare dati sporchi in caso di riavvio (scelta 7)
    for(int i=0; i<4; i++) { p1[i]=0; p2[i]=0; somma[i]=0; diff[i]=0; }
    for(int i=0; i<7; i++) { prod[i]=0; }

    // --- CONFIGURAZIONE PRIMO POLINOMIO ---
    system("cls");
    system("color 0B");
    cout << "  ___________________________________________________________" << endl;
    cout << " |                                                           |" << endl;
    cout << " |            ===> CONFIGURAZIONE PRIMO POLINOMIO <===       |" << endl;
    cout << " |___________________________________________________________|" << endl;
    cout << "\n\033[3m  Inserisci il grado del primo polinomio (massimo 3): \033[0m";
    
    // Controllo input: deve essere un numero tra 0 e 3
    while(!(cin >> g1) || g1 > 3 || g1 < 0) {
        cout << "  \033[1;31;3m[!] Attenzione RIPROVA il grado massimo e' 3 : \033[0m";
        cin.clear(); // Resetta lo stato del cin in caso di errore (es. lettere)
        cin.ignore(1000, '\n'); // Svuota il buffer
    }

    // Ciclo per inserire i coefficienti partendo dal grado piÃ¹ alto
    for (int i = g1; i >= 0; i--) {
        if (i == 0) cout << "\033[3m  [?] Immetti il TERMINE NOTO: \033[0m";
        else cout << "  \033[32;3m[?] Immetti il coefficiente di \033[33m" << "x^" << i << "\033[0m\033[3m: \033[0m";
        while(!(cin >> p1[i])) {
            cout << "  \033[1;31;3m[!] Inserisci un numero valido , non una lettera o caratteri speciali mi raccomando: \033[0m";
            cin.clear(); cin.ignore(1000, '\n');
        }
    }

    // --- CONFIGURAZIONE SECONDO POLINOMIO ---
    system("cls");
    system("color 0B");
    cout << "  ___________________________________________________________" << endl;
    cout << " |                                                           |" << endl;
    cout << " |           ===> CONFIGURAZIONE SECONDO POLINOMIO <===      |" << endl;
    cout << " |___________________________________________________________|" << endl;
    cout << "\n\033[3m  Inserisci il grado del secondo polinomio (massimo 3): \033[0m";
    
    while(!(cin >> g2) || g2 > 3 || g2 < 0) {
        cout << "  \033[1;31;3m[!] Attenzione RIPROVA il grado massimo e' 3 : \033[0m";
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
    // Calcoliamo somma e differenza tra i coefficienti corrispondenti
    for (int i = 0; i < 4; i++) {
        somma[i] = p1[i] + p2[i];
        diff[i] = p1[i] - p2[i];
    }
    // Calcolo del prodotto (doppio ciclo per moltiplicare ogni termine per ogni altro)
    for (int i = 0; i <= g1; i++) {
        for (int j = 0; j <= g2; j++) {
            prod[i + j] = prod[i + j] + (p1[i] * p2[j]);
        }
    }

    // Schermata di caricamento prima del menu
    system("cls");
    system("color 0F"); // Testo Bianco
    cout << "\n\n";
    cout << "                .--------------------------------------------." << endl;
    cout << "                |                SISTEMA DI CALCOLO          |" << endl;
    cout << "                |--------------------------------------------|" << endl;
    cout << "                |  Stato: Elaborazione completata            |" << endl;
    cout << "                |  Dati: Polinomi caricati correttamente     |" << endl;
    cout << "                '--------------------------------------------'" << endl;
    cout << "\n\033[3m                Premi un qualsiasi tasto per visualizzare il menu: \033[0m";
    system("pause > nul");

    // --- LOOP MENU PRINCIPALE ---
    do {
        system("cls");
        system("color 0B"); 
        cout << "  ================================================" << endl;
        cout << "  ||               PANNELLO DI CONTROLLO         ||" << endl;
        cout << "  ================================================" << endl;
        cout << "  ||                                             ||" << endl;
        cout << "  || [1] ADDIZIONE       (Pol 1 + Pol 2)         ||" << endl;
        cout << "  || [2] SOTTRAZIONE     (Pol 1 - Pol 2)         ||" << endl;
        cout << "  || [3] MOLTIPLICAZIONE (Pol 1 * Pol 2)         ||" << endl;
        cout << "  || [4] RICERCA ZERI    (Studio P(x)=0)         ||" << endl;
        cout << "  || [5] INTERSEZIONI    (Punti comuni)          ||" << endl;
        cout << "  || [6] RAPPRESENTAZIONE GRAFICA                ||" << endl;
        cout << "  || [7] RESET SISTEMA                           ||" << endl;
        cout << "  || [0] ESCI DAL PROGRAMMA                      ||" << endl;
        cout << "  ||                                             ||" << endl;
        cout << "  ================================================" << endl;
        cout << "\n\033[3m  Scelta operativa: \033[0m";
        cin >> scelta;

        system("cls");
        
        // --- CASO 1, 2, 3: OPERAZIONI ARITMETICHE ---
        if (scelta >= 1 && scelta <= 3) {
            system("color 0F"); 
            
            // Stampa del Polinomio 1 formattato (gestisce i segni e gli zeri)
            cout << "\033[3m  Polinomio 1: (\033[0m";
            bool primoTermine = true;
            for (int i = g1; i >= 0; i--) { 
                if(p1[i] != 0) { 
                    if(p1[i] > 0 && !primoTermine) cout << "+"; 
                    cout << p1[i] << (i > 0 ? "x^" : ""); 
                    if(i > 0) cout << i; 
                    primoTermine = false;
                } 
            }
            if(primoTermine) cout << "0"; 
            cout << "\033[3m) \033[0m";

            // Mostra l'operatore scelto
            if (scelta == 1) cout << "\033[3m +\033[0m";
            else if (scelta == 2) cout << "\033[3m -\033[0m";
            else if (scelta == 3) cout << "\033[3m *\033[0m";
            cout << "\n";

            // Stampa del Polinomio 2
            cout << "\033[3m  Polinomio 2: (\033[0m";
            primoTermine = true;
            for (int i = g2; i >= 0; i--) { 
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
            
            // --- QUI IL FIX PER IL DOPPIO MENO ---
            bool nullo = true;
            int fine = (scelta == 3) ? (g1+g2) : 3;
            for (int i = fine; i >= 0; i--) {
                int valoreAttuale = 0;
                if (scelta == 1) valoreAttuale = somma[i];
                else if (scelta == 2) valoreAttuale = diff[i];
                else if (scelta == 3) valoreAttuale = prod[i];
                
                if (valoreAttuale != 0) {
                    if (valoreAttuale > 0 && !nullo) cout << "+";
                    // Se il numero Ã¨ negativo, il segno meno Ã¨ giÃ  parte di valoreAttuale
                    cout << valoreAttuale; 
                    if (i > 0) cout << "x^" << i;
                    nullo = false;
                }
            }
            if(nullo) cout << "0";
            cout << endl;
        }
        
        // --- CASO 4: RICERCA ZERI (EQUAZIONI) ---
        else if (scelta == 4) {
            system("color 0A"); // Testo Verde
            cout << "  ._____________________________________________." << endl;
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
            
            // Ciclo per analizzare i polinomi in base alla scelta
            for(int k=1; k<=2; k++) {
                if((sceltaDelta == 1 && k == 2) || (sceltaDelta == 2 && k == 1)) continue;
                double ta, tb, tc;
                int tg;
                // Assegniamo coefficienti temporanei per l'analisi
                if(k==1) { ta=p1[2]; tb=p1[1]; tc=p1[0]; tg=g1; }
                else { ta=p2[2]; tb=p2[1]; tc=p2[0]; tg=g2; }
                
                cout << "  .-----------------------------------------------." << endl;
                cout << "  |  [ ANALISI MATEMATICA POLINOMIO " << k << ": P(x)=0 ]   |" << endl;
                cout << "  '-----------------------------------------------'" << endl;
                
                // Studio del grado e risoluzione equazione
                if (tg == 0) { // Costante
                    if(tc == 0) cout << "\033[32;3m  > EQUAZIONE INDETERMINATA (0=0)\033[0m" << endl;
                    else cout << "\033[32;3m  > EQUAZIONE IMPOSSIBILE (" << tc << "=0)\033[0m" << endl;
                }
                else if (tg == 1) { // I Grado
                    if(tb == 0) {
                        if(tc == 0) cout << "\033[32;3m  > EQUAZIONE INDETERMINATA\033[0m" << endl;
                        else cout << "\033[32;3m  > EQUAZIONE IMPOSSIBILE\033[0m" << endl;
                    } else {
                        cout << "\033[3m  > EQUAZIONE DI I GRADO (Lineare)\033[0m" << endl;
                        cout << "\033[32;3m  > Risultato: x = " << (double)-tc/tb << "\033[0m" << endl;
                    }
                } else if (tg == 2) { // II Grado con Delta
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
        
        // --- CASO 5: INTERSEZIONI TRA I DUE POLINOMI ---
        else if (scelta == 5) { 
            system("color 0E"); // Testo Giallo
            cout << "\033[3m  [ RICERCA PUNTI DI INTERSEZIONE ]\033[0m" << endl;
            cout << "  -----------------------------------------------" << endl;
            
            // Supporta solo fino al II grado
            if(g1 <= 2 && g2 <= 2) {
                // Calcoliamo il polinomio differenza (P1 - P2 = 0)
                double a = (double)p1[2] - p2[2];
                double b = (double)p1[1] - p2[1];
                double c = (double)p1[0] - p2[0];

                if(a == 0) { // Intersezione tra rette
                    if(b == 0) {
                        if(c == 0) cout << "\033[3m  [!] COINCIDENTI: Infiniti punti.\033[0m";
                        else cout << "\033[3m  [!] PARALLELE: Nessun punto.\033[0m";
                    } else {
                        x1 = -c / b;
                        y1 = p1[1] * x1 + p1[0];
                        cout << "\033[3m  Intersezione retta-retta: (\033[1;31m" << x1 << "\033[0m\033[3m ; \033[1;31m" << y1 << "\033[0m\033[3m)\033[0m";
                    }
                } else { // Intersezione parabolica
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
        
        // --- CASO 6: RAPPRESENTAZIONE GRAFICA ---
        else if (scelta == 6) { 
            char conf;
            cout << "\033[0;3m" << "  SEI SICURO DI VOLER VEDERE LA GRAFICA DEI POLINOMI?" << endl << endl;
            cout << "  [\033[1;31mSI\033[0m\033[3m] -> Preparati a visualizzare la nostra grafica!" << endl;
            cout << "  [\033[1;31mNO\033[0m\033[3m] -> Forse e' meglio ritornare al menu ..." << endl << endl;
            cout << "  Inserisci la tua scelta (S/N): \033[0m";
            cin >> conf;

            if (toupper(conf) == 'N') {
                continue; 
            } else {
                int gd = DETECT, gm;
                initgraph(&gd, &gm, (char*)"", 0, 0); // Inizializza finestra grafica
                
                int mx = getmaxx()/2; // Centro X
                int my = getmaxy()/2; // Centro Y
                int scala = 25;       // Fattore di ingrandimento dei punti

                line(0, my, getmaxx(), my); // Asse X
                line(mx, 0, mx, getmaxy()); // Asse Y
                outtextxy(getmaxx()-20, my+10, (char*)"X");
                outtextxy(mx+10, 10, (char*)"Y");
                
                // Disegno delle tacche sugli assi
                for(int i=-10; i<=10; i++) {
                    line(mx + i*scala, my-5, mx + i*scala, my+5); 
                    line(mx-5, my + i*scala, mx+5, my + i*scala); 
                }

                char leg1[100], leg2[100]; //  Dichiariamo due "array di caratteri" (stringhe) capaci di contenere fino a 100 lettere/numeri ciascuno.
                                           // Serviranno a memorizzare il testo del Polinomio 1 e del Polinomio 2.
                                           
                                           
                sprintf(leg1, "P1 (Giallo): %dx^3 + %dx^2 + %dx^1 + %d", p1[3], p1[2], p1[1], p1[0]); // // La funzione sprintf (string-print-format) "stampa" dentro la variabile leg1.
                   // %d sono dei segnaposto: verranno sostituiti dai valori contenuti in p1[3], p1[2], p1[1] e p1[0].
                   // Il risultato finale sarÃ  una scritta tipo: "P1 (Giallo): 2x^3 + 0x^2 + 5x^1 + 3"
                   
                   
                sprintf(leg2, "P2 (Verde) : %dx^3 + %dx^2 + %dx^1 + %d", p2[3], p2[2], p2[1], p2[0]); // Facciamo la stessa cosa per il secondo polinomio, salvando il testo nella variabile leg2.
                                                                                                   // Questa scritta apparirÃ  poi di colore verde sul grafico.
                
                
                // LEGENDA COLORATA nella finestra grafica
                setcolor(YELLOW);
                outtextxy(20, getmaxy()-60, leg1);
                setcolor(GREEN);
                outtextxy(20, getmaxy()-40, leg2);
                setcolor(RED);
                outtextxy(20, getmaxy()-20, (char*)"Intersezioni");

                // Disegno dei punti dei polinomi
                for (double i = -10; i <= 10; i += 0.4) // // Avviamo un ciclo for che fa scorrere la variabile 'i' (che rappresenta la nostra X)
                                                        // da -10 a +10, con piccoli passi di 0.4 per rendere la curva abbastanza fluida.  
                {
                    double v1 = p1[3]*pow(i,3) + p1[2]*pow(i,2) + p1[1]*i + p1[0]; //  CALCOLO POLINOMIO 1 
                        // Calcoliamo il valore della Y (chiamata v1) inserendo la X (i) nell'equazione di 3Â° grado:
                       // ax^3 + bx^2 + cx + d
                    if (v1 >= -10 && v1 <= 10) {
                        setcolor(YELLOW);
                        circle(mx + i*scala, my - v1*scala, 4); 
                    }
                    double v2 = p2[3]*pow(i,3) + p2[2]*pow(i,2) + p2[1]*i + p2[0];
                    if (v2 >= -10 && v2 <= 10) {
                        setcolor(GREEN);
                        circle(mx + i*scala, my - v2*scala, 4);
                    }
                }

                // --- AGGIUNTA PUNTI DI INTERSEZIONE (CERCHIO ROSSO PIU GRANDE) ---
                if(g1 <= 2 && g2 <= 2) {
                    double a = (double)p1[2] - p2[2];
                    double b = (double)p1[1] - p2[1];
                    double c = (double)p1[0] - p2[0];

                    if(a == 0 && b != 0) { // Intersezione tra rette
                        double ix = -c / b;
                        double iy = p1[1] * ix + p1[0];
                        if(ix >= -10 && ix <= 10 && iy >= -10 && iy <= 10) {
                            setcolor(RED);
                            circle(mx + ix*scala, my - iy*scala, 8);
                        }
                    } else if(a != 0) { // Intersezione parabolica
                        double idelta = b*b - 4*a*c;
                        if(idelta >= 0) {
                            double ix1 = (-b + sqrt(idelta)) / (2*a);
                            double iy1 = p1[2]*ix1*ix1 + p1[1]*ix1 + p1[0];
                            if(ix1 >= -10 && ix1 <= 10 && iy1 >= -10 && iy1 <= 10) {
                                setcolor(RED);
                                circle(mx + ix1*scala, my - iy1*scala, 8);
                            }
                            if(idelta > 0) {
                                double ix2 = (-b - sqrt(idelta)) / (2*a);
                                double iy2 = p1[2]*ix2*ix2 + p1[1]*ix2 + p1[0];
                                if(ix2 >= -10 && ix2 <= 10 && iy2 >= -10 && iy2 <= 10) {
                                    setcolor(RED);
                                    circle(mx + ix2*scala, my - iy2*scala, 8);
                                }
                            }
                        }
                    }
                }

                system("pause > nul");
                closegraph(); // Chiude la finestra grafica.
                continue;
            }
        }
        
        // --- CASO 7: RESET ---
        else if (scelta == 7) goto inserimento; // Torna all'inizio dell'inserimento dati

        // --- PAUSA TRA LE OPERAZIONI ---
        if (scelta != 0) {
            cout << "\n\033[3m  Premi un qualsiasi tasto per tornare al pannello... \033[0m";
            system("pause > nul");
       	}
    } while (scelta != 0);

    // --- SEQUENZA DI CHIUSURA (SCELTA 0) ---
    system("cls");
    cout << "\n\033[3m  Chiusura del sistema in corso...\033[0m" << endl;
    cout << "\033[3m  Sviluppato con successo. Arrivederci!\033[0m" << endl;
    return 0;
}
