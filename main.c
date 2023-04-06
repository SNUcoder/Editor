#include<stdio.h>
#include<string.h>

FILE *file;

int prompt();
void crfile();
void edit();
void read();

int main(){
	while (1){
		int in = prompt();
		if (in == 1){
			crfile();
		} else if (in == 2) {
			edit();
		} else if (in == 3) {
			read();
		}	else
		{
			printf("\033[1;31m");
			printf("Invalid operation\n");
			printf("\033[1;0m");
		}
		
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
	printf("******************** Ctrl+C to quit *********************\n");
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
	char fname[50];
	int i = 0;
	printf("\033[1;32m");
    printf("Enter the name of the file to read: ");
	printf("\033[1;36m");
	printf("\ninput>>> ");
	printf("\033[1;0m");
    scanf("%s", fname);

    file = fopen(fname, "r");
    if (file == NULL) {
		printf("\033[1;31m");
        printf("Unable to open file '%s'\n", fname);
		printf("\033[1;0m");
    }

    char line[100];
    while (fgets(line, sizeof(line), file)) {
		++i;
        printf("%d  %s", i, line);
    }

    fclose(file);
}
void edit(){
	char fname[31];
	char content[250];
	int i = 0;

	printf("\033[1;32m");
	printf("What file would you like to edit?\n");
	printf("\033[1;36m");
	printf("input>>> ");
	printf("\033[1;0m");

	scanf("%d", &fname);
	gets(fname);
	file = fopen(fname, "a");

	printf("******************** Edit ********************\n");
	
	while(1){
		printf("%d	", i++);
		fflush(stdin);
		fgets(content, 250, stdin);

		if(content[strlen(content)-1] == '\n'){
        	content[strlen(content)-1] = '\0';
		}
		
		if (strcmp(content,"$Quit") == 0 )
        	break;
      	else
      	{
        	fprintf(file, "%s\n", content);
      	}
    }

    fclose(file);
}
