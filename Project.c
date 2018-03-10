#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

int MAX_COURSE = 500;
int MAX_NOTICE = 200;
int MAX_MSG = 200;


struct Department
{
  char Course[100];
  char Time[20];
  char Room[10];
  char Faculty[100];
};


struct Notice
{
  char date[100];
  char Title[100];
  char Not[10000];
};

struct Msg
{
    char date[100];
    char PersCode[100];
    char MSG[10000];
};


void FacMsg()
{
    system("CLS");
    struct Msg D[MAX_MSG];
    FILE *fptr;
    fptr=fopen("MSG.txt","a");
    int i;
    for (i = 0; i < MAX_MSG; i++)
        {
   printf("Enter the date: ");
   fflush(stdin);
   gets(D[i].date);
      if(strcmp(D[i].date,"")==0) break;
   fprintf(fptr,"%s\n", D[i].date);
   fflush(stdin);
   printf("Enter you personal code to verify your message to the head: ");
   gets(D[i].PersCode);
    fprintf(fptr,"%s\n", D[i].PersCode);
    fflush(stdin);
   printf("Enter your message: ");
   gets(D[i].MSG);
    fprintf(fptr,"%s\n", D[i].MSG);
    fprintf(fptr,"...........................\n");
}
    fclose(fptr);
    printf("\n\n\nAny key to return to your menu............");
    getch();
    FacTeacMenu();
}


void MsgRead()
{
    system("CLS");
        FILE *fptr;
        fptr=fopen("MSG.txt","r");
        char c;

        while((c=getc(fptr))!= EOF)
        printf("%c",c);

        fclose(fptr);


       printf("\nAny key to continue..............\n");
       getch();
       headOfDeptMenu();


}


void AddCourse ()
{
    system("CLS");
       struct Department D[MAX_COURSE];

       FILE *fptr;
       fptr = fopen("Test1.txt", "a");

int i;
for (i = 0; i < MAX_COURSE; i++)
{
   printf("Enter the course name-section: ");
   fflush(stdin);
   gets(D[i].Course);
      if(strcmp(D[i].Course,"")==0) break;
   fprintf(fptr,"%s\n", D[i].Course);
   fflush(stdin);
   printf("Assign the time: ");
   gets(D[i].Time);
    fprintf(fptr,"%s\n", D[i].Time);
   fflush(stdin);
   printf("Assign the room: ");
   gets(D[i].Room);
   fprintf(fptr,"%s\n", D[i].Room);
   fflush(stdin);
   printf("Assign the faculty: ");
   gets(D[i].Faculty);
    fprintf(fptr,"%s\n", D[i].Faculty);
   //NUM_COURSE++;
   //fprintf(fptr,"............................................");
   fprintf(fptr,"\n");
}
fclose(fptr);
printf("Any key to return to your menu...................");
getch();
headOfDeptMenu();
}


      void headShowDept ()
{
     system("CLS");
 struct Department D;

FILE *fptr;

int c;
fptr=fopen("Test1.txt","r");
printf("All the courses are listen below\n");
while(!feof(fptr)){
    fscanf(fptr,"%s\n%s\n%s\n%s\n\n",D.Course,D.Time,D.Room,D.Faculty);
    printf("\n\n.................................................");
     printf("\nCOURSE Name = %s\nTime = %s\nRoom no = %s\nFaculty = %s",D.Course,D.Time,D.Room,D.Faculty);
}

fclose(fptr);


    printf("\n\nAny key to continue...........");
    getch();
    headOfDeptMenu();

}


void StudShowDept ()
{
   system("CLS");
 struct Department D;

FILE *fptr;

int c;
fptr=fopen("Test1.txt","r");
printf("All the courses are listen below\n");
while(!feof(fptr)){
    fscanf(fptr,"%s\n%s\n%s\n%s\n\n",D.Course,D.Time,D.Room,D.Faculty);
    printf("\n\n.................................................");
     printf("\nCOURSE Name = %s\nTime = %s\nRoom no = %s\nFaculty = %s",D.Course,D.Time,D.Room,D.Faculty);
}

fclose(fptr);


    printf("\nAny key to continue...........");
    getch();
    Stud();

}

