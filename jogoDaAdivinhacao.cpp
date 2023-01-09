#include <iostream>

using namespace std;

int main (){

    cout << "**************************************" << endl;
    cout << "* Bem-vindos ao jogo da adivinhacao! *" << endl;
    cout << "**************************************" << endl;

    int numeroSecreto = 42;
    int chute;
    bool acertou = chute == numeroSecreto;
    bool maior = chute > numeroSecreto;

    cout << "O numero secreto e " << numeroSecreto << ". Nao conte para ninguem!" << endl;

    do {

        cout << "Qual seu chute? ";
        cin >> chute;
        cout << "O valor do seu chute e: " << chute << endl;

        if (acertou){
            cout << "Parabens! Voce acertou o numero secreto!" << endl;
        }

        else if (maior){
            cout << "Seu chute foi maior que o numero secreto!" << endl;
        }

        else {
            cout << "Seu chute foi menor que numero secreto!" << endl;
        }

    }while (chute != numeroSecreto);
}