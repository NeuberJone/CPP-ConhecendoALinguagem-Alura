#include <iostream>

using namespace std;

int main (){

    cout << "**************************************" << endl;
    cout << "* Bem-vindos ao jogo da adivinhacao! *" << endl;
    cout << "**************************************" << endl;

    int numeroSecreto = 42;
    int chute;

    cout << "O numero secreto e " << numeroSecreto << ". Nao conte para ninguem!" << endl;

    do {

        cout << "Qual seu chute? ";
        cin >> chute;
        cout << "O valor do seu chute e: " << chute << endl;

        if (chute == numeroSecreto){
            cout << "Parabens! Voce acertou o numero secreto!" << endl;
        }

        else if (chute > numeroSecreto){
            cout << "Seu chute foi maior que o numero secreto!" << endl;
        }

        else {
            cout << "Seu chute foi menor que numero secreto!" << endl;
        }

    }while (chute != numeroSecreto);
}