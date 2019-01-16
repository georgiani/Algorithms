	
void DFS(int nod)
{
    viz[nod] = 1;
 
    for(auto x : L[nod]) ///vecinii lui nod
        if(!viz[i]) ///daca sunt nevizitati
            DFS(i); ///ii vizitam
}
 
void ComponenteConexe()
{ 
    for(int i = 1; i <= n; i++)
        if(!viz[i]) ///daca nu e vizitat
        {
            DFS(i); ///il vizitez
            ///notand astfel toate nodurile
            ///adicente cu el ca vizitate
            ///si formand astfel o componenta conexa
            ans++;
        }
    fout << ans << "\n";
}