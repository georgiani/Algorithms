	
void Union(int x, int y)
{
    t[y] = x; ///tatal lui y devine x
    ///asta insemnand ca multimea lui x se reuneste cu
    ///multimea lui y
}
 
int Find(int x)
{
    int rad = x, y;
 
    while(t[rad] != 0) ///radacina are tatal 0
        rad = t[rad]; ///urcam
 
    while(x != rad) ///atasez toate nodurile radacinii
    {
        y = t[x]; ///salvez auxiliar tatal
        t[x] = rad; ///atasez nodul la radacina
        x = y; ///urc
    }
 
    return rad; ///radacina reprezinta multimea
} 
