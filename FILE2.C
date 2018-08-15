#include<stdio.h>
#include<string.h>
#include<conio.h>
void main()
{
	int marks,marks1,ch,flag=0,set=0;
	char iusn[20],usn[20],usn1[20],fname[20],fname1[20],lname[20],lname1[20],buf[100],c;
	FILE *f;
	clrscr();
	while(1)
	{
		printf("Enter 1 for student detail\n2 for new entry\n3 for search\n4 for exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			printf("Enter the last 3 digits of usn \n");
			scanf("%s",iusn);
			sprintf(buf,"%s.txt",iusn);
			f=fopen(buf,"r");
			if(f==NULL)
			{
				printf("Invalid usn input\nTry again\n");
				exit(0);
			}
			while(!feof(f))
			{
				fscanf(f,"%s",usn);
				fscanf(f,"%s",fname);
				fscanf(f,"%s",lname);
				fscanf(f,"%d",&marks);
			}
			fclose(f);
			printf("Student details:\n");
			printf("usn\t\tname\t\tmarks\n");
			printf("%s\t%s %s\t%d\n",usn,fname,lname,marks);
			break;

			case 2:flag=0;
			while(flag==0)
			{
			f=fopen("newe.txt","a+");
			printf("Enter the student details\nUSN,Name and marks\n");
			scanf("%s%s%s%d",usn,fname,lname,&marks);
			while(!feof(f))
			{
				fscanf(f,"%s",usn1);
				fscanf(f,"%s",fname1);
				fscanf(f,"%s",lname1);
				fscanf(f,"%d",&marks1);
				if(strcmp(usn1,usn)==0)
				{
					printf("Student detail already exists\nTry again\n");
					fclose(f);
					set=1;
					break;
				}
			}
			if(set==1)
				break;
			else
				flag=1;
			fprintf(f,"%s\t%s %s\t%d\n",usn,fname,lname,marks);

			printf("Do you want to enter more student details(1/0)?\n");
			scanf("%d",&ch);
			if(ch==1)
				flag=0;
			else
			{       fclose(f);
				f=fopen("newe.txt","r");
				printf("USN\t\t\tNAME\t\tMARKS\n");
				while(!feof(f))
				{
					c=getc(f);
					printf("%c",c);

				}
			}
			}
			fclose(f);
			break;

			case 3:
			printf("Enter the usn of the student you want to search\n");
			scanf("%s",usn);
			f=fopen("newe.txt","r");
			flag=0;
			while(!feof(f))
			{
				fscanf(f,"%s",usn1);
				fscanf(f,"%s",fname1);
				fscanf(f,"%s",lname1);
				fscanf(f,"%d",&marks1);
				if(strcmp(usn1,usn)==0)
				{
					printf("Student found\n");
					printf("Details:- %s\t%s %s\t%d\n",usn1,fname1,lname1,marks1);
					flag=1;
					break;
				}
			}
			if(flag==0)
				printf("Student not found\n");
			fclose(f);
			break;
			default:exit(0);
		}
	}
}


