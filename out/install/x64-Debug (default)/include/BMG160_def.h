#pragma once
/***************************************************************/
/**\name    REGISTER ADDRESS DEFINITION        */
/***************************************************************/
/*******************************************/
/**\name    CHIP ID       */
/*******************************************/
#define BMG160_CHIP_ID_ADDR (0x00)

/**<Address of Chip ID Register*/
/*******************************************/
/**\name    DATA REGISTER       */
/*******************************************/
#define BMG160_RATE_X_LSB_ADDR (0x02)

/**<        Address of X axis Rate LSB Register       */
#define BMG160_RATE_X_MSB_ADDR (0x03)

/**<        Address of X axis Rate MSB Register       */
#define BMG160_RATE_Y_LSB_ADDR (0x04)

/**<        Address of Y axis Rate LSB Register       */
#define BMG160_RATE_Y_MSB_ADDR (0x05)

/**<        Address of Y axis Rate MSB Register       */
#define BMG160_RATE_Z_LSB_ADDR (0x06)

/**<        Address of Z axis Rate LSB Register       */
#define BMG160_RATE_Z_MSB_ADDR (0x07)

/**<        Address of Z axis Rate MSB Register       */
#define BMG160_TEMP_ADDR       (0x08)

/**<        Address of Temperature Data LSB Register  */
/*******************************************/
/**\name    STATUS REGISTER     */
/*******************************************/
#define BMG160_INTR_STAT0_ADDR (0x09)

/**<        Address of Interrupt status Register    */
#define BMG160_INTR_STAT1_ADDR (0x0A)

/**<        Address of Interrupt status Register     */
#define BMG160_INTR_STAT2_ADDR (0x0B)

/**<        Address of Interrupt status Register     */
#define BMG160_INTR_STAT3_ADDR (0x0C)

/**<        Address of Interrupt status Register     */
#define BMG160_FIFO_STAT_ADDR  (0x0E)

/**<        Address of FIFO status Register           */
/*******************************************/
/**\name    CONTROL REGISTER    */
/*******************************************/
#define BMG160_RANGE_ADDR        (0x0F)

/**<        Address of Range address Register     */
#define BMG160_BW_ADDR           (0x10)

/**<        Address of Bandwidth Register         */
#define BMG160_MODE_LPM1_ADDR    (0x11)

/**<        Address of Mode LPM1 Register         */
#define BMG160_MODE_LPM2_ADDR    (0x12)

/**<        Address of Mode LPM2 Register         */
#define BMG160_HIGH_BW_ADDR      (0x13)

/**<        Address of Rate HIGH_BW Register       */
#define BMG160_BGW_SOFT_RST_ADDR (0x14)

/**<        Address of BGW Softreset Register      */
/*******************************************/
/**\name    INTERRUPT STATUS REGISTERS    */
/*******************************************/
#define BMG160_INTR_ENABLE0_ADDR  (0x15)

/**<        Address of Interrupt Enable             */
#define BMG160_INTR_ENABLE1_ADDR  (0x16)

/**<        Address of Interrupt Enable             */
#define BMG160_INTR_MAP_ZERO_ADDR (0x17)

/**<        Address of Interrupt MAP                */
#define BMG160_INTR_MAP_ONE_ADDR  (0x18)

/**<        Address of Interrupt MAP                */
#define BMG160_INTR_MAP_TWO_ADDR  (0x19)

/**<        Address of Interrupt MAP                */
#define BMG160_INTR_ZERO_ADDR     (0x1A)

/**<        Address of Interrupt  register   */
#define BMG160_INTR_ONE_ADDR      (0x1B)

/**<        Address of Interrupt  register   */
#define BMG160_INTR_TWO_ADDR      (0x1C)

/**<        Address of Interrupt  register   */
#define BMG160_INTR_4_ADDR        (0x1E)

/**<        Address of Interrupt register   */
#define BMG160_RST_LATCH_ADDR     (0x21)

