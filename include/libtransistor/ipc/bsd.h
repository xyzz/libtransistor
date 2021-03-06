#pragma once

#include<libtransistor/types.h>

extern result_t bsd_result;
extern int      bsd_errno;

struct sockaddr;
typedef uint32_t socklen_t;

struct in_addr {
  uint32_t s_addr;
};

struct sockaddr_in {
  uint16_t sin_family;
  uint16_t sin_port;
  struct in_addr sin_addr;
  uint8_t pad[8]; // struct size has to be 16
} __attribute__((packed));

result_t bsd_init();
int bsd_socket(int domain, int type, int protocol);
int bsd_recv(int socket, void *message, size_t length, int flags);
int bsd_send(int socket, const void *data, size_t length, int flags);
int bsd_sendto(int socket, const void *message, size_t length, int flags, const struct sockaddr *dest_addr, socklen_t dest_len);
int bsd_accept(int socket, struct sockaddr *restrict address, socklen_t *restrict address_len);
int bsd_bind(int socket, const struct sockaddr *address, socklen_t address_len);
int bsd_connect(int socket, const struct sockaddr *address, socklen_t address_len);
int bsd_getsockname(int socket, struct sockaddr *restrict address, socklen_t *restrict address_len);
int bsd_listen(int socket, int backlog);
int bsd_setsockopt(int socket, int level, int option_name, const void *option_value, socklen_t option_len);
int bsd_shutdown(int socket, int how);
int bsd_close(int socket);
void bsd_finalize();
