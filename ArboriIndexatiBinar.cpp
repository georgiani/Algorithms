
/// cand updatam o pozitie
/// updatam si valorile intervalelor care
/// contin aceasta pozitie

/// pentru a ajunge la un interval care contine
/// aceasta pozitie se adauga la pozitie poz & (-poz)
/// adica se urca la intervalul tata al acestui interval
void Update(int x, int y) /// adauga la pozitia x din vectorul a valoarea y
{
    for(int i = x; i <= n; i += (i & (-i)))
        aib[i] += y;
}

///MOD DE INTELEGERE
///avem un sir de numere, iar fiecare pozitie
/// desemneaza un interval care se termina
/// la aceasta pozitie, de lungime
/// i & (-i)
   /// -i se calculeaza din (complementul lui i) + 1

///prin adunarea lsb-ului
/// la o pozitie, ajungem
/// la pozitia al carui interval
/// contine intervalul cu pozitia noastra (tatal)

/// prin acest mod de structurare cu fii si tati
/// putem vorbi despre un arbore, index-urile (capetele intervalelor)
/// fiind bazate pe operatii binare
 



///pentru a vedea suma obtinuta
/// pe un interval de la 1 la x
/// se pleaca de la intervalul care
/// il contine pe x
/// apoi, avand in vedere ca intervalul
/// are lungime i & (-i), se scade
/// pentru a putea trece la urmatorul
/// interval care nu se intersecteaza cu
/// acesta

/// de exemplu daca vreau sa fac suma 
/// de la 1 la 10, o sa adun suna de
/// la intervalul determinat de 10 (9 -> 10)
/// apoi prin scadere ajungem la 8,
///iar acest interval, fiind putere a lui 2
/// va determina un interval de lungime
/// exact 8, adunan practic suma de pe tot intervalul
/// 1 -> 8
long long Query(int x)
{
    long long sum = 0;
    for(int i = x; i >= 1; i -= (i & (-i)))
        sum += aib[i];
    return sum;
}


///Citire si build
for(int i = 1; i <= n; i++)
{
        fin >> x;
        Update(i, x);
}
///nota : (i & (-i)) - cel mai nesemnificativ bit de 1
/// returneaza (1 << (nr de zerouri de la finalul reprezentarii in baza 2))

/// x & (-x) -> cea mai mare putere a lui 2 mai mica decat x si divizibila cu x;
