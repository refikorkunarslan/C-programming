#include <stdio.h>
void menu();
int find_size_of_line(char line[]);
void reverse_line(char line[], int line_lenght);
void encrypt_open_msg();
void decrypt_secret_msg();

int main(){
	menu();	/*run program*/
	return 0;	
}
void menu(){
	char secim;
	do{
		printf("\n1. Encrypt\n2. Decrypt\n0. Exit");
		printf("\nPlease enter the option  : ");
		scanf(" %c",&secim);	/*I ask the value from user*/
		switch(secim){
				case '1':	/*if user take 1 value choose second option*/
					encrypt_open_msg();
					break;
				case '2':	/*if user take 2 value choose second option*/
					decrypt_secret_msg();
					break;
				case '0':	/*if user take 0 value loop and program become end*/
					printf("You log out\n");
					break;	
				default :	/*other cases*/
					printf("You entered the false value\n");
					break;
			}
	}while(secim != '0');/*if user take 0 value loop exist*/	
}

void encrypt_open_msg(){	/*this function for encrypt the mesage*/
	FILE * file;	/*file pointer for opening file and reading*/
	FILE* file1;	/*file pointer for opening file and writing*/
	int i = 0,x;
    char characters[1024];	/*characters in line*/
    int line_size;

	file = fopen("open_msg.txt","r");		/*I opened file for reading*/
	file1 = fopen("secret_msg.txt","w");	/*I opened file for writing*/
	printf("Please enter key : ");	
	scanf("%d",&x);		/*I take key from user*/
	while(fgets(characters,1024,file)!=NULL){	/*this loop read all of the line to end of the file*/
		line_size = find_size_of_line(characters);	/*I called this function calculate the size of line*/
		reverse_line(characters ,line_size);	/*I called this fucntion for reverse line*/
		for(i=0;i<=line_size+1;i++){
			if(characters[i]=='.'){		/*if character include '.' character in mesage instead of '*' character */
				characters[i]='*';
			}
			else if(characters[i]==' '){	/*if character include space character in mesage instead of '_' character */
				characters[i]='_';
			}
			else if(characters[i]-x<'a'){	/*if character's asci value smaller than character a find the new character*/
				characters[i]=characters[i]+26-x;
			}
			else				/*the truth case if character mines value include a to z calculate truth character*/	
				characters[i]=characters[i]-x;
		}		
		for(i=0;i<=line_size+1;i++){		/*I write mesage in file*/
			fprintf(file1,"%c",characters[i]);
		}
		fprintf(file1,"%c",'\n');		/*I write new line character in file*/
	}
	fclose(file);
	fclose(file1);
}

void decrypt_secret_msg(){	/*this function solve to secret mesage*/
	FILE * file;	/*file pointer for opening file and writing*/
	FILE* file1;	/*file pointer for opening file and reading*/
	int i = 0,x;
    char characters[1024];	/*characters in line*/
    int line_size;
    
	file = fopen("open_msg.txt","w");	/*I opened file for writing*/
	file1 = fopen("secret_msg.txt","r");	/*I opened file for reading*/
	printf("Please enter key");
	scanf("%d",&x);		
	while(fgets(characters,1024,file1)!=NULL){	/*this loop read all of the line to end of the file*/
		line_size = find_size_of_line(characters);	
		reverse_line(characters ,line_size);	/*I called this fucntion for reverse line*/
		for(i=0;i<=line_size+1;i++){
			if(characters[i]=='*'){
				characters[i]='.';
			}
			else if(characters[i]=='_'){
				characters[i]=' ';
			}
			else if(characters[i]+x>'z'){	/*if character's asci value bigger than character a find the new character*/
				characters[i]=characters[i]-26+x;
			}
			else					
				characters[i]=characters[i]+x;
		}		
		for(i=0;i<=line_size+1;i++){	/*I write mesage in file*/
			fprintf(file,"%c",characters[i]);
		}
		fprintf(file,"%c",'\n');		/*I write new line character in file*/
	}
	fclose(file);
	fclose(file1);
}

int find_size_of_line(char line[]){	/*I calculate the size of line*/
	int count = 0 ,i = 0;
	while(line[i] != '\0'){		/*this loops check all of the character */
		if (line[i] != '\n'){
			count+= 1;		/*calculate size of line*/
		}
		i+=1;
	}
	return count - 2;	/*return value size of line*/
}

void reverse_line(char line[], int line_lenght){	/*this function do reverse the line*/
	int i = 0 ,j = 0,t;
	char temp[1024];	/*this array for copy reverse the line */
	t=line_lenght+1;
	for(i=0;i<=(line_lenght+1);i++){	/*this loop copy the lastest character to first character*/
			temp[i]=line[t];
			t--;
	}
	for(i=0;i<=(line_lenght+1);i++){	/*this loop copy the reverse array (temp) to main array*/
			line[i]=temp[i];
	}	

}

