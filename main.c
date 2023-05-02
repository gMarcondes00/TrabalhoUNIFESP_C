#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//Definir estrutura para todos os livros
struct Livro
{
    int disponivel;
    int vendido;
    int id; //Código do Livro
    float valor;
    char descricao[200];
};

struct Livro Matematica;
struct Livro Probabilidade;
struct Livro Fisica;
struct Livro Quimica;
struct Livro Computacao;

//2) Mostrar a descrição da categoria
void desc(int id) {
    //Path Matematica
    FILE *descMat = fopen("matematica.txt", "r");
    fgets(Matematica.descricao, 200, descMat);
    fclose(descMat);
    //Path Probabilidade e estatistica
    FILE *descProb = fopen("probabilidade.txt", "r");
    fgets(Probabilidade.descricao, 200, descProb);
    fclose(descProb);
    //Path Fisica
    FILE *descFis = fopen("fisica.txt", "r");
    fgets(Fisica.descricao, 200, descFis);
    fclose(descFis);
    //Path Quimica
    FILE *descQuim = fopen("quimica.txt", "r");
    fgets(Quimica.descricao, 200, descQuim);
    fclose(descQuim);
    //Path Computação
    FILE *descComp = fopen("computacao.txt", "r");
    fgets(Computacao.descricao, 200, descComp);
    fclose(descComp);

    switch (id){
        case 1:
            printf("\n%s\n",Matematica.descricao);
            break;
        case 2:
            printf("\n%s\n",Probabilidade.descricao);
            break;
        case 3:
            printf("\n%s\n",Fisica.descricao);
            break;
        case 4:
            printf("\n%s\n",Quimica.descricao);
            break;
        case 5:
            printf("\n%s\n",Computacao.descricao);
            break;

        default:
            printf("Codigo nao cadastrado!\n");
            break;
    }
    //Caso queira outra descrição
    char voltar[4];int idInput2;
    printf("\nGostaria de ver outra descricao?\n");
    scanf("%s",voltar);
    if(!strcmp(voltar, "sim") || !strcmp(voltar, "Sim") || !strcmp(voltar, "SIM")){
        printf("Qual descricao?");
        scanf("%d", &idInput2);
        desc(idInput2);
    } 
}

