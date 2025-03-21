/**
 * @file peripheral_config.h
 * @brief 
 * 
 * Copyright (c) 2021 Bouffalolab team
 * 
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 * 
 *   http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 * 
 */

#ifndef _PERIPHERAL_CONFIG_H_
#define _PERIPHERAL_CONFIG_H_

/* PERIPHERAL USING LIST */
// #define BSP_USING_ADC0
// #define BSP_USING_DAC0
#define BSP_USING_UART0
#define BSP_USING_UART1
// #define BSP_USING_SPI0
// #define BSP_USING_I2C0
// #define BSP_USING_I2S0
#define BSP_USING_USB
// #define BSP_USING_PWM_CH2
/* ----------------------*/

/* PERIPHERAL With DMA LIST */

#define BSP_USING_DMA0_CH0
#define BSP_USING_DMA0_CH1

#ifdef BSP_USING_UART1
#define BSP_USING_DMA0_CH2
#endif

#ifdef BSP_USING_SPI0
#define BSP_USING_DMA0_CH3
#define BSP_USING_DMA0_CH4
#endif

#ifdef BSP_USING_I2S0
#define BSP_USING_DMA0_CH2
#endif

#ifdef BSP_USING_DAC0
#define BSP_USING_DMA0_CH6
#endif

/* PERIPHERAL CONFIG */
#if defined(BSP_USING_ADC0)
#ifndef ADC_CONFIG
#define ADC_CONFIG                                      \
    {                                                   \
        .clk = ADC_CLK_500KHZ,                          \
        .vref = ADC_VREF_3P2V,                          \
        .resWidth = ADC_DATA_WIDTH_16_WITH_256_AVERAGE, \
    }
#endif
#endif

#if defined(BSP_USING_DAC0)
#ifndef DAC_CONFIG
#define DAC_CONFIG                   \
    {                                \
        .clk = DAC_CLK_500KHZ,       \
        .pin.dac0 = GLB_GPIO_PIN_11, \
        .pin.pin_num = 1,            \
    }
#endif
#endif

#if defined(BSP_USING_UART0)
#ifndef UART0_CONFIG
#define UART0_CONFIG                 \
    {                                \
        .id = 0,                     \
        .baudrate = 2000000,         \
        .databits = UART_DATA_LEN_8, \
        .stopbits = UART_STOP_ONE,   \
        .parity = UART_PAR_NONE,     \
        .fifo_threshold = 64,         \
    }
#endif
#endif

#if defined(BSP_USING_UART1)
#ifndef UART1_CONFIG
#define UART1_CONFIG                 \
    {                                \
        .id = 1,                     \
        .baudrate = 2000000,         \
        .databits = UART_DATA_LEN_8, \
        .stopbits = UART_STOP_ONE,   \
        .parity = UART_PAR_NONE,     \
        .fifo_threshold = 64,        \
    }
#endif
#endif

#if defined(BSP_USING_SPI0)
#ifndef SPI0_CONFIG
#define SPI0_CONFIG                                 \
    {                                               \
        .id = 0,                                    \
        .clk = 36000000,                            \
        .mode = SPI_MASTER_MODE,                    \
        .direction = SPI_MSB_BYTE0_DIRECTION_FIRST, \
        .clk_polaraity = SPI_POLARITY_LOW,          \
        .clk_phase = SPI_PHASE_1EDGE,               \
        .datasize = SPI_DATASIZE_8BIT,              \
        .fifo_threshold = 4,                        \
    }
#endif
#endif

#if defined(BSP_USING_PWM_CH2)
#ifndef PWM_CH2_CONFIG
#define PWM_CH2_CONFIG        \
    {                         \
        .ch = 2,              \
        .frequency = 1000000, \
        .dutycycle = 0,       \
    }
#endif
#endif

#if defined(BSP_USING_I2S0)
#ifndef I2S0_CONFIG
#define I2S0_CONFIG                              \
    {                                            \
        .id = 0,                                 \
        .iis_mode = I2S_MODE_MASTER,             \
        .interface_mode = I2S_MODE_LEFT,         \
        .sampl_freq_hz = 16 * 1000,              \
        .channel_num = I2S_FS_CHANNELS_NUM_MONO, \
        .frame_size = I2S_FRAME_LEN_16,          \
        .data_size = I2S_DATA_LEN_16,            \
        .fifo_threshold = 8,                     \
    }