/**<        Address of Reset Latch Register           */
/***********************************************/
/**\name    INTERRUPT HIGH RATE CONFIGURATION REGISTER  */
/***********************************************/
#define BMG160_HIGHRATE_THRES_X_ADDR (0x22)

/**<        Address of High Th x Address register     */
#define BMG160_HIGHRATE_DURN_X_ADDR  (0x23)

/**<        Address of High Dur x Address register    */
#define BMG160_HIGHRATE_THRES_Y_ADDR (0x24)

/**<        Address of High Th y  Address register    */
#define BMG160_HIGHRATE_DURN_Y_ADDR  (0x25)

/**<        Address of High Dur y Address register    */
#define BMG160_HIGHRATE_THRES_Z_ADDR (0x26)

/**<        Address of High Th z Address register  */
#define BMG160_HIGHRATE_DURN_Z_ADDR  (0x27)

/**<        Address of High Dur z Address register  */
#define BMG160_SOC_ADDR              (0x31)

/**<        Address of SOC register        */
/***********************************************/
/**\name    OFFSET REGISTER  */
/***********************************************/
#define BMG160_A_FOC_ADDR (0x32)

/**<        Address of A_FOC Register        */
/***********************************************/
/**\name    NVM CONTROL REGISTER  */
/***********************************************/
#define BMG160_TRIM_NVM_CTRL_ADDR (0x33)

/**<        Address of Trim NVM control register    */
#define BMG160_BGW_SPI3_WDT_ADDR  (0x34)

/**<        Address of BGW SPI3,WDT Register           */
/***********************************************/
/**\name    OFFSET OCNFIGURATION REGISTER  */
/***********************************************/
/* Trim Register */
#define BMG160_OFFSET_OFC1_ADDR (0x36)

/**<        Address of OFC1 Register          */
#define BMG160_OFC2_ADDR        (0x37)

/**<        Address of OFC2 Register          */
#define BMG160_OFC3_ADDR        (0x38)

/**<        Address of OFC3 Register          */
#define BMG160_OFC4_ADDR        (0x39)

/**<        Address of OFC4 Register          */
#define BMG160_TRIM_GP0_ADDR    (0x3A)

/**<        Address of Trim GP0 Register              */
#define BMG160_TRIM_GP1_ADDR    (0x3B)

/**<        Address of Trim GP1 Register              */
/***********************************************/
/**\name    SELFTEST REGISTER  */
/***********************************************/
#define BMG160_SELFTEST_ADDR (0x3C)

/**<        Address of BGW Self test Register           */
/***********************************************/
/**\name    FIFO REGISTER  */
/***********************************************/
/* Control Register */
#define BMG160_FIFO_CGF0_ADDR (0x3D)

/**<        Address of FIFO CGF0 Register             */
#define BMG160_FIFO_CGF1_ADDR (0x3E)

/**<        Address of FIFO CGF1 Register             */
/* Data Register */
#define BMG160_FIFO_DATA_ADDR (0x3F)

/**<        Address of FIFO Data Register             */
/***********************************************/
/**\name    FIFO DEFINITIONS  */
/***********************************************/
#define BMG160_FIFO_XYZ_DATA_ENABLED           (0x00)
#define BMG160_FIFO_TAG_ENABLED                (0x01)
#define BMG160_FIFO_XYZ_AXES_TAG_FRAME_SIZE    (8)
#define BMG160_FIFO_XYZ_AXES_FRAME_SIZE        (6)
#define BMG160_FIFO_SINGLE_AXIS_TAG_FRAME_SIZE (4)
#define BMG160_FIFO_SINGLE_AXIS_FRAME_SIZE     (2)

/***********************************************/
/**\name    BIT LENGTH, MASK, POSITION FOR THE RANGE  */
/***********************************************/
/**< First (3) bits of range Registers */
#define BMG160_RANGE_ADDR_RANGE__POS (0)
#define BMG160_RANGE_ADDR_RANGE__LEN (3)
#define BMG160_RANGE_ADDR_RANGE__MSK (0x07)
#define BMG160_RANGE_ADDR_RANGE__REG (BMG160_RANGE_ADDR)
