#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 8
#define N 10

void limpaTela();
void pressEnter();
int criar_conj(int qtdConj);
int busca_seq(int v[],int chave);
void inserir_dados(int qtdConj,int matriz[][N]);
int remove_conj(int qtdConj,int matriz[][N]);
int uniao_conj(int qtdConj,int matriz[][N]);
int qtdCol(int matriz[],int lin);
int intersec_conj(int qtdConj, int matriz[][N]);
void print_conj(int qtdConj, int matriz[][N]);
void print_all_conj(int qtdConj, int matriz[][N]);
void busca_conj(int qtdConj, int matriz[][N]);

int main(int argc, char *argv[]){

    int opcao=0,qtdConj=0,matriz[M][N] = {0},i,j;
    limpaTela();
    printf("\n\tBem vindo ao trabalho de LPG:\n\n\tGerenciamento de conjuntos!\n\n");
    printf("Aperte enter para continuar...\n");
    getchar();
    limpaTela();

    do{
        
        for(int i =0;i<M;i++){
            for(int j =0 ; j< N;j++){
                printf("%d ",matriz[i][j]);
            }
            printf("\n");
        }
        printf("%d\n",qtdConj);

        printf("Escolha uma opcao:\n\n");
        printf("1 - Criar conjunto vazio\n");
        printf("2 - Inserir dados\n");
        printf("3 - Remover conjunto\n");
        printf("4 - Uniao de dois conjuntos\n");
        printf("5 - Interseccao de dois conjuntos\n");
        printf("6 - Imprimir conjunto\n");
        printf("7 - Imprimir todos os conjuntos\n");
        printf("8 - Buscar elemento em conjunto\n");
        printf("9 - Sair\n");
        scanf(" %d", &opcao);

        switch(opcao){

            case 1:
                limpaTela();
                if(criar_conj(qtdConj)){
                    qtdConj++;
                }
                break;
            
            case 2:
                limpaTela();
                if(qtdConj > 0){
                    inserir_dados(qtdConj,matriz);
                }
                else{
                    limpaTela();
                    printf("Nenhum conjunto criado ainda!\n\n");
                    pressEnter();
                }
                break;
            case 3:
                limpaTela();
                if(qtdConj > 0){
                    if(remove_conj(qtdConj,matriz)){
                        qtdConj--;
                    
                    }
                }
                else{
                    limpaTela();
                    printf("Nenhum conjunto criado ainda!\n\n");
                    pressEnter();
                }
                break;
            case 4:
                limpaTela();
                if(qtdConj >= M){
                    printf("Erro: Quantidade maxima de conjuntos atingida: (%d)\nImpossivel fazer uniao.\n\n",M);
                    pressEnter();
                    break;
                }
                if(qtdConj > 1){
                    if(uniao_conj(qtdConj,matriz)){
                        qtdConj++;
                    }
                }
                else{
                    limpaTela();
                    printf("Nao ha conjuntos suficientes para uniao!\n\n");
                    pressEnter();
                }
                break;
            case 5:
                limpaTela();
                if(qtdConj >= M){
                    printf("Erro: Quantidade maxima de conjuntos atingida: (%d)\nImpossivel fazer intersecao.\n\n",M);
                    pressEnter();
                    break;
                }
                if(qtdConj > 1){
                    if(intersec_conj(qtdConj,matriz)){
                        qtdConj++;
                    }
                }
                else{
                    limpaTela();
                    printf("Nao ha conjuntos suficientes para intersecao!\n\n");
                    pressEnter();
                }
                break;
            case 6:
                limpaTela();
                print_conj(qtdConj, matriz);
                break;
            case 7:
                limpaTela();
                print_all_conj(qtdConj, matriz);
                break;
            case 8:
                limpaTela();
                busca_conj(qtdConj, matriz);
                break;

            default:
                if(opcao == 9){
                    limpaTela();
                    printf("Ate mais! :D\n");
                    return 0;
                }
                limpaTela();
                printf("Opcao invalida\n");
                printf("Aperte enter para continuar...\n");
                getchar();
                getchar();
                limpaTela();
                break;
        }

    }while(opcao != 9);

    return 0;
}