#endif
#endif

#if defined(BSP_USING_DMA0_CH0)
#ifndef DMA0_CH0_CONFIG
#define DMA0_CH0_CONFIG                            \
    {                                              \
        .id = 0,                                   \
        .ch = 0,                                   \
        .direction = DMA_MEMORY_TO_MEMORY,         \
        .transfer_mode = DMA_LLI_ONCE_MODE,        \
        .src_req = DMA_REQUEST_NONE,               \
        .dst_req = DMA_REQUEST_NONE,               \
        .src_addr_inc = DMA_ADDR_INCREMENT_ENABLE, \
        .dst_addr_inc = DMA_ADDR_INCREMENT_ENABLE, \
        .src_burst_size = DMA_BURST_4BYTE,         \
        .dst_burst_size = DMA_BURST_4BYTE,         \
        .src_width = DMA_TRANSFER_WIDTH_32BIT,     \
        .dst_width = DMA_TRANSFER_WIDTH_32BIT,     \
    }
#endif
#endif

#if defined(BSP_USING_DMA0_CH1)
#ifndef DMA0_CH1_CONFIG
#define DMA0_CH1_CONFIG                            \
    {                                              \
        .id = 0,                                   \
        .ch = 1,                                   \
        .direction = DMA_MEMORY_TO_MEMORY,         \
        .transfer_mode = DMA_LLI_ONCE_MODE,        \
        .src_req = DMA_REQUEST_NONE,               \
        .dst_req = DMA_REQUEST_NONE,               \
        .src_addr_inc = DMA_ADDR_INCREMENT_ENABLE, \
        .dst_addr_inc = DMA_ADDR_INCREMENT_ENABLE, \
        .src_burst_size = DMA_BURST_4BYTE,         \
        .dst_burst_size = DMA_BURST_4BYTE,         \
        .src_width = DMA_TRANSFER_WIDTH_16BIT,     \
        .dst_width = DMA_TRANSFER_WIDTH_16BIT,     \
    }
#endif
#endif

#if defined(BSP_USING_DMA0_CH2)
#ifndef DMA0_CH2_CONFIG
#define DMA0_CH2_CONFIG                             \
    {                                               \
        .id = 0,                                    \
        .ch = 2,                                    \
        .direction = DMA_MEMORY_TO_PERIPH,          \
        .transfer_mode = DMA_LLI_ONCE_MODE,         \
        .src_req = DMA_REQUEST_NONE,                \
        .dst_req = DMA_REQUEST_UART1_TX,            \
        .src_addr_inc = DMA_ADDR_INCREMENT_ENABLE,  \
        .dst_addr_inc = DMA_ADDR_INCREMENT_DISABLE, \
        .src_burst_size = DMA_BURST_1BYTE,          \
        .dst_burst_size = DMA_BURST_1BYTE,          \
        .src_width = DMA_TRANSFER_WIDTH_8BIT,       \
        .dst_width = DMA_TRANSFER_WIDTH_8BIT,       \
    }
#endif
#endif

#if defined(BSP_USING_DMA0_CH3)
#ifndef DMA0_CH3_CONFIG
#define DMA0_CH3_CONFIG                             \
    {                                               \
        .id = 0,                                    \
        .ch = 3,                                    \
        .direction = DMA_MEMORY_TO_PERIPH,          \
        .transfer_mode = DMA_LLI_ONCE_MODE,         \
        .src_req = DMA_REQUEST_NONE,                \
        .dst_req = DMA_REQUEST_SPI0_TX,             \
        .src_addr_inc = DMA_ADDR_INCREMENT_ENABLE,  \
        .dst_addr_inc = DMA_ADDR_INCREMENT_DISABLE, \
        .src_burst_size = DMA_BURST_1BYTE,          \
        .dst_burst_size = DMA_BURST_1BYTE,          \
        .src_width = DMA_TRANSFER_WIDTH_8BIT,       \
        .dst_width = DMA_TRANSFER_WIDTH_8BIT,       \
    }
#endif
#endif

