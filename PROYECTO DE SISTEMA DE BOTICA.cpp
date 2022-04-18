#include <iostream>
#include <iomanip>
using namespace std;


struct Medicamentos { 
	int codMedi;
	char nombre[10];
	char denGenerica[10];
	int cant;
	char receta[2];
	int codProvee;
};

struct Clientes { 
	int dni;
	char nombre[15];  
	char apellidos[15];
	int edad;
};

struct Proveedores{ 
	int codProvee;
	char nombreLabo[15];
	char nombreEncar[20];
	int telefono;
};

struct Venta {  
	int codVenta;
	int dni;
	int fechadia;
	int fechames;
	int fechaanio;
};

struct DetalleVenta { 
	int codVenta;
	int codMedi; 
	int precioUni;
    int cant;
};

int menuPrincipal();
void menuMedicamentos();
void menuClientes();
void menuProveedores();
void menuVenta();
int ingrese();
void salir();
void selec(int opc);
void crearProveedores(FILE *F);
void ingresarProveedores(FILE *F, Proveedores regN);
void mostrarProveedores(FILE *F, Proveedores regN);
void buscarProveedores(FILE *F,Proveedores regN);
void crearVenta(FILE *VENT);
void crearDetalleVenta(FILE *DVENT);
void crearMedicamentos(FILE *MED);
void ingresarVenta(FILE *VENT, Venta vent);
void ingresarDetalleVenta(FILE *DVENT, DetalleVenta detvent);
void ingresarMedicamentos(FILE *MED,Medicamentos med);
void mostrarVenta(FILE *VENT, Venta vent);
void mostrarDetalleVenta(FILE *DVENT, DetalleVenta detvent);
void mostrarMedicamentos(FILE *MED, Medicamentos med);
int productosStock(FILE *MED, Medicamentos med, FILE *DVENT, DetalleVenta detvent);
void mensajeStock(FILE *MED, Medicamentos med, FILE *DVENT, DetalleVenta detvent);
void mostrarCantidadSobrante(FILE *MED, Medicamentos med, FILE *DVENT, DetalleVenta detvent);
void salir();
void crearClientes(FILE *CLIENTE);
void registrarClientes(FILE *CLIENTE, Clientes cliente);
void mostrarClientes(FILE *CLIENTE,Clientes cliente);
void mostrarClientesBeneficiados(FILE *CLIENTES, Clientes cliente);
float gananciasTotales(FILE *DVENT,FILE *CLIENTES,FILE *VENTA,DetalleVenta detvent,Clientes cliente,Venta Vent);
void mensajegananciasTotales(FILE *DVENT,FILE *CLIENTES,FILE *VENTA,DetalleVenta detvent,Clientes cliente,Venta Vent);

int main(){
	int opc;	
	selec(opc);
}

int ingrese(){
	int opc;
	cout<<"	\t\t\t\t\tElija una opcion :";
	cin>>opc;
	return opc;
}

