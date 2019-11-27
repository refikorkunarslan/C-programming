/*
** hw4_lib.c:
**
** The source file implementing library functions.
**
** Author: Yakup Genc. (c) 2018
**
** Revision: 2018.03.27.08.19
** 
*/

#include "hw4_lib.h"
#include <stdio.h>
double integral(double f(double x), double xs, double xe, double delta)
{	/*integral alma fonksiyonu*/
     int i=0;
	double x,sum=0,array[1000];
	
	for(x=xe;x<=xs;x+=delta)/*rieman toplamı kuralı sayesinde integral almaişlemini gerçekleştirdik*/
	{

		array[i]=f(x);		/*fonksiyonun altına kalan dikdötgenleri alma işleminde tabını delta olcak şekilde böldük*/
		sum+=array[i]*delta;/*Dikdötgenin alanlarını hesaplayıp sum değerine ulaşıyoruz*/
		i++;
	}
	
	return sum;
}
double integral2(double f(double x, double y), double xs, double xe, double ys, double ye, double delta)
{
	int i ;
	double x,y,n=100;
	double m=0,sum=0;	/*Çok katlı integrallerde reinman toplamı yaparak sonuca ulaşıcaz*/
	
	
	for(y=ye+(delta/2.0);y<=ys;y=y+delta)	/*bunda tek katlı integraldeki gibi dikdirgenler değil karelere bölecez*/
		{									/*Daha sonra bu karelerin orta noklarını teker teker toplayacaz*/
			for(x=xe+(delta/2.0);x<=xs;x=x+delta)/*Karelerin orta nokları delta/2 oluyor ve diper karenin ortasına gelmek için delta arttırıyoruz*/
			{

				sum=f(x,y)*(1/(n*n));
				m=m+sum;


			}
		}
	return m;

}
int derivatives(double f(double a), double x, double eps, double * d1, double * d2)
{

*d1=(f(x+eps) -f(x-eps))/(2*eps);
*d2=(f(x+eps) -(2*f(x))+f(x-eps))/(eps*eps);		/*formülü c koduna çevirdik*/
if(eps==0)
     {
	   return -1;									/*eps 0 olduğunde x/0 olacağında -1 değerinin döndürdük*/

     }
}
int compare_derivatives(double f(double a), double d1(double b), double d2(double b), double x, double eps, double * e1, double *e2)
{
	double b , k1 ,k2 ,m ;

	m = derivatives(f,x,eps,&k1,&k2);
	*e1=d1(b)- k1;
	*e2=d2(b)- k2;
	if(*e1<0)
	{
		*e1=*e1 * -1;

	}
	if(*e2<0)
	{
		*e1=*e1 * -1;

	}
}
int find_roots(double f(double x), double * x1, double * x2, double * x3, double * x4)
{
double x;
	int count=0;
	for(x=-100;x<=100;x=x+0.5)		/*-100 ile 100 arasında 0.5 arttırarak 0 yapacak değerleri teker teker arrattım*/
	{
		if( f(x)==0)
		{
			count++;
			
			if(count==1)
			{
				*x1=x;	/*ilk kökü 0 a atadım*/

			}
			else if(count==2)
			{

				*x2=x;		/*count 2 oldupu zaman ilk kökü bulmuştur ikinci köke değer atadım*/

			}
			else if(count==3)
			{
				*x3=x;		/*yukarıdaki ilemleri yaptım*/
			}
			else
			{
				*x4=x;
				return 1;	/*buraya girdiyse 4 kök bulmuştur o yüzden return -1*/
				
			}

		}
	}
	if(count<4)
	{
		return 0;	/*kök sayısı 4 den küçükse return 0 */
	}
	
	printf("%d\n",count );

}







