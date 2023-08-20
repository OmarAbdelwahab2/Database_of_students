#include"SDB.h"//hearder file that include the typedefine of the struct and the prototpye of all needed funtions 
#include<stdlib.h>//hearder file to facilitate dynamic memory allocation. 
#include<stdio.h>
#define Maxnumber 10 // maximum number of student in the database 
uint32 count=0;//to count the number of students added to the database.initialized by 0 since I start with nostudent
student* head=NULL;//create a pointer called head that points to a null ( start of my list) .   
bool SDB_IsFull()//to check if the database is full or not 
{
	//count is the number of student added in our database
	if(count==Maxnumber)//check for the max number of student to be added to our database (10)
	{
		
		return 1;//the database is full
	}
	else 
	{
		return 0;//the database is not full
	}
}
uint8 SDB_GetUsedSize()//to get how many student in the database
{
	return count;//return the counter only since we start with 0 student ;
}
bool SDB_AddEntry()//to add a student to the database
{
	uint32 Is_full=SDB_IsFull();//check if the database is full
	if (Is_full==1)  
	{
		printf(" the database is full \n\n");
		return 0;//the data is not added
	}
	else // let the user enter the data of the student 
	{
	student* newstudent=(student*)malloc(sizeof(student));//create a space in the heap for the new student .
	printf("enter the student id\n");
	scanf("%d",&newstudent->Student_ID);
	printf("enter the student year\n");
	scanf("%d",&newstudent->Student_year);
	printf("enter the student course1 ID\n");
	scanf("%d",&newstudent->Course1_ID);
	printf("enter the student course1 grade \n");
	scanf("%d",&newstudent->Course1_grade);
	printf("enter the student course2 ID\n");
	scanf("%d",&newstudent->Course2_ID);
	printf("enter the student course2 grade \n");
	scanf("%d",&newstudent->Course2_grade);
	printf("enter the student course3 ID\n");
	scanf("%d",&newstudent->Course3_ID);
	printf("enter the student course3 grade \n");
	scanf("%d",&newstudent->Course3_grade);
	newstudent->next=head;//inserting the new student before the head and make his pointer points to the head 
	head=newstudent;//change the head pointer to point to the start so our start now is the newstudent 
	count++; // adding the  student increase the count by 1  
	return 1;// the data is added sucsessfully
	}
	
}
bool SDB_IsIdExist (uint32 id)//to check if the student is exist according to his id
{
	student* temp=head;//check from the start of the database.
	uint32 result=0;//to return what we need. if we find the id it will be initialized 1 ,otherwise 0.
	if(temp==NULL)
	{
		printf("the database is empty\n\n");
		return result;
	}
	else
	{
	while(temp!=NULL)//to check on the entire database until it points to NULL (last student)
	{
		if(temp->Student_ID==id)
		{
			result=1;//return 1 
			break;//get out of the loop
		}
		else
		{
		//do nothing (misra rules)
		}
		temp=temp->next;//switch to the next student .
	}
		return result;//1 for true 0 for false 
	
	}
}
void SDB_DeletEntry (uint32 id)//to delete a student from the database according to his id 
{
	student* current =head;//the student data we want to remove .
	student* previous; //the student before the student we want to remove . 
	uint32 Is_exist =SDB_IsIdExist(id);//check if the is is exist or not . 
	if(Is_exist==0)
	{
		printf("the id is not exist or the database is empty\n\n");
	}
	else if(current->Student_ID==id)//condition where we want to delete the first element .
	{
		head=current->next;//adjusting the head for the second student.
		free(current);//remove the student data from the database.
		count--;//decrementing the count by one so that the database now one extra space to add a student 
		printf("the data is deleted sucsessfully\n\n");
	}
	else
	{
		while(current->next!=NULL&&current->Student_ID!=id)//searching for the id in the database
		{
			previous=current;//make the pointer points to the student just before the one we want to delete 
			current=current->next;//switch to the next student .
		}
		previous->next=current->next;//connect the student before the deleted one to the student after the deleted one.
		free(current);//delelte the student  
		count--;//decrementing the count by one so that the database now one extra space to add a student 
		printf("the data is deleted sucsessfully\n\n");
	}
	 
}
bool SDB_ReadEntry(uint32 id)//to read student from the database according to his id
{
	student* temp=head;//refere to the poisition where my pointer is in my list 
	uint32 IS_exist=SDB_IsIdExist(id);//check if the database is full
	if (IS_exist==0)  
	{
		printf(" the id is not in the database \n\n");
		return 0;
	}
	else
	{
	while(temp!=NULL)//search for all the list until the end (pointer points to null)
	{
		if(temp->Student_ID==id)//if the id is found 
		{
			printf(" student id is %d\n",temp->Student_ID);
			printf("student year is %d\n",temp->Student_year);
			printf(" student course 1 id is %d\n",temp->Course1_ID);
			printf("student course 1 grade is %d\n",temp->Course1_grade);
			printf("student course 2 id %d\n",temp->Course2_ID);
			printf("student course 2 grade is %d\n",temp->Course2_grade);
			printf("student course 3 id %d\n",temp->Course3_ID);
			printf("student course 3 grade is %d\n\n",temp->Course3_grade);
		}
		else{}//misra rules 
		temp =temp->next;//switch to the next student .
	}
	return 1;
	}
}
void SDB_GetList (uint32  count, uint32* list)//gets all the ids in the database .
{
	student* temp=head;//initialize the start of my database to temp
	uint32 i =0;//counter to use in the for loop 
	if(count==0) //check if the database is empty
	{
		printf("The database is empty.\n\n");
	}
	else//the database is not empty
	{
		printf("their are %d IDs in the database which are:\n\n",count);
		while(temp!=NULL)//to reach all the student's id 
		{
			list[count-i]=temp->Student_ID;//put the id of the first student in the last element of the array .
			temp=temp->next;//get to the next student.
			i++;//increase my counter to get the next  element of the array
		}
		for(i=1;i<=count;i++)//print the ids in the array ;
		{
			printf("%d\n",list[i]);
		}
	}
}
