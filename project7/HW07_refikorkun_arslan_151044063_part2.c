#include <stdio.h>


int main()
{
	FILE *inp ;
	FILE *outp;
	int day,year,month,fday,fmonth,fyear;
	int sum=0;
	char slash='/';
	inp=fopen("input_date.txt" , "w");/*input date dosyasını yazma modunda attık*/
	scanf("%d%d%d" ,&day,&month,&year);		/*ilk tarih*/	
	scanf("%d%d%d",&fday,&fmonth,&fyear);	/*son tarih*/


	fprintf(inp,"%d",day);
	fprintf(inp,"%c",slash);
	fprintf(inp,"%d",month);		/*girilen tarihini dosyaya yazık*/
	fprintf(inp,"%c",slash);
	fprintf(inp,"%d",year);
	
	int i=0,j,count=0;
	while(year<=fyear)			/*Yıl uyuna kadar döngü dönecek*/
	{ 	

		while(month<=7)			/*iLK 7 AY İÇİN DÖNDÜRECEK*/
		{
					
					if(month%2==0 &&month !=2)		/*2 ye bölünecek olanlar 30 gğn ıkuyor*/
						{
							for(j=day+1;j<=30;j++)
							{


								fprintf(inp,"%c",'\n');
								fprintf(inp,"%d",j);
								fprintf(inp,"%c",slash);
								fprintf(inp,"%d",month);	/*günleri bastıdık*/
								fprintf(inp,"%c",slash);
								fprintf(inp,"%d",year);
								count++;

								if(j==fday && month==fmonth && year==fyear)
								{

									
									month=20;	/*güne gelince durdurcak*/
									j=40;
								}
								
								
								



							}
							
						}
					else if(month==2)	/*Şubat ayına gelince istisnai bir durumdur*/
						{
							if( year%4==0 && year%100!=0 || year%400==0 )/*artık yıl bula olayı*/
								{	
									
										for(j=day+1;j<=29;j++)
											{					/*Eğer artık yıl var ise 29 gün oalcak*/


												fprintf(inp,"%c",'\n');
												fprintf(inp,"%d",j);
												fprintf(inp,"%c",slash);
												fprintf(inp,"%d",month);
												fprintf(inp,"%c",slash);
												fprintf(inp,"%d",year);
												count++;

												if(j==fday && month==fmonth && year==fyear)
													{

									
														month=20;
															j=40;
													}
												

											}
								}
							else
								{	
										for(j=day+1;j<=28;j++)
											{
																/*28 gün olacak*/

												fprintf(inp,"%c",'\n');
												fprintf(inp,"%d",j);
												fprintf(inp,"%c",slash);
												fprintf(inp,"%d",month);
												fprintf(inp,"%c",slash);
												fprintf(inp,"%d",year);
												count++;

												if(j==fday && month==fmonth && year==fyear)
													{

									
														month=20;
															j=40;
													}
												
								

											}
								

								}
						}
					else
						{	

							for(j=day+1;j<=31;j++)
											{


												fprintf(inp,"%c",'\n');
												fprintf(inp,"%d",j);
												fprintf(inp,"%c",slash);
												fprintf(inp,"%d",month);		/*Eğer 2 ye bölünmüyosa 31 günolacak*/
												fprintf(inp,"%c",slash);
												fprintf(inp,"%d",year);
												count++;

												if(j==fday && month==fmonth && year==fyear)
													{

									
														month=20;
															j=40;
													}

								

											}


						}

						
					
				
				
									
						month=month+1;
						day=0;
	
	
				}
		while(month>7 &&month<=12)	/*aylar 7 ve 12 arasında olunca işler değişiyor*/
		{
			
					if(month%2==0)	/*ay 2 ye bölünüce 31 gün çekecek*/
					{
									for(j=day+1;j<=31;j++)
											{


												fprintf(inp,"%c",'\n');
												fprintf(inp,"%d",j);
												fprintf(inp,"%c",slash);
												fprintf(inp,"%d",month);
												fprintf(inp,"%c",slash);
												fprintf(inp,"%d",year);
												count++;

												if(j==fday && month==fmonth && year==fyear)
													{

									
														month=20;
															j=40;
													}
								

											}




					}
					else
					{

						for(j=day+1;j<=30;j++)	/*d,ger koşulda 30 gün çekecek*/
											{


												fprintf(inp,"%c",'\n');
												fprintf(inp,"%d",j);
												fprintf(inp,"%c",slash);
												fprintf(inp,"%d",month);
												fprintf(inp,"%c",slash);
												fprintf(inp,"%d",year);
												count++;

												if(j==fday && month==fmonth && year==fyear)
													{

									
														month=20;
															j=40;
													}
								

											}

					}




					month+=1;
						day=0;




	}
	
	year=year+1;
	day=0;
	month=1;
	}

fclose(inp);
int w;
inp=fopen("input_date.txt" , "r");
outp=fopen("new_date.txt" , "w");









int k=0;
while(k<=count)	/*yukarda tuttuğumuz count kadar dönecek*/
{ 
	
	fscanf(inp,"%d%*c%d%*c%d" ,&day,&month,&year );
	
		if(month==1)	/*her ay için farklı formğl uygulanır ve buna göre gün belirlenir*/
			{	

				w=(day%7)+1+((year%100)%7)+(((year%100)/4)%7 );
				if(year>2000)
				{
					w=w-1;
				}
				else if(year==2000)
				{
					w=w-2;
					if(w<0)
					{
						w=w+7;
					}
				}
				else if(year<1900)
				{
					w=w+2;




				}
				if( year%4==0 && year%100!=0 || year%400==0 )
				{
					w=w-1;	/*artık yıl olursa 2 -1 olur*/

				}
				
				while(w>7)
				{
						w=w-7;

				}

				if(w==1)
				{
					fprintf(outp,"Sunday ,January %d,%d",day,year);

				}
				else if(w==2)
				{
					fprintf(outp,"Monday ,January %d,%d",day,year );
				}
				else if(w==3)
				{
					fprintf(outp,"Thuesday ,January %d,%d",day,year );
				}
				else if(w==4)
				{
					fprintf(outp,"Wednesday ,January %d,%d",day,year );
				}
				else if(w==5)
				{
					fprintf(outp,"Thursday ,January %d,%d",day,year );
				}
				else if(w==6)
				{
					fprintf(outp,"friday ,January %d,%d",day,year );
				}
				else if(w==7 ||w==0)
				{
					fprintf(outp,"Saturday ,January %d,%d",day,year );
				}

			}
			else if(month==2)
			{	
				w=(day%7)+4+((year%100)%7)+(((year%100)/4)%7 );
				if(year>2000)
				{
					w=w-1;
				}
				else if(year==2000)
				{
					w=w-2;
					if(w<0)
					{
						w=w+7;
					}
				}
				else if(year<1900)
				{
					w=w+2;




				}

				while(w>7)
				{
						w=w-7;

				}

				if(w==1)
				{
					fprintf(outp,"Sunday ,February %d,%d",day,year );

				}
				else if(w==2)
				{
					fprintf(outp,"Monday ,February %d,%d",day,year );
				}
				else if(w==3)
				{
					fprintf(outp,"Thuesday February %d,%d",day,year );
				}
				else if(w==4)
				{
					fprintf(outp,"Wednesday ,February %d,%d",day,year );
				}
				else if(w==5)
				{
					fprintf(outp,"Thursday ,February %d,%d",day,year );
				}
				else if(w==6)
				{
					fprintf(outp,"friday ,February %d,%d",day,year );
				}
				else if(w==7 || w==0)
				{
					fprintf(outp,"Saturday ,February %d,%d",day,year );
				}

			}
			else if(month==3)
			{	
				w=(day%7)+4+((year%100)%7)+(((year%100)/4)%7 );
				if(year>2000)
				{
					w=w-1;
				}
				else if(year==2000)
				{
					w=w-2;
					if(w<0)
					{
						w=w+7;
					}
				}
				else if(year<1900)
				{
					w=w+2;




				}
				while(w>7)
				{
						w=w-7;

				}

				if(w==1)
				{
					fprintf(outp,"Sunday ,March %d,%d",day,year );

				}
				else if(w==2)
				{
					fprintf(outp,"Monday ,March %d,%d",day,year );
				}
				else if(w==3)
				{
					fprintf(outp,"Thuesday March %d,%d",day,year );
				}
				else if(w==4)
				{
					fprintf(outp,"Wednesday ,March %d,%d",day,year );
				}
				else if(w==5)
				{
					fprintf(outp,"Thursday ,March %d,%d",day,year );
				}
				else if(w==6)
				{
					fprintf(outp,"friday ,March %d,%d",day,year );
				}
				else if(w==7 || w==0)
				{
					fprintf(outp,"Saturday ,March %d,%d",day,year );
				}

			}
			else if(month==4)
			{	
				w=(day%7)+7+((year%100)%7)+(((year%100)/4)%7 );
				if(year>2000)
				{
					w=w-1;
				}
				else if(year==2000)
				{
					w=w-2;
					if(w<0)
					{
						w=w+7;
					}
				}
				else if(year<1900)
				{
					w=w+2;




				}
				while(w>7)
				{
						w=w-7;

				}

				if(w==1)
				{
					fprintf(outp,"Sunday ,April %d,%d",day,year );

				}
				else if(w==2)
				{
					fprintf(outp,"Monday ,April %d,%d",day,year );
				}
				else if(w==3)
				{
					fprintf(outp,"Thuesday April %d,%d",day,year );
				}
				else if(w==4)
				{
					fprintf(outp,"Wednesday ,April %d,%d",day,year );
				}
				else if(w==5)
				{
					fprintf(outp,"Thursday ,April %d,%d",day,year );
				}
				else if(w==6)
				{
					fprintf(outp,"friday ,April %d,%d",day,year );
				}
				else if(w==7 || w==0)
				{
					fprintf(outp,"Saturday ,April %d,%d",day,year );
				}

			}
			else if(month==5)
			{	
				w=(day%7)+2+((year%100)%7)+(((year%100)/4)%7 );
				if(year>2000)
				{
					w=w-1;
				}
				else if(year==2000)
				{
					w=w-2;
					if(w<0)
					{
						w=w+7;
					}
				}
				else if(year<1900)
				{
					w=w+2;




				}
				
				
				while(w>7)
				{
						w=w-7;

				}

				if(w==1)
				{
					fprintf(outp,"Sunday ,May %d,%d",day,year );

				}
				else if(w==2)
				{
					fprintf(outp,"Monday ,May %d,%d",day,year );
				}
				else if(w==3)
				{
					fprintf(outp,"Thuesday May %d,%d",day,year );
				}
				else if(w==4)
				{
					fprintf(outp,"Wednesday ,May %d,%d",day,year );
				}
				else if(w==5)
				{
					fprintf(outp,"Thursday ,May %d,%d",day,year );
				}
				else if(w==6)
				{
					fprintf(outp,"friday ,May %d,%d",day,year );
				}
				else if(w==7 || w==0)
				{
					fprintf(outp,"Saturday ,May %d,%d",day,year );
				}

			}
			else if(month==6)
			{	
				w=(day%7)+5+((year%100)%7)+(((year%100)/4)%7 );
				if(year>2000)
				{
					w=w-1;
				}
				else if(year==2000)
				{
					w=w-2;
					if(w<0)
					{
						w=w+7;
					}
				}
				else if(year<1900)
				{
					w=w+2;




				}
				while(w>7)
				{
						w=w-7;

				}

				if(w==1)
				{
					fprintf(outp,"Sunday ,June %d,%d",day,year );

				}
				else if(w==2)
				{
					fprintf(outp,"Monday ,June %d,%d",day,year );
				}
				else if(w==3)
				{
					fprintf(outp,"Thuesday ,June %d,%d",day,year );
				}
				else if(w==4)
				{
					fprintf(outp,"Wednesday ,June %d,%d",day,year );
				}
				else if(w==5)
				{
					fprintf(outp,"Thursday ,June %d,%d",day,year );
				}
				else if(w==6)
				{
					fprintf(outp,"friday ,June %d,%d",day,year );
				}
				else if(w==7 || w==0)
				{
					fprintf(outp,"Saturday ,June %d,%d",day,year );
				}

			}
			else if(month==7)
			{	
				w=(day%7)+7+((year%100)%7)+(((year%100)/4)%7 );
				if(year>2000)
				{
					w=w-1;
				}
				else if(year==2000)
				{
					w=w-2;
					if(w<0)
					{
						w=w+7;
					}
				}
				else if(year<1900)
				{
					w=w+2;




				}
				while(w>7)
				{
						w=w-7;

				}

				if(w==1)
				{
					fprintf(outp,"Sunday ,July %d,%d",day,year );

				}
				else if(w==2)
				{
					fprintf(outp,"Monday ,July %d,%d",day,year );
				}
				else if(w==3)
				{
					fprintf(outp,"Thuesday ,July %d,%d",day,year );
				}
				else if(w==4)
				{
					fprintf(outp,"Wednesday ,July %d,%d",day,year );
				}
				else if(w==5)
				{
					fprintf(outp,"Thursday ,July %d,%d",day,year );
				}
				else if(w==6)
				{
					fprintf(outp,"friday ,July %d,%d",day,year );
				}
				else if(w==7 || w==0)
				{
					fprintf(outp,"Saturday ,July %d,%d",day,year );
				}

			}
			else if(month==8)
			{	
				w=(day%7)+3+((year%100)%7)+(((year%100)/4)%7 );
				if(year>2000)
				{
					w=w-1;
				}
				else if(year==2000)
				{
					w=w-2;
					if(w<0)
					{
						w=w+7;
					}
				}
				else if(year<1900)
				{
					w=w+2;




				}
				while(w>7)
				{
						w=w-7;

				}

				if(w==1)
				{
					fprintf(outp,"Sunday ,August %d,%d",day,year );

				}
				else if(w==2)
				{
					fprintf(outp,"Monday ,August %d,%d",day,year );
				}
				else if(w==3)
				{
					fprintf(outp,"Thuesday ,August %d,%d",day,year );
				}
				else if(w==4)
				{
					fprintf(outp,"Wednesday ,August %d,%d",day,year );
				}
				else if(w==5)
				{
					fprintf(outp,"Thursday ,August %d,%d",day,year );
				}
				else if(w==6)
				{
					fprintf(outp,"friday ,August %d,%d",day,year );
				}
				else if(w==7 || w==0)
				{
					fprintf(outp,"Saturday ,August %d,%d",day,year );
				}

			}
			else if(month==9)
			{	
				w=(day%7)+6+((year%100)%7)+(((year%100)/4)%7 );
				if(year>2000)
				{
					w=w-1;
				}
				else if(year==2000)
				{
					w=w-2;
					if(w<0)
					{
						w=w+7;
					}
				}
				else if(year<1900)
				{
					w=w+2;




				}
				while(w>7)
				{
						w=w-7;

				}

				if(w==1)
				{
					fprintf(outp,"Sunday ,September %d,%d",day,year );

				}
				else if(w==2)
				{
					fprintf(outp,"Monday ,September %d,%d",day,year );
				}
				else if(w==3)
				{
					fprintf(outp,"Thuesday ,September %d,%d",day,year );
				}
				else if(w==4)
				{
					fprintf(outp,"Wednesday ,September %d,%d",day,year );
				}
				else if(w==5)
				{
					fprintf(outp,"Thursday ,September %d,%d",day,year );
				}
				else if(w==6)
				{
					fprintf(outp,"friday ,September %d,%d",day,year );
				}
				else if(w==7 || w==0)
				{
					fprintf(outp,"Saturday ,September %d,%d",day,year );
				}

			}
			else if(month==10)
			{	
				w=(day%7)+1+((year%100)%7)+(((year%100)/4)%7 );
				if(year>2000)
				{
					w=w-1;
				}
				else if(year==2000)
				{
					w=w-2;
					if(w<0)
					{
						w=w+7;
					}
				}
				else if(year<1900)
				{
					w=w+2;




				}
				while(w>7)
				{
						w=w-7;

				}

				if(w==1)
				{
					fprintf(outp,"Sunday ,October %d,%d",day,year );

				}
				else if(w==2)
				{
					fprintf(outp,"Monday ,October %d,%d",day,year );
				}
				else if(w==3)
				{
					fprintf(outp,"Thuesday ,October %d,%d",day,year );
				}
				else if(w==4)
				{
					fprintf(outp,"Wednesday ,October %d,%d",day,year );
				}
				else if(w==5)
				{
					fprintf(outp,"Thursday ,October %d,%d",day,year );
				}
				else if(w==6)
				{
					fprintf(outp,"friday ,October %d,%d",day,year );
				}
				else if(w==7 || w==0)
				{
					fprintf(outp,"Saturday ,October %d,%d",day,year );
				}

			}
			else if(month==11)
			{	
				w=(day%7)+4+((year%100)%7)+(((year%100)/4)%7 );
				if(year>=2000)
				{
					w=w-1;
				}
				else if(year==2000)
				{
					w=w-2;
					if(w<0)
					{
						w=w+7;
					}
				}
				else if(year<1900)
				{
					w=w+2;




				}
				while(w>7)
				{
						w=w-7;

				}

				if(w==1)
				{
					fprintf(outp,"Sunday ,November %d,%d",day,year );

				}
				else if(w==2)
				{
					fprintf(outp,"Monday ,November %d,%d",day,year );
				}
				else if(w==3)
				{
					fprintf(outp,"Thuesday ,November %d,%d",day,year );
				}
				else if(w==4)
				{
					fprintf(outp,"Wednesday ,November %d,%d",day,year );
				}
				else if(w==5)
				{
					fprintf(outp,"Thursday ,November %d,%d",day,year );
				}
				else if(w==6)
				{
					fprintf(outp,"friday ,November %d,%d",day,year );
				}
				else if(w==7 || w==0)
				{
					fprintf(outp,"Saturday ,November %d,%d",day,year );
				}

			}
			else if(month==12)
			{	
				w=(day%7)+6+((year%100)%7)+(((year%100)/4)%7 );
				if(year>2000)
				{
					w=w-1;
				}
				else if(year==2000)
				{
					w=w-2;
					if(w<0)
					{
						w=w+7;
					}
				}
				else if(year<1900)
				{
					w=w+2;




				}
				while(w>7)
				{
						w=w-7;

				}

				if(w==1)
				{
					fprintf(outp,"Sunday ,December %d,%d",day,year );

				}
				else if(w==2)
				{
					fprintf(outp,"Monday ,December %d,%d",day,year );
				}
				else if(w==3)
				{
					fprintf(outp,"Thuesday ,December %d,%d",day,year );
				}
				else if(w==4)
				{
					fprintf(outp,"Wednesday ,December %d,%d",day,year );
				}
				else if(w==5)
				{
					fprintf(outp,"Thursday ,December %d,%d",day,year );
				}
				else if(w==6)
				{
					fprintf(outp,"friday ,December %d,%d",day,year );
				}
				else if(w==7 || w==0)
				{
					fprintf(outp,"Saturday ,December %d,%d",day,year );
				}

			}
			fprintf(outp,"%c",'\n');
			k=k+1;







}
fclose(inp);
fclose(outp);


}






