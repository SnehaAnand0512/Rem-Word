#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

void login();
int  menu();
void add();
void search();
void all();

void main()
{
	login();
	system("color 0a");//change the color of command prompt
    system("cls");//clear the screen
    menu();
}
void login()
{
	system("color 0a");
	int a=0,i=0,b=2;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";
    do
{
    printf("\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\  LOGIN FORM  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\  ");
    printf(" \n\n\t\t          ENTER USERNAME:-");
	scanf("%s", &uname); //username : sneha
	printf(" \n\n\t\t          ENTER PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13)
		 break;
	    else
		 printf("#");//password : 1998 will be replaced by #### for security
	    i++;
	}
	pword[i]='\0';
	i=0;
	if(strcmp(uname,"sneha")==0 && strcmp(pword,"1998")==0)// user id : sneha , password : 1998
	{
	printf("  \n\n\n\t\t          LOGIN IS SUCCESSFUL!\n\t\t          WELCOME TO Rem- WORD , your personal email -password reminder! ");
	printf("\n\n\n\t\t\t\tPress any key to continue...");
	getch();//holds the screen
	break;
	}
	else
	{
		printf("\n\n\t\t          SORRY !!!!  LOGIN IS UNSUCESSFUL");
		printf("\n\t\t           You have %d more trials left ",b--);
		printf("\n\t\t           Please ensure you give the valid id and password ");
		printf("\n\n\t\t           press any key to continue");
		a++;//count for login attempts
		getch();//holds the screen

	}
}	while(a<=2);

	if (a>2)// this loop will keep track of the number of login attempts
	{
		printf("\nSorry you have entered the wrong username and password for 3 times!!!");

		getch();
		exit(0);
		//login();
	}
		system("cls");


}

int menu()
{

    printf("\t\t\t\t*****REM-WORD : PASSWORD REMINDER*****\n");
    printf("\n\t\t[P.S: Be sure to use the type the correct details! OKAY???? ]");
    printf("\n\n\t\t\t --MENU--\t\t\n\n");
    printf("\t\t\t 1. Add website or link \n");
    printf("\t\t\t 2. Search website\n");
    printf("\t\t\t 3. View All website details\n");
    printf("\t\t\t 4. Exit\n");
    printf("Enter Your Choice:-");
    int option; // select the option 1 to 5
    scanf("%d",&option);
    switch(option)
    {
    case 1:
        add();
        break;
    case 2:
        search();
        break;
    case 3:
        all();
        break;
    case 4:
        exit(0);
    default:
        system("cls");
        printf("\n\t\t\tEnter 1 to 4 only \t\n");
        printf("\n\t\t\tEnter any key to return to the restart the process \t\n");
        printf("\n\t\t\t================================================== \t\n");
        printf("\n");
        getch();
    menu();
}
}

void add()
{
    FILE *fp;
    fp=fopen("website.txt","a+");
    system("cls");
    printf("\t*****ADD WEBSITE*****");
    printf("\n\t Website Name    :-");
    char name[20];
    scanf("\n%s",name);
    printf("\n\temail. :-" );
    char mail[20];
    scanf("\n%s",mail);
    printf("\n\tpassword:- ");
    char pw[20];
    scanf("\n%s",pw);
    fprintf(fp,"%s %s %s\n",name,mail,pw);
    fclose(fp);
    printf("\n\tPRESS ANY KEY TO CONTINUE");
    printf("\n\t\t\t================================================== \t\n");
    printf("\n");
    getch();
    system("cls");
    menu();
}
void search()
{
    FILE *fp;
    fp=fopen("website.txt","r");
    if(fp==NULL)
    {
    	printf("\nfile opening error in listing :");
	}
    system("cls");
    printf("\t\t\t*****SEARCH WESBITE*****");
    printf("\n\t\t Enter Website Name :-");
    char name[20];
    scanf("%s",name);
    char name1[20],mail[20],pw[20];
    int i=1;
    while(fscanf(fp,"%s %s %s",name1,mail,pw)!=EOF)
    {
        if(strcmp(name,name1)==0)
        {
            printf("\n\t\t================================================== \t\n");
			printf("\n\t\t DATA  %d",i++);
			printf("\n\t\t\tNAME     :- %s\n",name1);
            printf("\n\t\t\temail .  :- %s\n",mail);
            printf("\n\t\t\tpassword :- %s\n",pw);
            printf("\n\t\t================================================== \t\n");
        }
    }
    fclose(fp);
    printf("\n\t\t  PRESS ANY KEY TO CONTINUE");
    printf("\n\t\t================================================== \t\n");
    printf("\n");
    getch();
    system("cls");
    menu();
}

void all()
{
    FILE *fp;
    fp=fopen("website.txt","r");
    system("cls");
    printf("\t\t\t*****ALL WEBSITES*****");
    char name1[20],mail[20],pw[20];
    int i=1;
    while(fscanf(fp,"%s %s %s",name1,mail,pw)!=EOF)
    {
    	printf("\n\t\t DATA  %d",i++);
        printf("\n\t\t\t NAME    :-  %s",name1);
        printf("\n\t\t\tEmail . :-  %s",mail);
        printf("\n\t\t\tpassword :- %s",pw);
        printf("\n\t\t======================================");
    }
    fclose(fp);
    printf("\n\t\t\tPRESS ANY KEY TO CONTINUE");
    printf("\n\t\t================================================== \t\n");
    printf("\n");
    getch();
    system("cls");
    menu();
}
