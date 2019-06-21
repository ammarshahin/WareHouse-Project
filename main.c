/**********************Includes**********************/
#include "main.h"

/**********************Global Functions Definitions**********************/
int main(){

/*! Initialization for all the modules */
    display_Init();
    warehouse_Init();

/*! With a super loop Do this for ever */
     while(1)
    {
        display_Task();
    }

    return 0;
}

/**********************Private Functions Definitions**********************/
