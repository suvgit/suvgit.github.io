# include <stdio.h>
int main()
{
    char o;
    float num1,num2;
    printf("Enter operator either + or - or * or divide : ");
    scanf("%c",&o);
    printf("Enter two operands: ");	    
	if (scanf("%f%f",&num1,&num2) == 2)
	{
		switch(o) {
		case '+':
			printf("%.2f + %.2f = %.2f",num1, num2, num1+num2);
			break;
		case '-':
			printf("%.2f - %.2f = %.2f",num1, num2, num1-num2);
			break;
		case '*':
			printf("%.2f * %.2f = %.2f",num1, num2, num1*num2);
			break;
		case '/':
			printf("%.2f / %.2f = %.2f",num1, num2, num1/num2);
			break;
		default:
			/* If operator is other than +, -, * or /, error message is shown */
			printf("Error! operator is not correct");
			break;
		}	
	} else	{
		printf("Error! Invalid Params ");
	}    
    return 0;
}
