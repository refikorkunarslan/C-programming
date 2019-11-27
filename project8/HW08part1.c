#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include  <time.h>
typedef enum {P,S,M,B,T,empty,start,finish} rule;/*oyunun type larını belirledik*/


typedef struct {
		char text[200];
		int data;					/*struct içinde tanımlamalarımızı yaptık*/
		rule type;
		int pos_x,pos_y;
		int jump_x,jump_y;
	}block;

int init_board(block board[][10]);
int move(block board[][10],int counter);
int singlePlayer(block board[][10],int counter);
int multiPlayer(block board[][10],int counter, int counter1);


int main()
{
		int counter=0,counter1=0;
		block board[10][10];
		

	srand(time(NULL));		
	init_board(board);				/*main içersinde fonkiyonları çağırıdık*/
	 multiPlayer(board,counter,counter1);

}
int init_board(block board[][10])/*board u iniliaze atme ve ekrana bastırma*/
{
	
int k=91;			/*board[0][0]=91 oldupundan k yı 91 den başlattık*/
	
	int i,j;
	for(i=0;i<=9;i++)
		{	
			if(i%2==0)
				{ 
					for(j=0;j<=9;j++)
					{
						board[i][j].data=k;	/*eğer satır numarası 2ye tam bölünüyorsa demek ki sayılar sağa doğru artacak*/
						k=k+1;

					 }
					  k=k-11;			/*yeni satıra geçtiğinde k 11 azalacak*/
				}
			
			 else
			 	{ 
					 for(j=0;j<=9;j++)
					{
						board[i][j].data=k;/*2 ye tam bölünmüyorsa data lar sola doğru aratacak demek*/
						k=k-1;

					 }
					  k=k-9;	/*yeni satıra geçildiğinde k 9 azaltılacak*/

				}
			

		}
		for(i=0;i<=9;i++)
		{	
			 
					for(j=0;j<=9;j++)
					{
						board[i][j].type=empty;/*board ın typenın bütün değerlerine empty atadım*/
						

				 	}
					 
				

		}
		board[9][9].type=start;
		strcpy(board[9][9].text,"1(Start)");
		board[0][9].type=finish;
		strcpy(board[0][9].text,"100(Finish)");
		board[9][4].type=S;
		strcpy(board[9][4].text,"S{1}");
		board[9][3].type=M;
		strcpy(board[9][3].text,"M{11}");
		board[8][2].type=P;
		board[8][6].type=M;
		strcpy(board[8][6].text,"M{28}");
		board[7][1].type=B;
		board[7][5].type=S;
		strcpy(board[7][5].text,"S{12}");
		board[6][1].type=M;
		strcpy(board[6][1].text,"M{52}");
		board[6][5].type=B;
		board[6][9].type=T;
		board[5][0].type=B;
		board[5][2].type=P;
		board[5][5].type=S;
		strcpy(board[5][5].text,"S{22}");		/*HEPSİNE EMPTY ATADIPIMIZ TYPE IN BELLİ YERLERİNE DEĞERLER ATADIK*/
		board[4][3].type=T;
		board[4][6].type=M;
		strcpy(board[4][6].text,"M{77}");
		board[4][9].type=S;
		strcpy(board[4][9].text,"S{44}");
		board[3][1].type=M;
		strcpy(board[3][1].text,"M{77}");
		board[3][4].type=B;
		board[3][7].type=S;
		strcpy(board[3][7].text,"S{52}");
		board[2][2].type=S;
		strcpy(board[2][2].text,"S{68}");
		board[2][5].type=M;
		strcpy(board[2][5].text,"M{83}");
		board[2][8].type=T;
		board[1][1].type=M;
		strcpy(board[1][1].text,"M{94}");
		board[1][5].type=P;
		board[1][8].type=B;
		board[0][2].type=T;
		board[0][7].type=S;
		strcpy(board[0][7].text,"S{72}");
		board[0][8].type=S;
		strcpy(board[0][8].text,"S{53}");

	for(i=0;i<=9;i++)
		{	
			for(j=0;j<=9;j++)	/*Ekrana basma işlemi*/
			{
				
				if(board[i][j].type==empty)		/*Eper yerdeki teype empty se yani yukarda bir değer atanmadıysa datayı basacak*/
				{
					printf("%d",board[i][j].data );	
				}
			else if(board[i][j].type==start)
				{	
					printf("%s",board[i][j].text);

				}
			else if(board[i][j].type==finish)
				{	
					printf("%s",board[i][j].text);

				}
			else if(board[i][j].type==S)		/*Yukarda type S belirlendiyse S{x} stringini basacak*/
				{
					printf("%s",board[i][j].text);
					
				}
			else if(board[i][j].type==M)	/*Yukarda type M belirlendiyse S{x} stringini basacak*/
				{
					printf("%s",board[i][j].text);


				}
			else if(board[i][j].type==B)/*Yukarda type B belirlendiyse B basacak*/
				{
					printf("B");
				}
			else if(board[i][j].type==T)/*Yukarda type T belirlendiyse T basacak*/
				{
					printf("T");
				}
			else if(board[i][j].type==P)/*Yukarda type P belirlendiyse P basacak*/
				{
					printf("P");
				}
			
				/*ekranda güzel görünmesi için boşluk işlemleri*/
					 if(board[i][j].type==S ||board[i][j].type==M)
					{
						printf(" ");
					}

					
					
					else if(board[i][j].type==P ||board[i][j].type==B ||board[i][j].type==T)
					{
						printf("     ");
					}
					else if(board[i][j].data<10)
					{
						printf("     ");
					}
					else if(board[i][j].data>=10)
						{ 

						printf("    ");
						}

			 }
			  printf("\n");
		}




}
int move(block board[][10],int counter)/*Hareket fonksiyonu*/

