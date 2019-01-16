	
void Update(int poz, int val) ///adauga la nodul x valoarea y
{
    ///inaintez pe aib pentru a updata
    ///toate valorile cu +val
    for(int i = poz; i <= n; i += (i & (-i)))
        aib[i] += val;
}
 
long long Query(int x)
{
    ///calculez suma de la 1 la x
    long long sum = 0;
    for(int i = x; i >= 1; i -= (i & (-i)))
        sum += aib[i]; ///adaug la suma valoarea
    return sum;
}
 
void Read()
{
    int x, y, op;
    fin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        fin >> x;
        Update(i, x); ///Construiesc aib-ul
        ///facand sume partiale
    }
 
    fout << Query(y) - Query(x - 1) << "\n"; ///suma intre x si y
}