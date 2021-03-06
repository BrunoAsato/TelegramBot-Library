// Copyright Casa Jasmina 2016
// LGPL License
//
// TelegramBot library
// https://github.com/CasaJasmina/TelegramBot-Library

#ifndef TelegramBot_h
#define TelegramBot_h

#include <Arduino.h>
#include <ArduinoJson.h>
#include <Client.h>
#include <TelegramKeyboard.h>

#define HOST "api.telegram.org"
#define SSL_PORT 443
#define JSON_BUFF_SIZE 10000

struct message{
  String text;
  int chat_id;
  String sender;
  String date;
};

class TelegramBot
{
  public:
    TelegramBot(const char* token, const char* name, const char* username, Client &client);
  	void begin();
    String sendMessage(int chat_id, String text);
    String sendMessage(int chat_id, String text, TelegramKeyboard &keyboard_markup, bool one_time_keyboard = true, bool resize_keyboard = true);
    String postMessage(String msg);
    message getUpdates();

  private:
      String readPayload();
      const char* token;
      const char* name;
      const char* username;

      int last_message_recived;

      Client *client;
};

#endif
