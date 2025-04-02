# Simple TCP/UDP Networking Exercise (C)

---

## Project Description

This is a basic networking exercise implemented in C, showing minimal working examples of both **TCP** and **UDP** communication using **sockets**. It includes:

- A TCP client-server pair
- A UDP client-server pair

Each client sends a message, and the server replies. This example is designed for educational or testing purposes.

---

## 🧩 TCP Communication

### TCP Server (port 4321)
- Waits for a connection
- Reads incoming message from client
- Prints the message
- Sends a fixed response

**Compile:**
```bash
gcc -o tcp_server tcp_server.c
```

**Run:**
```bash
./tcp_server
```

### TCP Client
**Usage:**
```bash
./tcp_client <IP_ADDRESS> <PORT>
```
Example:
```bash
./tcp_client 127.0.0.1 4321
```

Sends: `wysylam`  
Receives: `odbieram`

**Compile:**
```bash
gcc -o tcp_client tcp_client.c
```

---

## 🧩 UDP Communication

### UDP Server (port 1212)
- Listens for incoming datagrams
- Responds to each with a fixed string

**Compile:**
```bash
gcc -o udp_server udp_server.c
```

**Run:**
```bash
./udp_server
```

### UDP Client
**Usage:**
```bash
./udp_client <IP_ADDRESS> <PORT>
```
Example:
```bash
./udp_client 127.0.0.1 1212
```

Sends: `wysylam`  
Receives: `odbieram`

**Compile:**
```bash
gcc -o udp_client udp_client.c
```

---

## Notes
- This code is intentionally simple, meant for learning and testing only.
- Contains minimal error handling.
- Uses basic system calls: `socket`, `bind`, `accept`, `connect`, `recvfrom`, `sendto`, etc.
- The language used in messages is vulgar (for humor/testing); please adjust for production or public use.

---

## Improvements (Optional)
- Add argument-based message passing
- Improve buffer size checks and error handling
- Use select/poll/epoll for concurrent client handling
- Handle multiple TCP clients in threads or with `fork()`

---

This setup is perfect for hands-on practice before an exam or lab involving sockets in C.

