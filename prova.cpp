#include <iostream>
#include <cctype> 

using namespace std;

int main() {
    char reserva[10][6] = {
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '}
    };

    int fileira = -1, assento = -1;
    char poltrona = ' ';
    int opcao = -1;
    int categoria = -1;

    while (true) {
        cout << "Escolha uma opcao:";
        cout << "\n[1] Reservar poltrona";
        cout << "\n[2] Mostrar quadro de poltronas";
        cout << "\n[3] Sair\n";
        cin >> opcao;

        if (opcao == 1) {
            cout << "\nEscolha a categoria da sua reserva: \n";
            cout << "\n[1] Executiva\n";
            cout << "\n[2] Economica\n";
            cin >> categoria;

            bool reservarMais = true;

            while (reservarMais) {
                if (categoria == 1) { // Executiva
                    cout << "\nDigite a fileira (1-10): ";
                    cin >> fileira;

                    cout << "\nDigite a poltrona [A][B][C][D][E][F]: ";
                    cin >> poltrona;
                    poltrona = tolower(poltrona); // Converte para minúscula

                    // Verifica se a poltrona é válida
                    if (fileira < 1 || fileira > 10 || (poltrona < 'a' || poltrona > 'f')) {
                        cout << "\nPoltrona ou fileira invalida. Tente novamente.\n";
                        continue; // Solicita novamente a entrada
                    }

                    switch (poltrona) {
                    case 'a':
                        assento = 0;
                        break;
                    case 'b':
                        assento = 1;
                        break;
                    case 'c':
                        assento = 2;
                        break;
                    case 'd':
                        assento = 3;
                        break;
                    case 'e':
                        assento = 4;
                        break;
                    case 'f':
                        assento = 5;
                        break;
                    }

                    // Verifica se o assento já está reservado
                    if (reserva[fileira - 1][assento] == 'x') {
                        cout << "Esse assento ja esta reservado. Por favor, escolha outro.\n";
                        continue;
                    }

                    reserva[fileira - 1][assento] = 'x';

                    // Recomendações para outras reservas
                    cout << "Para reservas Executivas, considere as poltronas A ou F!\n";

                }
                else if (categoria == 2) { // Econômica
                    cout << "\nDigite a fileira (1-10): ";
                    cin >> fileira;

                    cout << "\nDigite a poltrona [B][C][D][E]: ";
                    cin >> poltrona;
                    poltrona = tolower(poltrona); // Converte para minúscula

                    // Verifica se a poltrona é válida
                    if (fileira < 1 || fileira > 10 || (poltrona < 'b' || poltrona > 'e')) {
                        cout << "\nPoltrona ou fileira invalida. Tente novamente.\n";
                        continue; // Solicita novamente a entrada
                    }

                    switch (poltrona) {
                    case 'b':
                        assento = 1;
                        break;
                    case 'c':
                        assento = 2;
                        break;
                    case 'd':
                        assento = 3;
                        break;
                    case 'e':
                        assento = 4;
                        break;
                    }

                    // Verifica se o assento já está reservado
                    if (reserva[fileira - 1][assento] == 'x') {
                        cout << "Esse assento já está reservado. Por favor, escolha outro.\n";
                        continue;
                    }

                    reserva[fileira - 1][assento] = 'x';
                }

                // Pergunta se deseja realizar outra reserva
                char resposta;
                cout << "Deseja realizar outra reserva? (s/n): ";
                cin >> resposta;

                if (tolower(resposta) == 'n') {
                    reservarMais = false;
                    cout << "Encerrando o sistema de reservas...\n";
                }
            }

        }
        else if (opcao == 2) {
            cout << "\n\t\t[A] [B] [C]\t[D] [E] [F]\n";
            for (int x = 0; x < 10; x++) {
                printf("\n\t%02d\t", x + 1); // Formatação de fileira
                for (int y = 0; y < 6; y++) {
                    printf("[%c] ", reserva[x][y]);
                    if (y == 2) {
                        printf("\t");
                    }
                }
            }
            printf("\n");
        }

        if (opcao == 3) break;
    }

    return 0;
}