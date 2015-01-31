// 42 chars wide

#include <SoftwareSerial.h>

#include "thermalprinter.h"

#define ledPin 13
#define rxPin 6
#define txPin 7

int printStatus = 0;

Epson TM88 = Epson(rxPin, txPin); // init the Printer with Output-Pin

void setup()
{

  Serial.begin(9600); //open the USB connection too
  

  delay(1000);

  TM88.start();
  TM88.println(F("                                          "));
  TM88.println(F("                                          "));
  TM88.println(F("                                          "));
  TM88.println(F("        MMMMMMMMMMMMMMMMMMMMMMMMMM        "));
  TM88.println(F("        MMMMMMMMMMMMMMMMMMMMMMMMMM        "));
  TM88.println(F("        MMMMmddddddddddddddddmMMMM        "));
  TM88.println(F("        MMMM/````````````````/MMMM        "));
  TM88.println(F("        NMMMo                oMMMm        "));
  TM88.println(F("        oMMMM/              /MMMMo        "));
  TM88.println(F("        `NMMMNh+-``     `.+yNMMMN`        "));
  TM88.println(F("         -dMMMMMNNNmmmmmNNMMMMMd-         "));
  TM88.println(F("          `/dMMMMMMMMMMMMMMMMdo`          "));
  TM88.println(F("            `-/shddmmmmddhy/-`            "));
  TM88.println(F("                 ````````                 "));
  TM88.println(F("              `-/+oyyyyoo/:.              "));
  TM88.println(F("           .+hmNMMMMMMMMMMMmmo.           "));
  TM88.println(F("         `omMMMMMMMMMMMMMMMMMMmo`         "));
  TM88.println(F("        `hMMMMNds/:----:/odNMMMMh`        "));
  TM88.println(F("        +MMMMh:`          `-hMMMM+        "));
  TM88.println(F("        NMMMM`              `MMMMN        "));
  TM88.println(F("        NMMMM`              `MMMMN        "));
  TM88.println(F("        oMMMMy.            .yMMMMo        "));
  TM88.println(F("        `dMMMMNy+:-....-:/ymMMMMd`        "));
  TM88.println(F("         `yNMMMMMMMmmmmMMMMMMMNy.         "));
  TM88.println(F("           -omNMMMMMMMMMMMMNms-           "));
  TM88.println(F("             `-/oosddddsso/-`             "));
  TM88.println(F("                                          "));
  TM88.println(F("          `+:`          `...`             "));
  TM88.println(F("         .dMMh/      .+hmNMNmh+.          "));
  TM88.println(F("        `mMMMMs`    :mMMMMMMMMMm:         "));
  TM88.println(F("        oMMMMo     :MMMMMNyhNMMMN-        "));
  TM88.println(F("        NMMMM`    -NMMMMh`  -MMMMh        "));
  TM88.println(F("        MMMMM    `mMMMMd`    MMMMM        "));
  TM88.println(F("        oMMMMo.`:dMMMMN-    -MMMMs        "));
  TM88.println(F("        `dMMMMMMMMMMMM:    -mMMMN.        "));
  TM88.println(F("         `sNMMMMMMMMm:     .smMd-         "));
  TM88.println(F("           `+syhhys:         `:`          "));
  TM88.println(F("                                          "));
  TM88.println(F("                                          "));
  TM88.println(F("                                          "));
  TM88.println(F("                                          "));
  TM88.println(F("                                          "));
  TM88.println(F("                                          "));
  TM88.println(F("        oooooooooooooooooooooooooo        "));
  TM88.println(F("        MMMMMMMMMMMMMMMMMMMMMMMMMM        "));
  TM88.println(F("        MMMMMMMMMMMMMMMMMMMMMMMMMM        "));
  TM88.println(F("        MMMMs////////////////sMMMM        "));
  TM88.println(F("        MMMM/                /MMMM        "));
  TM88.println(F("        hMMMd`              `dMMMy        "));
  TM88.println(F("        :MMMMh:`           -hMMMM:        "));
  TM88.println(F("         sMMMMNNyo+////+oyNNMMMMs         "));
  TM88.println(F("          /dMMMMMMMMMMMMMMMMMMm+          "));
  TM88.println(F("           `:ydNMMMMMMMMMMMdh/.           "));
  TM88.println(F("        `     `.-::++++/:-.`              "));
  TM88.println(F("        mmso/-.`                          "));
  TM88.println(F("        MMMMMNNmds+/.`                    "));
  TM88.println(F("        dmNMMMMMMMMMNmmyo/-.`             "));
  TM88.println(F("        ``.:/+MMMMMMMMMMMMNmmds+/-        "));
  TM88.println(F("              MMMMo:/oyddmNMMMMMMN        "));
  TM88.println(F("              MMMM/     `.:+smMMMM        "));
  TM88.println(F("              MMMM+-/+oydmmNMMMMMM        "));
  TM88.println(F("         `.-:+MMMMNMMMMMMMMMNmdy+/        "));
  TM88.println(F("        ddmNMMMMMMMMMNmddo+:.`            "));
  TM88.println(F("        MMMMMMMmmdso/-.`                  "));
  TM88.println(F("        Nmdho+:.`              `./        "));
  TM88.println(F("        -.`                `-/ydNM        "));
  TM88.println(F("                      `.:ohmMMMMMM        "));
  TM88.println(F("                  `./sdmMMMMMMNmms        "));
  TM88.println(F("        yyyyyyyyyhdNMMMMMNmds+-.          "));
  TM88.println(F("        MMMMMMMMMMMMMMds/.`               "));
  TM88.println(F("        NNNNNNNNNMMMMMNdho:-``            "));
  TM88.println(F("        ---------:+yNNMMMMMMdhs/-`        "));
  TM88.println(F("                    `.+sdNMMMMMMMm        "));
  TM88.println(F("                         .:sdNNMMM        "));
  TM88.println(F("                             `-oyN        "));
  TM88.println(F("                                          "));
  TM88.println(F("                                          "));
  TM88.println(F("                                          "));
  TM88.println(F("                                          "));
  TM88.println(F("                                          "));
  TM88.println(F("        yyyy.              .yy.           "));
  TM88.println(F("        MMMMNo`           /MMMM+          "));
  TM88.println(F("        MMMMMMNo`          :NMMM/         "));
  TM88.println(F("        MMMMMMMMNs.         +MMMd         "));
  TM88.println(F("        MMMMyhMMMMMy:`      sMMMN         "));
  TM88.println(F("        MMMMs -yMMMMMmyo++sdMMMMo         "));
  TM88.println(F("        MMMMs   .odMMMMMMMMMMMMs`         "));
  TM88.println(F("        MMMMs      -ohNMMMMMmy-           "));
  TM88.println(F("        mmmmo         `.---.`             "));
  TM88.println(F("        ````                              "));
  TM88.println(F("            .:+syhmNNNNhys+:.             "));
  TM88.println(F("          :yNNMMMMMMMMMMMMMMNh/           "));
  TM88.println(F("        `yNMMMMmddhhhhhhdmMMMMMy`         "));
  TM88.println(F("        oMMMN+-```     ```-/NMMMo         "));
  TM88.println(F("        NMMM/               /MMMN         "));
  TM88.println(F("        hMMMd-             .hMMMh         "));
  TM88.println(F("        .mMMMNmyoo++++++oymNMMMm-         "));
  TM88.println(F("         .omMMMMMMMMMMMMMMMMMNy.          "));
  TM88.println(F("           ./ohdmmNMMMNmmdhs/.            "));
  TM88.println(F("               ``.-----.``                "));
  TM88.println(F("        ````                              "));
  TM88.println(F("        dddd:              :+++           "));
  TM88.println(F("        MMMM/              sMMM-          "));
  TM88.println(F("        MMMMo--------------yMMMd`         "));
  TM88.println(F("        MMMMMMMMMMMMMMMMMMMMMMMMh         "));
  TM88.println(F("        MMMMMMMMMMMMMMMMMMMMMMMMM         "));
  TM88.println(F("        MMMMhssssssssssssssssssss         "));
  TM88.println(F("        MMMM/                             "));
  TM88.println(F("        mmmm:                             "));
  TM88.println(F("        ````                              "));
  TM88.println(F("          `.`                             "));
  TM88.println(F("         `yNd/`     ----.....````         "));
  TM88.println(F("        `dMMMd.    +MMMMMMMMNmmmm         "));
  TM88.println(F("        oMMMd`     oMMMMMMMMMMMMM         "));
  TM88.println(F("        NMMM/      `MMMy:+++dMMMM         "));
  TM88.println(F("        mMMMy`     -MMMN    sMMMM         "));
  TM88.println(F("        /MMMMds//+yNMMMy    sMMMM         "));
  TM88.println(F("         oMMMMMMMMMMMMm.    sMMMM         "));
  TM88.println(F("          -ymMMMMMMMmo`     +hhhh         "));
  TM88.println(F("             .:/+/-.                      "));
  TM88.println(F("                                          "));
  TM88.println(F("                                          "));
  TM88.println(F("                                          "));  
  TM88.println("");  
  TM88.println("");  
  
  TM88.cut();  
}

void loop()                     // run over and over again
{
  
  printStatus = TM88.getStatus();     // get the current status of the TM88 printer
  if (printStatus == 22) {            // if status is 22 then we are good
    Serial.println("printer online");     // debug that we are online
  } else {
    Serial.print("printer offline: ");    // debug that we are offline
    Serial.println(printStatus);          // debug the returned status code  
  } 
  
  
  if (Serial.available() > 0) {
    TM88.print(Serial.read());
  }

  //digitalWrite(ledPin, LOW);    // sets the LED off
  delay(1000);                  // waits for a second
}
