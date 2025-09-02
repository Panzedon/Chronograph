# ⚡ Хронограф для страйкбола / Airsoft Chronograph

![GitHub repo size](https://img.shields.io/github/repo-size/USERNAME/REPO_NAME?color=blue)
![GitHub language count](https://img.shields.io/github/languages/count/USERNAME/REPO_NAME)
![GitHub top language](https://img.shields.io/github/languages/top/USERNAME/REPO_NAME?color=yellow)
![GitHub last commit](https://img.shields.io/github/last-commit/USERNAME/REPO_NAME?color=green)

[🇺🇦 Українська](#-українська) | [🇬🇧 English](#-english)

---

## 🇺🇦 Українська

### 📌 Опис проєкту
Хронограф для страйкбольних куль 6 мм на базі мікроконтролера **STM8S103F3P6**.  
Живлення від **USB Type-C**, використання **двох лазерів** для фіксації польоту кульки.

🎯 Можливості:
- 📏 Вимірювання **швидкості кулі** (м/с)  
- 💥 Розрахунок **енергії пострілу**  
- 🔫 Визначення **скорострільності** (опціонально)

### 🔧 Керування
- 🔴 **Кнопка 1** – вмикає/вимикає лазери  
- 🔵 **Кнопка 2** – перемикає режим (швидкість / енергія / скорострільність)

### ⚙️ Технічні характеристики

| Параметр          | Значення |
|-------------------|----------|
| Мікроконтролер    | STM8S103F3P6 |
| Живлення          | USB Type-C |
| Датчики           | 2 лазерні промені |
| Калібр            | 6 мм BB (страйкбол) |

### 📂 Структура проєкту

/Altium – принципова схема та плата (Altium Designer)
/VsCode – середовище розробки на VS Code, у якому можна програмувати та 
заливати прошивку у мікроконтролер (C, COSMIC, stm8flash, ST-LINK)


✍️ **Автор:** Матвій Шульга

---

## 🇬🇧 English

### 📌 Project description
Chronograph for 6 mm airsoft BBs based on **STM8S103F3P6** microcontroller.  
Powered via **USB Type-C**, uses **two laser beams** to detect BB flight.

🎯 Features:
- 📏 Measure **BB velocity** (m/s)  
- 💥 Calculate **shot energy**  
- 🔫 Measure **rate of fire** (optional)

### 🔧 Controls
- 🔴 **Button 1** – laser on/off  
- 🔵 **Button 2** – mode switch (velocity / energy / rate of fire)

### ⚙️ Technical specifications

| Parameter         | Value |
|-------------------|-------|
| Microcontroller   | STM8S103F3P6 |
| Power supply      | USB Type-C |
| Sensors           | 2 laser beams |
| Caliber           | 6 mm BBs |

### 📂 Project structure


/Altium – schematics and PCB (Altium Designer)
/VsCode – development environment in VS Code, where you can program and 
flash firmware to the microcontroller (C, COSMIC, stm8flash, ST-LINK)


✍️ **Developed by:** Matvei Shulga
