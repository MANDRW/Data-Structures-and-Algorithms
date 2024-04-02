#include <iostream>
#include "ArrayList.h"
#include "SingleListHead.h"
#include "SingleListHT.h"
#include "DoubleList.h"
#include "UI.h"
#include<fstream>
#include<ctime>
#include<cstdio>
#include <cstdlib>


using namespace std;

int main()
{
    srand(time(NULL));
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
    int size_file=5000;
    fstream file;
    ArrayList**tab=new ArrayList * [100];
    for(int i=0;100>i;i++) tab[i]=new ArrayList;


    file.open("test_data_small.txt",ios::in);
    for (int i = 0; size_file > i and file.eof() != 1; i++) {
        int temp;
        file >> temp;
        for(int i=0;100>i;i++) tab[i]->push_back(temp);

    }
    cout<<"ArrayList: ";
     cout<<"Wczytano "<<size_file<<" danych z przedzialu <-10,10>, 1 plik"<<endl;
    cout<<"Badanie na 100 strukturach"<<endl;
     int number=(rand()%21)-10;
     cout<<"Liczba dodana/usunieta: "<<number<<endl;
     //dodawanie na poczatku
     clock_t start=clock();
    for(int i=0;100>i;i++) tab[i]->push_front(number);
     clock_t end=clock();
     double time=double(end-start)/CLOCKS_PER_SEC;
     cout<<"Czas dodania na poczatek: "<<time<<" ms"<<endl;
    //usuwanie na poczatku
    start=clock();
    for(int i=0;100>i;i++) tab[i]->del_front();
    end=clock();
    time=double(end-start)/CLOCKS_PER_SEC;
    cout<<"Czas usuniecia na poczatku: "<<time<<" ms"<<endl;
    //dodawanie na koncu
    start=clock();
    for(int i=0;100>i;i++) tab[i]->push_back(number);
    end=clock();
    time=double(end-start)/CLOCKS_PER_SEC;
    cout<<"Czas dodania na koniec: "<<time<<" ms"<<endl;
    //usuwanie na koncu
    start=clock();
    for(int i=0;100>i;i++) tab[i]->del_back();
    end=clock();
    time=double(end-start)/CLOCKS_PER_SEC;
    cout<<"Czas usuniecia na koncu: "<<time<<" ms"<<endl;
    //dodawanie losowo
    int random_push=rand()%size_file;
    start=clock();
    for(int i=0;100>i;i++) tab[i]->append(random_push,number);
    end=clock();
    time=double(end-start)/CLOCKS_PER_SEC;
    cout<<"Index: "<<random_push<<endl;
    cout<<"Czas dodania losowo: "<<time<<" ms"<<endl;
     //usuwanie losowo
    int random_del=rand()%size_file;
    start=clock();
    for(int i=0;100>i;i++) tab[i]->del(random_del);
    end=clock();
    time=double(end-start)/CLOCKS_PER_SEC;
    cout<<"Index: "<<random_del<<endl;
    cout<<"Czas usuwania losowo: "<<time<<" ms"<<endl;
     //wyszukiwanie losowe
    int random=(rand()%21)-10;
    start=clock();
    for(int i=0;100>i;i++) tab[i]->search(random);
    end=clock();
    time=double(end-start)/CLOCKS_PER_SEC;
    cout<<"Szukana liczba: "<<random<<endl;
    cout<<"Czas szukania losowo: "<<time<<" ms"<<endl;

    for(int i=0;100>i;i++) delete tab[i];
    delete[] tab;

    return(0);
}
