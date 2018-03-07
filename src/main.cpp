#include "mbed.h"
#include "Simple-LoRaWAN.h"
#include "settings.h"
#include "Packet.h"

using namespace SimpleLoRaWAN;

Serial pc(USBTX, USBRX);
DigitalOut alive(LED1);
DigitalOut lora_tx(LED2);

Ticker send_ticker;
Node* node;
static const float LORAWAN_INTERVAL = 10.0;

void send_hello()
{
  pc.printf("Sending packet with hello\r\n");
  node->send("hello", 5);
  lora_tx = !lora_tx;
}

void init()
{
    pc.baud(115200);

    node = new ABP::Node(devAddr, nwksKey, appKey);
    node->disableLinkCheck();
    node->setSpreadFactor(DR_SF7);

    send_ticker.attach(&send_hello, LORAWAN_INTERVAL);
}

int main(void)
{
    init();
    wait(1.0);

    while(true){
        node->process();
        alive = !alive;
        wait(0.25);
    }
}
