# Configuration of I2C communication by libmpsse-i2c
## Channel config
Set 'I2C_ENABLE_DRIVE_ONLY_ZERO'

```CPP
ChannelConfig param;
param.ClockRate = (I2C_ClockRate_t)val;
param.LatencyTimer = 1;
param.Options = I2C_ENABLE_DRIVE_ONLY_ZERO;
```

## Write and Read
set I2C_TRANSFER_OPTIONS_FAST_TRANSFER option in both write and read.

### Write

```CPP
stat = I2C_DeviceWrite(
  Handle,
  slave_address,
  2,
  buffer,
  &transfered,
  I2C_TRANSFER_OPTIONS_START_BIT | I2C_TRANSFER_OPTIONS_STOP_BIT);
```

### Read

```CPP
stat_write = I2C_DeviceWrite(
  handle, 
  slave_address, 
  1, 
  &register_address, 
  &transfered, 
  I2C_TRANSFER_OPTIONS_START_BIT | I2C_TRANSFER_OPTIONS_FAST_TRANSFER);
stat_read = I2C_DeviceRead(
  handle, 
  slave_address, 
  1, 
  data, 
  &transfered, 
  I2C_TRANSFER_OPTIONS_START_BIT | I2C_TRANSFER_OPTIONS_STOP_BIT | I2C_TRANSFER_OPTIONS_NACK_LAST_BYTE | I2C_TRANSFER_OPTIONS_FAST_TRANSFER);
```
