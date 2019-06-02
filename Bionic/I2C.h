#ifndef I2C_H_
#define I2C_H_

#include<stdio.h>
#include<fcntl.h>
#include<sys/ioctl.h>
#include<linux/i2c.h>
#include<linux/i2c-dev.h>

#include<stdint.h>

/* No. of bytes per transaction */
#define I2C_ONE_BYTE                     1
#define I2C_TWO_BYTES                    2
#define I2C_THREE_BYTES                  3

/*Definitions specific to i2c-x */
#define I2C_DEV0_PATH                     "/dev/i2c-0"
#define I2C_DEV2_PATH                     "/dev/i2c-2"

/*I2C device configuration structure*/
typedef struct{
	char* i2c_dev_path;
	int fd_i2c;
	unsigned char i2c_slave_addr;
}I2C_DeviceT, *I2C_DevicePtr;

class I2C {
public:
    I2C(int bus, int address);
    void write_byte(char mode, char byte);
    int read_byte(uint8_t byte);

private:
    int Open_device(char *i2c_dev_path, int *fd);
    int Close_device(int fd);
    int Set_slave_addr(int fd, unsigned char slave_addr);
    int i2c_write(int fd, unsigned char data);
    int i2c_read(int fd, unsigned char *read_data);
    int i2c_read_register(int fd, unsigned char read_addr, unsigned char *read_data);
    int i2c_read_registers(int fd, int num, unsigned char starting_addr,
                        unsigned char *buff_Ptr);
    void config_i2c_struct(char *i2c_dev_path, unsigned char slave_addr, I2C_DevicePtr i2c_dev);
    int i2c_multiple_writes(int fd, int num, unsigned char *Ptr_buff);
    int i2c_write_register(int fd, unsigned char reg_addr_or_cntrl, unsigned char val);

    int init_i2c_dev2(unsigned char slave_address);
};
#endif /* I2C_H_ */
