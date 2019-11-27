#include <stdio.h>
typedef enum {white_man, black_man, white_king, black_king, empty} piece;
typedef enum {white = 10, black = 20} player;

void init_board( piece board[][8]);
void display_board(piece board[][8]);
int move(piece board[][8], int from_x, int from_y, int to_x, int to_y, player p);
int check_end_of_game(piece board[][8]);
void sample_game_1();
void sample_game_2();

int main()
{
	 sample_game_1();
	 printf("\n");
	 printf("-------------------------------------------------------------\n");
	 sample_game_2();

	
	
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
/*oyundaki hareketleri bu fonksiyonda hallettim*/
int move(piece board[][8], int from_x, int from_y, int to_x, int to_y, player p)
{
	
	if(p==white)					/*white ın sırasıysa devam edecek*/	
		{	
			
			if(board[from_x][from_y]==black_man)
			{
				
				return -1;							/*sıra white da olduğu için black man oynanınca return -1 yapıyor*/								
			}
			else if(board[from_x][from_y]==white_king)	/*Oynatmak istedipimiz taş white_king ise*/
			{
				int count=0, i;
				
				if(board[to_x][to_y]==empty)	/*oyanaycağımız yer boş ise*/		
				{ 
					if(to_x>from_x)	
					{	
							for(i=from_x+1 ;i<=to_x;i++)
									{	
										if(board[i][from_y]==black_man)
												{ 
															
															count++;		/*white king gideceği yere kadar kaç tane taş olduğunu gösteriyor from_x to_x arasında*/
														
												}
						
									}
							if(count==1)
									{
										board[from_x][from_y]=empty;	/*count 1 değerinde ise direk arada taşı yiyor ve white kingin gideceği yere götürüyor*/
										board[to_x][to_y]=white_king;

										for(i=from_x+1 ;i<=to_x;i++)
												{	
														if(board[i][from_y]==black_man||board[i][from_y]==black_king )
																{ 
																	board[i][from_y]=empty;
																}
						
												}

						
									}
							else if(count==0)
									{

										board[from_x][from_y]=empty;	/*count 0 yani gideceği yerle arasında taş yoksa gideceği yere gidiyor*/
										board[to_x][to_y]=white_king;





									}
							else if(count>1)
									{
										for(i=from_x+1;i<to_x;i++)
										{
											if(board[i][from_y]==black_man && board[i+1][from_y]==black_man)
												{																

														return -2;	/*2 black man yanyanaysa hata vercek*/

												}
											else

												{
													board[from_x][from_y]=empty;
													board[to_x][to_y]=white_king;
													if(board[i][from_y]==black_man || board[i][from_y]==black_king)	/*aradaki taş 2 den fazla olup aralarında boşluk varsa direk aradakileri siliyor ve white king gideceği yere gidiyor*/
																{ 
																	board[i][from_y]=empty;
																}




												}

										}

										
											

									}
					}

					
					

					if(from_x>to_x)	
					{	
							for(i=to_x+1 ;i<=from_x;i++)
									{	
										if(board[i][from_y]==black_man)
												{ 
															
															count++;	/*white king gideceği yere kadar kaç tane taş olduğunu gösteriyor from_x to_x arasında*/
														
												}
						
									}
							if(count==1)
									{
										board[from_x][from_y]=empty;	/*count 1 değerinde ise direk arada taşı yiyor ve white kingin gideceği yere götürüyor*/
										board[to_x][to_y]=white_king;

										for(i=to_x+1 ;i<=from_x;i++)
												{	
														if(board[i][from_y]==black_man || board[i][from_y]==black_king)
																{ 
																	board[i][from_y]=empty;
																	}
						
												}
						
									}
							else if(count==0)
									{

										board[from_x][from_y]=empty;	/*count 0 yani gideceği yerle arasında taş yoksa gideceği yere gidiyor*/
										board[to_x][to_y]=white_king;





									}
							else if(count>1)
									{
										for(i=to_x+1;i<from_x;i++)
										{
											if(board[i][from_y]==black_man && board[i+1][from_y]==black_man)
												{	

														return -2;/*2 black man yanyanaysa hata vercek*/

												}
											else

												{
													board[from_x][from_y]=empty;
													board[to_x][to_y]=white_king;
													if(board[i][from_y]==black_man || board[i][from_y]==black_king)
																{ 
																	board[i][from_y]=empty;	/*aradaki taş 2 den fazla olup aralarında boşluk varsa direk aradakileri siliyor ve white king gideceği yere gidiyor*/
																}




												}

										}

										
											


									}
					}		


				
				count=0;
				

				if(to_y>from_y)	
					{	
							for(i=from_y+1 ;i<=to_y;i++)
									{	
										if(board[to_x][i]==black_man ||board[to_x][i]==black_king)
												{ 
														
															count++;	/*white king gideceği yere kadar kaç tane taş olduğunu gösteriyor from_x to_x arasında*/
														
												}
						
									}
							if(count==1)
									{
										board[from_x][from_y]=empty;	/*count 1 değerinde ise direk arada taşı yiyor ve white kingin gideceği yere götürüyor*/
										board[to_x][to_y]=white_king;

										for(i=from_y+1 ;i<=to_y;i++)
												{	
														if(board[to_x][i]==black_man ||board[to_x][i]==black_king)
																{ 
																	board[to_x][i]=empty;
																}
						
												}
						
									}
							else if(count==0)
									{

										board[from_x][from_y]=empty;
										board[to_x][to_y]=white_king;	/*count 0 yani gideceği yerle arasında taş yoksa gideceği yere gidiyor*/





									}
							else if(count>1)
									{
										for(i=from_y+1;i<to_y;i++)
										{
											if(board[from_x][i]==black_man && board[from_x][i+1]==black_man)
												{	

														return -2;	/*2 black man yanyanaysa hata vercek*/

												}
											else

												{
													board[from_x][from_y]=empty;
													board[to_x][to_y]=white_king;
													if(board[to_x][i]==black_man || board[to_x][i]==black_king)
																{ 
																	board[to_x][i]=empty;	/*aradaki taş 2 den fazla olup aralarında boşluk varsa direk aradakileri siliyor ve white king gideceği yere gidiyor*/
																}




												}

										}

										
										


									}
									
					}
					count=0;
					


					if(from_y>to_y)	
					{	
							for(i=to_y+1 ;i<=from_y;i++)
									{	
										if(board[from_x][i]==black_man ||board[to_x][i]==black_king)
												{ 
														
															count++;	/*white king gideceği yere kadar kaç tane taş olduğunu gösteriyor from_x to_x arasında*/
														
												}
						
									}
							if(count==1)
									{
										board[from_x][from_y]=empty;
										board[to_x][to_y]=white_king;/*count 1 değerinde ise direk arada taşı yiyor ve white kingin gideceği yere götürüyor*/

										for(i=to_y+1 ;i<=from_y;i++)
												{	
														if(board[to_x][i]==black_man ||board[to_x][i]==black_king)
																{ 
																	board[from_x][i]=empty;
																	}
						
												}
						
									}
							else if(count==0)
									{

										board[from_x][from_y]=empty;
										board[to_x][to_y]=white_king;





									}
							else if(count>1)
									{
										for(i=to_y+1;i<from_x;i++)
										{
											if(board[from_x][i]==black_man && board[from_x][i+1]==black_man)
												{	

														return -2;/*2 black man yanyanaysa hata vercek*/

												}
											else

												{
													board[from_x][from_y]=empty;
													board[to_x][to_y]=white_king;
													if(board[from_x][i]==black_man ||board[from_x][i]==black_king)
																{ 
																	board[from_x][i]=empty;	/*aradaki taş 2 den fazla olup aralarında boşluk varsa direk aradakileri siliyor ve white king gideceği yere gidiyor*/
																}




												}

										}

										
											


									}
					}		


				

				

			}

			}
			else if(!(from_x-to_x==1 && from_y==to_y) && (to_y-from_y==1 && from_x==from_x)&&(to_y-from_y==-1 && from_x==from_x) )
			{
				

				return -2;				/*arkaya gitme ve hem x ve y aynı anda arttırma yada azaltma gibi olaylarda return -2*/
			}
			else if(board[to_x][to_y]==black_man ||board[to_x][to_y]==black_king )	/*seçtiğimiz yer black man yada black king ise atlama yapacak*/
			{
				 
						while(board[to_x][to_y]==black_man &&  board[to_x-1][to_y]==empty&& to_x>-1 )/*eğer yiyeceği taşın arkası bpşsa while a gircek*/
							{	
							
						
							
								board[to_x-1][to_y]=white_man;	/*direk seçtiğimiz yerin bir arkasına white yapacak*/
								board[to_x+1][to_y]=empty;		/*oynadığımız yerden white man ı silecek*/
								board[to_x][to_y]=empty;	/*daha sonra yediğimiz black man ı silecek*/

								to_x=to_x-1;		/*yeni yer olması için to_x i 1 azalttık*/
								if(to_x==0)
								{
									board[to_x][to_y]=white_king;	/*to_x =0 olduğunda white en uca ulaşmıştır white king olur*/

								}
								
								
								
								
								while(board[to_x][to_y+1]==black_man &&board[to_x][to_y+2]==empty &&to_y<6)
									{	
										
												
											
											
											board[to_x][to_y+2]=white_man;	/*daha sonra sağa doğru gidiyor mu dite kontrol edeceğiz böylece sağa doğru yenebilecek taş varsa onu yiyecek*/
											board[to_x][to_y+1]=empty;
											board[to_x][to_y]=empty;
											to_y=to_y+2;

											
											
						        	
							

										
										
						            }
						           

						         while(board[to_x][to_y-1]==black_man && board[to_x][to_y-2]==empty&& to_y>-1)
						           {
						           		
						           			board[to_x][to_y-2]=white_man;	/*daha sonra sola doğru gidiyor mu diye kontrol edeceğiz böylece sola doğru yenebilecek taş varsa onu yiyecek*/
						           			board[to_x][to_y-1]=empty;
						           			board[to_x][to_y]=empty;
						           			to_y=to_y-2;
						           		

						           	
						           			


						           }
						          to_x=to_x-1;		/*daha sonra tekrar x in gidelebilecği dikine göre gidebilir mi diye to_x i bir azalttık*/


						
							}
						
					


				    
				
					while(board[to_x][to_y]==black_man &&board[to_x][to_y+1]==empty && to_y<8 && to_x==from_x)
							{
								
											board[to_x][to_y+1]=white_man;	/*bunda ilk sağa doğru gitme olayına baktık*/
											board[to_x][to_y]=empty;
											board[to_x][to_y-1]=empty;
											to_y=to_y+1;
											
											while(board[to_x-1][to_y]==black_man &&  board[to_x-2][to_y]==empty&& to_x>-1)
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
											while(board[to_x][to_y-1]==black_man && board[to_x][to_y-2]==empty&& to_y>-1)
											{
											board[to_x][to_y-2]=white_man;
						           			board[to_x][to_y-1]=empty;
						           			board[to_x][to_y]=empty;	/*Sola doğru gitme olayını kontrol ettik eğer gidiyorsa şartlar uyguladık*/
						           			to_y=to_y-2;
						           		

						           	
						           			
						           			}
						           	to_y=to_y+1;/*en son tekrar sağa doğru gidiyor mu diye kontrol etmek için to_y 1 arttırdık*/ 


							}
						while((board[to_x][to_y]==black_man ||board[to_x][to_y]==black_king) && board[to_x][to_y-1]==empty&& to_y>-1)
							{	
								
											board[to_x][to_y-1]=white_man;/*bu while da ise ilk başta sola gitme olayına baktık*/
						           			board[to_x][to_y+1]=empty;
						           			board[to_x][to_y]=empty;
						           			to_y=to_y-1;
						           			while(board[to_x-1][to_y]==black_man &&  board[to_x-2][to_y]==empty&& to_x>-1)
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
						           			while(board[to_x][to_y+1]==black_man &&board[to_x][to_y+2]==empty &&to_y<8)
						           			{

													board[to_x][to_y+2]=white_man;
													board[to_x][to_y+1]=empty;
													board[to_x][to_y]=empty;	/*sağa doğru gitme olayını kontrol ettik*/
														to_y=to_y+2;

											
											
						        	 				

											}

						           		
											to_y=to_y-1;/*en son tekrar sola doğru gidiyor mu diye kontrol etmek için to_y 1 arttırdık*/ 
								}
			}
			else if(board[from_x][from_y]==white_man &&board[to_x][to_y]==empty && ((from_x-to_x==1 && from_y==to_y) || (to_y-from_y==1 && from_x==from_x)||(to_y-from_y==-1 && from_x==from_x)))
			{	
				
				
				board[to_x][to_y]=white_man;
				board[from_x][from_y]=empty;	/*eğer atlama işlemi yoksa direk taş seçilen yere gider şartlara uygun oluduğu zamanda*/
				if(to_x==0)
				{
				board[to_x][to_y]=white_king;		

				}

				
			}
			


											
											
						        	 		








	}
	
	if(p==black)		/*white yaptığımız herşeyi black te uyguladık*/
	{


			if(board[from_x][from_y]==white_man)
			{
				return -1;			/*oynadğımız taş karşı oyuncunu taşı ise return -1*/
			}
			else if(board[from_x][from_y]==black_king)	/*oynadığımız taş black king ise */
			{

				int count=0, i;
				
				if(board[to_x][to_y]==empty)		/*ve oynayacağımız yer boş ise*/
				{ 
					if(to_x>from_x)	
					{	
							for(i=from_x+1 ;i<=to_x;i++)
									{	
										if(board[i][from_y]==white_man)
												{ 
														
															count++;	/*from dan to ya kadarkaç taş var ise onların sayısı*/
														
												}
						
									}
							if(count==1)
									{
										board[from_x][from_y]=empty;
										board[to_x][to_y]=black_king;

										for(i=from_x+1 ;i<=to_x;i++)
												{	
														if(board[i][from_y]==white_man || board[i][from_y]==white_king)
																{ 
																	board[i][from_y]=empty;	/*count 1 ise direk otaşı silip gideceği yere white kingi götürüyor*/
																}
						
												}
						
									}
							else if(count==0)
									{

										board[from_x][from_y]=empty;
										board[to_x][to_y]=black_king;	/*eğer arda taş yok ise direk götürüyor*/





									}
								else if(count>1)
									{
										for(i=from_x+1;i<to_x;i++)
										{
											if(board[i][from_y]==white_man && board[i+1][from_y]==white_man)
												{	

														return -2;		/*ard arda beyaz taş var ise return -1*/

												}
											else

												{
													board[from_x][from_y]=empty;
													board[to_x][to_y]=black_king;
													if(board[i][from_y]==white_man ||board[i][from_y]==white_man || board[i][from_y]==white_king)
																{ 
																	board[i][from_y]=empty;	/*ard arda taş yok ise aradak taşları siler ve white king yerine gider*/
																}




												}

										}

										
											


									}
							
					}
										
					

					if(from_x>to_x)	
					{	
							for(i=to_x+1 ;i<=from_x;i++)
									{	
										if(board[i][from_y]==white_man ||board[i][from_y]==white_king)
												{ 
														
															count++;
														
												}
						
									}
							if(count==1)
									{
										board[from_x][from_y]=empty;
										board[to_x][to_y]=black_king;

										for(i=to_x+1 ;i<=from_x;i++)
												{	
														if(board[i][from_y]==white_man ||board[i][from_y]==white_king)
																{ 
																	board[i][from_y]=empty;
																	}
						
												}
						
									}
							else if(count==0)
									{

										board[from_x][from_y]=empty;
										board[to_x][to_y]=black_king;





									}
							else if(count>1)
									{
										for(i=to_x+1;i<from_x;i++)
										{
											if(board[i][from_y]==black_man && board[i+1][from_y]==white_man)
												{	

														return -2;

												}
											else

												{
													board[from_x][from_y]=empty;
													board[to_x][to_y]=black_king;
													if(board[i][from_y]==white_man||board[i][from_y]==white_man ||board[i][from_y]==white_king )
																{ 
																	board[i][from_y]=empty;
																}




												}

										}

										
											


									}
					}		


				

				 
				 count=0;
				if(to_y>from_y)	
					{	
							for(i=from_y+1 ;i<=to_y;i++)
									{	
										if(board[to_x][i]==white_man ||board[to_x][i]==white_king)
												{ 
														
															count++;
														
												}
						
									}
							if(count==1)
									{
										board[from_x][from_y]=empty;
										board[to_x][to_y]=black_king;

										for(i=from_y+1 ;i<=to_y;i++)
												{	
														if(board[to_x][i]==white_man ||board[to_x][i]==white_king)
																{ 
																	board[to_x][i]=empty;
																}
						
												}
						
									}
							else if(count==0)
									{

										board[from_x][from_y]=empty;
										board[to_x][to_y]=black_king;





									}
							else if(count>1)
									{
										for(i=from_y+1;i<to_x;i++)
										{
											if(board[from_x][i]==black_man && board[from_x][i+1]==black_man)
												{	

														return -2;

												}
											else

												{
													board[from_x][from_y]=empty;
													board[to_x][to_y]=black_king;
													if(board[from_x][i]==white_man ||board[from_x][i]==white_man ||board[from_x][i]==white_king)
																{ 
																	board[from_y][i]=empty;
																}




												}

										}

										
											


									}
					}
					count=0;
					


					if(from_y>to_y)	
					{	
							for(i=to_y+1 ;i<=from_y;i++)
									{	
										if(board[to_x][i]==white_man ||board[to_x][i]==white_king)
												{ 
														
															count++;
														
												}
						
									}
							if(count==1)
									{
										board[from_x][from_y]=empty;
										board[to_x][to_y]=black_king;

										for(i=to_y+1 ;i<=from_y;i++)
												{	
														if(board[to_x][i]==white_man || board[to_x][i]==white_king)
																{ 
																	board[to_x][i]=empty;
																	}
						
												}
						
									}
							else if(count==0)
									{

										board[from_x][from_y]=empty;
										board[to_x][to_y]=black_king;





									}
							else if(count>1)
									{
										for(i=to_y+1;i<from_x;i++)
										{
											if(board[from_x][i]==black_man && board[from_x][i+1]==black_man)
												{	

														return -2;

												}
											else

												{
													board[from_x][from_y]=empty;
													board[to_x][to_y]=black_king;
													if(board[from_x][i]==white_man || board[from_x][i]==white_man || board[from_x][i]==white_king)
																{ 
																	board[from_x][i]=empty;
																}




												}

										}

										
											


									}
					}		


				

				

			}
		
			}
			
			
			else if(!(to_x-from_x==1 && from_y==to_y)&& (to_y-from_y==1 && from_x==from_x)&&(to_y-from_y==-1 && from_x==from_x))
			{

				return -2;
			}
			else if(board[to_x][to_y]==white_man )	/*otomatik atlama işlemi*/
			{

				 
						while(board[to_x][to_y]==white_man &&  board[to_x+1][to_y]==empty&& to_x<8 &&to_y==from_y)
							{	
								
						
							
								board[to_x+1][to_y]=black_man;
								board[to_x-1][to_y]=empty;	/*ilk dikine gitme olayına bakıyor*/
								board[to_x][to_y]=empty;

								to_x=to_x+1;
								if(to_x==7)
								{
									board[to_x][to_y]=black_king;

								}

								
								
								while(board[to_x][to_y+1]==white_man &&board[to_x][to_y+2]==empty &&to_y<8)
									{	

										
												
											
											
											board[to_x][to_y+2]=black_man;	/*daha sonra sağa gitme olayına göre bakıyor*/
											board[to_x][to_y+1]=empty;
											board[to_x][to_y]=empty;
											to_y=to_y+2;


											
											
						        	 
							

										
										
						            }
						           

						         while(board[to_x][to_y-1]==white_man && board[to_x][to_y-2]==empty&& to_y>0)
						           {
						           	
						           		
						           			board[to_x][to_y-2]=black_man;
						           			board[to_x][to_y-1]=empty;		/*sola gitme durumuna bakıyor*/
						           			board[to_x][to_y]=empty;
						           			to_y=to_y-2;
						           		

						           	
						           			


						           }
						          to_x=to_x+1;/*tekrar dikine gitme olayına bakıyor*/
						
							}
				    
				
					while(board[to_x][to_y]==white_man &&board[to_x][to_y+1]==empty &&to_y<8)
							{
								
											board[to_x][to_y+1]=black_man;
											board[to_x][to_y]=empty;			/*sağa gitme olayına bakıyor*/
											board[to_x-1][to_y]=empty;
											to_y=to_y+1;
											
											while(board[to_x+1][to_y]==white_man &&  board[to_x+2][to_y]==empty&& to_x<8)
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
											while(board[to_x][to_y-1]==white_man && board[to_x][to_y-2]==empty&& to_y>-1)
											{
											board[to_x][to_y-2]=black_man;
						           			board[to_x][to_y-1]=empty;		/*daha sonra sola gitme olayına bakıyor*/
						           			board[to_x][to_y]=empty;
						           			to_y=to_y-2;
						           		

						           	
						           			
						           			}
						           	to_y=to_y+1;	/*tekrar sağa gitme durumuna bakmak için to_y 1 arttırıyor*/


							}
						while(board[to_x][to_y]==white_man && board[to_x][to_y-1]==empty && to_y>-1)
							{	

											board[to_x][to_y-1]=black_man;
						           			board[to_x][to_y+1]=empty;		/*sola gitme olayına bakıyor*/
						           			board[to_x][to_y]=empty;
						           			to_y=to_y-1;
						           			while(board[to_x+1][to_y]==white_man &&  board[to_x+2][to_y]==empty&& to_x<8)
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
						           			while(board[to_x][to_y+1]==white_man &&board[to_x][to_y+2]==empty &&to_y<8)
						           			{
						           				

													board[to_x][to_y+2]=black_man;
													board[to_x][to_y+1]=empty;	/*sağa gitme olayına bakıyor*/
													board[to_x][to_y]=empty;
														to_y=to_y+2;

											
											
						        	 				

											}

						           		
											to_y=to_y-1;/*Tekrar sola gitme olayına göre to_y 1 azalttıyoruz*/
								}
			}
			else if(board[from_x][from_y]==black_man  &&board[to_x][to_y]==empty && ((to_x-from_x==1 && from_y==to_y)||(to_y-from_y==1 && from_x==from_x) || (to_y-from_y==-1 && from_x==from_x)))
			{	
				
				board[to_x][to_y]=black_man;
				board[from_x][from_y]=empty;
				if(to_x==7)							/*atlama olayını yoksa direk yerine götürüyoruz*/
					{
					board[to_x][to_y]=black_king;

					}

				
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
	
	move(board, 0, 4, 0, 2,  white);
	display_board(board);
	
	check_end_of_game( board);
	
	move(board, 1, 6, 1, 7,  black);
	display_board(board);
	check_end_of_game( board);
	
	move(board, 0, 2, 4, 2,  white);
	display_board(board);
	check_end_of_game( board);
	
	move(board, 1, 1, 2, 1,  black);
	display_board(board);
	check_end_of_game( board);

	move(board, 0, 7, 4, 7,  white);
	display_board(board);
	check_end_of_game( board);
		
	move(board, 2, 1, 2, 2,  black);
	display_board(board);
	check_end_of_game( board);
	
	move(board, 4, 2, 1, 6,  white);
	display_board(board);
	check_end_of_game( board);
	
	move(board, 1, 0, 1, 1,  black);
	display_board(board);
	check_end_of_game( board);
	
	move(board, 1, 6, 1, 0,  white);
	display_board(board);
	check_end_of_game( board);
	
	move(board, 7, 4, 4, 4,  black);
	display_board(board);
	check_end_of_game( board);
	
	move(board, 4, 7, 4, 1,  white);
	display_board(board);
	check_end_of_game( board);
	








}
void sample_game_2()	/*gif e göre senaryo oynattım*/
{
	int i ,j;
	

	piece board[8][8];

	
	for(i=0;i<=7;i++)
		{	
			for(j=0;j<=7;j++)
			{
			  board[i][j]=empty;

			}


		}
		board[1][2]=black_man;
		board[1][3]=black_man;
		board[1][4]=black_man;
		board[1][5]=black_man;
		board[2][1]=black_man;
		board[2][2]=black_man;
		board[2][3]=black_man;
		board[2][4]=black_man;
		board[2][6]=black_man;
		board[2][7]=black_man;
		board[3][0]=black_man;
		board[3][1]=black_man;
		board[3][2]=black_man;
		board[3][5]=black_man;
		board[3][7]=black_man;
		board[4][5]=black_man;
		board[4][2]=white_man;
		board[4][3]=white_man;
		board[4][4]=white_man;
		board[4][6]=white_man;
		board[4][7]=white_man;
		board[5][0]=white_man;
		board[5][1]=white_man;
		board[5][2]=white_man;
		board[5][3]=white_man;
		board[5][4]=white_man;
		board[5][6]=white_man;
		board[5][7]=white_man;
		board[6][2]=white_man;
		board[6][3]=white_man;
		board[6][4]=white_man;
		board[6][5]=white_man;
		display_board(board);

		move(board, 5, 1, 4, 1,  white);
		display_board(board);
		
		move(board, 3, 1, 4, 1,  black);
		display_board(board);

		move(board, 4, 3, 3, 3,  white);
		display_board(board);
		
		move(board, 4, 5, 4, 4,  black);
		display_board(board);
		
		move(board, 3, 3, 3, 2,  white);
		display_board(board);
		
		move(board, 1, 2, 1, 1,  black);
		display_board(board);
		
		move(board, 5, 3, 4, 3,  white);
		display_board(board);
		
		move(board, 5, 1, 5, 2,  black);

		move(board, 7, 3, 7, 5,  black);
		display_board(board);
		
		move(board, 4, 3, 3, 3,  white);
		display_board(board);

		move(board, 2, 3, 3, 3,  black);
		display_board(board);
		
		
		move(board, 7, 5, 4, 5,  black);
		display_board(board);
		move(board, 4, 6, 4, 5,  white);
		display_board(board);
		
		
		
		
		














}
		
		

	
	

