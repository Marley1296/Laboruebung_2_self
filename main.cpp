#include <iostream>
#include "Taxi.h"

int main() {

    Taxi taxi = Taxi(0, 0, 0);

    double entfernung = 0;
    double liter;
    double preis;
    int answer;
    std::string passagiereAnswer;

    std::cout << "1: Taxi 1\n" << "2: Taxi 2" << std::endl;
    std::cin >> answer;

    switch (answer) {
        case 1 :
            taxi = Taxi(75, 7.2, 0.7);
            break;
        case 2 :
            taxi = Taxi(90, 12.5, 0.95);
            break;
        default:
            std::cerr << "WARNING! SELF-DESTRUCTION INITIATED!";
    }
    while (true) {
        std::cout << "1: Fahrt verbuchen ohne Fahrgast\n"
                     "2: Fahrt verbuchen mit Fahrgast\n"
                  << "3: Tanken\n"
                  << "4: Ausgabe\n"
                  << "5: Programm beenden" << std::endl;
        std::cin >> answer;

        switch (answer) {
            case 1 :
                std::cout << "Wie lang war die Fahrt (in km)?";
                std::cin >> entfernung;
                taxi.fahrtVerbuchen(entfernung, false);
                break;
            case 2 :
                std::cout << "Wie lang war die Fahrt (in km)?";
                std::cin >> entfernung;
                taxi.fahrtVerbuchen(entfernung, true);
                break;
            case 3 :
                std::cout << "Wieviel hat's gekostet?";
                std::cin >> preis;
                taxi.tanken(preis);
                break;
            case 4 :
                taxi.print();
                break;
            case 5 :
                return 0;
            default:
                std::cerr << "WARNING! SELF-DESTRUCTION INITIATED!";
                system("pause");
                break;

        }
    }
}

