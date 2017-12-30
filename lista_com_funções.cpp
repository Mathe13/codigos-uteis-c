#include <iostream>
//#include <string>
#include <stdbool.h>
#include <stdlib.h>
using namespace std;
//struct
typedef struct nodo{
    int cod;
    float peso;
    struct nodo *prox;
}lista;

//funções
void cadFim(lista** inicio,lista** boi);
void cadIni(lista** inicio,lista** boi);
void mostrar(lista *inicio,lista *boi);
void procurar(lista *inicio,lista *boi);
void cadMeio(lista** inicio,lista** boi);

void cadFim(lista** inicio,lista** boi){
    *boi=(lista*)malloc(sizeof(lista));
    if(boi){
    float tmpPeso;
    int tmpCod;
    cout<<"Digite o cod"<<endl;
    cin>>tmpCod;
    cout<<"Digite o peso"<<endl;
    cin>>tmpPeso;
    (*boi)->cod=tmpCod;
    (*boi)->peso=tmpPeso;
    (*boi)->prox=NULL;
    if(inicio==NULL){
        inicio=boi;
    }else{
        (*boi)->prox=NULL;
        lista *ultimo;
        ultimo=*inicio;
        while(ultimo->prox!=NULL){
            ultimo=ultimo->prox;
        }
        ultimo->prox=*boi;
    }

            }
}
void mostrar(lista *inicio,lista *boi){
    boi=inicio;
    while(boi!=NULL){
        cout<<"-----------------"<<endl;
        cout<<"Cod: "<<boi->cod<<endl;
        cout<<"Peso: "<<boi->peso<<endl;
        boi=boi->prox;
        }
}
void procurar(lista *inicio,lista *boi){
    cout<<"Digite um cod a ser buscado"<<endl;
    int tmp;
    bool achou=false;
    cin>>tmp;
    boi=inicio;
    while(boi!=NULL){
        if((*boi).cod == tmp){
            cout<<"peso:"<<boi->peso;
            boi=NULL;
            achou=true;
        }else{
            boi=boi->prox;
        }
    }
    if(achou==false){
        cout<<"boi n encontrado";
    }

}
void cadIni(lista** inicio,lista** boi){
    *boi=(lista*)malloc(sizeof(lista));
    if(boi){
    float tmpPeso;
    int tmpCod;
    cout<<"Digite o cod"<<endl;
    cin>>tmpCod;
    cout<<"Digite o peso"<<endl;
    cin>>tmpPeso;
    (*boi)->cod=tmpCod;
    (*boi)->peso=tmpPeso;
    (*boi)->prox=NULL;

        (*boi)->prox=*inicio;
        (*inicio)=(*boi);
    }

            }
void cadMeio(lista** inicio,lista** boi){
    cout<<"Digite um cod a ser buscado"<<endl;
    int tmp;
    cin>>tmp;
   // bool achou=false;
    lista *tmpb;
    tmpb=*inicio;
    while(tmpb->cod!=tmp){
        cout<<"dentro do while"<<endl;
        tmpb=tmpb->prox;
        }

    if(tmpb==NULL){
        cout<<"cod n encontrado";
    }else{
        *boi=(lista*)malloc(sizeof(lista));
        if(boi){
        float tmpPeso;
        int tmpCod;
        cout<<"Digite o cod"<<endl;
        cin>>tmpCod;
        cout<<"Digite o peso"<<endl;
        cin>>tmpPeso;
        (*boi)->cod=tmpCod;
        (*boi)->peso=tmpPeso;
        (*boi)->prox=NULL;

        (*boi)->prox=tmpb->prox;
        tmpb->prox=*boi;
            }
    }
}
void menu(lista** inicio,lista** boi){
    int op;
    cout<<"===MENU===="<<endl;
    cout<<"1-cadINI"<<endl;
    cout<<"2-cadFIM"<<endl;
    cout<<"3-cadMEIO"<<endl;
    cout<<"4-Procurar"<<endl;
    cout<<"5-Mostrar"<<endl;
    cout<<"6-Sair"<<endl;
    cin>>op;
    switch(op){
        case 1:
            cadFim(*(&inicio),*(&(boi)));
        break;
        case 2:
            cadFim(*(&inicio),*(&(boi)));
        break;
        case 3:
            cadMeio(*(&inicio),*(&(boi)));
        break;
        case 4:
            procurar(*inicio,*boi);
        break;
        case 5:
            mostrar(*inicio,*boi);
        break;
        case 6:
            terminate();
        break;
        default:
            cout<<"Digite um op valida"<<endl;
        break;
    }
    menu(*(&inicio),*(&(boi)));

}

main(){
    //ponteiros
    lista *inicio=NULL;
    lista *boi;
    while(1){
        int op;
    cout<<"===MENU===="<<endl;
    cout<<"1-cadINI"<<endl;
    cout<<"2-cadFIM"<<endl;
    cout<<"3-cadMEIO"<<endl;
    cout<<"4-Procurar"<<endl;
    cout<<"5-Mostrar"<<endl;
    cout<<"6-Sair"<<endl;
    cin>>op;
    switch(op){
        case 1:
            cadFim(&inicio,&boi);
        break;
        case 2:
            cadFim(&inicio,&boi);
        break;
        case 3:
            cadMeio(&inicio,&boi);
        break;
        case 4:
            procurar(inicio,boi);
        break;
        case 5:
            mostrar(inicio,boi);
        break;
        case 6:
            terminate();
        break;
        default:
            cout<<"Digite um op valida"<<endl;
        break;

    }
}
}
