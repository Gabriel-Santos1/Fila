#include <iostream>
#include <windows.h>
#include <fstream>
using namespace std;

const int MAX_PESSOAS = 10;

struct Client
{
    string name[MAX_PESSOAS];
    int number[MAX_PESSOAS];
    string describle[MAX_PESSOAS];
    int top = -1;
};

void newRequest();
void nextRequest();
void viewAll();
void remove();
bool full();
bool empty();
int menu();
void import();
void exporte();

Client client1;

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    int opcao;

    do
    {
        opcao = menu();

        switch (opcao)
        {
        case 1:
            newRequest();
            break;

        case 2:
            nextRequest();
            break;

        case 3:
            viewAll();
            break;

        case 4:
            remove();
            break;

        case 5:
            exporte();
            break;

         case 6:
            import();
            break;

        case 0:
            cout << ("Obrigado por comer no restaurante: Comeu, Morreu");
            break;

        default:
            cout << ("Opção Invalida");
            break;
        }

    } while (opcao != 0);

    cout << endl
         << endl;
    return 0;
}

void newRequest()
{
    if (full())
    {
        cout << ("The list is full");
    }

    else
    {
        client1.top++;
        cout << ("Digite seu nome: ") << endl;
        cin.ignore();
        getline(cin, client1.name[client1.top]);
        cout << ("O numero da mesa ") << endl;
        cin >> client1.number[client1.top];
        cout << ("Digite a descrição do pedido: ") << endl;
        cin.ignore();
        getline(cin, client1.describle[client1.top]);
        cout << ("Pedido computado") << endl;
    }
}

void nextRequest()
{
    if (empty())
    {
        cout << ("Don't have request") << endl;
        system("pause");
        system("cls");
    }
    else
    {
        cout << ("***** Mesa: ") << client1.number[0] << (" *****") << endl;
        cout << ("Titular: ") << client1.name[0] << endl;
        cout << ("Pedido: ") << client1.describle[0] << endl;
        system("pause");
        system("cls");
    }
}

void viewAll()
{
    if (empty())
    {
        cout << ("Não tem pedidos") << endl;
        system("pause");
        system("cls");
    }
    else
    {
        for (int i = 0; i <= client1.top; i++)
        {
            cout << ("***** Mesa: ") << client1.number[i] << (" *****") << endl;
            cout << ("Titular: ") << client1.name[i] << endl;
            cout << ("Pedidos: ") << client1.describle[i] << endl;
        }
        system("pause");
        system("cls");
    }
}

void remove()
{
    if (empty())
    {
        cout << ("Don't have request") << endl;
        system("pause");
        system("cls");
    }
    else
    {
        cout << ("The request of ") << client1.name[0] << (" is ready") << endl;
        for (int i = client1.top; i >= 1; i--)
        {
            client1.name[i - 1] = client1.name[i];
            client1.describle[i - 1] = client1.describle[i];
            client1.number[i - 1] = client1.number[i];
        }
        client1.top--;
        system("pause");
        system("cls");
    }
}
void exporte()
{
    ofstream arquivo("Pedidos.txt");
        if(empty()){
            cout << ("Lista de pedidos Vazia");
        }
        else{
            for (int i = 0; i < 2; i++)
            {
                if (i == 0)
                {
                    arquivo << client1.top << endl;
                }
                arquivo << client1.number[i] << endl;
                arquivo << client1.name[i] << endl;
                arquivo << client1.describle[i] << endl;
            }
            cout << ("Pedidos Cadastrados!");
            arquivo.close();
        }
            
    
}

void import()
{
    ifstream arquivo("Pedidos.txt");
        
            arquivo >> client1.top;
            for (int i = 0; i < 2; i++)
            {
                arquivo >> client1.number[i];
                arquivo >> client1.name[i];
                arquivo >> client1.describle[i];
            }
            cout << ("Lista de pedidos atualizada com sucesso!") << endl;
}
bool full()
{
    if (client1.top >= MAX_PESSOAS - 1)
    {
        return true;
    }
    return false;
}

bool empty()
{
    if (client1.top == -1)
    {
        return true;
    }
    return false;
}

int menu()
{
    int opcao;
    cout << ("1- Para um novo pedido") << endl;
    cout << ("2- Para saber o proximo pedido") << endl;
    cout << ("3- Para ver todos os pedidos") << endl;
    cout << ("4- Para a entrega do pedido") << endl;
    cout << ("5- Para salvar os pedidos no sistema") << endl;
    cout << ("6- Para pegar os pedidos salvos") << endl;
    cout << ("0- Para sair") << endl;
    cin >> opcao;
    return opcao;
}