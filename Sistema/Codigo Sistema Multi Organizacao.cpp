//============================================================================================================================================================================
// bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //Aceitar palavras no padr�o portugu�s-brasileiro com acentos
#include <string.h>
//============================================================================================================================================================================

int main(){
//============================================================================================================================================================================
//Vari�veis; Declara��o de fun��es
	int opcao;

	setlocale(LC_ALL, "Portuguese"); //Aceitar palavras no padr�o portugu�s-brasileiro com acentos

	void cabecalho();
//============================================================================================================================================================================
//Layout Principal

	do{
		cabecalho();
        printf("\nSeja Bem-Vindo ao Multi-Organiza��o!");
        printf("\nO que deseja fazer?");
        printf("\n[1]-Cadastro de Livros");
        printf("\n[2]-Cadrastro de Bibliotec�rios ou Volunt�rios");
        printf("\n[3]-Bibliotec�rios e Volunt�rios da Biblioteca");
        printf("\n[4]-Lista de Livros");
        printf("\n[5]-Lista de Livros Emprestados");
        printf("\n[6]-Buscar Livro");
        printf("\n[7]-Outras Ferramentas");
        printf("\n[0]-Sair do Sistema Multi-Organiza��o");
        printf("\nDigite sua op��o: ");
		scanf("%d", &opcao); system("cls");
	
	}while(opcao != 0);
	
	system("pause");
	return 0;
}

//============================================================================================================================================================================
//fun��o cabe�alho
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

