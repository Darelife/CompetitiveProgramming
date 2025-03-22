#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

struct Resource {
  int RI, RA, RP, RW, RM, RL, RU, RE;
  string RT;
};

struct Turn {
  int TM, TX, TR;
};

struct ActiveResource {
  Resource base;
  int remainingLife;
  int activeTimeLeft;
  int maintenanceTimeLeft;
  bool isActive;
  int accumulatedBuildings; // For E-type resources

  ActiveResource(const Resource& r) :
    base(r),
    remainingLife(r.RL),
    activeTimeLeft(r.RW),
    maintenanceTimeLeft(0),
    isActive(true),
    accumulatedBuildings(0) {
  }
};

void parseInput(const string& inputFile, int& D, int& R, int& T, vector<Resource>& resources, vector<Turn>& turns) {
  ifstream file(inputFile);
  if (!file) {
    cerr << "Error opening file: " << inputFile << endl;
    exit(1);
  }

  file >> D >> R >> T;

  resources.resize(R);
  for (int i = 0; i < R; i++) {
    file >> resources[i].RI >> resources[i].RA >> resources[i].RP >> resources[i].RW
      >> resources[i].RM >> resources[i].RL >> resources[i].RU >> resources[i].RT;

    if (resources[i].RT != "X") {
      file >> resources[i].RE;
    } else {
      resources[i].RE = 0;
    }
  }

  turns.resize(T);
  for (int i = 0; i < T; i++) {
    file >> turns[i].TM >> turns[i].TX >> turns[i].TR;
  }
}

// Function to calculate the effect of a special resource
void applySpecialEffects(vector<ActiveResource>& activeResources, Turn& currentTurn) {
  // Store original values before applying effects
  int originalTM = currentTurn.TM;
  int originalTX = currentTurn.TX;
  int originalTR = currentTurn.TR;

  // Apply effects from active resources
  for (auto& resource : activeResources) {
    if (!resource.isActive) continue;

    if (resource.base.RT == "A") { // Smart Meter
      for (auto& r : activeResources) {
        if (r.isActive) {
          float effect = resource.base.RE / 100.0;
          if (effect > 0) { // Green Resource
            r.base.RU = floor(r.base.RU * (1 + effect));
          } else { // Non-Green Resource
            r.base.RU = max(0, static_cast<int>(floor(r.base.RU * (1 + effect))));
          }
        }
      }
    } else if (resource.base.RT == "B") { // Distribution Facility
      float effect = resource.base.RE / 100.0;
      if (effect > 0) { // Green Resource
        currentTurn.TM = floor(originalTM * (1 + effect));
        currentTurn.TX = floor(originalTX * (1 + effect));
      } else { // Non-Green Resource
        currentTurn.TM = max(0, static_cast<int>(floor(originalTM * (1 + effect))));
        currentTurn.TX = max(0, static_cast<int>(floor(originalTX * (1 + effect))));
      }
    } else if (resource.base.RT == "D") { // Renewable Plant
      float effect = resource.base.RE / 100.0;
      if (effect > 0) { // Green Resource
        currentTurn.TR = floor(originalTR * (1 + effect));
      } else { // Non-Green Resource
        currentTurn.TR = max(0, static_cast<int>(floor(originalTR * (1 + effect))));
      }
    }
    // C-type (Maintenance Plan) will be handled at purchase time
  }
}

// Find a resource by ID
Resource* findResourceById(vector<Resource>& resources, int id) {
  for (auto& res : resources) {
    if (res.RI == id) {
      return &res;
    }
  }
  return nullptr;
}

// Get total buildings powered by active resources
int getTotalPoweredBuildings(const vector<ActiveResource>& activeResources) {
  int totalBuildings = 0;
  for (const auto& resource : activeResources) {
    if (resource.isActive && resource.base.RT != "E") {
      totalBuildings += resource.base.RU;
    }
  }
  return totalBuildings;
}

// Handle accumulator logic (E-type resources)
int useAccumulators(vector<ActiveResource>& activeResources, int shortage) {
  if (shortage <= 0) return 0;

  int totalUsed = 0;
  for (auto& resource : activeResources) {
    if (resource.isActive && resource.base.RT == "E" && resource.accumulatedBuildings > 0) {
      int used = min(shortage - totalUsed, resource.accumulatedBuildings);
      resource.accumulatedBuildings -= used;
      totalUsed += used;

      if (totalUsed >= shortage) break;
    }
  }
  return totalUsed;
}

// Store excess buildings in accumulators
void storeInAccumulators(vector<ActiveResource>& activeResources, int excess) {
  if (excess <= 0) return;

  for (auto& resource : activeResources) {
    if (resource.isActive && resource.base.RT == "E") {
      resource.accumulatedBuildings += excess;
      break; // Store all excess in the first active accumulator
    }
  }
}

