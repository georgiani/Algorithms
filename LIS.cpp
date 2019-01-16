	
void Lis()
{
    ///primul element din
    ///subsirul crescator
    ///este a[1]
    lis[1] = a[1];

    ///Elementul 1 e primul
    ///in subsirul creat cu el
    ///insusi
    poz[1] = 1;
    int k = 1;
    

    ///Am folosit pozitia 1 asa 
    ///ca plecam de la 2
    for(int i = 2; i <= n; i++)
    {   
        if(a[i] > lis[k])
        {
            ///daca elementul este
            ///mai mare decat ultimul
            ///element din subsir
            ///atunci devine urmatorul
            ///element din subsir
            lis[++k] = a[i];

            ///fiind inserat la poz
            ///k
            poz[i] = k;
        }
        else if(a[i] < lis[1])
        {
            ///daca elementul este
            ///mai mic decat primul
            ///element din subsir
            ///atunci am gasit 
            ///un subsir care incepe
            ///cu un numar mai mic
            lis[1] = a[i];

            ///elementul incepe 
            ///un nou subsir
            ///el fiind primul element
            ///al acestui subsir
            poz[i] = 1;
        }
        else
        {
            ///elementul este intre ultimul
            ///din subsir si primul

            ///cautam prin cautare
            ///binara cel mai din stanga
            ///element din subsir
            ///mai mare sau egal cu a[i]
            int st = 1, dr = k, mij, p;
            while(st <= dr)
            {
                mij = (st + dr) / 2;
 
                if(lis[mij] >= a[i])
                {
                    p = mij;
                    dr = mij - 1; 
                }
                else st = mij + 1;
            }
 
            lis[p] = a[i]; ///p este prima pozitie
            ///cu elementul din subsir mai mare sau egal
            ///decat a[i]
            poz[i] = p;
        }
    }
 
    int p = k;
 
    fout << k << "\n"; ///lungimea maxima a subsirului
    
    ///plec de la sfarsitul sirului
    /// pana la inceput sau pana se termina
    ///lungimea sirului
    for(int i = n; i >= 1 && p; i--)
    {
        ///daca am gasit un nr
        ///cu o pozitie intr-un subsir
        ///crescator egala intai cu p
        ///apoi cu p-1, p-2...1
        ///o pun in vectorul sir
        if(poz[i] == p)
        {
            sir[p] = a[i];
            p--;
            ///si scad p-ul
            ///trecand la urmatorul
            ///element din subsirul
            ///crescator
        }
    }
 
    for(int i = 1; i <= k; i++)
        fout << sir[i] << " "; ///subsirul final
}