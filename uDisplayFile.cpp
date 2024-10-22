//---------------------------------------------------------------------------

#pragma hdrstop

#include "uDisplayFile.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

void DisplayFile::desenha(TCanvas* canvas, Janela vp, Janela mundo, int tipoReta){
	canvas->Brush->Color = clSilver;
	canvas->FillRect(Rect(0, 0, 500, 500));

	canvas->Pen->Color = clBlack;
	canvas->Pen->Width = 1;

	for (int x = 0; x < poligonos.size(); x++) {
		poligonos[x].desenha(canvas, vp, mundo, tipoReta);
	}

}

void DisplayFile::mostra(TListBox* listBox){
	listBox->Items->Clear();
	for (int x = 0; x < poligonos.size(); x++) {
		listBox->Items->Add(poligonos[x].toString());
	}
}
