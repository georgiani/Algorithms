void DistantaDeEditare()
{
    ///operatii disponibile
    ///1 Adaugare
    ///2 Modificare
    ///3 Stergere

    ///cuvantul x cu m caractere
    ///cuvantul y cu n caractere

    ///costul transformarii cuvantului vid
    ///in primele j caractere
    ///ale cuvantului y este egal cu j
    /// j adaugari
    for(int j = 0; j <= n; j++)
        dp[0][j] = j;
    
    ///transformare din primele i
    ///caractere ale cuvantului x
    ///in cuvant vid este egal cu i
    ///i stergeri
    for(int i = 0; i <= m; i++)
        dp[i][0] = i;

    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
            ///daca sunt egale literele trecem mai departe,
            ///costul ramamand cel dinainte
            dp[i][j] = min(1 + dp[i - 1][j], 1 + dp[i][j - 1], dp[i - 1][j - 1] + (x[i] == y[j]));
                                                                ///modificare
    ///se returneaza dp[n][m]
}                           