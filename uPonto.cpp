//---------------------------------------------------------------------------

#pragma hdrstop

#include "uPonto.h"
#include <cmath>
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

void Ponto::transladaPonto(double dx, double dy){
	x = x + dx;
	y = y + dy;
}

void Ponto::escalonaPonto(double sx, double sy){
	x = x * sx;
	y = y * sy;
}

void Ponto::rotacionaPonto(double theta){
	double thetaRad = theta * (double)M_PI/180;
	double auxX = x;
	double auxY = y;

	x = auxX * cos(thetaRad) - y * sin(thetaRad);
    y = auxX * sin(thetaRad) + y * cos(thetaRad);
}

void Ponto::rotacaoHomogenea(double theta, int xc, int yc){
    double x1 = this->x;
	double y1 = this->y;
	this->x = ((x1 - xc) * cos(theta)) - ((y1 - yc) * sin(theta)) + xc;
	this->y = ((x1 - xc) * sin(theta)) + ((y1 - yc) * cos(theta)) + yc;
}

//rotação usuário passa o angulo em graus e deve converter para radianos antes de realizar as manipulações

UnicodeString Ponto::toString(){
    return "( " + FloatToStr(x) + " ; " + FloatToStr(y) + " )";
}

//cohen (clipping)
