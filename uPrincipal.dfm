object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 518
  ClientWidth = 855
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
    Left = 681
    Top = 165
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
    Left = 681
    Top = 215
    Width = 27
    Height = 15
    Caption = 'Ymin'
  end
  object Label6: TLabel
    Left = 681
    Top = 260
    Width = 30
    Height = 15
    Caption = 'Xmax'
  end
  object Label7: TLabel
    Left = 681
    Top = 305
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
    Left = 681
    Top = 186
    Width = 121
    Height = 23
    TabOrder = 5
    Text = '-250'
  end
  object edYmin: TEdit
    Left = 681
    Top = 231
    Width = 121
    Height = 23
    TabOrder = 6
    Text = '-250'
  end
  object edXmax: TEdit
    Left = 681
    Top = 276
    Width = 121
    Height = 23
    TabOrder = 7
    Text = '250'
  end
  object edYmax: TEdit
    Left = 681
    Top = 326
    Width = 121
    Height = 23
    TabOrder = 8
    Text = '250'
  end
  object Button1: TButton
    Left = 713
    Top = 355
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
  end
  object btMoveRight: TButton
    Left = 589
    Top = 267
    Width = 75
    Height = 25
    Caption = 'RIGHT'
    TabOrder = 12
  end
  object btMoveDown: TButton
    Left = 542
    Top = 298
    Width = 75
    Height = 25
    Caption = 'DOWN'
    TabOrder = 13
  end
  object btZoomIn: TButton
    Left = 508
    Top = 329
    Width = 75
    Height = 25
    Caption = 'Zoom in'
    TabOrder = 14
  end
  object btZoomOut: TButton
    Left = 589
    Top = 329
    Width = 75
    Height = 25
    Caption = 'Zoom out'
    TabOrder = 15
  end
end
