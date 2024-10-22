//---------------------------------------------------------------------------

#pragma hdrstop

#include "uPoligono.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Poligono::Poligono(){
	id = 99;
	tipo = 'N';
}

void Poligono::desenha(TCanvas* canvas, Janela vp, Janela mundo, int tipoReta){
	if(tipo == 'E'){
		canvas->Pen->Color = clBlack;
	}else{
		canvas->Pen->Color = clRed;
	}
	if(tipoReta == 0){

		for(int i = 0; i < pontos.size(); i++){
			if(i == 0){
				canvas->MoveTo(pontos[i].xW2Vp(vp, mundo), pontos[i].yW2Vp(vp, mundo));
			} else{
				canvas->LineTo(pontos[i].xW2Vp(vp, mundo), pontos[i].yW2Vp(vp, mundo));
			}
		}
	}else{
		if(tipoReta == 1){
			//DDA(pt1, pt2, canvas, vp, mundo)
		for(int i = 0; i < pontos.size()-1; i++){
			Ponto pt1, pt2;
			pt1 = pontos[i];
            pt2 = pontos[i+1];
		}
		}else{
			//BRESENHAM()
        }
	}
}

UnicodeString Poligono::toString(){
	return IntToStr(id) + " - "  + tipo + " - " + IntToStr((int)pontos.size()) + " ptos";
}

void Poligono::mostra(TListBox *listBox){
	listBox->Items->Clear();
	for(int i = 0; i < pontos.size(); i++){
		listBox->Items->Add(pontos[i].toString());
	}

}
