// implementation of a Black Scholes Monte Carlo Engine

#include <iostream>
#include "BSM.h"

using namespace std;

enum BSMExecution {
  ASSET = 1,
  STRIKE = 2,
  GROWTH = 3,
  VOLATILITY = 4,
  YEARS = 5,
  STEPS = 6,
  SIMULATIONS = 7,
};

int main(int argc, char** argv) {

  BSM bsm(atof(argv[ASSET]),
          atof(argv[STRIKE]),
          atof(argv[GROWTH]),
          atof(argv[VOLATILITY]),
          atof(argv[YEARS]),
          atof(argv[STEPS]),
          atof(argv[SIMULATIONS])
  );

  cout << "Asset: " << bsm.getBsmAsset() << endl <<
  cout << "Strike: " << bsm.getBsmStrike() << endl <<
  cout << "Growth: " << bsm.getBsmGrowth() << endl <<
  cout << "Volaility: " << bsm.getBsmVol() << endl <<
  cout << "Years: " << bsm.getBsmYears() << endl <<
  cout << "Steps: " << bsm.getBsmSteps() << endl <<
  cout << "Sims: " << bsm.getBsmMonteCarloSims() << endl;

  bsm.logNormalRandomWalk();

  cout << endl;

  cout << "Call option price: " << bsm.getCallPrice() << endl;
  cout << "Put option price: " << bsm.getPutPrice() << endl;

  return 0;
}
