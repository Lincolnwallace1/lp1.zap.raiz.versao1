#include"usuario.h"
#include"cadastro.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void usuario_load(Tcadastro *cadastro, int Susuario){

    int i;
    char aux[30];

    strcpy(aux, cadastro->usuarios_cadastrados[Susuario].nome);

    strcat(aux,".Contato.txt");

    FILE *pont_aqr2;

    pont_aqr2 = fopen(aux, "r");

    if(pont_aqr2 == NULL ){
        printf("Erro na abertura\n");
    }
    else{
        fscanf(pont_aqr2,"%d", &cadastro->usuarios_cadastrados[Susuario].numeros_contatos);

        for( i=0 ; i < cadastro->usuarios_cadastrados[Susuario].numeros_contatos; i++ ){
            fscanf(pont_aqr2,"%s", cadastro->usuarios_cadastrados[Susuario].contato[i].nome);
            fscanf(pont_aqr2,"%s", cadastro->usuarios_cadastrados[Susuario].contato[i].ip);
        }

    }
    fclose(pont_aqr2);
}
  
void loguin_usuario(Tcadastro *cadastro, int escolha){
    int i;
    int Susuario =-1;

    printf("Em qual usuario voce deseja logar?");
    scanf("%s",solicitado);
    printf("Digite sua senha:");
    scanf("%s", senha_digitada);
    for(i=0 ; i < cadastro->users; i++){
        if(strcmp(solicitado, cadastro->usuarios_cadastrados[i].nome)==0){
            Susuario = i;

        break;
        }
    }
        if(Susuario==-1){
            printf("Usuario nao cadastrado!\n");
        }
        else{
            if(strcmp(senha_digitada, cadastro->usuarios_cadastrados[Susuario].senha)==0){
                printf("Usuario logado\n");
                printf("1 - Gerenciar contatos\n");
                printf("2 - Gerenciar grupos\n");
                printf("3 - Iniciar uma conversa\n");
                printf("4 - sair\n");
                scanf("%d",&escolha);

                switch(escolha){
                    

                    case 1:

                        usuario_load(cadastro, Susuario);

                        usuario_contato_cadastro(cadastro, Susuario);     

                    break;
                    
                    case 2:

                        printf("NAO SE FAZ GRUPO SEM THREAD!\n");

                    break;
                    
                    case 3:
                        
                    break;
                
                    case 4:

                        //menu=0;

                    break;
            }
        }
            else{
                printf("Senha incorreta\n");
            }
        }
}

void usuario_contato_cadastro(Tcadastro *cadastro, int usuario_logado){

        int i;
        int j = cadastro->usuarios_cadastrados[usuario_logado].numeros_contatos;
        FILE *pont_aqr2;

        char usuario[30]; 

        strcpy(usuario,cadastro->usuarios_cadastrados[usuario_logado].nome);

        char contato[30]=".Contato.txt";

        pont_aqr2 = fopen(strcat(usuario,contato),"w");

        if(pont_aqr2 == NULL ){
            printf("Erro na abertura");
        }

        printf("Digite seu contato:");
        scanf("%s", cadastro->usuarios_cadastrados[usuario_logado].contato[j].nome);
        printf("Digite seu ip:");
        scanf("%s", cadastro->usuarios_cadastrados[usuario_logado].contato[j].ip);
        cadastro->usuarios_cadastrados[usuario_logado].numeros_contatos++;

        fprintf(pont_aqr2,"%d\n",cadastro->usuarios_cadastrados[usuario_logado].numeros_contatos); 

        for ( i = 0; i < cadastro->usuarios_cadastrados[usuario_logado].numeros_contatos; i++){
            fprintf(pont_aqr2,"%s\n", cadastro->usuarios_cadastrados[usuario_logado].contato[i].nome);
            fprintf(pont_aqr2,"%s\n", cadastro->usuarios_cadastrados[usuario_logado].contato[i].ip);
        }
         

        fclose(pont_aqr2);
} 

void cadastro_load(Tcadastro *cadastro){

    int i;

    FILE *pont_aqr;
    pont_aqr = fopen("usuarios.cadastrados.txt", "r+");

    if(pont_aqr == NULL ){
        printf("Erro na abertura\n");
    }

    else{
        fscanf(pont_aqr,"%d", &cadastro->users);

        for( i = 0 ; i < cadastro->users; i++ ){
            cadastro->usuarios_cadastrados[i].numeros_contatos = 0 ;
            fscanf(pont_aqr,"%s", cadastro->usuarios_cadastrados[i].nome);
            fscanf(pont_aqr,"%s", cadastro->usuarios_cadastrados[i].senha);
        }

    }
    fclose(pont_aqr);
}

