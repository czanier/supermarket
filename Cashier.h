#ifndef _CASHIER_H_
#define _CASHIER_H_
enum CashierStatus
{
    eCashierStatusOff,
    eCashierStatusOn,
    eCashierStatusServing
};

class Client;

class Cashier
{
public:    
    Cashier();
    void SetProductsPerSecond(int aSpeed){productsPerSecond = aSpeed;};
    void Update(float dt);
    void SetStatus(CashierStatus aStatus){status = aStatus;};
    int GetClientsServed(){return clientsServerd;};
    CashierStatus GetStatus(){return status;};
    bool IsWorking(){return status != eCashierStatusOff;};
    void SetWorking(bool aWorking){status = aWorking ? eCashierStatusOn : eCashierStatusOff;};
    bool CanServeClient(){return status == eCashierStatusOn;};
    void ServeClient(Client* aClient);
    int GetCurrentClientProductsProcessed(){return producsProccessed;};
private:
    void ReleaseCashier();
    
    int productsPerSecond;
    CashierStatus status;
    int clientsServerd;
    int producsProccessed;
    float productTimer;
    Client* currentClient;
};
#endif