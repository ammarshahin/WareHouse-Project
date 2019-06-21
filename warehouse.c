
/**********************Includes**********************/
#include "warehouse.h"

/**********************Private MACROS**********************/
#define MAX_STOARGE 1000

/**********************Global Functions Definitions**********************/
void warehouse_Init(){

/* Set initial values for the Linked list */

    START = NULL; // set the Start pointer to point at nothing as the list is empty
	END = NULL;   // set the End pointer to point at nothing as the list is empty

/* Set some initial values in the WareHouse */
    append(0,"Keyboard",20,20);
    append(1,"mouse",30,40);
    append(2,"headphones",200,10);
    append(3,"monitor",6000,6);

}

AUX Warehouse_getInfo(int NO){
        INFO *p = search(NO);
        AUX temp = {NO,0,0,"Empty"};
        if(p)
        {
            strcpy(temp.name,p->name);
            temp.no = p->no;
            temp.price = p->price;
            temp.quantity = p->quantity;
        }
        else
        {
            // Do nothing
        }
        return temp;
}

void warehouse_setQuantity(int NO,int update){
    INFO *p = search(NO);
    p->quantity = update;
}

void warehouse_setPrice(int NO,int update){
    INFO *p = search(NO);
    p->price = update;
}

void warehouse_setName(int NO,char* pp){
    INFO *p = search(NO);
    strcpy(p->name,pp);
}

void warehouse_SetNewProduct(int NO,char* arr,int p,int q){
    append(NO,arr,p,q);
}

int warehouse_getNo_Of_prod(){
    return no_Of_Product;
}

int warehouse_MaxNo(){
    return MAX_STOARGE;
}

void warehouse_deleteProduct(int NO){
    delete_prod(NO);
}



/**********************Private Functions Definitions**********************/
static INFO* search(int NO){
        INFO* temp = START;
        while( ( temp != NULL ) && ( temp -> no != NO )){ // Loop through all the elements until the element is Found
            temp = temp->next;
        }
        return temp;
}


static void append(int NO,char* pName,int price,int quantity){
    no_Of_Product = (NO > no_Of_Product) ? NO : no_Of_Product;
    INFO* element = create_Node();
	element->no = NO;
	strcpy( element->name , pName );
	element->price = price;
	element->quantity = quantity;
	if((START == NULL) && (END == NULL)){    // the list is empty___ and this is will be the first element
		START = element;
		END = element;
		element->prev = NULL;
		element->next = NULL;
	}else{                      // the list in Not_Empty and the element will be inserted in the End
		END->next = element;
		element->prev = END;
		END = element;
		element->next = NULL;
	}
}

static INFO* create_Node(){
    no_Of_Product++;
    return ((INFO* ) malloc( sizeof(INFO)));
}


static int delete_prod(int prod_No){
    INFO* temp;
	temp = search(prod_No); // call the search_Node function to get the Node address
	if(temp==NULL)  // the Node was not found ______ OR the List is empty
		return 0;
	if( (START == END) && (START != NULL) ){   // the Data is at First and it's the only element in the List
		START = NULL;  // reset the list to be empty
		END = NULL;
		free(temp);
        no_Of_Product--;
		return 1;
	}else if(temp == START){   // the Data is at First But not the only element in the List
		START = START->next;  // Make the next element the first One
		START->prev = NULL;
		free(temp);
		no_Of_Product--;
		return 1;
	}else if(temp == END){    // the Data is at the End of the List
		END = temp->prev;
		END->next = NULL;
		free(temp);
        no_Of_Product--;
		return 1;
	}else{                      // the Data is at The Middle
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		free(temp);
        no_Of_Product--;
		return 1;
	}
}