void cadastro_de_usuario(Tcadastro *cadastro){

        int i;
        char aux[30];

        FILE *pont_aqr;
        FILE *contato_aqr;

        pont_aqr = fopen("usuarios.cadastrados.txt", "w");

        if(pont_aqr == NULL ){
            printf("Erro na abertura");
        }

        cadastro->usuarios_cadastrados[cadastro->users].numeros_contatos = 0;

        printf("Digite seu nome de usuario:");
        scanf("%s", cadastro->usuarios_cadastrados[cadastro->users].nome);
        printf("Digite seu numero de senha:");
        scanf("%s", cadastro->usuarios_cadastrados[cadastro->users].senha);

        cadastro->users++;


        strcpy(aux, cadastro->usuarios_cadastrados[cadastro->users-1].nome);

        contato_aqr = fopen(strcat(aux,".Contato.txt"), "w");

        fprintf(pont_aqr,"%d\n",cadastro->users);  

        for(i=0; i < cadastro->users; i++){
        fprintf(pont_aqr,"%s\n", cadastro->usuarios_cadastrados[i].nome);
        fprintf(pont_aqr,"%s\n", cadastro->usuarios_cadastrados[i].senha);
    }
    
        fclose(pont_aqr);
        fclose(contato_aqr);
}


void editar_cadastro(Tcadastro *cadastro, int escolha){
    int i;
    int Susuario =-1;
    int remove;
    
    FILE *pont_aqr;
    pont_aqr = fopen("usuarios.cadastrados.txt","w");
    
    if(pont_aqr == NULL ){
        printf("Erro na abertura");
    }

    else{

        printf("Qual usuario voce deseja editar?");
        scanf("%s", solicitado);
        printf("Digite sua senha:");
        scanf("%s", senha_digitada);

        for(i=0 ; i < cadastro->users; i++){
            if(strcmp(solicitado, cadastro->usuarios_cadastrados[i].nome)==0){
                Susuario = i;
                break;
                }
        }
            if(Susuario==-1){
                printf("Usuario nao encontrado!\n");
            }

            else{
                if(strcmp(senha_digitada, cadastro->usuarios_cadastrados[Susuario].senha)==0){

                    printf("Usuario logado\n");
                    printf("Voce deseja mudar o Usuario ou a Senha?\n");
                    printf("1-Usuario\n2-Senha\n3-Excluir Cadastro\n");
                    scanf("%d",&escolha);

                    switch(escolha){

                        case 1:
                            printf("Digite seu novo Usuario:");
                            scanf("%s", solicitado);
                            strcpy(cadastro->usuarios_cadastrados[Susuario].nome, solicitado);

                        break;
                    
                        case 2:
                            printf("Digite sua nova Senha:");
                            scanf("%s",senha_digitada);
                            strcpy(cadastro->usuarios_cadastrados[Susuario].senha, senha_digitada);                    

                        break;

                        case 3:
                            printf("Digite a conta q deseja excluir:");
                            scanf("%s", solicitado);

                            for (i = 0; i < cadastro->users; i++){
                                if(strcmp(cadastro->usuarios_cadastrados[Susuario].nome, solicitado)==0){
                                    remove = Susuario;
                                }
                        
                            }
                            for (i = remove+1; i < cadastro->users; i++){ 
                                strcpy(cadastro->usuarios_cadastrados[Susuario-1].nome, cadastro->usuarios_cadastrados[Susuario].nome);
                                strcpy(cadastro->usuarios_cadastrados[Susuario-1].senha, cadastro->usuarios_cadastrados[Susuario].senha);
                            }
                            cadastro->users--;
                    }
                }
                else{
                    printf("Senha incorreta\n");
                }
            }
        }    

    fprintf(pont_aqr,"%d\n", cadastro->users);

    for( i=0 ; i < cadastro->users; i++ ){
        fprintf(pont_aqr,"%s\n", cadastro->usuarios_cadastrados[i].nome);
        fprintf(pont_aqr,"%s\n", cadastro->usuarios_cadastrados[i].senha);
    }

    fclose(pont_aqr);
}
