///Arbori de intervale cu minim in loc de maxim
/// Edit: functia de Build nu mai este necasara nici
/// in Aint-uri deoarece putem apela pentru fiecare element
/// citit functia de Update la pozitia i cu valoarea element


///SOLUTIE DINAMICA

rmq[i][j] - numarul minim de pe intervalul de lungime 2^i care incepe la j, adica intervalul [j, j + 2^i - 1]

for(int i = 1; i <= n; i++)
    fin >> rmq[0][i]; ///intervalele de lungime 1 care incep la i au minimele chiar elementele de pe pozitia i

void Build()
{
    lg[1] = 0; /// folosesc lg pentru logaritm in baza 2 , lg1 = 0
    for(int i = 2; i <= n; i++)
        lg[i] = lg[i / 2] + 1;

    int L = lg[n]; /// lungimea maxima a unui interval pentru n e 2^lgn, adica n

    for(int i = 1; i <= L; i++) ///parcurg posibilele lungimi de intervale
        for(int j = 1; j + (1 << i) - 1 <= n ; j++) /// pentru fiecare lungime merg pe pozitiile posibile
            /// fiecare interval va fi de forma [j, j + 2^i - 1] asa cum am mentionat si mai sus
            rmq[i][j] = min(rmq[i - 1][j], rmq[i - 1][j + (1 << (i - 1))]);
                ///minimul pe acest interval este minimul pe partea stanga si cel de pe partea dreapta
                /// rmq[i - 1][j], intervalul de lungime injumatatita, care incepe la j
                /// rmq[i - 1][j + (1 << (i - 1))], cealalta jumatat a intervalului
                          /// care incepe la pozitia aia  j + 2^(i - 1)
}

void Query()
{
    int x, y;
    for(int i = 1; i <= q; i++)
    {
        fin >> x >> y;

        if(x > y) swap(x, y);

        int L = lg[y - x + 1]; ///puterea cea mai mare a lui 2 mai mica decat y - x + 1, intervalele maxime pe care le putem lua
        int bucata1 = rmq[L][x]; ///un interval de lungimea aia, care incepe la x si care
        int bucata2 = rmq[L][y - (1 << L) + 1]; /// se va putea suprapune (sau nu) cu acest interval
        /// care incepe la y - 2^L + 1 si se termina la y, adica y - 2^L + 1 + 2^L - 1

        fout << min(bucata1, bucata2) << "\n";
        /// afisez minimul dintre cele doua intervale
    }
}

