//---------------------------------------------------------------------------

#ifndef uDisplayFileH
#define uDisplayFileH

#include <vector>
#include "uPoligono.h"
#include "uJanela.h"
#include <Vcl.StdCtrls.hpp>
//---------------------------------------------------------------------------
class DisplayFile{
	public:
		std::vector <Poligono> poligonos;

		void desenha(TCanvas* canvas, Janela vp, Janela mundo, int tipoReta);

		void mostra(TListBox *listBox);
};


#endif
