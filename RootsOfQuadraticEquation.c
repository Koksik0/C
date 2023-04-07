#include<stdio.h>
#include <math.h>
void pierwiastki(float a, float b, float c)
{
    float delta = (b*b) - 4*a*c;
    if(delta<0)
    {
        printf("Poniewaz delta jest mniejsza od 0, to rowananie nie ma miejsc zerowych\n");
    }
    else if (delta==0)
    {
        float pierwiastek = (-b)/(2*a);
        printf("Rownanie ma jeden pierwiastek, jest nim: \n");
        printf("%f", pierwiastek);
    }
    else
    {
        printf("Rownanie ma dwa pierwiaski, sa nimi: \n X1: \n");
        printf("%f",(-b - sqrt(delta))/(2*a));
        printf("\nX2: \n");
        printf("%f",(-b + sqrt(delta))/(2*a));
    }
}
int main()
{
    float a,b,c;
    int cyferka = 1;
    do
    {
        printf("Podaj wspolczynnik stojacy przy x^2(pamietaj ze nie moze byc zerem)\n");
        scanf("%f",&a);
        printf("Podaj wspolczynnik stojacy przy x\n");
        scanf("%f",&b);
        printf("Podaj wyraz wolny\n");
        scanf("%f",&c);
        pierwiastki(a,b,c);
        printf("\nJesli chcesz ponowanie obliczyc pierwiastki rownania kwadratowrgo to wpisz 1, w przyciwnym wypadku wpisz inna cyfre\n");
        scanf("%d",&cyferka);
    }
    while(cyferka == 1);
}
