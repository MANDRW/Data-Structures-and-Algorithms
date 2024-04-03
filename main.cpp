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
    int number=-5;//(rand()%21)-10;
    int random_push=4783;//rand()%size_file;
    int random_del=1389;//rand()%size_file;
    int random=0;//(rand()%21)-10;
    fstream file;

    ArrayList**tab=new ArrayList*[5];
    for(int i=0;i<5;i++) tab[i]=new ArrayList;

    file.open("test_data_small.txt",ios::in);
    for (int i = 0; size_file > i and file.eof() != 1; i++) {
        int temp;
        file >> temp;
        for(int i=0;5>i;i++) tab[i]->push_back(temp);

    }
    cout<<"ArrayList: ";
     cout<<"Wczytano "<<size_file<<" danych z przedzialu <-10,10>"<<endl;
     cout<<"Liczba dodana/usunieta: "<<number<<endl;

     //dodawanie na poczatku
    auto begin = std::chrono::high_resolution_clock::now();
    for(int i=0;5>i;i++) tab[i]->push_front(number);
    auto end = std::chrono::high_resolution_clock::now();
    auto time = std::chrono::duration_cast<std::chrono::nanoseconds >(end - begin);
     cout<<"Czas dodania na poczatek: "<<time.count()/5<<" ns"<<endl;

    //usuwanie na poczatku
    begin = std::chrono::high_resolution_clock::now();
    for(int i=0;5>i;i++) tab[i]->del_front();
    end = std::chrono::high_resolution_clock::now();
    time = std::chrono::duration_cast<std::chrono::nanoseconds >(end - begin);
    cout<<"Czas usuniecia na poczatku: "<<time.count()/5<<" ns"<<endl;

    //dodawanie na koncu
    begin = std::chrono::high_resolution_clock::now();
    for(int i=0;5>i;i++) tab[i]->push_back(number);
    end = std::chrono::high_resolution_clock::now();
    time = std::chrono::duration_cast<std::chrono::nanoseconds >(end - begin);
    cout<<"Czas dodania na koniec: "<<time.count()/5<<" ns"<<endl;

    //usuwanie na koncu*/
    begin = std::chrono::high_resolution_clock::now();
    for(int i=0;5>i;i++) tab[i]->del_back();
    end = std::chrono::high_resolution_clock::now();
    time = std::chrono::duration_cast<std::chrono::nanoseconds >(end - begin);
    cout<<"Czas usuniecia na koncu: "<<time.count()/5<<" ns"<<endl;

    //dodawanie losow
    begin = std::chrono::high_resolution_clock::now();
    for(int i=0;5>i;i++) tab[i]->append(random_push,number);
    end = std::chrono::high_resolution_clock::now();
    time = std::chrono::duration_cast<std::chrono::nanoseconds >(end - begin);
    cout<<"Index: "<<random_push<<endl;
    cout<<"Czas dodania losowo: "<<time.count()/5<<" ns"<<endl;
     //usuwanie losowo
    begin = std::chrono::high_resolution_clock::now();
    for(int i=0;5>i;i++) tab[i]->del(random_del);
    end = std::chrono::high_resolution_clock::now();
    time = std::chrono::duration_cast<std::chrono::nanoseconds >(end - begin);
    cout<<"Index: "<<random_del<<endl;
    cout<<"Czas usuwania losowo: "<<time.count()/5<<" ns"<<endl;

     //wyszukiwanie losowe
    begin = std::chrono::high_resolution_clock::now();
    for(int i=0;5>i;i++) tab[i]->search(random);
    end = std::chrono::high_resolution_clock::now();
    time = std::chrono::duration_cast<std::chrono::nanoseconds >(end - begin);
    cout<<"Szukana liczba: "<<random<<endl;
    cout<<"Czas szukania losowo: "<<time.count()/5<<" ns"<<endl;

    for(int i=0;5>i;i++) delete tab[i];
    delete[] tab;

    return(0);
}
