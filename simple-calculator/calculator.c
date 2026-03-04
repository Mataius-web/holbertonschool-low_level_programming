#include <stdio.h>

/**
 * main - display the menu
 * Return: 0 succes
 */

int main(void)
{

int cmd;
int number1;
int number2;
int result;
int restDiv;
float num1;
float num2;
float resultDiv;

do
    {
    printf("##################\n");
    printf("Simple Calculator\n");
    printf("\n");
    printf("1   =>  Add\n");
    printf("2   =>  Subtract\n");
    printf("3   =>  Multiply\n");
    printf("4   =>  Divide\n");
    printf("0   =>  Quit\n");
    printf("##################\n");
    printf("\n");
    printf("Choice: ");
    scanf("%d", &cmd);

        if (cmd == 0)
        {
        printf("\n");
        printf("Bye!\n");
        return (0);
        }
        else if (cmd == 1)
        {
        printf("\n");
        printf("Addition function: +\n");
        printf("\n");
        printf("First number to add: ");
        scanf("%d", &number1);
        printf("Second number to add: ");
        scanf("%d", &number2);
        result = number1 + number2;
        printf("Result: %d\n", result);
        printf("\n");
        }
        else if (cmd == 2)
        {
        printf("\n");
        printf("Subtraction function: -\n");
        printf("\n");
        printf("First number to subtract: ");
        scanf("%d", &number1);
        printf("Second number to subtract: ");
        scanf("%d", &number2);
        result = number1 - number2;
        printf("Result: %d\n", result);
        printf("\n");
        }
        else if (cmd == 3)
        {
        printf("\n");
        printf("Multiplication function: X\n");
        printf("\n");
        printf("First number to multiplie: ");
        scanf("%d", &number1);
        printf("Second number to multiplie: ");
        scanf("%d", &number2);
        result = number1 * number2;
        printf("Result: %d\n", result);
        printf("\n");
        }
        else if (cmd == 4)
        {
        printf("\n");
        printf("Division function: /\n");
        printf("\n");
        printf("First number to divise: ");
        scanf("%d", &number1);
        printf("Second number to divise: ");
        scanf("%d", &number2);
            if (number2 == 0)
            {
            printf("Error: division by zero\n");
            printf("\n");
            }
            else
            {
            restDiv = number1 % number2;
            }
            if (restDiv == 0)
            {
            result = number1 / number2;
            printf("Result: %d\n", result);
            printf("\n");
            }
            else
            {
            num1 = (float)number1;
            num2 = (float)number2;
            resultDiv = num1 / num2;
            printf("Result: %.1f\n", resultDiv);
            printf("\n");
            }
        }
        else
        {
        printf("Invalid choice");
        printf("\n");
        }
    } while (cmd != 0);
    return (0);
}
