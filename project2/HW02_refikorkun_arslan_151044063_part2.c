#include <stdio.h>
int main()
{
	int x,a,b,z,c,y,d,w,e;
	printf("Enter number \n");/*kullanıcan bir sayı istedik*/
	scanf("%d" , &x);
	while(x<=22 || x>=98761)
		{	
			printf("Enter number\n ");	/*Eğer bu sayı 23 ile 98760 arasında değilse tekrar bir sayı istedik*/
			scanf("%d" , &x);
		}
	a=x/10000;		/*Daha sonra girilen sayıyı 10000 e bölerek 10000 ler basamağındaki sayıya eriştik*/
	printf("The fifth digit is %d\n",a);/*bulduğumuz sayıyı direk bastırdık*/
	z=x-(a*10000);/*10000ler basamağındaki sayıyı 10000 ile çarparak girilen sayıdan çıkardık böylece sayı 1000 ler basamapına indi ve z ye atadık*/
	b=z/1000;/*1000 e bölerek binler basamağındaki değere ulaşyık*/
	printf("The fourth digit is %d\n",b);
	y=z-(b*1000);
	c=y/100;
	printf("The third digit is %d\n",c);		
	x=y-(c*100);							/*Ta ki birler basağına ulaşana kadar işlemleri tekrar ettirdik*/
	d=x/10;
	printf("The second digit is %d\n",d);
	w=x-(d*10);
	e=w;
	printf("The first digit is %d\n",e);
}