// ArduinoJson - https://arduinojson.org
// Copyright © 2014-2024, Benoit BLANCHON
// MIT License
//
// This example shows how to deserialize a MessagePack document with
// ArduinoJson.
//
// https://arduinojson.org/v7/example/msgpack-parser/

#include <ArduinoJson.h>

// #include <ctype.h>


void hexdump(Stream &s, void *ptr, int buflen) {
    unsigned char *buf = (unsigned char*)ptr;
    int i, j;
    for (i=0; i<buflen; i+=16) {
        s.printf("%06x: ", i);
        for (j=0; j<16; j++)
            if (i+j < buflen)
                s.printf("%02x ", buf[i+j]);
            else
                s.printf("   ");
        Serial.printf(" ");
        for (j=0; j<16; j++)
            if (i+j < buflen)
                s.printf("%c", isprint(buf[i+j]) ? buf[i+j] : '.');
        s.printf("\n");
    }
}

void setup() {
    delay(3000);
    Serial.begin(115200);


    // Allocate the JSON document
    JsonDocument doc;

    // The MessagePack input string
    uint8_t input[] = {131, 166, 115, 101, 110, 115, 111, 114, 163, 103, 112, 115,
                       164, 116, 105, 109, 101, 206, 80,  147, 50,  248, 164, 100,
                       97,  116, 97,  146, 203, 64,  72,  96,  199, 58,  188, 148,
                       112, 203, 64,  2,   106, 146, 230, 33,  49,  169
                      };
    // This MessagePack document contains:
    // {
    //   "sensor": "gps",
    //   "time": 1351824120,
    //   "data": [48.75608, 2.302038]
    // }

    // Parse the input
    DeserializationError error = deserializeMsgPack(doc, input);

    // Test if parsing succeeded
    if (error) {
        Serial.print("deserializeMsgPack() failed: ");
        Serial.println(error.f_str());
        return;
    }

    // Fetch the values
    //
    // Most of the time, you can rely on the implicit casts.
    // In other case, you can do doc["time"].as<long>();
    const char* sensor = doc["sensor"];
    long time = doc["time"];
    double latitude = doc["data"][0];
    double longitude = doc["data"][1];

    // Print the values
    Serial.println(sensor);
    Serial.println(time);
    Serial.println(latitude, 6);
    Serial.println(longitude, 6);

    // Serialize JSON to MessagePack
    // size_t capacity = measureJson(doc);
    // uint8_t buffer[capacity];
    uint8_t buffer[2048];
    size_t len = serializeMsgPack(doc, buffer);

    hexdump(Serial, buffer, len);
}

void loop() {
    // not used in this example
}