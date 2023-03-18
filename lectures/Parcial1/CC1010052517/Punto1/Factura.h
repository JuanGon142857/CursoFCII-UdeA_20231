#include <string>

using namespace std;

class Factura{
	public:
		Factura();
		void set_code();
		void set_cant();
		void set_desc();
		void set_precio();
		string get_code();
		string get_desc();
		float get_precio();
		int get_cant();

		float obtenerMontoFactura();
		void print_articulo();

	private:
		string code;
		string desc;
		int cantidad;
		float precio;
		float total;
};
