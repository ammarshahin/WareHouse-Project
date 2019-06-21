#ifndef ORGANIZER_H_INCLUDED
#define ORGANIZER_H_INCLUDED
/**********************Includes**********************/
#include "warehouse.h"

/**********************Global MACROS**********************/
/**********************Global Data Types**********************/
typedef enum{QUANTITY=1,PRICE=2}t_update_type;
/**********************Global Variables Declarations**********************/
/**********************Global Functions Prototypes**********************/
    void organizer_Init(void);
    AUX organizer_Search(int);
    void organizer_Update(int , t_update_type , int);
    void organizer_SetNewProduct(int,char*,int,int);
    void organizer_deleteProduct(int);

/**********************Private MACROS**********************/
/**********************Private Data Types**********************/
/**********************Private Variables Definitions**********************/
/**********************Private Functions Prototypes**********************/
/**********************Global Variables Definitions**********************/
#endif // ORGANIZER_H_INCLUDED
