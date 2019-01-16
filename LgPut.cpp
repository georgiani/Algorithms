long long lgput(int a, int b) ///a ^ b
{
    long long prod = 1;
    while(b)
    {
        ///daca b e impar
        if(b % 2 == 1)
            prod = (1LL * prod * a) % P;
        
        ///injumatatesc puterea
        b /= 2;
        ///ridic la patrat baza
        a = (1LL * a * a) % P;
    }
 
    return prod;
}

///simulare
a = 2
b = 3
prod = 1

b impar -> prod = 2, b = 1, a = 4
b impar -> prod = 8, b = 0, a = 16

=> 8

///logica
daca b e impar, scod un a inafara, b-ul devenind par

fiind par pot scoate un 2 din el si il atribui lui a,
a ridicandu-se la patrat

prod tine a-urile scoase inafara