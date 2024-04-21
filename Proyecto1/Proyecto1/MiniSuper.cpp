//#include "MiniSuper.h"
//
//MiniSuper::MiniSuper() {
//	Cont_Prod = new ContenedorLProducto();
//}
//MiniSuper::~MiniSuper() {
//	if (Cont_Prod != nullptr) {
//		delete Cont_Prod;
//		Cont_Prod = nullptr;
//	}
//}
//
//void MiniSuper::IngresarElProducto(string codigo, Producto* nuevo)
//{
//	Cont_Prod->IngresarProducto(codigo, nuevo);
//}
//
//void MiniSuper::EliminaProducto(string codigo)
//{
//	Cont_Prod->eliminarProducto(codigo);
//}
//
//void MiniSuper::ModificarProducto(string codigo, Producto* nuevo)
//{
//	Cont_Prod->cambiarProducto(codigo, nuevo);
//}
//
//string MiniSuper::TodosLosProductos()
//{
//	return Cont_Prod->TodosLosProductos();
//}
//
//string MiniSuper::ProductoDeUnaCategoria(string categoria)
//{
//	return Cont_Prod->ProductoDeUnaCategoria(categoria);
//}
//
//string MiniSuper::ProductosConMinExistencia()
//{
//	return Cont_Prod->ProductosConMinExistencia();
//}
