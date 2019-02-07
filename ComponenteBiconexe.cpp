vector <int> L[nmax]; ///liste de adiacenta
vector <pair<int, int> > mCritice; ///muchii critice
vector <int> compBicon[nmax]; ///comp biconexe

int nrCb; ///nr de componente biconexe

int C[nmax]; ///C[i] = 1 daca i este punct de articulatie, nod critic

int niv[nmax], low[nmax], viz[nmax];

///low - nivelul cel mai mic pe care se poate ajunge folosind
        ///muchiile de intoarcere
/// niv - nivel din dfs

stack <int> st; ///stiva in care retin nodurile
                ///pentru comp biconexe
                /// practic retin ordinea de parcurgere
                /// si la fiecare nod de articulatie gasit
                /// scot din stiva si adaug o noua componenta biconexa
int nrFii; ///nr fiilor radacinii in parcurgerea dfs

int n, m;

///DFS modificat
void DFS(int nod, int tata, int rad)
{
    viz[nod] = 1; ///vizitez nodul
    niv[nod] = low[nod] = 1 + niv[tata]; ///initial nivelul si cel mai jos nivel la care se poate ajunge sunt egale
    /// low urmand sa fie calculat ulterior
    
    st.push(nod); ///introduc acest nod in coada
    for(auto i : L[nod]) ///merg pe toate legaturile sale
        if(i != tata) /// toate inafara de tatal sau, adica doar fiii
        {
            if(viz[i] == 1) /// daca deja a fost vizitat in dfs, inseamna ca aceasta muchie
            { /// este muchie de intoarcere
                low[nod] = min(low[nod], niv[i]); /// asa ca putem merge pe ea din nodul curent inapoi
                continue; /// se formeaza practic un ciclu asa ca nodul curent nu poate fi critic
            }
            
            if(nod == rad) /// daca nodul curent din care vin este radacina acestei componente conexe
                nrFii++; /// atunci asta inseamna ca acum parcurg toti fii sai
            /// calculez acest numar pentru cazul particular al radacinii
            /// ca nod critic

            DFS(i, nod, rad); ///merg pe fiul i, tatal sau fiind nod-ul curent

            low[nod] = min(low[nod], low[i]); /// la intoarcerea din DFS
            /// cateva valori din low pot fi schimbate datorita descoperirii a noi
            /// muchii de intoarcere, asa ca suntem nevoiti sa actualizam
            /// din nou low

            if(niv[nod] < low[i]) /// nu au existat muchii de intoarcere, iar low a ramas egal cu 1 + niv[tata]
              mCritice.push_back({nod, i}); /// tatal fiind nod
            /// neexistand mod de intoarcere, eliminarea acestei muchii va lasa nodul i liber

            if(niv[nod] <= low[i]) /// poate exista muchie de intoarcere
            { /// in cazul asta muchia (nod, i) nu mai este critica
              /// dar nodul nod este critic deoarece eliminarea sa va duce
              /// si la eliminarea muchiilor adiacente (incluzand muchia de intoarcere)
              /// iar acest lucru va duce la nodul i liber
              
                nrCb++; /// o noua componenta biconexa

                int x;
                
                /// avand in vedere ca nodul nod este critic
                /// atunci componenta biconexa este reprezentata de parcurgerea dfs
                /// facuta de la acest nod pana acum
                do
                {
                    x = st.top(); 
                    st.pop();
                    compBicon[nrCb].push_back(x);
                }
                while(x != i);
                /// merg pana la fiu

                compBicon[nrCb].push_back(nod);
                /// adaug si nodul critic deoarece eliminarea sa in aceasta componenta biconexa
                /// nu va duce la neconexitatea sa

                if(nod != rad) C[nod] = 1;
                /// verific sa nu avem cazul particular al radacinii
                /// ca nod critic
            }
        }
        
        /// Caz particular
        /// daca nodul e radacina
        /// acesta necesita mai mult de un fiu
        /// deoarece eliminarea acestui nod in componenta biconexa
        /// nu va duce la neconexitatea sa
        if(nod == rad && nrFii > 1) C[rad] = 1;
}


///REZUMAT
///DFS
///  init niv, low -> 1 + niv[tata]
///  push nod in coada
///  parcurgere pe fii
///     fiu != tata
///         fiu vizitat -> muchie intoarcere
///            update low[nod]
///            continue
///         verificare daca nodul curent e racacina
///             pentru a adauga fiul la contor
///         continuare dfs

///         update low[nod]

///         caz de neexistenta a muchiei de intoarcere adica muchie critica

///         caz de probabila existenta a muchiei de intoarcere
///             dar nod critic
///             adaugare contor compBicon

///             parcurgere pe stiva si adaugare in componenta

///             adaugare nod critic in componenta

///             daca nod e diferit de radacina
///                  il notez ca punct de articulatie
///  caz nod = radacina, trebuie sa aiba mai mult de un fiu             
