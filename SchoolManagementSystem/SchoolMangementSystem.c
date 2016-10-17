#include<stdio.h>
#include<string.h>

FILE *fp,*fb;
void add();
void view();
void edit();
void del();

struct student
    {
    char name[50],adress[50],course[30],teacher[30];
    int dob;
    int enrollnum;
    }stud[2],stud1;

void main()
{
   int ch;
       char pass;
    system("cls");
    printf("\t\t++++++++Enter the password++++++++");
    scanf("%c",&pass);
    if(pass=='\n'||pass=='\r')
    {
   printf("\n\n\t***********************************\n");
    printf("\t\t*School Admission*\t");
    printf("\n\t***********************************");

                printf("\n\n\t\tMAIN MENU:");

                printf("\n\n\tADD RECORD\t 1)");

                printf("\n\tVIEW RECORD\t 2)");

                printf("\n\tEDIT RECORD\t 3)");

                printf("\n\tDELETE RECORD\t 4)");

                printf("\n\n\tENTER YOUR CHOICE:");

                scanf("%d",&ch);


            switch(ch)
            {
                case 1:

                            add();
                            break;
                case 2:

                            view();
                            break;
                  case 3:

                            edit();
                            break;
                case 4:

                            del();
                            break;

                default: printf("\n INVALID CHOICE");
                                    break;
            }
    }
    else
    {
        printf("Try again:::");
        main();
    }
}

void add()
{

    int i,choice,n;//,n=2;
    char c;
system("cls");
				printf("\n\n****Welcome to Student Details****\n");

				fp = fopen("student.txt","a+");

				if(fp==NULL)

					{
						printf("File not Found");
					}
                printf("\n\tEnter Number of Record to store: ");
				scanf("%d",&n);
				for(i=0;i<n;i++)

					{
                        printf("\n\tRecord Number:\t\t%d\n",i+1);

						printf("\n Enter Enrollment Number\t:");
						scanf("%d",&stud[i].enrollnum);

						printf("\n Enter Name of Student\t\t:");
						fflush(stdin);
						gets(stud[i].name);

						printf("\n Address\t\t\t:");
						fflush(stdin);
						gets(stud[i].adress);

						printf("\n Enter Date Of Birth\t\t:");
						fflush(stdin);
						scanf("\n %d",&stud[i].dob);

						printf("\n Enter course\t\t\t:");
						fflush(stdin);
						gets(stud[i].course);

						printf("\n Enter Teacher  name\t\t:");
						fflush(stdin);
						gets(stud[i].teacher);

						fprintf(fp,"%d \n %s \n %s \n %d \n %s \n %s \n",stud[i].enrollnum,stud[i].name,stud[i].adress,stud[i].dob,stud[i].course,stud[i].teacher);
						fflush(stdin);
					}

            fclose(fp);
            printf("\n ************************************************");
            printf("\n   Record Entered Successfully        ");
            printf("\n ************************************************");
            fclose(fp);
            printf("\n ADD ANOTHER RECORD Yes(y) NO(any key)");
            scanf("%c",&c);
    if(c=='y'||c=='Y')
    {
        add();
    }
    else
    {
        main();
    }

}


void view()
{

    int found=0,a;
    char search[20],c;
system("cls");
printf("\n\n\t****Welcome to view details of students****\n");
    printf("\n How you Want To Search Record BY:--");
                    printf("\n Enter your Choice:");
                    printf("\n By Student Name");
                    printf("\n By Subject Teacher Name\n");
                    scanf("%d",&a);
                    switch(a)
                    {
                case 1:

                        fp=fopen("student.txt","r");

				if(fp==NULL)
					{
						printf("File Not Found");
					}

				printf("\nEnter  Name of Student: ");
				scanf("%s",search);



				while(1)
					{

                        fscanf(fp,"%d  %s  %s  %d  %s  %s  ",&stud1.enrollnum,stud1.name,stud1.adress,&stud1.dob,stud1.course,stud1.teacher);

						if(strcmp(stud1.name,search)==0)
							{
								printf("\n\tStudent Details:-\n");

								printf("\nEnrollment Number\t:%d\n",stud1.enrollnum);
								printf("\nName of student\t\t:%s\n",stud1.name);
								printf("\nAddress\t\t\t:%s\n",stud1.adress);
								printf("\nDate Of Birth\t\t:%d\n",stud1.dob);
								printf("\n Course\t\t\t:%s\n",stud1.course);
								printf("\n Teacher\t\t\t:%s\n",stud1.teacher);
								break;
							}
					}

						break;
                case 2:

                            fp=fopen("student.txt","r");

				if(fp==NULL)
					{
						printf("File Not Found");
					}

				printf("\nEnter  Name of Subject teacher: ");
				scanf("%s",search);
			while(1)
					{

                        fscanf(fp,"%d  %s  %s  %d  %s  %s  ",&stud1.enrollnum,stud1.name,stud1.adress,&stud1.dob,stud1.course,stud1.teacher);

						if(strcmp(stud1.teacher,search)==0)
							{

                                printf("\n\tStudent Details:-\n");

								printf("\nEnrollment Number\t:%d\n",stud1.enrollnum);
								printf("\nName of student\t\t:%s\n",stud1.name);
								printf("\nAddress\t\t\t:%s\n",stud1.adress);
								printf("\nDate Of Birth\t\t:%d\n",stud1.dob);
								printf("\n Course\t\t\t:%s\n",stud1.course);
								printf("\n Teacher\t\t\t:%s\n",stud1.teacher);
								break;
							}

                            }


						if(found==0)
    {


						printf("\nFile Not Found\n");
    }
						fclose(fp);
						break;
                default: printf("\n RECORD NOT FOUND\n");

}
}

