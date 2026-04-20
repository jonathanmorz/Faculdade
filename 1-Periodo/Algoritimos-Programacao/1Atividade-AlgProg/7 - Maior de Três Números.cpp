//Unigranrio Afya, ciências da computação, 1 semestre
//Desafio 7 - Maior de Três Números
#include <iostream>
#include <algorithm>
using namespace std;

int main (){
    //Variáveis
    float valor1;
    float valor2;
    float valor3;

    //Captação de dados
    printf("Primeiro valor de medicao: ");
    cin >> valor1;
    printf("Segundo valor de medicao: ");
    cin >> valor2;
    printf("Terceiro valor de medicao: ");
    cin >> valor3;

    //Resultado
    printf("O maior numero e o %.1f\n", max({valor1,valor2,valor3}));
    return 0;
}