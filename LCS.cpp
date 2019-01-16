#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, a[1100], b[1100], dp[1100][1100], k;

void Afisare(int i, int j)
{
    if(i == 0 || j == 0) return;

    if(a[i] == b[j])
    {
        Afisare(i - 1, j - 1);
        fout << a[i] << " ";
    }
    else if(dp[i -1][j] > dp[i][j - 1]) Afisare(i - 1, j);
    else Afisare(i, j - 1);
}

void Citire()
{
    fin >> n >> m;

    for(int i = 1; i <= n; i++)
        fin >> a[i];
    for(int j = 1; j <= m; j++)
        fin >> b[j];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            dp[i][j] = max({dp[i - 1][j], dp[i][j - 1],
                            dp[i - 1][j - 1] + (a[i] == b[j])});

    fout << dp[n][m] << "\n";

    Afisare(n, m);
}
int main()
{
    Citire();
    return 0;
}
