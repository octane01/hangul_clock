// Include libraries
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <NTPClient.h>

// Get WiFi Credentials
const char *ssid = "*******";     // Change to your WiFi ID
const char *password = "*******"; // Change to your WiFi password

// Define NTP Client to get time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

// Define variables
String formattedTime;

#include <Adafruit_NeoPixel.h>
#define PIN       D8
#define NUMPIXELS 47

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_RGB + NEO_KHZ800);

// define main LED
int dAM[] = {1, 2, -1};          // AM
int dPM[] = {1, 14, -1};          // PM
int dHour[] = {22, -1};          // Hour
int dMinute[] = {41, -1};        // Minute
int dMidnight[] = {30, 33, -1};  // Midnight
int dNoon[] = {33, 46, -1};      // Noon

// Define Time
int Hour0[] = {3, 11, -1};        // 0
int Hour1[] = {4, -1};            // 1
int Hour2[] = {11, -1};           // 2
int Hour3[] = {5, -1};            // 3
int Hour4[] = {6, -1};            // 4
int Hour5[] = {13, 18, -1};       // 5
int Hour6[] = {17, 18, -1};       // 6
int Hour7[] = {12, 19, -1};       // 7
int Hour8[] = {10, 9, -1};       // 8
int Hour9[] = {20, 21, -1};       // 9
int Hour10[] = {3, -1};           // 10
int Hour11[] = {3, 4, -1};        // 11

// Define Minute
int Min0[] = {-1};                // 0
int Min1[] = {34, -1};            // 1
int Min2[] = {35, -1};            // 2
int Min3[] = {36, -1};            // 3
int Min4[] = {37, -1};            // 4
int Min5[] = {38, -1};            // 5
int Min6[] = {45, -1};            // 6
int Min7[] = {44, -1};            // 7
int Min8[] = {43, -1};            // 8
int Min9[] = {42, -1};            // 9
int Min10[] = {25, -1};           // 10
int Min11[] = {25, 34, -1};       // 11
int Min12[] = {25, 35, -1};       // 12
int Min13[] = {25, 36, -1};       // 13
int Min14[] = {25, 37, -1};       // 14
int Min15[] = {25, 38, -1};       // 15
int Min16[] = {25, 45, -1};       // 16
int Min17[] = {25, 44, -1};       // 17
int Min18[] = {25, 43, -1};       // 18
int Min19[] = {25, 42, -1};       // 19
int Min20[] = {29, 25, -1};       // 20
int Min21[] = {29, 25, 34, -1};   // 21
int Min22[] = {29, 25, 35, -1};   // 22
int Min23[] = {29, 25, 36, -1};   // 23
int Min24[] = {29, 25, 37, -1};   // 24
int Min25[] = {29, 25, 38, -1};   // 25
int Min26[] = {29, 25, 45, -1};   // 26
int Min27[] = {29, 25, 44, -1};   // 27
int Min28[] = {29, 25, 43, -1};   // 25
int Min29[] = {29, 25, 42, -1};   // 29
int Min30[] = {28, 25, -1};       // 30
int Min31[] = {28, 25, 34, -1};   // 31
int Min32[] = {28, 25, 35, -1};   // 32
int Min33[] = {28, 25, 36, -1};   // 33
int Min34[] = {28, 25, 37, -1};   // 34
int Min35[] = {28, 25, 38, -1};   // 35
int Min36[] = {28, 25, 45, -1};   // 36
int Min37[] = {28, 25, 44, -1};   // 37
int Min38[] = {28, 25, 43, -1};   // 38
int Min39[] = {28, 25, 42, -1};   // 39
int Min40[] = {27, 25, -1};       // 40
int Min41[] = {27, 25, 34, -1};   // 41
int Min42[] = {27, 25, 35, -1};   // 42
int Min43[] = {27, 25, 36, -1};   // 43
int Min44[] = {27, 25, 37, -1};   // 44
int Min45[] = {27, 25, 38, -1};   // 45
int Min46[] = {27, 25, 45, -1};   // 46
int Min47[] = {27, 25, 44, -1};   // 47
int Min48[] = {27, 25, 43, -1};   // 48
int Min49[] = {27, 25, 42, -1};   // 49
int Min50[] = {26, 25, -1};       // 50
int Min51[] = {26, 25, 34, -1};   // 51
int Min52[] = {26, 25, 35, -1};   // 52
int Min53[] = {26, 25, 36, -1};   // 53
int Min54[] = {26, 25, 37, -1};   // 54
int Min55[] = {26, 25, 38, -1};   // 55
int Min56[] = {26, 25, 45, -1};   // 56
int Min57[] = {26, 25, 44, -1};   // 57
int Min58[] = {26, 25, 43, -1};   // 58
int Min59[] = {26, 25, 42, -1};   // 59

