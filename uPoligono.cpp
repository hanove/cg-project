//---------------------------------------------------------------------------

#pragma hdrstop

#include "uPoligono.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

#define SIGN(x) ((x) < 0 ? (-1) : (1))
#define ABS(x) ((x) < 0 ? (-x) : (x))
#define FLOOR(x) ((x) < 0 ? ((x) - (int)(x) != 0 ? ((int) (x) - 1) : ((int) (x))) : (int) (x))

Poligono::Poligono(){
	tipo = 'N';
}

void Poligono::desenha(TCanvas* canvas, Janela vp, Janela mundo, int tipoReta){
	if(tipo == 'B' && centro && raio){
	   rendFazBolinha(*centro, *raio, canvas, vp, mundo);
	}else{
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
				dda(pt1, pt2, canvas, vp, mundo);
			}
			}else{
				//BRESENHAM()
				for(int i = 0; i < pontos.size()-1; i++){
					Ponto pt1, pt2;
					pt1 = pontos[i];
					pt2 = pontos[i+1];
					bresenham(pt1, pt2, canvas, vp, mundo);
				}

			}
		}
	}
}

void Poligono::dda(Ponto pt1, Ponto pt2, TCanvas* canvas, Janela vp, Janela mundo){
	int length = 0;
	int p1x, p1y, p2x, p2y;
	p1x = pt1.xW2Vp(vp, mundo);
	p1y = pt1.yW2Vp(vp, mundo);
	p2x = pt2.xW2Vp(vp, mundo);
	p2y = pt2.yW2Vp(vp, mundo);

	if(ABS((p2x-p1x)) >= ABS((p2y-p1y))){
		length = ABS((p2x-p1x));
	}else{
		length = ABS((p2y-p1y));
	}

	double dx = (float) (p2x-p1x) / (float) length;
	double dy = (float) (p2y-p1y) / (float) length;
	float x = p1x + 0.5 * SIGN(dx);
	float y = p1y + 0.5 * SIGN(dy);

	for(int i = 0; i < length; i++){
		canvas->Pixels[FLOOR(x)][FLOOR(y)] = clBlue;
		x += dx;
		y += dy;
	}

}

void Poligono::bresenham(Ponto pt1, Ponto pt2, TCanvas* canvas, Janela vp, Janela mundo){
	int p1x, p1y, p2x, p2y;
	p1x = pt1.xW2Vp(vp, mundo);
	p1y = pt1.yW2Vp(vp, mundo);
	p2x = pt2.xW2Vp(vp, mundo);
	p2y = pt2.yW2Vp(vp, mundo);

	double dx = ABS((p2x - p1x));
	double dy = ABS((p2y - p1y));
	int signalx = SIGN((p2x - p1x));
	int signaly = SIGN((p2y - p1y));
	double x = p1x;
	double y = p1y;

	if(signalx < 0){
		x -= 1;
	}
	if(signaly < 0){
		y -= 1;
	}
	bool interchange = false;
	if(dy > dx){
		double tmp = dx;
		dx = dy;
		dy = tmp;
		interchange = true;
	}
	double erro = 2 * dy - dx;
	for (int i=0; i < dx; i++) {
		canvas->Pixels[x][y] = clGreen;
		while(erro >= 0){
			if(interchange){
				x = x + signalx;
			}else{
				y = y + signaly;
			}
			erro = erro - 2 * dx;
		}
		if(interchange){
			y = y + signaly;
		}else{
			x = x + signalx;
		}
		erro = erro + 2 * dy;
	}

}

void Poligono::rendFazBolinha(Ponto pc, int raio, TCanvas* canvas, Janela vp, Janela mundo){
//	int x = 0;
//	int y = raio;
//	int p = 1 - raio;
//
//	// Desenhar os pontos iniciais da circunferência
//	rendDesenhaPontosSimetricos(pc, x, y, canvas, vp, mundo);
//
//	while (x < y) {
//		if (p < 0) {
//			x++;
//			p += 2 * x + 1;
//		} else {
//			x++;
//			y--;
//			p += 2 * (x - y) + 1;
//		}
//		rendDesenhaPontosSimetricos(pc, x, y, canvas, vp, mundo);
//	}

	for(int i=0; i < pontos.size(); i++){
		canvas->Pixels[pontos[i].x][pontos[i].y] = clRed;
	}
}

void Poligono::rendDesenhaPontosSimetricos(Ponto pc, int x, int y, TCanvas* canvas, Janela vp, Janela mundo){
	Ponto pcVp;
	pcVp.x = pc.xW2Vp(vp, mundo);
	pcVp.y = pc.yW2Vp(vp, mundo);

	// Instanciação direta de objetos Ponto
	Ponto p1(pcVp.x + x, pcVp.y + y);
	Ponto p2(pcVp.x - x, pcVp.y + y);
	Ponto p3(pcVp.x + x, pcVp.y - y);
	Ponto p4(pcVp.x - x, pcVp.y - y);
	Ponto p5(pcVp.x + y, pcVp.y + x);
	Ponto p6(pcVp.x - y, pcVp.y + x);
	Ponto p7(pcVp.x + y, pcVp.y - x);
	Ponto p8(pcVp.x - y, pcVp.y - x);

	// Desenhando os pontos no canvas
	canvas->Pixels[p1.x][p1.y] = clRed;
	canvas->Pixels[p2.x][p2.y] = clRed;
	canvas->Pixels[p3.x][p3.y] = clRed;
	canvas->Pixels[p4.x][p4.y] = clRed;
	canvas->Pixels[p5.x][p5.y] = clRed;
	canvas->Pixels[p6.x][p6.y] = clRed;
	canvas->Pixels[p7.x][p7.y] = clRed;
	canvas->Pixels[p8.x][p8.y] = clRed;
}


