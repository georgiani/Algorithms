	
void Rez()
{
    ///inserez toate nodurile cu grad interior 0
    for(int i = 1; i <= n; i++)
        if(grad[i] == 0) ///grad interior 0
            q.push(i); ///coada normala q
 
    while(!q.empty())
    {
        int el = q.front(); ///preiau primul element din coada
        fout << el << " "; ///nod cu grad 0, se afiseaza

        q.pop(); ///dupa afisare il elimin din coada
 
        for(auto i : L[el]) ///mergem pe fiii elementului
        {
            ///pentru fiecare fiu scad gradul interior deoarece
            ///simulam eliminarea nodului el

            /// daca vreun nod a ajuns la gradul interior 0
            /// prin eliminarea nodului el, acesta
            /// se insereaza in coada
            if((--grad[i]) == 0) 
                q.push(i);
        }
    }
}