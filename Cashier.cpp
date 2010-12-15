#include "Cashier.h"
#include <cstddef>
#include "Client.h"
#include <iostream>
#include <ctime>

Cashier::Cashier(): productsPerSecond(0), clientsServerd(0), status(eCashierStatusOff), producsProccessed(0), productTimer(0.0f)
{
    
};

void Cashier::Update(float dt)
{
    if (status == eCashierStatusOff || currentClient == NULL) return;
    
    productTimer += dt;
    if (productTimer >= (1.0f / productsPerSecond))
    {
        productTimer = 0.0f;
        producsProccessed++;
        if (producsProccessed >= currentClient->GetProducts())
        {
            clientsServerd++;
            ReleaseCashier();
        }
    }
}

void Cashier::ReleaseCashier()
{
    currentClient = NULL;
    status = eCashierStatusOn;
    productTimer = 0.0f;
    producsProccessed = 0;
}

void Cashier::ServeClient(Client* aClient)
{
    status = eCashierStatusServing;
    currentClient = aClient;
    producsProccessed = 0;
    productTimer = 0.0f;
}
