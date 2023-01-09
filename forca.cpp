#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

const string PALAVRA_SECRETA = "MELANCIA";
map <char, bool> chutou;
vector <char> chutesErrados;

bool letraExiste (char chute){
    for(char letra : PALAVRA_SECRETA){
        if(chute == letra){
                return true;
        }
    }
    return false;
}

bool naoAcertou(){
    for(char letra : PALAVRA_SECRETA){
        if(!chutou[letra]){
            return true;
        }
    }
    return false;
}

bool naoEnforcou(){
    return chutesErrados.size() < 5;
}

int main (){

    cout << "********************************" << endl;
    cout << "* Bem-vindos ao jogo da forca! *" << endl;
    cout << "********************************" << endl;
    cout << endl;
    
    cout << "A palavra secreta e: " << PALAVRA_SECRETA << endl;

    while(naoAcertou() && naoEnforcou()){

        cout << "Seus chutes errados: ";
        for(char letra : chutesErrados){
                cout << letra << " ";
            }
            cout << endl;

        for(char letra : PALAVRA_SECRETA){
            if (chutou [letra]){
                cout << letra << " ";
            }
            else{
                cout << "_ ";
            }
        }
        cout << endl;
        
        cout << "Qual seu chute? ";
        char chute;
        cin >> chute;

        chutou[chute] = true;

        if(letraExiste(chute)){
            cout << "Voce acertou! Seu chute esta na palavra." << endl;
        }
        else{
            cout << "Voce errou! Seu chute nao esta na palavra!" << endl;
            chutesErrados.push_back(chute);
        }
        cout << endl;
    }

    if(!naoAcertou()){
        cout << "PARABENS! Voce acertou! A palavra secreta era: " << PALAVRA_SECRETA << endl; 
    }
    else {
        cout << "QUE PENA! Voce perdeu! A palavra secreta era: " << PALAVRA_SECRETA << endl; 
    }

}