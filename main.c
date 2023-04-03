#include<stdio.h>

FILE *file;

int prompt();
void crfile();
void edit();
void read();

int main(){
	int in = prompt();
	if (in == 1){
		crfile();
	} else if (in == 2) {
		edit();
	} else if (in == 3) {
		read();
	}
}

int prompt(){
	int in;
	printf("\033[1;32m");
	printf("********************WELCOME TO EDITOR********************\n");
	printf("**                                                     **\n");
	printf("**                  1) CREATE FILE                     **\n");
	printf("**                  2) EDIT FILE                       **\n");
	printf("**                  3) READ FILE                       **\n");
	printf("**                                                     **\n");
	printf("*********************************************************\n");
	printf("\033[1;36m");
	printf("input>>> ");
	printf("\033[1;0m");

	scanf("%d", &in);
	return in;
}

void crfile(){
	char fname[31];

	printf("\033[1;32m");
	printf("What would you like your file name to be?");
	printf("\033[1;36m\n");
	printf("input>>> ");
	printf("\033[1;0m");

	scanf("%d", &fname);
	gets(fname);
	file = fopen(fname, "w");

	fclose(file);
}

void read(){
	char fname[31];
	char content[200];

	printf("\033[1;32m");
	printf("What file would you like to read?\n");
	printf("\033[1;36m");
	printf("input>>> ");
	printf("\033[1;0m");
	scanf("%d", &content);
	gets(content);
	
	file = fopen(fname, "r");

	while(fgets(content, 200, file)){
		printf("%s", content);
	}
	fclose(file);
}
void edit(){

}