int main() {
    //Definir Livro de Matematica
    Matematica.disponivel = 5;
    Matematica.vendido = 5;
    Matematica.id = 1;
    Matematica.valor = 150.00;
    
    //Definir Livro de Probabilidade e Estatistica
    Probabilidade.disponivel = 10;
    Probabilidade.vendido = 0;
    Probabilidade.id = 2;
    Probabilidade.valor = 100.00;

    //Definir Livro de Fisica
    Fisica.disponivel = 8;
    Fisica.vendido = 2;
    Fisica.id = 3;
    Fisica.valor = 160.00;

    //Definir Livro de Quimica
    Quimica.disponivel = 7;
    Quimica.vendido = 3;
    Quimica.id = 4;
    Quimica.valor = 160.00;

    //Definir Livro de Computação
    Computacao.disponivel = 1;
    Computacao.vendido = 9;
    Computacao.id = 5;
    Computacao.valor = 200.00;

    //5)Mantenha o programa em loop
    char voltar[4];
    bool ficar = true;

    while(ficar){
        //1) Mostrar total de unidades e valor de cada categoria
        printf("Listagem de livros:\n");
        printf("---------------------------- Disponivel --- Vendido --- Codigo --- Valor\n");

        printf("Matematica:                      %d             %d        %d      R$%.2f\n", Matematica.disponivel, Matematica.vendido, Matematica.id, Matematica.valor);
        printf("Probabilidade e Estatistica:     %d            %d        %d      R$%.2f\n", Probabilidade.disponivel, Probabilidade.vendido, Probabilidade.id, Probabilidade.valor);
        printf("Fisica:                          %d             %d        %d      R$%.2f\n", Fisica.disponivel, Fisica.vendido, Fisica.id, Fisica.valor);
        printf("Quimica:                         %d             %d        %d      R$%.2f\n", Quimica.disponivel, Quimica.vendido, Quimica.id, Quimica.valor);
        printf("Computacao:                      %d             %d        %d      R$%.2f\n\n", Computacao.disponivel, Computacao.vendido, Computacao.id, Computacao.valor);
        
        //Pegar o assunto do livro desejado
        int idInput;
        printf("\nTendo a tabela em vista, selecione a descricao do assunto do livro que gostaria com base no Codigo:\n");
        scanf("%d", &idInput);
        desc(idInput);
        
        //Iniciar processo de compra
        int entrarCompra;int idCompra; bool comprar = false; float valorDaCompra; int carrinho = 0;

        printf("\nGostaria de entrar na compra? 1 ou 0\n");
        scanf("%d", &entrarCompra);
        if(entrarCompra == 1){
            comprar = true;
        } 
        //3)Comprar livros
        while (comprar){
            printf("\nQual livro gostaria de comprar? Para finalizar a compra, digite 0!\n");
            scanf("%d", &idCompra);
            if((idCompra == Matematica.id && Matematica.disponivel <= 0) ||
               (idCompra == Quimica.id && Quimica.disponivel <= 0) ||
               (idCompra == Fisica.id && Fisica.disponivel <= 0) ||
               (idCompra == Probabilidade.id && Probabilidade.disponivel <= 0) ||
               (idCompra == Computacao.id && Computacao.disponivel <= 0)){
                printf("O livro referente ao codigo: %d nao esta disponivel\n", idCompra);
                comprar = false;
                break;
            }

            switch (idCompra){
                case 0:
                    comprar = false;
                    break;
                case 1:
                    carrinho += 1;
                    printf("\n%d item(s) no carrinho\n", carrinho);
                    Matematica.disponivel -= 1;
                    Matematica.vendido += 1;
                    valorDaCompra += 150.00;
                    printf("%d Livros disponiveis de Matematica\n", Matematica.disponivel);
                    break;
                case 2:
                    carrinho += 1;
                    printf("\n%d item(s) no carrinho\n", carrinho);
                    Probabilidade.disponivel -= 1;
                    Probabilidade.vendido += 1;
                    valorDaCompra += 100.00;
                    printf("%d Livros disponiveis de Probabilidade e Estatistica\n", Probabilidade.disponivel);
                    break;
                case 3:
                    carrinho += 1;
                    printf("\n%d item(s) no carrinho\n", carrinho);
                    Fisica.disponivel -= 1;
                    Fisica.vendido += 1;
                    valorDaCompra += 160.00;
                    printf("%d Livros disponiveis de Fisica\n", Fisica.disponivel);
                    break;
                case 4:
                    carrinho += 1;
                    printf("\n%d item(s) no carrinho\n", carrinho);
                    Quimica.disponivel -= 1;
                    Quimica.vendido += 1;
                    valorDaCompra += 160.00;
                    printf("%d Livros disponiveis de Quimica\n", Quimica.disponivel);
                    break;
                case 5:
                    carrinho += 1;
                    printf("\n%d item(s) no carrinho\n", carrinho);
                    Computacao.disponivel -= 1;
                    Computacao.vendido += 1;
                    valorDaCompra += 200.00;
                    printf("%d Livros disponiveis de Computacao\n", Computacao.disponivel);
                    break;
                
                default:
                    printf("Selecione um valor valido!");
                    break;
        }}
        // Encerrar loop
        printf("\nGostaria de sair das compras?\n");
        scanf("%s", voltar); 
        if(!strcmp(voltar, "sim") || !strcmp(voltar, "Sim") || !strcmp(voltar, "SIM")){
            ficar = false;
            break;
        }
            //4)Total vendido e montante em caixa
            int senha;
            printf("Forneca a senha para ter acesso ao caixa\n");
            scanf("%d", &senha);
            if(senha == 123){
                printf("\n\n%d item(s) vendidos, com valor atual em caixa de: R$%.2f\n\n", carrinho, valorDaCompra);
            } else {
                printf("\n\nSenha incorreta!\n\n");
            }
    }
    return 0;
}