#ifndef _CLIENT_H_
#define _CLIENT_H_

class Client
{
public:
    Client();
    void Update(float dt);
    void SetProducts(int aNumProducts){numProducts = aNumProducts;};
    int GetProducts(){return numProducts;};
    bool IsBoring();
private:
    int numProducts;
    float timer;
};

#endif
