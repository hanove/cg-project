object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 518
  ClientWidth = 876
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Scaled = False
  TextHeight = 15
  object lbVp: TLabel
    Left = 528
    Top = 24
    Width = 24
    Height = 15
    Caption = 'lbVp'
  end
  object lbMundo: TLabel
    Left = 677
    Top = 24
    Width = 49
    Height = 15
    Caption = 'lbMundo'
  end
  object Label1: TLabel
    Left = 528
    Top = 99
    Width = 53
    Height = 15
    Caption = 'Poligonos'
  end
  object Label2: TLabel
    Left = 528
    Top = 169
    Width = 37
    Height = 15
    Caption = 'Pontos'
  end
  object Label3: TLabel
    Left = 697
    Top = 264
    Width = 28
    Height = 15
    Caption = 'Xmin'
  end
  object Label4: TLabel
    Left = 416
    Top = 272
    Width = 34
    Height = 15
    Caption = 'Label4'
  end
  object Label5: TLabel
    Left = 697
    Top = 314
    Width = 27
    Height = 15
    Caption = 'Ymin'
  end
  object Label6: TLabel
    Left = 697
    Top = 359
    Width = 30
    Height = 15
    Caption = 'Xmax'
  end
  object Label7: TLabel
    Left = 697
    Top = 404
    Width = 29
    Height = 15
    Caption = 'Ymax'
  end
  object Panel1: TPanel
    Left = 0
    Top = 8
    Width = 502
    Height = 502
    TabOrder = 0
    object Image1: TImage
      Left = 1
      Top = 1
      Width = 500
      Height = 500
      Align = alClient
      OnMouseDown = Image1MouseDown
      OnMouseMove = Image1MouseMove
      ExplicitLeft = -50
      ExplicitTop = -31
    end
  end
  object btIniciaPol: TButton
    Left = 528
    Top = 56
    Width = 89
    Height = 25
    Caption = 'Inicia Pol'#237'gono'
    TabOrder = 1
    OnClick = btIniciaPolClick
  end
  object lbPoligonos: TListBox
    Left = 528
    Top = 120
    Width = 121
    Height = 49
    ItemHeight = 15
    Items.Strings = (
      'dsdsds'
      'ds'
      'ds'
      ''
      'ds'
      'd')
    TabOrder = 2
    OnClick = lbPoligonosClick
  end
  object lbPontos: TListBox
    Left = 528
    Top = 190
    Width = 121
    Height = 40
    ItemHeight = 15
    Items.Strings = (
      'gggg')
    TabOrder = 3
    OnClick = lbPontosClick
  end
  object rgTipoReta: TRadioGroup
    Left = 655
    Top = 45
    Width = 185
    Height = 105
    Caption = 'Tipo de reta'
    ItemIndex = 0
    Items.Strings = (
      'LineTo'
      'DDA'
      'Bresenham')
    TabOrder = 4
  end
  object edXmin: TEdit
    Left = 697
    Top = 285
    Width = 121
    Height = 23
    TabOrder = 5
    Text = '-250'
  end
  object edYmin: TEdit
    Left = 697
    Top = 330
    Width = 121
    Height = 23
    TabOrder = 6
    Text = '-250'
  end
  object edXmax: TEdit
    Left = 697
    Top = 375
    Width = 121
    Height = 23
    TabOrder = 7
    Text = '250'
  end
  object edYmax: TEdit
    Left = 697
    Top = 425
    Width = 121
    Height = 23
    TabOrder = 8
    Text = '250'
  end
  object Button1: TButton
    Left = 729
    Top = 454
    Width = 89
    Height = 25
    Caption = 'Atualiza mundo'
    TabOrder = 9
    OnClick = Button1Click
  end
  object btMoveUp: TButton
    Left = 542
    Top = 236
    Width = 75
    Height = 25
    Caption = 'UP'
    TabOrder = 10
    OnClick = btMoveUpClick
  end
  object btMoveLeft: TButton
    Left = 508
    Top = 267
    Width = 75
    Height = 25
    Caption = 'LEFT'
    TabOrder = 11
    OnClick = btMoveLeftClick
  end
  object btMoveRight: TButton
    Left = 589
    Top = 267
    Width = 75
    Height = 25
    Caption = 'RIGHT'
    TabOrder = 12
    OnClick = btMoveRightClick
  end
  object btMoveDown: TButton
    Left = 542
    Top = 298
    Width = 75
    Height = 25
    Caption = 'DOWN'
    TabOrder = 13
    OnClick = btMoveDownClick
  end
  object btZoomIn: TButton
    Left = 508
    Top = 329
    Width = 75
    Height = 25
    Caption = 'Zoom in'
    TabOrder = 14
    OnClick = btZoomInClick
  end
  object btZoomOut: TButton
    Left = 589
    Top = 329
    Width = 75
    Height = 25
    Caption = 'Zoom out'
    TabOrder = 15
    OnClick = btZoomOutClick
  end
  object edNewX: TEdit
    Left = 655
    Top = 156
    Width = 121
    Height = 23
    TabOrder = 16
  end
  object edNewY: TEdit
    Left = 655
    Top = 185
    Width = 121
    Height = 23
    TabOrder = 17
  end
  object btBolinha: TButton
    Left = 655
    Top = 214
    Width = 75
    Height = 25
    Caption = 'C'#237'rculo'
    TabOrder = 18
    OnClick = btBolinhaClick
  end
  object edRaio: TEdit
    Left = 736
    Top = 214
    Width = 57
    Height = 23
    TabOrder = 19
  end
  object btTranslada: TButton
    Left = 782
    Top = 156
    Width = 65
    Height = 25
    Caption = 'Translada'
    TabOrder = 20
    OnClick = btTransladaClick
  end
  object btEscalona: TButton
    Left = 782
    Top = 187
    Width = 65
    Height = 25
    Caption = 'Escalona'
    TabOrder = 21
    OnClick = btEscalonaClick
  end
  object btRotaciona: TButton
    Left = 799
    Top = 218
    Width = 58
    Height = 25
    Caption = 'Rotaciona'
    TabOrder = 22
    OnClick = btRotacionaClick
  end
  object btReleteX: TButton
    Left = 508
    Top = 374
    Width = 75
    Height = 25
    Caption = 'Relete X'
    TabOrder = 23
    OnClick = btReleteXClick
  end
  object btRefleteY: TButton
    Left = 589
    Top = 374
    Width = 75
    Height = 25
    Caption = 'Reflete Y'
    TabOrder = 24
    OnClick = btRefleteYClick
  end
  object btRotacionaHomo: TButton
    Left = 508
    Top = 405
    Width = 101
    Height = 25
    Caption = 'Rotacao Homo'
    TabOrder = 25
    OnClick = btRotacionaHomoClick
  end
end
