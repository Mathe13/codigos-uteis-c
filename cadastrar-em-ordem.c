//inserir valores inteiros, deve ser realizado a inserÃ§Ã£o em ordem, nao deve cadastrar se o numero ja estiver cadastrado
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	float num;
	struct nodo *ant;
	struct nodo *prox;
}listaD;

void cadastrar(listaD **inicioListaD, listaD *pListaD);
void listarIni(listaD **inicioListaD);

int main(){

	listaD *pListaD = NULL, *inicioListaD = NULL;
	int op = 1;

	while (op != 0){

        printf("\n\n\n\t\t--MENU PRINCIPAL--\n");
        printf("\t1 - Cadastrar numero \n");
        printf("\t2 - Listar do inicio\n");
        printf("\t0- Sair\n");
        printf("\n\t");
        scanf("%d", &op);

        switch (op){

            case 1:
                printf("\n\t--------------------------------------------------\n");
                cadastrar(&inicioListaD, pListaD);
                printf("\n\t--------------------------------------------------\n");
                printf("\n\t");
            break;

            case 2:
                printf("\n\t--------------------------------------------------\n");
                listarIni(&inicioListaD);
                printf("\n\t--------------------------------------------------\n");
                printf("\n\t");
            break;

        }
    }
}

void cadastrar(listaD **inicioListaD, listaD *pListaD){
	listaD *pAux, *pAux2, *pAux3;
	int num, teste=0, aux;

	pListaD = (listaD*)malloc(sizeof(listaD));

	if(pListaD){
		printf("\nDigite o numero a ser cadastrado: ");
		scanf("%d", &num);

		if(*inicioListaD == NULL){
			*inicioListaD = pListaD;
			pListaD->num = num;
			pListaD->ant = NULL;
			pListaD->prox = NULL;
		}else{
			pAux = *inicioListaD;
			while(pAux != NULL){
				if(pAux->num == num){
					printf("Numero ja cadastrado!! \n");
					teste = 1;
					break;
				}else if(pAux->num > num){
					teste = 1;
					break;
				}

				pAux = pAux->prox;
			}
			if(teste == 0){
				pAux = *inicioListaD;
				while(pAux->prox != NULL) pAux = pAux->prox;

				pListaD->ant = pAux;
				pListaD->prox = NULL;
				pListaD->num = num;
				pAux->prox =pListaD;
			}else if(pAux->num > num){
				pListaD->num = num;

				pAux2= pAux->ant;
				if(pAux2 == NULL){
					*inicioListaD = pListaD;
					pListaD->ant = NULL;
				}else{
					pListaD->ant = pAux2;
					pAux2->prox = pListaD;
				}

				pListaD->prox = pAux;
			}


		}
	}else printf("Erro ao alocar memoria para a lista (malloc)\n");
}

void listarIni(listaD **inicioListaD){
	listaD *pAux;

	if (*inicioListaD == NULL) {

		printf("\nLista Vazia");

	} else {

		pAux = *inicioListaD;

		while (pAux != NULL) {
			printf("\n\t\tAtual: %p", pAux);
			printf("\n\t\tNumero: %.2f", pAux->num);
			printf("\n\t\tAnterior: %p", pAux->ant);
			printf("\n\t\tProximo: %p\n", pAux->prox);
			pAux = pAux->prox;
		}

	}
}

