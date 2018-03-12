#ifndef _I2C_AUP_H
#define _I2C_AUP_H

#define I2C_M_WR        0

#define I2C_DEV_CHIP    "/dev/i2c-0"

extern int i2c_fd;
extern unsigned int i2c_slave_addr;

extern int I2CBus_packetRead(int fd, unsigned char addr, unsigned char offset,
                             unsigned char *buf, unsigned char len);
extern int I2CBus_packetWrite(int fd, unsigned char addr, unsigned char offset,
                              unsigned char *buf, unsigned char len);
extern void open_i2c_device(void);
extern void close_i2c_device(void);
extern void aup_write_common(int fd, unsigned char addr, unsigned char offset,
                             unsigned char *buf, unsigned char len);
extern void aup_read_common(int fd, unsigned char addr, unsigned char offset,
                              unsigned char *buf, unsigned char len);
#endif
