#ifndef SDB_h_//guards to prevent duplicate definition
#define SDB_h_//guards
#include"STD.h"//file that include the typedefine of the datatypes
typedef struct simpleDb
{
	uint32 Student_ID;
	uint32 Student_year;
	uint32 Course1_ID;
	uint32 Course1_grade;
	uint32 Course2_ID;
	uint32 Course2_grade;
	uint32 Course3_ID;
	uint32 Course3_grade;
	struct simpleDb* next;//pointer the points to the next element in the database.(self refrential structure).
}student;
extern uint32 count;//to count the number of students added in the database .
extern uint8 choice;//to get the choice from  the user .
bool SDB_IsFull();
uint8 SDB_GetUsedSize();
bool SDB_AddEntry();
bool SDB_IsIdExist (uint32 id);
void SDB_DeletEntry (uint32 id);
bool SDB_ReadEntry(uint32 id);
void SDB_GetList (uint32  count, uint32*list);
void SDB_APP ();
void SDB_action (uint8 choice);

#endif//guards