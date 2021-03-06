#ifndef PERCEPTRONSLVL_H
#define PERCEPTRONSLVL_H

class PerceptronSlvl{
TImage* CurrImage;
int x, y, x1, y1, minsum;
public:
PerceptronSlvl(int _x, int _y, int _x1, int _y1, TImage* _CurrImage){
        x = _x;
        y = _y;
        x1 = _x1;
        y1 = _y1;
        minsum = ((x - x1) * (y - y1)) * 0.80;
        CurrImage = _CurrImage;
        CurrImage->Repaint();
}
~PerceptronSlvl(){};
bool Check();
};

bool PerceptronSlvl::Check(){
int sum = 0;
for(int xi = x; xi < x1; xi++)
        for(int yi = y; yi < y1; yi++)
                if(CurrImage->Picture->Bitmap->Canvas->Pixels[x][y] < 14500000)
                        sum++;
return sum > minsum;
}

#endif PERCEPTRONALVL_H