void edit()
{
    int choice,test=0;
    FILE *fp,*fb;
    int a,sdob;
    char s1name[20],c;
    char sname[20],sadd[20],steach[20];
    system("cls");
    printf("\n\n\t****Welcome to edit details of students****\n");
    fp=fopen("student.txt","r");
    fb=fopen("new.txt","w");

    printf("\n Enter the Name of Student for editing:-");
    scanf("%s",sname);
    while(fscanf(fp,"%d  %s  %s  %d  %s  %s  ",&stud1.enrollnum,stud1.name,stud1.adress,&stud1.dob,stud1.course,stud1.teacher)!=EOF)
    {
        if(strcmp(stud1.name,sname)==0)
        {
            test=1;
            printf("\n Which information do you want to change?\n1.Name\n2.Address\n3.Teacher\n4.DOB");
             scanf("%d",&choice);
            system("cls");
            if(choice==1)
                    {
                        printf("Enter the new name:");
                        scanf("%s",s1name);
                        fprintf(fb,"\n %d \t %s \t %s \t %d \n %s \n %s \n ",stud1.enrollnum,s1name,stud1.adress,stud1.dob,stud1.course,stud1.teacher);
                        fflush(stdin);
                        printf("Changes saved!");
                }
            else if(choice==2)
                {
                    printf("Enter the new Address:");
                scanf("%s",sadd);
                fprintf(fb,"%d \n %s \n %s \n %d \n %s \n %s\n  ",stud1.enrollnum,stud1.name,sadd,stud1.dob,stud1.course,stud1.teacher);
                        fflush(stdin);
                        printf("Changes saved!");
                }
             else if(choice==3)
                {
                    printf("Enter the teacher name:");
                scanf("%s",steach);
                fprintf(fb,"%d \n %s \n %s \n %d \n %s \n %s\n  ",stud1.enrollnum,stud1.name,stud1.adress,stud1.dob,stud1.course,steach);
                        fflush(stdin);
                        printf("Changes saved!");
                }
             else if(choice==4)
                {
                    printf("Enter the new DOB:");
                scanf("%d",&sdob);
                fprintf(fb,"%d \n %s \n %s \n %d \n %s \n %s  ",stud1.enrollnum,stud1.name,stud1.adress,sdob,stud1.course,stud1.teacher);
                        fflush(stdin);
                        printf("Changes saved!");
                }
        }
        else
        fprintf(fb,"%d \n %s \n %s \n %d \n %s \n %s  ",stud1.enrollnum,stud1.name,stud1.adress,stud1.dob,stud1.course,stud1.teacher);


        }
        fclose(fp);
    fclose(fb);
    remove("student.txt");
    rename("new.txt","student.txt");
printf("\nWant to view more  details YES<y> NO <Any key>");
    scanf("%c",&c);
    if(c=='y'||c=='Y')
    {
        view();
    }
    else
    {
        main();
    }



if(test!=1)
        {
            main();
        }
}

void del()
{
    FILE *fp,*fb;
    int test=0;
    int sname;
system("cls");
printf("\n\n\t****Welcome to delete details of students****\n");

    fp=fopen("student.txt","r");
    fb=fopen("new.txt","w");
    printf("\n Enter the Enrollment number");
    scanf("%d",&sname);
     while(fscanf(fp,"%d  %s  %s  %d  %s  %s  ",&stud1.enrollnum,stud1.name,stud1.adress,&stud1.dob,stud1.course,stud1.teacher)!=EOF)
    {
        if(stud1.enrollnum!=sname)
        {

            fprintf(fb,"%d \n %s \n %s \n %d \n %s \n %s \n ",stud1.enrollnum,stud1.name,stud1.adress,stud1.dob,stud1.course,stud1.teacher);

        }
         else
            {
                test++;
            printf("\nRecord deleted successfully!\n");
            }
   }
   fclose(fp);
   fclose(fb);
   remove("student.txt");
   rename("new.txt","student.txt");

   if(test==0)
   {
       main();
   }

}


