#include <iostream>
using namespace std;


typedef struct nodo{
    int thisCod;
    char thisTipo;
    nodo *anterior;
}Pilha;

void push(Pilha** topo,Pilha aux);
Pilha pop(Pilha** topo);
void Listar(Pilha* topo);

main(){
Pilha *topo=NULL;//aponta para o topo
    int op;
    while(1){
    cout<<"====MENU===="<<endl;
    cout<<"1-Cadastrar"<<endl;
    cout<<"2-Listar"<<endl;
    cout<<"3-Tirar da pilha"<<endl;
    cout<<"4-Sair"<<endl;
    cin>>op;//leu op
    switch(op){
        case 1:
            Pilha tmp;//vai armazenar os dados por um tempo
            cout<<"-----Cadastra-----"<<endl;
            cout<<"Digite o codigo"<<endl;
            cin>>tmp.thisCod;
            cout<<"Digite o char do tipo"<<endl;
            cin>>tmp.thisTipo;
            push(&topo,tmp);//coloca no topo
        break;
        case 2:
            //cout<<(topo)->thisCod<<endl;
            //cout<<(topo)->thisTipo<<endl;
            Listar(topo);
        break;
        case 3:
            pop(&topo);
        break;
        case 4:
            terminate();//termina a execução
        break;
    }//switch
    }//fim menu

}//fim main

void push(Pilha** topo,Pilha aux){
    cout<<"entrou no cadastro"<<endl;
    Pilha *tmp=new Pilha;//aloca memoria
    if(tmp){
        tmp->thisCod=aux.thisCod;
        tmp->thisTipo=aux.thisTipo;//carregou os dados
        if(*topo==NULL){
            tmp->anterior=NULL;//marca que ele é a base
            (*topo)=tmp;   //adiciona no fim da pilha
            }
        else{
            tmp->anterior=*topo;//diz que o anterior é o antigo top0
            *topo=tmp;//adiciona no topo
        }
    }//fim if(tmp)


}//fim do void

Pilha pop(Pilha** topo){
    Pilha retornara,*aux;
    retornara.thisCod=(*topo)->thisCod;
    retornara.thisTipo=(*topo)->thisTipo;
    aux=*topo;
    *topo=(*topo)->anterior;//removeu da pilha
    delete aux;
    return retornara;

}

void Listar(Pilha *topo){
    cout<<"entrou listar"<<endl;
    Pilha *tmp;
    tmp=topo;
    while(tmp!=NULL){
        cout<<"Cod: "<<tmp->thisCod<<endl;
        cout<<"Tipo: "<<tmp->thisTipo<<endl;
        cout<<"-------------------------"<<endl;
        tmp=tmp->anterior;//percorre do topo ate a base
    }
}
