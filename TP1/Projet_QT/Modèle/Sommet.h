#include <map>
#include <limits.h>

class Sommet {
public:
    Sommet();
    Sommet(int gain, const std::map<Sommet*, int>& distances);
    virtual ~Sommet();

    int distanceA(const Sommet* s) const;
    inline int getGain() const { return _gain; }
    virtual void visiter() = 0;
    virtual void diminuerDistanceAvantActif(int distance) = 0;

private:
    virtual bool _estActif() const = 0;
    virtual int _obtenirDistanceAvantActif() const = 0;

private:
    int _gain;
    std::map<Sommet*, int> _distances;
};
