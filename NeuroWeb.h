#ifndef NEUROWEB_H
#define NEUROWEB_H

struct Teacher;

#include "PerceptronSlvl.h"
#include "Perceptron.h"
#include <list>

class Neuroweb{
        friend Teacher;
        list<Perceptron*> *Web;
        PerceptronSlvl **Slvls;
        int n;

        public:
        Neuroweb(TImage*);
        AnsiString Prove();
        void SaveToMemoryDir();
        void Add(AnsiString, int, int);
};

Neuroweb::Neuroweb(TImage* _CurrImage){
int xn = 3, yn = 3;
n = xn * yn;
Web = new list<Perceptron*>;
Slvls = new PerceptronSlvl*[n];
int sx = n, sy = n;
int x = 50, y = 50;

int i = 0;
for(int x = 50, stepx = (_CurrImage->Width - 50) / 2; x < _CurrImage->Width; x += stepx)
for(int y = 50, stepy = (_CurrImage->Height - 50) / 2; y < _CurrImage->Height; y += stepy){
Slvls[i] = new PerceptronSlvl(x - 50, y - 50, x, y, _CurrImage);
i++;
}


/*Slvls[0] = new PerceptronSlvl(0, 0, 50, 50, _CurrImage);
Slvls[1] = new PerceptronSlvl((_CurrImage->Width / 2) - 25, 0, (_CurrImage->Width / 2) + 25, 50, _CurrImage);
Slvls[2] = new PerceptronSlvl(_CurrImage->Width - 51, 0, _CurrImage->Width - 1, 50, _CurrImage);

Slvls[3] = new PerceptronSlvl(0, _CurrImage->Height / 2 - 25, 50, _CurrImage->Height / 2 + 25, _CurrImage);
Slvls[4] = new PerceptronSlvl((_CurrImage->Width / 2) - 25, _CurrImage->Height / 2 - 25, (_CurrImage->Width / 2) + 25, _CurrImage->Height / 2 + 25, _CurrImage);
Slvls[5] = new PerceptronSlvl(_CurrImage->Width - 51, _CurrImage->Height / 2 - 25, _CurrImage->Width - 1, _CurrImage->Height / 2 + 25, _CurrImage);

Slvls[6] = new PerceptronSlvl(1, _CurrImage->Height - 51, 51, _CurrImage->Height - 1, _CurrImage);
Slvls[7] = new PerceptronSlvl((_CurrImage->Width / 2) - 25, _CurrImage->Height - 51, (_CurrImage->Width / 2) + 25, _CurrImage->Height - 1, _CurrImage);
Slvls[8] = new PerceptronSlvl(_CurrImage->Width - 51, _CurrImage->Height - 51, _CurrImage->Width - 1, _CurrImage->Height - 1, _CurrImage);
*/
if(DirectoryExists("memory")){

        for(int i = 0; FileExists("memory/"+IntToStr(i)+".txt"); i++){

        ifstream *fin = new ifstream(("memory/"+IntToStr(i)+".txt").c_str());

        if(fin->is_open()){
                int value;
                int *weight = new int[n];
                std::string name;
                *fin >> name;
                *fin >> value;
                for(int i = 0; i < n; i++) *fin >> weight[i];
                Perceptron *toAdd = new Perceptron(n ,value, name.c_str(), weight , Slvls);
                Web->push_back(toAdd);
        }
        fin->close();
        delete fin;
        }
    }
    else  CreateDir("memory");
}

AnsiString Neuroweb::Prove(){
AnsiString res = "";
list<Perceptron*>::iterator *iter = new list<Perceptron*>::iterator();
for(*iter = Web->begin(); *iter!=Web->end(); ++(*iter)){
        Perceptron* toCount = **iter;
                if(toCount->Count()) res += toCount->GetName() + ' ';
        }
        delete iter;
return res;
}

void Neuroweb::Add(AnsiString _name, int _minsum, int _weight){
        int *aw = new int[n];
        for(int i = 0; i < n; i++) aw[i] = _weight;
        Perceptron *toAdd = new Perceptron(n, _minsum, _name, aw, Slvls);
        Web->push_back(toAdd);
}

void Neuroweb::SaveToMemoryDir(){
        list<Perceptron*>::iterator *iter = new list<Perceptron*>::iterator();
        *iter = Web->begin();
        for(int i = 0; *iter!=Web->end(); i++)
        {
                (**iter)->SaveToFile(i);
                ++(*iter);
        }
        delete iter;
}

#endif