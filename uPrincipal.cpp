//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uJanela.h"
#include "uPoligono.h"
#include "uPrincipal.h"
#include "uPonto.h"
#include "uDisplayFile.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Ponto aux;
Poligono pol;
DisplayFile display;
Janela mundo(-250, -250, 250, 250);
Janela vp(0, 0, 500, 500);

bool inicia = false;
int countId = 0;
//---------------------------------------------------------------------------
double TForm1::xVp2W(int x, Janela vp, Janela mundo) {
	return ((x - vp.xMin) / (vp.xMax - vp.xMin)) * (mundo.xMax - mundo.xMin) + mundo.xMin;
}

double TForm1::yVp2W(int y, Janela vp, Janela mundo) {
	return (1 - ((y - vp.yMin) / (vp.yMax - vp.yMin))) * (mundo.yMax - mundo.yMin) + mundo.yMin;
}

void TForm1::atualizaMundo(){
    mundo.xMin = StrToFloat(edXmin->Text);
	mundo.yMin = StrToFloat(edYmin->Text);
	mundo.xMax = StrToFloat(edXmax->Text);
	mundo.yMax = StrToFloat(edYmax->Text);

	//atualiza eixo vertical
	display.poligonos[0].pontos[0].y = mundo.yMax;
	display.poligonos[0].pontos[1].y = mundo.yMin;

	//atualiza eixo horizontal
	display.poligonos[1].pontos[0].x = mundo.xMin;
	display.poligonos[1].pontos[1].x = mundo.xMax;

	display.desenha(Image1->Canvas, vp, mundo, rgTipoReta->ItemIndex);
}


__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{

	//linha vertical
//	Image1->Canvas->MoveTo(250, 0);
//	Image1->Canvas->LineTo(250, 500);
	pol.id = countId++;
	pol.tipo = 'E';
	pol.pontos.push_back(Ponto(0, mundo.yMax));
	pol.pontos.push_back(Ponto(0, mundo.yMin));
	display.poligonos.push_back(pol);
	pol.pontos.clear();

	//linha horizontal
//	Image1->Canvas->MoveTo(0, 250);
//	Image1->Canvas->LineTo(500, 250);
	pol.id = countId++;
	pol.tipo = 'E';
	pol.pontos.push_back(Ponto(mundo.xMin, 0));
	pol.pontos.push_back(Ponto(mundo.xMax, 0));
	display.poligonos.push_back(pol);
	pol.pontos.clear();

	pol.tipo = 'N';

	display.desenha(Image1->Canvas, vp, mundo, rgTipoReta->ItemIndex);
	display.mostra(lbPoligonos);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image1MouseMove(TObject *Sender, TShiftState Shift, int X,
		  int Y)
{
	double xMundo, yMundo;
	xMundo = xVp2W(X, vp, mundo);
	yMundo = yVp2W(Y, vp, mundo);

	lbVp->Caption = "( " + IntToStr(X) + ", " + IntToStr(Y) + " )";
	lbMundo->Caption = "( " + FloatToStr(xMundo) + ", " + FloatToStr(yMundo) + " )";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
	double xMundo, yMundo;

	if(inicia){
		if(Button == mbLeft){
			xMundo = xVp2W(X, vp, mundo);
			yMundo = yVp2W(Y, vp, mundo);

			aux.x = xMundo;
			aux.y = yMundo;

			pol.pontos.push_back(aux);
			pol.desenha(Image1->Canvas, vp, mundo, rgTipoReta->ItemIndex);
		}else{
			pol.id = countId++;
			pol.tipo = 'N';
			display.poligonos.push_back(pol);

			pol.pontos.clear();
			inicia = false;
			display.desenha(Image1->Canvas, vp, mundo, rgTipoReta->ItemIndex);
			display.mostra(lbPoligonos);
		}

	}else{
		ShowMessage("Clique no botão iniciar");
	}

//	ShowMessage("(" + FloatToStr(aux.x) + ", " + FloatToStr(aux.y) + ")");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btIniciaPolClick(TObject *Sender)
{
	inicia = true;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::lbPoligonosClick(TObject *Sender)
{
  if(lbPoligonos->ItemIndex != -1){
	display.poligonos[lbPoligonos->ItemIndex].mostra(lbPontos);
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::lbPontosClick(TObject *Sender)
{
ShowMessage("oi");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
  atualizaMundo();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btMoveUpClick(TObject *Sender)
{
	mundo.yMax += 50;
	mundo.yMin += 50;

	//ShowMessage(FloatToStr(mundo.yMax));
    display.desenha(Image1->Canvas, vp, mundo, rgTipoReta->ItemIndex);
	display.mostra(lbPoligonos);
}
//---------------------------------------------------------------------------

