#include "I2C.h"


/*! @note Exposed objects for i2c-x */
I2C_DeviceT I2C_DEV_2;

int
I2C::Open_device(char *i2c_dev_path, int *fd)
{
	if((*fd = open(i2c_dev_path, O_RDWR))<0)
		return -1;
	else
		return 0;
}

int
I2C::Close_device(int fd)
{
	if(close(fd) == -1)
		return -1;
	else
		return 0;
}

int
I2C::Set_slave_addr(int fd, unsigned char slave_addr)
{
	if(ioctl(fd, I2C_SLAVE, slave_addr) < 0)
		return -1;
	else
		return 0;
}

int
I2C::i2c_write(int fd, unsigned char data)
{
	int ret = 0;
	ret = write(fd, &data, I2C_ONE_BYTE);
	if((ret == -1) || (ret != 1))
		return -1;
	else
		return(ret);
}

int
I2C::i2c_read(int fd, unsigned char *read_data)
{
	int ret = 0;
	ret = read(fd, &read_data, I2C_ONE_BYTE);
	if(ret == -1)
		perror("I2C: Failed to read |");
	if(ret == 0)
		perror("I2C: End of FILE |");
	return(ret);
}

int
I2C::i2c_read_register(int fd,
                       unsigned char read_addr,
                       unsigned char *read_data)
{
	int ret = 0;
	if(i2c_write(fd, read_addr) == -1)
	{
		perror("I2C: Failed to write |");
		return -1;
	}
	ret = read(fd, read_data, I2C_ONE_BYTE);
	if(ret == -1)
		perror("I2C: Failed to read |");
	if(ret == 0)
		perror("I2C: End of FILE |");
	return(ret);
}

int
I2C::i2c_read_registers(int fd,
                        int num,
                        unsigned char starting_addr,
                        unsigned char *buff_Ptr)
{
	int ret = 0;
	if(i2c_write(fd, starting_addr) == -1)
	{
		perror("I2C: Failed to write |");
		return -1;
	}
	ret = read(fd, buff_Ptr, num);
	if(ret == -1)
		perror("I2C: Failed to read |");
	if(ret == 0)
		perror("I2C: End of FILE |");
	return(ret);
}

int
I2C::i2c_multiple_writes(int fd,
                         int num,
                         unsigned char *Ptr_buff)
{
	int ret = 0;
	ret = write(fd, Ptr_buff, num);
	if((ret == -1) || (ret != num))
		return -1;
	else
		return(ret);
}

int
I2C::i2c_write_register(int fd,
                        unsigned char reg_addr_or_cntrl,
                        unsigned char val)
{
	unsigned char buff[1];
	int ret = 0;
	buff[0] = reg_addr_or_cntrl;
	buff[1] = val;
	ret = write(fd, buff, I2C_TWO_BYTES);
	if((ret == -1) || (ret != I2C_TWO_BYTES))
		return -1;
	else
		return(ret);
}

void
I2C::config_i2c_struct(char *i2c_dev_path,
                       unsigned char slave_addr,
                       I2C_DevicePtr i2c_dev)
{
	i2c_dev->i2c_dev_path = i2c_dev_path;
	i2c_dev->fd_i2c = 0;
	i2c_dev->i2c_slave_addr = slave_addr;
}

int
I2C::init_i2c_dev2(unsigned char slave_address)
{
	config_i2c_struct(I2C_DEV2_PATH, slave_address, &I2C_DEV_2);
	if(Open_device(I2C_DEV_2.i2c_dev_path, &I2C_DEV_2.fd_i2c) == -1)
	{
		perror("I2C: Failed to open device |");
		return -1;
	}
	if(Set_slave_addr(I2C_DEV_2.fd_i2c, I2C_DEV_2.i2c_slave_addr) == -1)
	{
		perror("I2C: Failed to connect to slave device |");
		return -1;
	}

	return 0;
}

void
I2C::write_byte(char mode, char byte)
{

}

int
I2C::read_byte(uint8_t byte)
{
    int ret = 0;
    return ret;
}
