#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch,  or input loop */
char productname[40];
int isProductAvailable(int num);
double getProductCost(int num);
char * getProductName(int num);
int howManyLeft(int cents);

/* 
 * The main function should:
 * 	validate the inputs
 * 	Verify if the product is available
 * 	Obtain the cost and the name of the product
 * 	If available, give out the product and the change amount
 */
int main() {

	/* Your code goes here */
	int argc = 0;
	double argm = 0.00;
	char *name;
	
	/* 0) ask for number 1 and 9 and how much cash you are putting in (e.g. 4.00) double */
	printf("Please enter the product code: ");
	scanf("%d", &argc);
	
	printf("Please enter the money: ");
	scanf("%lf", &argm);
	
	// validate the inputs
 	if (argc < 1 || argc > 9)
 	{
  		printf("Product must be between 1 and 9 inclusive\n");
 		return;		
 	}
 	if (argm < 0 || argm > 10000)
 	{
  		printf("Cast inserted must be between 0 and 10000 cents inclusive\n");
 		return;		
 	} 		
	
	/* Check if product available */
	if (isProductAvailable(argc))
	{
		/* Get the product cost */
		double cost = getProductCost(argc);
		
		if (argm >= cost)
		{
			/* Get the name of the product */	
				
			name = getProductName(argc);
		
			printf("Product Name is %s", name,"\n");
			
			if (argm > cost){
				//printf( "\n name is available with a change : ");
				//calculateCost(argm, cost);
			} else {
				printf( "\n name is available ");
			}			
		} else {
			printf(" Amount entered is less than the cost of the product!");
		}		
	} else {
		printf("Product not available!");
	}	
	
	/* Print out the name of the product, the number, the cost and thee change due */


	/* finish */

	printf("Press a key\n");
	system("pause");
	return 0;
}

/**************** HELPING FUNCTIONS ********************/
// function to calculate the change
double calculateCost(double amount,double cost){
	
}

/*
 *	int isProductAvailable(int productNumber)
 *	
 *	This will return 1 if the product is available in the machine
 *	It will return 0 if it is not available
 *
 *	num can be between 1 and 9 inclusive
 */
int isProductAvailable(int num) {
	int avail = 0;
	
	switch (num)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 9:
			avail = 1;
			break;
		
		default:
			break;
	}
	return(avail);
}

/*
 *	double getProductCost(int productNumber)
 *	
 *	This will return the price to buy the product as a double
 *	num can be between 1 and 9 inclusive
 *
 *  
 */
double getProductCost(int num) {
	double price = 0;
	
	switch (num)
	{
		case 1:
		case 4:
		case 7:
			price = 2.70;
			break;
		
		case 2:
		case 5:
		case 8:
			price = 1.60;
			break;
		
		case 3:
		case 6:
		case 9:
			price = 3.10;
			break;
		
		default:
			break;
	}
	return(price);	
}

/*
 * char * getProductName(int num)
 * Returns the name of the product as a char *
 *
 * num can be between 1 and 9 inclusive
 * 
  *	Example theName = getProductName(2);
 */
char * getProductName(int num) {
	
	switch (num)
	{
		case 1:
			strcpy(productname,"Cone Explosion");
			break;
		case 4:
			strcpy(productname,"Mad Cone");
			break;
		case 7:
			strcpy(productname,"Cone Experience");
			break;
		
		case 2:
			strcpy(productname,"Cone d'amour'");
			break;
		case 5:
			strcpy(productname,"Le cône");
			break;
		case 8:
			strcpy(productname,"Wafer thin");
			break;
		
		case 3:
			strcpy(productname,"Cone Lemon");
			break;
		case 6:
			strcpy(productname,"The Engineers Cone");
			break;
		case 9:
			strcpy(productname,"Hot Cone");
			break;
		
		default:
			strcpy(productname,"Unknown");
			break;
	}
	return(productname);
}

/*
 * int howManyLeft(int cents)
 *
 * returns how many coins of each type are left in the machine
 * cents should be one of 200, 100, 50, 20 or 10
 *
 * No50centsLeft = howManyLeft(50);
 */
int howManyLeft(int cents) {
	int left = 0;
	
	switch (cents)
	{
		case 200:
			left = 10;		// 200 cents
			break;
		
		case 100:
			left = 10;		// 100 cents
			break;
		
		case 50:
			left = 10;		// 50 cents
			break;
		
		case 20:
			left = 10;		// twenty cents
			break;
		
		case 10:
			left = 10;		// 10 cents
			break;
		
		default:
			left = 0;	// unknown coin
			break;
	}
	
	return(left);
}

