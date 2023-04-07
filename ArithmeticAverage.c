#include <stdio.h>
#include <math.h>
void zad1(int n)
{
    int i, a;
    int x = 1;
    float w = 0.0;
    float wariancja = 0.0;
    float odchylenie = 0.0;
    int tab[n];
    printf("Podaj liczby:\n");
    for( i = 0; i < n; i++ )
    {
        printf("%d",x);
        printf(". ");
        scanf("%i",&tab[i]);
        x++;
    }
    for( i = 0; i < n; i++ )
    {   
        w += tab[i];
    }
    w/=n;
    printf("Srednia arytmetyczna wynosi: ");
    printf("%f", w);
    printf("\n");
     for( i = 0; i < n; i++ )
     {
         wariancja += (tab[i]-w)*(tab[i]-w);
     }
     wariancja /=n;
     odchylenie = sqrt(wariancja);
     printf("Odchylenie standardowe wynosi: ");
     printf("%f",odchylenie);
       
} 
int main()
{   
    int n;
    printf("Podaj z ilu liczb chcesz policzyc srednia arytmetyczna i odchylenie standardowe: \n");
    scanf("%d", &n);
    zad1(n);
}
