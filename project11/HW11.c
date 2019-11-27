#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct rooms{
	int number;
	int capacity;				/*odanın özelliklerini taşıyan değikenleri tanımladım ve linked list oluşturdum*/
	int floor;
	struct rooms *next;
}rooms;
typedef struct customers{
	int number;
	char *surname;				/*müşteri bilgileri içeren değişkenlerle tanımlı bir linked list daha oluşturdum*/
	char *name;
	char *gender;
	int age;
	struct customers *next;
}customers;

rooms * add_room_to_end(rooms *r,int a,int b,int c);/*oda numarsını,kapasitesini ve katını linked list ile bağlama fonksiyonu*/
rooms *add_room_after_room_number (rooms *r,int add_number,int add_capacity,int add_floor);/*yukarda bağladıpımız fonksiyona oda ekleme fonksiyonu*/
rooms *remove_room(rooms *r,int x);/*oda silme fonksiyonu*/
rooms * get_by_floor(rooms *r,int floor);/*sadece girilen kattadaki odalaro bastırma fonksiyonu*/
customers *add_customer_to_end(customers *r,int num,char cm_name[],char cm_surname[],int age,char cm_gender[]);/*müşteri bilgilerini linked list ile bağlma fonksiyonu*/

int main()
{
	
		rooms *root,*iter;
		customers *root2,*iterr;	
        root=(rooms * )malloc(sizeof(rooms));
	FILE *inp,*w;
	inp=fopen("rooms.txt","r");	
	
	iter=root;
	iterr=root2;
	
	
	w=fopen("customers.txt","r");
	int i=0,a,b,c,d,e,f,number,x;
	char name[20],surname[20],gender[20];

	int floor;

	root = NULL;
	root2=NULL;
	printf(" 1)Rooms List\n 2)Add Room\n 3)Costumer List\n 4)Remove Room\n 5)Get by Floor\n");
	int select;
	scanf("%d",&select);
		
	int age;
	customers *try;
	try = NULL;		/*yazdığımız fonksiyonları switch-case ile ulaşmayı sağladım*/
	switch(select){
		case 1:
								while(	fscanf(inp,"%d,%d,%d\n",&a,&b,&c)!=EOF)
										{	
											root=add_room_to_end(root,a,b,c);	
										}
								iter=root;										// burada ilk olarak linked list ile bağlanma fonksiyonun çağırarak 
																				// ekrana bütn odaları çağırdım.
								while(iter !=NULL )
										{	
											printf("%d,%d,%d\n",iter->number,iter->capacity,iter->floor );
											iter=iter->next;
										}
								iter=root;
									break;
		case 2:
								while(fscanf(inp,"%d,%d,%d\n",&a,&b,&c)!=EOF)
										{	
											root=add_room_to_end(root,a,b,c);			/*linked list ile bapladığımız odalara ek oda ekleyiroruz*/
										}												
		
								iter=root;

								root=add_room_after_room_number (root, d,e,f);
								while(iter !=NULL )
										{	
											printf("%d,%d,%d\n",iter->number,iter->capacity,iter->floor );
											iter=iter->next;
										}
								iter=root;
									break;
		case 3:

								while(fscanf(w,"%d,%s %[^,],%d,%[^\n]",&number,name,surname,&age,gender)!=EOF)
										{	
				//printf("%d,%s %s,%d,%s\n",number,isim,soyisim,ys,aaa );			
											try=add_customer_to_end(try,number,name,surname,age,gender);
										}
		
								customers *head = try;
								while(try->next !=NULL )													/*müşteri bilgilerini linked list ile bağlama*/
										{	
											printf("%d,%s %s,%d,%s\n",try->number,try->name,try->surname,try->age,try->gender);
											try=try->next;
										}
									break;
		case 4:

								while(	fscanf(inp,"%d,%d,%d\n",&a,&b,&c)!=EOF)
										{	
											root=add_room_to_end(root,a,b,c);
										}
								iter=root;
								while(iter !=NULL )
										{														/*verilen bir oda numarsını siler*/
											printf("%d,%d,%d\n",iter->number,iter->capacity,iter->floor );
											iter=iter->next;
										}
	
								root=remove_room(root,x);
								iter=root;
								while(iter !=NULL )
										{	
											printf("%d,%d,%d\n",iter->number,iter->capacity,iter->floor );
											iter=iter->next;
										}
								iter=root;
								break;
		case 5:
								
								while(	fscanf(inp,"%d,%d,%d\n",&a,&b,&c)!=EOF)
										{	
											root=add_room_to_end(root,a,b,c);
										}
		
								iter=root;
								root=get_by_floor(root,floor);				/*verilen kat da ki odaları ekrana bastırma*/
								while(iter !=NULL )
										{	
											if(floor==iter->floor)
													{ 
														printf("%d,%d,%d\n",iter->number,iter->capacity,iter->floor );
													}
											iter=iter->next;
										}
		
		
		
		
	


		

	}
	
		

	fclose(w);
	fclose(inp);
	free(root);
	free(root2);




}
rooms * add_room_to_end(rooms *r,int a,int b,int c)/*oda numarlarını,kapasittelerini,katları linked ile ile bağlama*/
{
	if(r==NULL)
        {
                r=(rooms*)malloc(sizeof(rooms));/*ilk başta node NULL ise bu fonksiyona girecek*/
                r->next=NULL;
                r->number=a;		/*atamaları yaptık*/
        		r->capacity=b;
        		r->floor=c;
                return r;	/*root değişeceğinden return r yaparak root değerini kaybolmasına izin vermedik*/
        }
    else if (r->next == NULL)/*eğer bir eleman varsa*/
    {
    	r->next=(rooms*)malloc(sizeof(rooms));/*r->next için bir bellekten node açtık*/
    	r->next->number = a;	/*r->next ine atamalar yapılacak*/
    	r->next->capacity =b;
    	r->next->floor=c;
    	r->next->next =NULL;
    	return r;
    }
    else
    	{	
    		rooms * iter=r;/*root değerini katbetmemek için iter üzerinden işlem yaptık*/
    		while(iter->next !=NULL)
    			{	
    				iter=iter->next;	/*linked list in sonuna gider*/

    			}

    		rooms * temp=(rooms *)malloc(sizeof(rooms));	
        	temp->next=iter->next;
        	iter->next=temp;
        	temp->number=a;
        	temp->capacity=b;
        	temp->floor=c;
        	temp->next=NULL;
        	

        	return r;


        }


}
rooms *add_room_after_room_number (rooms *r,int add_number,int add_capacity,int add_floor)/*oda ekleme*/
{	
	rooms *iter;
	printf("Add rooms number :\n");
	scanf("%d", &add_number);

	iter=r;
	while(iter->next !=NULL)		/*while ile linked listin sonuna kadar döndürme olayını gerçekleştirdik*/
		{ 
			if(iter->number == add_number)	/*eğer verilen da numarası listede varsa olan odanın sonrasını yeni biro da açar*/
				{
					printf("enter room capacity :\n");
					scanf("%d", &add_capacity);
				rooms *temp=malloc(sizeof(rooms));		
				temp->next=iter->next;
        		iter->next=temp;
        		temp->number=add_number;	/*atamaları yaptım*/
        		temp->capacity=add_capacity;
        		temp->floor=add_number/100;	/*katı dosayadan istemedim ilk baştaki sayı ne ile başlıyorsa kat orasıdır*/
        		return r;

					



				}
			iter=iter->next;
		}

					printf("enter room capacity :\n");
					scanf("%d", &add_capacity);
					add_floor=add_number/100;	/*eğer oda yoksa yukardaki if e girmeyecek ve lsitenin sonuna eklenecek*/
	
	r= add_room_to_end(r,add_number,add_capacity,add_floor);/*yukardaki fonksiyonu çağıtdırarak linked listin sonuna bağladım*/






}
rooms * remove_room(rooms *r,int x)/*oda silme fonksiyonu*/
{
 	printf("enter remove rooms number\n");
 	scanf("%d",&x);       
        rooms * iter;
        rooms *temp;
        iter=r;
        if(x==iter->number)				/*eğer listenin başındaki odayı silerse root değeri değişir*/
        {
                rooms *temp=(rooms*)malloc(sizeof(rooms));
                temp=r;			/*root değeri temp atanır*/					
                r=r->next;		/*yeni root artık r->next oalcak*/
                free(temp);			/*free leyerek o yeri boşaltırız*/
                return r;
                



        }

        while(iter->next !=NULL && iter->next->number != x)
        {

                iter=iter->next;				/*silinecek oda numarası bulunana kadar linked list üzerinde ilerlenecek*/
        }
        temp =(rooms*)malloc(sizeof(rooms));
        temp=iter->next;						/*iter->next bağı temp atanır*/
        iter->next=iter->next->next;			/*daha sonra iter next aradaki sileceğinden r->next->next olacak*/
        free(temp);							/*silinecek değer free leniyor*/
        return r;

}
rooms * get_by_floor(rooms *r,int floor)/*kullanıcın verdiği kat numarsında göre o kat numarsındaki odaları bastıran fonksiyon*/
{
	printf("Enter floor\n");
	scanf("%d",&floor);
	rooms *iter;
	iter=r;
	while(iter->next)/*linked listi üzerinde sırayla gidilir*/
		 {
		 	if(floor==iter->floor)/*verilen kat numarsında eşit olnlar kuşul içine girer*/
		 		{	
		 			printf("%d,%d,%d\n",iter->number,iter->capacity,iter->floor );/*ve ekrana basılır*/

		 		}
		 		iter=iter->next;

		 }
		 return r;




}
customers *add_customer_to_end(customers *r,int num,char cm_name[],char cm_surname[],int age,char cm_gender[])/*müşteri bilgilerini linked list ile bağlama*/
{
	if(r==NULL)			/*eğer ilk değer null ise*/
	{
				r=(customers*)malloc(sizeof(customers));/*bir node açarız*/
    			r->name=(char*)malloc(sizeof(char)*(strlen(cm_name)));	
    			r->surname=(char*)malloc(sizeof(char)*(strlen(cm_surname)));	/*daha sonra char pointer değişkenler için bellekte yer ayırırız*/	
    			r->gender=(char*)malloc(sizeof(char)*(strlen(cm_gender)));		/*strlen fonksiyonu sayesinde karekter sayısı buluruz*/	
                r->next=NULL;
              	r->number=num;			
            	r->age=age;
            	strcpy(r->gender,cm_gender);			/*atamaları yaptık*/
              	strcpy(r->name,cm_name);
              	strcpy(r->surname,cm_surname);
              	
                return r;

	}
	 else if (r->next == NULL)/*eğer sadece bir node varsa*/
    {
    	r->next=(customers*)malloc(sizeof(customers));
    	r->next->name=(char*)malloc(sizeof(char)*(strlen(cm_name)));
    	r->next->surname=(char*)malloc(sizeof(char)*strlen(cm_surname));
    	r->next->gender=(char*)malloc(sizeof(char)*(strlen(cm_gender)));		
    	r->next->number=num;
    	r->next->age=age;
    	strcpy(r->next->gender,cm_gender);
        strcpy(r->next->name,cm_name);
              	strcpy(r->next->surname,cm_surname);
    	r->next->next =NULL;
    	return r;
    }
    else
    	{	
    		customers * iter=r;
    		while(r->next !=NULL)
    			{	
    				r=r->next;

    			}

    		r->next=(customers *)malloc(sizeof(customers));
    		r->next->name=(char*)malloc(sizeof(char)*(strlen(cm_name)));
    		r->next->surname=(char*)malloc(sizeof(char)*(strlen(cm_surname)));
    		r->gender=(char*)malloc(sizeof(char)*(strlen(cm_gender)));
        	r->number=num;
        	r->age=age;
        	strcpy(r->gender,cm_gender);
       		strcpy(r->name,cm_name);
              	strcpy(r->surname,cm_surname);
        	r->next->next=NULL;
        	 // printf("%d\n",temp->number );

        	return iter;


        }





}
