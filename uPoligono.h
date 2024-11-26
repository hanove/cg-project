//---------------------------------------------------------------------------

#ifndef uPoligonoH
#define uPoligonoH

#include <vector>
#include "uPonto.h"
#include "uJanela.h"
#include <Vcl.StdCtrls.hpp>
#include <optional>
//---------------------------------------------------------------------------
class Poligono {
	public:
		std::vector <Ponto> pontos;
		int id;
		char tipo;
		std::optional<Ponto> centro;
		std::optional<int> raio;

		Poligono();


		void desenha(TCanvas* canvas, Janela vp, Janela mundo, int tipoReta);

		UnicodeString toString();

		void mostra(TListBox *listBox);

		//DDA(pt1, pt2, canvas, vp, mundo)
		void dda(Ponto pt1, Ponto pt2, TCanvas* canvas, Janela vp, Janela mundo);

		void bresenham(Ponto pt1, Ponto pt2, TCanvas* canvas, Janela vp, Janela mundo);

		void fazBolinha(Ponto pc, int raio, TCanvas* canvas, Janela vp, Janela mundo);

		void desenhaPontosSimetricos(Ponto pc, int x, int y, TCanvas* canvas, Janela vp, Janela mundo);

		void rendFazBolinha(Ponto pc, int raio, TCanvas* canvas, Janela vp, Janela mundo);

		void rendDesenhaPontosSimetricos(Ponto pc, int x, int y, TCanvas* canvas, Janela vp, Janela mundo);

		void translada(double dx, double dy);

		void escalona(double sx, double sy);

		void rotaciona(double theta);

		int xCentral();

		int yCentral();

		void rotacionaHomogenea(double theta, int xc, int yc);

		Ponto pontoMedio(Ponto ponto, Ponto ponto1);

		void casteljau(int dist);

		void casteljauRec(Ponto p1, Ponto p2, Ponto p3, int dist);

		int distancia(Ponto p1, Ponto p2, int dist);
};

#endif
