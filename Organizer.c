
/**********************Includes**********************/
#include "Organizer.h"

/**********************Global Functions Definitions**********************/
AUX organizer_Search(int NO){
        return Warehouse_getInfo(NO);
}

void organizer_Update(int NO,t_update_type choice,int update){

    switch(choice){
        case QUANTITY:
            warehouse_setQuantity(NO,update);
            break;
        case PRICE:
            warehouse_setPrice(NO,update);
            break;
    }
}

void organizer_SetNewProduct(int NO,char* arr,int p,int q){
        warehouse_SetNewProduct(NO,arr,p,q);
}

void organizer_deleteProduct(int NO){
    warehouse_deleteProduct(NO);
}
/**********************Private Functions Definitions**********************/
