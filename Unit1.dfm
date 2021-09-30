object Form1: TForm1
  Left = 305
  Top = 126
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'Neuroweb'
  ClientHeight = 746
  ClientWidth = 725
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 0
    Top = 41
    Width = 725
    Height = 288
  end
  object Image2: TImage
    Left = 0
    Top = 356
    Width = 393
    Height = 389
  end
  object Image3: TImage
    Left = 428
    Top = 396
    Width = 205
    Height = 181
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 725
    Height = 41
    Align = alTop
    TabOrder = 0
    object Button1: TButton
      Left = 4
      Top = 8
      Width = 75
      Height = 25
      Caption = #1047#1072#1075#1088#1091#1079#1080#1090#1100
      TabOrder = 0
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 124
      Top = 8
      Width = 75
      Height = 25
      Caption = #1054#1087#1088#1077#1076#1077#1083#1080#1090#1100
      TabOrder = 1
      OnClick = Button2Click
    end
    object Edit2: TEdit
      Left = 244
      Top = 8
      Width = 129
      Height = 21
      TabOrder = 2
      Text = #1050#1086#1083'-'#1074#1086' '#1094#1080#1082#1083#1086#1074' '#1086#1073#1091#1095#1077#1085#1080#1103
      OnMouseDown = Edit2MouseDown
    end
    object Button4: TButton
      Left = 380
      Top = 8
      Width = 75
      Height = 25
      Caption = #1059#1095#1080#1090#1100
      TabOrder = 3
      OnClick = Button4Click
    end
    object Button5: TButton
      Left = 664
      Top = 8
      Width = 57
      Height = 25
      Caption = #1044#1086#1073#1072#1074#1080#1090#1100
      TabOrder = 4
      OnClick = Button5Click
    end
  end
  object Panel2: TPanel
    Left = -4
    Top = 332
    Width = 725
    Height = 21
    Align = alCustom
    Caption = 
      #1054#1073#1088#1072#1073#1072#1090#1099#1074#1072#1077#1084#1099#1081' '#1089#1080#1084#1074#1086#1083':                                          ' +
      '                                          '#1054#1090#1095#1077#1090':                ' +
      '                                                                ' +
      '                  '
    TabOrder = 1
  end
  object Memo1: TMemo
    Left = 400
    Top = 360
    Width = 321
    Height = 385
    Lines.Strings = (
      'Memo1')
    TabOrder = 2
  end
  object OpenPictureDialog1: TOpenPictureDialog
    Left = 152
    Top = 64
  end
end
