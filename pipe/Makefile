all:writer reader
writer:writer.c
	gcc -o $@ $^
reader:reader.c
	gcc -o $@ $^
.PHONY:clean
clean:
	rm -f writer reader
