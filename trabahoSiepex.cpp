#include<iostream>
#include<string>
#include<fstream>
using namespace std;

//struct
typedef struct nodo{
    int thisCod;
    float thisSalario;
    string thisNome;
    nodo *ant,*prox;
}funcionario;

//declaração de funçoes
void cadini(funcionario** inicio, funcionario* tmp, funcionario** fim, funcionario auxf);
void cadfim(funcionario** inicio, funcionario* tmp, funcionario** fim, funcionario auxf);
void cadastrarOrdem(funcionario **inicio, funcionario* tmp, funcionario** fim, funcionario auxf);
float Listar(funcionario* inicio);
void ordenar(funcionario** inicio, funcionario* tmp);

//main
main(){
    funcionario *tmp = NULL, *inicioLista = NULL, *fimLista = NULL;
    //int total;
    ifstream leia;
    leia.open("dados.txt");

    /*
    o arquivo dados deve conter os dados na forma
    cod salario nome
    */
    if(!leia.is_open()){
        cout<<"erro ao abrir o arquivo"<<endl;
        terminate;
    }else{
    int tmpCod;
    //leia>>total;
    funcionario auxf;
    //for(int i=0;i<total;i++){
    while(leia>>tmpCod){//melhor forma de fazer um loop de leitura com ifstream
        //leia>>auxf.thisCod;
        auxf.thisCod=tmpCod;
        //cout<<"cod"<<auxf.thisCod<<endl;
        leia>>auxf.thisSalario;
        //cout<<"salario"<<auxf.thisSalario<<endl;
        leia>>auxf.thisNome;
        //cout<<"nome"<<auxf.thisNome<<endl;
        if(auxf.thisCod < 10){
            //cout<<"entrou if"<<endl;
            cadini(&inicioLista,tmp,&fimLista,auxf);
            //cout<<"cadastrando no inicio..."<<endl;
        }else if((auxf.thisCod>10)&&(auxf.thisCod<26)){
            cadastrarOrdem(&inicioLista,tmp,&fimLista,auxf);
            //cout<<"cadastrando no meio..."<<endl;
        }else if(auxf.thisCod>25){
            cadfim(&inicioLista,tmp,&fimLista,auxf);
            //cout<<"cadastrando no fim..."<<endl;
        }
    }

}
    //cout<<"vai listar"<<endl;
    float salario=Listar(inicioLista);
    cout<<"Maior Salario:"<<salario<<endl;
    ordenar(&inicioLista,tmp);
    cout<<"============================ordenando====================================="<<endl;
    Listar(inicioLista);
}
//funções
void cadini(funcionario** inicio,funcionario* tmp,funcionario** fim,funcionario auxf){
    tmp = new funcionario();
    funcionario *Aux;
    if(tmp){
            //carrega tmp
            tmp->thisCod = auxf.thisCod;
			tmp->thisNome = auxf.thisNome;
			tmp->thisSalario=auxf.thisSalario;

		if(*inicio == NULL){
			*inicio = tmp;
			//tmp->thisCod = auxf.thisCod;
			//tmp->thisNome = auxf.thisNome;
			//tmp->thisSalario=auxf.thisSalario;
			tmp->ant = NULL;
			tmp->prox = NULL;
			if(tmp->prox == NULL) *fim = tmp;
		}else{
			Aux = *inicio;
			Aux->ant = tmp;
			*inicio = tmp;
			tmp->prox = Aux;
			tmp->ant = NULL;
			if(tmp->prox == NULL) *fim = tmp;
		}

        }else cout<<"Erro ao alocar memoria para a lista (new)"<<endl;


        //cout<<"ini cod"<<(*inicio)->thisCod<<endl;
        //cout<<"ini salario"<<(*inicio)->thisSalario<<endl;
        //cout<<"ini nome"<<(*inicio)->thisNome<<endl;
}