void menuMedicamentos(){
	FILE *MED, *DVENT;
	Medicamentos med;
	DetalleVenta detvent;
	int opc;
	do{
		system("cls");
		cout<<"			================================================================\n";
		cout<<"	\t\t\t\tBienvenido al Menu de Medicamentos\n";
		cout<<"			================================================================\n";
		cout<<"	\t\t\t\t1) Crear archivo Medicamentos\n";
		cout<<"	\t\t\t\t2) Registrar Medicamentos\n";
		cout<<"	\t\t\t\t3) Mostrar Medicamentos \n";
		cout<<"	\t\t\t\t4) Stock de Medicamentos \n";
		cout<<"	\t\t\t\t5) Cantidad sobrante de Medicamentos por codigo \n";
		cout<<"	\t\t\t\t0) Regresar al menu principal \n";
		cout<<"			================================================================\n";
		opc=ingrese();
		switch(opc){
			case 1: crearMedicamentos(MED); break;
			case 2: ingresarMedicamentos(MED,med); break;
			case 3: mostrarMedicamentos(MED,med); break;
			case 4: mensajeStock(MED, med,DVENT,detvent); break;
			case 5: mostrarCantidadSobrante(MED, med, DVENT, detvent);break;
			case 0: break;
		}
		if(opc!=0)
			system("Pause");
	} while(opc!=0);

}
void menuClientes(){
	int opc;
	FILE *CLIENTES;
	Clientes cliente;
	do{
		system("cls");
		cout<<"			================================================================\n";
		cout<<"	\t\t\t\tBienvenido al Menu de Clientes\n";
		cout<<"			================================================================\n";
		cout<<"	\t\t\t\t1) Crear archivo Clientes\n";
		cout<<"	\t\t\t\t2) Registrar clientes\n";
		cout<<"	\t\t\t\t3) Mostrar Clientes \n";
		cout<<"	\t\t\t\t4) Mostrar Clientes Beneficiados y No Beneficiados\n";
		cout<<"	\t\t\t\t0) Salir";
		cout<<"			================================================================\n";
		opc=ingrese();
		switch(opc){
			case 1: crearClientes(CLIENTES);break;
			case 2: registrarClientes(CLIENTES, cliente);break;
			case 3: mostrarClientes(CLIENTES, cliente);break;
			case 4: mostrarClientesBeneficiados(CLIENTES, cliente);break;
			case 0: break;
		}
		if(opc!=0)
			system("Pause");
	
	} while(opc!=0);
}
void menuProveedores(){
	int opc;
	FILE *F;
	Proveedores regN;
	do{
		system("cls");
		cout<<"			================================================================\n";
		cout<<"	\t\t\t\tBienvenido al Menu de Proveedores\n";
		cout<<"			================================================================\n";
		cout<<"	\t\t\t\t1) Crear archivo Proveedores\n";
		cout<<"	\t\t\t\t2) Registrar Proveedores\n";
		cout<<"	\t\t\t\t3) Mostrar Proveedores \n";
		cout<<"	\t\t\t\t4) Buscar Proveedores \n";
		cout<<"	\t\t\t\t0) Regresar al menu principal \n";
		cout<<"			================================================================\n";
		opc=ingrese();
		switch(opc){
			case 1:	crearProveedores(F); break;
			case 2: ingresarProveedores(F,regN); break;
			case 3: mostrarProveedores(F,regN); break;
			case 4: buscarProveedores(F,regN); break;
			case 0:	break;
		}
		if(opc!=0)
			system("Pause");
		
	} while( opc != 0);	
}
void menuVenta(){
	int opc;
	FILE *VENT,*DVENT, *CLIENTES;
	Venta vent;
	Clientes cliente;
	DetalleVenta detvent;
	do{
		system("cls");
		cout<<"			================================================================\n";
		cout<<"	\t\t\t\tBienvenido al Menu de Ventas\n";
		cout<<"			================================================================\n";
		cout<<"	\t\t\t\t1) Crear archivo Ventas\n";
		cout<<"	\t\t\t\t2) Crear archivo Detalle Ventas\n";
		cout<<"	\t\t\t\t3) Registrar Ventas\n";
		cout<<"	\t\t\t\t4) Registrar Detalle Ventas\n";
		cout<<"	\t\t\t\t5) Mostrar Ventas \n";
		cout<<"	\t\t\t\t6) Mostrar Detalle Ventas \n";
		cout<<"	\t\t\t\t7) Mostrar Ganancias Totales \n";
		cout<<"	\t\t\t\t0) Regresar al menu principal \n";
		cout<<"			================================================================\n";
		opc=ingrese();
		switch(opc){
			case 1: crearVenta(VENT); break;
			case 2: crearDetalleVenta(DVENT); break;
			case 3: ingresarVenta(VENT,vent); break;
			case 4: ingresarDetalleVenta(DVENT,detvent); break;
			case 5: mostrarVenta(VENT,vent); break;
			case 6: mostrarDetalleVenta(DVENT,detvent); break;
			case 7: mensajegananciasTotales(DVENT,CLIENTES,VENT,detvent,cliente,vent);break;
			case 0: break;
		}
		if(opc!=0)
			system("Pause");
	} while(opc!=0);
		
}
int menuPrincipal(){
	system("cls");
	cout<<"			================================================================\n";
	cout<<"	\t\t\t\tBienvenido al sistema de boticas\n";
	cout<<"			================================================================\n";
	cout<<"	\t\t\t\tMenu Principal:\n";
	cout<<"	\t\t\t\t1) Medicamentos\n";
	cout<<"	\t\t\t\t2) Clientes\n";
	cout<<"	\t\t\t\t3) Proveedores \n";
	cout<<"	\t\t\t\t4) Ventas \n";
	cout<<"	\t\t\t\t0) Salir\n";
	cout<<"			================================================================\n";
	ingrese();
}

