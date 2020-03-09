#ifndef USUARIO_H
#define USUARIO_H
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"cadastro.h"
#include"usuario.h"


typedef struct{

        char nome[30];
        char ip[30];

}Tcontato;


typedef struct{

        char nome[30];
        char senha[30];
        Tcontato contato[30];
        int numeros_contatos;

}Tusuario;

typedef struct{

    Tusuario usuarios_cadastrados[50];

    int users;
    
}Tcadastro;


void loguin_usuario(Tcadastro *cadastro, int escolha);
void usuario_load(Tcadastro *cadastro, int Susuario);
void usuario_contato_cadastro(Tcadastro *cadastro, int Susuario);
void cadastro_load(Tcadastro *cadastro);
void cadastro_de_usuario(Tcadastro *cadastro);
void editar_cadastro(Tcadastro *cadastro, int escolha);
char solicitado[30];
char senha_digitada[30];

#endif