void FacShowDept ()
{

 system("CLS");
 struct Department D;

FILE *fptr;

int c;
fptr=fopen("Test1.txt","r");
printf("All the courses are listen below\n");
while(!feof(fptr)){
    fscanf(fptr,"%s\n%s\n%s\n%s\n\n",D.Course,D.Time,D.Room,D.Faculty);
    printf("\n\n.................................................");
     printf("\nCOURSE Name = %s\nTime = %s\nRoom no = %s\nFaculty = %s",D.Course,D.Time,D.Room,D.Faculty);
}

fclose(fptr);


    printf("\nAny key to continue...........");
    getch();
    FacTeacMenu();

}



void deleteCourse()
{
    system("CLS");
    FILE *f,*fptr;
    struct Department D;
    int flag=0;
    int cho;
    char course[50];
    printf("Enter the course name you want to delete: ");
    scanf("%s",&course);
    f=fopen("Test1.txt","r");
    fptr=fopen("Coursedelete.txt","w");
    while(!feof(f))
      {
      fscanf(f,"%s\n%s\n%s\n%s\n\n",D.Course,D.Time,D.Room,D.Faculty);
         if(strcmp(D.Course,course)!=0)
         fprintf(fptr,"%s\n%s\n%s\n%s\n\n",D.Course,D.Time,D.Room,D.Faculty);
        else if(strcmp(D.Course,course)==0)
            flag=1;
      }
fclose(f);
fclose(fptr);

       if(flag!=1)
            printf("No such course with such section\n\n");
       else{
        remove("Test1.txt");
        rename("Coursedelete.txt","Test1.txt");
        printf("Delete Complete\n\n");
       }




       printf("Press 1 to go to your menu\n");
       printf("Press 2 to go to main menu");
      scanf("%d",&cho);
      if(cho==1)
        headOfDeptMenu();
      else if(cho==2)
        main();
      else{
        printf("Invalid\n");
        getch();
        headOfDeptMenu();
      }
}



void HeadSearchCourse(){
    system("CLS");
      FILE *f;
      struct Department D;
      char course[20];
      char faculty[100];
      int c;

      printf("Press 1 to search via course\n");
      printf("Press 2 to search via faculty\n");
      printf("Press 3 to return to your menu\n");
      scanf("%d",&c);
      if(c==1){
      f=fopen("Test1.txt","r");

      printf("\nEnter Name: ");
      scanf("%s",&course);
      while(!feof(f))
      {
      fscanf(f,"%s\n%s\n%s\n%s\n\n\n",D.Course,D.Time,D.Room,D.Faculty);
         if(strcmp(D.Course,course)==0){
        printf("\nCourse name=%s\nTime=%s\nRoom=%s\nFaculty=%s\n",D.Course,D.Time,D.Room,D.Faculty);
     printf(".............................\n");

         }
      }
      }
      else if(c==2) {
            f=fopen("Test1.txt","r");

      printf("\nEnter the faculty name : ");
      scanf("%s",&faculty);
      while(!feof(f))
      {
      fscanf(f,"%s\n%s\n%s\n%s\n\n\n",D.Course,D.Time,D.Room,D.Faculty);
         if(strcmp(D.Faculty,faculty)==0){
        printf("\nCourse name=%s\nTime=%s\nRoom=%s\nFaculty=%s\n",D.Course,D.Time,D.Room,D.Faculty);
     printf("...............................\n");

         }
      }
      }
      else if(c==3){
        headOfDeptMenu();
      }
      else{
        printf("Invalid\n");
        printf("Any key to search again\n");
        getch();
        HeadSearchCourse(0);
      }


          fclose(f);
          printf("Any key to search again........\n");
          getch();
          HeadSearchCourse();
}



