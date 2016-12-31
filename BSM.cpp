// BSM.cpp

#include "BSM.h"
#include <math.h>

using namespace std;

BSM::BSM(float asset,
         float strike,
         float growth,
         float vol,
         float year,
         long steps,
         long sims)
{

  bsmAsset = asset;
  bsmStrike = strike;
  bsmGrowth = growth;
  bsmVol = vol;
  bsmYears = year;
  bsmSteps = steps;
  bsmMonteCarloSims = sims;

}

BSM::~BSM(){}

void BSM::logNormalRandomWalk() {
  srand( (unsigned) time(0));

  double callPayoffPot = 0.0;
  double putPayoffPot = 0.0;

  double timeStep = getBsmYears() / getBsmSteps();
  double sqrtTS = sqrt(timeStep);

  for (long i = 1; i <= getBsmMonteCarloSims(); i++) {

    double assetPrice = getBsmAsset();

    for (int j = 1; j <= getBsmSteps(); j++) {
      assetPrice *= (1 + getBsmGrowth() * timeStep +
                     getBsmVol() * sqrtTS * (
                      rn() + rn() + rn() +
                      rn() + rn() + rn() +
                      rn() + rn() + rn() +
                      rn() + rn() + rn() - 6));
    }

    if (assetPrice > getBsmStrike()) {
      callPayoffPot += (assetPrice - getBsmStrike());
    }

    else if(assetPrice < getBsmStrike()) {
      putPayoffPot += (getBsmStrike() - assetPrice);
    }
  }

  bsmCallPrice = callPayoffPot / getBsmMonteCarloSims();
  bsmPutPrice = putPayoffPot / getBsmMonteCarloSims();

  return;
}

double BSM::rn() {
  return (double) rand() / (double) (RAND_MAX + 1.0);
}

float BSM::getBsmAsset() {
  return bsmAsset;
}

float BSM::getBsmStrike() {
  return bsmStrike;
}

float BSM::getBsmGrowth() {
  return bsmGrowth;
}

float BSM::getBsmVol() {
  return bsmVol;
}

float BSM::getBsmYears() {
  return bsmYears;
}

long BSM::getBsmSteps() {
  return bsmSteps;
}

long BSM::getBsmMonteCarloSims() {
  return bsmMonteCarloSims;
}

double BSM::getCallPrice() {
  return bsmCallPrice;
}

double BSM::getPutPrice() {
  return bsmPutPrice;
}