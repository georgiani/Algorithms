    
    ///1 nu este numar prim
    a[1] = 1;
    
    ///toate numerele pare, exceptand 2
    ///sunt neprime
    for(int i = 4; i <= n; i += 2)
        a[i] = 1;
    
    ///avand in vedere ca am eliminat
    ///numerele pare, vom merge
    ///doar pe cele impare
    for(int i = 3; i * i <= n; i += 2)
        ///daca acestea nu sunt notate ca prime
        if(a[i] == 0) 
            ///notam multipli numarului ca neprime
            ///avand divizori pe ei insusi, 1 si i
            for(int j = i * i; j <= n; j += 2 * i)
                ///merg din 2i in 2i deoarece,
                ///daca de exemplu am i = 3
                ///atunci primul multiplu ar fi 2 * 3
                ///dar am eliminat deja toate numerele pare
                ///asa ca mergem doar pe multiplii impari
                ///incepand cu patratul acestuia
                    ///deoarece daca gen am 5, nu tre sa
                    ///mai trec prin 5 * 3 pentru ca am trecut deja
                    ///la iteratia cu 3
                a[j] = 1;
                ///prin adaugarea de 3 la multiplu am obtine i * unNrPar
                ///dar avand in vedere ca deja am eliminat numerele pare
                ///mai adunam un 3, rezultand in j += 6