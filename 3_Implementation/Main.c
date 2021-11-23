#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

struct Person
{
     char name[20];
     long telno;
     char email[30];
     int age;
     char address[50];
     char gender[10];
};

void appendData();
void showAllData();
void findData();
void deleteData();
void displayMenu();

int main()
{
    system("cls");
    displayMenu();
    
    return 0;
}


void appendData()
{
      FILE *fp;
      struct Person obj;
      system("cls");
      fp=fopen("data.txt","a");
      
      printf("*Add Record\n");
      printf("Enter Name : ");
      scanf("%s",obj.name);
      printf("Enter Telephone No. : ");
      scanf("%ld",&obj.telno);
      printf("Enter Email id : ");
      scanf("%s",obj.email);
      printf("Enter Age : ");
      scanf("%d",&obj.age);
      printf("Enter Gender : ");
      scanf("%s",obj.gender);
      printf("Enter Address : ");
      scanf("%s",obj.address);
      
      fprintf(fp,"%20s %7ld %20s %7d %20s %20s",obj.name,obj.telno,obj.email, obj.age, obj.gender,obj.address);
      fclose(fp);
}

void showAllData()
{
      FILE *fp;
      struct Person obj;
      system("cls");
      fp=fopen("data.txt","r");
      printf("Display All Records\\n");
      printf("\n\n\t\tName");
      printf("\t\tTelephone No.");
      printf("\t\tEmail id");
      printf("\t\tAge");
      printf("\t\tGender");
      printf("\t\tAddress");
      while(!feof(fp))
      {
            fscanf(fp,"%20s %7ld %20s %7d %20s %20s",obj.name,&obj.telno,obj.email, &obj.age, obj.gender,obj.address);
            printf("\t\t%s ",obj.name);
            printf("\t\t%ld ",obj.telno);
            printf("\t\t%s\n",obj.email);
            printf("\t\t%d ",obj.age);
            printf("\t\t%s\n",obj.gender);
            printf("\t\t%s\n",obj.address);
      }
      fclose(fp);
      getch();
}

void findData()
{
      FILE *fp;
      struct Person obj;
      char name[20];
      int totrec = 0;
      system("cls");
      fp=fopen("data.txt","r");
      printf("Display Specific Records\n");
      printf("\nEnter Name : ");
      scanf("%s",name);
      while(!feof(fp))
      { 
            fscanf(fp,"%20s %7ld %20s %7d %20s %20s",obj.name,&obj.telno,obj.email, &obj.age, obj.gender,obj.address);
            if(strcmp(obj.name,name) == 0)
            {
                printf("\n\nName         : %s",obj.name);
                printf("  \nTelephone No : %ld",obj.telno);
                printf("  \nEmail id     : %s",obj.email);
                printf("  \nAge          : %d",obj.age);
                printf("  \nGender       : %s",obj.gender);
                printf("  \nAddress      : %s",obj.address);
                totrec++;
            }
      }
      if(totrec==0)
      { 
           printf("\n\n\nNo Data Found");
      }
      else
      {  
           printf("\n\n===Total %d Record found===",totrec);
      }
      fclose(fp);
      getch();
}
void deleteData()
{
	  FILE *fp , *temp;
      struct Person obj;
      system("cls");
      fp = fopen("data.txt","r");
      temp = fopen("temp.txt","w");
      int totrec;
      char name[20];
      printf("Delete  Records\n");
      printf("\nEnter Name : ");
      scanf("%s",name);
      while(!feof(fp))
      { 
            fscanf(fp,"%20s %7ld %20s %7d %20s %20s",obj.name,&obj.telno,obj.email, &obj.age, obj.gender,obj.address);
            if(strcmp(obj.name,name) == 0)
            {
                 fwrite(&obj ,sizeof(obj),1,temp);
                 totrec=1;
            }
      }
      if(totrec==0)
      { 
           printf("\n\n\nNo Data Found");
      }
      fclose(fp);
      fclose(temp);
      remove("record.txt");
      rename("temp.txt","record.txt");
      getch();
}
void displayMenu()
{   
    mainMenu:
    system("cls");
    char choice;
    
    printf("*  TELEPHONE DIRECTORY  *\n\n");
    printf("1) Append new Record\n");
    printf("2) Find a Record\n");
    printf("3) Display all records\n");
    printf("4) Delete Records\n");
    printf("5) Exit\n");
    printf("Enter your choice : ");
    
    scanf("%c", &choice);

    switch(choice)
    {
         case '1' : //call append record
            appendData();
            goto mainMenu;
         case '2' : //call find record
            findData();
            goto mainMenu;
         case '3' : //Read all record
            showAllData();
            goto mainMenu;
         case '4' :
         	deleteData();
         	goto mainMenu;
         case '5':
            break;
         default:
            goto mainMenu;
    }
}
