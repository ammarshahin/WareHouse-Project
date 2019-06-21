/**********************Includes**********************/
#include "Display.h"

/**********************Global Functions Definitions**********************/
void display_Init(void){
    Console_write(STRING , "*********************************Database Program For a Warehouse **********************************\n");
    Console_write(STRING , "Operations Commands:\n");
    Console_write(STRING , "1. List all the product.\n");
    Console_write(STRING , "2. Search For a product.\n");
    Console_write(STRING , "3. Update a product.\n");
    Console_write(STRING , "4. Set a new product to the Warehouse.\n");
    Console_write(STRING , "5. Delete a product from the Warehouse.\n");
    Console_write(STRING , "6. Quit the program.\n");
}


void display_Task(void){

    int NO;
    Operation Choice;

    Console_write(STRING , "\nEnter your operation Choice: ");
    Console_Read(INT,&Choice);

    switch(Choice){

        case LIST_PROD :
            display_all_proInf0();
            break;

        case SEARCH_PROD :
            Console_write(STRING , "Enter the Product Number: ") ;
            Console_Read(INT,&NO);
            display_Inf0(NO);
            break;

        case UPDATE_PROD :
            Console_write(STRING , "Enter the Product Number: ") ;
            Console_Read(INT,&NO);
            display_Updata(NO);
            break;

        case SET_PROD :
            Console_write(STRING , "Enter the New Product Number: ") ;
            Console_Read(INT,&NO);
            display_SetNewProduct(NO);
            break;

        case DELETE_PROD :
            Console_write(STRING , "Enter the Product Number to delete: ") ;
            Console_Read(INT,&NO);
            display_deleteProduct(NO);
            break;
        case QUIT :
            exit(0);
            break;
         default :
            Console_write(STRING , "Not a valid entry !!!\n\n") ;
            break;
    }
}

/**********************Private Functions Definitions**********************/

static void display_all_proInf0(){
    int i,inStorage_prod = (int) warehouse_getNo_Of_prod();
    for(i = 0 ; i < inStorage_prod ; i++){
        display_Inf0(i);
    }
}

static int display_Inf0(int NO){

    AUX Prod_Inf0 = organizer_Search(NO);
    Console_write(STRING, "\nThe product info is: number: ");
    Console_write(INT, &NO);
    Console_write(STRING, "    Name: ");
    Console_write(STRING, Prod_Inf0.name);
    Console_write(STRING, "    Price: ");
    Console_write(INT, &Prod_Inf0.price);
    Console_write(STRING, "$      quantity: ");
    Console_write(INT, &Prod_Inf0.quantity);
    Console_write(STRING, "\n");

    return (Prod_Inf0.price != 0);
}

static void display_Updata(int NO){

    int update;
    t_update_type choice;

    if(display_Inf0(NO))
    {
        Console_write(STRING, "What field you want to update( [1] for Quantity & [2] for price): ");
        Console_Read(INT,&choice);
        switch(choice)
        {
            case QUANTITY :
                Console_write(STRING, "Enter the new Quantity: ");
                Console_Read(INT,&update);
                organizer_Update(NO,QUANTITY,update);
                break;

            case PRICE:
                Console_write(STRING, "Enter the new Price: ");
                Console_Read(INT,&update);
                organizer_Update(NO,PRICE,update);
                break;

            default :
                Console_write(STRING, "Not a valid Enter!!!");
                break;
        }
    }
    else
    {
                Console_write(STRING, "NO Product to be updated !\n\n");
    }
}

static void display_SetNewProduct(int NO){

    char arr[20];
    int p,q;
    int maxStorage_prod = warehouse_MaxNo();
    int inStorage_prod = warehouse_getNo_Of_prod();

    if(inStorage_prod < maxStorage_prod)
    {
        int already_exist = display_Inf0(NO);
        if(!already_exist){
        Console_write(STRING, "Enter the new product name: ");
        Console_Read(STRING,arr);
        Console_write(STRING, "Enter the new product price: ");
        Console_Read(INT,&p);
        Console_write(STRING, "Enter the new product Quantity: ");
        Console_Read(INT,&q);
        organizer_SetNewProduct(NO,arr,p,q);
        Console_write(STRING, "Done!\n");
        }
        else if(already_exist)
        {
        Console_write(STRING, "Product Number already exist !! \n\n");
        }
        else
        {
            // do nothing
        }
        }
    else if(inStorage_prod >= maxStorage_prod)
    {
        Console_write(STRING, "The warehouse is full. !! \n\n");
    }
    else
    {
        // do nothing
    }
}

static void display_deleteProduct(int NO){

    if((display_Inf0(NO)))
    {
        organizer_deleteProduct(NO);
        Console_write(STRING, "Done!\n");
    }
    else
    {
        Console_write(STRING, "No product With this number!! \n\n");
    }
}
