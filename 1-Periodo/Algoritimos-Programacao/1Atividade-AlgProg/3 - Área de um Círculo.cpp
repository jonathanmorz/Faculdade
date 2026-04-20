//Unigranrio Afya, ciências da computação, 1 semestre
//Desafio 3 - Área de um Círculo
#include <iostream>
using namespace std;

int main (){
    //Variável
    float raio;

    //Captação de dado
    printf("Qual o raio do circulo medido por João? ");
    cin >> raio;

    //Resultado
    printf("A área do circulo e %.1f\n", 3.14 * (raio * raio)); // ná questão ta sem únidade de medida
    return 0;
}