void Poligono::fazBolinha(Ponto pc, int raio, TCanvas* canvas, Janela vp, Janela mundo){
	int x = 0;
	int y = raio;
	int p = 1 - raio;

	// Desenhar os pontos iniciais da circunferência
	desenhaPontosSimetricos(pc, x, y, canvas, vp, mundo);

	while (x < y) {
		if (p < 0) {
			x++;
			p += 2 * x + 1;
		} else {
			x++;
			y--;
			p += 2 * (x - y) + 1;
		}
		desenhaPontosSimetricos(pc, x, y, canvas, vp, mundo);
	}
}

void Poligono::desenhaPontosSimetricos(Ponto pc, int x, int y, TCanvas* canvas, Janela vp, Janela mundo){
	Ponto pcVp;
	pcVp.x = pc.xW2Vp(vp, mundo);
	pcVp.y = pc.yW2Vp(vp, mundo);

	// Instanciação direta de objetos Ponto
	Ponto p1(pcVp.x + x, pcVp.y + y);
	Ponto p2(pcVp.x - x, pcVp.y + y);
	Ponto p3(pcVp.x + x, pcVp.y - y);
	Ponto p4(pcVp.x - x, pcVp.y - y);
	Ponto p5(pcVp.x + y, pcVp.y + x);
	Ponto p6(pcVp.x - y, pcVp.y + x);
	Ponto p7(pcVp.x + y, pcVp.y - x);
	Ponto p8(pcVp.x - y, pcVp.y - x);

	// Desenhando os pontos no canvas
	canvas->Pixels[p1.x][p1.y] = clRed;
	canvas->Pixels[p2.x][p2.y] = clRed;
	canvas->Pixels[p3.x][p3.y] = clRed;
	canvas->Pixels[p4.x][p4.y] = clRed;
	canvas->Pixels[p5.x][p5.y] = clRed;
	canvas->Pixels[p6.x][p6.y] = clRed;
	canvas->Pixels[p7.x][p7.y] = clRed;
	canvas->Pixels[p8.x][p8.y] = clRed;

	pontos.push_back(p1);
	pontos.push_back(p2);
	pontos.push_back(p3);
	pontos.push_back(p4);
	pontos.push_back(p5);
	pontos.push_back(p6);
	pontos.push_back(p7);
	pontos.push_back(p8);
}

void Poligono::translada(double dx, double dy){
	for (int i = 0; i < pontos.size(); i++) {
		pontos[i].transladaPonto(dx, dy);
	}
}

void Poligono::escalona(double sx, double sy){
	for (int i = 0; i < pontos.size(); i++) {
        pontos[i].escalonaPonto(sx, sy);
	}
}

void Poligono::rotaciona(double theta){
	for (int i = 0; i < pontos.size(); i++) {
		pontos[i].rotacionaPonto(theta);
	}
}

int Poligono::xCentral(){
    float s;

	for(unsigned int i = 0; i < pontos.size(); i++){
		s = s + pontos[i].x;
	}
	s = s / pontos.size();
	return FLOOR(s);
}

int Poligono::yCentral(){
    float s;

	for(unsigned int i = 0; i < pontos.size(); i++){
		s = s + pontos[i].y;
	}
	s = s / pontos.size();
	return FLOOR(s);
}

void Poligono::rotacionaHomogenea(double theta, int xc ,int yc){
	float ang = theta * M_PI / 180;

	for(unsigned int i = 0; i < pontos.size(); i++){
		pontos[i].rotacaoHomogenea(ang, xc, yc);
	}
}

Ponto Poligono::pontoMedio(Ponto ponto, Ponto ponto1)
{
	Ponto ponto2;

	ponto2.x = (ponto.x + ponto1.x) / 2;
	ponto2.y = (ponto.y + ponto1.y) / 2;
	return ponto2;
}

void Poligono::casteljau(int dist)
{
	Ponto ponto2 = pontos[1];
	Ponto ponto3 = pontos[2];
	pontos.pop_back();
	pontos.pop_back();

	//calculo da  distancia
	//dAB = ? ( x2 – x1 ) ² + ( y2 – y1 ) ²
//	pow

	casteljauRec(pontos[0], ponto2, ponto3, dist);
}

void Poligono::casteljauRec(Ponto p1, Ponto p2, Ponto p3, int dist){
	if(distancia(p1, p3, dist) == 1){
		pontos.push_back(p3);
	}else{
		Ponto p4 = pontoMedio(p1, p2);
		Ponto p5 = pontoMedio(p2, p3);
		Ponto p6 = pontoMedio(p4, p5);
		casteljauRec(p1, p4, p6, dist);
		casteljauRec(p6, p5, p3, dist);
	}
}

int Poligono::distancia(Ponto p1, Ponto p2, int dist){
	double x, y;

	x = p2.x - p1.x;
	y = p2.y - p1.y;
	x = x * x;
	y = y * y;
	if(sqrt(x + y) <= 5){
		return 1;
	}else{
		return 0;
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

//ponto central
