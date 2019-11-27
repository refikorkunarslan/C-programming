/*
** hw4_io.c:
**
** The source file implementing input and output functions.
**
** Author: Yakup Genc. (c) 2018
**
** Revision: 2018.03.27.08.19
** 
*/


#include "hw4_io.h"
#include <stdio.h>
int read_polynomial3(double * a0, double * a1, double * a2, double * a3)
{
	scanf("%lf%lf%lf%lf" , &*a3, &*a2 , &*a1, &*a0);/*3.dereceden polinomun katsayılarını kullanıcan istedik*/

}
int read_polynomial4(double * a0, double * a1, double * a2, double * a3, double * a4)
{
	scanf("%lf%lf%lf%lf%lf" , &*a4, &*a3 , &*a2,&*a1 ,&*a0);/*4. dereceden polinomun katsayılarını kullanıcan istedik*/
}


void write_polynomial3(double a0, double a1, double a2, double a3)/*3.derecen polinomun istediğimiz katsayılarını polinom şeklinde yazma fonksiyonu*/
{
	read_polynomial3(&a3, &a2, &a1, &a0);

	if (a3 != 0)
	{
		printf("%.2fx^3",a3 );	/*3 dereceden x 0 değilse direk printf bastırıyoruz*/
	}
	if(a2>0)
	{
		printf("+%.2fx^2",a2);	/*Eğer a^2>0 dan ise printf de direk + ile basşadım*/
	}
	else if(a2<0)
	{
		printf("%.2fx^2" , a2);/*Eğer a^2> dan ise printf de direk - ile başlar*/
	}
	else 
	{
		printf(" ");	/*Eğer sayı 0 sa o değer yazılmaz*/
	}
	if(a1>0)
	{
		printf("+%.2fx^1",a1);
	}
	else if(a1<0)
	{
		printf("%.2fx^1" , a1);							/*yukarıdaki işlemlerin aynısı yapıldı*/
	}
	else 
	{
		printf(" ");
	}
	if(a0>0)
	{
		printf("+%.2f",a0);
	}
	else if(a2<0)
	{
		printf("%.2f" , a0);
	}
	else 
	{
		printf(" ");
	}
}
void write_polynomial4(double a0, double a1, double a2, double a3, double a4)/*4.derecen fonksiyonları polinom şeklinde yazma fonksiyonu*/
{
	read_polynomial4(&a4, &a3, &a2, &a1,&a0);

	if (a4 != 0)
	{
		printf("%.2fx^4",a4 );
	}
	if(a3>0)
	{
		printf("+%.2fx^3",a3);
	}
	else if(a3<0)
	{
		printf("-%.2fx^3" , a3);		/*Yukarıdaki fonksiyonların aynıları bu fonksiyonda da uygulandı*/
	}
	else 
	{
		printf(" ");
	}

	if(a2>0)
	{
		printf("+%.2fx^2",a2);
	}
	else if(a2<0)
	{
		printf("-%.2fx^2" , a2);
	}
	else 
	{
		printf(" ");
	}
	if(a1>0)
	{
		printf("+%.2fx^1",a1);
	}
	else if(a1<0)
	{
		printf("-%.2fx^1" , a1);
	}
	else 
	{
		printf(" ");
	}
	if(a0>0)
	{
		printf("+%.2f",a0);
	}
	else if(a2<0)
	{
		printf("-%.2f" , a0);
	}
	else 
	{
		printf(" ");
	}

}





