#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED

/**********************Includes**********************/
#include "console.h"
#include "Organizer.h"

/**********************Global MACROS**********************/
/**********************Global Data Types**********************/
/**********************Global Variables Declarations**********************/
/**********************Global Variables Definitions**********************/
/**********************Global Functions Prototypes**********************/
void display_Init(void);
void display_Task(void);


/**********************Private MACROS**********************/
/**********************Private Data Types**********************/
typedef enum{
    LIST_PROD   = 1,
    SEARCH_PROD = 2,
    UPDATE_PROD = 3,
    SET_PROD    = 4,
    DELETE_PROD = 5,
    QUIT        = 6,
}Operation;

/**********************Private Variables Definitions**********************/
/**********************Private Functions Prototypes**********************/
static void display_all_proInf0();
static int display_Inf0(int);
static void display_Updata(int);
static void display_SetNewProduct(int);
static void display_deleteProduct(int);
#endif // DISPLAY_H_INCLUDED
