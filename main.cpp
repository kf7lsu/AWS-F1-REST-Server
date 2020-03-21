#include <iostream>

#include "BaseRestClient.h"

int main() {
  RestAPIClient::BaseClient client("ILSVRC2012_val_00000003.jpeg");
  client.sendRequest();
  std::cout << client.getReply() << std::endl;
  
  return 0;
}