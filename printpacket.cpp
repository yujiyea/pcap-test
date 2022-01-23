#include "printpacket.h"
#include <stdbool.h>
#include <netinet/in.h>

void get_ether(const u_char *packet)
{
    struct ethernet_hdr* eth_hdr = (struct ethernet_hdr*) packet;
    printf("----Ethernet Headers----\n");
    printf("Src Mac: %02x:%02x:%02x:%02x:%02x:%02x\n",eth_hdr->ether_src[0],eth_hdr->ether_src[1],eth_hdr->ether_src[2],eth_hdr->ether_src[3],eth_hdr->ether_src[4],eth_hdr->ether_src[5]);
    printf("Dst Mac: %02x:%02x:%02x:%02x:%02x:%02x\n",eth_hdr->ether_dst[0],eth_hdr->ether_dst[1],eth_hdr->ether_dst[2],eth_hdr->ether_dst[3],eth_hdr->ether_dst[4],eth_hdr->ether_dst[5]);
}

void get_ip(const u_char *packet)
{
    struct ip_hdr* ip_hdr = (struct ip_hdr*) packet;
    printf("----IP Headers----\n");
    printf("Src IP: %hhu.%hhu.%hhu.%hhu\n",ip_hdr->ip_src[0],ip_hdr->ip_src[1],ip_hdr->ip_src[2],ip_hdr->ip_src[3]);
    printf("Dst IP: %hhu.%hhu.%hhu.%hhu\n",ip_hdr->ip_dst[0],ip_hdr->ip_dst[1],ip_hdr->ip_dst[2],ip_hdr->ip_dst[3]);
}

void get_tcp(const u_char *packet)
{
    struct tcp_hdr* tcp_hdr = (struct tcp_hdr*) packet;
    printf("----TCP Headers----\n");
    printf("Src Port: %d\n",ntohs(tcp_hdr->tcp_src));
    printf("Dst Port: %d\n",ntohs(tcp_hdr->tcp_dst));
}

void get_payload(const u_char *packet)
{
    struct payload* payload = (struct payload*) packet;
    printf("----Payload----\n");
    //int size =
    for(int i=0;i<8;i++){
        printf("%02hhx ",payload->payload[i]);
    }
    printf("\n");
}

void capture_tcp(const u_char *packet)
{
    get_ether(packet);
    packet= packet+sizeof(struct ethernet_hdr);
    get_ip(packet);
    packet = packet+sizeof(struct ip_hdr);
    get_tcp(packet);
    packet = packet+sizeof(struct tcp_hdr);
    get_payload(packet);
    return;
}
