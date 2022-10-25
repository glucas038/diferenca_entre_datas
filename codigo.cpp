#include<iostream>

using namespace std;

bool Bissexto(int ano){

	double divisao1 = 0;
	double divisao2 = 0;
	double divisao3 = 0;
	
	divisao1 = ano % 4;
	divisao2 = ano % 100;
	divisao3 = ano % 400;
	
	if(divisao1 != 0){
		return false;
	} else if (divisao2 != 0){
		return true;
	} else if (divisao3 == 0){
		return true;
	} else 
		return false;	
		
	
}

int DiasNoMes(int mes,int ano){
	int diasMes = 0;
	bool bi = Bissexto(ano);
	
	
	switch (mes){
		case 1:
			diasMes = 31;
			break;
		
		case 2:
			if(bi)
				diasMes = 29;
			else
				diasMes = 28;
			break;
		
		case 3:
			diasMes = 31;
			break;
		
		case 4:
			diasMes = 30;
			break;
			
		case 5:
			diasMes = 31;
			break;
			
		case 6:
			diasMes = 30;
			break;
			
		case 7:
			diasMes = 31;
			break;
			
		case 8:
			diasMes = 31;
			break;
			
		case 9:
			diasMes = 30;
			break;
			
		case 10:
			diasMes = 31;
			break;
			
		case 11:
			diasMes = 30;
			break;
			
		case 12:
			diasMes = 31;
			break;
	}
	return diasMes;
}

int main(){
	int dia1 = 0;
	int mes1 = 0;
	int ano1 = 0;
	
	int dia2 = 0;
	int mes2 = 0;
	int ano2 = 0;
	
	int diasMes1 = 0;
	int diasMes2 = 0;
		
	int sub1 = 0;
	int sub2 = 0;
	int sub3 = 0;
	int sub4 = 0;
	int sub5 = 0;
	int sub6 = 0;
	
	int soma1 = 0;
	int soma2 = 0;
	int soma3 = 0;
	int soma4 = 0;
	
	int diasRest = 0;
	int mesRest = 0;
	int anosRest = 0;
	int diasTotal = 0;
	
	int diasNoMes = 0;
	
	for (; dia1 >= 0;){
		cout << "Digite a primeira data comecando pelo dia (dd): ";
		cin >> dia1;
		
			
		if(dia1>1){
			cout << "Digite o mes da primeira data (mm): ";
			cin >> mes1;
			cout << "Digite o ano da primeira data (aaaa): ";
			cin >> ano1;
			
			cout << "Digite a segunda data comecando pelo dia (dd): ";
			cin >> dia2; 
			cout << "Digite o mes da segunda data (mm): ";
			cin >> mes2;
			cout << "Digite o ano da segunda data (aaaa): ";
			cin >> ano2;
		}
				
		sub1 = ano2 - ano1 - 2;
		
		if (sub1 == -2){
			sub2 = mes2 - mes1;
			
			if (sub2 == -2){
				diasTotal = dia2 - dia1;
			}else if(sub2 == -1){

				sub3 = DiasNoMes(mes1, ano1) - dia1;
				diasTotal = sub3 + dia2;
			} else{
				
				sub3 = DiasNoMes(mes1, ano1) - dia1;
				diasTotal = sub3 + dia2;
				
				for(int cont = mes1 + 1; cont < mes2; cont++){
					diasNoMes = DiasNoMes(cont,ano1);
					diasTotal += diasNoMes;
				}
			}		
		}
		
		if(sub1 == -1){
			sub3 = DiasNoMes(mes1, ano1) - dia1;
			diasTotal = sub3 + dia2;
			
			for(int cont= mes1 + 1; cont <=12; cont ++){
				diasTotal += (DiasNoMes(cont,ano1));
			}
			
			for(int cont = mes2 - 1; cont>= 1; cont--){
				diasTotal += (DiasNoMes(cont,ano2));
			}	
		}
		
		if(sub1 >= 0){
			sub3 = DiasNoMes(mes1, ano1) - dia1;
			diasTotal = sub3 + dia2;
			
			for(int cont= mes1 + 1; cont <=12; cont ++){
				diasTotal += (DiasNoMes(cont,ano1));
			}
			
			for(int cont = mes2 - 1; cont>= 1; cont--){
				diasTotal += (DiasNoMes(cont,ano2));
			}
			
			for(int cont = ano1 + 1; cont < ano2; cont++){
				if(Bissexto(cont))
					diasTotal += 366;
				else
					diasTotal += 365;
			}
		}
		cout<<"\n------------------------------------------------\n";
		cout <<"Entre essas duas datas tem: " << diasTotal << " dias.\n";
		cout<<"------------------------------------------------\n\n";
	}
	return 0;
}
