# Embedded Battleship

Welcome to the **Embedded Battleship** repository! This project implements the classic game of Battleship on an embedded system, combining low-level programming techniques with fun, strategic gameplay.

## Features

- **Real-Time Gameplay**: Play Battleship in a real-time environment designed for embedded systems.
- **LCD Display Integration**: A clear and intuitive interface displayed on an LCD.
- **Button Inputs**: Navigate and control the game using physical buttons.
- **Audio Feedback**: Enjoy sound effects for hits, misses, and other game events.
- **Modular Design**: Easy to adapt to different hardware platforms.

## Getting Started

### Prerequisites

- **Microcontroller/Embedded Board**: Ensure your hardware supports the required peripherals (e.g., LCD, buttons, buzzer).
- **Development Environment**: Install an IDE or toolchain compatible with your microcontroller (e.g., Keil, MPLAB X, or GCC).
- **Connections**: Connect the necessary peripherals (LCD, buttons, etc.) as specified in the `hardware/` documentation.

### Setup

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/AaronYangello/embedded-battleship.git
   ```
2. **Configure the Project**:
   - Update hardware configurations  to match your setup.
   - Check pin assignments and peripheral settings.
3. **Build and Flash**:
   - Compile the code using your chosen IDE/toolchain.
   - Flash the binary to your embedded device.
4. **Run**:
   - Power up the system and start playing!

### Controls

- **Arrow Buttons**: Move the cursor on the grid.
- **Select Button**: Place ships or confirm an attack.
- **Reset Button**: Restart the game.

## How to Play

1. **Place Ships**: Arrange your fleet on your grid using the controls.
2. **Take Turns**: Guess your opponent’s ship positions and mark hits/misses.
3. **Win**: Sink all of your opponent’s ships before they sink yours.

## License

This project is licensed under the [MIT License](LICENSE). You are free to use, modify, and distribute the software as long as the original license is included.

## Acknowledgments

- Inspired by the classic Battleship board game.
- Special thanks to the open-source community for tools and libraries.