void selec(int opc){
	do{
		system("cls");
		opc=menuPrincipal();
		switch(opc){
			case 1: menuMedicamentos(); break;
			case 2: menuClientes(); break;
			case 3: menuProveedores(); break;
			case 4:	menuVenta(); break;
			case 0: salir(); break;
		}
	
	}while(opc!=0);
}
void crearProveedores(FILE *F){
	F=fopen("c:Registro de Proveedores.txt","w");
	if (F==NULL)
		cout<<"No se puede crear el archivo Registro de Proveedores \n";
	else {
		cout<<"Creacion exitosa \n";
		fclose(F);
	}
}
void ingresarProveedores(FILE *F, Proveedores regN){
	char temp[2];
	cout<<"Registro de nuevo Proveedor \n";
	cout<<"Digite datos del Proveedor \n";
	cout<<"Codigo : "; cin>>regN.codProvee;
	gets(temp);
	cout<<"Laboratorio : "; gets(regN.nombreLabo);
	cout<<"Encargo : "; gets(regN.nombreEncar);
	cout<<"Telefono : "; cin>>regN.telefono;

	F=fopen("c:Registro de Proveedores.txt","a");
	if (F!=NULL){
		fwrite(&regN,sizeof(regN),1,F);
		if (!ferror(F))
			fclose(F);
		else
			cout<<"Error en la escritura\n";
	}
	else
		cout<<"No se puede abrir el archivo \n";
}
void mostrarProveedores(FILE *F,Proveedores regN){
	system("cls");
	F=fopen("c:Registro de Proveedores.txt","r");
	if (F!=NULL){
		cout<<"\n\n";
		cout << "\t\t\t       ===================================================="<<endl;
		cout << "\t\t\t       | Codigo |   Laboratorio   |   Encargo   | Telefono|" << endl;
		cout << "\t\t\t       ===================================================="<<endl;
		while (!feof(F)){
			fread(&regN,sizeof(regN),1,F);
			if (!ferror(F)){
				if(!feof(F)){
					
					cout <<"\t\t\t       |"<<setw(8); cout<<regN.codProvee<<"|";
					cout<< setw(17); cout<<regN.nombreLabo<<"|";
					cout<< setw(13); cout<<regN.nombreEncar<<"|";
					cout<<setw(9); cout<<regN.telefono<<"|"<<endl;
					cout<<"			       ----------------------------------------------------\n";
				}
			}
			else
				cout<<"Error en la lectura del registro \n";
		}
		fclose(F);
	}
	else
		cout<<"No se puede abrir el archivo Registro de Proveedores \n";
}
void buscarProveedores(FILE *F,Proveedores regN)
{
	int r;
	bool encontrado;
	encontrado=false;
	cout<<"Digite el codigo a buscar: ";
	cin>>r;
	F=fopen("c:Registro de Proveedores.txt","r");
	if (F!=NULL){
		while (!feof(F)){
			fread(&regN,sizeof(regN),1,F);
			if (!ferror(F)){
				if(!feof(F)){
					if(r==regN.codProvee){
						encontrado=true;
						cout<<" \t\t\t\tSe ha encontrado el registro:\n";
						cout<<" \t\t\t\t=============================\n";
						cout<<"	\t\t\t\tCodigo : "; cout<<regN.codProvee<<"\n";
						cout<<"	\t\t\t\tLaboratorio : "; cout<<regN.nombreLabo<<"\n";
						cout<<"	\t\t\t\tEncargo: "; cout<<regN.nombreEncar<<"\n";
						cout<<"	\t\t\t\tTelefono : "; cout<<regN.telefono<<"\n";	
					}
				}
				
			}
			else
				cout<<"Error en la lectura del registro \n";
	
		}
		if(encontrado==false)
			cout<<"No se ha podido encontrar el codigo digitado\n";
		fclose(F);
		
	}
	else
		cout<<"No se puede abrir el archivo Registro de Proveedores \n";
	

}
void salir(){
	cout<<" \t\t\t\t\tGracias por usar nuestros servicios :)\n";
}


