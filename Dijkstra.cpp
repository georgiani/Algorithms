
///L - vector pt noduri si legaturi
///drum - distanta de la nodul de plecare(in cazul asta la 1)
    ///la fiecare nod

void Dijkstra()
{
    ///initializam cu un nr foarte mare
    ///pentru a putea compara cu numere
    ///si gasi drumul minim
    for(int i = 1; i <= n; i++)
        drum[i] = inf
        
    int nod, cost, el;

    q.push({0, 1}); ///in dijkstra coada este una
    ///de prioritate

    drum[1] = 0; ///drumul de la nodul 1 la 1 este 0
    while(!q.empty()) ///cat timp coada nu este goala
    {
        el = q.top().second; ///preluam primul element din coada
        q.pop();///si il scoate din coada

        for(int i = 0; i < L[el].size(); i++) ///merg pe vecini
        {
            nod = L[el][i].first; ///preiau nodul
            cost = L[el][i].second; ///preiau costul de la el la nodul
            ///L[el][i].first

            ///vectorul L este de tip pair <int, int>
            ///pentru a tine 2 informatii
            /// -nodul
            /// -costul catre nod


            ///daca drumul de la el la nod
            ///costa mai putin decat
            ///pretul deja existent
            if(drum[nod] > drum[el] + cost) 
            {
                ///atunci actualizez costul
                drum[nod] = drum[el] + cost;
                q.push({-drum[nod], nod});
                ///si pushez in coada nodul

                ///OBS: pusham cu -drum[nod]
                ///pentru ca o coada de prioritati
                ///sorteaza crescator valorile
                ///dupa .first, iar daca noi inseram
                ///nod, cu -costul drumului in first
                ///vom avea coada de prioritati
                ///in mod descrescator
                ///dupa cost
            }
        }
    }
    
    ///Afisez distantele
    for(int i = 2; i <= n; i++)
        if(drum[i] == inf)
            fout << "0 ";
        else fout << drum[i] << " ";
    fout << "\n";
}