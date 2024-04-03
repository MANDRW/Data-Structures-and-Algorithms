#include <iostream>
#include "ArrayList.h"
#include "SingleListHead.h"
#include "SingleListHT.h"
#include "DoubleList.h"
#include "UI.h"
#include<fstream>
#include<ctime>
#include <cstdlib>
#include <stdio.h>
#include <chrono>


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
    int q=50;
    int random_push[q];
    int random_del[q];
    int random[q];
    for(int i=0;i<q;i++){
        random_push[i]=rand()%size_file;
        random_del[i]=rand()%size_file;
        random[i]=(rand()%21)-10;

    }
    int number=(rand()%21)-10;
    fstream file;
    ArrayList**tab=new ArrayList*[q];
    for(int i=0;i<q;i++) tab[i]=new ArrayList;

    file.open("test_data_small.txt",ios::in);
    for (int i = 0; size_file > i and file.eof() != 1; i++) {
        int temp;
        file >> temp;
        for(int i=0;q>i;i++) tab[i]->push_back(temp);

    }
    cout<<"ArrayList: ";
     cout<<"Wczytano "<<size_file<<" danych z przedzialu <-10,10>"<<endl;
     cout<<"Liczba dodana/usunieta: "<<number<<endl;

     //dodawanie na poczatku
    auto begin = std::chrono::high_resolution_clock::now();
    for(int i=0;q>i;i++) tab[i]->push_front(number);
    auto end = std::chrono::high_resolution_clock::now();
    auto time = std::chrono::duration_cast<std::chrono::nanoseconds >(end - begin);
     cout<<"Czas dodania na poczatek: "<<time.count()/q<<" ns"<<endl;

    //usuwanie na poczatku
    begin = std::chrono::high_resolution_clock::now();
    for(int i=0;q>i;i++) tab[i]->del_front();
    end = std::chrono::high_resolution_clock::now();
    time = std::chrono::duration_cast<std::chrono::nanoseconds >(end - begin);
    cout<<"Czas usuniecia na poczatku: "<<time.count()/q<<" ns"<<endl;

    //dodawanie na koncu
    begin = std::chrono::high_resolution_clock::now();
    for(int i=0;q>i;i++) tab[i]->push_back(number);
    end = std::chrono::high_resolution_clock::now();
    time = std::chrono::duration_cast<std::chrono::nanoseconds >(end - begin);
    cout<<"Czas dodania na koniec: "<<time.count()/q<<" ns"<<endl;

    //usuwanie na koncu*/
    begin = std::chrono::high_resolution_clock::now();
    for(int i=0;q>i;i++) tab[i]->del_back();
    end = std::chrono::high_resolution_clock::now();
    time = std::chrono::duration_cast<std::chrono::nanoseconds >(end - begin);
    cout<<"Czas usuniecia na koncu: "<<time.count()/q<<" ns"<<endl;

    //dodawanie losow
    begin = std::chrono::high_resolution_clock::now();
    for(int i=0;q>i;i++) tab[i]->append(random_push[i],number);
    end = std::chrono::high_resolution_clock::now();
    time = std::chrono::duration_cast<std::chrono::nanoseconds >(end - begin);
    cout<<"Czas dodania losowo: "<<time.count()/q<<" ns"<<endl;
     //usuwanie losowo
    begin = std::chrono::high_resolution_clock::now();
    for(int i=0;q>i;i++) tab[i]->del(random_del[i]);
    end = std::chrono::high_resolution_clock::now();
    time = std::chrono::duration_cast<std::chrono::nanoseconds >(end - begin);
    cout<<"Czas usuwania losowo: "<<time.count()/q<<" ns"<<endl;

     //wyszukiwanie losowe
    begin = std::chrono::high_resolution_clock::now();
    for(int i=0;q>i;i++) tab[i]->search(random[i]);
    end = std::chrono::high_resolution_clock::now();
    time = std::chrono::duration_cast<std::chrono::nanoseconds >(end - begin);
    cout<<"Czas szukania losowo: "<<time.count()/q<<" ns"<<endl;

    for(int i=0;q>i;i++) delete tab[i];
    delete[] tab;

    return(0);
}
