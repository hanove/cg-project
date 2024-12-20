//---------------------------------------------------------------------------

#ifndef uPrincipalH
#define uPrincipalH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TImage *Image1;
	TLabel *lbVp;
	TLabel *lbMundo;
	TButton *btIniciaPol;
	TListBox *lbPoligonos;
	TListBox *lbPontos;
	TLabel *Label1;
	TLabel *Label2;
	TRadioGroup *rgTipoReta;
	TEdit *edXmin;
	TEdit *edYmin;
	TEdit *edXmax;
	TEdit *edYmax;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TButton *Button1;
	TButton *btMoveUp;
	TButton *btMoveLeft;
	TButton *btMoveRight;
	TButton *btMoveDown;
	TButton *btZoomIn;
	TButton *btZoomOut;
	TEdit *edNewX;
	TEdit *edNewY;
	TButton *btBolinha;
	TEdit *edRaio;
	TButton *btTranslada;
	TButton *btEscalona;
	TButton *btRotaciona;
	TButton *btReleteX;
	TButton *btRefleteY;
	TButton *btRotacionaHomo;
	void __fastcall Image1MouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall btIniciaPolClick(TObject *Sender);
	void __fastcall lbPoligonosClick(TObject *Sender);
	void __fastcall lbPontosClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall btMoveUpClick(TObject *Sender);
	void __fastcall btMoveRightClick(TObject *Sender);
	void __fastcall btMoveDownClick(TObject *Sender);
	void __fastcall btMoveLeftClick(TObject *Sender);
	void __fastcall btZoomInClick(TObject *Sender);
	void __fastcall btZoomOutClick(TObject *Sender);
	void __fastcall btBolinhaClick(TObject *Sender);
	void __fastcall btTransladaClick(TObject *Sender);
	void __fastcall btEscalonaClick(TObject *Sender);
	void __fastcall btRotacionaClick(TObject *Sender);
	void __fastcall btReleteXClick(TObject *Sender);
	void __fastcall btRefleteYClick(TObject *Sender);
	void __fastcall btRotacionaHomoClick(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
	double xVp2W(int x, Janela vp, Janela mundo);
	double yVp2W(int y, Janela vp, Janela mundo);
    void atualizaMundo();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
