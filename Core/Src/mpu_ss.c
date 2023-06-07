
#include "mpu_ss.h"
#include "math.h"

// Setup MPU6050
const uint16_t i2c_timeout = 100;
const double Accel_Z_corrector = 14418.0;

uint16_t accX;
uint16_t accY;
uint16_t accZ;

uint16_t Gx;
uint16_t Gy;
uint16_t Gz;

void MPU6050_Init(I2C_HandleTypeDef *I2Cx) {
    uint8_t check;
    uint8_t Data;
    HAL_I2C_Mem_Read(I2Cx, MPU6050_ADDR, WHO_AM_I_REG, 1, &check, 1, i2c_timeout);
    if (check == 104){
        Data = 0;
        HAL_I2C_Mem_Write(I2Cx, MPU6050_ADDR, PWR_MGMT_1_REG, 1, &Data, 1, i2c_timeout);
        Data = 0x07;
        HAL_I2C_Mem_Write(I2Cx, MPU6050_ADDR, SMPLRT_DIV_REG, 1, &Data, 1, i2c_timeout);
        Data = 0x00;
        HAL_I2C_Mem_Write(I2Cx, MPU6050_ADDR, ACCEL_CONFIG_REG, 1, &Data, 1, i2c_timeout);
        Data = 0x00;
        HAL_I2C_Mem_Write(I2Cx, MPU6050_ADDR, GYRO_CONFIG_REG, 1, &Data, 1, i2c_timeout);
    }
}

void MPU6050_Read_Accel(I2C_HandleTypeDef *I2Cx){
    uint8_t Data[6];
    HAL_I2C_Mem_Read(I2Cx, MPU6050_ADDR, ACCEL_XOUT_H_REG, 1, Data, 6, i2c_timeout);
    accX = (int16_t)(Data[0] << 8 | Data[1]);
    accY = (int16_t)(Data[2] << 8 | Data[3]);
    accZ = (int16_t)(Data[4] << 8 | Data[5]);
}

void MPU6050_Read_Gyro(I2C_HandleTypeDef *I2Cx){
    uint8_t Data[6];
    HAL_I2C_Mem_Read(I2Cx, MPU6050_ADDR, GYRO_XOUT_H_REG, 1, Data, 6, i2c_timeout);
    Gx = (int16_t)(Data[0] << 8 | Data[1]);
    Gy = (int16_t)(Data[2] << 8 | Data[3]);
    Gz = (int16_t)(Data[4] << 8 | Data[5]);
}

double MPUgetValue(I2C_HandleTypeDef *I2Cx) {
	uint8_t Data[6];
	HAL_I2C_Mem_Read(I2Cx, MPU6050_ADDR, ACCEL_XOUT_H_REG, 1, Data, 6, i2c_timeout);
	accX = (int16_t)(Data[0] << 8 | Data[1]);
	accY = (int16_t)(Data[2] << 8 | Data[3]);
	accZ = (int16_t)(Data[4] << 8 | Data[5]);
	double value = 1.0*accX*accX + 1.0*accY*accY + 1.0*accZ*accZ;
	value = sqrt(value);
	return value;
}
uint16_t MPUgetX(I2C_HandleTypeDef *I2Cx) {
	uint8_t Data[2];
	HAL_I2C_Mem_Read(I2Cx, MPU6050_ADDR, ACCEL_XOUT_H_REG, 1, Data, 6, i2c_timeout);
	return (int16_t)(Data[0] << 8 | Data[1]);
}

uint16_t MPUgetY(I2C_HandleTypeDef *I2Cx) {
	uint8_t Data[2];
	HAL_I2C_Mem_Read(I2Cx, MPU6050_ADDR, ACCEL_YOUT_H_REG, 1, Data, 6, i2c_timeout);
	return (int16_t)(Data[0] << 8 | Data[1]);
}

uint16_t MPUgetZ(I2C_HandleTypeDef *I2Cx) {
	uint8_t Data[2];
	HAL_I2C_Mem_Read(I2Cx, MPU6050_ADDR, ACCEL_ZOUT_H_REG, 1, Data, 6, i2c_timeout);
	return (int16_t)(Data[0] << 8 | Data[1]);
}
