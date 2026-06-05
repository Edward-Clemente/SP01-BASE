
## Princípio Fundamental

O SP01-BASE segue a separação permanente de responsabilidades:

* Core 0: Serviços do sistema
* Core 1: Aplicação do usuário

A aplicação nunca deverá interferir diretamente nos serviços críticos do sistema.

Esta arquitetura visa garantir estabilidade, manutenção simplificada e reutilização em projetos futuros.

## Arquitetura

### Core 0

Responsável pelos serviços do sistema:

* Wi-Fi
* OTA
* NTP
* Atualização via GitHub
* Reconexão automática
* Watchdog
* Logs do sistema

### Core 1

Responsável pela aplicação do usuário:

* Interface gráfica
* Menus
* Sensores
* Automação
* Projetos específicos


# SP01-BASE

Base oficial Frederico Labs para ESP32-WROOM-32.

## Objetivo

Criar uma plataforma única para todos os projetos futuros baseados no SP-01.

## Princípio Fundamental

O SP01-BASE segue a separação permanente de responsabilidades:

- Core 0: Serviços do sistema
- Core 1: Aplicação do usuário

A aplicação nunca deverá interferir diretamente nos serviços críticos do sistema.

Esta arquitetura visa garantir estabilidade, manutenção simplificada e reutilização em projetos futuros.

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

## Pinagem Oficial

O projeto utiliza a pinagem oficial Frederico Labs para ESP32 + TFT ILI9341 + SD Card SPI dedicado.

Alterações de pinagem devem ser evitadas para garantir compatibilidade entre projetos.

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

Projeto: SP01-BASE

Versão: v0.1
Status: Validado

Dual Core............. OK
WiFi.................. OK
OTA................... OK
Core 0................ OK
Core 1................ OK

Próxima meta:
v0.2 - TFT + Diagnóstico de Rede

---

Projeto desenvolvido por Frederico Labs.
