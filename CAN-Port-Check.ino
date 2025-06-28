#include <Arduino.h>
#include "driver/twai.h"  // ESP32's internal CAN driver

#define TX_GPIO_NUM GPIO_NUM_5  //GPIOs connect to the CAN transceiver TJA1050 Module
#define RX_GPIO_NUM GPIO_NUM_4

void initCAN() {
  // Configure CAN driver

  twai_general_config_t g_config = TWAI_GENERAL_CONFIG_DEFAULT(TX_GPIO_NUM, RX_GPIO_NUM, TWAI_MODE_NORMAL);

  twai_timing_config_t t_config = TWAI_TIMING_CONFIG_500KBITS();

  twai_filter_config_t f_config = TWAI_FILTER_CONFIG_ACCEPT_ALL();



  // Install CAN driver

  if (twai_driver_install(&g_config, &t_config, &f_config) == ESP_OK) {

    Serial.println("CAN driver installed");

  } else {

    Serial.println("Failed to install CAN driver");

    return;
  }


  // Start CAN driver

  if (twai_start() == ESP_OK) {

    Serial.println("CAN driver started");

  } else {

    Serial.println("Failed to start CAN driver");

    return;
  }
}

void setup() {

  Serial.begin(115200);

  initCAN(); //CAN Driver Intialization
}

void loop() {

  twai_message_t message;

  message.identifier = 0x351;  // CAN ID

  message.extd = 0;  // Standard frame

  message.rtr = 0;  // Data frame has 0, RTR frame has 1

  message.ss = 0;  // Single Shot mode

  message.self = 0;  // Self reception (loopback)

  message.dlc_non_comp = 1;  // DLC is 8

  message.data_length_code = 8;

  message.data[0] = 0x1C;

  message.data[1] = 0x02;

  message.data[2] = 0xC8;

  message.data[3] = 0x00;

  message.data[4] = 0xC8;

  message.data[5] = 0x00;

  message.data[6] = 0xA4;

  message.data[7] = 0x01;

  Serial.print("Sending message with ID: 0x");

  Serial.println(message.identifier, HEX);

  Serial.print("Data: ");

  for (int i = 0; i < message.data_length_code; i++) {

    Serial.print(message.data[i], HEX);

    Serial.print(" ");
  }

  Serial.println();



  if (twai_transmit(&message, pdMS_TO_TICKS(1000)) == ESP_OK) {

    Serial.println("Message sent");

  } else {

    Serial.println("Failed to send message");
  }



  delay(1000);
}
