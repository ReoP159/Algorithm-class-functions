#include "Token.cpp"

struct Coll{
    string s;
    char sep;
};

//generals
Coll collCreate(char sep){
    Coll coll;
    coll.s = "";
    coll.sep = sep;
    return coll;
}

int collSize(Coll c){
    return tokenCount(c.s, c.sep);
}

void collRemoveAll(Coll& c){
    c.s = "";
}

void collRemoveAt(Coll& c, int p){
    removeTokenAt(c.s, c.sep, p);
}

//string
void collAddString(Coll& c, string s){
    addToken(c.s, c.sep, s);
}

void collSetStringAt(Coll& c, string s, int p){
    setTokenAt(c.s, c.sep, s, p);
}

string collGetString(Coll c, int p){
    return getTokenAt(c.s, c.sep, p);
}

int collFindString(Coll c, string s){
    return findToken(c.s, c.sep, s);
}

//integers
void collAddInt(Coll& c, int i){
    addToken(c.s, c.sep, intToString(i));
}

void collSetIntAt(Coll& c, int i, int p){
    setTokenAt(c.s, c.sep, intToString(i), p);
}

int collGetIntAt(Coll c, int p){
    return stringToInt(getTokenAt(c.s, c.sep, p));
}

int collFindInt(Coll c, int i){
    return findToken(c.s, c.sep, intToString(i));
}

//double


void collAddDouble(Coll& c, double d){
    addToken(c.s, c.sep, doubleToString(d));
}

void collSetDoubleAt(Coll& c, double d, int p){
    setTokenAt(c.s, c.sep, doubleToString(d), p);
}

double  collGetDoubleAt(Coll c, int p){
    return  stringToDouble(getTokenAt(c.s, c.sep, p));
}

int collFindDouble(Coll c, double d){
    return findToken(c.s, c.sep, doubleToString(d));
}

//char

void collAddChar(Coll& c, char ch){
    addToken(c.s, c.sep, charToString(ch));
}

void colllSetCharAt(Coll& c, char ch, int p){
    setTokenAt(c.s, c.sep, charToString(ch), p);
}

char collGetCharAt(Coll c, int p){
    return stringToChar(getTokenAt(c.s, c.sep, p));
}

int collFindChar(Coll c, char ch){
    return  findToken(c.s, c.sep, charToString(ch));
}

//templates
template <typename  T>
void collAdd<T>(Coll& c, T t, string tToString(T)){
    addToken(c.s, c.sep, tToString(t));
}

template <typename  T>
void collSetAt<T>(Coll& c, T t, int p, string tToString(T)){
    setTokenAt(c.s, c.sep, tToString(t), p);
}

template <typename  T>
T collGetAt(Coll c, int p, T stringToT(string)){
    return stringToT(getTokenAt(c.s, c.sep, p));
}

template <typename  T, typename K>
int collFind(Coll c, K k, int compare(T,K), T stringToT(string)){
    for(int i = 0; i < collSize(c); i++){
        if(compare(stringToT(getTokenAt(c.s,c.sep, i)), k) == 0) return i;
    }
    return -1;
};

template <typename  T>
void collSort(Coll& c, T t, int compare(T,T), T stringToT(string), string tToString(T)){
    int base = 0;
    t = collGetAt(c,base, stringToT);

    while (base < collSize(c)){
        T buff = collGetAt(c, base, stringToT);
        int pos = 0;
        for (int i  = 0; i  < collSize(c); ++i ) {

            if(compare( collGetAt(c,i, stringToT), t ) <= 0){
                t =  collGetAt(c,i, stringToT);
                pos = i;

            }

        }
        collSetAt(c, buff, pos, tToString);
        collSetAt(c, t, base, tToString );
        base++;
    }

}




