#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef enum {left=0,right,up,down}jungle;/*yönler random atılacağı için enum yapısını kullandım*/
typedef struct{
	char **map;		/*two dimensional array olduğu için map double pointer ile tanımladık*/
	int width;
	int height;
	int flower_x;
	int flower_y;
}Forest;				
							/*struct içersinde variable ları tanımladık*/
typedef struct{
	int coord_x;
	int coord_y;
	int water_bootle_size;
}Botanist;
void init_game (Forest *forest, Botanist *botanist)/*iniliaze etme kısmı*/
{
	int i,j=1;
	FILE *fptr;
	fptr=fopen("init.csv","r");/*dosyayı çağırdık*/
	fscanf(fptr,"%d",&botanist->water_bootle_size);	/*dosyadaki iik satır bize su miktarını gösterecek ve bunları fscanf ile alaral bir variable a atadık*/
	fscanf(fptr,"%d,%d",&forest->width,&forest->height);/*bir sonraki satır ise arrayin boyutunu göstereck*/

	
		forest->map=(char **)calloc(forest->height,sizeof(int*)) ;	/*daha sonra map ten bir bellek hücresi ayırma işleminicalloc yoluyla gerçekleştiridik*/
		for(i=0;i<forest->width;++i)
		{
		forest->map[i]=(char *)calloc(forest->width,sizeof(int));	/*bellekten yer ayırdık*/
		
		}
	for(i=0;i<forest->width;i++)
	{
		for(j=0;j<forest->height+2;j++)
		{
			fscanf(fptr,"%c,",&forest->map[i][j]);	/*daha sonra geri kalan satırları karekter karekter okuyup arraye atadık*/
		}
	}

	for (i = 0; i < forest->width; ++i)
	{
		for(j=2;j<forest->height+2;j++)
		{
			forest->map[i][j-2] = forest->map[i][j];	/*map in indislerini kaydınığını gördük bunu düzeltemk için -2 işlemini yaptık*/
			if(forest->map[i][j]=='B')
			{
				
				botanist->coord_x=i;				/*başlangıç noktasını bulma*/
				botanist->coord_y=j - 2;
			}
			if(forest->map[i][j]=='F')
			{
				forest->flower_x=i;					/*bitiş noktasını bulma*/
				forest->flower_y=j - 2;
			}
		}
	}


		



fclose(fptr);
}
void print_map (Forest *forest)	/*Map i ekrana basma fonksiyonu*/
{
	int i,j;
	for(i=0;i<forest->width;i++)
	{
		for(j=0;j<forest->height;j++)
		{
			printf("%c",forest->map[i][j] );		
		}
		printf("\n");
	}




}
void search (Forest *forest, Botanist *botanist)/*flower ulaşma fonksiyonu*/
{
	int a;

	a=rand()%4;	/*random değer atadık*/
	
	
	if(botanist->coord_x==forest->flower_x && botanist->coord_y==forest->flower_y)
	{
		printf("I have found it on(%d,%d)!\n\n",botanist->coord_x,botanist->coord_y);/*Eğer flower ı bulursa ekrana basacak*/
		
	}

	else if(botanist->water_bootle_size==0)
	{ 
		printf("Help! I am on (%d,%d)\n\n",botanist->coord_x,botanist->coord_y);/*Eğer suyu bitirse ekrana basacak*/
		
	}
	else 
	{
			if(a==left)	/*enum*/
				{
					if(forest->map[botanist->coord_x][botanist->coord_y-1] !='#'&& botanist->coord_y-1 >=0 )/*Eper gideceği yer # varsa gitmeyecek ve*/
						{ 																					/*indis 0 dan küçük olursa gitmeyecek*/
							botanist->water_bootle_size=botanist->water_bootle_size-1;/*koşul içine girerse hareket edecek su miktarı bir azalacak*/
							forest->map[botanist->coord_x][botanist->coord_y]=' ';/*bulunduğu yeri boşluk yapacak*/
							botanist->coord_y=botanist->coord_y-1;			/*yeni koordinat işlemi*/
							forest->map[botanist->coord_x][botanist->coord_y]='B';/*yeni koordinata B basılır*/
							 printf("Searching...\n\n");
							 print_map (forest);
							search (forest,  botanist);
						}
					else
						{	
							search (forest,  botanist);			/*koşullara uymazsa function bir daha çapıralacak*/

						}
				}
				else if(a==right)
				{
					if(forest->map[botanist->coord_x][botanist->coord_y+1] !='#' && botanist->coord_y<=forest->width-2)/*Eper gideceği yer # varsa gitmeyecek ve*/
																										/*İndis 8 den büyük olmayacak*/
						{ 
							botanist->water_bootle_size=botanist->water_bootle_size-1;/*koşul içine girerse hareket edecek su miktarı bir azalacak*/
							forest->map[botanist->coord_x][botanist->coord_y]=' ';/*bulunduğu yeri boşluk yapacak*/
							botanist->coord_y=botanist->coord_y+1;				/*yeni koordinat işlemi*/
							forest->map[botanist->coord_x][botanist->coord_y]='B';/*yeni koordinata B basılır*/
							printf("Searching...\n\n");
							 print_map (forest);
							search (forest,  botanist);
						}

					else
						{	
							search (forest,  botanist);

						}

						
		
				}
				else if(a==up)
				{
					if(forest->map[botanist->coord_x-1][botanist->coord_y] !='#' && botanist->coord_x-1 >=0)/*Eper gideceği yer # varsa gitmeyecek ve*/
						{ 																					/*İndis 0 dan küçük olmayacak*/
							botanist->water_bootle_size=botanist->water_bootle_size-1;/*koşul içine girerse hareket edecek su miktarı bir azalacak*/
							forest->map[botanist->coord_x][botanist->coord_y]=' ';/*bulunduğu yeri boşluk yapacak*/
							botanist->coord_x=botanist->coord_x-1;				/*yeni koordinat işlemi*/
							forest->map[botanist->coord_x][botanist->coord_y]='B';/*yeni koordinata B basılır*/
							printf("Searching...\n\n");
							 print_map (forest);
							search (forest,  botanist);							
						}
					else
						{	
							search (forest,  botanist);

						}
				}
				else if(a==down)
				{
					if(forest->map[botanist->coord_x+1][botanist->coord_y] !='#' && botanist->coord_x+1 <=forest->height-2)/*Eper gideceği yer # varsa gitmeyecek ve*/
						{ 																					/*İndis 8 den büyük olmayacak*/
							botanist->water_bootle_size=botanist->water_bootle_size-1;/*koşul içine girerse hareket edecek su miktarı bir azalacak*/
							forest->map[botanist->coord_x][botanist->coord_y]=' ';/*bulunduğu yeri boşluk yapacak*/
							botanist->coord_x=botanist->coord_x+1;				/*yeni koordinat işlemi*/
							forest->map[botanist->coord_x][botanist->coord_y]='B';/*yeni koordinata B basılır*/
							printf("Searching...\n\n");
							 print_map (forest);
							search (forest,  botanist);
						}
					else
						{	
							search (forest,  botanist);

						}
				}
	
	
	}









}
int main()
{
	srand(time(NULL));
Forest forest;
Botanist botanist;

init_game (&forest,  &botanist);

search (&forest, &botanist);

}