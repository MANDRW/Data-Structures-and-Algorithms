#include <iostream>
#include "ArrayList.h"
#include "SingleListHead.h"
#include "SingleListHT.h"
#include "DoubleList.h"
#include "UI.h"
#include<fstream>
#include<ctime>
#include<cstdio>


using namespace std;

int main()
{
    //5000, 8000, 10000, 16000, 20000, 40000, 60000, 100000
    //Ilośc ́różnych punktów pomiarowych (rozmiarów problemu) powinna wynosić ok.8,
    // aby uzyskać odpowiednie rezultaty możliwe do przeanalizowania.
    // Podczas pomiaru czasu wykonywania, wyłączyć zbędne aplikacje.
    //W przypadku tablicy i list rozpatrzeć osobno operacje dodawania i usuwania elementu na różnych pozycjach:
    //– początek tablicy (listy),
    //– koniec tablicy (listy),
    //– losowe miejsce tablicy (listy).
    //• W kontekście wyszukiwania – generujemy liczbę, której szukamy w strukturze.
    //Ui();
    srand(time(NULL));
    int size_file=5000;
    fstream file;

    ArrayList*tab1=new ArrayList;
    ArrayList*tab2=new ArrayList;
    ArrayList*tab3=new ArrayList;
    ArrayList*tab4=new ArrayList;
    ArrayList*tab5=new ArrayList;
    ArrayList*tab6=new ArrayList;
    ArrayList*tab7=new ArrayList;
    ArrayList*tab8=new ArrayList;
    ArrayList*tab9=new ArrayList;
    ArrayList*tab10=new ArrayList;
    ArrayList*tab11=new ArrayList;
    ArrayList*tab12=new ArrayList;
    ArrayList*tab13=new ArrayList;
    ArrayList*tab14=new ArrayList;
    ArrayList*tab15=new ArrayList;
    ArrayList*tab16=new ArrayList;
    ArrayList*tab17=new ArrayList;
    ArrayList*tab18=new ArrayList;
    ArrayList*tab19=new ArrayList;
    ArrayList*tab20=new ArrayList;
    ArrayList*tab21=new ArrayList;
    ArrayList*tab22=new ArrayList;
    ArrayList*tab23=new ArrayList;
    ArrayList*tab24=new ArrayList;
    ArrayList*tab25=new ArrayList;

    cout<<"ArrayList"<<endl<<endl;

    file.open("test_data_small.txt",ios::in);
    for (int i = 0; size_file > i and file.eof() != 1; i++) {
        int temp;
        file >> temp;
        tab1->push_back(temp);
        tab2->push_back(temp);
        tab3->push_back(temp);
        tab4->push_back(temp);
        tab5->push_back(temp);
        tab6->push_back(temp);
        tab7->push_back(temp);
        tab8->push_back(temp);
        tab9->push_back(temp);
        tab10->push_back(temp);
        tab11->push_back(temp);
        tab12->push_back(temp);
        tab13->push_back(temp);
        tab14->push_back(temp);
        tab15->push_back(temp);
        tab16->push_back(temp);
        tab17->push_back(temp);
        tab18->push_back(temp);
        tab19->push_back(temp);
        tab20->push_back(temp);
        tab21->push_back(temp);
        tab22->push_back(temp);
        tab23->push_back(temp);
        tab24->push_back(temp);
        tab25->push_back(temp);
    }

     cout<<"Wczytano "<<size_file<<" danych z przedzialu <-10,10>, 1 plik"<<endl<<endl;
    cout<<"Badanie na 25 strukturach"<<endl<<endl;
     int number=(rand()%21)-10;
     cout<<"Liczba dodana/usunieta: "<<number<<endl;
     //dodawanie na poczatku
     clock_t start=clock();
     tab1->push_front(number);
     tab2->push_front(number);
     tab3->push_front(number);
     tab4->push_front(number);
     tab5->push_front(number);
    tab6->push_front(number);
    tab7->push_front(number);
    tab8->push_front(number);
    tab9->push_front(number);
    tab10->push_front(number);
    tab11->push_front(number);
    tab12->push_front(number);
    tab13->push_front(number);
    tab14->push_front(number);
    tab15->push_front(number);
    tab16->push_front(number);
    tab17->push_front(number);
    tab18->push_front(number);
    tab19->push_front(number);
    tab20->push_front(number);
    tab21->push_front(number);
    tab22->push_front(number);
    tab23->push_front(number);
    tab24->push_front(number);
    tab25->push_front(number);
     clock_t end=clock();
     double time=double(end-start)/CLOCKS_PER_SEC;
     cout<<"Czas dodania na poczatek: "<<time<<" ms"<<endl;
     //dodawanie na koncu
    start=clock();
    tab1->push_back(number);
    tab2->push_back(number);
    tab3->push_back(number);
    tab4->push_back(number);
    tab5->push_back(number);
    tab6->push_back(number);
    tab7->push_back(number);
    tab8->push_back(number);
    tab9->push_back(number);
    tab10->push_back(number);
    tab11->push_back(number);
    tab12->push_back(number);
    tab13->push_back(number);
    tab14->push_back(number);
    tab15->push_back(number);
    tab16->push_back(number);
    tab17->push_back(number);
    tab18->push_back(number);
    tab19->push_back(number);
    tab20->push_back(number);
    tab21->push_back(number);
    tab22->push_back(number);
    tab23->push_back(number);
    tab24->push_back(number);
    tab25->push_back(number);
    end=clock();
    time=double(end-start)/CLOCKS_PER_SEC;
    cout<<"Czas dodania na koniec: "<<time<<" ms"<<endl;
     //dodawanie losowo
     //usuwanie na poczatku
     //usuwanie na koncu
     //usuwanie losowo
     //wyszukiwanie losowe


    delete tab1;
    delete tab2;
    delete tab3;
    delete tab4;
    delete tab5;
    delete tab6;
    delete tab7;
    delete tab8;
    delete tab9;
    delete tab10;
    delete tab11;
    delete tab12;
    delete tab13;
    delete tab14;
    delete tab15;
    delete tab16;
    delete tab17;
    delete tab18;
    delete tab19;
    delete tab20;
    delete tab21;
    delete tab22;
    delete tab23;
    delete tab24;
    delete tab25;
    return(0);
}
