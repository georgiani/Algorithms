int n, viz[120005], st[120005];
 
/// structura pentru puncte
struct db{
    double x, y;
}a[120005];
 
int top;

/// Sortez crescator dupa y, iar daca y-urile sunt egale
/// crescator dupa x
inline bool Cmp(const db A, const db B)
{
    if(A.y == B.y)
        return A.x < B.x;
    return A.y < B.y;
}
 

/// Determinantul
/// |a[i].x a[i].y 1|
/// |a[j].x a[j].y 1|
/// |a[p].x a[p].y 1|

/// verifica daca punctul cu index p se afla
/// in stanga, in dreapta sau coliniar cu punctele
/// de inddex i si j

/// < 0 pt stanga
/// = 0 pt coliniar
/// > 0 pt dreapta
inline double F(int i, int j, int p)
{
    return a[p].x * (a[i].y - a[j].y) +
            a[p].y * (a[j].x - a[i].x) +
            a[i].x * a[j].y - a[i].y * a[j].x;
}

void EliminareSiEchilibrare()
{
        /// elimin toate punctele din stiva
        /// cat timp punctul curent
        /// e mai in stanga dreptei determinate
        /// de ultimele 2 puncte din stiva
        /// st[top - 1] si st[top] (F < 0)
        while(top > 1 && F(st[top - 1], st[top], i) < 0)
        {
            viz[st[top]] = 0; ///le deselectionez
            top--; /// le sterg
        }
        viz[i] = 1; ///inserez acest punct in forma
        st[++top] = i; /// il pun pe stiva
}

void Rezolvare()
{
 
    sort(a + 1, a + n + 1, Cmp);

    /// tin punctele in stiva, nu vizitez inca primul
    /// punct pentru a putea lega de el ultimul punct
    /// pentru cand termin forma
    st[1] = 1;

    viz[2] = 1;
    st[2] = 2;

    top = 2;
 
    for(int i = 3; i <= n; i++) ///traversez punctele
        EliminareSiEchilibrare();
    
    ///mai traversam odata invers
    for(int i = n - 1; i >= 1; i--)
        if(!viz[i]) ///Un punct nevizitat
            EliminareSiEchilibrare();

    fout << top - 1 << "\n";
 
    for(int i = 1; i < top; i++)
        fout << fixed << setprecision(13) << a[st[i]].x << " "
            << a[st[i]].y << "\n";
}