#include <iostream>
#include <iomanip>
#include "kibic.h"
#include "miasto.h"
#include "interface.h"

int main()
{
    int citizensNum = 0, evolutionNum = 0, procent = 0; 
    std::string cityName = "";
    Interface simulator;
    
    simulator.ustalWartParametrow(&cityName, &citizensNum, &procent, &evolutionNum);

    if(true){
      City M(citizensNum,procent,cityName);
      M.calcTotCitizensHapp();
      M.calcCityHapp();
      int happ = M.getCityHapp();
      printf("Happiness level: %d\n", happ);

      if(evolutionNum != 0){
        for(int i = 0; i < evolutionNum; i++){
          printf("Evolution #%d:\n", i+1);
          M.evolve();
          M.resetCitizenHapp();
          M.calcTotCitizensHapp();
          M.calcCityHapp();
          happ = M.getCityHapp();
          printf("Happiness level: %d\n", happ);
        }
      }
    }
  else{
      printf("Unrecognized decision!\n");
      std::exit(0);
    }

    return 0;
}
