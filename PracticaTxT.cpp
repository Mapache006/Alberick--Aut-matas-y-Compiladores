#include <iostream>
#include <string>
#include <cctype>   //Lq identifica simbolo
//isspace(c) es espacio?
//isalpha(c) es letra?
//isdigit(c) es numero?

#include <fstream>  //Lq manejo de docs txt
//is_open()  is_close()   verifica abertura o cerrado de doc
//ofstream escribir en doc de salida
//ifstream leer en doc de entrada
//fstream lee el contenido o editacontenido
//getline() lee archivos linea a linea      como/donde,variable renglon
using namespace std;


int main() {
	char op;
	bool valrfc,valcurp,valine; 	//valido o invalido
	string tk,linea;
    int nmenu,a,b,numline,totalAnalizadas=0,lineasVaciasSeguidas = 0,leidas=0;

    do {
    	
    	
    	
      //Interfaz de inicio para ver que doc va a leer  		////////////////
       do{

		cout << "\nTeclea que quiere verificar: "<<endl;
		cout << "\n 1) RFC \n 2) CURP \n 3)INE \n ";
        cin >> nmenu;
        
        
        if(nmenu==1 || nmenu==2 || nmenu==3){
        	system("cls");
        	a=1;
		}else{
			cout<<"\n Ingrese un numero valido, enter para continuar \n ";
			system("pause");
			system("cls");
			a=0;
		}
        
}while(a==0); //verdad? se repite

		//cuantas variables vas a leer
	   do{
    cout << "\nTeclee cuantos valores desea leer (max 50): ";
    cin >> numline;

    if (numline >= 1 && numline <= 50) {
        system("cls");
        b = 1;
        numline++;//puse esto como un curita, si pones 3 salen 2 xd
    } else {
        cout << "\nIngrese un numero valido\n";
        system("pause");
        system("cls");
        b = 0;
    }
} while (b == 0);

ifstream fich;
ofstream salida("TxTsalida.txt", ios::out | ios::trunc);//declaro archivo de salida para imprimir mis valores validos o invalidos

//reinicio de var para hacer varias pasadas
leidas = 0;
lineasVaciasSeguidas=0;

switch (nmenu) { 		//break;










	case 1: // RFC
    fich.open("TxTRFC.txt"); //entra al documento de RFCs 
		//C:\Users\Irma\Desktop\UAEH\6 Semestre\ si estuviera en otra carpeta
		//TxTcomp.txt por que es la misma carpeta
if (!salida) {
    cout << "Error al crear archivo de salida\n";
    return 1;
}
	while (getline(fich, linea)) {
//lineas vacias
    if (linea.empty()) {
		continue;
        lineasVaciasSeguidas++;
        if (lineasVaciasSeguidas == 2) break;
        
    }

    lineasVaciasSeguidas = 0;
    leidas++;
    if (leidas == numline) break;
//lineas vacias

		cout << "Linea " << leidas << ": " << linea << endl; //miestra en el programa las curps
	    bool valrfc=true;//declaro el valor verdadero para que el siguiente rfc inicie como verdadero hasta encontrarle falla
	    
		
				if (linea.size() != 13) valrfc = false; //EL RFC DEBE DE TENER 13 SIMBOLOS

            if (isalpha(linea[0])) {//////inicia en 0 por que es el primer valor 
                //si comple todo chido xd
                linea[0]=toupper(linea[0]);
            }else{
            	valrfc=false;
			}
            if (isalpha(linea[1]) && ((linea[1])=='A'||(linea[1])=='E'||(linea[1])=='I'||(linea[1])=='O'||(linea[1])=='U')) {
               linea[1]=toupper(linea[1]);
            }else{
            	valrfc=false;
			}
            if (isalpha(linea[2]) ) { linea[2]=toupper(linea[2]);
            }else{
            	valrfc=false;
			}
            if (isalpha(linea[3]) ) {linea[3]=toupper(linea[3]);
            }else{
            	valrfc=false;
			}
            if (!isdigit(linea[4]) || !isdigit(linea[5])) valrfc = false; //si los digitos del anio no son numero = error
			////////////////////////////////////////////////////////////////////////////////
				if (linea[6]=='0') {
    	if (!(linea[7]>='1' && linea[7]<='9')) valrfc = false;
	} else if (linea[6]=='1') {
	    if (!(linea[7]>='0' && linea[7]<='2')) valrfc = false;
	} else valrfc = false;

			///////////////////////////////////////////en este caso si mes inicia con 0 solo puede seguir 1-9 si inicia con 1 solo sigue del 0-2
										
				if (linea[8]=='0' || linea[8]=='1' || linea[8]=='2') {
	    if (!isdigit(linea[9])) valrfc = false;
	} else if (linea[8]=='3') {
	    if (!(linea[9]=='0' || linea[9]=='1')) valrfc = false;
	} else valrfc = false;

				if (linea[8]=='0' && linea[9]=='0') valrfc = false;
									
			///////////////////////////////////////si el dia inicia con 0-2 solo puede ir de 1-9 si inicia 3 solo puede ir de 0-1
            ///////homoclave
            if ((isalpha(linea[10])  )|| isdigit(linea[10]) ) {//////si inicia con letra o numero todobien pq va del 1 al 9
                linea[10]=toupper(linea[10]);
            }else{
            	valrfc=false;
			}
        	if ((isalpha(linea[11])) || isdigit(linea[11]) ) {//////si inicia con letra o numero todobien pq va del 1 al 9
                linea[11]=toupper(linea[11]);
            }else{
            	valrfc=false;
			}
			if ((isalpha(linea[12])  )  || isdigit(linea[12]) ) {//////si inicia con letra o numero todobien pq va del 1 al 9
                linea[12]=toupper(linea[12]);
            }else{
            	valrfc=false;
			}
		
		
		if(valrfc==true){	//imprimir linea y valido
			salida << linea << " -> RFC VALIDO\n";
		}else if(valrfc==false){//imprimir linea e invalido
			salida << linea << " -> RFC Invalido\n";
		}
		
				
}//while 
		
		
		
		
		
		
		
		
case 2:////////////////////////////////////////////////////////       *CUURP
fich.open("TxTCURP.txt"); //entra al documento de CURPs 
		
if (!salida) {
    cout << "Error al crear archivo de salida\n";
    return 1;
}
	while (getline(fich, linea)) {
//lineas vacias
    if (linea.empty()) {
        lineasVaciasSeguidas++;
        if (lineasVaciasSeguidas == 2) break;
        continue;
    }

    lineasVaciasSeguidas = 0;
    leidas++;
    if (leidas == numline) break;
//lineas vacias

		cout << "Linea " << leidas << ": " << linea << endl; //miestra en el programa las curps
	    bool valcurp=true;//declaro el valor verdadero para que el siguiente curp inicie como verdadero hasta encontrarle falla
	    
		
				if (linea.size() != 18) valcurp = false; //EL RFC DEBE DE TENER 13 SIMBOLOS

            if (isalpha(linea[0])) {//////inicia en 0 por que es el primer valor 
                //si comple todo chido xd
                linea[0]=toupper(linea[0]);
            }else{
            	valcurp=false;
			}
            if (isalpha(linea[1]) && ((linea[1])=='A'||(linea[1])=='E'||(linea[1])=='I'||(linea[1])=='O'||(linea[1])=='U')) {
               linea[1]=toupper(linea[1]);
            }else{
            	valcurp=false;
			}
            if (isalpha(linea[2]) ) { linea[2]=toupper(linea[2]);
            }else{
            	valcurp=false;
			}
            if (isalpha(linea[3]) ) {linea[3]=toupper(linea[3]);
            }else{
            	valcurp=false;
			}
            if (!isdigit(linea[4]) || !isdigit(linea[5])) valcurp = false; //si los digitos del anio no son numero = error
			////////////////////////////////////////////////////////////////////////////////
				if (linea[6]=='0') {
    	if (!(linea[7]>='1' && linea[7]<='9')) valcurp = false;
	} else if (linea[6]=='1') {
	    if (!(linea[7]>='0' && linea[7]<='2')) valcurp = false;
	} else valcurp = false;

			///////////////////////////////////////////en este caso si mes inicia con 0 solo puede seguir 1-9 si inicia con 1 solo sigue del 0-2
										
				if (linea[8]=='0' || linea[8]=='1' || linea[8]=='2') {
	    if (!isdigit(linea[9])) valcurp = false;
	} else if (linea[8]=='3') {
	    if (!(linea[9]=='0' || linea[9]=='1')) valcurp = false;
	} else valcurp = false;

				if (linea[8]=='0' && linea[9]=='0') valcurp = false;
									
						//////////////////////////////////			
									
									
					// Sexo
if (linea[10] != 'H' && linea[10] != 'M')
    valcurp = false;

// Entidad
string entidades[] = {
    "AS","BC","BS","CC","CS","CH","CL","CM","DG","GT","GR",
    "HG","JC","MC","MN","MS","NT","NL","OC","PL","QT","QR",
    "SP","SL","SR","TC","TS","TL","VZ","YN","ZS","NE"
};
//esto fue un chatgepetazo pq lo iba a dejar como cualquier par de letras
bool entidadValida = false;
string entidad = linea.substr(11, 2);

for (int i = 0; i < 32; i++) {
    if (entidad == entidades[i]) {
        entidadValida = true;
        break;
    }
}

if (!entidadValida)
    valcurp = false;

// Consonantes internas
for (int i = 13; i <= 15; i++) {
    if (!isalpha(linea[i]) ||
        linea[i]=='A'||linea[i]=='E'||linea[i]=='I'||linea[i]=='O'||linea[i]=='U')
        valcurp = false;
}

// Homoclave
if (!isalnum(linea[16]))
    valcurp = false;

// Dígito verificador
if (!isdigit(linea[17]))
    valcurp = false;				
									
									
			if(valcurp==true){	//imprimir linea y valido
			salida << linea << " -> CURP VALIDO\n";
		}else if(valcurp==false){//imprimir linea e invalido
			salida << linea << " -> CURP Invalido\n";
		}						
									
	
///CURP
}//while












	case 3:		///INE
	fich.open("TxTINE.txt"); //entra al documento de CURPs 
		
if (!salida) {
    cout << "Error al crear archivo de salida\n";
    return 1;
}
	while (getline(fich, linea)) {
//lineas vacias
    if (linea.empty()) {
        lineasVaciasSeguidas++;
        if (lineasVaciasSeguidas == 2) break;
        continue;
    }

    lineasVaciasSeguidas = 0;
    leidas++;
    if (leidas == numline) break;
//lineas vacias

		cout << "Linea " << leidas << ": " << linea << endl; //miestra en el programa las curps
	    bool valine=true;//declaro el valor verdadero para que el siguiente ine inicie como verdadero hasta encontrarle falla
	   
if (linea.size() != 18)
    valine = false;

// Letras iniciales
for (int i = 0; i <= 3; i++)
    if (!isalpha(linea[i]) || !isupper(linea[i]))
        valine = false;

// Fecha
for (int i = 4; i <= 9; i++)
    if (!isdigit(linea[i]))
        valine = false;

// Sexo
if (linea[10] != 'H' && linea[10] != 'M')
    valine = false;

// Estado
string estados[] = {
    "AS","BC","BS","CC","CS","CH","CL","CM","DG","GT","GR",
    "HG","JC","MC","MN","MS","NT","NL","OC","PL","QT","QR",
    "SP","SL","SR","TC","TS","TL","VZ","YN","ZS","NE"
};

bool estadoValido = false;
string estado = linea.substr(11, 2);

for (int i = 0; i < 32; i++)
    if (estado == estados[i]) estadoValido = true;

if (!estadoValido)
    valine = false;

// Consonantes
for (int i = 13; i <= 15; i++)
    if (!isalpha(linea[i]) ||
        linea[i]=='A'||linea[i]=='E'||linea[i]=='I'||linea[i]=='O'||linea[i]=='U')
        valine = false;

// Homoclave
if (!isalnum(linea[16]) || !isalnum(linea[17]))
    valine = false;
									
									
			if(valine==true){	//imprimir linea y valido
			salida << linea << " -> INE VALIDO\n";
		}else if(valcurp==false){//imprimir linea e invalido
			salida << linea << " -> INE INVALIDO\n";
		}						
									
///INE
}//while

//espacio para mas case 

}//switch
	
fich.close();
		salida.close();
		system("TxTsalida.txt");
	 



cout << "\nDesea reintentar? (S/N): ";
		cin >> op;
			system("cls");
    } while (op == 'S' || op=='s');
	
	


}

