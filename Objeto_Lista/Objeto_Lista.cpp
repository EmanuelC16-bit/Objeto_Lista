#include "iostream"
#include "conio.h"
using namespace std;

struct Nodo
{
public:
	int dato;
	Nodo* siguiente;
};

class Pila
{
public:
	Nodo* indice, * temporal, * cursor;
	int numeroBusqueda;
	void imprimirDatos();
	void altas();
	void bajas();
	void modificar();
	bool busqueda();
	Pila();
	~Pila() {};
};

Pila::Pila()
{
	indice = new (Nodo);
	indice = NULL;
}

void Pila::imprimirDatos()
{
	int i = 0;
	cursor = indice;
	cout << "A continuacion se mostraran los datos de 3 en 3. Pulse una tecla para ver los siguientes 3\n";
	while (cursor != NULL)
	{
		system("CLS");
		i = 0;
		while (cursor != NULL && i < 3)
		{
			cout << cursor->dato << "\n";
			cursor = cursor->siguiente;
			i++;
		}
		_getch();
	}
}

void Pila::altas()
{
	cout << "Ingresa el dato:\t";

	temporal = new (Nodo);
	cin >> temporal->dato;
	temporal->siguiente = NULL;
	if (indice == NULL)
	{
		indice = temporal;
	}
	else
	{
		cursor = indice;
		while (cursor->siguiente != NULL)
		{
			cursor = cursor->siguiente;
		}
		cursor->siguiente = temporal;
	}
}

void Pila::bajas()
{
	bool eliminar = false;
	cursor = indice;
	if ((indice->siguiente == NULL) && (indice->dato == numeroBusqueda))
	{
		delete cursor;
		indice = NULL;
		cout << "\n Se ha eliminado el dato\t" << numeroBusqueda << "\n\n";
	}
	else
	{
		if (indice->dato == numeroBusqueda)
		{
			indice = cursor->siguiente;
			cout << "\n Se ha eliminado el dato\t" << numeroBusqueda << "\n\n";
		}
		else
		{
			eliminar = busqueda();
			if (eliminar)
			{
				cursor->siguiente = temporal->siguiente;
				delete temporal;
				cout << "\n Se ha eliminado el dato\t" << numeroBusqueda << "\n\n";
			}
			else
			{
				cout << "No se ha encontrado el dato\t" << numeroBusqueda << "\ten la lista";
			}
		}
	}
}

bool Pila::busqueda()
{
	cursor = indice;
	while (cursor->siguiente != NULL)
	{
		if (indice->siguiente == NULL)
		{
			return (indice->dato == numeroBusqueda) ? true : false;
		}
		else
		{
			if (cursor->dato == numeroBusqueda)
			{
				return true;
			}
			else
			{
				if (cursor->siguiente->dato == numeroBusqueda)
				{
					temporal = cursor->siguiente;
					return true;
				}
				cursor = cursor->siguiente;
			}
		}
	}
	return false;
}

void Pila::modificar()
{
	bool modificar = false;
	if ((indice->siguiente == NULL) && (indice->dato == numeroBusqueda))
	{
		cout << "Ingresa el nuevo dato\t";
		cin >> indice->dato;
	}
	else
	{
		if (indice->dato == numeroBusqueda)
		{
			cout << "Ingresa el nuevo dato\t";
			cin >> indice->dato;
			cout << "\n Se ha modificado el dato\n\n";
		}
		else
		{
			modificar = busqueda();
			if (modificar)
			{
				cout << "Ingresa el nuevo dato\t";
				cin >> temporal->dato;
				cout << "\n Se ha modificado el dato\n\n";
			}
			else
			{
				cout << "No se ha encontrado el dato\t" << numeroBusqueda << "\ten la lista";
			}
		}
	}

}

int main()
{
	int operacion, OPT = 0, numeroBusqueda = 0;
	bool encontrado = false;
	Pila objetoA;
	system("CLS");
	do
	{
		system("CLS");
		cout << "Selecciona la opcion:\n[1] Altas.\n[2] Bajas.\n[3] Modificar.\n[4] Ver (3).\n[5] Buscar.\n[6] Salir.\n\n";
		cin >> operacion;
		system("CLS");
		if (operacion == 2 || operacion == 3 || operacion == 4 || operacion == 5)
		{
			if (objetoA.indice == NULL)
			{
				cout << "Opcion no disponible. No hay datos en la lista\n\n";
				operacion = 6;
			}
		}
		switch (operacion)
		{
		case 1:
			objetoA.altas();
			break;

		case 2:
			cout << "Ingresa el numero que quieres eliminar\t";
			cin >> objetoA.numeroBusqueda;
			objetoA.bajas();
			break;

		case 3:
			cout << "Ingresa el numero que quieres modificar\t";
			cin >> objetoA.numeroBusqueda;
			objetoA.modificar();
			break;

		case 4:
			objetoA.imprimirDatos();
			break;

		case 5:
			cout << "Ingresa el numero que quieres buscar\t";
			cin >> objetoA.numeroBusqueda;
			encontrado = objetoA.busqueda();
			(encontrado == true) ? cout << "\n\nDato encontrado" : cout << "No se ha encontrado el dato\t" << objetoA.numeroBusqueda << "\ten la lista";
			break;

		case 6:
			break;

		default:
			cout << "Opcion no encontrada";
		}

		cout << "\n\n---------------------------------------------------------";
		cout << "\nDesea realizar otra operacion?\n[1] Si.\n[2] No.\n\n";
		cin >> OPT;
	} while (OPT != 2);
	return 0;
}