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
#include "base.h"
using namespace std;

void Ui() {
    while (true) {
        int number, mode;
        Base*tab;
        cout << "Wybierz strukture: " << endl;
        cout << "[1] Tablica dynamiczna" << endl;
        cout << "[2] Lista jednokierunkowa z headem" << endl;
        cout << "[3] Lista jednokierunkowa z headem i tailem" << endl;
        cout << "[4] Lista dwukierunkowa" << endl;
        cout << "[0] Zakoncz" << endl << endl;
        cout << "Wybor: ";
        cin >> mode;
        cout << endl;
        bool start = true;
        switch (mode) {
            case 1: {
                ArrayList *t= new ArrayList;
                tab=t;
                break;
            }
            case 2: {
                SingleListHead *t = new SingleListHead;
                tab=t;
                break;
            }
            case 3: {
                SingleListHT *t = new SingleListHT;
                tab=t;
                break;
            }
            case 4: {
                DoubleList *t = new DoubleList;
                tab=t;
                break;
            }
            default: {
                cout << "Program zakonczony";
                return;
            }
        }

        while (start == 1) {
            switch (mode) {
                case 1: {
                    cout << "Tablica dynamiczna:" << endl;
                    break;

                }
                case 2: {
                    cout << "Lista jednokierunkowa z headem:" << endl;
                    break;
                }
                case 3: {
                    cout << "Lista jednokierunkowa z headem i tailem:" << endl;
                    break;
                }
                case 4: {
                    cout << "Lista dwukierunkowa:" << endl;
                    break;
                }
                default: {
                    cout << "Zly tryb";
                    start = 0;
                    break;
                }
            }
            cout << "[1] Zbuduj z pliku" << endl;
            cout << "[2] Utworz losowo" << endl;
            cout << "[3] Dodaj element" << endl;
            cout << "[4] Usun element" << endl;
            cout << "[5] Znajdz element" << endl;
            cout << "[6] Wyswietl" << endl;
            cout << "[0] Wroc do menu" << endl << endl;
            cout << "Wybor: ";
            cin >> number;
            cout << endl;
            switch (number) {
                case 0: {
                    start = false;
                    delete tab;
                    break;
                }
                case 1: {
                    string name = "";
                    cout << "Podaj nazwe pliku: ";
                    cin >> name;
                    cout << "Podaj ilość danych: ";
                    cin >> number;
                    cout << endl;
                    if (tab->get_size() != 0) {
                        switch (mode) {
                            case 1: {
                                delete tab;
                                ArrayList *temp = new ArrayList;
                                tab = temp;
                                break;

                            }
                            case 2: {
                                delete tab;
                                SingleListHead *temp = new SingleListHead;
                                tab = temp;
                                break;
                            }
                            case 3: {
                                delete tab;
                                SingleListHT *temp = new SingleListHT;
                                tab = temp;
                                break;
                            }
                            case 4: {
                                delete tab;
                                DoubleList *temp = new DoubleList;
                                tab = temp;
                                break;
                            }
                        }
                    }
                    fstream file;
                    file.open(name, ios::in);
                    for (int i = 0; number > i and file.eof() != 1; i++) {
                        int temp;
                        file >> temp;
                        tab->push_back(temp);
                    }
                    file.close();
                    cout << endl << "Wczytano" << endl << endl;
                    break;
                }
                case 2: {
                    srand(time(NULL));
                    cout << "Podaj ilość danych: ";
                    cin >> number;
                    if (tab->get_size() != 0) {
                        switch (mode) {
                            case 1: {
                                delete tab;
                                ArrayList *temp = new ArrayList;
                                tab = temp;
                                break;

                            }
                            case 2: {
                                delete tab;
                                SingleListHead *temp = new SingleListHead;
                                tab = temp;
                                break;
                            }
                            case 3: {
                                delete tab;
                                SingleListHT *temp = new SingleListHT;
                                tab = temp;
                                break;
                            }
                            case 4: {
                                delete tab;
                                DoubleList *temp = new DoubleList;
                                tab = temp;
                                break;
                            }
                        }
                    }
                    int max;
                    cout << "Podaj najwieksza mozliwa liczbe: ";
                    cin >> max;
                    for (int i = 0; number > i; i++) tab->push_back(rand() % (2 * max + 1) - max);
                    cout << endl << "Wygenerowano z liczb z przedzialu <-" << max << "," << max << ">" << endl << endl;
                    break;
                }
                case 3: {
                    int temp;
                    cout << "Dodawanie: " << endl << endl;
                    cout << "[1] Dodaj" << endl;
                    cout << "[2] Dodaj na poczatek" << endl;
                    cout << "[3] Dodaj na koniec" << endl;
                    cout << "[0] Cofnij" << endl << endl;
                    cout << "Wybor: ";
                    cin >> number;
                    switch (number) {
                        case 0: {
                            break;
                        }
                        case 1: {
                            cout << "Podaj indeks do dodania: ";
                            cin >> number;
                            cout << "Podaj liczbe całkowita: ";
                            cin >> temp;
                            if (number > tab->get_size() or number == 0) {
                                cout << endl << "Brak takiego indeksu (iteracja zaczyna sie od 1)" << endl << endl;
                                break;
                            }
                            tab->append(number - 1, temp);
                            cout << endl << "Dodano" << endl << endl;
                            break;
                        }
                        case 2: {
                            cout << "Podaj liczbe całkowita: ";
                            cin >> temp;
                            tab->push_front(temp);
                            cout << endl << "Dodano" << endl << endl;
                            break;
                        }
                        case 3: {
                            cout << "Podaj liczbe całkowita: ";
                            cin >> temp;
                            tab->push_back(temp);
                            cout << endl << "Dodano" << endl << endl;
                            break;
                        }
                        default: {
                            break;
                        }
                    }
                    break;
                }
                case 4: {
                    cout << "Usuwanie: " << endl << endl;
                    cout << "[1] Usun" << endl;
                    cout << "[2] Usun na poczatku" << endl;
                    cout << "[3] Usun na koncu" << endl;
                    cout << "[0] Cofnij" << endl << endl;
                    cout << "Wybor: ";
                    cin >> number;
                    switch (number) {
                        case 0: {
                            break;
                        }
                        case 1: {
                            cout << "Podaj indeks do usuniecia: ";
                            cin >> number;
                            if (number > tab->get_size()or number==0) {
                                cout << endl << "Brak takiego indeksu (iteracja zaczyna sie od 1)"<< endl << endl;
                                break;
                            }
                            tab->del(number - 1);
                            cout << endl << "Usunieto" << endl << endl;
                            break;
                        }
                        case 2: {
                            tab->del_front();
                            cout << endl << "Usunieto" << endl << endl;
                            break;
                        }
                        case 3: {
                            tab->del_back();
                            cout << endl << "Usunieto" << endl << endl;
                            break;
                        }
                        default: {
                            break;
                        }
                    }
                    break;
                }
                case 5: {
                    int temp;
                    cout << "Podaj element do wyszukania: ";
                    cin >> temp;
                    cout << "Numer pierwszego znalezionego elementu: " << tab->search(temp) << endl << endl;
                    break;
                }
                case 6: {
                    tab->print();
                    break;
                }
                default: {
                    start = false;
                    break;
                }
            }
        }
    }
}