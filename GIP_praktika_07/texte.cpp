
#include "texte.h"

void spalte_ab_erstem(const std::string &eingabe, char trennzeichen, std::string &teil1, std::string &rest) {
    size_t position = eingabe.find(trennzeichen);
    if (position != std::string::npos) {
        size_t erste_komma = position;
        for(size_t i=0; i< erste_komma ; i++){
            teil1 += eingabe[i];
        }
        while(position < eingabe.length()){
            rest += eingabe[position+1];
            position++;
        }


        //teil1 = eingabe[i];
        //rest = eingabe[position + 1];
    } else {
        teil1 = eingabe;
        rest = "";
    }

}

std::string trimme(const std::string &s){
    std::string s_trimm = s;
    int i=0,j=0;
    while(s_trimm[i]){
        if(s_trimm[i] == ' '){
            s_trimm[j++] = s_trimm[i];
            i++;
        }

        return s_trimm;
    }
}


std::string ersetze(const std::string &s, char placeholder, const std::string &replacement) {
    std::string result = "";

    for(int i = 0; i < s.length(); i++) {
        if (s.at(i) != placeholder) result += s.at(i);
        else result += replacement; 
    }

    // size_t pos = 0;
    // int j=0;
    // for(int i =0;i<result.length();i++){
    //     if(s[i] == placeholder){
    //         pos = i;

    //     }
    // }
    // if(pos != 0){
    // for(int i = pos; i<replacement.length();i++){
    //         result += replacement[i];
    //     }
    //    // pos = result.find(placeholder, pos + replacement.length());
    
    // }
    return result;
}
