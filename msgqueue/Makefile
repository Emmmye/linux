.PHONY:all
all:client server
client:client.c common.c
	gcc -o $@ -g $^
server:server.c common.c
	gcc -o $@ -g $^
.PHONY:clean
clean:
	rm -rf client server 