void StudSearchCourse()
{
    system("CLS");
      FILE *f;
      struct Department D;
      char course[20];
      int c;

      printf("Press 1 to search via course\n");
      printf("Press 2 to return to your menu\n");
      scanf("%d",&c);
      if(c==1){
      f=fopen("Test1.txt","r");

      printf("\nEnter Name: ");
      scanf("%s",&course);
      while(!feof(f))
      {
      fscanf(f,"%s\n%s\n%s\n%s\n\n\n",D.Course,D.Time,D.Room,D.Faculty);
         if(strcmp(D.Course,course)==0){
        printf("\nCourse name=%s\nTime=%s\nRoom=%s\nFaculty=%s\n",D.Course,D.Time,D.Room,D.Faculty);
     printf("............................\n");

         }
      }
      }

      else if(c==2)
        Stud();
      else{
        printf("Invalid\n");
        printf("Any key to search again\n");
        getch();
        StudSearchCourse(0);
      }
         fclose(f);
          printf("Press any key to continue.......... ");
     getch();
     Stud();
}

void FacSearchCourse()
{

    system("CLS");
      FILE *f;
      struct Department D;
      char course[20];
      int c;

      printf("Press 1 to search via course\n");
      printf("Press 2 to return to your menu\n");
      scanf("%d",&c);
      if(c==1){
      f=fopen("Test1.txt","r");

      printf("\nEnter Name: ");
      scanf("%s",&course);
      while(!feof(f))
      {
      fscanf(f,"%s\n%s\n%s\n%s\n\n\n",D.Course,D.Time,D.Room,D.Faculty);
         if(strcmp(D.Course,course)==0){
        printf("\nCourse name=%s\nTime=%s\nRoom=%s\nFaculty=%s\n",D.Course,D.Time,D.Room,D.Faculty);
     printf("............................\n");

         }
      }
      }

      else if(c==2)
        FacTeacMenu();
      else{
        printf("Invalid\n");
        printf("Any key to search again\n");
        getch();
        FacSearchCourse(0);
      }
         fclose(f);
          printf("Press any key to continue.......... ");
     getch();
     FacTeacMenu();
}


void HeadNotice()
{
    system("CLS");

    struct Notice D[MAX_NOTICE];
    FILE *fptr;
    fptr=fopen("Notice.txt","a");
    int i;
for (i = 0; i < MAX_NOTICE; i++)
{
   printf("Enter the Date: ");
   fflush(stdin);
   gets(D[i].date);
      if(strcmp(D[i].date,"")==0) break;
   fprintf(fptr,"%s\n",D[i].date);
   fflush(stdin);
   printf("Enter notice title: ");
   gets(D[i].Title);
   fprintf(fptr,"%s\n",D[i].Title);
   printf("Put your notice: ");
   gets(D[i].Not);
    fprintf(fptr,"%s\n",D[i].Not);
    fprintf(fptr,"\n");
}
    fclose(fptr);
    printf("Any key to continue\n");
    getch();
    headOfDeptMenu(0);
}

void HeadReadNotice()
{
    system("CLS");
    FILE *fp;
fp=fopen("Notice.txt", "r");
char c;

while((c=getc(fp))!= EOF)
printf("%c",c);

fclose(fp);

printf("Any key to continue\n");
getch();

    headOfDeptMenu(0);

}

void StudReadNotice()
{
    system("CLS");
    FILE *fp;
fp=fopen("Notice.txt", "r");
char c;

while((c=getc(fp))!= EOF)
printf("%c",c);

fclose(fp);


printf("Any key to continue\n");
getch();
Stud(0);
}

void FacReadNotice()
{
    system("CLS");
    FILE *fp;
fp=fopen("Notice.txt", "r");
char c;

while((c=getc(fp))!= EOF)
printf("%c",c);

fclose(fp);


printf("Any key to continue\n");
getch();
FacTeacMenu();
}