{
	

	int a;
	
	
	a=rand()%6+1;	/*1-6 arası random bir sayı verildi(zar)*/
	printf("Dice: %d\n",a );

				if(board[9][9].pos_x%2==1)	/*Eğer satır numarası tekse sola doğru gidilecek*/
					{
						
						if(a>board[9][9].pos_y)/*Eğer sola dopru gidip o satırı bitiriyorsa gerekli işlemleri uygulayacak*/
						{
							board[9][9].pos_x=board[9][9].pos_x-1;	
							board[9][9].pos_y=a-board[9][9].pos_y-1;

						}	
						else
						{
							
							board[9][9].pos_y=board[9][9].pos_y-a;/*Eğer satır bitmiyorsa direk azaltacak*/
						}


					}
				else	/*Eğer satır numarası çifte sağa doğru gidecek*/
					{	
						
						if(a+board[9][9].pos_y>9)/*Eper sağa doğrı  gidip o satırı bitiriyorsa gerkli işlemler uyugulanır*/
						{
							if(board[9][9].pos_x==0 && a+board[9][9].pos_y>9)/*eper finishe yaklaşıp data 100 ü geçiyorsa counter++*/
							{
								return counter++;
								

							}
							board[9][9].pos_x=board[9][9].pos_x-1;	/*finisi gemiyorsa işlemler uyugulanır*/
							board[9][9].pos_y=10-(board[9][9].pos_y+a-9 );




						}
						else
						{

							board[9][9].pos_y=board[9][9].pos_y+a;/*satır bitmiyorsa direk sütün satısı arttırılır*/



						}




					}

	 if(board[board[9][9].pos_x][board[9][9].pos_y].data==7)/*data 7 de S olduğu için parantez içindeki sayıya gidecek*/
		{	

			board[9][9].jump_x=8;
			board[9][9].jump_y=0;
			board[9][9].pos_x=board[9][9].jump_x;
			board[9][9].pos_y=board[9][9].jump_y;

		}
	 if(board[board[9][9].pos_x][board[9][9].pos_y].type==P)/*P ye geldiği zaman duracak ve hareket işlemi yapılmayacak bu da counter u arttıracak*/
	 	{	
	 		return counter++;



	 	}
	 if(board[board[9][9].pos_x][board[9][9].pos_y].type==B)/*B ye gekdiği zaman 5 ileri doğru hareket edecek*/
		{	

			if(board[9][9].pos_x%2==1)/*yukarıdaki düz gitme işleminin aynısı yapıldı sadece a=5 olarak değiştirildi*/
					{
						
						if(5>board[9][9].pos_y)
						{
							board[9][9].pos_x=board[9][9].pos_x-1;
							board[9][9].pos_y=5-board[9][9].pos_y-1;

						}	
						else
						{
							board[9][9].pos_y=board[9][9].pos_y-5;
						}


					}
				else
					{	
						
						if(5+board[9][9].pos_y>9)
						{
							board[9][9].pos_x=board[9][9].pos_x-1;
							board[9][9].pos_y=10-(board[9][9].pos_y+5-9 );




						}
						else
						{
							board[9][9].pos_y=board[9][9].pos_y+5;
						}




					}







		}
    if(board[board[9][9].pos_x][board[9][9].pos_y].type==T)/*T ye geldiği zaman 5 geri doğru hareket yapacak*/
		{	
			if(board[9][9].pos_x%2==1)	/*yine satır numarasına göre işlem yaptık*/
					{
						
						if(5<board[9][9].pos_y)
						{
							board[9][9].pos_x=board[9][9].pos_x+1;	/*eğer oldupu yer 5 ten büyükse alt satıra gidecek */
							board[9][9].pos_y=5-board[9][9].pos_y-1;

						}
						else
						{
							board[9][9].pos_y=board[9][9].pos_y+5;
						}	


					}
				else
					{	
						
						if(board[9][9].pos_y-5<0)
						{
							board[9][9].pos_x=board[9][9].pos_x+1;
							board[9][9].pos_y=(10-(board[9][9].pos_y+5-9 ))-10;




						}
						else
						 {

						 	board[9][9].pos_y=board[9][9].pos_y-5;
						 }




					}








		}
	 if(board[board[9][9].pos_x][board[9][9].pos_y].data==6)/* parantez içindeki sayıya gidecek*/
		{	
			
			board[9][9].jump_x=9;
			board[9][9].jump_y=9;
			board[9][9].pos_x=board[9][9].jump_x;
			board[9][9].pos_y=board[9][9].jump_y;

		}
	 if(board[board[9][9].pos_x][board[9][9].pos_y].data==17)/* parantez içindeki sayıya gidecek*/
		{	
			board[9][9].jump_x=8;
			board[9][9].jump_y=6;
			board[9][9].pos_x=board[9][9].jump_x;
			board[9][9].pos_y=board[9][9].jump_y;
			

		}
	 if(board[board[9][9].pos_x][board[9][9].pos_y].data==25)/* parantez içindeki sayıya gidecek*/
		{	
			board[9][9].jump_x=8;
			board[9][9].jump_y=1;
			board[9][9].pos_x=board[9][9].jump_x;
			board[9][9].pos_y=board[9][9].jump_y;
			

		}
	
	 if(board[board[9][9].pos_x][board[9][9].pos_y].data==32)/* parantez içindeki sayıya gidecek*/
		{	
			board[9][9].jump_x=4;
			board[9][9].jump_y=1;
			board[9][9].pos_x=board[9][9].jump_x;
			board[9][9].pos_y=board[9][9].jump_y;

			
			

		}
	
		
	 if(board[board[9][9].pos_x][board[9][9].pos_y].data==44)/* parantez içindeki sayıya gidecek*/
		{	
			board[9][9].jump_x=7;
			board[9][9].jump_y=8;
			board[9][9].pos_x=board[9][9].jump_x;
			board[9][9].pos_y=board[9][9].jump_y;

			
			

		}
	
	if(board[board[9][9].pos_x][board[9][9].pos_y].data==57)/* parantez içindeki sayıya gidecek*/
		{	
			board[9][9].jump_x=2;
			board[9][9].jump_y=6;
			board[9][9].pos_x=board[9][9].jump_x;
			board[9][9].pos_y=board[9][9].jump_y;

			
			

		}
	if(board[board[9][9].pos_x][board[9][9].pos_y].data==60)/* parantez içindeki sayıya gidecek*/
		{	
			board[9][9].jump_x=5;
			board[9][9].jump_y=5;
			board[9][9].pos_x=board[9][9].jump_x;
			board[9][9].pos_y=board[9][9].jump_y;

		}
	 if(board[board[9][9].pos_x][board[9][9].pos_y].data==63)/* parantez içindeki sayıya gidecek*/
		{	
			board[9][9].jump_x=4;
			board[9][9].jump_y=1;
			board[9][9].pos_x=board[9][9].jump_x;
			board[9][9].pos_y=board[9][9].jump_y;

			
			

		}
	 if(board[board[9][9].pos_x][board[9][9].pos_y].data==69)/* parantez içindeki sayıya gidecek*/
		{	
			board[9][9].jump_x=2;
			board[9][9].jump_y=6;
			board[9][9].pos_x=board[9][9].jump_x;
			board[9][9].pos_y=board[9][9].jump_y;

			
			

		}
	 if(board[board[9][9].pos_x][board[9][9].pos_y].data==73)/* parantez içindeki sayıya gidecek*/
		{	
			board[9][9].jump_x=3;
			board[9][9].jump_y=2;
			board[9][9].pos_x=board[9][9].jump_x;
			board[9][9].pos_y=board[9][9].jump_y;

			
			

		}
	 if(board[board[9][9].pos_x][board[9][9].pos_y].data==76)/* parantez içindeki sayıya gidecek*/
		{	
			board[9][9].jump_x=1;
			board[9][9].jump_y=7;
			board[9][9].pos_x=board[9][9].jump_x;
			board[9][9].pos_y=board[9][9].jump_y;

			
			

		}
	
		
	 if(board[board[9][9].pos_x][board[9][9].pos_y].data==89)/* parantez içindeki sayıya gidecek*/
		{	
			board[9][9].jump_x=0;
			board[9][9].jump_y=3;
			board[9][9].pos_x=board[9][9].jump_x;
			board[9][9].pos_y=board[9][9].jump_y;
			

		}
	 if(board[board[9][9].pos_x][board[9][9].pos_y].data==93)/* parantez içindeki sayıya gidecek*/
		{	
			
			

		}
	 if(board[board[9][9].pos_x][board[9][9].pos_y].data==98)/* parantez içindeki sayıya gidecek*/
		{	
			board[9][9].jump_x=2;
			board[9][9].jump_y=1;
			board[9][9].pos_x=board[9][9].jump_x;
			board[9][9].pos_y=board[9][9].jump_y;
			

		}
	 if(board[board[9][9].pos_x][board[9][9].pos_y].data==99)/* parantez içindeki sayıya gidecek*/
		{	
			board[9][9].jump_x=4;
			board[9][9].jump_y=5;
			board[9][9].pos_x=board[9][9].jump_x;
			board[9][9].pos_y=board[9][9].jump_y;
			

		}
	

	

	printf("pos_x :%d\n",board[9][9].pos_x );
	printf("pos_y :%d\n",board[9][9].pos_y );


	printf("data :%d\n",board[board[9][9].pos_x][board[9][9].pos_y].data);


}
int singlePlayer(block board[][10],int counter)
{
printf("////////////////////////////////////////////////////////////\n");
move(board,counter);/*move fonksiyonunu çağırdık*/
	if(board[board[9][9].pos_x][board[9][9].pos_y].data==100)/*eğer finish e vardıysa işlem tamam*/
	{
		
		return counter;
	}
	else if(board[9][9].pos_x==0 && board[9][9].pos_y==9 )
		return 0;
	else if(board[9][9].pos_x<0 || board[9][9].pos_y>9 )
		return 0;	
	else
	{
		counter=counter+1;	/*counter u arttırdık ger döndürmesinde sonra*/
		printf("counter :%d\n ",counter);		
		return singlePlayer(board,counter);/*recursive*/

	}




}
int multiPlayer(block board[][10],int counter,int counter1)/*bu fonksiyonda 2 oyuncudan en az counter a sahip olan oyunu kazaznmı olacak*/
{
	int a,b;
	board[9][9].pos_x=9;
		board[9][9].pos_y=9;
	a=singlePlayer(board, counter);	
	printf("************PLAYER 2*******************\n");
	board[9][9].pos_x=9;
		board[9][9].pos_y=9;
	b=singlePlayer(board, counter1);
	printf("Player1 counter:%d \n Player2 counter:%d \n",a,b );

		if(a>b)
		{
			printf("Player2 WİN\n");
		}
		else if(a<b)
		{
			printf("PLayer1 WİN\n");
		}


	return 0 ;
}