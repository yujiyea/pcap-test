all: pcap-test

pcap-test: printpacket.o main.o
	g++ -g -o pcap_test printpacket.o main.o -lpcap
	
printpacket.o:
	g++ -g -c -o printpacket.o printpacket.cpp
	
main.o:
	g++ -g -c -o main.o main.cpp

clean:
	rm -f pcap-test *.o
