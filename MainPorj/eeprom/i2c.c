#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#include <linux/i2c.h>
#include <linux/i2c-dev.h>

#include <i2c.h>

int i2c_fd;
unsigned int i2c_slave_addr = 0x50;

/*
 * I2C read
 * @fd: file handler
 * @addr: i2c slave 7-bit address
 * @offset: read position.
 * @buf: buffer for reading data.
 * @len: length for reading.
 *
 * @return: the number of i2c_msg has read. 
 *          succeed is 2.
 */
int I2CBus_packetRead(int fd, unsigned char addr, unsigned char offset,
                             unsigned char *buf, unsigned char len)
{
    unsigned char tmpaddr[2];
    struct i2c_msg msgs[2];
    struct i2c_rdwr_ioctl_data msgset;
    int rc;

    tmpaddr[0]     = offset;
    msgs[0].addr   = addr & 0xfe;
    msgs[0].flags  = I2C_M_WR;
    msgs[0].len    = 1;
    msgs[0].buf    = tmpaddr;

    msgs[1].addr   = addr & 0xfe;
    msgs[1].flags  = I2C_M_RD;  ;
    msgs[1].len    = len;
    msgs[1].buf    = buf;

    msgset.msgs    = msgs;
    msgset.nmsgs   = 2;

    rc = ioctl(fd, I2C_RDWR, &msgset);
    return rc;
}

/* 
 * I2C write
 * @fd: file handler.
 * @addr: i2c slave 7-bit address
 * @offset: write position
 * @buf: buffer for writuing data.
 * @len: the length for writing
 *
 * @return: the number of i2c_msg has write.
 *          succeed is 1.
 */
int I2CBus_packetWrite(int fd, unsigned char addr, unsigned char offset,
                              unsigned char *buf, unsigned char len)
{
    unsigned char tmpaddr[2];
    struct i2c_msg msgs[2];
    struct i2c_rdwr_ioctl_data msgset;
    int rc;

    tmpaddr[0]     = offset;
    tmpaddr[1]     = buf[0];
    msgs[0].addr   = addr & 0xfe;
    msgs[0].flags  = I2C_M_WR;
    msgs[0].len    = 2;
    msgs[0].buf    = tmpaddr;

    msgset.msgs    = msgs;
    msgset.nmsgs   = 1;

    rc = ioctl(fd, I2C_RDWR, &msgset);
    return rc;
}

/*
 * Open I2C device
 */
void open_i2c_device(void)
{
    i2c_fd = open(I2C_DEV_CHIP, O_RDWR);
    if (i2c_fd < 0) {
        printf("Can't open I2C device: %s\n", I2C_DEV_CHIP);
        exit(1);
    }
}

/*
 * Close I2C device
 */
void close_i2c_device(void)
{
    close(i2c_fd);
}

/*
 * I2C write command entry 
 */
void aup_write_common(int fd, unsigned char addr, unsigned char offset,
                             unsigned char *buf, unsigned char len)
{
    int err;
    int i;

    for (i = 0; i < len; i++) {
        int local_offset = offset + i;

        err = I2CBus_packetWrite(fd, addr, local_offset, &buf[i], 1);
        usleep(4000);
        if (err != 1) {
            printf("Can't write data to %02x\n", local_offset);
            exit(1);
        }
    }
}

/* 
 * I2c read common function 
 */
void aup_read_common(int fd, unsigned char addr, unsigned char offset,
                              unsigned char *buf, unsigned char len)
{
    int err;
    int i;

    for (i = 0; i < len; i++) {
        int local_offset = offset + i;

        err = I2CBus_packetRead(fd, addr, local_offset, &buf[i], 1);
        if (err != 2) {
            printf("Can't read data from %02x\n", local_offset);
            exit(1);
        }
    }
}
