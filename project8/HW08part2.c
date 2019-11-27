#include <stdio.h>
#include <math.h>
char* find_operations(int arr[], int expected_val, char operations[], size_t arr_len, int cursor, int current);
int find_number(int num1,int num2,char operations);
int main()
{
	int arr_len=8;						/*İlk başta bir size belirledik*/
	int arr[]={8,7,25,4,17,3,9,11};		/*İşleme sokulacak sayıları array içinde initialize ettik*/
	char operations[arr_len-1];			/*operatör sayılardan 1 eksik olacağı için size ını 1 eksilttik*/ 
	int current=0;						
	int cursor=pow(3,arr_len-1);	/*current ı cursor a kadar artıracağımız için kaç ihtimal varsa 3 üzeri x gibi bir işlem uyguladık*/		
	int expected_val=29;
	find_operations( arr,  expected_val,  operations,  arr_len,  cursor,  current);
	printf("\n%s\n",operations);



}
int	find_number(int num1,int num2,char operations)/*find number buldupumuz operation ihtimallerini işleme dökdüğümüz fonksyon*/
{
	if(operations=='+')
	{
		return num1+num2;
	}
	else if(operations=='-')
	{
		return num1-num2;
	}
	else if(operations=='*')
	{
		return num1*num2;
	}



}
char* find_operations(int arr[], int expected_val, char operations[], size_t arr_len, int cursor, int current)/*ihtimalleri buldupumuz fonksiyon*/
{			
	char opr[3] = {'+','-','*'};/*kullanacağmız operationları biar arraye atadık*/
	int temp[arr_len-1];	/*temp diye bir array tanımladık*/
	int m=0;
	int i=0;
	
	temp[i]=arr[i];
	
	while(i<arr_len-1)	/*while içinde işlmeleri uyguladık*/
	{
	/*örneğin ilk başta(operation[0]) 3 tane işlem alabilir (+,- *) daha sonra operantion[1] 9 tane ihtimal vardır bu böyle 3 ün katı olarak gider*/
	/*Bu ihtimalleri array in size göre yaparız*/
		operations[i]=opr[((int)((current/pow(3,arr_len-(i+2)))))%3];/*current arttırılark bütün ihtimallere bakılır*/
		temp[i+1]=find_number(temp[i],arr[i+1],operations[i]);
	/*daha sonra buldupumuz ihtimalleri yukarda tanımladığımız fonksiyona göndeririz ve o fonksiyon operatör ne gönderdiysek onun sonucu bulur*/	
		i++;
		

	}




	if (temp[i] == expected_val)	/*Eğer bulduğumuz değer expected_val e eşitse operatörler döndürülür*/
	{
		printf("found number\n");
		return operations;
	}
	

	else if (cursor == current + 1)	/*Eğer bütün ihtimaller yapılıp değer bulunumazsa*/
	{
		i=0;
		printf("Not found\n");
		while(i<arr_len-1)
		{ 
		operations[i]=' ';	/*opetör bşluk gönderir*/
		}
		
		return operations;
	}
	

	return find_operations( arr,  expected_val,  operations,  arr_len,  cursor, current + 1);/*bu işlemi current arttırarak devam ettiririz*/

}
