#include <stdio.h>
void nwd(int a, int b)
{
    int pom;
    if(b==0)
    {
        printf("%d",a);
    }
    else if(b>0)
    {
        while(b!=0)
        {
		    pom = b;
		    b = a%b;
		    a = pom;	
	    }
        printf("NWD: ");
        printf("%d",a);
    }
}
int main()
{
    int a,b;
    int cyferka = 1;
    do
    {
         printf("%s","Podaj pierwsza liczbe naturalna: \n");
        scanf("%d", &a);
        printf("%s","Podaj druga liczbe naturalna(mniejsza lub rowna pierwszej): \n");
        scanf("%d", &b);
        nwd(a ,b);
        printf("\nJesli chcesz ponowanie znalezc nwd to wpisz 1, w przyciwnym wypadku wpisz inna cyfre\n");
        scanf("%d",&cyferka);
    } 
    while (cyferka == 1);
}
