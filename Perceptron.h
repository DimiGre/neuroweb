#ifndef PERCEPTRON_H
#define PERCEPTRON_H

class Perceptron{
friend Teacher;
int NOSL;   //Number Of S Levels
int minsum;
PerceptronSlvl** Slvls;
AnsiString name;
int *weight;
public:
Perceptron(int, int, AnsiString, int*, PerceptronSlvl**);
~Perceptron();
bool Count();
void SaveToFile(int);
AnsiString GetName(){return name;}
};


Perceptron::Perceptron(int _NOSL, int _minsum, AnsiString _name, int* _weight, PerceptronSlvl** _Slvls){
        NOSL = _NOSL;
        name = _name;
        minsum = _minsum;
        weight = _weight;
        Slvls = _Slvls;
}

Perceptron::~Perceptron(){
delete[] weight;
delete[] Slvls;
}

bool Perceptron::Count(){
        int sum = 0;
        for(int i = 0; i < NOSL; i++)
        if(Slvls[i]->Check()) sum += weight[i];
        return sum > minsum;
}

void Perceptron::SaveToFile(int i){
        ofstream *fout = new ofstream(("memory/"+IntToStr(i)+".txt").c_str());
        *fout << name.c_str() << " " << minsum;
        for(int i = 0; i < NOSL; i++) *fout <<  ' ' << weight[i];
        fout->close();
        delete fout;
}

#endif
 