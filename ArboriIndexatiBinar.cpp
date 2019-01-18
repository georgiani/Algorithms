void Update(int x, int y) /// adauga la pozitia x din vectorul a valoarea y
{
    for(int i = x; i <= n; i += (i & (-i)))
        aib[i] += y;
}
 
 /// i += (i & (-i))
 ///
 /// daca i e impar
 ///     prima adunare va aduna 1 si a doua va
 ///     face ca i sa devina cea mai mica putere a 
 ///     lui 2 mai mare decat i-ul initial
 /// daca i e par
 ///    prima adunare va face ca i sa devina
 ///    cea mai mica putere a lui 2 mai mare decat
 ///    i-ul initial
 
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
