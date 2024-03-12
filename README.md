# Minitalk

Welcome to Minitalk! This project focuses on creating a simple client-server communication system using signals in Unix-based systems. By implementing this project, you'll gain a deeper understanding of interprocess communication (IPC) and signal handling in C programming.

## Table of Contents

1. [Introduction](#introduction)
2. [Usage](#usage)
3. [Protocol](#protocol)
4. [Building](#building)
5. [Contributing](#contributing)
6. [Credits](#credits)

## Introduction

In this project, you'll implement a client-server system where the server receives messages from the client and displays them on the standard output. The communication between the client and server will be achieved using signals. The client will send ASCII-encoded messages to the server, which will decode and display them.

## Usage

To use Minitalk, follow these steps:

1. Clone the repository:

    ```bash
    git clone https://github.com/yourusername/minitalk.git
    ```

2. Build the server and client executables:

    ```bash
    make
    ```

3. Start the server:

    ```bash
    ./server
    ```

4. In another terminal window, start the client with the server's process ID (PID) as an argument:

    ```bash
    ./client <server_pid>
    ```

5. Enter messages in the client terminal, and they will be displayed on the server terminal.

## Protocol

Minitalk uses a simple protocol for communication between the client and server. Each message consists of a series of ASCII-encoded characters followed by a null terminator ('\0'). The client sends each character of the message as an individual signal to the server, which decodes and displays the message on the standard output.

## Building

To build the Minitalk server and client, simply run:

```bash
make
```

## Contributing
Contributions are welcome! If you find any bugs or have suggestions for improvement, please open an issue or submit a pull request on GitHub.

## Credits
This project was created by adrgonza for the minitalk project at 42Madrid.
