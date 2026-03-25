//Unigranrio Afya, ciências da computação, 1 semestre
//Desafio 6 - Classificação de Notas
#include <iostream>
using namespace std;

int main () {
    //Variável
    float nota;
    string conceito;

    //Captação de dado
    printf("Qual foi a nota de Maria? ");
    cin >> nota;

    //Resultado
        //Condicional
    if (nota >= 9){
        conceito = "A";
    }else if (nota >= 7){
        conceito = "B";
    }else if (nota >= 5){
        conceito = "C";
    }else if (nota >= 3){
        conceito = "D";
    }else if (nota < 3){
        conceito = "E";
    }else{
        printf("Ponha um valor valido");
    }
    cout << "O conceito de Maria e " << conceito << endl;
    return 0;
}