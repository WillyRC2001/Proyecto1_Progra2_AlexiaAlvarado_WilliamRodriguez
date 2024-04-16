#include "Utiles_Clases.h"
#include "Lista_Generica.h"
#include "Nodo_Generico.h"
#include "Producto_Clases.h"

int main() {
	Fecha* fech1 = new Fecha(1, 1, 1);
	Fecha* fech2 = new Fecha(2, 2, 2);
	Categoria* categ1 = new Categoria(1);
	Producto* c1 = new Embutido("111", "comercial", "desc", 10, "Embutido", 1, 2, fech1,fech2, true,20,"nom_animal","part_animal","marca");
	cout << c1->toString() << endl;
	Lista<Producto>* lista = new Lista<Producto>();
	lista->agregarFinal(c1);
	lista->eliminar(c1);
	cout << "Funciona!!" << endl;
    
	system("pause");
	return 0;
}