void crearVenta(FILE *VENT){
	VENT = fopen("c:Venta.txt","w"); 
	if(VENT!=NULL){
		cout<<"Archivo de ventas creado exitosamente"<<endl;
		fclose(VENT);
	}else{
		cout<<"No se pudo abrir el archivo de ventas"<<endl;
	}
}

void crearDetalleVenta(FILE *DVENT){
	DVENT = fopen("c:DetalleVenta.txt","w");
	if(DVENT!=NULL){
		cout<<"Archivo de ventas creado exitosamente"<<endl;
		fclose(DVENT);
	}else{
		cout<<"No se pudo abrir el archivo de ventas"<<endl;
	}
}

void crearMedicamentos(FILE *MED){
	MED = fopen("c:Medicamentos.txt","w");
	if(MED!=NULL){
		cout<<"Archivo de medicamentos creado exitosamente"<<endl;
		fclose(MED);
	}else{
		cout<<"No se pudo abrir el archivo de medicamentos"<<endl;
	}
}

void ingresarVenta(FILE *VENT, Venta vent){
	cout<<"======================================================"<<endl;
	cout<<"   Ingreso de nueva venta"<<endl;
	cout<<"   Ingrese el codigo de venta           ----> ";cin>>vent.codVenta;
	cout<<"   Ingrese el numero de DNI del cliente ----> ";cin>>vent.dni;
	cout<<"   Ingrese el dia de venta              ----> ";cin>>vent.fechadia;
	cout<<"   Ingrese el mes de venta              ----> ";cin>>vent.fechames;
	cout<<"   Ingrese el anio de venta             ----> ";cin>>vent.fechaanio;
	cout<<"======================================================"<<endl;
	VENT = fopen("c:Venta.txt","a");
	if(VENT!=NULL){
		fwrite(&vent,sizeof(vent),1,VENT);
		if(ferror(VENT)){
			cout<<"Ocurrio un error en el ingreso de la venta"<<endl;
		}
		    cout<<"Registro guardado exitosamente"<<endl;
		    fclose(VENT);
	}else{
		cout<<"No se ha podido abrir el archivo de ventas"<<endl;
	}
}

void ingresarDetalleVenta(FILE *DVENT, DetalleVenta detvent){
	cout<<"==============================================================="<<endl;
	cout<<"   Ingreso los detalles de la venta "<<endl;
	cout<<"   Ingrese el codigo de venta                 ----> ";cin>>detvent.codVenta;
	cout<<"   Ingrese el codigo del medicamento          ----> ";cin>>detvent.codMedi;
	cout<<"   Ingrese el precio unitario del medicamento ----> ";cin>>detvent.precioUni;
	cout<<"   Ingrese la cantidad que se va adquirida    ----> ";cin>>detvent.cant;
	cout<<"==============================================================="<<endl;
	DVENT = fopen("c:DetalleVenta.txt","a");
	if(DVENT!=NULL){
		fwrite(&detvent,sizeof(detvent),1,DVENT);
		if(ferror(DVENT)){
			cout<<"Ocurrio un error en el ingreso de los detalles de la venta"<<endl;
		}
		    cout<<"Registro guardado exitosamente"<<endl;
		    fclose(DVENT);
	}else{
		cout<<"No se ha podido abrir el archivo de ventas"<<endl;
	}	
}

void ingresarMedicamentos(FILE *MED,Medicamentos med){
	char opc;
	char temp[2];
	int canti = 0;
	do{
		if(canti == 40){
		cout<<"Se ingresó la cantidad maxima de medicamentos\n";
		break; 
		}
	cout<<"=============================================================================================="<<endl;
	cout<<"       						INGRESO DE NUEVA MEDICINA             							 "<<endl;
	cout<<"=============================================================================================="<<endl;
	cout<<"Por favor digite los siguientes datos"<<endl;
	cout<<"Codigo del medicamento: "; cin>>med.codMedi;
	fflush(stdin);
	//gets(temp);
	cout<<"Nombre del medicamento: "; cin>>med.nombre;
	cout<<"Ingrese la denominacion generica del medicamento: "; cin>>med.denGenerica;
	cout<<"Requiere receta: "; cin>>med.receta;
	cout<<"Cantidad: "; cin>>med.cant;
    cout<<"Ingrese el codigo del proveedor: "; cin>>med.codProvee;
    cout<<"============================================"<<endl;
    cout<<"Desea ingresar otro medicamento? (s/n)";
		cin>>opc;
		canti++;
	} while(opc == 's' || opc == 'S' && canti < 40);


	MED=fopen("c:Medicamentos.txt","a");
	if(MED!=NULL){
		fwrite(&med,sizeof(med),1,MED);
		 if(!ferror(MED)){
		 	cout<<"Registro guardado exitosamente"<<endl;
			fclose(MED);
		 }else{
			cout<<"Ocurrio un error"<<endl;
		 }
	}else{
		cout<<"No se puede abrir el archivo"<<endl;
	}
}



