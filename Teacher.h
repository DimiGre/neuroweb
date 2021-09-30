#ifndef TEACHER_H
#define TEACHER_H

#include"Unit1.h"


struct Teacher
{
Teacher(Neuroweb*, TImage*, TMemo*);
~Teacher();
void Teach(int);

private:
TMemo* Log;
list<Perceptron*> *CurrWeb;
TImage* CurrImage;
void Punish(Perceptron*, AnsiString&);
};
Teacher::Teacher(Neuroweb* _CurrWeb, TImage* _CurrImage, TMemo* _Log){
        CurrWeb = _CurrWeb->Web;
        CurrImage = _CurrImage;
        Log = _Log;
}

Teacher::~Teacher(){
}

void Teacher::Teach(int _number){

list<Perceptron*>::iterator *biter = new list<Perceptron*>::iterator();

for(int count = 0; count < _number; count++){
        *biter = CurrWeb->begin();
        Perceptron *toIt = **biter;
        for(int i = 0; *biter != CurrWeb->end() && FileExists("pic/" + toIt->name + " " +IntToStr(i)+".jpg");){

                Graphics::TBitmap* Bitmap = new Graphics::TBitmap();
                TJPEGImage *image = new TJPEGImage();
                image->LoadFromFile(("pic/" + toIt->name + " " +IntToStr(i)+".jpg").c_str());
                Bitmap->Assign(image);
                delete image;
                SetStretchBltMode(CurrImage->Canvas->Handle, HALFTONE );
                StretchBlt(CurrImage->Canvas->Handle, 0, 0, CurrImage->Width, CurrImage->Height, Bitmap->Canvas->Handle, 0, 0, Bitmap->Width, Bitmap->Height, SRCCOPY);
                CurrImage->Repaint();
                Log->Lines->Add("pic/" + toIt->name + " " +IntToStr(i)+".jpg");

       list<Perceptron*>::iterator *iter = new list<Perceptron*>::iterator();
       for(*iter = CurrWeb->begin(); *iter!=CurrWeb->end(); ++(*iter)){
        Perceptron *toDo = **iter;
                        bool isit = toDo->Count();
                                if ((isit && toDo->name != toIt->name) ||
                                (!(isit) && toDo->name == toIt->name)){
                                        Log->Lines->Add("Провал " + String(toDo->name) + " на " + toIt->name + ". Попытка " + (count + 1));
                                        Application->ProcessMessages();
                                        Punish(toDo, toIt->name);
                                } else  Log->Lines->Add("Успех: " + String(toDo->name) + " на " + toIt->name + ". Попытка " + (count + 1));
                        }
                        delete iter;
                        delete Bitmap;
                        if(!FileExists("pic/" + toIt->name + " " +IntToStr(++i)+".jpg")){
                                i = 0;
                                (*biter)++;
                                toIt = **biter;
                        } else i++;
                }
        }
        Log->Lines->Add("Конец");
}

void Teacher::Punish(Perceptron* Learner, AnsiString &name){
        if(Learner->name == name){
                for(int i = 0; i < Learner->NOSL; i++)
                        if(Learner->Slvls[i]->Check()) Learner->weight[i]++;
                } else
                for(int i = 0; i < Learner->NOSL; i++)
                        if(Learner->Slvls[i]->Check()) Learner->weight[i]--;
                Log->Lines->Add("Научено");
}
#endif

