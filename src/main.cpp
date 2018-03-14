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
  uint8_t buffer[5];
  buffer[0] = 215 >> 8;
  buffer[1] = 215 & 0x00FF;
  buffer[2] = 27;
  buffer[3] = 73 >> 8;
  buffer[4] = 73 & 0x00FF;


  pc.printf("Sending packet with hello\r\n");
  node->send(buffer, 5);
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
