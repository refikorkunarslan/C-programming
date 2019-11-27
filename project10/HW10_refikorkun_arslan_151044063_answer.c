#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

typedef struct n{
	int *arr;
	int x;
	struct n *next;		/*struct oluşturup dynamic allocated arrat ve linked list i tanımladık*/

}n;
typedef n node;
void linkPrime(node * r,int x);
void print_fonk(node *r,FILE *q);
void primeNumber(node *r,int a,FILE *q);
void dma_arr(node *r,int n);
void test_fonk(node *r,int n,FILE *q);

int main()
{
	
	FILE *w;
	
	node *r;

	w=fopen("data.txt","r");/*dosyamızı okuduk*/
	FILE *q;

	q=fopen("output_prime_LiknedList.txt","w");/*doysa yazımı işlemi*/

	
		

	test_fonk(r,500000,q);/*1 ile n arasındaki asal sayıları bulmaya yarayan programı çagırdım*/
	
}

void test_fonk(node *r,int n,FILE *q)/*1 ile 10000000 arasındaki bütün asal sayıları bulan test fonksiyonu*/
{	
	int i;

	r=(node *)malloc(sizeof(node));/*ilk önce r ile yer ayırdım malloc sayesinde*/
	time_t start,finish;
	time_t a,b;					/*compile etme süresini öğrenmek için time fonksiyonunu kullandım*/
	time(&start);
	for(i=2;i<n;i++)/*linked list yoluyla yazıyoruz*/
		{
			
			
			linkPrime(r,i);		/*linkPRime fonksiyonunu çagıryoruz ve döngü içersinde bütün dostadan aldığımız değerleri sıralı bir şekilde tutuyoruz*/	
			primeNumber(r,i,q);/*daha sonra bu aldığımız sayının asal olup olmadıpına bakıyoruz*/
			
			
		}
	time(&finish);
	time(&a);
		dma_arr(r,n);/*array ile dynamaci memory allocation yoluyla bulma işlemini yapıyoruz*/
	time(&b);
		printf("%.3lf time linked list 1-%d\n",difftime(finish,start),n );/*linked list ile yapınca geçen süre*/
		printf("%.3lf time  array dyanamic memory allocation 1-%d\n",difftime(b,a),n );	/*array ile dynamic memory allocation ile yapıla süre*/
}

void linkPrime(node * r,int x)/*linked list işlemi*/
{
		
	r->x=x;		/*ilk başta alınan değeri node un integer kısmına attık*/
	
	r->next=(node *)malloc(sizeof(node));/*daha sonra diğer node için bir bellek ayırdık malloc ile*/
	
	r=r->next;		/*r-> next değer geleceğinden bunu r a atadık*/
	r->next=NULL;	/*ve diğer bir node u NULL yaptık ve yukarda buişlemleri or sayesinde sürekli olarak döngüye soktuk*/
}
void print_fonk(node *r,FILE *q)/*linked list dosyaya bastırma fonksiyonu*/
{
	
	fprintf(q, "%d\n",r->x );	
		r=r->next;

}
void primeNumber(node *r,int n,FILE *q)/*Asal sayıları bulma fonksiyonu*/
{
	int  i, flag = 0;

   

    for(i=2; i<=n/2; ++i)
    {
    	if(n==1)
    	{
    		break;
    	}
        
        if(n%i==0)
        {
            flag=1;
            break;
        }
    }

    if (flag==0)
    {
        print_fonk(r,q);/*Eğer sayı asalsa print fonksiyonu çağıtılıyor*/
    }
   
    
   

}
void dma_arr(node *r,int n)/*dynamic memory allocated array ile yapma fonksiyonu*/
{
	
	int i=0;
	struct n ms;
	FILE *w;
	int a,b;

	w=fopen("data.txt","r");/*dosyayı okuduk*/
	FILE *q;
	q=fopen("output_prime_dynamic_array.txt","w");/*dosyaya yazma işlemi*/
	ms.arr=malloc(1000000*sizeof(ms));/*array iç,n malloc ile yer ayırdık*/
	
	while(fscanf(w,"%d,%d",&a,&b) !=EOF &&  a !=n)/*dosyadan değerleri aldık*/
	{
		ms.arr[i]=a;	/*array içerisinde atadık*/
		
		
		i++;
	}
	int j=0;
	
		while(ms.arr[j] !='\0')	/*prime mı değil mi bulma işlemini gerçekleştirdik*/
		{
			int  i, flag = 0;

   			for(i=2; i<=ms.arr[j]/2; ++i)
   		 	{
   		 		
        
        		if(ms.arr[j]%i==0 )
        		{
           			 flag=1;
           				 break;
        		}
  			  }

   		 if (flag==0)
    		{
    			
       			 fprintf(q,"%d\n",ms.arr[j] );	/*asalsa basma işlemini gerçekleştirdik*/

   			 }
   			 j++;
		

		}



	



}
