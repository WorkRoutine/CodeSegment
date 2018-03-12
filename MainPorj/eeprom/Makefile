CC=gcc
CFLAGS= -I./

OBJ= main.o command.o i2c.o parse.o

eeprom-cfg: $(OBJ)
	$(CC) $^ $(CFLAGS) -o $@

$(OBJ):

clean:
	rm eeprom-cfg $(OBJ)
