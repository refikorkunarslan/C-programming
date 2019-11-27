#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void menu(int );
int enter_student();
void randomm(int);
int largest(int);
int smallest(int );
int letter_grade( int );
int letter_count( int);
double calculate_avarege(int );

int main()
{
	int student_count,b;      
	student_count=enter_student(); /*ögrenci sayısı girme fonksiyonu çağırdım*/
	

		while(student_count<3 || student_count>50)
			{	
					printf("Not in Range\n");
					printf("Enter student count : ");  /*3 ile 50 arasında rakam girilmediği sürece ögrenci sayını isteyecek*/
					scanf("%d",&student_count);

			}
		if(student_count>2 || student_count<51)
				{
					randomm(student_count);		/*3 ile 50 arasında sayı girildiğinde  random fonksiyonu çağrılıyor*/

				}
			printf("\n");
			printf("--------------------------------------------------------\n");
			menu(student_count);/*Daha sonra menu fonksiyonu çağırılıyor*/
}
void menu(int student_count)
{
	
	printf("Student Score Calculator Menü for %d Student\n",student_count );
	int secim;
	while(secim != -1)		/*-1 girilmediği sürecemenü sürekli dönecek*/
		{	
			printf("1) Most Successful Student\n2) Most Unsuccessful Student\n3)Letter Grade Statistics\n4)Calculate Avarege\n5) Show all data\n" );
			scanf("%d" ,&secim);
			printf("\t\tMake Selection : %d \n",secim);
			
			switch(secim){
				case -1:break;/*-1 girildiğinde switch-case den çıkacak*/
				case 1 : largest( student_count);
				printf("--------------------------------------------------------\n"); break;

				case 2 : smallest( student_count);
				printf("--------------------------------------------------------\n");break;
				case 3 : letter_count( student_count);
				printf("--------------------------------------------------------\n");break;			/*girilen sayıya göre fonksiyon çağırma işlemi*/
				case 4 :calculate_avarege( student_count); 
				printf("--------------------------------------------------------\n");break;
				case 5 :largest( student_count);printf("\n\n");
						smallest( student_count);printf("\n\n");
						letter_count( student_count);printf("\n\n");
						calculate_avarege( student_count);printf("\n\n");
						printf("--------------------------------------------------------\n");break;
				default : printf("False Selection!!!\n"); 
				printf("--------------------------------------------------------\n");break;
			}


		}
}
int enter_student()
{
	int student_count;
	printf("Enter student count : ");/*ögrenci sayısı girme fonksiyonu*/
	scanf("%d",&student_count);
	return(student_count);
	
}
void randomm(int student_count)
{
	       int i,b;
   					 srand(40);
    				for(i=1;i<=student_count;i++)	/*girilen ögrenci sayısı kadar random değer atama*/
    					{
                      b=rand()%101;			/*0-ila 100 arası değer atama*/
                      printf("%d",b);
					printf(" "); 
                      
        				}  

}
int largest(int student_count)/*girilen random sayılardan en büyüğünü ,yerini ve harf notunu bulunmasını sağlayan fonksiyon*/
{
	int temp=0;
	 int i,b,count=0,count_largest;
	 				
   					 srand(40);
    				for(i=1;i<=student_count;i++)	/*Random atılmış sayılar*/
    					{
                    		  b=rand()%101;
                      		  count++;				/*sayının index ini bulmak için her sayı için count arttırdım*/
							if(b>temp)				/*En yüksek sayıyı bulmak için b den gelen değerle temp i karlılaştırım*/
                      		{
                      			count_largest=count; /*Eger bu fonksiyonun içine girdiyse en büyük sayı değişmiştir bu yüzden bu eşitliği yaptım*/
                      			temp=b;	/*Eğer b>temp olursa b değerini temp değikenine atadım*/ 

                      		}		
                      
        				} 
        				printf("Most Successful Student : \n");
        				printf("Index:%d \n",count_largest);
        				printf("Score = %d\n" , temp);
        				letter_grade( temp);/*En başarılı ögrencinin harf notunu bulmayı sağlayan fonksiyon*/
return temp;
}
int smallest(int student_count) /*girilen random sayılardan en küçüğünü ,yerini ve harf notunu bulunmasını sağlayan fonksiyon*/
 {
 	int tem=101,count=0,count_smallest;
	 int i,a,c;
	 				
   					 srand(40);
    				for(i=1;i<=student_count;i++)/*random atılmış sayılar*/
    					{
    					count++;
                      a=rand()%101;
                    
							if(a<tem)/*yukardaki yaptığımız fonksiyonun tersini yaptım en küçük sayıyı bulmak için*/
                      		{
                      			count_smallest=count;/*fonksiyonun içine girdiğinde en küçük sayı değimiştir bu yüzden count la eşitledim*/
                      			tem=a;
                      		}
                      	} 
        				printf("Most Unsuccessful Student : \n");
        				printf("index : %d\n" , count_smallest);
        				printf("Score = %d\n" , tem); 
        				letter_grade( tem);/*En başarısız ögrencinin harf notu*/
        				
  }
 int letter_grade(int c)/*Harf notu bulmaya yarayan fonksiyon*/
 {
 	int i;
 	int count1,count2,count3,count4,count5;
 	
    				
					if(90<=c && c<=100)
					{
						
						printf("letter grade : A \n");
						
					}
					else if(80<=c && c<=89)
					{
						
						printf("letter grade : B \n");
						
					}
					else if(70<=c && c<=79)
					{
						
						printf("letter grade : C \n");
						
					}
					else if(60<=c && c<=69)
					{
						
						printf("letter grade : D \n");
						
					}
					else 
					{
						
						printf("letter grade : F \n");
						
					}
return c;

}
int letter_count(int student_count)/*her harf notundan kaç öğrenci oldupunu gösteren fonksiyon*/
{
	int count1=0,count2=0,count3=0,count4=0,count5=0;
	int z,i;
	srand(40);
    				for(i=1;i<=student_count;i++)
    					{
                      z=rand()%101;
                      
					if(90<=z && z<=100)
					{
						count1++;
						
					}
					else if(80<=z && z<=89)
					{
						count2++;
						
						
					}
					else if(70<=z && z<=79)
					{
						count3++;
						
						
					}
					else if(60<=z && z<=69)
					{
						count4++;
						
						
					}
					else 
					{
						count5++;
						
					} 
	
}
printf("%d student got letter grade 'A'\n",count1 );
	printf("%d student got letter grade 'B'\n",count2 );
	printf("%d student got letter grade 'C'\n",count3 );/*count lara göre ögrenci sayını hesaplayıp ekrana bastıyoruz*/
	printf("%d student got letter grade 'D'\n",count4 );
	printf("%d student got letter grade 'F'\n",count5 );
	

}
double calculate_avarege(int student_count)/*random atılan yıların ortalamasını bulan fonksiyon*/
{
	double sum=0.0;
	double avarege;
	int i,z;
	srand(40);
    				for(i=1;i<=student_count;i++)
    					{
                      z=rand()%101;	/*random atılan her bir sayıyı topluyoruz*/
                      sum=sum+z;
                  		}
                      avarege=sum/student_count;/*Daha sonra girilen ögrenci sayısına bölüyoruz*/

                      printf("The avarege Score of %d student is %7.2f\n" , student_count,avarege);
                     


}
















	