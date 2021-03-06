#pragma once

#include <iostream>
#include <string>
#include <utility>

class Monitor {
private:
    int Nr_Pixeli_Inaltime;
    int Nr_Pixeli_Latime;
    std::string Rezolutie;

public:
    // Constructor
    Monitor(int Nr_Pixeli_Inaltime = 0, int Nr_Pixeli_Latime = 0, std::string  Rezolutie = " ")
            : Nr_Pixeli_Inaltime{Nr_Pixeli_Inaltime}, Nr_Pixeli_Latime{Nr_Pixeli_Latime}, Rezolutie{std::move(Rezolutie)} {
        std::cout << "Creare Monitor\n";
    }
    // Copy constructor
    Monitor(const Monitor &x) {
        Nr_Pixeli_Inaltime = x.Nr_Pixeli_Inaltime ;
        Nr_Pixeli_Latime = x.Nr_Pixeli_Latime;
        Rezolutie = x.Rezolutie;}


    // Destructor
    ~Monitor() {
        std::cout << "Monitor Goes Brrr( dieded :o )\n";
    }

    // Op Overload
    // Operator =
    Monitor &operator=(const Monitor &obj) {
        Nr_Pixeli_Inaltime = obj.Nr_Pixeli_Inaltime;
        Nr_Pixeli_Latime = obj.Nr_Pixeli_Latime;
        Rezolutie = obj.Rezolutie;
        return *this;
    }
    // Operator <<
    friend std::ostream &operator<<(std::ostream &os, const Monitor &obj) {
        os << "Rezolutia specificata este : " << obj.Rezolutie << "\n";
        return os;
    }

    // Functii
    void setMonitor(int nrPixeliInaltime, int nrPixeliLatime, const std::string &rezolutie) {
        this->Nr_Pixeli_Inaltime = nrPixeliInaltime;
        this->Nr_Pixeli_Latime = nrPixeliLatime;
        this->Rezolutie = rezolutie;
    }

    void Creare_Monitor() {

        std::cout << " Care este rezolutia monitorului dumneavoastra?" << std::endl;
        std::cout << " 1280 x 720  - 1" << std::endl;
        std::cout << " 1920 x 1080 - 2" << std::endl;
        std::cout << " 2560 x 1440 - 3" << std::endl;
        std::cout << " 3840 x 2160 - 4" << std::endl;
        std::cout << " 7680 x 4320 - 5" << std::endl;
        std::cout << " Introduceti numarul corespunzator rezolutiei dumneavoastra :\n";

        std::string rez_mon;
        getline(std::cin, rez_mon);
        rez_mon.erase(remove(rez_mon.begin(), rez_mon.end(), ' '), rez_mon.end());
        while (rez_mon.size() > 1 || (rez_mon[0] < '1' || rez_mon[0] > '5')) {
            std::cout << "Alegere incorecta ! Introduceti un raspuns valabil." << "\n";
            getline(std::cin, rez_mon);
            rez_mon.erase(remove(rez_mon.begin(), rez_mon.end(), ' '), rez_mon.end());
        }
        char a = rez_mon[0];
        switch (a) {
            case '1':
                this->setMonitor(720, 1280, "720p");
                break;
            case '2':
                this->setMonitor(1080, 1920, "1080p");
                break;
            case '3':
                this->setMonitor(1440, 2560, "1440p");
                break;
            case '4':
                this->setMonitor(2160, 3840, "2160p/4K");
                break;
            case '5':
                this->setMonitor(4320, 7680, "4320p/8K");
                break;
            default:
                break;
        }
    }

};
class Monitor_factory {
public:
    static Monitor HP() { return Monitor(1920, 1080 ,"1080p"); }
    static Monitor Acer() { return Monitor(1440, 2560, "1440p"); }
    static Monitor LG() { return Monitor(720, 1280, "720p"); }
    static Monitor Philips() { return Monitor(2160, 3840, "2160p/4K"); }
    static Monitor Asus() { return Monitor(4320, 7680, "4320p/8K"); }
};