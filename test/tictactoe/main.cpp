#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "TicTacToeAgent.h"
#include "TicTacToeAgentFactory.h"
#include "TicTacToeFitnessCalculator.h"

#include "../../src/AgentFactory.h"
#include "../../src/Engine.h"
#include "../../src/NetworkConfiguration.h"
#include "../../src/RandomUtil.h"

int main(int argc, char ** argv) {
  srand (static_cast <unsigned> (time(0)));

  if (argc < 2 || atoi(argv[1]) < 4) {
    cerr << "Usage: ./ttt <population_size> (population_size >= 4)" << endl;
    exit(1);
  }

  NetworkConfiguration * config = new NetworkConfiguration(9,1,20,9);
  AgentFactory * factory = new TicTacToeAgentFactory();

  Engine * engine = new Engine(atoi(argv[1]), config, new TicTacToeFitnessCalculator(), factory);

  while(true) {
    engine->update();
  }
}
