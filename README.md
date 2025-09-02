# ⚡ Хронограф для страйкбола / Airsoft Chronograph

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
- ⏱ **Утримання кнопки 2** – перемикання в режим **задання ваги кульки** (0.2, 0.25 і т.д.), подальше утримання зберігає вагу та повертає до початкового режиму  

### 🔧 Керування
- 🔴 **Кнопка 1** – вмикає/вимикає лазери  
- 🔵 **Кнопка 2** – коротке натискання перемикає режим (швидкість / енергія / скорострільність)  
- 🔵 **Кнопка 2** – довге утримання перемикає в режим задання ваги кульки та зберігає її після наступного утримання  

### ⚙️ Технічні характеристики

| Параметр          | Значення |
|-------------------|----------|
| Мікроконтролер    | STM8S103F3P6 |
| Живлення          | USB Type-C |
| Датчики           | 2 лазерні промені |
| Калібр            | 6 мм BB (страйкбол) |

### 📂 Структура проєкту

- Altium – принципова схема та плата (Altium Designer)  
- VsCode – середовище розробки на VS Code, у якому можна програмувати та заливати прошивку у мікроконтролер (C, COSMIC, stm8flash, ST-LINK)  

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
- ⏱ **Hold Button 2** – switch to **BB weight setting mode** (0.2, 0.25 etc.), hold again to save the weight and return to the previous mode  

### 🔧 Controls
- 🔴 **Button 1** – laser on/off  
- 🔵 **Button 2** – short press switches mode (velocity / energy / rate of fire)  
- 🔵 **Button 2** – long press switches to **BB weight setting mode**; holding again saves weight and returns to previous mode  

### ⚙️ Technical specifications

| Parameter         | Value |
|-------------------|-------|
| Microcontroller   | STM8S103F3P6 |
| Power supply      | USB Type-C |
| Sensors           | 2 laser beams |
| Caliber           | 6 mm BBs |

### 📂 Project structure

- Altium – schematics and PCB (Altium Designer)  
- VsCode – development environment in VS Code, where you can program and flash firmware to the microcontroller (C, COSMIC, stm8flash, ST-LINK)  

✍️ **Developed by:** Matvei Shulga