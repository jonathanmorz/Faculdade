//Unigranrio Afya, ciências da computação, 1 semestre
//Desafio 2 - Conversão de Temperatura
#include <iostream>
using namespace std;

int main () {
    //Variável
    float temperaturacelcius;

    //Captação de dado
    printf("Qual a temperatura anotada por Maria de sua cidade natal(em celsius)? ");
    cin >> temperaturacelcius;

    //Resultado
    printf("A temperatura de %.1f °C em Fahrenheit fica %.1f °F\n",temperaturacelcius, (temperaturacelcius * 9/5) + 32);
    return 0;
}