void pressEnter(){
    printf("Aperte enter para continuar...\n");
    getchar();
    getchar();
    limpaTela();
}

void limpaTela(){
    printf("\033[H\033[J"); 
}

int criar_conj(int qtdConj){
    if(qtdConj < M){
        printf("Conjunto criado com sucesso!\n");
        printf("Quantidade atual: %d\n\n",qtdConj+1);
        pressEnter();
        return 1;
    }
    else{
        printf("Quantidade maxima de conjuntos atingida! (%d)\n\n",M);
        pressEnter();
        return 0;
    }
}

int busca_seq(int v[],int chave){
    for(int i=0;i<N;i++){
        if(chave==v[i]){
            return 1;
        }
    }
    return 0;
} 

void inserir_dados(int qtdConj,int matriz[][N]){
    int lin=0,numCol=0,valor=-1;
    printf("Indice i do conjunto desejado? (0 a %d)\n",qtdConj-1);
    scanf("%d",&lin);

    if(lin < 0 || lin >= qtdConj){
        limpaTela();
        printf("Indice invalido! :(\nInsira um indice de 0 a %d\n\n",qtdConj-1);
        pressEnter();
    }
    // if(matriz[lin][0]!=0){
    //     limpaTela();
    //     printf("Conjunto ja possui elementos, impossivel sobreescrever!\n\n");
    //     pressEnter();
    // }
    else{
        for(numCol=0;matriz[lin][numCol] != 0;numCol++){}
        while(numCol != N){
            printf("Valor na coluna %d?\n",numCol);
            scanf("%d",&valor);
            if(valor == 0){
                limpaTela();
                printf("Insercao finalizada! :)\n\n");
                pressEnter();   
                break;
            }
            else{
                if(busca_seq(matriz[lin],valor)){
                    limpaTela();
                    printf("Valor ja inserido, tente novamente!\n");
                    pressEnter();
                }
                else{
                    matriz[lin][numCol] = valor;
                    numCol++;
                }
            }
        }
        if(numCol==N){
            limpaTela();
            printf("Insercao finalizada! :)\n\n");
            pressEnter();
        }

    }
}

int remove_conj(int qtdConj,int matriz[][N]){
    int lin=0;
    printf("Indice i do conjunto desejado? (0 a %d)\n",qtdConj-1);
    scanf("%d",&lin);
    if(lin < 0 || lin >= qtdConj){
        limpaTela();
        printf("Indice invalido! :(\nInsira um indice de 0 a %d\n\n",qtdConj-1);
        pressEnter();
        return 0;
    }
    else{
        for(lin;lin<qtdConj;lin++){
            if(lin==qtdConj-1){
                for(int i = 0;i<N;i++){
                    matriz[lin][i] = 0;
                }
            }
            else{
                for(int i = 0;i<N;i++){
                    matriz[lin][i] = matriz[lin+1][i];
                }
            }
        }
        limpaTela();
        printf("Conjunto removido com sucesso!\n\n");
        pressEnter();
        return 1;
    }    
}

int qtdCol(int matriz[],int lin){
    int i=0;
    while(matriz[i] != 0){
        i++;
    }
    return i;
}

