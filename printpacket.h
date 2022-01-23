#ifndef PRINTPACKET_H
#define PRINTPACKET_H
#endif // PRINTPACKET_H

#include <pcap.h>

struct ethernet_hdr{
    u_int8_t ether_dst[6];
    u_int8_t ether_src[6];
    u_int16_t ether_type;
};
struct ip_hdr{
    u_int8_t version;
    u_int8_t ip_tos;
    u_int16_t ip_len;
    u_int16_t ip_ident;
    u_int16_t ip_off;
    u_int8_t ip_time;
    u_int8_t ip_pro;
    u_int16_t ip_check;
    u_int8_t ip_src[4];
    u_int8_t ip_dst[4];
};
struct tcp_hdr{
    u_int16_t tcp_src;
    u_int16_t tcp_dst;
    u_int32_t tcp_seq;
    u_int32_t tcp_ack;
    u_int8_t tcp_flags;
    u_int16_t tcp_win;
    u_int16_t tcp_check;
    u_int16_t tcp_urg;
};
struct payload{
    char payload[8];
};

void get_ether(const u_char* packet);
void get_ip(const u_char* packet);
void get_tcp(const u_char* packet);
void get_payload(struct payload);
void capture_tcp(const u_char* packet);//final
