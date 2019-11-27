#include <stdio.h>
#include <math.h>
#define PI 3.14
double circle_area(double );
double calc_hypotenuse(int , int );
double calc_radius_of_smallest_circle(int , int );
double calc_radius_of_largest_circle( int , int );        /* Fonksiyonları tanımladım*/
double calc_area_of_smallest_circle( int,int);
double calc_area_of_largest_circle(int , int );
double calc_area_of_square ( int);
double calc_area_of_smallest_square(int , int );
double calc_area_of_largest_square(int , int );
void display_results(double ,double ,double ,double );


int main()
{
	
	double largest_circle, largest_square, smallest_circle,smallest_square;
display_results( largest_circle, largest_square, smallest_circle, smallest_square);/*sonucları bastırmak fonksiyon çağırdım*/
	
}
double circle_area(double radius) /*Daire alan hesaplama fonksiyonu*/
{
	double area;
	
	area=PI*pow(radius,2);  /* Dairenin alanı = PI * r*r   */
	return area;
}
double calc_hypotenuse(int side1, int side2) /*Dikdörtgen hipotenüs hesaplama*/
{
	double hypotenuse;
	
	hypotenuse=sqrt(pow(side1,2)+pow(side2,2));  /*Hipotenüs formülü */
	
	
	return hypotenuse;
}
double calc_radius_of_smallest_circle(int side1, int side2) /*Dikdörtgeni içine alan dairenin yarıcapını hesaplama fonksiyonu*/
{
	double smallest_circle_radius;
	smallest_circle_radius=calc_hypotenuse( side1, side2); /*Dikdötgenin köşegenini hesaplaması için üstteki fonksiyonu cağırdım*/
	smallest_circle_radius=smallest_circle_radius/2; /*Dikdörtgenin köşegeni dairenin çapı olacağıdan 2 ye bölerek yarıcapına ulaştım*/
	
	return smallest_circle_radius;
}
double calc_radius_of_largest_circle(int side1, int side2)/*Dikdötgenin içinde çizilebilecek en büyük dairenin yarıçapını bulan fonksiyon*/
{
	double largest_circle_radius; /*Dİkdötgenin içine  en büyük daire çizilebilmesi için dikdötgenin kısa kenarı dairenin çapı olmalı*/
	if(side1>side2)
	{
		largest_circle_radius=side2/2.0;  /*Yukardaki koşula göre eger side2 küçükse side2/2 işlemi ile dairenin yarıçapına ulaşırız*/ 
	}
	else if(side1<side2)
	{
		largest_circle_radius=side1/2.0;/*side1 daha kısaysa side1/2 işlemiyle sonuca ulaşırız*/
	}
	else
	{
		largest_circle_radius=side1/2.0;/*side1 ve side2 aynı uzunluktaysa yani kareyse side1=side2/2 işlemiyle yarıçaoa ulaşırız*/
	}
	
	return largest_circle_radius;
}
double calc_area_of_smallest_circle(int side1, int side2)/*Çizilebilecek en küçük daire alanı*/
{
	double smallest_circle_area;
	smallest_circle_area=calc_radius_of_smallest_circle( side1,  side2);/*üstte yazdığımız smallest daire yarı çap bulma fonksiyounu cagırırız*/
	smallest_circle_area=circle_area(smallest_circle_area);/*Bulduğumuz yarıçapı yine üstte tanımladıpımız dairenin alanı fonksiyonunu çağırarak sonuca ulaşırız*/
	return smallest_circle_area;
}
double calc_area_of_largest_circle(int side1, int side2)/*Çizilebilecek en büyük dairenin alanı*/
{
	double largest_circle_area;
	largest_circle_area=calc_radius_of_largest_circle( side1,  side2);/*largest daire yarı çapı  bulma fonksiyonun çağırırız*/
	
    largest_circle_area=circle_area(largest_circle_area);/*dairenin alanı bulma fonksiyonun çağırarak işlemin sonucuna ulaştık*/
    
 	return largest_circle_area;
}
double calc_area_of_square (int side) /*Karenin alanını bulma fonksiyonu */
{
	int area_of_square;
	area_of_square=pow(side,2); /* Karenin alanı formulu = side*side*/
	return area_of_square;

}
double calc_area_of_largest_square(int side1, int side2)/*Dİkdötgen içine çizilebilecek en büyük kare için dildötgenin kısa kenarını karenin bir kenarı olacak şekilde alırız*/
{
	int area_of_largest_square;
	if(side1<side2)
		{	
			area_of_largest_square=calc_area_of_square(side1);
		}
	else if(side1>side2)
		{	
			area_of_largest_square=calc_area_of_square(side2);

		}
	else
		{
			area_of_largest_square=calc_area_of_square(side1);
		}
		
	return area_of_largest_square;
}
double calc_area_of_smallest_square(int side1, int side2)/*dikdörgen içinde olacak şekilde en küçük kare çizmek için de karenin uzun kenarını karenin bir kenarı olacak şekilde alırız*/
{
	int area_of_smallest_square;
	if(side1<side2)
		{	
			area_of_smallest_square=calc_area_of_square(side2);
		}
	else if(side1>side2)
		{	
			area_of_smallest_square=calc_area_of_square(side1);

		}
	else
		{
			area_of_smallest_square=calc_area_of_square(side1);
		}
	return area_of_smallest_square;
}
void display_results(double largest_circle,double largest_square,double smallest_circle,double smallest_square)
{
int side1,side2;
	printf("Enter Side1 : \n");/*dikdörgenin 2 kenarını kullanıcıdan istedik*/
	scanf("%d" , &side1);
	printf("Enter Side2 : \n");
	scanf("%d" , &side2);
	

	smallest_circle=calc_area_of_smallest_circle( side1,  side2);
    largest_circle=calc_area_of_largest_circle( side1,  side2);		/*printleyeceğimiz fonksiyonları çağırdık*/
    smallest_square=calc_area_of_smallest_square( side1,  side2);
    largest_square=calc_area_of_largest_square( side1, side2);

printf("the area of the largest circle that fits inside a rectangle : %.2f\n" ,largest_circle);
printf("the area of the largest square that fits inside the rectangle : %.2f\n" , largest_square);	/*sonuçları ekrana bastırdık*/
printf("the area of the smallest circle that surrounds the same : %.2f\n" , smallest_circle);
printf("the area of the smallest square that surrounds the same rectangle : %.2f\n" ,smallest_square);



}