#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct{
        char nome[30];
        char senha[30];
        char solicitado[30];
        char senha_digitada[30];

}Tusuario;

Tusuario usuario;

typedef struct{
    Tusuario usuarios_cadastrados[50];
    int users;
}Tcadastro;




void cadastro_de_usuario(Tcadastro *cadastro){
    int i;

    FILE *pont_aqr;
    pont_aqr = fopen("usuarios.cadastrados.txt", "w");

    if(pont_aqr == NULL ){
        printf("Erro na abertura");
    }

    setbuf(stdin, NULL);
    printf("Digite seu nome de usuario:\n");
    scanf("%s", cadastro->usuarios_cadastrados[cadastro->users].nome);
    setbuf(stdin, NULL);
    printf("Digite seu numero de senha:");
    scanf("%s", cadastro->usuarios_cadastrados[cadastro->users].senha);
    cadastro->users++;
    setbuf(stdin, NULL);


    fprintf(pont_aqr,"%d\n",cadastro->users);

    for(i=0; i < cadastro->users; i++){

        fprintf(pont_aqr,"%s\n", cadastro->usuarios_cadastrados[i].nome);
        fprintf(pont_aqr,"%s\n", cadastro->usuarios_cadastrados[i].senha);
    }

    fclose(pont_aqr);
}
void cadastro_load(Tcadastro *cadastro){
    int i;

    FILE *pont_aqr;
    pont_aqr = fopen("usuarios.cadastrados.txt", "r");

    if(pont_aqr == NULL ){
        printf("Erro na abertura");
    }

    else{
        fscanf(pont_aqr,"%d", &cadastro->users);

        for( i=0 ; i <cadastro->users; i++ ){
            fscanf(pont_aqr,"%s", cadastro->usuarios_cadastrados[i].nome);
            fscanf(pont_aqr,"%s", cadastro->usuarios_cadastrados[i].senha);
        }

    }


}

void editar_usuario(Tcadastro *cadastro){
    int i;
    int Susuario =-1;
    
    FILE *pont_aqr;
    pont_aqr = fopen("usuarios.cadastrados.txt","r");
    
    if(pont_aqr == NULL ){
        printf("Erro na abertura");
    }
    else{
        
    }

    }

    fclose(pont_aqr);
}


void loguin_usuario(Tcadastro *cadastro){
    int i;
    int Susuario =-1;

    printf("Em qual usurio voce deseja logar?");
    scanf("%s",usuario.solicitado);
    printf("Digite sua senha:");
    scanf("%s", usuario.senha_digitada);
    for(i=0 ; i < cadastro->users; i++){
        if(strcmp(usuario.solicitado, cadastro->usuarios_cadastrados[i].nome)==0){
            Susuario = i;

        break;
        }
    }
        if(Susuario==-1){
            printf("Usuario nao cadastrado!\n");
        }
        else{
            if(strcmp(usuario.senha_digitada,cadastro->usuarios_cadastrados[Susuario].senha)==0){
                printf("Usuario logado\n");
            }
            else{
                printf("Senha incorreta\n");
            }
        }
}


int main(){

    Tcadastro *cadastro;
    cadastro = (Tcadastro*)malloc(sizeof(Tcadastro));

    cadastro->users=0;

    int menu = 1;
    int escolha;
    int i, j;

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
                editar_usuario();

            break;
            
            case 3:
                loguin_usuario(cadastro);

            break;
        
            case 4:

                menu=0;

            break;
            

        }

    }
  return 0;
}