int uniao_conj(int qtdConj,int matriz[][N]){
    int i=0,j=0,k=0,lastConj=qtdConj,conj1=0,conj2=0;
    printf("Indices dos conjuntos a serem unidos? 0 a %d \n",qtdConj-1);
    scanf("%d %d",&conj1,&conj2);
    if(conj1 < 0 || conj1 >= qtdConj || conj2 < 0 || conj2 >= qtdConj){
        limpaTela();
        printf("Indice invalido! :(\nInsira um indice de 0 a %d\n\n",qtdConj-1);
        pressEnter();
        return 0;
    }
    else if(qtdCol(matriz[conj1],conj1) + qtdCol(matriz[conj2],conj2) > N){
        limpaTela();
        printf("Erro: Quantidade de elementos maior que o permitido!\nImpossivel fazer uniao.\n\n");
        pressEnter();
        return 0;
    }
    else{
        for(k ;k < N && matriz[conj1][k] != 0;k++){
            matriz[lastConj][k] = matriz[conj1][k];
        }
        int p = k;
        for(int i=0 ;i < N && matriz[conj2][i] != 0;i++){
            if(!busca_seq(matriz[lastConj],matriz[conj2][i])){
                matriz[lastConj][k] = matriz[conj2][i];
                k++;
            }
        }
        limpaTela();
        printf("Uniao realizada com sucesso!\n\n");
        pressEnter();
        return 1;
   }
}

void print_conj(int qtdConj, int matriz[][N]){

    limpaTela();

    int indice;

    printf("Informe o índice do conjunto que deseja (0 a %i): \n", qtdConj - 1);
    scanf("%i", &indice);
    printf("\nConjunto %i = ", indice);

    for(int j = 0; matriz[indice][j] != '\0' && j < N; j++){
        printf("%i ", matriz[indice][j]);
    }

    printf("\n");
    pressEnter();

    

}

void print_all_conj(int qtdConj, int matriz[][N]){

    limpaTela();

    printf("Temos %i conjunto(s):\n", qtdConj);

    for(int i = 0; i < qtdConj; i++){
        if(matriz[i][0] == 0){
            printf("Conjunto %i = vazio", i);
        }else{
            printf("Conjunto %i = ", i);
            for(int j = 0; j < N && matriz[i][j] != '\0'; j++){
                printf("%i ", matriz[i][j]);
            }
        }
        printf("\n");
    }

    printf("\n");
    pressEnter();
}

void busca_conj(int qtdConj, int matriz[][N]){

    limpaTela();

    int valor, valor_encontrado = 0;

    printf("Informe o valor a ser buscado: ");
    scanf("%i", &valor);

    limpaTela();

    printf("Conjuntos que contém o valor %i:\n", valor);

    for(int i = 0; i < qtdConj; i++){
        for(int j = 0; j < N && matriz[i][j] != '\0'; j++){    
                if(valor == matriz[i][j]){
                    printf("Conjunto %i\n", i);
                    valor_encontrado++;
                }
        }
    }

    if(valor_encontrado == 0){
        printf("Não há conjuntos que possuam o valor %i", valor);
    }

    printf("\n");
    pressEnter();

}

int intersec_conj(int qtdConj, int matriz[][N]){

    limpaTela();

    int conj1 = 0, conj2 = 0, n = 0, lastConj = qtdConj;

    printf("Informe os indices para realizar a intersecao (de 0 a %i): ", qtdConj - 1);
    scanf("%i %i", &conj1, &conj2);
    if(conj1 < 0 || conj1 >= qtdConj || conj2 < 0 || conj2 >= qtdConj){
        limpaTela();
        printf("Indice invalido! :(\nInsira um indice de 0 a %d\n\n",qtdConj-1);
        pressEnter();
        return 0;
    }else if(matriz[conj1] == 0 || matriz[conj2] == 0){
        printf("\nUm dos conjuntos esta vazio! Nao foi feita a intersecao\n");
    }else if(){

    }else{
        for(int i = 0; i < N; i++){
            //busca_seq(vetor, chave);
            if(busca_seq(matriz[conj2], matriz[conj1][i])){
                matriz[lastConj][n] = matriz[conj1][i];
                n++;
            }
        }
        if(matriz[lastConj][0] == 0){
            printf("\nNao ha elementos em comum entre os conjuntos, portanto, nao foi feita a intersecao!\n");
        }
        limpaTela();
        printf("\nIntersecao realizada com sucesso!\n");
        pressEnter();
        return 1;
    
    
    }

}
