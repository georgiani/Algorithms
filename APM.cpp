inline bool Cmp(const tr A, const tr B)
{
    return A.cost < B.cost;
}

void  APM()
{
    int x, y, op;
    fin >> n >> m;
    for(int i = 1; i <= m; i++)
        fin >> a[i].x >> a[i].y >> a[i].cost;
    ///citesc o lista de legaturi
    ///ponderate
    
    sort(a + 1, a + m + 1, Cmp); ///sortez in functie de cost
    ///folosind functia de comparare Cmp
    ///crescator
 
    int costmin = 0;
    for(int i = 1; i <= m; i++)
    {
        ///merg pe fiecare legatura
        ///si avand costurile
        ///crescator
        ///leg fiecare muchie
        x = Find(a[i].x); 
        y = Find(a[i].y);
        
        ///daca cele 2 noduri nu sunt legate
        ///le leg, muchia avand
        ///costul minim
        ///fata de oricare alta solutie
        if(x != y)
        {
            a[i].viz = 1; ///notez muchia pentru
            /// a o afisa ulterior
            costmin += a[i].cost; ///adaug costul
            Union(x, y);///formez muchia
        }
    }
 
    fout << costmin << "\n"; ///costul minim
    fout << n - 1 << "\n"; ///un arbore este format
    ///din n - 1 muchii
 
    for(int i = 1; i <= m; i++)
        if(a[i].viz)
            fout << a[i].x << " " << a[i].y << "\n";
}
