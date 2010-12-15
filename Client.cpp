#include "Client.h"
#include <cstdlib>

#define kBoringTime 5 //secs

Client::Client()
{
    
};

void Client::Update(float dt)
{
    timer += dt;
};

bool Client::IsBoring()
{
    if ( timer > kBoringTime )
        return (rand() % 100) < 20;
    return false;
}
