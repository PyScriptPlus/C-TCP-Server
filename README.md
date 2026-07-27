# C-TCP-Server

A simple TCP server implementation in **C** using the **POSIX Socket API**.

## Overview

This project demonstrates the fundamentals of **TCP server programming** using POSIX sockets on Linux.

The application creates a TCP socket, binds it to a local IPv4 address and port, listens for incoming client connections, accepts a connection request, and receives a text message over a reliable TCP connection.

This project is designed for educational purposes and serves as a foundation for learning socket programming in C.

---

## Project Structure

```text
C_TCP_Server/
│
└── main.c
```

---

## Technologies

### C

* POSIX Sockets
* `socket()`
* `bind()`
* `listen()`
* `accept()`
* `recv()`
* `sockaddr_in`
* `inet_addr()`
* `htons()`
* `close()`

---

## Communication

```text
+----------------------+          TCP           +----------------------+
| TCP Client           | --------------------> | C TCP Server         |
| Any TCP Client       |                       | Linux / POSIX        |
+----------------------+                       +----------------------+
```

Default configuration:

| Setting    | Value     |
| ---------- | --------- |
| Protocol   | TCP       |
| IP Address | 127.0.0.1 |
| Port       | 2525      |

---

## How It Works

1. Create a TCP socket.
2. Configure the server IPv4 address and port.
3. Bind the socket to the local address using `bind()`.
4. Put the socket into listening mode using `listen()`.
5. Wait for an incoming client connection using `accept()`.
6. Receive a text message from the connected client using `recv()`.
7. Close the client socket and the listening socket.

---

## Connection Flow

```text
socket()
    │
    ▼
bind()
    │
    ▼
listen()
    │
    ▼
accept()
    │
    ▼
recv()
    │
    ▼
close()
```
---

## Learning Goals

This project demonstrates:

* Basic TCP socket programming
* TCP server implementation
* IPv4 networking
* Connection-oriented communication
* POSIX Socket API
* Receiving data over TCP
* Client connection handling
* Basic server workflow

---

## Notes

* This project implements only the **server** side of a TCP connection.
* The server waits for a client to establish a connection before receiving data.
* The default configuration uses the loopback interface (`127.0.0.1`) for local testing.
* This example accepts a single client connection and receives a single message.
* The project focuses on understanding the fundamental TCP server workflow rather than building a production-ready server.

---

## Future Improvements

* Send responses back to the client
* Bidirectional communication
* Support multiple clients
* Multi-threaded server
* IPv6 support
* Better error handling
* Binary data transfer

---

## Related Projects

* [**Socket-Programming**](https://github.com/PyScriptPlus/Socket-Programming)
* [**TCP Client (C++)**](https://github.com/PyScriptPlus/Cpp-TCP-Client)
* [**UDP Example (C++ & C#)**](https://github.com/PyScriptPlus/Cpp-CSharp-UDP-Example)

---

## What is POSIX?

**POSIX (Portable Operating System Interface)** is a family of IEEE standards that defines a common programming interface for Unix-like operating systems.

This project uses the **POSIX Socket API**, including functions such as:

* `socket()`
* `bind()`
* `listen()`
* `accept()`
* `recv()`
* `close()`

Because these APIs are standardized, the same networking code can typically be compiled and run on many Unix-like operating systems with little or no modification, including:

* Linux
* macOS
* FreeBSD
* OpenBSD
* NetBSD

---
## Output:
<img width="2560" height="1440" alt="Image" src="https://github.com/user-attachments/assets/6e229162-10e2-4ce1-9192-d269ffa9bdee" />

---

## Thanks

**Mohammad Yousefi**