// Define colours
uint32_t Black = pixels.Color(0, 0, 0);
uint32_t Red = pixels.Color(255, 0, 0);
uint32_t Green = pixels.Color(0, 255, 0);
uint32_t Blue = pixels.Color(0, 0, 255);
uint32_t Yellow = pixels.Color(255, 255, 0);
uint32_t Magenta = pixels.Color(255, 0, 255);
uint32_t Cyan = pixels.Color(0, 255, 255);
uint32_t White = pixels.Color(255, 255, 255);
uint32_t Gold = pixels.Color(255, 204, 0);
uint32_t Lightblue = pixels.Color(153, 204, 255);
uint32_t Brown = pixels.Color(153, 102, 051);

// Define Brightness
int dayBrightness = 100;
int nightBrightness = 50;

void setup() {

    // Initialize Serial Monitor
    Serial.begin(115200);
    delay(10);

    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.print(ssid);
    
    WiFi.begin(ssid, password);
    
    while (WiFi.status() != WL_CONNECTED ) {
        delay(500);
        Serial.print(".");
    }

    // Print local IP address and start web server
    Serial.println("");
    Serial.println("WiFi Connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    Serial.println("/");

    // Initialize a NTPClient to get time
    timeClient.begin();
    timeClient.setTimeOffset(32400); // GMT +9

    //Wire.begin();
    pixels.begin();

    blank();
    test();

}

void lightup(int Word[], uint32_t ColorName) {
  for (int x = 0; x < pixels.numPixels() + 1; x++) {
    if (Word[x] == -1) {
      pixels.show();
      break;
    } //end of if loop
    else {
      pixels.setPixelColor(Word[x], ColorName);
      pixels.show();
    } // end of else loop
  } //end of for loop
}

void displayTime(int minute, int hour) {
  // Minutes
  switch (minute) {
    case  1: lightup(Min59, Black); lightup(Min0,  Black); lightup(Min1,  Red); lightup(dMinute, Cyan); break;
    case  2: lightup(Min0,  Black); lightup(Min1,  Black); lightup(Min2,  Red); lightup(dMinute, Cyan); break;
    case  3: lightup(Min1,  Black); lightup(Min2,  Black); lightup(Min3,  Red); lightup(dMinute, Cyan); break;
    case  4: lightup(Min2,  Black); lightup(Min3,  Black); lightup(Min4,  Red); lightup(dMinute, Cyan); break;
    case  5: lightup(Min3,  Black); lightup(Min4,  Black); lightup(Min5,  Red); lightup(dMinute, Cyan); break;
    case  6: lightup(Min4,  Black); lightup(Min5,  Black); lightup(Min6,  Red); lightup(dMinute, Cyan); break;
    case  7: lightup(Min5,  Black); lightup(Min6,  Black); lightup(Min7,  Red); lightup(dMinute, Cyan); break;
    case  8: lightup(Min6,  Black); lightup(Min7,  Black); lightup(Min8,  Red); lightup(dMinute, Cyan); break;
    case  9: lightup(Min7,  Black); lightup(Min8,  Black); lightup(Min9,  Red); lightup(dMinute, Cyan); break;
    case 10: lightup(Min8,  Black); lightup(Min9,  Black); lightup(Min10, Red); lightup(dMinute, Cyan); break;
    case 11: lightup(Min9,  Black); lightup(Min10, Black); lightup(Min11, Red); lightup(dMinute, Cyan); break;
    case 12: lightup(Min10, Black); lightup(Min11, Black); lightup(Min12, Red); lightup(dMinute, Cyan); break;
    case 13: lightup(Min11, Black); lightup(Min12, Black); lightup(Min13, Red); lightup(dMinute, Cyan); break;
    case 14: lightup(Min12, Black); lightup(Min13, Black); lightup(Min14, Red); lightup(dMinute, Cyan); break;
    case 15: lightup(Min13, Black); lightup(Min14, Black); lightup(Min15, Red); lightup(dMinute, Cyan); break;
    case 16: lightup(Min14, Black); lightup(Min15, Black); lightup(Min16, Red); lightup(dMinute, Cyan); break;
    case 17: lightup(Min15, Black); lightup(Min16, Black); lightup(Min17, Red); lightup(dMinute, Cyan); break;
    case 18: lightup(Min16, Black); lightup(Min17, Black); lightup(Min18, Red); lightup(dMinute, Cyan); break;
    case 19: lightup(Min17, Black); lightup(Min18, Black); lightup(Min19, Red); lightup(dMinute, Cyan); break;
    case 20: lightup(Min18, Black); lightup(Min19, Black); lightup(Min20, Red); lightup(dMinute, Cyan); break;
    case 21: lightup(Min19, Black); lightup(Min20, Black); lightup(Min21, Red); lightup(dMinute, Cyan); break;
    case 22: lightup(Min20, Black); lightup(Min21, Black); lightup(Min22, Red); lightup(dMinute, Cyan); break;
    case 23: lightup(Min21, Black); lightup(Min22, Black); lightup(Min23, Red); lightup(dMinute, Cyan); break;
    case 24: lightup(Min22, Black); lightup(Min23, Black); lightup(Min24, Red); lightup(dMinute, Cyan); break;
    case 25: lightup(Min23, Black); lightup(Min24, Black); lightup(Min25, Red); lightup(dMinute, Cyan); break;
    case 26: lightup(Min24, Black); lightup(Min25, Black); lightup(Min26, Red); lightup(dMinute, Cyan); break;
    case 27: lightup(Min25, Black); lightup(Min26, Black); lightup(Min27, Red); lightup(dMinute, Cyan); break;
    case 28: lightup(Min26, Black); lightup(Min27, Black); lightup(Min28, Red); lightup(dMinute, Cyan); break;
    case 29: lightup(Min27, Black); lightup(Min28, Black); lightup(Min29, Red); lightup(dMinute, Cyan); break;
    case 30: lightup(Min28, Black); lightup(Min29, Black); lightup(Min30, Red); lightup(dMinute, Cyan); break;
    case 31: lightup(Min29, Black); lightup(Min30, Black); lightup(Min31, Red); lightup(dMinute, Cyan); break;
    case 32: lightup(Min30, Black); lightup(Min31, Black); lightup(Min32, Red); lightup(dMinute, Cyan); break;
    case 33: lightup(Min31, Black); lightup(Min32, Black); lightup(Min33, Red); lightup(dMinute, Cyan); break;
    case 34: lightup(Min32, Black); lightup(Min33, Black); lightup(Min34, Red); lightup(dMinute, Cyan); break;
    case 35: lightup(Min33, Black); lightup(Min34, Black); lightup(Min35, Red); lightup(dMinute, Cyan); break;
    case 36: lightup(Min34, Black); lightup(Min35, Black); lightup(Min36, Red); lightup(dMinute, Cyan); break;
    case 37: lightup(Min35, Black); lightup(Min36, Black); lightup(Min37, Red); lightup(dMinute, Cyan); break;
    case 38: lightup(Min36, Black); lightup(Min37, Black); lightup(Min38, Red); lightup(dMinute, Cyan); break;
    case 39: lightup(Min37, Black); lightup(Min38, Black); lightup(Min39, Red); lightup(dMinute, Cyan); break;
    case 40: lightup(Min38, Black); lightup(Min39, Black); lightup(Min40, Red); lightup(dMinute, Cyan); break;
    case 41: lightup(Min39, Black); lightup(Min40, Black); lightup(Min41, Red); lightup(dMinute, Cyan); break;
    case 42: lightup(Min40, Black); lightup(Min41, Black); lightup(Min42, Red); lightup(dMinute, Cyan); break;
    case 43: lightup(Min41, Black); lightup(Min42, Black); lightup(Min43, Red); lightup(dMinute, Cyan); break;
    case 44: lightup(Min42, Black); lightup(Min43, Black); lightup(Min44, Red); lightup(dMinute, Cyan); break;
    case 45: lightup(Min43, Black); lightup(Min44, Black); lightup(Min45, Red); lightup(dMinute, Cyan); break;
    case 46: lightup(Min44, Black); lightup(Min45, Black); lightup(Min46, Red); lightup(dMinute, Cyan); break;
    case 47: lightup(Min45, Black); lightup(Min46, Black); lightup(Min47, Red); lightup(dMinute, Cyan); break;
    case 48: lightup(Min46, Black); lightup(Min47, Black); lightup(Min48, Red); lightup(dMinute, Cyan); break;
    case 49: lightup(Min47, Black); lightup(Min48, Black); lightup(Min49, Red); lightup(dMinute, Cyan); break;
    case 50: lightup(Min48, Black); lightup(Min49, Black); lightup(Min50, Red); lightup(dMinute, Cyan); break;
    case 51: lightup(Min49, Black); lightup(Min50, Black); lightup(Min51, Red); lightup(dMinute, Cyan); break;
    case 52: lightup(Min50, Black); lightup(Min51, Black); lightup(Min52, Red); lightup(dMinute, Cyan); break;
    case 53: lightup(Min51, Black); lightup(Min52, Black); lightup(Min53, Red); lightup(dMinute, Cyan); break;
    case 54: lightup(Min52, Black); lightup(Min53, Black); lightup(Min54, Red); lightup(dMinute, Cyan); break;
    case 55: lightup(Min53, Black); lightup(Min54, Black); lightup(Min55, Red); lightup(dMinute, Cyan); break;
    case 56: lightup(Min54, Black); lightup(Min55, Black); lightup(Min56, Red); lightup(dMinute, Cyan); break;
    case 57: lightup(Min55, Black); lightup(Min56, Black); lightup(Min57, Red); lightup(dMinute, Cyan); break;
    case 58: lightup(Min56, Black); lightup(Min57, Black); lightup(Min58, Red); lightup(dMinute, Cyan); break;
    case 59: lightup(Min57, Black); lightup(Min58, Black); lightup(Min59, Red); lightup(dMinute, Cyan); break;
    case 60: lightup(Min58, Black); lightup(Min59, Black);                      lightup(dMinute, Black); break;
    case  0: lightup(Min58, Black); lightup(Min59, Black);                      lightup(dMinute, Black); break;
  }

  // Hours
  switch (hour) {
    case 1:  lightup(dAM, Cyan); lightup(Hour0,  Black); lightup(Hour1,  Red); lightup(dHour, Cyan); break;
    case 13: lightup(dPM, Cyan); lightup(Hour0,  Black); lightup(Hour1,  Red); lightup(dHour, Cyan); break;
    case 2:  lightup(dAM, Cyan); lightup(Hour1,  Black); lightup(Hour2,  Red); lightup(dHour, Cyan); break;
    case 14: lightup(dPM, Cyan); lightup(Hour1,  Black); lightup(Hour2,  Red); lightup(dHour, Cyan); break;
    case 3:  lightup(dAM, Cyan); lightup(Hour2,  Black); lightup(Hour3,  Red); lightup(dHour, Cyan); break;
    case 15: lightup(dPM, Cyan); lightup(Hour2,  Black); lightup(Hour3,  Red); lightup(dHour, Cyan); break;
    case 4:  lightup(dAM, Cyan); lightup(Hour3,  Black); lightup(Hour4,  Red); lightup(dHour, Cyan); break;
    case 16: lightup(dPM, Cyan); lightup(Hour3,  Black); lightup(Hour4,  Red); lightup(dHour, Cyan); break;
    case 5:  lightup(dAM, Cyan); lightup(Hour4,  Black); lightup(Hour5,  Red); lightup(dHour, Cyan); break;
    case 17: lightup(dPM, Cyan); lightup(Hour4,  Black); lightup(Hour5,  Red); lightup(dHour, Cyan); break;
    case 6:  lightup(dAM, Cyan); lightup(Hour5,  Black); lightup(Hour6,  Red); lightup(dHour, Cyan); break;
    case 18: lightup(dPM, Cyan); lightup(Hour5,  Black); lightup(Hour6,  Red); lightup(dHour, Cyan); break;
    case 7:  lightup(dAM, Cyan); lightup(Hour6,  Black); lightup(Hour7,  Red); lightup(dHour, Cyan); break;
    case 19: lightup(dPM, Cyan); lightup(Hour6,  Black); lightup(Hour7,  Red); lightup(dHour, Cyan); break;
    case 8:  lightup(dAM, Cyan); lightup(Hour7,  Black); lightup(Hour8,  Red); lightup(dHour, Cyan); break;
    case 20: lightup(dPM, Cyan); lightup(Hour7,  Black); lightup(Hour8,  Red); lightup(dHour, Cyan); break;
    case 9:  lightup(dAM, Cyan); lightup(Hour8,  Black); lightup(Hour9,  Red); lightup(dHour, Cyan); break;
    case 21: lightup(dPM, Cyan); lightup(Hour8,  Black); lightup(Hour9,  Red); lightup(dHour, Cyan); break;
    case 10: lightup(dAM, Cyan); lightup(Hour9,  Black); lightup(Hour10, Red); lightup(dHour, Cyan); break;
    case 22: lightup(dPM, Cyan); lightup(Hour9,  Black); lightup(Hour10, Red); lightup(dHour, Cyan); break;
    case 11: lightup(dAM, Cyan); lightup(Hour10, Black); lightup(Hour11, Red); lightup(dHour, Cyan); break;
    case 23: lightup(dPM, Cyan); lightup(Hour10, Black); lightup(Hour11, Red); lightup(dHour, Cyan); break;
    case 12: lightup(dPM, Cyan); lightup(Hour11, Black); lightup(Hour0,  Red); lightup(dHour, Cyan); break;
    case 24: lightup(dPM, Cyan); lightup(Hour11, Black); lightup(Hour0,  Red); lightup(dHour, Cyan); break;
    case 0:  lightup(dAM, Cyan); lightup(Hour11, Black); lightup(Hour0,  Red); lightup(dHour, Cyan); break;
  }
}

void loop()
{
  
    timeClient.update();
    /*while(!timeClient.update()) {
        timeClient.forceUpdate();
    }*/

    // Get time for the Word Clock
    formattedTime = timeClient.getFormattedTime();
    int hour = timeClient.getHours();
    int minute = timeClient.getMinutes();
    int dayOfWeek = timeClient.getDay();

    Serial.println(hour);
    Serial.println(minute);
    delay(1000);
    
    // Set brightness dependent on time of day in the word Clock
    if ((hour >= 0) && (hour < 8)) {
      pixels.setBrightness(nightBrightness);
    }
    else {
      pixels.setBrightness(dayBrightness);
    }

    // Midnight & Noon display
    if ( (minute == 0) && (hour == 0) ) {
      lightup(dAM, Black);
      lightup(dPM, Black);
      lightup(dHour, Black);
      lightup(dMinute, Black);
      lightup(Min58, Black);
      lightup(Min59, Black);
      lightup(Hour11, Black);
      lightup(dNoon, Black);
      lightup(dMidnight, Magenta); 
    }
    if ( (minute == 0) && (hour == 12) ) {
      lightup(dAM, Black);
      lightup(dPM, Black);
      lightup(dHour, Black);
      lightup(dMinute, Black);
      lightup(Min58, Black);
      lightup(Min59, Black);
      lightup(Hour11, Black);
      lightup(dMidnight, Black);
      lightup(dNoon, Magenta);
    }

    // AM & PM & Hour display
    if ( (minute == 0) && (hour != 0) && (hour != 12) ) {
      lightup(dNoon, Black);
      lightup(dMidnight, Black);
      // Display time
      displayTime(minute, hour);
    }
    if ( (minute != 0) && (hour != 0) && (hour != 12) ) {
      lightup(dNoon, Black);
      lightup(dMidnight, Black);
      // Display time
      displayTime(minute, hour);
    }
    if ( (minute != 0) && (hour == 0) ) {
      lightup(dNoon, Black);
      lightup(dMidnight, Black);
      // Display time
      displayTime(minute, hour);
    }
    if ( (minute != 0) && (hour == 12) ) {
      lightup(dNoon, Black);
      lightup(dMidnight, Black);
      // Display time
      displayTime(minute, hour);
    }
    
}

void blank()
{
    for (int i = 0 ; i < NUMPIXELS ; i++) {
        pixels.setPixelColor(i, Black);
    }
}

void wipe()
{
    for (int x = 0 ; x < NUMPIXELS ; ++x) {
        pixels.setPixelColor(x, Gold);
        delay(10);
        pixels.show();
        pixels.setPixelColor(x, Green);
        delay(10);
        pixels.show();
        pixels.setPixelColor(x, Red);
        delay(10);
        pixels.show();
        pixels.setPixelColor(x, Black);
        delay(10);
        pixels.show();
    }
}

void test()
{
    blank();
    wipe();
    blank();
}
