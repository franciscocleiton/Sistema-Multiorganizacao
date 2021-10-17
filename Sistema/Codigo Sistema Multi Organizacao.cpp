//============================================================================================================================================================================
// bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //Aceitar palavras no padrão português-brasileiro com acentos
#include <string.h>
//============================================================================================================================================================================

int main(){
//============================================================================================================================================================================
//Variáveis; Declaração de funções
	int opcao;

	setlocale(LC_ALL, "Portuguese"); //Aceitar palavras no padrão português-brasileiro com acentos

	void cabecalho();
//============================================================================================================================================================================
//Layout Principal

	do{
		cabecalho();
        printf("\nSeja Bem-Vindo ao Multi-Organização!");
        printf("\nO que deseja fazer?");
        printf("\n[1]-Cadastro de Livros");
        printf("\n[2]-Cadrastro de Bibliotecários ou Voluntários");
        printf("\n[3]-Bibliotecários e Voluntários da Biblioteca");
        printf("\n[4]-Lista de Livros");
        printf("\n[5]-Lista de Livros Emprestados");
        printf("\n[6]-Buscar Livro");
        printf("\n[7]-Outras Ferramentas");
        printf("\n[0]-Sair do Sistema Multi-Organização");
        printf("\nDigite sua opção: ");
		scanf("%d", &opcao); system("cls");
	
	}while(opcao != 0);
	
	system("pause");
	return 0;
}

//============================================================================================================================================================================
//função cabeçalho
void cabecalho(){
	system("cls");
	printf("  _ _ _        _ _ _     __         __    __     _ _ _ _ _ _ _ _ __    __  \n");
	printf("|   _  \\      /  _   |  |  |       |  |  |  |   |_ _ _ _    _ _ _ _|  |  | \n");
	printf("|  | \\  \\    /  / |  |  |  |       |  |  |  |           |  |          |  | \n");
	printf("|  |  \\  \\  /  /  |  |  |  |       |  |  |  |           |  |          |  | \n");
	printf("|  |   \\  \\/  /   |  |  |  |       |  |  |  |           |  |          |  | \n");
	printf("|  |    \\    /    |  |  |  |       |  |  |  |           |  |          |  | \n");
	printf("|  |     \\__/     |  |  |  |       |  |  |  |           |  |          |  | \n");
	printf("|  |              |  |  |  |_ _ _ _|  |  |  |_ _ _ __   |  |          |  | \n");
	printf("|__|              |__|  |_ _ _ _ _ _ _|  |_ _ _ _ _ _|  |__|          |__| \n");
	printf("___________________________________________________________________________\n");	
}

