#include <stdio.h>
#include <stdlib.h>
#include "Dorso.h"

int main()
{
    int opcion, flagA=0, flagB=0;
    float rdo, num1, num2;
    char seguir = 's';

    do
     {
         system("cls");
         printf("\tTrabajo Practico n1. Calculadora || Juan Martin Dorso\n\n");
         printf("1. Ingrese Primer Numero(A=x): \n");
         printf("2. Ingrese Segundo Numero(B=y): \n");
         printf("3. Suma(A+B): \n");
         printf("4. Resta(A-B): \n");
         printf("5. Division(A/B): \n");
         printf("6. Multiplicacion(A*B): \n");
         printf("7. Calcular el Factorial(A!)\n");
         printf("8. Calcular todas las operaciones\n");
         printf("9. Salir\n\n");
         printf("Los numeros que fueron ingresados son los siguientes: A=%.2f y B=%.2f\n\n",num1,num2);
         printf("Ingrese opcion: ");
         scanf("%d", &opcion);

         while(!validarRangoInt(opcion,1,9))
         {
         printf("\nError! Reingrese opcion: ");
         scanf("%d", &opcion);
         }

         switch(opcion)
        {
            case 1:
                    printf("Ingrese primer numero: ");
                    scanf("%f", &num1);
                    flagA=1;
                    break;
            case 2:
                    printf("Ingrese segundo numero: ");
                    scanf("%f", &num2);
                    flagB=1;
                    break;
            case 3:
                    if(flagA==0||flagB==0)
                        {
                        printf("\nFalta Ingresar algun numero\n\n");
                        }
                    else
                        {
                        rdo=suma(num1, num2);
                        printf("\nEl resultado de la suma es de: %.2f\n\n", rdo);
                        }
                    break;
            case 4:
                    if(flagA==0||flagB==0)
                        {
                        printf("\nFalta Ingresar algun numero\n\n");
                        }
                    else
                        {
                        rdo=resta(num1, num2);
                        printf("\nEl resultado de la resta es de: %.2f\n\n", rdo);
                        }
                    break;
            case 5:
                    if(flagA==0||flagB==0)
                        {
                        printf("\nFalta Ingresar algun numero\n\n");
                        }
                    else if(num2==0 && seguir!='n')
                        {
                        printf("\nMath Error! Imposible dividir por 0.\n\n");
                        }

                    else
                        {
                        rdo=division(num1, num2);
                        printf("\nEl resultado de la division es de: %.2f\n\n", rdo);
                        }
                    break;
            case 6:
                    if(flagA==0||flagB==0)
                        {
                        printf("\nFalta Ingresar algun numero\n\n");
                        }
                    else
                        {
                        rdo=multiplicacion(num1, num2);
                        printf("\nEl resultado de la multiplicacion es de: %.2f\n\n", rdo);
                        }
                    break;
            case 7:
                    if(flagA==0||flagB==0||!validarPositivo(num1))
                        {
                        printf("\nFalta Ingresar algun numero o num1 (%.f) no es positivo\n\n", num1);
                        }
                    else if(num1>34)
                        {
                        printf("\nEl numero resultante del factorial de %.f! desborda el sistema, imposible realizar.\n\n", num1);
                        }
                    else
                        {
                        rdo=factorial(num1);
                        printf("\nEl %.f! tiene como resultado: %.2f\n\n", num1, rdo);
                        }
                    break;
//NOTA: EN CASO DE SER UN NUMERO CON COMA EL INGRESADO EN num1, EL RESULTADO DEL FACTORIAL ES EL ANTERIOR.
//EJ: SI EL NUMERO ES 5.99, REALIZA FACTORIAL DE 5! (ES DECIR 120) Y NO DE 6!, AUNQUE EN PANTALLA REDONDEA A 6!
//SI EN LA FUNCION FACTORIAL EN VEZ DE INGRESAR UN INT COMO PARAMETRO, INGRESO UN FLOAT, SE ROMPE EL PROGRAMA
//POR ESO DECIDI DEJARLO ASI Y ACLARAR LO SUCEDIDO.
            case 8:
                    if(flagA==0||flagB==0)
                        {
                        printf("\nFalta Ingresar algun numero\n\n");
                        }
                    else
                        {
                        rdo=suma(num1, num2);
                        printf("\nEl resultado de la suma es de: %.2f\n", rdo);

                        rdo=resta(num1, num2);
                        printf("\nEl resultado de la resta es de: %.2f\n", rdo);

                        if(num2==0 && seguir!='n')
                            {
                            printf("\nMath Error! Imposible dividir por 0.\n");
                            }
                        else
                            {
                            rdo=division(num1, num2);
                            printf("\nEl resultado de la division es de: %.2f\n", rdo);
                            }

                        rdo=multiplicacion(num1, num2);
                        printf("\nEl resultado de la multiplicacion es de: %.2f\n", rdo);

                       if(num1>34)
                            {
                            printf("\nEl numero resultante del factorial de %.f! desborda el sistema, imposible realizar.\n\n", num1);
                            }
                        else if(!validarPositivo(num1))
                            {
                            printf("\nFalta Ingresar algun numero o num1 (%.f) no es positivo\n\n", num1);
                            }
                        else
                            {
                            rdo=factorial(num1);
                            printf("\nEl %.f! tiene como resultado: %.2f\n\n", num1, rdo);
                            }
                        }
                    break;
            case 9:
                    seguir='n';
                    break;
        }
        system("pause");
    }while(seguir=='s');

return 0;
}