void mostrarVenta(FILE *VENT, Venta vent){
	cout<<" Mostrar todas las ventas "<<endl;
	VENT = fopen("c:Venta.txt","r");
	cout<<"======================================="<<endl;
	if(VENT!=NULL){
		while(!feof(VENT)){
			fread(&vent,sizeof(vent),1,VENT);
			if(!ferror(VENT)){
				if(!feof(VENT)){
					
					cout<<" Codigo de venta: ";
					cout<<vent.codVenta<<endl;
					cout<<" Numero de DNI del cliente: ";
					cout<<vent.dni<<endl;
					cout<<" Dia: ";
					cout<<vent.fechadia<<endl;
					cout<<" Mes: ";
					cout<<vent.fechames<<endl;
					cout<<" Anio: ";
					cout<<vent.fechaanio<<endl;
					cout<<"============================="<<endl;
				}
			}else{
				cout<<"Ocurrio un error en la muestra "<<endl;
			}
		} fclose(VENT);
	}else{
		cout<<"No se ha podido abrir el archivo ";
	}
}

void mostrarDetalleVenta(FILE *DVENT, DetalleVenta detvent){
	cout<<"Mostrar todos los detalles de ventas "<<endl;
	DVENT = fopen("c:DetalleVenta.txt","r");
	cout<<"======================================="<<endl;
	if(DVENT!=NULL){
		cout<<"\n\n";
		cout << "\t\t\t       ==================================================================================================="<<endl;                 
		cout << "\t\t\t       | Codigo de Venta | Codigo del Medicamento | Precio Unitario del Medicamento | Cantidad adquirida |" << endl;               
		cout << "\t\t\t       ==================================================================================================="<<endl;       
		cout<<"No se pudo abrir el archivo de medicamentos"<<endl;
		while(!feof(DVENT)){
			fread(&detvent,sizeof(detvent),1,DVENT);
			if(!ferror(DVENT)){
				if(!feof(DVENT)){
					cout <<"\t\t\t       |"<<setw(17);cout<<detvent.codVenta<<"|";
					cout<< setw(24);cout<<detvent.codMedi<<"|";;
					cout<< setw(33);cout<<detvent.precioUni<<"|";;
					cout<< setw(20);cout<<detvent.cant<<"|";;
					cout<<"============================="<<endl;
				}
			}else{
				cout<<"Ocurrio un error en la muestra "<<endl;
			}
		} fclose(DVENT);
	}else{
		cout<<"No se ha podido abrir el archivo ";
	}
}

