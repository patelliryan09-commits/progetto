#include <iostream>  // Serve per stampare e leggere (cout e cin)
#include <cstdlib>   // Serve per pulire lo schermo e cambiare colore
#include <cmath>     // Serve per fare i calcoli come le potenze e le radici
#include <iomanip>   // Serve per mettere in ordine i numeri decimali
#include <cctype>    // Serve per trasformare le lettere in maiuscolo
#include <conio.h>   // Serve per bloccare lo schermo finche' non premi un tasto
#include "graphics2.h" // La libreria per fare i disegni del grafico

using namespace std;

int main() {
    
    // --- MESSAGGI DI AVVIO ---
    // Scritte all'inizio del programma (il \033[3m serve per farle apparire in corsivo)
    cout << "\033[3mAvvio del progetto polinomi...\033[0m" << endl;
    cout << "\033[3mCaricamento moduli matematici e grafici...\033[0m" << endl;

    // --- DICHIARAZIONE VARIABILI ---
    // Qui creo le liste di numeri (array) per i polinomi e i risultati
    // p1[0] e' il numero da solo, p1[3] e' quello con x^3
    int p1[4], p2[4], somma[4], diff[4], prod[7];
    int g1, g2, scelta, sceltaDelta;
    double x1, x2, y1, y2, delta; 

    // --- 2. INTERFACCIA GRAFICA ---
    // Comandi per pulire tutto e mettere lo sfondo nero con le scritte azzurre
    system("cls");      
    system("color 0B"); 

    // Qui disegno il titolo gigante con i bordi fatti di trattini
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
    system("pause > nul"); // Aspetta che l'utente prema un tasto senza scrivere nulla
    

    // --- ETICHETTA DI RESET (GOTO) ---
    // Se l'utente resetta, il programma torna qui e svuota tutti i numeri (li mette a zero)
    inserimento:
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
    
    // Controllo che l'utente metta un numero giusto tra 0 e 3
    while(!(cin >> g1) || g1 > 3 || g1 < 0) {
        if(cin.fail()){
             cout << "  \033[1;31;3m[!] Inserisci un numero valido , non una lettera o caratteri speciali mi raccomando: \033[0m";
        } else {
             cout << "  \033[1;31;3m[!] Attenzione RIPROVA il grado massimo e' 3 : \033[0m";
        }
        cin.clear(); // Toglie l'errore se l'utente ha scritto una lettera
        cin.ignore(1000, '\n'); // Svuota quello che l'utente ha scritto per sbaglio
    }

    // Qui chiedo i numeri del polinomio uno alla volta (dal piu' alto al piu' basso)
    for (int i = g1; i >= 0; i--) {
        if (i == 0) cout << "\033[3m  [?] Immetti il TERMINE NOTO: \033[0m";
        else cout << "  \033[32;3m[?] Immetti il coefficiente di \033[33m" << "x^" << i << "\033[0m\033[3m: \033[0m";
        while(!(cin >> p1[i])) {
            cout << "  \033[1;31;3m[!] Inserisci un numero valido , non una lettera o caratteri speciali mi raccomando: \033[0m";
            cin.clear(); cin.ignore(1000, '\n');
        }
    }

    // --- CONFIGURAZIONE SECONDO POLINOMIO ---
    // Rifaccio la stessa cosa di prima per il secondo polinomio
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
    // Faccio subito i calcoli di somma e sottrazione mettendo insieme i termini simili
    for (int i = 0; i < 4; i++) {
        somma[i] = p1[i] + p2[i];
        diff[i] = p1[i] - p2[i];
    }
    // Per la moltiplicazione devo moltiplicare ogni pezzo del primo per ogni pezzo del secondo
    for (int i = 0; i <= g1; i++) {
        for (int j = 0; j <= g2; j++) {
            // Sommo i gradi (i+j) e calcolo il nuovo coefficiente
            prod[i + j] = prod[i + j] + (p1[i] * p2[j]);
        }
    }

    system("cls");
    system("color 0F"); // Cambio colore in bianco per far capire che ho finito i calcoli
    cout << "\n\n";
    cout << "                  .--------------------------------------------." << endl;
    cout << "                  |               SISTEMA DI CALCOLO           |" << endl;
    cout << "                  |--------------------------------------------|" << endl;
    cout << "                  |  Stato: Elaborazione completata            |" << endl;
    cout << "                  |  Dati: Polinomi caricati correttamente     |" << endl;
    cout << "                  '--------------------------------------------'" << endl;
    cout << "\n\033[3m                  Premi un qualsiasi tasto per visualizzare il menu: \033[0m";
    system("pause > nul");

    // --- LOOP MENU PRINCIPALE ---
    // Questo ciclo fa apparire il menu finche' l'utente non decide di uscire (premendo 0)
    do {
        system("cls");
        system("color 0B"); 
        cout << "  ================================================" << endl;
        cout << "  ||                 PANNELLO DI CONTROLLO        ||" << endl;
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
        
        // Controllo che il numero scelto sia nel menu
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
        // Se l'utente ha scelto 1, 2 o 3, mostro il calcolo a video
        if (scelta >= 1 && scelta <= 3) {
            system("color 0F"); 
            // Qui stampo il primo polinomio saltando i numeri che sono 0 per farlo stare bene
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

            // Stampo il segno dell'operazione (+, - o *)
            if (scelta == 1) cout << "\033[3m +\033[0m";
            else if (scelta == 2) cout << "\033[3m -\033[0m";
            else if (scelta == 3) cout << "\033[3m *\033[0m";
            cout << "\n";

            // Stampo il secondo polinomio
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
            
            // Stampo il risultato finale gestendo i segni + e - correttamente
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
        // Qui cerco quando il polinomio tocca lo zero (equazione p(x)=0)
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
            cout << "\n\033[3m  Inserisci scelta: \033[0m"; 
            
            // AGGIUNTO IL CONTROLLO RICHIESTO QUI:
            while(!(cin >> sceltaDelta) || sceltaDelta < 1 || sceltaDelta > 3) {
                cout << "  \033[1;31;3m[!] Attenzione qui hai 3 scelte, inserisci un numero tra quelli elencati!\033[0m" << endl;
                cout << "\033[3m  Inserisci scelta: \033[0m";
                cin.clear();
                cin.ignore(1000, '\n');
            }

            system("cls");
            
            // Faccio lo studio matematico per quello che ha scelto l'utente
            for(int k=1; k<=2; k++) {
                if((sceltaDelta == 1 && k == 2) || (sceltaDelta == 2 && k == 1)) continue;
                double ta, tb, tc;
                int tg;
                // Uso delle variabili d'appoggio (ta, tb, tc) per rendere le formule piu' facili
                if(k==1) { ta=p1[2]; tb=p1[1]; tc=p1[0]; tg=g1; }
                else { ta=p2[2]; tb=p2[1]; tc=p2[0]; tg=g2; }
                
                cout << "  .-----------------------------------------------." << endl;
                cout << "  |  [ ANALISI MATEMATICA POLINOMIO " << k << ": P(x)=0 ]   |" << endl;
                cout << "  '-----------------------------------------------'" << endl;
                
                // Vedo di che grado e' l'equazione e uso la formula giusta
                if (tg == 0) {
                    if(tc == 0) cout << "\033[32;3m  > EQUAZIONE INDETERMINATA (0=0)\033[0m" << endl;
                    else cout << "\033[32;3m  > EQUAZIONE IMPOSSIBILE (" << tc << "=0)\033[0m" << endl;
                }
                else if (tg == 1) {
                    // Se e' di primo grado faccio x = -c / b
                    if(tb == 0) {
                        if(tc == 0) cout << "\033[32;3m  > EQUAZIONE INDETERMINATA\033[0m" << endl;
                        else cout << "\033[32;3m  > EQUAZIONE IMPOSSIBILE\033[0m" << endl;
                    } else {
                        cout << "\033[3m  > EQUAZIONE DI I GRADO (Lineare)\033[0m" << endl;
                        cout << "\033[32;3m  > Risultato: x = " << (double)-tc/tb << "\033[0m" << endl;
                    }
                } else if (tg == 2) {
                    // Se e' di secondo grado uso il Delta e la formula con la radice
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
        // Qui cerco dove i due polinomi si toccano (faccio p1 - p2 = 0)
        else if (scelta == 5) { 
            system("color 0E"); 
            cout << "\033[3m  [ RICERCA PUNTI DI INTERSEZIONE ]\033[0m" << endl;
            cout << "  -----------------------------------------------" << endl;
            
            // Calcolo la differenza tra i due e studio il risultato
            if(g1 <= 2 && g2 <= 2) {
                double a = (double)p1[2] - p2[2];
                double b = (double)p1[1] - p2[1];
                double c = (double)p1[0] - p2[0];

                if(a == 0) { // Se il termine al quadrato sparisce, e' una retta
                    if(b == 0) {
                        if(c == 0) cout << "\033[3m  [!] COINCIDENTI: Infiniti punti.\033[0m";
                        else cout << "\033[3m  [!] PARALLELE: Nessun punto.\033[0m";
                    } else {
                        x1 = -c / b;
                        y1 = p1[1] * x1 + p1[0];
                        cout << "\033[3m  Intersezione retta-retta: (\033[1;31m" << x1 << "\033[0m\033[3m ; \033[1;31m" << y1 << "\033[0m\033[3m)\033[0m";
                    }
                } else { // Se resta il quadrato uso il delta
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
        // Qui si apre la finestra per disegnare le funzioni
        else if (scelta == 6) { 
            char conf;
            do {
                cout << "\033[0;3m" << "  SEI SICURO DI VOLER VEDERE LA GRAFICA DEI POLINOMI?" << endl << endl;
                cout << "  [\033[1;31mSI\033[0m\033[3m] -> Preparati a visualizzare la nostra grafica!" << endl;
                cout << "  [\033[1;31mNO\033[0m\033[3m] -> Forse e' meglio ritornare al menu ..." << endl << endl;
                cout << "  Inserisci la tua scelta (S/N): \033[0m";
                cin >> conf;
                conf = toupper(conf); // Trasforma 's' in 'S' per non avere problemi
                if(conf != 'S' && conf != 'N') {
                    cout << "\033[1;31m  [!] ERRORE: Devi inserire 'S' per SI o 'N' per NO!\033[0m" << endl << endl;
                }
            } while(conf != 'S' && conf != 'N');

            if (conf == 'N') {
                int sceltaNo;
                system("cls");
                cout << "\n\033[1;31m[\033[0m\033[3mNO\033[1;31m]\033[0m \033[3mse desideri ritornare al menu, o desideri uscire dal nostro progetto polinomi\033[0m" << endl << endl;
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

                // Carico il motore grafico (BGI)
                int gd = DETECT, gm;
                initgraph(&gd, &gm, (char*)"", 0, 0); 
                
                // Imposto la pagina per disegnare senza che l'immagine "tremi" (flickering)
                setvisualpage(0);
                setactivepage(0);
                
                delay(100); // Aspetto un attimo che la scheda video sia pronta
                
                int mx = getmaxx()/2; // Trovo il centro X dello schermo
                int my = getmaxy()/2; // Trovo il centro Y dello schermo
                int scalaX = 30;      // Zoom per asse X
                int scalaY = (int)(scalaX * (double)getmaxx() / getmaxy() * 0.6); // Zoom corretto per asse Y       

                // Disegno le righe degli assi X e Y
                line(0, my, getmaxx(), my); // Asse X
                line(mx, 0, mx, getmaxy()); // Asse Y
                outtextxy(getmaxx()-20, my+10, (char*)"X");
                outtextxy(mx+10, 10, (char*)"Y");
                
                // Disegno la griglia e i trattini dei numeri
                for(int i=-15; i<=15; i++) {
                    setcolor(DARKGRAY);
                    for(int j=-15; j<=15; j++) putpixel(mx + i*scalaX, my + j*scalaY, WHITE); 
                    setcolor(WHITE);
                    line(mx + i*scalaX, my-3, mx + i*scalaX, my+3); 
                    line(mx-3, my + i*scalaY, mx+3, my + i*scalaY); 
                }

                // Legenda dei colori in basso a sinistra
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

                // Ciclo per calcolare i punti della curva uno per uno
                for (double i = -10; i <= 10; i += 0.1) 
                {
                    // Calcolo il valore Y usando i coefficienti p[i]
                    double v1 = p1[3]*pow(i,3) + p1[2]*pow(i,2) + p1[1]*i + p1[0]; 
                    double v2 = p2[3]*pow(i,3) + p2[2]*pow(i,2) + p2[1]*i + p2[0];

                    // Disegno il primo polinomio con pallini gialli
                    if (v1 >= -10 && v1 <= 10) {
                        setcolor(YELLOW);
                        circle(mx + i*scalaX, my - v1*scalaY, 4);
                    }
                    // Disegno il secondo polinomio con pallini verdi
                    if (v2 >= -10 && v2 <= 10) {
                        setcolor(GREEN);
                        circle(mx + i*scalaX, my - v2*scalaY, 4);
                    }

                    // Se i due grafici sono molto vicini, cambio colore per far vedere che si toccano
                    if (abs(v1 - v2) < 0.05) { 
                        setcolor(CYAN);
                        circle(mx + i*scalaX, my - v1*scalaY, 5); 
                        circle(mx + i*scalaX, my - v1*scalaY, 6); 
                    }
                }

                // Metto un cerchio rosso nei punti esatti di intersezione calcolati prima
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

                getch(); // Aspetto che l'utente prema un tasto prima di chiudere il disegno
                closegraph(); // Chiudo la finestra grafica
                continue; 
            }
        }
        
        // --- RESET SISTEMA (SCELTA 7) ---
        // Se l'utente preme 7, uso il goto per tornare all'inizio
        else if (scelta == 7) goto inserimento; 

        if (scelta != 0) {
            cout << "\n\033[3m  Premi un qualsiasi tasto per tornare al pannello... \033[0m";
            system("pause > nul");
        }
    } while (scelta != 0); 

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
