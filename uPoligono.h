//---------------------------------------------------------------------------

#ifndef uPoligonoH
#define uPoligonoH

#include <vector>
#include "uPonto.h"
#include "uJanela.h"
#include <Vcl.StdCtrls.hpp>
//---------------------------------------------------------------------------
class Poligono {
	public:
		std::vector <Ponto> pontos;
		int id;
		char tipo;

		Poligono();

		void desenha(TCanvas* canvas, Janela vp, Janela mundo, int tipoReta);

		UnicodeString toString();

		void mostra(TListBox *listBox);
};

#endif
