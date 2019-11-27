#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int numberGeneratorBetweenRange(int min, int max);
void horseRacingGame();
void triangleOfSequences();
void countOccurrence();
int getInt(int mini, int maxi);
void menu();

int main()
{
	menu(); 	/*Menu fonksiyonu çağırdım*/

}
void menu()
{
	srand(time(NULL)); /*her defasında rasgele sayı atama yapmak için bunu kullandım*/
	int secim ;
	do
	{
		printf("1. Horse Racing Game\n2. Occurrence Counter\n3. Triangle of Sequences\n0. Exit\n");/*menu seceneklerini ekranı bastırma*/
		scanf("%d",&secim);
		switch(secim)
		{
			case 1 : 
				 horseRacingGame();
				break;
			case 2 :
			countOccurrence();		/*switch case ile menu seceneklerinden istenileni seçme ve o numaralara ilgili fonksiyonu atama*/
			 
				
				break;			
			case 3 :
			triangleOfSequences();
				
				break;
			default :
				break;
		}


	}while(secim !=0);/*kullanıcı 0 girmediği sürece menüyü döndürecek*/
	
}
int getInt(int mini, int maxi)
{
	int x;
	
	scanf("%d" , &x);
	
	while(x<mini || x >maxi)
		{	
			
			scanf("%d" , &x);		/*girilen sayının max min değerleri arasında girilmesini sağlayan fonksiyon*/
		}
	return x;

}
int numberGeneratorBetweenRange(int min, int max)
{
	int randomm;
    
    randomm=min+rand()%(max-min + 1);	/*verilen random sayının max ve min değerleri arasında olmasını sağlayan fonksiyon*/
 										/*Max değeri de verebilmesi için 1 arttırılıyor*/

 return randomm;

}
void horseRacingGame()
{
	int horse_number,number_horse,speed,temp=30,count=0,i,count_horse=0;
	
	horse_number=numberGeneratorBetweenRange( 3,  5);	/*at sayısını fonksiyon çağırarak 3 ve 5 arasu olarak belirliyoruz*/
	printf("Number of Horse : %d\n" , horse_number);
	number_horse= getInt( 1, horse_number);	/*Oynanan atın random atılan at sayısına göre girilen aralık belirleniyor*/
	printf("Horse Number : %d\n" , number_horse);

	printf("Racing starts...\n");
		for(i=1;i<=horse_number;i++)	/*at sayısı kadar o atın hızı döndürülüyor*/
		{
			speed =numberGeneratorBetweenRange( 10,  20);	/*Atlara belli uzunluğu ne kadar sürede aldığı random atanıyor 10 ile 20 arası*/
			count++;

			printf("Horse %d : %d \n",i,speed);
			if(speed<=temp)
			{
				temp=speed;			/*En hızlı giden at degeri temp değerine atanıyor*/
				
				count_horse=count; /*koşula girdiği zaman en hızlı at değişmiştir bu yüzden count_horse sayacı tutuluyor*/
			}
		}
	if(count_horse==number_horse)/*en hızlı at (count_horse) = oynanan at (number_horse) ise win*/
		{	
			printf("You win! Winner is Horse %d.\n", count_horse);
		}
	else
		{	

			printf("You lose! Winner is Horse %d\n" , count_horse);
		}

}
void triangleOfSequences()/*Random sayı verip üçgen yaptırma fonksiyonu*/
{
	int triagle,i,j;
	triagle=numberGeneratorBetweenRange(2, 10);/*2 ve 10 arasında fonksiyon yoluyla bir sayı istedim*/
	for(i=1;i<=triagle;i++)/*random sayı kaç tane verdiyse o kadar döndürme işlemi*/
	{

		for(j=i;j<=i*i;j=j+i)
		{
			printf("%d", j );	/*daha sonra bu sayıları i ye i ekeleyerek toplama işlemi*/
			printf(" ");
		}
		printf("\n");
    }
}
void countOccurrence()
{
	int bigNumber,searchNumber,count=1,count1=1;
	int x=1,a=0,occurrence=0,i,bigger,search;
	printf("Big Number :  ");
	scanf("%d" , &bigNumber);
	printf("Search Number :  ");
	scanf("%d" , &searchNumber);
	bigger=bigNumber;
	search=searchNumber;
	
		while(bigNumber>=10)
		{
        bigNumber=bigNumber/10;	/*big number ın basamağını bulma işlemi*/
        count++;
        }
       
        
       while(searchNumber>=10)
        {
        searchNumber=searchNumber/10;/*search number ın basmaapını bylma işlemi*/
        count1++;
        }
        
       
        for(i=1;i<=count1;i++)
        {
        	x=x*10;				/*Daha sonra mod almak için search numberın basamağı kadar mod alma işlemi*/
		}
		for(i=1;i<=count;i++)
		{
			
			a=bigger % x;	/*bigger=bignumber 'ın modu böylece 1 ler basampındaki sayıya erişiyoruz*/
			
			if(a==search)
				{	
					occurrence++;	/*mod da çıkan sayı search numbera eşitse count arttırıyoruz*/


				}
			bigger=bigger/10;/*Daha sonra 1 ler basamağındaki sayıyı elemek(10 lar basamağındaki sayıya geçmek ) için 10 a bölüyoruz ve tekrar döndürüyoruz*/

		}
		printf("Occurrence : %d\n",occurrence );
}

	


