void cadfim(funcionario** inicio, funcionario* tmp,funcionario** fim,funcionario auxf){
    tmp = new funcionario();
    funcionario *Aux;
    if(tmp){
            //carrega tmp
            tmp->thisCod = auxf.thisCod;
			tmp->thisNome = auxf.thisNome;
			tmp->thisSalario=auxf.thisSalario;

		if(*inicio == NULL){
			*inicio = tmp;
			//tmp->thisCod = auxf.thisCod;
			//tmp->thisNome = auxf.thisNome;
			//tmp->thisSalario=auxf.thisSalario;
			tmp->ant = NULL;
			tmp->prox = NULL;
			if(tmp->prox == NULL) *fim = tmp;
		}else{
			Aux = *inicio;
			while(Aux->prox != NULL) Aux = Aux->prox;

			tmp->ant = Aux;
			tmp->prox = NULL;
            //tmp->thisCod = auxf.thisCod;
			//tmp->thisNome = auxf.thisNome;
			//tmp->thisSalario=auxf.thisSalario;
			Aux->prox =tmp;
			if(tmp->prox == NULL) *fim = tmp;
		}

        }else cout<<"Erro ao alocar memoria para a lista (new)"<<endl;
}

void cadastrarOrdem(funcionario** inicio, funcionario* tmp,funcionario** fim,funcionario auxf){
funcionario *pAux, *pAux2, *pAux3;
	int num, teste=0, aux;

	tmp = new funcionario();

	if(tmp){
            tmp->thisCod = auxf.thisCod;
			tmp->thisNome = auxf.thisNome;
			tmp->thisSalario=auxf.thisSalario;

		if(*inicio == NULL){
			*inicio = tmp;
			tmp->ant = NULL;
			tmp->prox = NULL;
		}else{
            num=0;
            pAux=*inicio;
            while(pAux->prox!=NULL){
                if(pAux->thisCod<tmp->thisCod){
                   num=1;
                    break;
                }else{
                        pAux=pAux->prox;
                     }
            }//fim while
                if(num==1){
                    pAux2=pAux->prox;
                    pAux->prox=tmp;
                    tmp->ant=pAux;
                    tmp->prox=pAux2;
                    pAux2->ant=tmp;
                    //cout<<"cadastrado apos"<<pAux->thisCod<<endl;
                }else cout<<"erro satanico"<<endl;

		}

	}else cout<<"Erro ao alocar memoria para a lista n"<<endl;
}

float Listar(funcionario* inicio){
    //cout<<"entrou Listar"<<endl;
    float MaiorSalario=0;
    funcionario *tmp=inicio;
    while(tmp!=NULL){
        if(MaiorSalario<tmp->thisSalario){
            MaiorSalario=tmp->thisSalario;
        }
        if(tmp!=NULL){
        //cout<<"entrou while"<<endl;
        cout<<"Cod: "<<tmp->thisCod<<endl;
        cout<<"Nome: "<<tmp->thisNome<<endl;
        cout<<"Salarios: "<<tmp->thisSalario<<endl;
        cout<<"-----------------------"<<endl;
        tmp=tmp->prox;
    }}
    //cout<<"Maior Salario:"<<MaiorSalario<<endl;
    return MaiorSalario;
}

void ordenar(funcionario** inicio, funcionario* tmp){
    funcionario *adiantado,*atrasado,aux;
    int flag;
    //tmp=*inicio;
    do{
        flag=0;
        tmp=*inicio;
        while(tmp->prox!=NULL){
            adiantado=tmp->prox;
            if(tmp->thisCod>adiantado->thisCod){
                aux.thisCod=adiantado->thisCod;
                aux.thisNome=adiantado->thisNome;
                aux.thisSalario=adiantado->thisSalario;

                adiantado->thisCod=tmp->thisCod;
                adiantado->thisNome=tmp->thisNome;
                adiantado->thisSalario=tmp->thisSalario;
                //adiantado tem os valores de tmp
                tmp->thisCod=aux.thisCod;
                tmp->thisNome=aux.thisNome;
                tmp->thisSalario=aux.thisSalario;
                //tmp tem os valores de adiantado
                flag=1;
            }
            tmp=tmp->prox;//proxima posição
        }

    }while(flag==1);

}