void headOfDept (int ChoiceOfHead)
{
     system("CLS");
    struct Department D;

    char id[100], pass[100];
      printf("\t\t\t                  LOGIN SESSION\n\n\n");
      printf("\t\t\t                  Enter your id      : ");
      fflush(stdin);
      gets(id);
      printf("\t\t\t                  Enter your password: ");
    gets(pass);

    if(strcmp(id,"Rezaul")==0 && strcmp(pass,"1234asdf")==0){
            system("CLS");

        printf("\t\t\t                   WELCOME\n");
        printf("\t\t\t               DR. Rezaul Bari\n\n");
        printf("\t\t\t    Press 1 for adding new course!!!!\n");
        printf("\t\t\t    Press 2 for displaying the recent course lists with details!!!\n");
        printf("\t\t\t    Press 3 for doing course related query!!!!\n");
        printf("\t\t\t    Press 4 for deleting course!!!!\n");
        printf("\t\t\t    Press 5 for updating notice!!!!\n");
        printf("\t\t\t    Press 6 for viewing notice!!!!\n");
        printf("\t\t\t    Press 7 for displaying messages from faculty teachers!!!!\n");
        printf("\t\t\t    Press 8 to logout!!!!\n");
        printf("\t\t\t    Choose what you intend to do: ");
        scanf("%d",&ChoiceOfHead);
        printf("\n\n\n");

 if(ChoiceOfHead==1){
            AddCourse();
        }

        else if(ChoiceOfHead==2){
            headShowDept();

}
        else  if(ChoiceOfHead==3){
            HeadSearchCourse();
        }
         else  if(ChoiceOfHead==4){
            deleteCourse();
        }
         else  if(ChoiceOfHead==5){
            HeadNotice();
        }
         else  if(ChoiceOfHead==6){
            HeadReadNotice();
        }
         else  if(ChoiceOfHead==7){
            MsgRead();
        }
        else  if(ChoiceOfHead==8){
            main();
        }


else{
    printf("Not valid");
    getch();
    headOfDeptMenu();
}
}
else{
    printf("Invalid admin ID or Password\nAny key to continue\n");
    getch();
    main();
}
}

void headOfDeptMenu(int ChoiceOfHead){
    system("CLS");
         printf("\t\t\t                   WELCOME\n");
        printf("\t\t\t               DR. Rezaul Bari\n\n");
        printf("\t\t\t    Press 1 for adding new course!!!!\n");
        printf("\t\t\t    Press 2 for displaying the recent course lists with details!!!\n");
        printf("\t\t\t    Press 3 for doing query!!!!\n");
        printf("\t\t\t    Press 4 for deleting course!!!!\n");
        printf("\t\t\t    Press 5 for updating notice!!!!\n");
        printf("\t\t\t    Press 6 for viewing notice!!!!\n");
        printf("\t\t\t    Press 7 for displaying messages from faculty teachers!!!!\n");
        printf("\t\t\t    Press 8 to logout!!!!\n");
        printf("\t\t\t    Choose what you intend to do: ");
        scanf("%d",&ChoiceOfHead);
        printf("\n\n\n");


       if(ChoiceOfHead==1){
            AddCourse();
        }

        else if(ChoiceOfHead==2){
            headShowDept();

}
        else  if(ChoiceOfHead==3){
            HeadSearchCourse();
        }
         else  if(ChoiceOfHead==4){
            deleteCourse();

        }
         else  if(ChoiceOfHead==5){
            HeadNotice();
        }
         else  if(ChoiceOfHead==6){
            HeadReadNotice();
        }

         else  if(ChoiceOfHead==7){
            MsgRead();
        }
        else  if(ChoiceOfHead==8){
            main();
        }


else{
    printf("Not valid");
    printf("Enter any key.............\n");
    getch();
    headOfDeptMenu(0);

}

}




void Stud(int ChoiceOfStud)
{

    system("CLS");
    struct Department D;
    printf("\t\t\t                               WELCOME\n\n\n");
    printf("\t\t\t              Here You Can Take A Look At Recent Course Details\n");
    printf("\t\t\t              Press 1 to take a look to recent courses: \n");
    printf("\t\t\t              Press 2 to search courses: \n");
    printf("\t\t\t              Press 3 to view notice: \n");
    printf("\t\t\t              Press 4 to return to menu: \n");
    fflush(stdin);
    scanf("%d",&ChoiceOfStud);
    if(ChoiceOfStud==1){
                    StudShowDept();

    }
    else if(ChoiceOfStud==2){
        StudSearchCourse();
    }
    else if(ChoiceOfStud==3){
        StudReadNotice();
    }
    else if(ChoiceOfStud==4){
        main();
    }
    else
        Stud(0);
}





