#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

string palavraSecreta = "MELANCIA";

map <char, bool> chutou;
vector <char> chutesErrados;

vector<string> leArquivo(){
    ifstream arquivo;
    arquivo.open("palavras.txt");

    if(arquivo.is_open()){

        int quantidadePalavras;
        arquivo >> quantidadePalavras;

        vector <string> palavrasDoArquivo;

        for (int i=0;i<quantidadePalavras;i++){
            string palavraLida;
            arquivo >> palavraLida;
            palavrasDoArquivo.push_back(palavraLida);
        }
        arquivo.close();
        return palavrasDoArquivo;
    } else {
        cout << "Nao foi possivel acessar o banco de palavras." << endl;
        exit (0);
    }
}

void sorteiaPalavra() {
    vector<string> palavras = leArquivo();

    srand(time(NULL));
    int indiceSorteado = rand() % palavras.size();

    palavraSecreta = palavras[indiceSorteado];
}

bool letraExiste (char chute){
    for(char letra : palavraSecreta){
        if(chute == letra){
                return true;
        }
    }
    return false;
}

void imprimeCabecalho(){
    cout << "********************************" << endl;
    cout << "* Bem-vindos ao jogo da forca! *" << endl;
    cout << "********************************" << endl;
    cout << endl;
}

void mostraErros(){
    cout << "Seus chutes errados: ";
    for(char letra : chutesErrados){
        cout << letra << " ";
    }
    cout << endl;
}

void mostraPalavra(){
    for(char letra : palavraSecreta){
        if (chutou [letra]){
            cout << letra << " ";
        }
        else{
            cout << "_ ";
        }
    }
    cout << endl;
}

void chuta(){
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

bool naoAcertou(){
    for(char letra : palavraSecreta){
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

    imprimeCabecalho();
    leArquivo();
    sorteiaPalavra();
    
    cout << "A palavra secreta e: " << palavraSecreta << endl;

    while(naoAcertou() && naoEnforcou()){

        mostraErros();
        mostraPalavra();
        chuta();
    }

    if(naoAcertou()){
        cout << "QUE PENA! Voce perdeu! A palavra secreta era: " << palavraSecreta << endl; 
    }
    else {
        cout << "PARABENS! Voce acertou! A palavra secreta era: " << palavraSecreta << endl; 
    }

}