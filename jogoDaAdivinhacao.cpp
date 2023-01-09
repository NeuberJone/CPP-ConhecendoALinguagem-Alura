#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main (){

    cout << "**************************************" << endl;
    cout << "* Bem-vindos ao jogo da adivinhacao! *" << endl;
    cout << "**************************************" << endl << endl;

    cout << "Escolha o seu nivel de dificuldade: " << endl;
    cout << "Facil (F), Medio (M) ou Dificil (D)" << endl;

    char dificuldade;
    cin >> dificuldade;

    int numeroDeTentativas;

    if (dificuldade == 'F' || dificuldade == 'f'){
        numeroDeTentativas = 15;
    }
    else if (dificuldade == 'M' || dificuldade == 'm'){
        numeroDeTentativas = 10;
    }
    else {
        numeroDeTentativas = 5;
    }

    srand(time(NULL));
    const int NUMERO_SECRETO = rand() % 100;
    
    bool naoAcertou = true;    
    int tentativas = 0;
    double pontos = 1000.0;

    cout << "O numero secreto e " << NUMERO_SECRETO << ". Nao conte para ninguem!" << endl << endl;

    for(tentativas = 1; tentativas <= numeroDeTentativas; tentativas++){

        int chute;

        cout << "Tentativa " << tentativas << endl;
        cout << "Qual seu chute? ";
        cin >> chute;

        double pontosPerdidos = abs(chute - NUMERO_SECRETO) / 2.0;
        pontos = pontos - pontosPerdidos;

        cout << "O valor do seu chute e: " << chute << endl;

        bool acertou = chute == NUMERO_SECRETO;
        bool maior = chute > NUMERO_SECRETO;

        if (acertou){
            cout << "Parabens! Voce acertou o numero secreto!" << endl << endl;
            break;
        }

        else if (maior){
            cout << "Seu chute foi maior que o numero secreto!" << endl << endl;
        }

        else {
            cout << "Seu chute foi menor que numero secreto!" << endl << endl;
        }

    }

    cout << "Fim de Jogo" << endl;
    if (naoAcertou){
        cout << "Voce perdeu! Tente novamente!" << endl;
    }
    else {
        cout << "Voce acertou o numero secreto em " << tentativas << " tentativas" << endl;
        cout.precision(2);
        cout << fixed;
        cout << "Sua pontuacao foi de " << pontos << " pontos." << endl;
    }
}