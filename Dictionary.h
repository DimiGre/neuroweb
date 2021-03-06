#ifndef DICTIONARY_H
#define DICTIONARY_H

class Dictionary{
struct Word{
        char* word;
        Word* next;
        int count;
        Word(char* _word, int _count = 0){word = _word; count = _count; next = NULL;}
        ~Word(){
        delete word;
        if(next != NULL)
        delete next;}
};
static const int SIZE = 80;
Word* wordbook[SIZE];

public:                                                            
void Add(char*, int);
char* Compare(char*);
Dictionary(){for(int i = 0; i < SIZE; i++) wordbook[i] = NULL;};
~Dictionary();
};

Dictionary::~Dictionary(){
        for(int i = 0; i < SIZE; i++) delete wordbook[i];
}

void Dictionary::Add(char* _word, int _count = 0){
if(strlen(_word) > SIZE){
        ShowMessage(AnsiString(_word) + " больше максимального размера. Невозможно добавить");
        return;
}
Word** where = &(wordbook[strlen(_word) - 1]);
while((*where) != NULL){
        where = &((*where)->next);
        (*where)->word;
}
*where = new Word(_word, _count);
}

char* Dictionary::Compare(char* _word){
int len = 0;
int l = strlen(_word);
for(int i = 0; i < l; i++) if(_word[i] == '\n') len++;
Word* toRet, *curr = wordbook[len - 1];
int maxSum = 0;
while(curr != NULL){
        int sum = 0;
        for(int Pos = 0, Cpos = 0; Cpos < len; Pos++){
                while(_word[Pos] == '\n'){
                        Pos++;
                        Cpos++;
                }
                if(_word[Pos] == curr->word[Cpos]) sum++;
                }
                if(sum > maxSum){
                        maxSum = sum;
                        toRet = curr;
                }
                curr = curr->next;
        }
return toRet->word;
}


#endif
