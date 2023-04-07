#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <ctype.h>
char tablicaWejsciowa[1000];
double tablicaLiczb[1000];
int ileElementowWTablicaLiczb = 0;
int czyOperator(char c)
{
    if(c == '+' || c == '-' || c == '*' || c == '/')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void dodajDoTablicyLiczb(double liczba)
{
    tablicaLiczb[ileElementowWTablicaLiczb] = liczba;
    ileElementowWTablicaLiczb++;
}
void charNaInt(char *tablica)
{
    dodajDoTablicyLiczb(atoi(tablica));
}
double wykonajOperacje(double b, double a, char c)
{
        if(c=='+') 
        {
           return a + b; 
        }
		if(c=='-') 
        {
            return b-a;
        }	
		if(c=='*') 
        {
            return b*a;
        }
		if(c=='/') 
        {
            return b/a;
        }
        return 0;
}
void usunZTablicyLiczb()
{
    tablicaLiczb[ileElementowWTablicaLiczb-1] = 0;
    ileElementowWTablicaLiczb--;
}
int main()
{
    int warunek = 1;
    int x;
    while(warunek==1)
    {
        printf("Wpisz wyrazenie: ");
        scanf("%s",tablicaWejsciowa);
        if(czyOperator(tablicaWejsciowa[0])==1)
        {
            if(ileElementowWTablicaLiczb<2)
            {
                printf("Za malo elementow na stosie\n");
                warunek = 0;
            }
            double b = tablicaLiczb[ileElementowWTablicaLiczb-2];
            double a = tablicaLiczb[ileElementowWTablicaLiczb-1];
            usunZTablicyLiczb();
            usunZTablicyLiczb();
            dodajDoTablicyLiczb(wykonajOperacje(b,a,tablicaWejsciowa[0]));
        }
        else if(tablicaWejsciowa[0]=='=')
        {
            printf("Wynik: %f\n",tablicaLiczb[0]);
            usunZTablicyLiczb();
            tablicaWejsciowa[0] = 0;
        }
        else
        {
            charNaInt(tablicaWejsciowa);
        }     
        if(tablicaWejsciowa[0]=='q')
        {
            warunek = 0;
        }
    }
}
