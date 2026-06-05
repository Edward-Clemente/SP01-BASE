#include <WiFi.h>
#include <ArduinoOTA.h>

// ========================================
// CONFIGURACAO WIFI
// ========================================

const char* ssid = "sp_01";
const char* password = "magmag123";

// ========================================
// PINOS
// ========================================

#define LED_STATUS 4

// ========================================
// CONTROLE LED
// ========================================

unsigned long ultimoPisca = 0;
bool estadoLED = false;

// ========================================
// TASK HANDLES
// ========================================

TaskHandle_t TaskBase = NULL;
TaskHandle_t TaskApp  = NULL;

// ========================================
// CORE 0 - BASE
// ========================================

void tarefaBase(void *pvParameters)
{
    Serial.println("[BASE] Core 0 iniciado");

    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);

    Serial.print("[BASE] Conectando WiFi");

    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print(".");
        vTaskDelay(pdMS_TO_TICKS(500));
    }

    Serial.println();
    Serial.println("[BASE] WiFi conectado");
    Serial.print("[BASE] IP: ");
    Serial.println(WiFi.localIP());

    ArduinoOTA.setHostname("SP-01");

    ArduinoOTA.onStart([]()
    {
        Serial.println("[OTA] Iniciando atualização...");
    });

    ArduinoOTA.onEnd([]()
    {
        Serial.println("[OTA] Atualização concluída");
    });

    ArduinoOTA.onError([](ota_error_t error)
    {
        Serial.printf("[OTA] Erro %u\n", error);
    });

    ArduinoOTA.begin();

    Serial.println("[BASE] OTA ativo");

    while (true)
    {
        ArduinoOTA.handle();

        if (WiFi.status() != WL_CONNECTED)
        {
            Serial.println("[BASE] Reconectando WiFi...");
            WiFi.reconnect();
        }

        vTaskDelay(pdMS_TO_TICKS(10));
    }
}

// ========================================
// CORE 1 - APP
// ========================================

void tarefaApp(void *pvParameters)
{
    Serial.println("[APP] Core 1 iniciado");

    pinMode(LED_STATUS, OUTPUT);

    while (true)
    {
        unsigned long agora = millis();

        if (agora - ultimoPisca >= 1000)
        {
            ultimoPisca = agora;

            estadoLED = !estadoLED;

            digitalWrite(LED_STATUS, estadoLED);

            Serial.println("[APP] Heartbeat");
        }

        vTaskDelay(pdMS_TO_TICKS(1));
    }
}

// ========================================
// SETUP
// ========================================

void setup()
{
    Serial.begin(115200);

    Serial.println();
    Serial.println("================================");
    Serial.println("      SP01_BASE v0.1");
    Serial.println("================================");

    xTaskCreatePinnedToCore(
        tarefaBase,
        "TaskBase",
        10000,
        NULL,
        1,
        &TaskBase,
        0
    );

    xTaskCreatePinnedToCore(
        tarefaApp,
        "TaskApp",
        5000,
        NULL,
        1,
        &TaskApp,
        1
    );
}

// ========================================
// LOOP
// ========================================

void loop()
{
    vTaskDelay(pdMS_TO_TICKS(1000));
}