void mostrarMedicamentos(FILE *MED, Medicamentos med){
   cout<<"Mostrar todos los detalles de los medicamentos"<<endl;
   system("cls");
   MED = fopen("c:Medicamentos.txt","r");
   if(MED!=NULL){
   		cout<<"\n\n";
		cout << "\t\t\t       ==========================================================================================="<<endl;                 
		cout << "\t\t\t       | Codigo |      Nombre     |   Denominacion   | Receta | Cantidad  | Codigo del Proveedor |" << endl;               
		cout << "\t\t\t       ============================================================================================"<<endl;       
   	 while (!feof(MED)){
			fread(&med,sizeof(med),1,MED);
			if (!ferror(MED)){
				if(!feof(MED)){
					cout <<"\t\t\t       |"<<setw(8); cout<<med.codMedi<<"|";
					cout<< setw(17); cout<<med.nombre<<"|";
					cout<< setw(18); cout<<med.denGenerica<<"|";
					cout<< setw(8); cout<<med.receta<<"|";
					cout<< setw(11); cout<<med.cant<<"|";
					cout<< setw(22); cout<<med.codProvee<<"|";
					cout<<"			       ----------------------------------------------------\n";
				}
			}
			else
				cout<<"Error en la lectura del registro \n";
		}
		fclose(MED);
    }
	else{
    	cout<<"No se puede abrir el archivo Registro de Medicamentos \n";
 	  }
}
int productosStock(FILE *MED, Medicamentos med, FILE *DVENT, DetalleVenta detvent){
	int aux;
	int aux1 = 0;
	int aux2;
	cout<<"Digite el codigo del medicamento: "; cin>>aux;
	DVENT = fopen("c:DetalleVenta.txt","r");
	if(DVENT==NULL){
		cout<<"No se pudo abrir el archivo de detalles de venta"<<endl;
	}else{
	while(!feof(DVENT)){
	    fread(&detvent,sizeof(detvent),1,DVENT);
		if(ferror(DVENT)){
			cout<<"No se puede mostrar los datos"<<endl;
		}else{
		 if(!feof(DVENT)){
		 	if(aux==detvent.codMedi){
		 		aux1 = aux1 + detvent.cant;
			 }
		 }	
		}	
	   }fclose(DVENT);
	}
	MED = fopen("c:Medicamentos.txt","r");
	if(MED==NULL){
		cout<<"No se pudo abrir el archivo de medicamentos"<<endl;
	}else{
	while(!feof(MED)){
	    fread(&med,sizeof(med),1,MED);
		if(ferror(MED)){
			cout<<"No se puede mostrar los datos"<<endl;
		}else{
		 if(!feof(MED)){
		 	if(aux==med.codMedi){
			    aux2 = med.cant - aux1; 
			}
		 }	
		}	
	   }fclose(MED);
	}

	return aux2;
}

void mensajeStock(FILE *MED, Medicamentos med, FILE *DVENT, DetalleVenta detvent){
	int hola;
	hola = productosStock(MED, med, DVENT, detvent);
	cout<<"El numero de medicamentos que quedan es: "<<hola<<endl;
	if(hola==0){
		cout<<"El medicamento se agoto "<<endl;
	}
}

void mostrarCantidadSobrante(FILE *MED, Medicamentos med, FILE *DVENT, DetalleVenta detvent){
	int cantidadTotalV,aux[50],suma = 0,aux1[50],aux2,j=0,i=0,sobrante;
	cout<<"| Nombre del medicamento   |      Codigo      |   Cantidad sobrante   |"<<endl;
	DVENT = fopen("c:DetalleVenta.txt","r");
	if(DVENT==NULL){
		cout<<"El archivo de detalles de venta no se pudo abrir "<<endl;
	}else{
		while(!feof(DVENT)){
			fread(&detvent,sizeof(detvent),1,DVENT);
			if(ferror(DVENT)){
				cout<<"No se pueden mostrar los datos del archivo detalles de venta "<<endl;
			}else{
				if(!feof(DVENT)){
					aux[i] = detvent.codMedi; //vector para q se almacenen los codigos de los medicamentos ya q pueden cambiar dependiendo de la venta 
					aux1[i] = detvent.cant; //vector para almacenar la cantidad de un medicamento que se ha adquirido
					i++;
				}
			}
		}fclose(DVENT);
	}
	aux2 = i; //el total de posiciones que ha debido usar el vector aux para almacenar los diversos codigos de los medicamentos que han sido vendidos
	MED = fopen("c:Medicamentos.txt","r");//abrimos el archivo med para poder restar la cantidad incial con la cantidad que se ha vendido
	if(MED==NULL){
		cout<<"El archivo de medicamentos no se ha podido abrir "<<endl;
	}else{
	   while(!feof(MED)){
			fread(&med,sizeof(med),1,MED);
			if(ferror(MED)){
				cout<<"No se pueden mostrar los datos de los medicamentos "<<endl;
			}else{
				if(!feof(MED)){
					cantidadTotalV = 0; //para que en cada medicamento no se almacene el cantidadTotalV del anterior medicamento si no del nuevo al q vamos a evaluar 
					     for(int i=0;i<aux2;i++){
						      if(aux[i]==med.codMedi){//va a evaluar los codigos de los medicamentos que fueron digitados en el detalle de venta y //sumaremos las cantidades que fueron vendidas en base a la posicion
							      cantidadTotalV = cantidadTotalV + aux1[i]; //dentro del cantidadTotalV se van a acumular la cantidad de veces q pedimos un medicamento en los detalles de venta a traves aux1[i]
						    }
					     }
					sobrante = med.cant - cantidadTotalV;//aqui restamos la cantidad que al inicio pusimos al ingresar el medicamento (med.cant) con la cantidadTotalV que es la acumulacion de distintos detalles de 
					//venta que pidieron los clientes y la resta seria la cantidad que queda en la botica. 
					cout<<"  "<<med.nombre<<"                      "<<med.codMedi<<"                     "<<sobrante<<"          "<<endl;
					cout<<"======================================================================="<<endl;
				//creamos el vector sobrante para almacenar la cantidad que queda por medicamento en la botica
				}
			}
		}fclose(MED);
	}
}