// Transfer accumulated buildings from dying accumulators to active ones
void transferAccumulatedBuildings(vector<ActiveResource>& activeResources) {
  // First, identify accumulators about to die
  vector<int> dyingAccumulators;
  for (size_t i = 0; i < activeResources.size(); i++) {
    if (activeResources[i].base.RT == "E" && activeResources[i].remainingLife == 1) {
      dyingAccumulators.push_back(i);
    }
  }

  // Transfer accumulated buildings to active accumulators
  for (int index : dyingAccumulators) {
    int toTransfer = activeResources[index].accumulatedBuildings;
    if (toTransfer > 0) {
      for (auto& resource : activeResources) {
        if (resource.isActive && resource.base.RT == "E" && resource.remainingLife > 1) {
          resource.accumulatedBuildings += toTransfer;
          activeResources[index].accumulatedBuildings = 0;
          break;
        }
      }
    }
  }
}

// Update resource lifecycles at the end of a turn
void updateResourceLifecycles(vector<ActiveResource>& activeResources) {
  // First, transfer any accumulated buildings from dying accumulators
  transferAccumulatedBuildings(activeResources);

  // Update each resource's lifecycle
  for (auto it = activeResources.begin(); it != activeResources.end(); ) {
    if (it->remainingLife <= 1) {
      // Resource has reached the end of its life
      it = activeResources.erase(it);
    } else {
      it->remainingLife--;

      if (it->isActive) {
        it->activeTimeLeft--;
        if (it->activeTimeLeft <= 0) {
          // Resource enters maintenance period
          it->isActive = false;
          it->maintenanceTimeLeft = it->base.RM;
        }
      } else {
        it->maintenanceTimeLeft--;
        if (it->maintenanceTimeLeft <= 0) {
          // Resource returns to active state
          it->isActive = true;
          it->activeTimeLeft = it->base.RW;
        }
      }

      ++it;
    }
  }
}

// Apply C-type resource effects to newly purchased resources
void applyCTypeEffects(const vector<ActiveResource>& activeResources, Resource& newResource) {
  for (const auto& resource : activeResources) {
    if (resource.isActive && resource.base.RT == "C") {
      float effect = resource.base.RE / 100.0;
      if (effect > 0) { // Green Resource
        newResource.RL = floor(newResource.RL * (1 + effect));
      } else { // Non-Green Resource
        newResource.RL = max(1, static_cast<int>(floor(newResource.RL * (1 + effect))));
      }
    }
  }
}

// Calculate resource efficiencies for better purchasing decisions
vector<pair<double, int>> calculateResourceEfficiency(const vector<Resource>& resources) {
  vector<pair<double, int>> resourceEfficiency;

  for (const auto& res : resources) {
    // Skip resources that don't power any buildings (unless they're accumulators)
    if (res.RT != "E" && res.RU <= 0) continue;

    int totalPotentialOutput = res.RU * res.RW;
    int totalLifetimeCost = max(1, res.RA + (res.RP * res.RL)); // Avoid division by zero
    double efficiency = static_cast<double>(totalPotentialOutput) / totalLifetimeCost;

    // Adjust for special effects and resource type
    if (res.RT == "D" && res.RE > 0) efficiency *= (1.0 + res.RE / 100.0); // Boost renewable plants
    if (res.RT == "E") efficiency *= 1.5; // Prioritize accumulators even more
    if (res.RT == "B" || res.RT == "A") efficiency *= 1.3; // Boost special effects

    resourceEfficiency.push_back({ efficiency, res.RI });
  }

  // Sort by efficiency (descending)
  sort(resourceEfficiency.begin(), resourceEfficiency.end(), greater<pair<double, int>>());

  return resourceEfficiency;
}

