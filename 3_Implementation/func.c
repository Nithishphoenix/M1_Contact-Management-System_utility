#include<stdio.h>
#include<conio.h>
#include"func.h"

void validate()
{
	for(i=0;i<j;i++)
	{
		if(!strcmp(s[i].name,temp_name))
		{
			printf("Name already existed!\n");
			exit(1);
		}
	}
	if(i==j)
	{
		count=0;
		for(i=0;temp_email[i]!='\0';i++)
		{
			if(temp_email[i]=='@' || temp_email[i]=='.')
			{
				count++;
			}
		}
		if(count!=2)
		{
			printf("Please Enter correct Email:\n");
			exit(1);
		}
		else
		{
			if(!(strlen(temp_email)>=5))
			{
				printf("\nPlease Enter correct Email\n");
				exit(1);
			}
		}
	}
	for(i=0;i<10;i++)
	{
		if(strlen(temp_mobile)!=10 || temp_mobile[0]=='0')
		{
			printf("Please Enter the valid Mobile Number");
			exit(1);
		}
		else if(!(temp_mobile[i]>='0' && temp_mobile[i]<='9'))
		{
			printf("Please Enter the valid Mobile Number:");
			exit(1);
		}
	}
	for(i=0;i<j;i++)
	{
		if(!strcmp(temp_mobile,s[i].mobileno))
		{
			printf("Phone Number already existed in contact book\n");
			exit(1);
		}
	}
}
void addition()
{
	printf("Enter the Name:");
	scanf("%s",temp_name);
	printf("Enter the Mobile Number:");
	scanf("%s",&temp_mobile);
	printf("Enter the email:");
	scanf("%s",temp_email);
	validate();
	strcpy(s[j].name,temp_name);
	strcpy(s[j].mobileno,temp_mobile);
	strcpy(s[j].email,temp_email);
	j++;
	c++;
	printf("\n\nContact saved successfully\n");
}
void deletion()
{
	printf("Enter the Name:\t");
	scanf("%s",temp_name);
	for(i=0;i<j;i++)
	{
		if(!strcmp(s[i].name,temp_name))
		{
			strcpy(s[i].name,empty);
			strcpy(s[i].mobileno,empty);
			strcpy(s[i].email,empty);
			printf("\nContact Successfully Deleted!\n");
			c--;
			break;
		}
	}
	if(i==j)
	{
		printf("\nContact Not found!\n");
	}
}
void search()
{
	printf("Enter the Name:\t");
	scanf("%s",temp_name);
	for(i=0;i<j;i++)
	{
		if(!strcmp(s[i].name,temp_name))
		{
			printf("Name : %s\nMobile No.: %s\nE-Mail : %s\n",s[i].name,s[i].mobileno,s[i].email);
			break;
		}
	}
	if(i==j)
	{
		printf("\n Contact Not Found\n");
	}
}
void sort()
{
	for(m=1;m<j;m++)
	{
		for(n=0;n<j-m;n++)
		{
			if(strcmp(s[n].name,s[n+1].name)>0)
			{
				temp=s[n];
				s[n]=s[n+1];
				s[n+1]=temp;
			}
		}
	}
}
void display()
{
	if(c==0)
	{
		printf("\n\nNo Contact to displayed!!\n\n");
	}
	else
	{
		sort();
		printf("\n\n-----------Your Contact Dairy is-------------\n\n");
		for(i=0;i<j;i++)
		{
			if(strcmp(s[i].name,empty))
			{
				printf("Name : %s\nMobile No.: %s\nE-Mail : %s\n",s[i].name,s[i].mobileno,s[i].email);
				printf("\n--------------\n");
			}
		}
		printf("\n\n-------THE END--------\n\n");
	}
}

