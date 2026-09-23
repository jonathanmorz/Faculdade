#include <iostream>
int fibonacci(int n){
    if (n <= 1){
        return n;
    }else{
        return fibonacci(n - 1) + fibonacci(n - 2);
}}
// Exemplo de uso em finanças:
// Valor de aporte seguindo a sequência de Fibonacci
int periodos = 8;
int valor_base = 100; // valor multiplicador em reais
int main(){
    for (int i = 0; i < periodos; i++){
        float aporte = fibonacci(i + 1) * valor_base;
        printf("Periodo %i: R$ %.2f\n", (i + 1), aporte);
}}