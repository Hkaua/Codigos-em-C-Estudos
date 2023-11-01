#include <stdio.h>

int main()
{
    double num1, num2, num3, divisor, result;
    
    printf("coloque o primeiro Número: ");
    scanf("%lf",&num1);
    
    printf("coloque o segundo Número: ");
    scanf("%lf",&num2);
    
    printf("coloque o terceiro Número: ");
    scanf("%lf",&num3);
    
    printf("vamos dividir por que Número: ");
    scanf("%lf",&divisor);
    
    result = num1 + num2 + num3;
    
    if (divisor != 0) {
        result = result / divisor;
        printf ("O resultado é: (%.2lf + %.2lf + %.2lf) / %.2lf is %.2lf\n", num1, num2, num3, divisor, result);
    } else {
        printf ("error: A divisão por zero não é permitida.\n");
    }
    
    return 0;
    
}