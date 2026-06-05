# SP01-BASE

Base oficial Frederico Labs para ESP32-WROOM-32.

## Objetivo

Criar uma plataforma única para todos os projetos futuros baseados no SP-01.

## Arquitetura

### Núcleo 0

Responsável pelos serviços do sistema:

* Wi-Fi
* OTA
* NTP
* Atualização via GitHub
* Reconexão automática
* Watchdog
* Logs do sistema

### Núcleo 1

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

### v0.1 (Validado)

* ✅ Dual Core
* ✅ Core 0 dedicado aos serviços do sistema
* ✅ Core 1 dedicado à aplicação
* ✅ Wi-Fi funcional
* ✅ OTA funcional
* ✅ Estrutura inicial aprovada

## Roadmap

### v0.2

* TFT ILI9341
* Diagnóstico de rede
* Exibição de IP
* Status OTA

### v0.3

* SD Card

### v0.4

* Checkpoint

### v0.5

* Atualização via GitHub

### v1.0

* Primeira versão estável do SP01-BASE

---

Projeto desenvolvido por Frederico Labs.
