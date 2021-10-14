#include <stdio.h>
#include <stdlib.h>

int notas(int value, float nota)
{
    printf("%d nota(s) de R$ %.2f\n", value / (int) nota, nota);
    return value % (int) nota;
}

float moedas(float value, float cents)
{
    printf("%d moeda(s) de R$ %.2f\n", (int)(value / cents), cents);
    return ((value / cents) - (int)(value / cents)) / (1 / cents);
}

int main()
{
    float cents, nota;
    int reais, i;
    scanf("%f", &cents);
    reais = (int) cents;
    cents -= reais;
    
    printf("NOTAS:\n");
    nota = 100;
    reais = notas(reais, nota);
    nota = 50;
    reais = notas(reais, nota);
    nota = 20;
    reais = notas(reais, nota);
    nota = 10;
    reais = notas(reais, nota);
    nota = 5;
    reais = notas(reais, nota);
    nota = 2;
    reais = notas(reais, nota);
    printf("MOEDAS:\n");
    nota = 1;
    moedas(reais, nota);
    nota = .50;
    cents = moedas(cents + 0.001, nota);
    nota = .25;
    cents = moedas(cents + 0.001, nota);
    nota = .10;
    cents = moedas(cents + 0.001, nota);
    nota = .05;
    cents = moedas(cents + 0.001, nota);
    nota = .01;
    cents = moedas(cents + 0.001, nota);
    return 0;
}