void FacTeac(int ChoiceOfFac)
{

    system("CLS");
    char id[100], pass[100];
    printf("Enter the given universal faculty id: ");
   fflush(stdin);
    gets(id);
    printf("Enter the given universal faculty password: ");
    gets(pass);

    if(strcmp(id,"FacTeac123")==0 && strcmp(pass,"qwertyzxc")==0){
            system("CLS");
    struct Department D;
    printf("\t\t\t                              WELCOME\n");
    printf("\t\t\t           Here You Can Take A Look At Recent Course Details\n");
    printf("\t\t\t           Press 1 to take a look to recent courses: \n");
    printf("\t\t\t           Press 2 to search courses: \n");
    printf("\t\t\t           Press 3 to view notice: \n");
    printf("\t\t\t           Press 4 to send message to head of department\n");
    printf("\t\t\t           Press 5 to logout\n");
    fflush(stdin);
    scanf("%d",&ChoiceOfFac);
    if(ChoiceOfFac==1){
                    FacShowDept();
    }
    else if(ChoiceOfFac==2){
        FacSearchCourse();
    }
    else if(ChoiceOfFac==3){
        FacReadNotice();
    }
    else if(ChoiceOfFac==4){
        FacMsg();
    }
    else if(ChoiceOfFac==5){
        main();
    }
    else
        FacTeacMenu(0);
}

   else{
    printf("Invalid\n");
    printf("Any key to continue.........");
    getch();
    main();
   }
}

void FacTeacMenu(int ChoiceOfFac)
{

     system("CLS");
    struct Department D;
    printf("\t\t\t                              WELCOME\n\n\n");
    printf("\t\t\t             Here You Can Take A Look At Recent Course Details\n");
    printf("\t\t\t             Press 1 to take a look to recent courses: \n");
    printf("\t\t\t             Press 2 to search courses: \n");
    printf("\t\t\t             Press 3 to view notice: \n");
    printf("\t\t\t             Press 4 to send message to head of department\n");
    printf("\t\t\t             Press 5 to logout\n");
    fflush(stdin);
    scanf("%d",&ChoiceOfFac);
    if(ChoiceOfFac==1){
                    FacShowDept();
    }
    else if(ChoiceOfFac==2){
        FacSearchCourse();
    }
    else if(ChoiceOfFac==3){
        FacReadNotice();
    }
    else if(ChoiceOfFac==4){
        FacMsg();
    }
    else if(ChoiceOfFac==5){
        main();
    }
    else
        FacTeacMenu(0);
}



void main()
{
    system("CLS");
        struct Department D;
        printf("\t\t\t            NORTH SOUTH UNIVERSIY\n\n\n");
        printf("\t\t\t                    WELCOME\n ");
        printf("\t\t\t                      TO\n  ");
        printf("\t\t\t               DEPARTMENT OF ECE\n\n\n\n\n");

        printf("\t\t\t.................................................\n\n");
        printf("\t\t\t           LET US KNOW WHO YOU ARE?\n\n");
        printf("\t\t\t    CHOOSE 1 for SIGNIN as HEAD OF DEPARTMENT\n");
        printf("\t\t\t    CHOOSE 2 for SIGNIN as FACULTY TEACHERS\n");
        printf("\t\t\t        CHOOSE 3 for SIGNIN as STUDENTS\n");
        printf("\t\t\t              CHOOSE 4 to quit\n");
        printf("\t\t\t.................................................\n\n");
        printf("\t\t\t\t\t\t\t                                                Created By\n ");
        printf("\t\t\t\t\t\t\t                                              MD.IFTEKHAR_ALI\n ");
        printf("\t\t\t\t\t\t\t                                              ABDUL_WALID\n ");
        printf("\t\t\t\t\t\t\t                                              TANVIR_HAIDER\n ");
        printf("\t\t\t\t\t\t\t                                              FARHAN_UL_HAQUE\n\n\n ");

        printf("\t\t\t    Choose your option: \n");
        int FChoice;
        scanf("%d",&FChoice);
        switch(FChoice){
                           case 1 : headOfDept(FChoice);
                                    break;
                           case 2 : FacTeac(FChoice);
                                    break;
                           case 3 : Stud(FChoice);
                                    break;
                           case 4 : exit(0);
                       }


}

