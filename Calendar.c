#include <stdio.h>
int dzienTygodnia(int dzien, int miesiac, int rok)
{
    int cyfry = rok / 100;
    if (miesiac > 2)        
        miesiac -= 2;        
    else               
    {                  
        miesiac += 10;       
        rok--;           
    }
    
    rok %= 100;
    return (dzien + (13*miesiac - 1)/5 + rok + rok/4 + cyfry/4 + 5*cyfry) % 7;
}
void nazwaDnia(int n)
{
    if(n==0)
    {
        printf("Niedziela");
    }
    if(n==1)
    {
        printf("Poniedzialek");
    }
    if(n==2)
    {
        printf("Wtorek");
    }
    if(n==3)
    {
        printf("Sroda");
    }
    if(n==4)
    {
        printf("Czwartek");
    }
    if(n==5)
    {
        printf("Piatek");
    }
    if(n==6)
    {
        printf("Sobota");
    }
}
int main()
{
    int dzien;
    int miesiac;
    int rok;
    printf("Podaj dzien: \n");
    scanf("%d",&dzien);
    printf("Podaj miesiac: \n");
    scanf("%d",&miesiac);
    printf("Podaj rok: \n");
    scanf("%d",&rok);
    nazwaDnia(dzienTygodnia(dzien,miesiac,rok));
}
