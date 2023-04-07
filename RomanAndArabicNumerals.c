#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define NMAX 100 // Maxymalna wielkość tablicy
struct RZYM 
    {
    int arab;
    char *rzym;
    } 
    rz[]=
    {
        {1,"I"},{4,"IV"},{5,"V"},{9,"IX"},{10,"X"},
        {40,"XL"},{50,"L"},{90,"XC"},{100,"C"},
        {400,"CD"},{500,"D"},{900,"CM"},{1000,"M"}
    };
int jakaLiczba(char d) //Zwracamy liczbę typu całkowitego
{
    int liczba = 0;
    if(d=='0')
    {
        liczba = 0;
    }
    if(d=='1')
    {
        liczba = 1;
    }
    if(d=='2')
    {
        liczba = 2;
    }
    if(d=='3')
    {
        liczba = 3;
    }
    if(d=='4')
    {
        liczba = 4;
    }
    if(d=='5')
    {
        liczba = 5;
    }
    if(d=='6')
    {
        liczba = 6;
    }
    if(d=='7')
    {
        liczba = 7;
    }
    if(d=='8')
    {
        liczba = 8;
    }
    if(d=='9')
    {
        liczba = 9;
    }
    return liczba;
}
int charToInt(char *c) //Zameianamy wartość liczby podanej w tablicy znakowej na liczbę załkowitą
{
    int liczba = 0;
    //1000
    if(isdigit(c[3]))
    {
        liczba += jakaLiczba(c[0]) * 1000;
    }
    //100
    if(isdigit(c[2]) && !isdigit(c[3]))
    {
        liczba += jakaLiczba(c[0]) * 100;
    }
    if(isdigit(c[3]))
    {
        liczba += jakaLiczba(c[1]) * 100;
    }
    //10
    if(isdigit(c[1]) && !isdigit(c[2]))
    {
        liczba += jakaLiczba(c[0]) * 10;
    }
    if(isdigit(c[2]) && !isdigit(c[3]))
    {
        liczba += jakaLiczba(c[1]) * 10;
    }
    if(isdigit(c[3]))
    {
        liczba += jakaLiczba(c[2]) * 10;
    }
    //1
    if(isdigit(c[0]) && !isdigit(c[1]))
    {
        liczba += jakaLiczba(c[0]) * 1;
    }
    if(isdigit(c[1]) && !isdigit(c[2]))
    {
        liczba += jakaLiczba(c[1]) * 1;
    }
    if(isdigit(c[2]) && !isdigit(c[3]))
    {
        liczba += jakaLiczba(c[2]) * 1;
    }
    if(isdigit(c[3]))
    {
        liczba += jakaLiczba(c[3]) * 1;
    }
    
    return liczba;
}
void arabskieNaRzymskie(int n)//Zamiana Liczby arabskiej na rzymską
{
    int x;
    static char liczbaRzymska[NMAX];
    for(x = 12;x>=0;x--)
    {
        while(n>=rz[x].arab)
        {
            strcat(liczbaRzymska, rz[x].rzym);
            n -= rz[x].arab;
        }
    }
    printf("%s",liczbaRzymska);
}

void rzymskieNaArabskie(char* a)//Zamiana liczby rzymskiej na arabską
{
    int liczbaArabska = 0;
    int i;
    for(i = 0; i <= NMAX; i++)
  {
    if (a[i] == 'I' && a[i+1] == 'V')
    {
          liczbaArabska += rz[1].arab;
          i++;
    }
    else if(a[i] == 'I' && a[i+1] == 'X')
    {
        liczbaArabska+=rz[3].arab;
        i++;
    }
    else if(a[i] == 'X' && a[i+1] == 'L')
    {
        liczbaArabska+=rz[5].arab;
        i++;
    }
    else if(a[i] == 'X' && a[i+1] == 'C')
    {
        liczbaArabska+=rz[7].arab;
        i++;
    }    
    else if(a[i] == 'C' && a[i+1] == 'D')
    {
        liczbaArabska+=rz[9].arab;
        i++;
    }
    else if(a[i] == 'C' && a[i+1] == 'M')
    {
        liczbaArabska+=rz[11].arab;
        i++;
    }        
    else if(a[i] == 'I')
    {
        liczbaArabska+=rz[0].arab;
    }
    else if(a[i] == 'V')
    {
        liczbaArabska+=rz[2].arab;
    }
    else if(a[i] == 'X')
    {
        liczbaArabska+=rz[4].arab;
    }
    else if(a[i] == 'L')
    {
        liczbaArabska+=rz[6].arab;
    }
    else if(a[i] == 'C')
    {
        liczbaArabska+=rz[8].arab;
    }
    else if(a[i] == 'D')
    {
        liczbaArabska+=rz[10].arab;
    }    
    else if(a[i] == 'M')
    {
        liczbaArabska+=rz[12].arab;
    }
    else
    {
        break;
    }
  }
  printf("%d",liczbaArabska);
}
int main()
{
        char liczba[NMAX];
        printf("Wpisz liczbe w systemie arabskim lub rzymskim\n");
        printf("Rozpatrujemy wartosci dodatnie z zakresu [1,3999])\n");
        scanf("%s",liczba);
        if(isdigit(liczba[0]))//Sprawdzamy czy podana liczba jest arabska
        {
            printf("Liczba zapisana w systemie rzymskim: ");
            arabskieNaRzymskie((charToInt(liczba)));
        }
          else if (isalpha(liczba[0]))//Sprawdzamy czy podana liczba jest rzymska
        {
            printf("Liczba zapisana w systemie arabskim: ");
            rzymskieNaArabskie(liczba);
        }             
}

  
