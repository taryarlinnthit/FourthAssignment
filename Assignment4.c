//4th assignment
//Created by Taryarlinnthit on 9/14/2022
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 300
void InsertFun();
void ReadFun();
void updateFun();
int main() {
    FILE *fptr;
    int choice, case1, case2, case3 = 0;

    printf("----------------------------------------------\n");
    printf("          Welcome! \n");
    printf("Press 1 to insert data \n");
    printf("Press 2 to find data \n");
    printf("Press 3 to update data \n");
    printf("Enter your choice:");
    scanf("%d", &choice);

    switch (choice) {
        case (1):
            InsertFun();
            printf("Do you want to insert data again? \n");
            printf("press 1 to insert more,0 to exit \n");
            printf("Enter your choice:");
            scanf("%d", &case1);
            while (case1 == 1) {
                InsertFun();
                printf("press 1 to insert more,0 to exit \n");
                printf("Enter your choice:");
                scanf("%d", &case1);
            }
            break;

        case (2):

            printf("id   Name     Password     amount     age   location \n");
            ReadFun();
            printf("Enter 1 to add more or 0 to exit\n");
            printf("Enter your choice:");
            scanf("%d", &case2);
            while (case2 == 1) {
                printf("Enter 1 to add more or 0 to exit \n");
                printf("Enter your choice:");
                scanf("%d", &case2);
                InsertFun();
            }
            break;

        case (3):

            updateFun();
            printf("Do you want to insert data again? \n");
            printf("press 1 to insert more,0 to exit \n");
            printf("Enter your choice:");
            scanf("%d", &case3);
            while (case3 == 1) {
                InsertFun();
                printf("press 1 to insert more,0 to exit \n");
                printf("Enter your choice:");
                scanf("%d", &case3);

                break;

                default:
                    printf("Error!Please enter 1, 2 or 3!!");
                break;
            }

            return 0;
    }
}
void InsertFun(){

    FILE*fptr;
    int id,amount,age = 0;
    char userName[30];
    char password[30];
    char location[30];
    fptr = fopen("assignment4.txt","a" );

    if(fptr == NULL){
        printf("Error");
        exit(0);
    }
    printf("Please enter id: ");
    scanf("%d",&id);
    printf("\nPlease enter username: ");
    scanf("%s",userName);
    printf("\nPlease enter password: ");
    scanf("%s",password);
    printf("\nPlease enter amount: ");
    scanf("%d",&amount);
    printf("\nPlease enter age: ");
    scanf("%d",&age);
    printf("\nPlease enter location: ");
    scanf("%s",location);

    fprintf(fptr,"%d",id);
    fprintf(fptr,"%10s",userName);
    fprintf(fptr,"%10s",password);
    fprintf(fptr,"%10d",amount);
    fprintf(fptr,"%10d",age);
    fprintf(fptr,"%10s",location);
    fprintf(fptr,"\n");

    fclose(fptr);
}
void ReadFun(){
    FILE *fptr;
    char c;
    fptr = fopen("assignment4.txt","r");
    if(fptr == NULL) {
        printf("The file cannot be opened!");
        exit(1);
    }
        while (1) {
            c = getc(fptr);
            if (c == EOF) {
                break;
            } else {
                printf("%c", c);
            }
        }
        printf("\n");

        fclose(fptr);
    }

void updateFun(){

    int lno, ctr = 0;
    char ch;
    FILE *fptr1, *fptr2;
    char str[MAX], temp[] = "temp.txt";
    char fname[MAX] = "assignment4.txt";
    printf("id   Name     Password     amount     age   location \n");
    ReadFun();
    printf("\n\n Delete a specific line from the file :\n");
    printf("-----------------------------------------\n");
    fptr1 = fopen("assignment4.txt", "r");
    if (!fptr1)
    {
        printf(" File not found or unable to open the input file!!\n");
        exit(0);
    }
    fptr2 = fopen(temp, "w");
    if (!fptr2)
    {
        printf("Unable to open a temporary file!! \n");
        fclose(fptr1);
        exit(0);
    }
    printf(" Input the line number you want to remove : ");
    scanf("%d", &lno);
    lno++;

    while (!feof(fptr1))
    {
        strcpy(str, "\0");
        fgets(str, MAX, fptr1);
        if (!feof(fptr1))
        {
            ctr++;

            if (ctr != lno)
            {
                fprintf(fptr2, "%s", str);
            }
        }
    }
    fclose(fptr1);
    fclose(fptr2);
    remove(fname);
    rename(temp, fname);

    fptr1=fopen(fname,"r");
    ch=fgetc(fptr1);
    printf(" Now the content of the file %s is : \n",fname);
    while(ch!=EOF)
    {
        printf("%c",ch);
        ch=fgetc(fptr1);
    }
    fclose(fptr1);

}
