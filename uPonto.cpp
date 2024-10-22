//---------------------------------------------------------------------------

#pragma hdrstop

#include "uPonto.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Ponto::Ponto() {
	x = y = 0;
}

Ponto::Ponto(double nx, double ny) {
	x = nx;
    y = ny;
}

int Ponto::xW2Vp(Janela vp, Janela mundo){
	return ((x - mundo.xMin) / (mundo.xMax - mundo.xMin)) * (vp.xMax - vp.xMin);
}

int Ponto::yW2Vp(Janela vp, Janela mundo){
	return (1 - ((y - mundo.yMin) / (mundo.yMax - mundo.yMin))) * (vp.yMax - vp.yMin);
}

UnicodeString Ponto::toString(){
    return "( " + FloatToStr(x) + " ; " + FloatToStr(y) + " )";
}
