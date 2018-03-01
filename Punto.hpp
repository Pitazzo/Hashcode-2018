class Punto{
	private:
		int x;
		int y;
	public:
		
		//Constructor por defecto
		Punto(int x, int y);
		
		int obtenerX();
		
		int obtenerY();
		
		int distancia(Punto destino);
		
};
