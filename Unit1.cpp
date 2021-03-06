//---------------------------------------------------------------------------
#pragma hdrstop

#include <vcl.h>
#include <fstream.h>
#include <jpeg.hpp>
#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"

#include "NeuroWeb.h"
#include "Dictionary.h"
#include "Teacher.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;


//---------------------------------------------------------------------------
Neuroweb *Web;
Dictionary* dictionary;
bool isChanged = false;


__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}

//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender){
Web = new Neuroweb(Image2);
dictionary = new Dictionary();
Image1->Picture->Bitmap->Width = Image1->Width;
Image1->Picture->Bitmap->Height = Image1->Height;
Image2->Picture->Bitmap->Width = Image2->Width;
Image2->Picture->Bitmap->Height = Image2->Height;
Form1->Memo1->Text = "";
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
        if(OpenPictureDialog1->Execute()){
       Graphics::TBitmap *Bitmap = new Graphics::TBitmap();
       if((AnsiLowerCase(ExtractFileExt(OpenPictureDialog1->FileName)) == ".jpg" || AnsiLowerCase(ExtractFileExt(OpenPictureDialog1->FileName)) == ".jpeg")){
                TJPEGImage *image = new TJPEGImage();
                image->LoadFromFile(OpenPictureDialog1->FileName);
                Bitmap->Assign(image);
                delete image;

        }
        else{
                ShowMessage("?????????????? ?????? .jpg");
                return;
         }

                for(int x = 0; x < Bitmap->Width; x++)
                for(int y = 0; y < Bitmap->Height; y++){
                if(Bitmap->Canvas->Pixels[x][y] > 14500000) Bitmap->Canvas->Pixels[x][y] = 16777215;
                else Bitmap->Canvas->Pixels[x][y] = 0;
                }

                int gx = -100, gy = -100, gxb = -100, gyb = -100;
                bool flag = true;

                for(int x = 0; x < Bitmap->Width && flag; x++)
                for(int y = 0; y < Bitmap->Height && flag; y++)
                if(Bitmap->Canvas->Pixels[x][y] < 14500000){
                        flag = false;
                        gx = x;
                }
                flag = true;
                for(int y = 0; y < Bitmap->Height && flag; y++)
                for(int x = 0; x < Bitmap->Width && flag; x++)
                if(Bitmap->Canvas->Pixels[x][y] < 14500000){
                        flag = false;
                        gy = y;
                }
                flag = true;
                if(Bitmap->Canvas->Pixels[Bitmap->Width - 1][Bitmap->Height - 1] > 14500000){
                for(int x = Bitmap->Width -1; x > -1 && flag; x--)
                for(int y = Bitmap->Height -1; y > -1 && flag; y--)
                if(Bitmap->Canvas->Pixels[x][y] < 14500000){
                        flag = false;
                        gxb = x;
                        }
                flag = true;
                for(int y = Bitmap->Height -1; y > -1 && flag; y--)
                for(int x = Bitmap->Width -1; x > -1  && flag; x--)
                if(Bitmap->Canvas->Pixels[x][y] < 14500000){
                        flag = false;
                        gyb = y;
                        }
                } else {
                        gxb = Bitmap->Width;
                        gyb = Bitmap->Height;
                }

        SetStretchBltMode(Image1->Canvas->Handle, HALFTONE);
        StretchBlt(Image1->Canvas->Handle, 0, 0, Image1->Width, Image1->Height, Bitmap->Canvas->Handle, gx, gy, gxb - gx, gyb - gy, SRCCOPY);
        }
        Image1->Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
        int x = 0, y = 0, sumSize = 0, Lcounter = 0, x1 = 0, x2 = -1, y1 = Image1->Height;
        AnsiString res = "", toRet = "";
        bool isBlack = false;
        do{
        while(!isBlack){
                for(int y = 0; y < Image1->Height -1; y++)
                        if(Image1->Picture->Bitmap->Canvas->Pixels[x][y] != 16777215){
                                isBlack = true;
                                break;
                        }                                                                 //725 288
                if(!isBlack) x++;
        }
        x1 = x;
        if(x1 < x2){
                x1 = x2;
                isBlack = false;
        }
        else
        while(isBlack){                               
                isBlack = false;
                for(int y = 0; y < Image1->Height -1; y++)
                        if(Image1->Picture->Bitmap->Canvas->Pixels[x1][y] != 16777215 && x1 < Image1->Width){
                                isBlack = true;
                                break;
                        }
                if(isBlack) x1++;
        }
        x2 = x1;
        while(!isBlack){
                for(int y = 0; y < Image1->Height -1; y++)
                        if(Image1->Picture->Bitmap->Canvas->Pixels[x2][y] != 16777215 || x2 > Image1->Width){
                                isBlack = true;
                                break;
                        }                                                                 //725 288
                if(!isBlack) x2++;
        }
        int x3 = x2;
        while(isBlack){
                isBlack = false;
                for(int y = 0; y < Image1->Height -1; y++)
                        if(Image1->Picture->Bitmap->Canvas->Pixels[x2][y] != 16777215 && x2 < Image1->Width){
                                isBlack = true;
                                break;
                        }
                if(isBlack) x2++;
        }
        if(Lcounter && ((sumSize / (Lcounter))) > ((x1 - x) * 1.5) && !((sumSize / Lcounter) < (x3 - x1) * 1.2))
        x1 = x2;
        sumSize += (x1 - x);
        ++Lcounter;
        y = 0;
        while(!isBlack){
                for(int _x = x; _x < x1; _x++)
                        if(Image1->Picture->Bitmap->Canvas->Pixels[_x][y] != 16777215){
                                isBlack = true;
                                break;
                        }
                if(!isBlack) y++;
        }
        y1 = Image1->Height -1;
        while(isBlack){
                for(int _x = x; _x < x1; _x++)
                        if(Image1->Picture->Bitmap->Canvas->Pixels[_x][y1] != 16777215){
                                isBlack = false;
                                break;
                        }
                if(isBlack) y1--;
        }
        SetStretchBltMode(Image2->Canvas->Handle, HALFTONE);
        StretchBlt(Image2->Canvas->Handle, 0, 0, Image2->Width, Image2->Height, Image1->Canvas->Handle, x, y, x1 - x, y1 - y, SRCCOPY);
        Image2->Repaint();
        res += Web->Prove() + '\n';
        Application->ProcessMessages();
        x = x1 + 1;
        if(Lcounter && ((sumSize / (Lcounter))) < (x3 - x1) * 1.2){
                toRet += AnsiString(dictionary->Compare(res.c_str())) + " ";
                res = "";
                x = x3;
                x1 = x2;
        }
        }while(x1 < Image1->Width);
        toRet += dictionary->Compare(res.c_str());
        ShowMessage(toRet);
}//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
        isChanged = true;
        Teacher* teacher = new Teacher(Web, Image2, Memo1);
        teacher->Teach(StrToInt(Edit2->Text));
        delete teacher;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Edit2MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        Edit2->SelectAll();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
        Form3->Show();
}

void AddNew(){
        if(Form3->LabeledEdit1->Text == ""){
        ShowMessage("?????????? ???????");
        return;
        }
        isChanged = true;
        Web->Add(Form3->LabeledEdit1->Text, StrToInt(Form3->LabeledEdit2->Text), StrToInt(Form3->LabeledEdit3->Text));
        Form3->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
        if(isChanged) Web->SaveToMemoryDir();
        delete dictionary;
        delete Web;
}
//---------------------------------------------------------------------------

