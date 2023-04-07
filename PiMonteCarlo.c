#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double generator(int R0,int n)
{
    //Rn+1 = [ 75 · (Rn + 1) mod 65537 ] − 1.
    int x;

    for(x = 1;x<=n;x++)
    {
        R0 = (75*(R0+1)%65537)-1;
    }
    return R0;
}
void probyBernulliego(double n, double k)
{
    double p;
    double sigma;
    double sigmaPi;
    p = k/n;
    sigma = sqrt(p*(1-p)*n);
    sigmaPi = 4*sigma/n;
    printf("Proby Bernulliego: %1.10f",sigmaPi);
}
int main() 
{
    int n;
    double n1;
    double x,y;
    int k=0;
    double k1;
    int i;
    int X = 1000000;
    
    printf("Liczba losowanych punktow: ");
    scanf("%d",&n);
    n1=(double)n;
    for(i=1; i<=2*n; i++)
    {
        if(i%2==1)
        {
            x=generator(rand() % (X + 1),n)/(pow(2,16));
        }
        if(i%2==0)
        {
            y=generator(rand() % (X + 1),n)/(pow(2,16));
        }
        if(x*x+y*y<=1 && i%2==0) 
        {
            k++; 
        }
    }
    k1 = (double)k;
    printf("Liczba trafien w kolo: %d\n",k);
    double pi=4.0*k/n;
    printf("Liczba pi: %1.10f\n",pi);
    probyBernulliego(n1,k1);
}
