//Desafio 01 - Introdução a Programação

//ficou faltando corrigir bug do imc e na parte de recadastro ta pulando "o nome:" mas não deu tempo por conta do prazo

//chamando bibliotecas

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h> //biblioteca para acentuações em português (chamado dentro do main com setlocate)

typedef struct{ //função declarando uma estrutura com todas as variaveis do usuario
    
    char nome[50];
    int idade;
    char end[100];
    float peso;
    float altura;

}usuario;

void cadastro (usuario *user){ //chamando a função usuario e usando ele como ponteiro (não funcionou com . somente com ->)

    printf("Cadastro");
    printf("\nDigite seu nome completo:");
    fgets(user->nome, sizeof(user->nome), stdin); //fgets sempre espera 3 argumentos (1- o ponteiro para o destino, 2- tamanho máximo de caracteres que vai ser lido"sizeof", 3- ponteiro para o fluxo de entrada"stdin")
    printf("\nDigite sua idade:");
    scanf("%d", &user->idade);

    getchar(); //limpa linha residual da memoria e faz com com que n vá dois inputs de uma vez só esperando resp

    printf("\nDigite seu endereço:");
    fgets(user->end, sizeof(user->end), stdin);
    printf("\nSeu peso em kg:");
    scanf("%f", &user->peso);

    getchar();

    printf("\nSua altura em metros:");
    scanf("%f", &user->altura);

    printf("Cadastrado com sucesso!");

    getchar();
    
}

void imc (usuario *user){ //usuario é chamado pelo ponteiro *user
    
    float resultado; //declarado em float pois o resultado do imc na maioria das vezes é um valor quebrado.

    resultado = user->peso / user->altura * user->altura; //calculo IMC

    if(resultado <= 24){
       
       printf("\nseu IMC foi %.2f e está normal", resultado);
        
   }else if(resultado > 24 && resultado <= 29){
       
       printf("\nseu IMC foi %.2f você está Sobrepeso", resultado);
       
   }else if(resultado <= 39 && resultado > 30){
       
       printf("\nseu IMC foi %.2f você está Obeso", resultado);
       
   }else if(resultado > 40){
       
       printf("\nseu IMC foi %.2f você está gravemente obeso", resultado);
       
   }

}

int main(void){ //void da acesso a funções fora do main

    int teclas, recadastro, mudanca = 1;

    setlocale(LC_ALL, "Portuguese"); //chamando o #include <locale.h>

    usuario user; //Chamo a variável do tipo usuario chamada por user
    cadastro(&user); //chamo cadastro com user
    imc(&user); //chamo imc do user

    while(mudanca == 1){

        printf("\ndeseja alterar alguma informação de cadastro?");
        printf("\n   '1' SIM      '2' NÃO   \n");
        scanf("%d", &recadastro);

        switch (recadastro){

            case 1:
                cadastro(&user);
                imc(&user);
                mudanca = 0;
            break;

            case 2:
                mudanca = 0;
            break;
        
            default:
                printf ("\nTecla Invalida!");
            break;
        }

        getchar();
    }

    printf("\nQual Seu objetivo?\n   Pressione '1' para ganho de massa\n   Pressione '2' perca de gordura");
    scanf("%d", &teclas);

    switch (teclas){ //cria a estrutura para evitar varios if e else, assim colocando de froma pratica a multipla escolha para o cliente 

        case 1: //case com a tecla setada
            printf("dieta para ganho de massa"); //intrução da case
        break; //Força a saída
    
        case 2:
            printf("dieta para perda de gordura");
        break;

        default :
            printf ("\nTecla Invalida!");
    }

    getchar();

    return 0;

}
