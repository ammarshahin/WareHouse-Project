
/**********************Includes**********************/
#include "Console.h"

/**********************Private MACROS**********************/


/**********************Private Data Types**********************/


/**********************Private Variables Definitions**********************/


/**********************Private Functions Prototypes**********************/


/**********************Global Variables Definitions**********************/


/**********************Global Functions Definitions**********************/
void Console_Read(CONSOLE_DATA_t read_type , void* data )
{
    switch(read_type){
        case CHAR:
            scanf(" %c" , (TU08*)data);
            break;
        case INT:
            scanf(" %d" , (TS32*)data);
            break;
        case FLOAT:
            scanf(" %f" , (TF32*)data);
            break;
        case STRING:
            scanf("%s" , (TU08*)data);
            break;
        default :
            //Do Nothing
            break;
    }

}
 void Console_write(CONSOLE_DATA_t write_type , void* data)
 {

    switch(write_type)
    {
        case CHAR:
            printf("%c" , *(TU08*)data);
            break;
        case INT:
            printf("%d" , *(TS32*)data);
            break;
        case FLOAT:
            printf("%.3f" , *(TF32*)data);
            break;
        case DOUBLE:
            printf("%.3f" , *(TF64*)data);
            break;
        case STRING:
            printf("%s" , (TU08*)data);
            break;
        default :
            //Do Nothing
            break;
    }
 }

/**********************Private Functions Definitions**********************/

