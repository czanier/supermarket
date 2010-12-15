#ifndef _SUPERMARKET_H_
#define _SUPERMARKET_H_

#include <vector>

class Client;
class Cashier;

class Supermarket
{
public:
    Supermarket();
    void RunSimulation(float dt);
    void PrintStatus();
    void ChangeCashierStatus(int aCashierNumber);
private:
    
    void AddNewClient();
    void AddNewCashier();
    
    std::vector<Client*>    clients;
    std::vector<Cashier*>   cashiers;
    
    float   newClientsTimer;
    int     totalClients;
    int     boredClients;
};
#endif
