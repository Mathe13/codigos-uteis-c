//biblioteca principal
#include<iostream>
//biblioteca para usar string
#include<string.h>
//biblioteca de leitura e escrita
#include <fstream>
//vetores dinamicos
#include<vector>
//para não ter q digitar std::
//#include<stdlib.h>
//#include<stdio.h>
using namespace std;
typedef struct{
    int itsCod;
    float itsPeso;
    int itsDia,itsMes,itsAno;
}bovino;
vector <bovino> boi;
void cadastrar();
void listar();
void peso_total();
void salvar();
void carregar();
void mais_velho();
void menu();
void cls();

void cls() {
    for (int i = 0; i < 100; ++i) {
        std::cout << endl;
    }
}

void menu(){
    //cls();
    cout<<"------MENU-------"<<endl;
    cout<<"1-Cadastar"<<endl;
    cout<<"2-Listar"<<endl;
    cout<<"3-Calcular peso total"<<endl;
    cout<<"4-boi mais velho"<<endl;
    cout<<"5-Salvar e Sair"<<endl;
    int op;
    cin>>op;
    switch (op){
        case 1:
            cadastrar();
        break;
        case 2:
            listar();
        break;
        case 3:
            peso_total();
        break;
        case 4:
          mais_velho();
        break;
        case 5:
            salvar();
            terminate();
        break;
    }
    menu();
}
void cadastrar(){
    bovino tmp;
    int nLote,dia,mes,ano;
    float peso;
    cout<<"----Cadastro de Lote----"<<endl;
    cout<<"Quantos bois no lote de hoje?"<<endl;
    cin>>nLote;
    for(int i=0;i<nLote;i++){
        cout<<"O cod do boi sera: "<<boi.size()+1<<endl;
        cout<<"Peso do Boi:"<<endl;
        cin>>peso;
        cout<<"\tData de nasc do boi "<<endl;
        do{
            cout<<"Digite o dia:"<<endl;
            cin>>dia;
        }while((dia>31)||(dia<0));
        do{
            cout<<"Digite o mes:"<<endl;
            cin>>mes;
        }while((mes>12)||mes<0);
        do{
            cout<<"Digite o ano:"<<endl;
            cin>>ano;
        }while(ano<0);
        tmp.itsPeso=peso;
        tmp.itsCod=boi.size()+1;
        tmp.itsDia=dia;
        tmp.itsMes=mes;
        tmp.itsAno=ano;
        boi.push_back(tmp);
    }
}
void salvar(){
    ofstream escreve;
    //system("mkdir digdin");
    escreve.open("dados.txt");
    if(!escreve.is_open()){
        cout<<"erro ao abrir o arquivo"<<endl;
        terminate();
    }
    escreve<<boi.size()<<endl;
    for(int i=0;i<boi.size();i++){
        escreve<<boi[i].itsCod<<" "<<boi[i].itsPeso<<" "<<boi[i].itsDia<<" "<<boi[i].itsMes<<" "<<boi[i].itsAno<<endl;
    }
    escreve.close();
    cout<<"Salvo com sucesso"<<endl;
}
void carregar(){
//primeiro zerar o vetor
    boi.clear();
    bovino tmp;
    int total;
    ifstream leia;
    leia.open("dados.txt");
    if(!leia.is_open()){
        cout<<"erro ao abrir o arquivo"<<endl;
        terminate;
    }
    leia>>total;
    for(int i=0;i<total;i++){
        leia>>tmp.itsCod;
        leia>>tmp.itsPeso;
        leia>>tmp.itsDia;
        leia>>tmp.itsMes;
        leia>>tmp.itsAno;
        boi.push_back(tmp);
    }
    cout<<"Arquivos carregados com sucesso"<<endl;


}
void listar (){
    cout<<"\tListando bois"<<endl;
    for(int i=0;i<boi.size();i++){
        cout<<"Cod: "<<boi[i].itsCod<<endl;
        cout<<"Peso: "<<boi[i].itsPeso<<endl;
        cout<<"Data de nasc: "<<boi[i].itsDia<<"/"<<boi[i].itsMes<<"/"<<boi[i].itsAno<<endl;
        cout<<"------------------------"<<endl;
    }

}
void peso_total(){
    float pesoT=0;
    for(int i=0;i<boi.size();i++){
        pesoT=pesoT+boi[i].itsPeso;
    }
    cout<<"\tPeso total do rebano"<<endl;
    cout<<"peso total: "<<pesoT<<endl;

}
void mais_velho(){

    int anoMaior=0,mesMaior=0,diaMaior=0;
    vector <bovino> tmp2,tmp;

    for(int i=0;i<boi.size();i++){
            if(anoMaior<boi[i].itsAno){
                anoMaior=boi[i].itsAno;
            }
    }

    for(int i=0;i<boi.size();i++){
        if(boi[i].itsAno==anoMaior){
            tmp.push_back(boi[i]);
        }
    }

    for(int i=0;i<tmp.size();i++){
            if(mesMaior<tmp[i].itsMes){
                mesMaior=tmp[i].itsMes;
            }
    }
    for(int i=0;i<tmp.size();i++){
        if(tmp[i].itsMes==mesMaior){
            tmp2.push_back(tmp[i]);
    }
    }

    for(int i=0;i<tmp2.size();i++){
        if(diaMaior<tmp2[i].itsDia){
            diaMaior=tmp2[i].itsDia;
    }
    }
    tmp.clear();
    cout<<"bois Velhos:"<<endl;
    for(int i=0;i<tmp2.size();i++){
        tmp.push_back(tmp2[i]);
        cout<<"Cod:"<<tmp[i].itsCod<<endl;
    }
}
main(){
    carregar();
    menu();
}
