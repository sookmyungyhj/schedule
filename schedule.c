#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "schedule.h"

#define MAX_TYPE		7

//strings for printing the name of each enum element
//enum type's name
char type_string[MAX_TYPE][20] = 
{
	"drama",
	"movie",
	"advertisement",
	"entertainment",
	"meeting",
	"fitness",
	"privacy"
};

//month's name
char month_string[13][4] = 
{
	"", "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"
};

//enum definitions
typedef enum scheduleType {
	drama=0, 		//드라마 
	movie, 			//영화 
	advertisement, 	//광고 
	entertainment, 	//예능 
	meeting,		//회의 
	fitness,		//운동 
	privacy			//개인사 
} scheduleType_e;



//structure definition for a schedule info.
typedef struct schedInfo
{
	char name[200];			//schedule name
	scheduleType_e type;	//schedule type
	int month;				//when : month
	int day;				//when : day
	char place[100];		//where
} schedInfo_t;


void sched_printTypes(void) 
{
	int i;
	
	for (i=0;i<MAX_TYPE;i++) {
		printf("- %s\n", i, type_string[i]);
	}
}

void sched_print(void* obj) 
{
	schedInfo_t* schedPtr = (schedInfo_t*)obj;
	
	if (schedPtr == NULL) {
		printf("[ERROR] failed to print the schedule Info! (object is NULL)\n");
	}
	
	printf("Schedule Name : %s (%s)\n", schedPtr->name, type_string[schedPtr->type]);
	printf("When : %s. %i\n", month_string[schedPtr->month], schedPtr->day);
	printf("Where : %s\n", schedPtr->place);
	
	return;
}



//generating a structure of scheduling information
void* sched_genSchedInfo(char* name, char* place, int type, int month, int day)
{
	schedInfo_t* schedPtr;
	
	//error handler
	if(schedPtr == NULL){
		printf("Error");
		return 0;
	}
	
	//allocate memory and set the member variables
	schedPtr = (schedInfo_t*)malloc(5*sizeof(schedInfo_t)); 	//allocate memory
	
	if(schedPtr == NULL){  //error handler
		printf("Error : Allocate Memory \n ");
		return 0;
	}
	
	strcpy(schedPtr->name,name);  //set the member variables
	strcpy(schedPtr->place,place);
	schedPtr->type=type;
	schedPtr->month=month;
	schedPtr->day=day;
	
	free(schedPtr); //memory 반납 
	
	return (void*)schedPtr;
}


//get month information from the scheduler info structure
float sched_getMonth(void* obj)
{
	float* Input_month = (schedInfo_t*)obj;
	
	if(Input_month==NULL){ //error handler
		printf("Error : Input month");
	}
	
	Input_month=schedPtr->month; //set the value of month
	
	return Input_month;
}


//get type information from the scheduler info structure
int sched_getType(void* obj)
{
	int* Input_type = (schedInfo_t*)obj;
	
	if(Input_type==NULL){ //error handler
		printf("Error : Input type");
	}
	
	Input_type=schedPtr->type; //set the value of type
	
	return Input_type;
}



//get place string information from the scheduler info structure
char* sched_getPlace(void* obj)
{
	char* Input_place = (schedInfo_t*)obj;
	
	if(Input_place==NULL){ //error handler
		printf("Error : Input place");
	}
	
	Input_place=schedPtr->place; //set the value of place
	
	return Input_place;
}

//convert the name of the type into the enum(integer) value
int sched_convertType(char* typeName)
{
	enum convertType{drama=0,movie,advertisement,entertainment,meeting,fitness,privacy};
	
	return drama,movie,advertisement,entertainment,meeting,fitness,privacy;
}

