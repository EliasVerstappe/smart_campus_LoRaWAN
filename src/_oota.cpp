/*#include "mbed.h"
#include "Simple-LoRaWAN.h"
#include "Gps.h"
#include "settings.h"
#include "Packet.h"
#include "Logger.h"

using namespace SimpleLoRaWAN;

Serial pc(USBTX, USBRX);
// Serial gps_serial(p28,p27);
// Gps* gps;
// Ticker gps_ticker;
Ticker send_ticker;

DigitalOut fix_led_external(p21);
DigitalOut power_led_external(p22);

DigitalOut fix_led(LED4);
DigitalOut tx_led(LED1);
Logger logger(&pc);

Node* node;

static const float GPS_UPDATE_TIME = 2.0;
static const float LORAWAN_INTERVAL = 5.0;

void show_gps_info()
{
   // logger.gps(gps);
}

void send_gps_info()
{
    // if(gps->fix){
        pc.printf("Sending packet:");
        // uint8_t* packet = Packet::build(gps);
        // logger.packet(packet);

        node->send("hello", 5);
    // }
}

void init()
{
    power_led_external = 1;
    pc.baud(115200);
    //node = new ABP::Node(devAddr, nwksKey, appKey);
    node = new OTAA::Node(appEui, devEui, appKey);
    node->disableLinkCheck();
    node->setSpreadFactor(DR_SF7);

    // gps = new Gps(&gps_serial);
    // gps_ticker.attach(&show_gps_info, GPS_UPDATE_TIME);
    send_ticker.attach(&send_gps_info, LORAWAN_INTERVAL);
}

int main(void)
{
    init();
    wait(1.0);

    while(true){
        node->process();
        // gps->run();
        // fix_led = gps->fix;
        // fix_led_external = gps->fix;
    }
}*/
