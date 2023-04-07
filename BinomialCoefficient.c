#include <stdio.h>
#include <math.h>
#define NMAX 15
static int pascal[NMAX][NMAX] = {{1},{1,1},{1,2,1},{1,3,3,1},
{1,4,6,4,1},{1,5,10,10,5,1},{1,6,15,20,15,6,1},{1,7,21,35,35,21,7,1},
{1,8,28,56,70,56,28,8,1},{1,9,36,84,126,126,84,36,9,1},
{1,10,45,120,210,252,210,120,45,10,1},
{1,11,55,165,330,462,462,330,165,55,11,1},
{1,12,66,220,495,792,924,792,495,220,66,12,1},
{1,13,78,286,715,1287,1716,1716,1287,715,286,78,13,1},
{1,14,91,364,1001,2002,3003,3432,3003,2002,1001,364,91,14,1}};


double symbolNewtonaRekurencyjnie(int n, int k)
{
    if (k == n || k == 0)
    {
        return 1;
    }
    return symbolNewtonaRekurencyjnie(n-1, k-1) + symbolNewtonaRekurencyjnie(n-1, k);
}
int symbolNewtonaIteracyjnie(int n, int k)
{
    return pascal[n][k];
}
void dwumianNewtona(int n)
{
    int x;
    int k = 0;
    int y = 0;
    printf("Wzor skroconego mnozenia dla (n+k)^%d: ",n);
    for(x = n;x>=0;x--)
    {
        printf("%1.0f*n^%d*k^%d",symbolNewtonaRekurencyjnie(n,k),x,y);
        y++;
        k++;
        if(x!=0)
        {
            printf(" + ");
        }
    }
}
void rozkladBernulliego(int n, int k, double p)
{
    double a = pow(p,k);
    double b = pow((1-p),(n-k));
    double c = symbolNewtonaIteracyjnie(n,k);
    printf("Wynik rozkladu bernulliego: %lf", a*b*c);
}
void rozkladBernulliego2(int n, int k, double p)
{
    double a = pow(p,k);
    double b = pow((1-p),(n-k));
    double c = symbolNewtonaRekurencyjnie(n,k);
    printf("Wynik rozkladu bernulliego: %lf", a*b*c);
}
int main(int narg, char *argv[])
{   int n,k,c,metoda;
    double symbolNewtona;
    double p;
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
    if (narg<1 && metoda==1) 
    {
        printf("> ./DwumianNewtona [-Mmetoda] <n>\n");
        return 2;
    }
    if(narg!=3 && (metoda==2 || metoda==3))
    {
        printf("> ./DwumianNewtona [-Mmetoda] <n> <k> <p>\n");
        return 2;
    }
    if(metoda==1)
    {
        sscanf(argv[0],"%d",&n);
    }
    if(metoda==2)
    {
        sscanf(argv[0],"%d",&n);
        sscanf(argv[1],"%d",&k);
        sscanf(argv[2],"%lf",&p);
    }
    if(metoda==3)
    {
        sscanf(argv[0],"%d",&n);
        sscanf(argv[1],"%d",&k);
        sscanf(argv[2],"%lf",&p);
    }
    if (metoda==1) 
    {
        dwumianNewtona(n);
    }
    else if (metoda==2) 
    {
        rozkladBernulliego(n,k,p);
    } 
    else if (metoda==3) 
    {
        rozkladBernulliego2(n,k,p);
    } 
    else 
    {
        printf("Nieznana metoda: %d\n",metoda);
        return 3;
    }
    return 0;
}
