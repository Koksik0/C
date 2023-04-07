#include <stdio.h>
double silnia_rekurencyjnie(int n)
{
    if(n<2)
    {
        return 1;
    }
    else
    {
        return n*silnia_rekurencyjnie(n-1);
    }   
}
double silnia_iteracyjnie(int n)
{
    double silnia = 1;
    while(n>0)
    {
        silnia*=n;
        n--;
    }
    return silnia;
}
int main(int narg, char *argv[])
{
    int n,c,metoda;
    double silnia;
    metoda = 1; 
    while (--narg>0 && (*++argv)[0]=='-') 
    {
        if (c=*++argv[0]) 
        {
            switch (c) 
            {
                case 'M':
                    sscanf(++argv[0],"%d",&metoda);
                    break;
                default:
                    printf("Nieznana opcja: -%c\n",c);
                    return 1;
            }
        }
    }
    if (narg<1) 
    {
        printf("> ./silnia [-Mmetoda] <n>\n");
        return 2;
    }
    sscanf(argv[0],"%d",&n);
    if (metoda==1) 
    {
        silnia = silnia_rekurencyjnie(n);
    }
    else if (metoda==2) 
    {
        silnia = silnia_iteracyjnie(n);
    }   
    else 
    {
        printf("Nieznana metoda: %d\n",metoda);
        return 3;
    }
    // Wydruk wynikow: //
    printf("Wynik: %d! = %g",n,silnia);
    return 0;
}
