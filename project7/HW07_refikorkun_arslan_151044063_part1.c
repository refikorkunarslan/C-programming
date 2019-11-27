#include <stdio.h>
typedef enum {white_man, black_man, white_king, black_king, empty} piece;
typedef enum {white = 10, black = 20} player;

void init_board( piece board[][8]);
void display_board(piece board[][8]);
int move(piece board[][8], int from_x, int from_y, int to_x, int to_y, player p);
int check_end_of_game(piece board[][8]);
void sample_game_1();


int main()
{
	sample_game_1();
}
void init_board( piece board[][8])
{
	int i ,j;
	for(i=0;i<=7;i++)
		{	
			for(j=0;j<=7;j++)
			{
			  board[i][j]=empty;		/*büyün tahtaya boş değer atdık*/

			}


		}
	for(i=1;i<=2;i++)
		{	
			for(j=0;j<=7;j++)
			{
 	
				  board[i][j]=black_man;	/*1 ve 2.satırlar black man atadım*/
			}


		}


	for(i=5;i<=6;i++)
		{	
			for(j=0;j<=7;j++)
			{
				 board[i][j]=white_man;	/*5 ve 6 satırları white man atadım*/

			}


		}
		

	
		
}
void display_board(piece board[][8])
{
	int i,j;
	for(i=0;i<=7;i++)
		{	
			for(j=0;j<=7;j++)
			{
				if(  board[i][j]==empty)
					{	

						printf("-");

					}
				else if( board[i][j]==black_man)
					{	

						printf("b");

					}
				else if( board[i][j]==white_man)
					{	

						printf("w");

					}
				else if( board[i][j]==white_king)
					{	

						printf("W");

					}
				else if( board[i][j]==black_king)
					{	

						printf("B");

					}				

			}

			printf("\n");
			
		}



}
int move(piece board[][8], int from_x, int from_y, int to_x, int to_y, player p)
{
	
	if(p==white)
	{
		if(board[to_x][to_y]==black_man &&  board[to_x-1][to_y]==empty&& to_x>-1 )/*eğer yiyeceği taşın arkası bpşsa while a gircek*/
							{	
								
							
						
							
								board[to_x-1][to_y]=white_man;	/*direk seçtiğimiz yerin bir arkasına white yapacak*/
								board[to_x+1][to_y]=empty;		/*oynadığımız yerden white man ı silecek*/
								board[to_x][to_y]=empty;	/*daha sonra yediğimiz black man ı silecek*/

								to_x=to_x-1;
								 	/*yeni yer olması için to_x i 1 azalttık*/
								if(to_x==0)
								{
									board[to_x][to_y]=white_king;	/*to_x =0 olduğunda white en uca ulaşmıştır white king olur*/

								}
								
								
								
								
								if(board[to_x][to_y+1]==black_man &&board[to_x][to_y+2]==empty &&to_y<6)
									{	
										
												
											
											
											board[to_x][to_y+2]=white_man;	/*daha sonra sağa doğru gidiyor mu dite kontrol edeceğiz böylece sağa doğru yenebilecek taş varsa onu yiyecek*/
											board[to_x][to_y+1]=empty;
											board[to_x][to_y]=empty;
											to_y=to_y+2;

											
											
						        	
							

										
										
						            }
						           

						         if(board[to_x][to_y-1]==black_man && board[to_x][to_y-2]==empty&& to_y>-1)
						           {
						           		
						           			board[to_x][to_y-2]=white_man;	/*daha sonra sola doğru gidiyor mu diye kontrol edeceğiz böylece sola doğru yenebilecek taş varsa onu yiyecek*/
						           			board[to_x][to_y-1]=empty;
						           			board[to_x][to_y]=empty;
						           			to_y=to_y-2;
						           		

						           	
						           			


						           }
						           move(board, from_x,  from_y, to_x-1, to_y, p);		/*daha sonra tekrar x in gidelebilecği dikine göre gidebilir mi diye to_x i bir azalttık*/
						          	

						
							}
	
	else if(board[to_x][to_y]==black_man &&board[to_x][to_y+1]==empty && to_y<8 && to_x==from_x)
							{
								
								
											board[to_x][to_y+1]=white_man;	/*bunda ilk sağa doğru gitme olayına baktık*/
											board[to_x][to_y]=empty;
											board[to_x][to_y-1]=empty;
											to_y=to_y+1;
											
											if(board[to_x-1][to_y]==black_man &&  board[to_x-2][to_y]==empty&& to_x>-1)
											{
												board[to_x-2][to_y]=white_man;
												board[to_x][to_y]=empty;
												board[to_x-1][to_y]=empty;			/*sağa gittikten sonra tekrar dikine gidebilir mi onu kontrol ettik şartlar saglarsa uyguladık*/

												to_x=to_x-2;
												if(to_x==0)
													{
														board[to_x][to_y]=white_king;/*to_x =0 olduğunda white en uca ulaşmıştır white king olur*/

													}

												
											}
											if(board[to_x][to_y-1]==black_man && board[to_x][to_y-2]==empty&& to_y>-1)
											{
											board[to_x][to_y-2]=white_man;
						           			board[to_x][to_y-1]=empty;
						           			board[to_x][to_y]=empty;	/*Sola doğru gitme olayını kontrol ettik eğer gidiyorsa şartlar uyguladık*/
						           			to_y=to_y-2;
						           		

						           	
						           			
						           			}
						            move(board, from_x,  from_y, to_x, to_y+1, p);/*en son tekrar sağa doğru gidiyor mu diye kontrol etmek için to_y 1 arttırdık*/ 


							}

	else if((board[to_x][to_y]==black_man ||board[to_x][to_y]==black_king) && board[to_x][to_y-1]==empty&& to_y>-1)
							{	
								
								
											board[to_x][to_y-1]=white_man;/*bu while da ise ilk başta sola gitme olayına baktık*/
						           			board[to_x][to_y+1]=empty;
						           			board[to_x][to_y]=empty;
						           			to_y=to_y-1;
						           			if(board[to_x-1][to_y]==black_man &&  board[to_x-2][to_y]==empty&& to_x>-1)
						           			{
						           				board[to_x-2][to_y]=white_man;
												board[to_x][to_y]=empty;	/*sola gittikten sonra tekrar dikine gidebilir mi onu kontrol ettik şartlar saglarsa uyguladık*/
												board[to_x-1][to_y]=empty;

												to_x=to_x-2;
												if(to_x==0)
													{
														board[to_x][to_y]=white_king;

													}
												

						           			}
						           			if(board[to_x][to_y+1]==black_man &&board[to_x][to_y+2]==empty &&to_y<8)
						           			{

													board[to_x][to_y+2]=white_man;
													board[to_x][to_y+1]=empty;
													board[to_x][to_y]=empty;	/*sağa doğru gitme olayını kontrol ettik*/
														to_y=to_y+2;

											
											
						        	 				

											}
								move(board, from_x,  from_y, to_x, to_y-1, p);
											/*en son tekrar sola doğru gidiyor mu diye kontrol etmek için to_y 1 arttırdık*/ 
								}
	else if(board[to_x][to_y]==empty)
	{
		
		board[to_x][to_y]=white_man;
		board[from_x][from_y]=empty;





	}
	

	}
	if(p==black)
	{

		if(board[to_x][to_y]==white_man &&  board[to_x+1][to_y]==empty&& to_x<8 &&to_y==from_y)
							{	
								
						
							
								board[to_x+1][to_y]=black_man;
								board[to_x-1][to_y]=empty;	/*ilk dikine gitme olayına bakıyor*/
								board[to_x][to_y]=empty;

								to_x=to_x+1;
								if(to_x==7)
								{
									board[to_x][to_y]=black_king;

								}

								
								
								if(board[to_x][to_y+1]==white_man &&board[to_x][to_y+2]==empty &&to_y<8)
									{	

										
												
											
											
											board[to_x][to_y+2]=black_man;	/*daha sonra sağa gitme olayına göre bakıyor*/
											board[to_x][to_y+1]=empty;
											board[to_x][to_y]=empty;
											to_y=to_y+2;


											
											
						        	 
							

										
										
						            }
						           

						         if(board[to_x][to_y-1]==white_man && board[to_x][to_y-2]==empty&& to_y>0)
						           {
						           	
						           		
						           			board[to_x][to_y-2]=black_man;
						           			board[to_x][to_y-1]=empty;		/*sola gitme durumuna bakıyor*/
						           			board[to_x][to_y]=empty;
						           			to_y=to_y-2;
						           		

						           	
						           			


						           }
						         move(board, from_x,  from_y, to_x+1, to_y, p);/*tekrar dikine gitme olayına bakıyor*/
						
							}

		if(board[to_x][to_y]==white_man &&board[to_x][to_y+1]==empty &&to_y<8)
							{
								
											board[to_x][to_y+1]=black_man;
											board[to_x][to_y]=empty;			/*sağa gitme olayına bakıyor*/
											board[to_x-1][to_y]=empty;
											to_y=to_y+1;
											
											if(board[to_x+1][to_y]==white_man &&  board[to_x+2][to_y]==empty&& to_x<8)
											{
												board[to_x+2][to_y]=black_man;
												board[to_x][to_y]=empty;
												board[to_x+1][to_y]=empty;	/*dikine gitme olayını bitirdikten sonra sağa gitme durumuna bakıyor*/

												to_x=to_x+2;
												if(to_x==7)
													{
														board[to_x][to_y]=black_king;

													}
												
											}
											if(board[to_x][to_y-1]==white_man && board[to_x][to_y-2]==empty&& to_y>-1)
											{
											board[to_x][to_y-2]=black_man;
						           			board[to_x][to_y-1]=empty;		/*daha sonra sola gitme olayına bakıyor*/
						           			board[to_x][to_y]=empty;
						           			to_y=to_y-2;
						           		

						           	
						           			
						           			}
						           			move(board, from_x,  from_y, to_x, to_y+1, p);
						           		/*tekrar sağa gitme durumuna bakmak için to_y 1 arttırıyor*/


							}
		if(board[to_x][to_y]==white_man && board[to_x][to_y-1]==empty && to_y>-1)
							{	

											board[to_x][to_y-1]=black_man;
						           			board[to_x][to_y+1]=empty;		/*sola gitme olayına bakıyor*/
						           			board[to_x][to_y]=empty;
						           			to_y=to_y-1;
						           			if(board[to_x+1][to_y]==white_man &&  board[to_x+2][to_y]==empty&& to_x<8)
						           			{
						           				
						           				board[to_x+2][to_y]=black_man;
												board[to_x][to_y]=empty;
												board[to_x+1][to_y]=empty;		/*dikine gitme olayına bakıyor*/

												to_x=to_x-2;
												if(to_x==7)
														{
															board[to_x][to_y]=black_king;

														}
														

						           			}
						           			if(board[to_x][to_y+1]==white_man &&board[to_x][to_y+2]==empty &&to_y<8)
						           			{
						           				

													board[to_x][to_y+2]=black_man;
													board[to_x][to_y+1]=empty;	/*sağa gitme olayına bakıyor*/
													board[to_x][to_y]=empty;
														to_y=to_y+2;

											
											
						        	 				

											}

						           		
											move(board, from_x,  from_y, to_x, to_y-1, p);/*Tekrar sola gitme olayına göre to_y 1 azalttıyoruz*/
								}
					
		if(board[to_x][to_y]==empty)
	{
		
		board[to_x][to_y]=black_man;
		board[from_x][from_y]=empty;





	}


















	}

}
int check_end_of_game(piece board[][8])
{
	int i,j,count_white=0,count_black=0;
			for(i=0;i<=7;i++)
				{
					for(j=0;j<=7;j++)
					{
						if(board[i][j] == white_man ||board[i][j] == white_king)
						{
							count_white +=1;								/*white man in sayısını buluyoruz*/
							
						}
						else if(board[i][j] == black_man || board[i][j] == black_king)
						{
							count_black +=1;		/*black man ib sayısını buluyoruz*/
							


						}
						



					}





				}
	if(count_white==0)
		{	
			printf("Black wins the game.\n");	/*eğer white man kalmayınca black win olacak*/
			return 1;

		}
	else if(count_black==0)
		{	


			printf("White wins the game.\n");		/*eğer black man kalmayınca white win olacak*/
			return 1;
		}
		printf("Game countinues\n");	/*2 side varsa oyuna devam*/
		return -1;

}
void sample_game_1()	/*kendi oluşturduğum senaryoya göre oynattım*/
{
	int i ,j,x,y,xs,ys,flag;
	int status;

	piece board[8][8];

	
	for(i=0;i<=7;i++)
		{	
			for(j=0;j<=7;j++)
			{
			  board[i][j]=empty;

			}


		}
	for(i=1;i<=2;i++)
		{	
			for(j=0;j<=7;j++)
			{
 
				  board[i][j]=black_man;
			}


		}


	for(i=5;i<=6;i++)
		{	
			for(j=0;j<=7;j++)
			{
				 board[i][j]=white_man;

			}


		}	
	
	
	display_board(board);

	move(board, 5, 0, 4, 0,  white);
	display_board(board);
	check_end_of_game( board);
	
	
	move(board, 2, 0, 3, 0,  black);
	display_board(board);
	check_end_of_game( board);
	

	move(board, 5, 5, 4, 5,  white);
	display_board(board);
	check_end_of_game( board);

	move(board, 2, 2, 3, 2,  black);
	display_board(board);
	check_end_of_game( board);

	move(board, 5, 4, 4, 4,  white);
	display_board(board);
	check_end_of_game( board);


	move(board, 2, 4, 3, 4,  black);
	display_board(board);
	check_end_of_game( board);


	move(board, 4, 0, 3, 0,  white);
	display_board(board);
	check_end_of_game( board);


	move(board, 2, 7, 3, 7,  black);

	display_board(board);
	check_end_of_game( board);



	move(board, 6, 0, 5, 0,  white);
	display_board(board);
	check_end_of_game( board);
		


	move(board, 2, 5, 3, 5,  black);
	display_board(board);
	check_end_of_game( board);
	

	move(board, 4, 5, 3, 5,  white);
	display_board(board);
	check_end_of_game( board);
		
	move(board, 3, 4, 4, 4,  black);
	display_board(board);
	check_end_of_game( board);
	
}
