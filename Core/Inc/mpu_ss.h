/*
 * mpu6050.h
 *
 *  Created on: Nov 13, 2019
 *      Author: Bulanov Konstantin
 */

#ifndef INC_GY521_H_
#define INC_GY521_H_

#endif /* INC_GY521_H_ */

#include <stdint.h>
#include "main.h"
//define Register
#define WHO_AM_I_REG 0x75
#define PWR_MGMT_1_REG 0x6B
#define SMPLRT_DIV_REG 0x19
#define ACCEL_CONFIG_REG 0x1C

#define ACCEL_XOUT_H_REG 0x3B
#define ACCEL_XOUT_L_REG 0x3C
#define ACCEL_YOUT_H_REG 0x3D
#define ACCEL_YOUT_L_REG 0x3E
#define ACCEL_ZOUT_H_REG 0x3F
#define ACCEL_ZOUT_L_REG 0x40

#define GYRO_CONFIG_REG 0x1B
#define GYRO_XOUT_H_REG 0x43
//define Sensor address
#define MPU6050_ADDR 0xD0

void MPU6050_Init(I2C_HandleTypeDef *I2Cx);
uint16_t MPUgetX(I2C_HandleTypeDef *I2Cx);
uint16_t MPUgetY(I2C_HandleTypeDef *I2Cx);
uint16_t MPUgetZ(I2C_HandleTypeDef *I2Cx);

void MPU6050_Read_Accel(I2C_HandleTypeDef *I2Cx);
void MPU6050_Read_Gyro(I2C_HandleTypeDef *I2Cx);

double MPUgetValue(I2C_HandleTypeDef *I2Cx);
