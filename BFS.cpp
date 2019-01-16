///un fel de dijkstra
while (!q.empty())
{
    el = q.front(); ///se scoate elementul din scoada
    q.pop(); ///se da pop la element

    for (i = 0; i < L[el].size(); i++) ///se merge pe vecinii elementului
    {
        nod = L[el][i]; ///se salveaza vecinul
        if (drum[nod] > drum[el] + 1)
        {
            ///drumurile dintre noduri au distanta 1

            ///daca distanta de la radacina la nod
            ///trecand prin el este mai scurta
            ///atunci schimbam drumul
            drum[nod] = drum[el] + 1;

            q.push(nod);///pusham nodul
        }
    }
}