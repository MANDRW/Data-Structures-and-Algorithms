#include "UI.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cstdio>
#include<fstream>
#include <string>
#include "ArrayList.h"
#include "SingleListHead.h"
#include "SingleListHT.h"
#include "DoubleList.h"
using namespace std;

void Ui(){
    while(true){
        int number;
        cout<<"Wybierz strukture: "<<endl;
        cout<<"[1] Tablica dynamiczna"<<endl;
        cout<<"[2] Lista jednokierunkowa z headem"<<endl;
        cout<<"[3] Lista jednokierunkowa z headem i tailem"<<endl;
        cout<<"[4] Lista dwukierunkowa"<<endl;
        cout<<"[0] Zakoncz"<<endl<<endl;
        cout<<"Wybor: ";
        cin>>number;
        cout<<endl;
        switch(number){
            case 0:{
                cout<<"Program zakonczony";
                return;
            }
            case 1:{
                bool start=true;
                ArrayList*tab=new ArrayList;
                while(start==1){
                    cout<<"Tablica dynamiczna"<<endl<<endl;
                    cout<<"[1] Zbuduj z pliku"<<endl;
                    cout<<"[2] Utworz losowo"<<endl;
                    cout<<"[3] Dodaj element"<<endl;
                    cout<<"[4] Usun element"<<endl;
                    cout<<"[5] Znajdz element"<<endl;
                    cout<<"[6] Wyswietl"<<endl;
                    cout<<"[0] Wroc do menu"<<endl<<endl;
                    cout<<"Wybor: ";
                    cin>>number;
                    cout<<endl;
                    switch (number) {
                        case 0:{
                            start=false;
                            delete tab;
                            break;
                        }
                        case 1:{
                            string name="";
                            cout<<"Podaj nazwe pliku: ";
                            cin>>name;
                            cout<<"Podaj ilość danych: ";
                            cin>>number;
                            cout<<endl;
                            if(tab->get_size()!=0){
                                delete tab;
                                ArrayList*temp=new ArrayList(number);
                                tab=temp;
                            }
                            fstream file;
                            file.open(name,ios::in);
                            for(int i=0;number>i and file.eof()!=1;i++){
                                int temp;
                                file>>temp;
                                tab->push_back(temp);
                            }
                            file.close();
                            cout<<endl<<"Wczytano"<<endl<<endl;
                            break;
                        }
                        case 2:{
                            srand(time(NULL));
                            cout<<"Podaj ilość danych: ";
                            cin>>number;
                            if(tab->get_size()!=0){
                                delete tab;
                                ArrayList*temp=new ArrayList(number);
                                tab=temp;
                            }
                            int max;
                            cout<<"Podaj najwieksza mozliwa liczbe: ";
                            cin>>max;
                            for(int i=0;number>i;i++) tab->push_back(rand()%(2*max+1)-max);
                            cout<<endl<<"Wygenerowano z liczb z przedzialu <-"<<max<<","<<max<<">"<<endl<<endl;
                            break;
                        }
                        case 3:{
                            int temp;
                            cout<<"Dodawanie: "<<endl<<endl;
                            cout<<"[1] Dodaj"<<endl;
                            cout<<"[2] Dodaj na poczatek"<<endl;
                            cout<<"[3] Dodaj na koniec"<<endl;
                            cout<<"[0] Cofnij"<<endl<<endl;
                            cout<<"Wybor: ";
                            cin>>number;
                            switch (number) {
                                case 0:{
                                    break;
                                }
                                case 1:{
                                    cout<<"Podaj indeks do dodania: ";
                                    cin>>number;
                                    cout<<"Podaj liczbe całkowita: ";
                                    cin>>temp;
                                    if(number>tab->get_size()){
                                        cout<<endl<<"Brak takiego indeksu"<<endl<<endl;
                                        break;
                                    }
                                    tab->append(number-1,temp);
                                    cout<<endl<<"Dodano"<<endl<<endl;
                                    break;
                                }
                                case 2:{
                                    cout<<"Podaj liczbe całkowita: ";
                                    cin>>temp;
                                    tab->push_front(temp);
                                    cout<<endl<<"Dodano"<<endl<<endl;
                                    break;
                                }
                                case 3:{
                                    cout<<"Podaj liczbe całkowita: ";
                                    cin>>temp;
                                    tab->push_back(temp);
                                    cout<<endl<<"Dodano"<<endl<<endl;
                                    break;
                                }
                                default:{
                                    break;
                                }
                            }
                            break;
                        }
                        case 4:{
                            cout<<"Usuwanie: "<<endl<<endl;
                            cout<<"[1] Usun"<<endl;
                            cout<<"[2] Usun na poczatku"<<endl;
                            cout<<"[3] Usun na koncu"<<endl;
                            cout<<"[0] Cofnij"<<endl<<endl;
                            cout<<"Wybor: ";
                            cin>>number;
                            switch (number) {
                                case 0:{
                                    break;
                                }
                                case 1:{
                                    cout<<"Podaj indeks do usuniecia: ";
                                    cin>>number;
                                    if(number>tab->get_size()) {
                                        cout <<endl<< "Brak takiego indeksu" << endl << endl;
                                        break;
                                    }
                                    tab->del(number-1);
                                    cout<<endl<<"Usunieto"<<endl<<endl;
                                    break;
                                }
                                case 2:{
                                    tab->del_front();
                                    cout<<endl<<"Usunieto"<<endl<<endl;
                                    break;
                                }
                                case 3:{
                                    tab->del_back();
                                    cout<<endl<<"Dodano"<<endl<<endl;
                                    break;
                                }
                                default:{
                                    break;
                                }
                            }
                            break;
                        }
                        case 5:{
                            int temp;
                            cout<<"Podaj element do wyszukania: ";
                            cin>>temp;
                            cout<<"Element nr: "<<tab->search(temp)<<endl<<endl;
                            break;
                        }
                        case 6:{
                            for(int i=0;tab->get_size()>i;i++)
                                cout<<tab->get(i)<<endl;
                            cout<<endl;
                            break;
                        }
                        default:{
                            start=false;
                            break;
                        }
                    }
                }
                break;
            }
            case 2:{

                break;
            }
            case 3:{
                bool start = true;
                SingleListHT* slht = new SingleListHT;
                while(start == true)
                {
                    cout<<"Lista jednokierunkowa z headem i tailem"<<endl<<endl;
                    cout<<"[1] Zbuduj z pliku"<<endl;
                    cout<<"[2] Utworz losowo"<<endl;
                    cout<<"[3] Dodaj element"<<endl;
                    cout<<"[4] Usun element"<<endl;
                    cout<<"[5] Znajdz element"<<endl;
                    cout<<"[6] Wyswietl"<<endl;
                    cout<<"[0] Wroc do menu"<<endl<<endl;
                    cout<<"Wybor: ";
                    cin>>number;
                    cout<<endl;
                    switch(number) {
                        case 0:
                        {
                            start = false;
                            delete slht;
                            break;
                        }
                        case 1:{
                            string name = "";
                            cout << "Podaj nazwe pliku z ktorego chcesz pobierac dane" << endl;
                            cin >> name;
                            cout << "Podaj ilosc danych ktore chcesz pobrac" << endl;
                            cin >> number;
                            cout << endl;
                            if(slht->get_size() != 0){
                               delete slht;
                               SingleListHT* slht = new SingleListHT;
                            }
                            fstream file;
                            file.open(name,ios::in);
                            for(int i = 0; number>i and file.eof()!=1;i++){
                                int temp;
                                file>>temp;
                                slht->push_back(temp);
                            }
                            break;
                        }
                        case 2:{
                            break;
                        }
                        case 3:{
                            int temp;
                            cout<<"Dodawanie: "<<endl<<endl;
                            cout<<"[1] Dodaj w podanym miejscu"<<endl;
                            cout<<"[2] Dodaj na poczatek"<<endl;
                            cout<<"[3] Dodaj na koniec"<<endl;
                            cout<<"[0] Cofnij"<<endl<<endl;
                            cout<<"Wybor: ";
                            cin>>number;
                            switch (number) {
                                case 0:{
                                    break;
                                }
                                case 1:{
                                    cout << "Podaj wartosc do dodania" << endl;
                                    cin >> temp;
                                    cout << "Podaj numer indeksu" << endl;
                                    cout << "Od 0 do " << slht->get_size() << endl;
                                    cin >> number;
                                    if(number > slht->get_size())
                                    {
                                        cout << "Index poza wielkoscia tablicy" << endl;
                                        break;
                                    }
                                    slht->append(number,temp);
                                    cout << "Poprawnie dodano" << endl << endl;
                                    break;
                                }
                                case 2:{
                                    cout << "Podaj wartosc do dodania" << endl;
                                    cin >> temp;
                                    slht->push_front(temp);
                                    cout <<endl<<"Poprawnie dodano" << endl << endl;
                                    break;
                                }
                                case 3:{
                                    cout << "Podaj wartość do dodania na koniec" << endl;
                                    cin >> temp;
                                    slht->push_back(temp);
                                    cout << endl << " Poprawnie dodano wartosc" << endl << endl;
                                    break;
                                }
                            }
                        }
                        case 4:{
                            cout<<"Usuwanie: "<<endl<<endl;
                            cout<<"[1] Usun"<<endl;
                            cout<<"[2] Usun na poczatku"<<endl;
                            cout<<"[3] Usun na koncu"<<endl;
                            cout<<"[0] Cofnij"<<endl<<endl;
                            cout<<"Wybor: ";
                            cin>>number;
                            switch (number){
                                case 0:{
                                    break;
                                }
                                case 1:{
                                    cout << "Podaj indeks który chcesz usunac" << endl;
                                    cin >> number;
                                    if(number > slht->get_size())
                                    {
                                        cout << "Index poza wielkoscia tablicy" << endl;
                                        break;
                                    }
                                    slht->del(number);
                                    cout << "Poprawnie usunieto" << endl << endl;
                                    break;
                                }
                                case 2:{
                                    if(slht->get_size() == 0)
                                    {
                                        cout << "Lista jest pusta" << endl << endl;
                                    }
                                    slht->del_front();
                                    cout << "Poprawnie usunieto" << endl << endl;
                                    break;
                                }
                                case 3:{
                                    if(slht->get_size() == 0)
                                    {
                                        cout << "Lista jest pusta" << endl << endl;
                                    }
                                    slht->del_back();
                                    cout << "Poprawnie usunieto" << endl << endl;
                                    break;
                                }
                            }
                            break;
                        }
                        case 5:{
                            int temp;
                            cout << "Podaj element który chcesz wyszukać" << endl;
                            cin >> temp;
                            cout << "index elementu: " << slht->search(temp) << endl << endl;
                            break;
                        }
                        case 6:{
                            slht->print_all();
                            break;
                        }
                    }

                }

                break;
            }
            case 4:{

                break;
            }
            default:{
                break;
            }
        }

        //menu wyswietlanie wyboru struktury
        //zbudujz pliku, usun, dodaj, znajdz, utworz losowo, wyswietl
    }

}