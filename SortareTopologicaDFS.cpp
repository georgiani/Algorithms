O prima modalitate de sortare topologica

void DFS(int k)
{
    int i;
    viz[k] = 1; ///il vizitez
 
    for(auto i : L[k]) ///merg pe adiacentii lui
        if(viz[i] == 0) ///daca sunt nevizitati
            DFS(i); ///parcurgere in adancime si pe ei

    t[++cnt] = k; /// inserez nodul curent dupa ce am parcurs toti fiii sai
    /// adica are gradul 0
}

void SortareTop()
{
    int i;
    for(i = 1; i <= n; i++) ///parcurg fiecare nod
        if(viz[i] == 0) ///daca nu este vizitat
            DFS(i); ///fac o parcurgere in adancime pe acesta
 
}