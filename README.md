# ⚡ Хронограф для страйкбола / Airsoft Chronograph

[🇺🇦 Українська](#-українська) | [🇬🇧 English](#-english)

---

## 🇺🇦 Українська

### 📌 Опис проєкту
Хронограф для страйкбольних куль 6 мм на базі мікроконтролера **STM8S103F3P6**.  
Живлення від **USB Type-C**, використання **двох ІЧ-променів (інфрачервоних)** для фіксації польоту кульки.

🎯 **Можливості:**
- 📏 Вимірювання **швидкості кулі** (м/с)
- 💥 Розрахунок **енергії пострілу** (Дж)
- 🔫 Визначення **скорострільності** (пострілів за хвилину / RPM)
- 🧠 **Енергонезалежна пам'ять:** пристрій запам'ятовує останній обраний режим та вагу кульки після вимкнення живлення.
- ⚡ **Миттєвий розрахунок:** при пострілі система одночасно обчислює швидкість, енергію та скорострільність.

### 🔧 Керування
- 🔴 **Ліва кнопка (Кнопка 1)** — вмикає/вимикає ІЧ-промені.
- 🔵 **Права кнопка (Кнопка 2):**
    - **Коротке натискання** — перемикання між режимами відображення (Швидкість / Енергія / Скорострільність).
    - **Довге утримання** — перехід у режим **задання ваги кульки** (у грамах). 
    - **Вибір ваги:** доступні значення — **0.2г, 0.23г, 0.25г, 0.28г, 0.3г**.
    - **Збереження:** повторне довге утримання зберігає обрану вагу та повертає до основного режиму.

### ⚙️ Технічні характеристики

| Параметр          | Значення |
|-------------------|----------|
| Мікроконтролер    | STM8S103F3P6 |
| Живлення          | USB Type-C |
| Датчики           | 2 ІЧ-промені |
| Калібр            | 6 мм BB (страйкбол) |

### 📂 Структура проєкту
- **Altium** — принципова схема та плата (Altium Designer).
- **VsCode** — середовище розробки (C, COSMIC, stm8flash, ST-LINK).

✍️ **Автор:** Матвій Шульга

---

## 🇬🇧 English

### 📌 Project description
Chronograph for 6 mm airsoft BBs based on **STM8S103F3P6** microcontroller.  
Powered via **USB Type-C**, uses **two IR (Infrared) beams** to detect BB flight.

🎯 **Features:**
- 📏 Measure **BB velocity** (m/s)
- 💥 Calculate **shot energy** (Joules)
- 🔫 Measure **rate of fire** (rounds per minute / RPM)
- 🧠 **Non-volatile memory:** the device remembers the last measurement mode and BB weight setting after power off.
- ⚡ **Instant calculation:** a single shot triggers simultaneous calculation of velocity, energy, and rate of fire.

### 🔧 Controls
- 🔴 **Left Button (Button 1)** — IR beams power on/off.
- 🔵 **Right Button (Button 2):**
    - **Short press** — toggles between display modes (Velocity / Energy / Rate of Fire).
    - **Long hold** — enters **BB weight setting mode** (in grams).
    - **Weight presets:** **0.2g, 0.23g, 0.25g, 0.28g, 0.3g**.
    - **Saving:** long hold again to save the selected weight and return to the measurement mode.

### ⚙️ Technical specifications

| Parameter         | Value |
|-------------------|-------|
| Microcontroller   | STM8S103F3P6 |
| Power supply      | USB Type-C |
| Sensors           | 2 IR beams |
| Caliber           | 6 mm BBs |

### 📂 Project structure
- **Altium** — schematics and PCB (Altium Designer).
- **VsCode** — development environment (C, COSMIC, stm8flash, ST-LINK).

✍️ **Developed by:** Matvei Shulga