#include<iostream>
using namespace std;

struct arvore{
    string item;
    arvore *esq,*dir;
};

arvore *Raiz;
int contador;

void arvore_Construtor(){
    Raiz=NULL;
    contador=0;
}

void arvore_Destrutor(arvore *&Raiz){
    if(Raiz!=NULL){
        arvore_Destrutor(Raiz->esq);
        arvore_Destrutor(Raiz->dir);
        free(Raiz);
        Raiz=NULL;
    }
}

bool arvore_Vazia(){
    return Raiz==NULL;
}

int arvore_Tamanho(){
    return contador;
}

bool arvore_Inserir(string letra, arvore *&Raiz){
    if(Raiz==NULL){
        Raiz=new arvore;
        if(Raiz==NULL)
            return false;
        else{
            Raiz->item=letra;
            Raiz->esq=Raiz->dir=NULL;
            contador++;
            return true;
        }
    }
    else{
        if(letra<Raiz->item)
            return arvore_Inserir(letra,Raiz->esq);
        else{
            if(letra>Raiz->item)
                return arvore_Inserir(letra,Raiz->dir);
            else
                return false;//letra já existe na árvore
        }
    }
}

//percorre a árvore
void arvore_Busca_em_Ordem(arvore *&Raiz){
    if(Raiz!=NULL){
        arvore_Busca_em_Ordem(Raiz->esq);
        cout<<Raiz->item;
        arvore_Busca_em_Ordem(Raiz->dir);
    }
}

//percorre a árvore
void arvore_Busca_pre_Ordem(arvore *&Raiz){
    if(Raiz!=NULL){
        cout<<Raiz->item;
        arvore_Busca_pre_Ordem(Raiz->esq);
        arvore_Busca_pre_Ordem(Raiz->dir);
    }
}

//percorre a árvore
void arvore_Busca_pos_Ordem(arvore *&Raiz){
    if(Raiz!=NULL){
        arvore_Busca_pos_Ordem(Raiz->esq);
        arvore_Busca_pos_Ordem(Raiz->dir);
        cout<<Raiz->item;
    }
}

int main(){
    string x,opcao;

    arvore_Construtor();

    do{
        cout<<"\nInforme a letra: ";
        cin>>x;

        arvore_Inserir(x,Raiz);

        printf("\nMais dados? S/N:  ");
        cin>>opcao;
    }while((opcao!="N")&& (opcao!="n"));

//  tamanho da árvore
    printf("\nQuantidade de elementos: %d\n",contador);

//   impressão em ordem
    printf("\nArvore em ordem:\n");
    arvore_Busca_em_Ordem(Raiz);
    printf("\n\n");

//  impressão em pré-ordem
    printf("Arvore em pre-ordem:\n");
    arvore_Busca_pre_Ordem(Raiz);
    printf("\n\n");

//  impressão em pós-ordem
    printf("Arvore em pos-ordem:\n");
    arvore_Busca_pos_Ordem(Raiz);
    printf("\n\n");

//  devolvendo memóra alocada ao sistema operacional
    arvore_Destrutor(Raiz);

    return 0;
}
