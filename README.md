# SP01-BASE

Base oficial Frederico Labs para ESP32-WROOM-32.

## Objetivo

Criar uma plataforma única para todos os projetos futuros baseados no SP-01.

## Arquitetura

### Core 0

Responsável pelos serviços do sistema:

* WiFi
* OTA
* NTP
* GitHub Update
* Reconexão automática
* Watchdog
* Logs

### Core 1

Responsável pela aplicação do usuário:

* Interface gráfica
* Menus
* Sensores
* Automação
* Projetos específicos

## Hardware Padrão

* ESP32-WROOM-32 (30 pinos)
* TFT ILI9341
* SD Card SPI dedicado
* Encoder HW-040

## Status Atual

v0.1 (Validado)

✅ Dual Core
✅ Core 0 dedicado aos serviços do sistema
✅ Core 1 dedicado à aplicação
✅ WiFi funcional
✅ OTA funcional
✅ Estrutura inicial aprovada
Projeto desenvolvido por Frederico Labs.
