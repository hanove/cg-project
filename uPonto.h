//---------------------------------------------------------------------------

#ifndef uPontoH
#define uPontoH
#include "uJanela.h"
//---------------------------------------------------------------------------
class Ponto {
	public:
		double x;
		double y;

		Ponto();
		Ponto(double nx, double ny);
		int xW2Vp(Janela vp, Janela mundo);
		int yW2Vp(Janela vp, Janela mundo);
		UnicodeString toString();

		void transladaPonto(double dx, double dy);

		void escalonaPonto(double sx, double sy);

		void rotacionaPonto(double theta);

        void rotacaoHomogenea(double theta, int xc, int yc);
};

#endif
