#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#include<stdbool.h>


int table[8][8];
int dizi[8];


int main()
{
    srand(time(NULL));
    int a,i,j,k,sayac=0,secim,mutasyon=1,rand_muts,muts=0;
    int random;
    bool durum=true;
    printf("secim yapiniz\n");
    printf("1-elle kromozom giris\n");
    printf("2-random guclu kromozom olusturma\n");
    scanf("%d",&secim);
    if(secim==1)
    {
        i=0;
        while(i<8)
        {
            printf("%d. gen girin: ",i+1);
            scanf("%d",&dizi[i]);
            if(dizi[i]>0 && dizi[i]<9)
                i++;
        }
        printf("\n");
        //guclu kromozom olusturma
        while(muts<2)
        {
            for(i=0;i<7;i++)
            {
                for(j=i+1;j<8;j++)
                {
                    if(dizi[i]==dizi[j])
                    {
                        printf("mutasyon: ");
                        mutasyon++;
                        rand_muts=1+rand()%8;
                        dizi[j]=rand_muts;
                        muts=0;
                        for(k=0;k<8;k++)
                        {
                            printf("%d ",dizi[k]);
                        }
                        printf("\n");
                    }
                }
            }
        muts++;
        }
    }
    else if(secim==2)
    {
            //random sayi uretme
    for (i=0;i<8;i++)
        {
        while(durum)
        {
            random =1+ rand() % 8;
            if (i == 0)
            {
				dizi[0] = random;
				break;
            }
            for(k=0;k<i;k++)
            {
				if (dizi[k] == random)
				{
					durum = true;
					break;
				}
				else
					durum = false;
            }
            if (durum == false)
				dizi[i] = random;
        }
        durum = true;
        }
    }


    printf("ilk guclu nesil\n");
    //ilk olusan diziyi yazdirmak icin
    for(i=0;i<8;i++)
    {
        printf("%d ",dizi[i]);
    }
    printf("\n\n");

    //karismamasi icin
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            table[i][j]=0;
        }

    }
    int m=0,n=0, yeni_rand,temp;
    //rastgele gen olusumu icin
   while(m<2)
    {

        for(i=0;i<7;i++)
        {
            n=1;
            for(j=i+1;j<8;j++)
            {

                if(dizi[i]==dizi[j]+n || dizi[i]==dizi[j]-n)
                {
                    sayac++;
                    yeni_rand=1+rand() %7;
                    temp=dizi[yeni_rand];
                    dizi[yeni_rand]=dizi[j];
                    dizi[j]=temp;
                    printf("%d nesil: ",sayac);
                    for(k=0;k<8;k++)
                    {
                        printf("%d ",dizi[k]);
                    }
                    printf("\n");
                    m=0;
                }
                n++;
            }
        }
        m++;
    }
     printf("\n");
     printf("  ");
     for(i=0;i<8;i++)
    {
        printf("%d ",dizi[i]);
    }
    printf("\n");

    //tahtaya yerlestirme
    for(i=0;i<8;i++)
    {
        table[8-dizi[i]][i]=dizi[i];
    }
    int st=8;
    //satranc tahtasi
    printf("  a b c d e f g h\n");
    for(i=0;i<8;i++)
    {
        printf("%d ",st);
        st--;
        for(j=0;j<8;j++)
        {
            if(table[i][j]==0)
                printf("* ");
            else
                printf("X ",table[i][j]);
        }
        printf("\n");
    }
    getch();
    return 0;
}
