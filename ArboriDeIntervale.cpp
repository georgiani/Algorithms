Functie de Build
void B(int nod, int x, int y)
{
    ///Metoda gen Divide et Impera
    /// iar cand x si y au aceeasi valoare
    /// va avea loc atribuirea
    if(x == y) 
    {
        aint[nod] = a[x];
        return;
    }
 
    int mij = (x + y) / 2; ///impartim sirul initial 1 n in jumatate (DeI)

    B(2 * nod, x, mij); ///Lucram pe jumatate de sir
    /// iar prin sintaxa gen heap, nodul stang e reprezentat de
    /// nodul 2 * nod

    B(2 * nod + 1, mij + 1, y); ///lucram pe cealalta jumatate de sir
    /// nodul drept e reprezentat de nodul 2 * nod + 1
 
    ///dupa apelarea celor 2 functii
    ///am facut rost de ambii fii
    /// si putem atribui maximul din ei
    /// tatalui
    aint[nod] = max(aint[2 * nod], aint[2 * nod + 1]);
}
 
///Functie de Update
///nod de inceput, capat stang, capat drept 
///Destinatie, Valoare
void Up(int nod, int x, int y, int D, int V)
{
    ///valoarea se va pune unde trebuie
    ///dar arborele de intervale trebuie
    ///recalculat putin

    if(x == y)
    {
        aint[nod] = V; ///am ajuns la D
        ///si atribuim valoarea V
        return;
    }
 
    int mij = (x + y) / 2; ///impartim sirul in 2
 
    ///vedem unde este Destinatia
    if(D <= mij) ///este in stanga?
        Up(2 * nod, x, mij, D, V); mergem pe stanga
    else Up(2 * nod + 1, mij + 1, y, D, V); ///altfel mergem in dreapta
    
    ///actualizam maximele la fel ca la Build
    ///deoarece valoarea nou pusa poate
    ///afecta arborele
    aint[nod] = max(aint[2 * nod], aint[2 * nod + 1]);
}
 
int Q(int nod, int x, int y, int a, int b)
{
    if(x == a && y == b) /// am gasit intervalul
        return aint[nod]; ///returnez maximul de pe interval
 
    int mij = (x + y) / 2;///impartim sirul in 2
    
    /// daca capatul drept e mai mic sau egal decat mijlocul
    /// inseamna ca tot intervalul e in stanga
    if(b <= mij) 
        return Q(2 * nod, x, mij, a, b);

    /// daca capatul stang e mai mare decat mijlocul
    /// inseamna ca tot intervalul e in dreapta
    if(a > mij)
        return Q(2 * nod + 1, mij + 1, y, a, b);

    ///in cazul in care a e in stanga si b in dreapta
    ///returnam maximul dintre valorile maxime 
    /// de pe jumatatea stanga [a, mij]
    /// si de pe cea dreapta [mij + 1, b]
    return max(Q(2 * nod, x, mij, a, mij), Q(2 * nod + 1, mij + 1, y, mij + 1, b));
}
 
int main()
{
    Citire();
    B(1, 1, n); ///Functia B(Build) construieste arborele
    ///prin intermediul elementelor din vectorul a
    ///de la 1 la n incepand cu nodul 1
 
    int a, b, op; ///op = 1 pt Update
    ///op = 0 pt Query
    while(q--)
    {
        fin >> op >> a >> b;

        ///caut de la nodul 1, pe tot sirul, intervalul [a, b]
        if(op == 0)
            fout << Q(1, 1, n, a, b) << "\n"; 
        else Up(1, 1, n, a, b);
        ///D = a, V = b
    }
    return 0;
}