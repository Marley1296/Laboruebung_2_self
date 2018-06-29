//
// Created by Marley on 13.05.2018.
//

#include <iostream>
#include "Taxi.h"

/*Ich habe direkt einen Konstruktor benutzt, weil ich die Aufgabe nicht komplett gelesen habe
und dachte anstatt eine initalisieren Funktion zu benutzen ist es besser einen Konstruktor zu benutzen.
Falls ich trotzdem eine initalisieren Funktion schreiben soll hole ich das gerne nach.*/
Taxi::Taxi(double maximalerTankinhalt, double verbrauch, double fahrpreis):
        mMaximalerTankinhalt(maximalerTankinhalt),mVerbrauchProKilometer(verbrauch/100), mFahrpreisProKilometer(fahrpreis) {
    mTageskilometerstand = 0;
    mAktuellerTankinhalt = maximalerTankinhalt;
    mGeldbilanz = 0;
}

void Taxi::print() const {
    std::cout
            << "\nTageskilometerstand: " << mTageskilometerstand
            << "\nAktueller Tankinhalt: " << mAktuellerTankinhalt
            << "\nGeldbilanz: " << mGeldbilanz
            << std::endl;
}

void Taxi::fahrtVerbuchen(double entfernung, bool passagiere) {
    if (mAktuellerTankinhalt - entfernung * mVerbrauchProKilometer < 0) {
        std::cerr << "So nicht mein Freund, so nicht! Der Tank wird nicht ausreichen." << std::endl;
        return;
    }
    mTageskilometerstand += entfernung;
    mAktuellerTankinhalt -= entfernung * mVerbrauchProKilometer;
    if (passagiere) {
        mGeldbilanz += mFahrpreisProKilometer * entfernung;
    }
}

void Taxi::tanken(double preis) {
    if (mGeldbilanz <= preis*(mMaximalerTankinhalt-mAktuellerTankinhalt)){ //Tanken, bis Geld alle
        mAktuellerTankinhalt += mGeldbilanz/preis;
        mGeldbilanz = 0;

    }
    if(mGeldbilanz >= preis*(mMaximalerTankinhalt-mAktuellerTankinhalt) ){ //Volltanken, wenn Geld ausreicht
        mGeldbilanz -= preis*(mMaximalerTankinhalt-mAktuellerTankinhalt);
        mAktuellerTankinhalt=mMaximalerTankinhalt;

    }


}


