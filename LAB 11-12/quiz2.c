#include <stdio.h>

int main() {
	
	char name[10];
	char surname[10];
	int number ;
	
	FILE *student;
	if((student=fopen("student.dat","w"))==NULL)
		printf("Error");
	else{
		printf("name,surname and student number: \n");
		printf("enter EOF to finish\n");
		scanf("%s%s&d",name,surname,&number);
		
		while(!feof(stdin)){
			fprintf(student,"%s %s %d \n",name,surname,number);
			printf("? ");
			scanf("%s%s%d",name,surname,&number);
		}
		fclose(student);
	}	
	
	return 0;
}
