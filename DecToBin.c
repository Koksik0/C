#include <stdio.h>
#define NMAX 32
char array[NMAX];
int b = 1;
int Konwersja_Dec_Bin(unsigned dec, char *bin)
{
    int x;
    int i = 0;
    for(x = 0;dec!=0 && x>-1;x++)
    {
        char a;
        a = dec%2 + '0';
        dec = dec / 2; 
        *(bin+x) = a;
        i++;
    }
    return i;
}
int Konwersja_Dec_Bin2(unsigned dec, char *bin)
{
    int x;
    int i = 0;
    for(x = 31;dec!=0 && x>=0;x--)
    {
        char a;
        a = (dec&(1<<i)?1:0) + '0';
        *(bin+x) = a;
        i++;  
    }
    return i;
}
int main(int narg, char *argv[])
{
    int x,metoda,c;
    int a;
    unsigned int cyfra;
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
        printf("> ./DecToBin [-Mmetoda] <n>\n");
        return 2;
    }
        sscanf(argv[0],"%d",&cyfra);
        if (metoda==1) 
        {
            a = Konwersja_Dec_Bin(cyfra,&array[0]);
            for(x = a-1;x>=0;x--)
            {
                printf("%c",array[x]);
            }
        }
        else if (metoda==2) 
        {
            int y = 0;
            a = Konwersja_Dec_Bin2(cyfra,&array[0]);
            for(x = 0;x<=a-1;x++)
            {
                if(array[x]==49 && b==1)
                {
                    y = 31-x;
                    b=0;
                }
            }
            for(x = 31-y;x<=31;x++)
            {
                printf("%c",array[x]);
            }
        }
        else 
        {
            printf("Nieznana metoda: %d\n",metoda);
            return 3;
        }
        return 0;
}
