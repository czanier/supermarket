#include "Supermarket.h"
#include "Client.h"
#include "Cashier.h"
#include <cstdlib>
#include <iostream>

#define MAX_NUM_CLIENTS 10
#define kDefaultNumClients 2
#define kDefaultNumCashiers 10
#define kNewClientsLap 2

Supermarket::Supermarket() : newClientsTimer(0.0f), boredClients(0), totalClients(0)
{
    for(int i = 0; i < kDefaultNumClients; i++)
        AddNewClient();
        
    for(int i = 0; i < kDefaultNumCashiers; i++)
        AddNewCashier();
};

void Supermarket::RunSimulation(float dt)
{
    std::vector<Client*>::iterator clientIt;
    std::vector<Cashier*>::iterator cashierIt;
    
    newClientsTimer += dt;
    
    if (newClientsTimer > kNewClientsLap && clients.size() < MAX_NUM_CLIENTS)
    {
        AddNewClient();
        newClientsTimer = 0.0f;
    }
        
    
    Client* client;
                                   
    clientIt = clients.begin();
    while(clientIt < clients.end())
    {
        client = *clientIt;
        
        client->Update(dt);
        if (client->IsBoring())
        {
            clientIt = clients.erase(clientIt);
            boredClients++;
        }
            
        clientIt++;
    }
    
    Cashier* cashier;
    for(cashierIt = cashiers.begin(); cashierIt < cashiers.end(); cashierIt++)
    {
        cashier = *cashierIt;
        cashier->Update(dt);
        if (cashier->CanServeClient() && clients.size() > 0)
        {
            clientIt = clients.begin();
            client = *clientIt;
            clients.erase(clientIt);
            cashier->ServeClient(client);
        }
    }
}

void Supermarket::ChangeCashierStatus(int aCashierNumber)
{
    Cashier* cashier = cashiers[aCashierNumber];
    cashier->SetWorking(!cashier->IsWorking());
};

void Supermarket::AddNewClient()
{
    Client* client = new Client();
    client->SetProducts((int)(rand() % 20) + 10);
    clients.push_back(client);
    totalClients++;
}

void Supermarket::AddNewCashier()
{
    Cashier* cashier = new Cashier();
    cashier->SetProductsPerSecond((rand() % 3) + 1);
    cashiers.push_back(cashier);
}

void Supermarket::PrintStatus()
{
    std::vector<Cashier*>::iterator cashierIt;
    std::cout << "Clients Line : " << clients.size() << std::endl;
    std::cout << "Total clients of the day : " << totalClients << std::endl;
    std::cout << "Clients left  : " << boredClients << std::endl;
    
    Cashier* cashier;
    int i;
    for(i = 0, cashierIt = cashiers.begin(); cashierIt < cashiers.end(); cashierIt++, i++)
    {
        cashier = *cashierIt;
        std::cout << "Cashier :" << i << " Status:" << (cashier->GetStatus() ? "ON" : "OFF");
        std::cout << " Clients Served :" << cashier->GetClientsServed() ;
        std::cout << " Client Producs Proce: " << cashier->GetCurrentClientProductsProcessed() << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Press 0-1 to Enable/Disable Cashier" << std::endl;
}
