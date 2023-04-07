#include<stdio.h>
#include <math.h>
void sitoErastotenesta(int n)
{
    int tab[n+1];
    int x = 0;
    int y;
    for(x;x<=n;x++)
    {
        tab[x] = 0;
    }
    x = 2;
    for(x;x<=n;x++)
    {
        if(tab[x] == 0)
        {
                for (y = x+x; y <= n; y+=x)
                {
                    tab[y] = 1;
                }    
        }
    }
    x = 2;
    printf("%s","Liczby pierwsze:\n");
    for(x;x<=n;x++)
    {
         if(tab[x]==0)
         {
            printf("%d\n",x);
         }
    }
}
int main()
{
    int n;
    int cyferka = 1;
    do
    {
        printf("%s","Podaj gorne ograniczenie zakresu [2,n]: \n");
        scanf("%d",&n);
        sitoErastotenesta(n);
        printf("Jesli chcesz ponowanie podac przedzial i wypisac liczby pierwsze to wpisz 1, w przyciwnym wypadku wpisz inna cyfre\n");
        scanf("%d",&cyferka);
    }
    while (cyferka == 1);
}
