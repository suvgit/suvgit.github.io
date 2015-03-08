#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch,  or input loop */
char productname[40];

void doVend(int product, int cashIn);
int getProductCost(int num);
char * getProductName(int ); 
int isProductAvailable(int num);

int main(int argc, char *argv[])
{
	int cashIn;
	int prodNo;
	
	printf("Enter your product number (1 to 9) inclusive : ");
	scanf("%d", &prodNo);

	printf("How much cash inserted (e.g. 410) : ");
	scanf("%d", &cashIn);
	
	//prodNo = 3;
	//cashIn = 990;
	doVend(prodNo, cashIn);
	
	system("pause");
	return (0);
}

/* 
 * The main function should:
 * 	validate the inputs
 * 	Verify if the product is available
 * 	Obtain the cost and the name of the product
 * 	If available, give out the product and the change amount
 */
 void doVend(int product, int cashIn)
 {
 	int cost, change, tc, rem, nleft, nremaining;
 	
 	// validate the inputs
 	if (product < 1 || product > 9)
 	{
  		printf("Product must be between 1 and 9 inclusive\n");
 		return;		
 	}
 	if (cashIn < 0 || cashIn > 10000)
 	{
  		printf("Cast inserted must be between 0 and 10000 cents inclusive\n");
 		return;		
 	} 	
 	
 	
 	printf("Product is %s\n", getProductName(product));
 	printf("Cash inserted : %d\n", cashIn);
 	
 	if (isProductAvailable(product) == 0)
 	{
 		printf("Product is not available, sorry!\n");
 		return;	
 	}
 	
 	cost = getProductCost(product);
 	printf("Product cost  : %d\n", cost);
 	
 	if (cashIn < cost)
 	{
  		printf("Please insert more cash, there is not enough\n");
 		return;			
 	}
 	
 	change = cashIn - cost;
 	printf("Your change will be : %d\n", change);
 	
 	// return minimum coins
 	tc = change / 200;
 	rem = change % 200;	
 	if (tc != 0) 
	 {
 		nleft = howManyLeft(200);
 		if (nleft > 0)	// we can give some back
 		{
 			nremaining = nleft;	// how many left after give out
 			while (tc > 0 && nremaining > 0)
 			{
 				printf("Returning 1 E2 coin\n");
 				tc--;
 				nremaining--;
 				change = (change - 200);  			
			}		
 		}	
 	}
 	//printf("change remaining : %d\n", change);
  
 	tc = change / 100;
 	rem = change % 100;	
 	if (tc != 0) 
	 {
 		nleft = howManyLeft(100);
 		if (nleft > 0)	// we can give some back
 		{
 			nremaining = nleft;	// how many left after give out
 			while (tc > 0 && nremaining > 0)
 			{
 				printf("Returning 1 E1 coin\n");
 				tc--;
 				nremaining--;
 				change = (change - 100);  			
			}		
 		}	
 	} 	

 	//printf("change remaining : %d\n", change);
 	tc = change / 50;
 	rem = change % 50;	
 	if (tc != 0) 
	 {
 		nleft = howManyLeft(50);
 		if (nleft > 0)	// we can give some back
 		{
 			nremaining = nleft;	// how many left after give out
 			while (tc > 0 && nremaining > 0)
 			{
 				printf("Returning 1 50c coin\n");
 				tc--;
 				nremaining--;
 				change = (change - 50);  			
			}		
 		}	
 	} 
     
 	//printf("change remaining : %d\n", change);
 	tc = change / 20;
 	rem = change % 20;	
 	if (tc != 0) 
	 {
 		nleft = howManyLeft(20);
 		if (nleft > 0)	// we can give some back
 		{
 			nremaining = nleft;	// how many left after give out
 			while (tc > 0 && nremaining > 0)
 			{
 				printf("Returning 1 20c coin\n");
 				tc--;
 				nremaining--;
 				change = (change - 20);  			
			}		
 		}	
 	} 

 	// printf("change remaining : %d\n", change);
 	tc = change / 10;
 	rem = change % 10;	
 	if (tc != 0) 
	 {
 		nleft = howManyLeft(10);
 		if (nleft > 0)	// we can give some back
 		{
 			nremaining = nleft;	// how many left after give out
 			while (tc > 0 && nremaining > 0)
 			{
 				printf("Returning 1 10 coin\n");
 				tc--;
 				nremaining--;
 				change = (change - 10);  			
			}		
 		}	
 	}            	
 }
 
 
/**************** HELPING FUNCTIONS ********************/

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
int getProductCost(int num) {
	int price = 0;
	
	switch (num)
	{
		case 1:
		case 4:
		case 7:
			price = 270;
			break;
		
		case 2:
		case 5:
		case 8:
			price = 160;
			break;
		
		case 3:
		case 6:
		case 9:
			price = 310;
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
			left = 1;		// 200 cents
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


