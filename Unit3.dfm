object Form3: TForm3
  Left = 520
  Top = 128
  Width = 526
  Height = 88
  Caption = 'Add'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object LabeledEdit1: TLabeledEdit
    Left = 4
    Top = 20
    Width = 121
    Height = 21
    EditLabel.Width = 22
    EditLabel.Height = 13
    EditLabel.Caption = #1048#1084#1103
    LabelPosition = lpAbove
    LabelSpacing = 3
    TabOrder = 0
  end
  object LabeledEdit2: TLabeledEdit
    Left = 148
    Top = 20
    Width = 121
    Height = 21
    EditLabel.Width = 31
    EditLabel.Height = 13
    EditLabel.Caption = #1055#1086#1088#1086#1075
    LabelPosition = lpAbove
    LabelSpacing = 3
    TabOrder = 1
    Text = '9'
  end
  object LabeledEdit3: TLabeledEdit
    Left = 300
    Top = 20
    Width = 121
    Height = 21
    EditLabel.Width = 87
    EditLabel.Height = 13
    EditLabel.Caption = #1042#1077#1089' '#1087#1086' '#1091#1084#1086#1095#1072#1085#1080#1102
    LabelPosition = lpAbove
    LabelSpacing = 3
    TabOrder = 2
    Text = '1'
  end
  object Button1: TButton
    Left = 428
    Top = 20
    Width = 75
    Height = 25
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100
    TabOrder = 3
    OnClick = Button1Click
  end
end
