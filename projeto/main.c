#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"usuario.h"
#include"cadastro.h"


int main(){

    Tcadastro *cadastro;
    cadastro = (Tcadastro*)malloc(sizeof(Tcadastro));

    cadastro->users = 0;

    int menu = 1;
    int escolha;
    int i, j = 0;


    cadastro_load(cadastro);


    while(menu){
    printf("1 - Cadastrar um usuario\n");
    printf("2 - Editar um usuario\n");
    printf("3 - Loguin\n");
    printf("4 - sair\n");
    scanf("%d",&escolha);
    
        switch(escolha){

            case 1:

                cadastro_de_usuario(cadastro);     

            break;
            
            case 2:
        
                editar_cadastro(cadastro, escolha);

            break;
            
            case 3:

                loguin_usuario(cadastro, escolha);

            break;
        
            case 4:

                menu=0;

            break;
            

        }

    }
  return 0;
}