float gananciasTotales(FILE *DVENT,FILE *CLIENTES,FILE *VENTA,DetalleVenta detvent,Clientes Clientes,Venta Venta){
	int cantidadTotalV,suma = 0,j=0,i=0,sobrante,DetventTotales,precioClientes[50],edadClientes[50];
	int k=0,m=0,aux1=0,aux2=0,dniClientes[50],codigoVenta[50],dniClientesVenta[50];
	float importe[50],sumaGanT=0;
	CLIENTES = fopen("c:Clientes.txt","r");
	if(CLIENTES==NULL){
		cout<<"El archivo de Clientes no se pudo abrir "<<endl;
	}else{
		while(!feof(CLIENTES)){
			fread(&Clientes,sizeof(Clientes),1,CLIENTES);
			if(ferror(CLIENTES)){
				cout<<"No se pueden mostrar el archivo Clientes "<<endl;
			}
			else{
				if(!feof(CLIENTES)){
					dniClientes[k]=Clientes.dni;
					edadClientes[k]=Clientes.edad;
					k++;
				}
			}
		}fclose(CLIENTES);
	}
	aux1=k;
	VENTA=fopen("c:Venta.txt","r");
	if(VENTA==NULL){
		cout<<"El archivo Venta no se pudo abrir "<<endl;
	}else{
		while(!feof(VENTA)){
			fread(&Venta,sizeof(Venta),1,VENTA);
			if(ferror(VENTA)){
				cout<<" No se puede mostrar el archivo Venta "<<endl;
			}else{
				if(!feof(VENTA)){
					codigoVenta[m]=Venta.codVenta;
					dniClientesVenta[m]=Venta.dni;
					m++;
				}
			}
		}fclose(VENTA);
	}
	aux2=m;
	DVENT=fopen("c:DetalleVenta.txt","r");
	if(DVENT==NULL){
		cout<<"El archivo de Detalle Venta no se pudo abrir "<<endl;
	}else{
		while(!feof(DVENT)){
			fread(&detvent,sizeof(detvent),1,DVENT);
			if(ferror(DVENT)){
				cout<<"No se pueden mostrar los datos del archivo detalles de venta "<<endl;
			}else{
				if(!feof(DVENT)){
					for(int r=0;r<m;r++){
						for(int t=0;t<k;t++){
							if(detvent.codVenta==codigoVenta[r]){
								if(dniClientesVenta[r]==dniClientes[t]){
									if(edadClientes[t]>65){
										importe[i]=detvent.cant*detvent.precioUni*0.9;
									}else{
										importe[i]=detvent.cant*detvent.precioUni;
	  								}i++;
								}
							}
						}
					}
				}
			}
		}fclose(DVENT);
	}
    DetventTotales = i;
    for(i=0;i<DetventTotales;i++){
    	sumaGanT = sumaGanT + importe[i];
	}
	return sumaGanT;
}

void mensajegananciasTotales(FILE *DVENT,FILE *CLIENTES,FILE *VENTA,DetalleVenta detvent,Clientes Clientes,Venta Venta){
	float mensaje;
	mensaje = gananciasTotales(DVENT,CLIENTES,VENTA,detvent,Clientes,Venta);
	cout<<"Las ganancias totales son de: "<<mensaje<<endl;
}

