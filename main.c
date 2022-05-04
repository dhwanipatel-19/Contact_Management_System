 #include<stdio.h>
 #include <stdlib.h>
 #include<string.h>


 int main()
 {

     char fname[50], mname[50], sname[50], filename[50], update[50], phn[11];
     int choice;
     FILE *fptr, *cptr;
     char  ans,a='y', i;


     while(choice!=5)
     {

         printf("\n");
         printf("------------------------------------------------------\n");
         printf("CONTACT MANAGEMENT SYSTEM.\n");
         printf("------------------------------------------------------\n");
         printf("\n");
         printf("\nEnter 1 to create a contact: \n");
         printf("Enter 2 to update a contact: \n");
         printf("Enter 3 to delete a contact: \n");
         printf("Enter 4 to display a contact: \n");
         printf("Enter 5 to exit: \n");

         printf("Enter your choice: ");
         scanf("%d", &choice);

         switch(choice)
         {
             case 1:

                 printf("\nEnter first name: ");
                 scanf("%s", fname);
                  fptr=fopen(fname, "r");

                 if ((fptr = fopen(fname,"r")) == NULL)
                 {
                     fptr=fopen(fname, "w");
                 }
                 else
                 {
                     printf("\n");
                     printf("--------------------------------------------\n");
                     printf("The contact exist already.\n");
                     printf("--------------------------------------------\n");
                     printf("\n");
                     exit(1);
                 }

                 printf("Enter middle name: ");
                 scanf("%s", mname);
                 printf("Enter surname: ");
                 scanf("%s", sname);
                 printf("Enter phone number: ");
                 scanf("%s", phn);
                  while(strlen(phn)!=10)
                 {
                     printf("\n");
                     printf("--------------------------------------------\n");
                     printf("Enter valid phone number.\n");
                     printf("--------------------------------------------\n");
                     printf("\n");

                     printf("Enter phone number: ");
                     scanf("%s", phn);
                 }


                 fprintf(fptr,"First name :%s                  ", fname);
                 fprintf(fptr,"\nMiddle name :%s                        ", mname);
                 fprintf(fptr,"\nLast name : %s                ", sname);
                 fprintf(fptr,"\nPhone number :%s             ", phn);

                 printf("\n");
                 printf("--------------------------------------------\n");
                 printf("The contact is saved successfully.\n");
                 printf("--------------------------------------------\n");
                 printf("\n");
                 fclose(fptr);

                 printf("\n");
                 system("pause");

                 system("cls");

                 break;

             case 3 :

                 printf("\nEnter the name of contact to delete: ");
                 scanf("%s", filename);

                 printf("Are you sure you want to delete %s (Enter y to delete or enter any other alphabet to terminate.) :", filename);
                 scanf(" %c", &a );

                 if(a=='y')
                 {
                     if(remove(filename)==0)
                     {
                         printf("\n");
                         printf("--------------------------------------------\n");
                         printf("The contact is deleted successfully.\n");
                         printf("--------------------------------------------\n");
                         printf("\n");
                     }
                     else{
                         printf("\n");
                         printf("--------------------------------------------\n");
                         printf("The contact doesn't exist.\n");
                         printf("--------------------------------------------\n");
                         printf("\n");
                     }
                 }

                 else
                 {
                     printf("\n");
                     printf("--------------------------------------------\n");
                     printf("The contact is not deleted.\n");
                     printf("--------------------------------------------\n");
                     printf("\n");
                 }

                 printf("\n");
                 system("pause");
                 system("cls");

                 break;

             case 2:

                 printf("\nEnter the name of contact to be update: ");
                 scanf("%s",filename);


                 fptr=fopen(filename, "r");

                 if ((fptr = fopen(filename,"r")) == NULL){
                 printf("\n");
                 printf("--------------------------------------------\n");
                 printf("The file does not exist.\n");
                 printf("--------------------------------------------\n");
                 printf("\n");
                     exit(1);
                 }

                 printf("\n");
                 printf("--------------------------------------------\n");
                 printf("THE CONTACT'S OLD DETAILS\n");
                 printf("--------------------------------------------\n");
                 printf("\n");

                  i = fgetc(fptr);
                while (i != EOF)
                 {
                     printf ("%c", i);
                     i = fgetc(fptr);
                 }

                 printf("\n\nWhat type of information would you want to change? (first name, middle name, surname, phone number): ");
                 scanf(" %[^\t\n]s",&update);

                 if(strcmp(update,"first name")== 0)
                 {
                     printf("Enter the new first name: ");
                     scanf("%s",fname);

                     cptr= fopen(fname, "w");

                     while ((ans = fgetc(fptr)) != EOF)
                     {
                         fputc(ans, cptr);
                    }

                     fclose(fptr);

                     /*if( remove(filename)==0)
                     {
                         printf("The contact is updated successfully.");
                     }
                     else
                     {
                         printf("contact is not updated.");
                     }*/

                     fseek(cptr, 12, SEEK_SET);
                     fputs("                    ",cptr);
                     fseek(cptr, 12, SEEK_SET);
                     fputs(fname,cptr);

                     printf("\n");
                     printf("--------------------------------------------\n");
                     printf("The contact is updated successfully.\n");
                     printf("--------------------------------------------\n");
                     printf("\n");

                     fclose(cptr);
                 }

                 if (strcmp(update,"middle name")== 0)
                 {
                     fptr=fopen(filename, "r+");

                     if ((fptr = fopen(filename,"r+")) == NULL){
                         printf("Error! opening file");
                         exit(1);
                     }

                     printf("Enter the new middle name: ");
                     scanf("%s",mname);

                     fseek(fptr,51, SEEK_SET);
                     fputs("                    ",fptr);
                     fseek(fptr,51, SEEK_SET);
                     fputs(mname,fptr);

                     printf("\n");
                     printf("--------------------------------------------\n");
                     printf("The contact is updated successfully.\n");
                     printf("--------------------------------------------\n");
                     printf("\n");

                    fclose(fptr);
                 }

                 if (strcmp(update,"surname")== 0)
                 {
                     fptr=fopen(filename, "r+");

                     if ((fptr = fopen(filename,"r+")) == NULL){
                         printf("Error! opening file");
                         exit(1);
                     }

                     printf("Enter the new surname: ");
                     scanf("%s",sname);

                     fseek(fptr,89, SEEK_SET);
                     fputs("                    ",fptr);
                     fseek(fptr,89, SEEK_SET);
                     fputs(sname,fptr);

                     printf("\n");
                     printf("--------------------------------------------\n");
                     printf("The contact is updated successfully.\n");
                     printf("--------------------------------------------\n");
                     printf("\n");

                     fclose(fptr);
                 }

                 if (strcmp(update,"phone number:")== 0)
                 {
                     fptr=fopen(filename, "r+");

                     if ((fptr = fopen(filename,"r+")) == NULL){
                         printf("Error! opening file");
                         exit(1);
                 }

                 printf("Enter the new phone number: ");
                 scanf("%s",phn);

                 fseek(fptr,130, SEEK_SET);
                 fputs("                                    ",fptr);
                 fseek(fptr,130, SEEK_SET);
                 fputs(phn,fptr);

                 printf("\n");
                 printf("--------------------------------------------\n");
                 printf("The contact is updated successfully.\n");
                 printf("--------------------------------------------\n");
                 printf("\n");

                 fclose(fptr);
                 }

                 printf("\n");
                 system("pause");
                 system("cls");

                 break;

             case 4:

                 printf("\nEnter the name of the contact to display: ");
                 scanf("%s", filename);

                 fptr=fopen(filename,"r");

                 if ((fptr = fopen(filename,"r")) == NULL){
                         printf("Error! opening file");
                         exit(1);
                 }

                  i = fgetc(fptr);
                while (i != EOF)
                 {
                     printf ("%c", i);
                     i = fgetc(fptr);
                 }

                 fclose(fptr);

                 printf("\n");
                 system("pause");
                 system("cls");

             case 5 :
                 break;

             default:
                 printf("Invalid choice!");

     }
     }

    return 0;
}