#if defined(BSP_USING_DMA0_CH4)
#ifndef DMA0_CH4_CONFIG
#define DMA0_CH4_CONFIG                             \
    {                                               \
        .id = 0,                                    \
        .ch = 4,                                    \
        .direction = DMA_PERIPH_TO_MEMORY,          \
        .transfer_mode = DMA_LLI_ONCE_MODE,         \
        .src_req = DMA_REQUEST_SPI0_RX,             \
        .dst_req = DMA_REQUEST_NONE,                \
        .src_addr_inc = DMA_ADDR_INCREMENT_DISABLE, \
        .dst_addr_inc = DMA_ADDR_INCREMENT_ENABLE,  \
        .src_burst_size = DMA_BURST_1BYTE,          \
        .dst_burst_size = DMA_BURST_1BYTE,          \
        .src_width = DMA_TRANSFER_WIDTH_8BIT,       \
        .dst_width = DMA_TRANSFER_WIDTH_8BIT,       \
    }
#endif
#endif

#if defined(BSP_USING_DMA0_CH5)
#ifndef DMA0_CH5_CONFIG
#define DMA0_CH5_CONFIG                             \
    {                                               \
        .id = 0,                                    \
        .ch = 5,                                    \
        .direction = DMA_MEMORY_TO_PERIPH,          \
        .transfer_mode = DMA_LLI_CYCLE_MODE,        \
        .src_req = DMA_REQUEST_NONE,                \
        .dst_req = DMA_REQUEST_I2S_TX,              \
        .src_addr_inc = DMA_ADDR_INCREMENT_ENABLE,  \
        .dst_addr_inc = DMA_ADDR_INCREMENT_DISABLE, \
        .src_burst_size = DMA_BURST_1BYTE,          \
        .dst_burst_size = DMA_BURST_1BYTE,          \
        .src_width = DMA_TRANSFER_WIDTH_16BIT,      \
        .dst_width = DMA_TRANSFER_WIDTH_16BIT,      \
    }
#endif
#endif

#if defined(BSP_USING_DMA0_CH6)
#ifndef DMA0_CH6_CONFIG
#define DMA0_CH6_CONFIG                             \
    {                                               \
        .id = 0,                                    \
        .ch = 6,                                    \
        .direction = DMA_MEMORY_TO_PERIPH,          \
        .transfer_mode = DMA_LLI_CYCLE_MODE,        \
        .src_req = DMA_REQUEST_NONE,                \
        .dst_req = DMA_REQUEST_I2S_TX,              \
        .src_addr_inc = DMA_ADDR_INCREMENT_ENABLE,  \
        .dst_addr_inc = DMA_ADDR_INCREMENT_DISABLE, \
        .src_burst_size = DMA_BURST_1BYTE,          \
        .dst_burst_size = DMA_BURST_1BYTE,          \
        .src_width = DMA_TRANSFER_WIDTH_16BIT,      \
        .dst_width = DMA_TRANSFER_WIDTH_16BIT,      \
    }
#endif
#endif

#if defined(BSP_USING_DMA0_CH7)
#ifndef DMA0_CH7_CONFIG
#define DMA0_CH7_CONFIG                            \
    {                                              \
        .id = 0,                                   \
        .ch = 7,                                   \
        .direction = DMA_MEMORY_TO_MEMORY,         \
        .transfer_mode = DMA_LLI_ONCE_MODE,        \
        .src_req = DMA_REQUEST_NONE,               \
        .dst_req = DMA_REQUEST_NONE,               \
        .src_addr_inc = DMA_ADDR_INCREMENT_ENABLE, \
        .dst_addr_inc = DMA_ADDR_INCREMENT_ENABLE, \
        .src_burst_size = DMA_BURST_1BYTE,         \
        .dst_burst_size = DMA_BURST_1BYTE,         \
        .src_width = DMA_TRANSFER_WIDTH_32BIT,     \
        .dst_width = DMA_TRANSFER_WIDTH_32BIT,     \
    }
#endif
#endif

#if defined(BSP_USING_I2C0)
#ifndef I2C0_CONFIG
#define I2C0_CONFIG          \
    {                        \
        .id = 0,             \
        .mode = I2C_HW_MODE, \
        .phase = 15,         \
    }
#endif
#endif

#endif
