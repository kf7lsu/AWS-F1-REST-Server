#include <iostream>
#include <chrono>
#include "BaseRestClient.h"

int main() {
  std::cout << "start" << std::endl;
  int iters = 0;
  int numClients = 1;
  std::chrono::time_point<std::chrono::steady_clock> startTimes[numClients];
  std::chrono::time_point<std::chrono::steady_clock> endTimes[numClients];
  int latencies[numClients];
  int avgLat;
  RestAPIClient::BaseClient* clients[numClients];
  auto start = std::chrono::steady_clock::now();
  for (int i = 0; i < numClients; i++){
    startTimes[i] = std::chrono::steady_clock::now();
    //RestAPIClient::BaseClient client("ILSVRC2012_val_00000003.jpeg");
    //(&client)->getReply();
    clients[i] = new RestAPIClient::BaseClient("ILSVRC2012_val_00000003.jpeg");
    //(clients[i]).getReply();
    //std::cout << clients[i] << std::endl;
  }
  //std::cout << clients[0] << std::endl;
  //(clients[0])->getReply();
  for (int i = 0; i < numClients; i++) {
    (clients[i])->getReply();
    endTimes[i] = std::chrono::steady_clock::now();
  }
  //std::cout << start << std::endl;
  auto end = std::chrono::steady_clock::now();
  //std::cout << "end: " << end << std::endl;
  long sumLat = 0;
  for(int i = 0; i < numClients; i++){
     int currLat = std::chrono::duration_cast<std::chrono::milliseconds>(endTimes[i] - startTimes[i]).count();
     sumLat += currLat;
  }
  avgLat = sumLat / numClients;
  std::cout << "throughput: " << (std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()) / numClients << " ns/img" << std::endl;
  std::cout << "avg latency: " << avgLat << " ms" << std::endl;
  //std::cout << "iters: " << iters << std::endl;
  return 0;
}
