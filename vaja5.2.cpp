// vaja5.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <cstdlib>

using namespace std;

/*
 *
 */
class Student {
public:
    Student(); //osnovni konstruktor
    Student(string vpisna_stevilka1, string priimek1, string ime1, int ocena1); //dodatni konstruktor 
    void setVpisnaStevilka(string nova_vpisna_stevilka);
    void setPriimek(string novi_priimek);
    void setIme(string nova_ime);
    void setOcena(int nova_ocena);
    string getVpisnaStevilka();
    string getPriimek();
    string getIme();
    int getOcena();
    void vnosOsebnihPodatkov();
    void vnosPrijateljice();
    void izpis();
    string boljsi(Student* student1, Student* student2);
    bool izboljsajOceno(int nova_ocena);


private:
    string vpisna_stevilka;
    string priimek;
    string ime;
    int ocena;
    bool veljavnostOcene(int veljavnost_ocena);
};

// Osnovni konstruktor
Student::Student() {
    vpisna_stevilka = "E1149715";
    priimek = "Jakovljevic";
    ime = "Neda";
    ocena = 6;
}

//Dodatni konstruktor
Student::Student(string vpisna_stevilka1, string priimek1, string ime1, int ocena1) {
    vpisna_stevilka = vpisna_stevilka1;
    priimek = priimek1;
    ime = ime1;
    ocena = ocena1;
}

void Student::setVpisnaStevilka(string nova_vpisna_stevilka) {
    vpisna_stevilka = nova_vpisna_stevilka;
}
void Student::setPriimek(string novi_priimek) {
    priimek = novi_priimek;
}
void Student::setIme(string novo_ime) {
    ime = novo_ime;
}
void Student::setOcena(int nova_ocena) {
    ocena = nova_ocena;
}
string Student::getVpisnaStevilka() {
    return vpisna_stevilka;
}
string Student::getPriimek() {
    return priimek;
}
string Student::getIme() {
    return ime;
}
int Student::getOcena() {
    return ocena;
}

void Student::vnosOsebnihPodatkov() {
    Student* student1 = new Student();
}

void Student::vnosPrijateljice() {
    cout << "Vnesite vpisno stevilko: ";
    cin >> this->vpisna_stevilka;
    cout << "Vnesite priimek: ";
    cin >> this->priimek;
    cout << "Vnesite ime: ";
    cin >> this->ime;
    cout << "Vnesite oceno: ";
    cin >> this->ocena;
}

void Student::izpis()
{
    cout << "Vpisna stevilka: " << this->vpisna_stevilka << endl;
    cout << "Priimek: " << this->priimek << endl;
    cout << "Ime: " << this->ime << endl;
    cout << "Ocena: " << this->ocena << endl;
}

string Student::boljsi(Student* student1, Student* student2) {
    if (student1->getOcena() > student2->getOcena())
        return student1->getVpisnaStevilka();
    else if (student1->getOcena() < student2->getOcena())
        return student2->getVpisnaStevilka();
    else
        cout << "Oba studenta imata enako oceno, in sicer: " << student1->getOcena() << endl;
    return student1->getVpisnaStevilka();
}

bool Student::izboljsajOceno(int nova_ocena) {
    cout << "Vnesi novo oceno: ";
    cin >> nova_ocena;
    if (veljavnostOcene(nova_ocena) == false) {
        this->ocena = this->ocena;
    }
    else {
        if (nova_ocena > this->ocena) {
            this->ocena = nova_ocena;
            cout << "Ocena je bila izboljsana." << endl;
            return true;
        }
        else {
            this->ocena = nova_ocena;
            cout << "Ocena ni bila izboljsana." << endl;
            return false;
        }
    }
}

bool Student::veljavnostOcene(int veljavnost_ocena) {
    if (veljavnost_ocena < 1) {
        cout << "Ocena ne more biti manja od 1!" << endl;
        return false;
    }
    if (veljavnost_ocena > 10) {
        cout << "Ocena ne more biti vecja od 10!" << endl;
        return false;
    }
}

int main(int argc, char** argv) {

    bool izhod = false;
    int izbira;
    Student* jaz, * prijateljica, * pomozni;
    jaz = new Student();
    prijateljica = new Student();
    pomozni = new Student();
    while (izhod == false) {
        cout << "---------------------------------------------------------" << endl;
        cout << "Na izbiro imate naslednje moznosti:" << endl;
        cout << "1 - vnos studijskih podatkov o meni" << endl;
        cout << "2 - vnos studijskih podatkov o prijatelju/prijateljici" << endl;
        cout << "3 - izpis studijskih podatkov o meni" << endl;
        cout << "4 - izpis studijskih podatkov o prijatelju/prijateljici" << endl;
        cout << "5 - izpis boljsega studenta" << endl;
        cout << "6 - izboljsaj oceno pri meni" << endl;
        cout << "7 - izboljsaj oceno pri prijatelju/prijateljici" << endl;
        cout << "8 - izhod iz programa" << endl;
        cout << "---------------------------------------------------------" << endl;
        cout << "Vnesite izbiro: ";
        cin >> izbira;
        cout << "---------------------------------------------------------" << endl;
        switch (izbira) {
        case 1:
            int vpisana_ocena;
            jaz->vnosOsebnihPodatkov();
            cout << "Podatki o meni se vneseni." << endl;
            cout << "Vnesite se oceno: ";
            cin >> vpisana_ocena;
            jaz->setOcena(vpisana_ocena);
            break;
        case 2:
            prijateljica->vnosPrijateljice();
            break;
        case 3:
            cout << "Izpis podatkov o meni: " << endl;
            jaz->izpis();
            break;
        case 4:
            cout << "Izpis podatkov o prijatelju/prijateljici: " << endl;
            prijateljica->izpis();
            break;
        case 5:
            pomozni->boljsi(jaz, prijateljica);
            if (jaz->getOcena() > prijateljica->getOcena()) {
                cout << "Student, ki ima boljso oceno: " << endl;
                jaz->izpis();
            }
            else if (jaz->getOcena() < prijateljica->getOcena()) {
                cout << "Student, ki ima boljso oceno: " << endl;
                prijateljica->izpis();
            }
            break;
        case 6:
            jaz->izboljsajOceno(jaz->getOcena());
            break;
        case 7:
            prijateljica->izboljsajOceno(prijateljica->getOcena());
            break;
        case 8:
            cout << "Izhod iz programa!";
            izhod = true;
            break;
        }
    }
    delete jaz;
    delete prijateljica;
    delete pomozni;
    return 0;
}