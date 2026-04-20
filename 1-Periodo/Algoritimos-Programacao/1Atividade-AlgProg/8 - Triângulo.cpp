//Unigranrio Afya, ciências da computação, 1 semestre
//Desafio 8 - Triângulo
#include <iostream>
using namespace std;

int main () {
    //Variáveis
    float l1;
    float l2;
    float l3;

    //Captação de dados
    printf("Primeiro lado do triângulo: ");
    cin >> l1;
    printf("Segundo lado do triângulo: ");
    cin >> l2;
    printf("Terceiro lado do triângulo: ");
    cin >> l3;

    //Resultado
        //Condicional
    if (l1+l2<l3){
        printf("Não é um triângulo valido\n");
    }else if(l1+l3<l2){
        printf("Não é um triângulo valido\n");
    }else if(l2+l3<l1){
        printf("Não é um triângulo valido\n");
    }else{
        printf("É um triângulo valido\n");
    }
    return 0;
}