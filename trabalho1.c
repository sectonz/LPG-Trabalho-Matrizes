#include <stdio.h>
#include <stdlib.h>

criar_conj();
inserir_dados();
remove_conj();
uniao_conj();
intersec_conj();
print_conj();
print_all_conj();
busca_conj();

int main(int argc, char *argv[]){

    int opcao;

    do{

        switch(opcao){

            case 1:

                criar_conj();

            case 2:

                inserir_dados();

            case 3:

                remove_conj();
            
            case 4:

                uniao_conj();

            case 5:

                intersec_conj();

            case 6:

                print_conj();

            case 7:

                print_all_conj();

            case 8:

                busca_conj();

            default:
            
        }

    }while(opcao != 9);

    return 0;
}