void crearClientes(FILE *CLIENTES){
	CLIENTES=fopen("C:Clientes.txt","w");
	if(CLIENTES==NULL)
	cout<<"No se puede abrir archivos Clientes\n";
	else{
		cout<<"Creacion exitosa\n";
		fclose(CLIENTES);
	}
}

void registrarClientes(FILE *CLIENTES, Clientes cliente){
	char temp[2];
	cout<<" Ingreso de nuevo cliente "<<endl;
	cout<<" Digite datos del cliente "<<endl;
	cout<<" DNI: ";
	cin>>cliente.dni;
	gets(temp);
	cout<<" Nombres: ";
	gets(cliente.nombre);
	cout<<" Apellidos: ";
	gets(cliente.apellidos);
	cout<<" Edad: ";
	cin>>cliente.edad;
	CLIENTES=fopen("c:Clientes.txt","a");
	if(CLIENTES!=NULL){
		fwrite(&cliente,sizeof(cliente),1,CLIENTES);
		if(!ferror(CLIENTES))
			fclose(CLIENTES);
		else
			cout<<"Error de escritura en archivo Clientes\n";
	}
	else{
		cout<<"No se puede abrir el archivo Clientes\n";
	}
}

void mostrarClientes(FILE *CLIENTES,Clientes cliente){
	system("cls");
	CLIENTES=fopen("c:Clientes.txt","r");
	if(CLIENTES!=NULL){
			cout<<"\n\n";
			cout << "\t\t\t       ======================================================="<<endl;                 
			cout << "\t\t\t       |   DNI   |    Nombre    |     Apellidos     |  Edad  |"<< endl;               
			cout << "\t\t\t       ========================================================"<<endl;
			while(!feof(CLIENTES)){
				fread(&cliente,sizeof(cliente),1,CLIENTES);
				if(!ferror(CLIENTES)){
					if(!feof(CLIENTES)){
						cout <<"\t\t\t       |"<<setw(9);cout<<cliente.dni<<"|";
						cout<< setw(14); cout<<cliente.nombre<<"|";
						cout<< setw(19); cout<<cliente.apellidos<<"|";
						cout<< setw(8);cout<<cliente.edad<<"|";
						cout<<"==========================================================================\n";
					}
				}
				else
					cout<<"Error en la lectura del archivo Clientes\n";
			}
			fclose(CLIENTES);
	}
	else
		cout<<"No se puede abrir el archivo Clientes \n";
}

void mostrarClientesBeneficiados(FILE *CLIENTES, Clientes cliente){
	system("cls");
	CLIENTES=fopen("C:Clientes.txt","r");
	if(CLIENTES!=NULL){
			cout<<"\n\n";     
			cout << "\t\t\t       ======================================================="<<endl;                 
			cout << "\t\t\t       |   DNI   |    Nombre    |     Apellidos     |  Edad  |"<< endl;               
			cout << "\t\t\t       ========================================================"<<endl;       
		while(!feof(CLIENTES)){
			fread(&cliente,sizeof(cliente),1,CLIENTES);
			if(!ferror(CLIENTES)){
				if(!feof(CLIENTES)){
					if(cliente.edad>65){
			           cout<< "\t\t\t            CLIENTES BENEFICIADOS            \n";
			           cout<<"DNI: "<<cliente.dni<<"\n";
			           cout<<"Nombre: "<<cliente.nombre<<"\n";
			           cout<<"Apellidos: "<<cliente.apellidos<<"\n";
			           cout<<"Edad: "<<cliente.edad<<"\n";
			           cout<<"==========================================================================\n";	
			           }else{
			           cout<< "\t\t\t            CLIENTES NO BENEFICIADOS            \n";
			           cout<<"DNI: "<<cliente.dni<<"\n";
			           cout<<"Nombre: "<<cliente.nombre<<"\n";
			           cout<<"Apellidos: "<<cliente.apellidos<<"\n";
			           cout<<"Edad: "<<cliente.edad<<"\n";
			           cout<<"==========================================================================\n";
			           }
			    }
			    }else{
			    cout<<"Ocurrio un error en la lectura"<<endl;
				}
        }fclose(CLIENTES);
		}else{
      	cout<<"No se ha podido abrir el archivo "<<endl;
	}
  }



