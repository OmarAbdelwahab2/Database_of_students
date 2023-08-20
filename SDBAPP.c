#include"STD.h"//file that include the typedefine of the datatypes
#include"SDB.h"//file that include the typedefine of the struct and the prototpye of all needed funtions 
#include<stdlib.h>//libarary for the linked list funtions
#include<stdio.h>
uint8 choice ; //to get the choice of the user when he picks what the operation he wants .
uint32 count;//to count the number of students added to the database.initialized by 0 since we start with nostudent.
uint32 a[10];//to get the list of all students ids.
void SDB_APP ()//the start of the project.
{
	do // the following lines at least has to be done once .
	{
		printf("\nplease choose from the following options :\n1. To add entry, enter 1\n2. To get used size in database, enter 2\n");
		printf("3. To read student data, enter 3\n4. To get the list of all student IDs, enter 4\n5. To check is ID is existed, enter 5 \n");
		printf("6. To delete student data, enter 6\n7. To check is database is full, enter 7\n8. To exit enter 0\n");
		scanf(" %d",&choice);//get the choice from the user.
		SDB_action(choice);//call the function to choose the specific operation .
	} while(choice!=0);//will stop when the user choose the exit operation.
}
void SDB_action (uint8 choice)//calling other functions according to the choice .
{
	uint32 id;//to get the id the user want to do any operation with it 
	uint32 is_exist;//to store the result of SDB_IsIdExist function. 
	uint32 is_full;//to store the result of SDB_IsFull function.
	uint32 used_size;//to store the size used in the database.
	switch(choice)//choose the function according to the choice of the user.
	{
		case 1 : SDB_AddEntry(); break;
		case 2 : 
		used_size=SDB_GetUsedSize(); 
		printf("the number of students in the database is %d\n\n",used_size);
		break;
		case 3:
		printf("enter the id to read\n\n");
		scanf("%d",&id);
		SDB_ReadEntry(id); break;
		case 4: SDB_GetList (count,a); break;
		case 5: 
		printf("enter the id to check if it exist in the database\n\n");
		scanf("%d",&id);
		is_exist=SDB_IsIdExist (id); 
		if(is_exist==0)
		{
			printf("the id is not in the database\n\n");
		}
		else
		{
			printf("the id is found\n\n");
		}
		break;
		case 6:
		printf("enter the id to delete from the database\n\n");
		scanf("%d",&id);
		SDB_DeletEntry (id);break;
		case 7:
		is_full=SDB_IsFull();
		if(is_full==1)
		{
			printf("the database is full\n\n");
			
		}
		else 
		{
			printf("the database is not full you still have %d spaces\n\n",10-count);
		} break;
		case 0: break;
		default://if the user choose a wrong number .
		printf("please choose a valid number for a specific opertaion\n\n");
	}
}