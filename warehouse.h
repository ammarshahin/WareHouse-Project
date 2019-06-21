#ifndef WAREHOUSE_H_INCLUDED
#define WAREHOUSE_H_INCLUDED
/**********************Includes**********************/
#include <stdlib.h>
#include <string.h>

/**********************Global MACROS**********************/
/**********************Global Data Types**********************/
typedef struct INFO{
    struct INFO* next;
	struct INFO* prev;
    int no;
    int price;
    int quantity;
    char name[20];
}INFO;

typedef struct{
    int no;
    int price;
    int quantity;
    char name[20];
}AUX;



/**********************Global Variables Declarations**********************/
    void warehouse_Init(void);
    AUX Warehouse_getInfo(int);
    void warehouse_setQuantity(int,int);
    void warehouse_setPrice(int,int);
    void warehouse_setName(int,char*);
    void warehouse_SetNewProduct(int,char*,int,int);
    int warehouse_MaxNo();
    void warehouse_deleteProduct(int);





/**********************Global Functions Prototypes**********************/
/**********************Private Data Types**********************/
/**********************Private Variables Definitions**********************/
static INFO* START;
static INFO* END;
static int no_Of_Product = 0;


/**********************Private Functions Prototypes**********************/
static INFO* create_Node();
static void append(int,char*,int,int);
static INFO* search(int);
static int delete_prod(int);


/**********************Global Variables Definitions**********************/

#endif // WAREHOUSE_H_INCLUDED
