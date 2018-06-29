#ifndef LABORUEBUNG_2_SELF_TAXI_H
#define LABORUEBUNG_2_SELF_TAXI_H


class Taxi {
    double mTageskilometerstand;
    double mAktuellerTankinhalt;
    double mGeldbilanz;
    double const mMaximalerTankinhalt;
    double const mVerbrauchProKilometer;
    double const mFahrpreisProKilometer;


public:
    Taxi(double maximalerTankinhalt, double verbrauch, double fahrpreis);

    void print() const;
    void fahrtVerbuchen(double entfernung, bool passagiere);
    void tanken(double preis);
};


#endif //LABORUEBUNG_2_SELF_TAXI_H