int simulateGame(int D, int R, int T, vector<Resource>& resources, vector<Turn>& turns, vector<string>& output) {
  vector<ActiveResource> activeResources;
  int budget = D;
  int totalProfit = 0;

  // Precalculate resource efficiencies
  vector<pair<double, int>> resourceEfficiency = calculateResourceEfficiency(resources);

  // Strategy: Buy the most efficient resources first based on a heuristic
  for (int turnIdx = 0; turnIdx < T; turnIdx++) {
    Turn currentTurn = turns[turnIdx];
    vector<int> purchasedResources;

    // Calculate current power capacity before purchases
    int currentCapacity = getTotalPoweredBuildings(activeResources);

    // Only attempt to purchase resources if we don't meet the minimum requirement
    // or if we can improve our profit by purchasing more resources
    if (currentCapacity < currentTurn.TX) { // Try to reach maximum capacity for better profit
      int resourcesPurchasedCount = 0;
      const int MAX_PURCHASES_PER_TURN = 50;

      // Buy resources based on efficiency and budget constraints
      for (const auto& [eff, resId] : resourceEfficiency) {
        if (resourcesPurchasedCount >= MAX_PURCHASES_PER_TURN) break;

        Resource* res = findResourceById(resources, resId);
        if (!res) continue;

        // Only consider resources that can help power buildings
        if (res->RT != "E" && res->RU <= 0) continue;

        // Try to buy this resource multiple times if needed
        int purchaseCount = 0;
        while (budget >= res->RA && purchaseCount < 50 && resourcesPurchasedCount < MAX_PURCHASES_PER_TURN) {
          // Make a copy of the resource for potentially applying C-type effects
          Resource newResource = *res;

          // Apply C-type effects to this new resource (if any are active)
          applyCTypeEffects(activeResources, newResource);

          // For regular resources, check if they help meet/increase our capacity
          if (newResource.RT != "E") {
            if (currentCapacity < currentTurn.TX) { // Still need more capacity
              purchasedResources.push_back(resId);
              budget -= newResource.RA;

              // Activate the resource
              activeResources.push_back(ActiveResource(newResource));

              // Update the current capacity
              currentCapacity += newResource.RU;

              purchaseCount++;
              resourcesPurchasedCount++;
            } else {
              break; // We've reached or exceeded maximum capacity
            }
          }
          // For accumulators, always consider them valuable (up to a reasonable number)
          else if (newResource.RT == "E" && purchaseCount < 5) { // Limit accumulator purchases
            purchasedResources.push_back(resId);
            budget -= newResource.RA;

            // Activate the resource
            activeResources.push_back(ActiveResource(newResource));

            purchaseCount++;
            resourcesPurchasedCount++;
          } else {
            break; // Enough of this resource
          }
        }

        if (currentCapacity >= currentTurn.TX) break;
      }
    }

    // Apply special effects to modify this turn's parameters
    applySpecialEffects(activeResources, currentTurn);

    // Calculate maintenance costs
    int maintenanceCost = 0;
    for (const auto& resource : activeResources) {
      maintenanceCost += resource.base.RP;
    }

    // Calculate buildings powered
    int poweredBuildings = getTotalPoweredBuildings(activeResources);

    // Handle accumulators if we don't meet minimum requirements
    if (poweredBuildings < currentTurn.TM) {
      int shortage = currentTurn.TM - poweredBuildings;
      int fromAccumulators = useAccumulators(activeResources, shortage);
      poweredBuildings += fromAccumulators;
    } else if (poweredBuildings > currentTurn.TX) {
      // Store excess in accumulators for future turns
      int excess = poweredBuildings - currentTurn.TX;
      storeInAccumulators(activeResources, excess);
      poweredBuildings = currentTurn.TX;
    }

    // Calculate profit
    int profit = 0;
    if (poweredBuildings >= currentTurn.TM) {
      profit = min(poweredBuildings, currentTurn.TX) * currentTurn.TR;
      totalProfit += profit;
    }

    // Update budget
    budget = budget + profit - maintenanceCost;

    // Debug output
    // cout << "Turn " << turnIdx << ": Powered=" << poweredBuildings << ", Profit=" << profit
    //   << ", Budget=" << budget << ", Resources=" << activeResources.size() << endl;

    // Always output a line for each turn
    ostringstream oss;
    oss << turnIdx << " " << purchasedResources.size();
    for (int id : purchasedResources) {
      oss << " " << id;
    }
    output.push_back(oss.str());

    // Update resource lifecycles
    updateResourceLifecycles(activeResources);
  }

  return totalProfit;
}

void mainProcess(const string& inputFile, const string& outputFile) {
  int D, R, T;
  vector<Resource> resources;
  vector<Turn> turns;

  parseInput(inputFile, D, R, T, resources, turns);

  vector<string> output;
  int totalProfit = simulateGame(D, R, T, resources, turns, output);

  ofstream outFile(outputFile);
  for (const auto& line : output) {
    outFile << line << endl;
  }

  cout << "Total Profit for " << inputFile << ": " << totalProfit << endl;
}

int main(int argc, char* argv[]) {
  if (argc > 1) {
    string inputFile = argv[1];
    string outputFile = inputFile + ".out";
    mainProcess(inputFile, outputFile);
  } else {
    // Default processing for provided test files
    vector<string> testFiles = {
        "0-demo.txt",
        "1-thunberg.txt",
        "2-attenborough.txt",
        "4-maathai.txt",
        "6-earle.txt",
        "8-shiva.txt",
        "7-mckibben.txt",
        "5-carson.txt",
        "3-goodall.txt",
    };

    for (const auto& file : testFiles) {
      mainProcess(file, file + ".out.txt");
    }
  }

  return 0;
}