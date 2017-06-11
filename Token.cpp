#include "String.cpp"


int tokenCount(string s, char sep){
    return  charCount(s, sep)+1;
}

string getTokenAt(string s, char sep, int i){
    s = substring(s, indexOfN(s, sep, i));
    return i > tokenCount(s, sep) ? s : substring(s ,0, indexOf(s, '|'));
}

void addToken(string& s, char sep, string t){
    s += (s=="")? t : sep + t;
}

string removeTokenAt(string& s, char sep, int i){
    string buff = "";
    for (int y = 0; y < tokenCount(s, sep); y++){
        if(i!=y) {
            addToken(buff, sep, getTokenAt(s, sep, y));
        }
    }
    s = buff;
    return  buff;
}

void setTokenAt(string& s, char sep, string t, int i){
    string buff = "";
    for (int x = 0; x < tokenCount(s, sep); x++){

        (i!=x) ? addToken(buff, sep, getTokenAt(s,sep, x)) : addToken(buff, sep, t);
    }

    s = buff;
}

int findToken(string s, char sep, string t){
    for(int i = 0; i < tokenCount(s, sep); i++){
        if(getTokenAt(s, sep, i)==t){
            return i;
        }
    }
    return  -1;
}


